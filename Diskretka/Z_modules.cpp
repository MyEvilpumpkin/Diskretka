#include "Z_modules.h"

Z* initZ() {
	Z* z = (Z*)malloc(sizeof(Z));
	z->number = initN();
	z->sign = true;
	return z;
}

Z* inputZ() {
	Z* z = (Z*)malloc(sizeof(Z));
	char *s = (char*)malloc(sizeof(char));
	bool error;
	do {
		error = false;
		*s = getchar();
		if (*s == '-')
			z->sign = false;
		else if ('0' <= *s && *s <= '9')
			z->sign = true;
		else
			error = true;
		z->number = input();
		if (z->number->len == -1 || (z->number->len == 0 && *s == '-'))
			error = true;
		if (error) {
			printf("Введены некорректные данные. Введите целое число: ");
			freeN(z->number);
		}
		else if (*s != '-' && (*s != '0' || z->number->len == 0)) {
			z->number->n = (int*)realloc(z->number->n, (z->number->len + 1) * sizeof(int));
			z->number->len++;
			z->number->n[z->number->len - 1] = atoi(s);
		}
	} while (error);
	free(s);
	z->number = deNULL(z->number);
	return z;
}

Z* zeroZ()
{
	Z* z = (Z*)malloc(sizeof(Z));
	z->number = zeroN();
	z->sign = true;
	return z;
}

Z* assignmentZ(Z* z)
{
	Z* a = (Z*)malloc(sizeof(Z));
	a->number = assignmentN(z->number);
	a->sign = z->sign;
	return a;
}

void printZ(Z* z) {
	if (!z->sign)
		printf("-");
	printN(z->number);
}

Z* freeZ(Z* z) {
	freeN(z->number);
	free(z);
	return z;
}

// Z-1 Андрианова Вера

N* ABS_Z_N(Z *a)
{
	return assignmentN(a->number); // возвращаем число натуральную часть числа (целое = натуральное + знак)
}

// Z-2 Макаренко Данил

int POZ_Z_D(Z *a)
{
	if (!a->sign) // если число отрицательное
		return 1;
	else if (a->number->len == 1 && a->number->n[0] == 0) //если число = 0
		return 0;
	else // если число положительное
		return 2;
}

// Z-3 Андрианова Вера

Z* MUL_ZM_Z(Z* a)
{
	Z* resPtr = (Z*)malloc(sizeof(Z));
	resPtr->sign = true;
	resPtr->number = assignmentN(a->number); // присваиваем результату исходное число
	if (resPtr->number->len != 1 || resPtr->number->n[0] != 0) // если число не ноль
		resPtr->sign = !a->sign; // меняем знак результата на противоположный
	return resPtr;
}

// Z-4 Мищенко Алина

Z *TRANS_N_Z(N *a)
{
	Z *z = (Z*)malloc(sizeof(Z));
	z->number = assignmentN(a); // присваиваем целому результату натуральное число 
	z->sign = true;
	return z;
}

// Z-5 Манжиков Леонид

N *TRANS_Z_N(Z *a)
{
	return assignmentN(a->number); // возвращаем число натуральную часть числа
}

// Z-6 Стоянова Алина

Z *ADD_ZZ_Z(Z *num1, Z *num2)
{
	Z* sum = (Z*)malloc(sizeof(Z));
	if (num1->sign == num2->sign) { // если знаки двух чисел одинаковы
		sum->number = ADD_NN_N(num1->number, num2->number); // результату по модулю присваиваем значение суммы двух чисел
		sum->sign = num1->sign; // присваиваем результату общий знак двух чисел
	}
	else {
		if (COM_NN_D(num1->number, num2->number) == 2) { // если первое число больше второго по модулю
			sum->number = SUB_NN_N(num1->number, num2->number); // вычитаем из большего числа меньшее
			sum->sign = num1->sign; // присваиваем результату знак первого числа
		}
		else if (COM_NN_D(num1->number, num2->number) == 1) { // если второе число больше первого по модулю
			sum->number = SUB_NN_N(num2->number, num1->number); // наоборот
			sum->sign = num2->sign;
		}
		else if (COM_NN_D(num1->number, num2->number) == 0) { // если числа равны
			sum->number = zeroN(); // результат присваиваем нулю
			sum->sign = true; // со знаком плюс
		}
	}
	return sum;
}

// Z-7 Стоянова Алина

Z *SUB_ZZ_Z(Z *num1, Z *num2)
{
	Z *n2 = (Z*)malloc(sizeof(Z));
	n2->number = assignmentN(num2->number); // присваиваем вычитаемому значение меньшего числа 
	n2->sign = !num2->sign; // умножаем второе число на (-1)
	Z* result = ADD_ZZ_Z(num1, n2); // суммируем числа
	freeZ(n2);
	return result; // возвращаем их сумму
}

// Z-8 Манжиков Леонид

Z *MUL_ZZ_Z(Z *num1, Z *num2)
{
	Z *mul = (Z*)malloc(sizeof(Z));
	mul->number = MUL_NN_N(num1->number, num2->number); // присваиваем результату по модулю значение произведения первого числа на второе по модулю
	if (num1->sign == num2->sign) // если знаки двух чисел равны
		mul->sign = true; // то знак результата +
	else
		mul->sign = false; // знак результата -
	if (mul->number->len == 1 && mul->number->n[0] == 0) // если результа - 0
		mul->sign = true; // то знак результата +
	return mul;
}

// Z-9 Мищенко Алина

Z* DIV_ZZ_Z(Z* n1, N* n2)
{
	Z* res = (Z*)malloc(sizeof(Z));
	res->number = DIV_NN_N(n1->number, n2); // делим как натуральные числа большее (преобразованное в целое) на меньшее
	res->sign = n1->sign; // присваиваем знаку результата знак большего числа
	if (res->number->len == 1 && res->number->n[0] == 0) // если результат равен нулю
		res->sign = true; // то знак нуля +
	N* mod = MOD_NN_N(n1->number, n2);
	if (!res->sign && !(mod->len == 1 && mod->n[0] == 0))
	{
		Z* one = zeroZ();
		one->number->n[0] = 1;
		Z* temp = assignmentZ(res);
		freeZ(res);
		res = SUB_ZZ_Z(temp, one);
		freeZ(temp);
		freeZ(one);
	}
	freeN(mod);
	return res;
}

// Z-10 Кожанов Даниил

Z* MOD_ZZ_Z(Z* First, N* Second)
{
	Z* tmp = TRANS_N_Z(Second); // преобразованное в целое второе число
	Z *Rest = DIV_ZZ_Z(First, Second); // результат от деления без остатка первого числа на второе
	Z *Temp = MUL_ZZ_Z(Rest, tmp);
	freeZ(tmp);
	freeZ(Rest);
	tmp = SUB_ZZ_Z(First, Temp); // разность между исходным первым числом и произведением
	freeZ(Temp);

	if (First->sign) { // если знак реузльтата +
		Rest = (Z*)malloc(sizeof(Z));
		Rest->number = assignmentN(tmp->number);
		Rest->sign = true;
	}
	else {
		Temp = TRANS_N_Z(Second);
		Rest = ADD_ZZ_Z(tmp, Temp); // добавляем к остатку преобразованное второе число
		freeZ(Temp);
	}
	freeZ(tmp);
	return Rest;
}
