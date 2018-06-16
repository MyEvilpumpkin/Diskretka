#include "Q_modules.h"

Q* initQ() {
	Q* q = (Q*)malloc(sizeof(Q));
	q->num = initZ();
	q->denom = initN();
	return q;
}

Q* inputQ() {
	Q* q = (Q*)malloc(sizeof(Q));
	printf("Введите числитель: ");
	q->num = inputZ();
	printf("Введите знаменатель: ");
	bool error;
	do {
		error = false;
		q->denom = inputN();
		if (q->denom->len == 1 && q->denom->n[0] == 0) {
			error = true;
			freeN(q->denom);
			printf("Введены некорректные данные. Введите знаменатель > 0: ");
		}
	} while (error);
	return q;
}

Q* zeroQ() {
	Q* q = (Q*)malloc(sizeof(Q));
	q->num = (Z*)malloc(sizeof(Z));
	q->num->sign = true;
	q->num->number = zeroN();
	q->denom = zeroN();
	q->denom->n[0] = 1;
	return q;
}

Q* assignmentQ(Q* q) {
	Q* a = (Q*)malloc(sizeof(Q));
	a->num = assignmentZ(q->num);
	a->denom = assignmentN(q->denom);
	return a;
}

void printQ(Q* q) {
	if (!q->num->sign)
		printf("- ");
	printN(q->num->number);
	if (q->denom->len != 1 || q->denom->n[0] != 1) {
		printf("/");
		printN(q->denom);
	}
}

Q* freeQ(Q* q) {
	freeN(q->denom);
	freeZ(q->num);
	free(q);
	return q;
}

// Q-1 Мищенко Алина

Q* RED_Q_Q(Q* fraction) {
	Q* temp;
	N* d = GCF_NN_N(fraction->num->number, fraction->denom); // присваиваем d значение НОДа (модуля числителя дроби) и знаменателя дроби 
	while (d->len != 1 or d->n[0] != 1) { // до тех пор пока d не станет равным 1  
		temp = (Q*)malloc(sizeof(Q));
		temp->num = DIV_ZN_Z(fraction->num, d); // сокращаем числитель на d
		temp->denom = DIV_NN_N(fraction->denom, d); // сокращаем знаменатель на d
		freeZ(fraction->num);
		fraction->num = (Z*)malloc(sizeof(Z));
		fraction->num->number = assignmentN(temp->num->number);
		fraction->num->sign = temp->num->sign;
		freeN(fraction->denom);
		fraction->denom = assignmentN(temp->denom);
		freeQ(temp);
		freeN(d);
		d = GCF_NN_N(fraction->num->number, fraction->denom); // присваиваем d значение НОДа (модуля числителя дроби) и знаменателя дроби  
	}
	freeN(d);
	return fraction;
}

// Q-2 Мищенко Алина

bool INT_Q_B(Q* Numb)
{
	return (RED_Q_Q(Numb)->denom->len == 1 && RED_Q_Q(Numb)->denom->n[0] == 1); // возвращаем истинность высказывания о том, что знаменатель дроби = 1
}

// Q-3 Соцкова Ирина

Q* TRANS_Z_Q(Z* First)
{
	Q* Rez = (Q*)malloc(sizeof(Q));
	Rez->denom = zeroN();
	Rez->denom->n[0] = 1;
	Rez->num = (Z*)malloc(sizeof(Z));
	Rez->num->number = assignmentN(First->number); // присваивание числителю результата значения целого числа
	Rez->num->sign = First->sign; // копируем знак числа
	if (First->number->len == 1 && First->number->n[0] == 0) // если число равно нулю
		Rez->num->sign = true; // то число положительно
	return Rez; // результат перевода
}

// Q-4 Соцкова Ирина

Z* TRANS_Q_Z(Q* First)
{
	return assignmentZ(RED_Q_Q(First)->num); // возвращаем значение числителя сокращенной дроби 
}

// Q-5 Дяченко Виталий

Q* ADD_QQ_Q(Q* f1, Q* f2) {
	Q* ans = (Q*)malloc(sizeof(Q));
	//произведение находим, в знаменатель пишем
	ans->denom = MUL_NN_N(f1->denom, f2->denom);
	Z* q1 = (Z*)malloc(sizeof(Z));
	q1->number = MUL_NN_N(f1->num->number, f2->denom); // присваиваем значению знаменателя f1 произведение числителя f1 и знаменателя f2 
	q1->sign = f1->num->sign; // копируем знак числителя f1
	Z* q2 = (Z*)malloc(sizeof(Z));
	q2->number = MUL_NN_N(f2->num->number, f1->denom); // присваиваем значению знаменателя f2 произведение числителя f2 и знаменателя f1
	q2->sign = f2->num->sign; // копируем знак числителя f2
	ans->num = ADD_ZZ_Z(q1, q2);
	freeZ(q1);
	freeZ(q2);
	return RED_Q_Q(ans); // cокращаем дробь
}

// Q-6 Зерцалов Владимир

Q* SUB_QQ_Q(Q* f1, Q* f2) {
	Q* q = assignmentQ(f2);
	q->num->sign = !f2->num->sign;
	Q* result = ADD_QQ_Q(f1, q); // складываем первую дробь со второй * (-1)
	freeQ(q);
	return result;
}

// Q-7 Дяченко Виталий

Q* MUL_QQ_Q(Q* First, Q* Second)
{
	Q* Result = (Q*)malloc(sizeof(Q));
	Result->denom = MUL_NN_N(First->denom, Second->denom); // перемножаем числители
	Result->num = MUL_ZZ_Z(First->num, Second->num); // перемножаем знаменатели
	return RED_Q_Q(Result); // результат умножения
}

// Q-8 Кожанов Даниил

Q* DIV_QQ_Q(Q* First, Q* Second)
{
	Q* Result;
	if (Second->num->number->len == 1 && Second->num->number->n[0] == 0) // если числитель = 0
		Result = zeroQ();
	else {
		Result = (Q*)malloc(sizeof(Q));
		Result->num = (Z*)malloc(sizeof(Z));
		Result->num->sign = First->num->sign == Second->num->sign; // присвоить знаку результата эквиваленцию знаков двух числителей
		Result->num->number = MUL_NN_N(First->num->number, Second->denom); // присвоить числителю результата произведение первого числителя и второго знаменателя
		Result->denom = MUL_NN_N(First->denom, Second->num->number); // присвоить знаменателю результата произведение первого знаменателя и второго числителя
	}
	return RED_Q_Q(Result);
}
