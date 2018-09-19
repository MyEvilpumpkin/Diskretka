#include "Q_modules.h"

// Ввод
Q* inputQ()
{
	Q* q = (Q*)malloc(sizeof(Q));
	printf("Введите числитель: ");
	q->num = inputZ();
	printf("Введите знаменатель: ");
	bool error;
	do
	{
		error = false;
		q->denom = inputN();
		if (q->denom->len == 1 && q->denom->n[0] == 0)
		{
			error = true;
			freeN(q->denom);
			printf("Введены некорректные данные. Введите знаменатель > 0: ");
		}
	} while (error);
	return q;
}
// Инициализация с обнулением
Q* zeroQ()
{
	Q* q = (Q*)malloc(sizeof(Q));
	q->num = zeroZ();
	q->denom = zeroN();
	q->denom->n[0] = 1;
	return q;
}
// Присваивание
Q* assignmentQ(Q* q)
{
	Q* result = (Q*)malloc(sizeof(Q));
	result->num = assignmentZ(q->num);
	result->denom = assignmentN(q->denom);
	return result;
}
// Вывод
void printQ(Q* q)
{
	if (!q->num->sign)
		printf("- ");
	printN(q->num->number);
	if (q->denom->len != 1 || q->denom->n[0] != 1)
	{
		printf("/");
		printN(q->denom);
	}
}
// Освобождение памяти
Q* freeQ(Q* q)
{
	freeN(q->denom);
	freeZ(q->num);
	free(q);
	return q;
}

// Q-1
Q* RED_Q_Q(Q* q)
{
	N* d = GCF_NN_N(q->num->number, q->denom); // Присваиваем d значение НОДа (модуля числителя дроби) и знаменателя дроби 
	while (d->len != 1 || d->n[0] != 1) // До тех пор пока d не станет равным 1  
	{
		N* temp = DIV_NN_N(q->num->number, d); // Сокращаем числитель на d
		freeN(q->num->number);
		q->num->number = temp;
		temp = DIV_NN_N(q->denom, d); // Сокращаем знаменатель на d
		freeN(q->denom);
		q->denom = temp;
		freeN(d);
		d = GCF_NN_N(q->num->number, q->denom); // Присваиваем d значение НОДа (модуля числителя дроби) и знаменателя дроби  
	}
	freeN(d);
	return q;
}
// Q-2
bool INT_Q_B(Q* q)
{
	return (RED_Q_Q(q)->denom->len == 1 && RED_Q_Q(q)->denom->n[0] == 1); // Возвращаем истинность высказывания о том, что знаменатель дроби = 1
}
// Q-3
Q* TRANS_Z_Q(Z* z)
{
	Q* result = (Q*)malloc(sizeof(Q));
	result->denom = zeroN();
	result->denom->n[0] = 1;
	result->num = assignmentZ(z); // Присваивание числителю результата значения целого числа
	return result;
}
// Q-4
Z* TRANS_Q_Z(Q* q)
{
	return assignmentZ(RED_Q_Q(q)->num); // Возвращаем значение числителя сокращенной дроби 
}
// Q-5
Q* ADD_QQ_Q(Q* q1, Q* q2)
{
	Q* result = (Q*)malloc(sizeof(Q));
	result->denom = MUL_NN_N(q1->denom, q2->denom); // Находим произведение и записываем в знаменатель
	Z* z1 = (Z*)malloc(sizeof(Z));
	z1->number = MUL_NN_N(q1->num->number, q2->denom); // Присваиваем значению знаменателя q1 произведение числителя q1 и знаменателя q2 
	z1->sign = q1->num->sign; // Копируем знак числителя q1
	Z* z2 = (Z*)malloc(sizeof(Z));
	z2->number = MUL_NN_N(q2->num->number, q1->denom); // Присваиваем значению знаменателя q2 произведение числителя q2 и знаменателя q1
	z2->sign = q2->num->sign; // Копируем знак числителя q2
	result->num = ADD_ZZ_Z(z1, z2);
	freeZ(z1);
	freeZ(z2);
	return RED_Q_Q(result);
}
// Q-6
Q* SUB_QQ_Q(Q* q1, Q* q2)
{
	Q* result = (Q*)malloc(sizeof(Q));
	result->denom = MUL_NN_N(q1->denom, q2->denom); // Находим произведение и записываем в знаменатель
	Z* z1 = (Z*)malloc(sizeof(Z));
	z1->number = MUL_NN_N(q1->num->number, q2->denom); // Присваиваем значению знаменателя q1 произведение числителя q1 и знаменателя q2 
	z1->sign = q1->num->sign; // Копируем знак числителя q1
	Z* z2 = (Z*)malloc(sizeof(Z));
	z2->number = MUL_NN_N(q2->num->number, q1->denom); // Присваиваем значению знаменателя q2 произведение числителя q2 и знаменателя q1
	z2->sign = q2->num->sign; // Копируем знак числителя q2
	result->num = SUB_ZZ_Z(z1, z2);
	freeZ(z1);
	freeZ(z2);
	return RED_Q_Q(result);
}
// Q-7
Q* MUL_QQ_Q(Q* q1, Q* q2)
{
	Q* result = (Q*)malloc(sizeof(Q));
	result->denom = MUL_NN_N(q1->denom, q2->denom); // Перемножаем числители
	result->num = MUL_ZZ_Z(q1->num, q2->num); // Перемножаем знаменатели
	return RED_Q_Q(result);
}
// Q-8
Q* DIV_QQ_Q(Q* q1, Q* q2)
{
	Q* result;
	if (!POZ_Z_D(q1->num) || !POZ_Z_D(q2->num)) // Eсли числитель = 0
		result = zeroQ();
	else
	{
		result = (Q*)malloc(sizeof(Q));
		result->num = (Z*)malloc(sizeof(Z));
		result->num->sign = q1->num->sign == q2->num->sign; // Присвоить знаку результата эквиваленцию знаков двух числителей
		result->num->number = MUL_NN_N(q1->num->number, q2->denom); // Присвоить числителю результата произведение первого числителя и второго знаменателя
		result->denom = MUL_NN_N(q1->denom, q2->num->number); // Присвоить знаменателю результата произведение первого знаменателя и второго числителя
	}
	return RED_Q_Q(result);
}
