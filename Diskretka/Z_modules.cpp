#include "Z_modules.h"

// Инициализация
Z* initZ()
{
	Z* z = (Z*)malloc(sizeof(Z));
	z->number = initN();
	z->sign = true;
	return z;
}
// Ввод
Z* inputZ() {
	Z* z = (Z*)malloc(sizeof(Z));
	char *s = (char*)malloc(sizeof(char));
	bool error;
	do
	{
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
		if (error)
		{
			printf("Введены некорректные данные. Введите целое число: ");
			freeN(z->number);
		}
		else if (*s != '-' && (*s != '0' || z->number->len == 0))
		{
			z->number->n = (byte*)realloc(z->number->n, (z->number->len + 1) * sizeof(byte));
			z->number->len++;
			z->number->n[z->number->len - 1] = atoi(s);
		}
	} while (error);
	free(s);
	z->number = deNullN(z->number);
	return z;
}
// Инициализация с обнулением
Z* zeroZ()
{
	Z* z = (Z*)malloc(sizeof(Z));
	z->number = zeroN();
	z->sign = true;
	return z;
}
// Присваивание
Z* assignmentZ(Z* z)
{
	Z* result = (Z*)malloc(sizeof(Z));
	result->number = assignmentN(z->number);
	result->sign = z->sign;
	return result;
}
// Вывод
void printZ(Z* z)
{
	if (!z->sign)
		printf("-");
	printN(z->number);
}
// Освобождение памяти
Z* freeZ(Z* z)
{
	freeN(z->number);
	free(z);
	return z;
}

// Z-1
N* ABS_Z_N(Z* z)
{
	return assignmentN(z->number); // Возвращаем число натуральную часть числа (целое = натуральное + знак)
}
// Z-2
int POZ_Z_D(Z* z)
{
	if (!NZER_N_B(z->number)) // Если число = 0
		return 0;
	else if (!z->sign) // Если число отрицательное
		return 1;
	else // Если число положительное
		return 2;
}
// Z-3
Z* MUL_ZM_Z(Z* z)
{
	Z* result = (Z*)malloc(sizeof(Z));
	result->sign = true;
	result->number = assignmentN(z->number); // Присваиваем результату исходное число
	if (POZ_Z_D(result)) // Если число не ноль
		result->sign = !z->sign; // Меняем знак результата на противоположный
	return result;
}
// Z-4
Z* TRANS_N_Z(N* n)
{
	Z* result = (Z*)malloc(sizeof(Z));
	result->number = assignmentN(n); // Присваиваем целому результату натуральное число 
	result->sign = true;
	return result;
}
// Z-5
N* TRANS_Z_N(Z* z)
{
	return assignmentN(z->number); // Возвращаем число натуральную часть числа
}
// Z-6
Z* ADD_ZZ_Z(Z* z1, Z* z2)
{
	Z* result = (Z*)malloc(sizeof(Z));
	if (z1->sign == z2->sign) // Если знаки двух чисел одинаковы
	{
		result->number = ADD_NN_N(z1->number, z2->number); // Результату по модулю присваиваем значение суммы двух чисел
		result->sign = z1->sign; // Присваиваем результату общий знак двух чисел
	}
	else
	{
		int com = COM_NN_D(z1->number, z2->number);
		if (com == 2) // Если первое число больше второго по модулю
		{
			result->number = SUB_NN_N(z1->number, z2->number); // Вычитаем из большего числа меньшее
			result->sign = z1->sign; // Присваиваем результату знак первого числа
		}
		else if (com == 1) // Если второе число больше первого по модулю
		{
			result->number = SUB_NN_N(z2->number, z1->number); // Наоборот
			result->sign = z2->sign;
		}
		else // Если числа равны
		{
			result->number = zeroN(); // Результат присваиваем нулю
			result->sign = true; // Со знаком плюс
		}
	}
	return result;
}
// Z-7
Z* SUB_ZZ_Z(Z* z1, Z* z2)
{
	Z* result = (Z*)malloc(sizeof(Z));
	if (z1->sign != z2->sign) // Если знаки двух чисел разные
	{
		result->number = ADD_NN_N(z1->number, z2->number); // Результату по модулю присваиваем значение суммы двух чисел
		result->sign = z1->sign; // Присваиваем результату общий знак двух чисел
	}
	else
	{
		int com = COM_NN_D(z1->number, z2->number);
		if (com == 2) // Если первое число больше второго по модулю
		{
			result->number = SUB_NN_N(z1->number, z2->number); // Вычитаем из большего числа меньшее
			result->sign = z1->sign; // Присваиваем результату знак первого числа
		}
		else if (com == 1) // Если второе число больше первого по модулю
		{
			result->number = SUB_NN_N(z2->number, z1->number); // Наоборот
			result->sign = !z2->sign;
		}
		else // Если числа равны
		{
			result->number = zeroN(); // Результат присваиваем нулю
			result->sign = true; // Со знаком плюс
		}
	}
	return result;
}
// Z-8
Z* MUL_ZZ_Z(Z* z1, Z* z2)
{
	Z* result = (Z*)malloc(sizeof(Z));
	result->number = MUL_NN_N(z1->number, z2->number); // Присваиваем результату по модулю значение произведения первого числа на второе по модулю
	if (!POZ_Z_D(result)) // Если результа - 0
		result->sign = true; // То знак результата +
	else if (z1->sign == z2->sign) // Если знаки двух чисел равны
		result->sign = true; // То знак результата +
	else
		result->sign = false; // Знак результата -
	return result;
}
// Z-9
Z* DIV_ZN_Z(Z* z, N* n)
{
	Z* result = (Z*)malloc(sizeof(Z));
	result->number = DIV_NN_N(z->number, n); // Делим как натуральные числа большее (преобразованное в целое) на меньшее
	result->sign = z->sign; // Присваиваем знаку результата знак большего числа
	if (!POZ_Z_D(result)) // Если результат равен нулю
		result->sign = true; // То знак нуля +
	N* mod = MOD_NN_N(z->number, n);
	if (!result->sign && NZER_N_B(mod))
	{
		Z* one = zeroZ();
		one->number->n[0] = 1;
		Z* temp = result;
		result = SUB_ZZ_Z(temp, one);
		freeZ(temp);
		freeZ(one);
	}
	freeN(mod);
	return result;
}
// Z-10
Z* MOD_ZN_Z(Z* z, N* n)
{
	Z* result = TRANS_N_Z(n); // Преобразованное в целое второе число
	Z* tmp = DIV_ZN_Z(z, n); // Результат от деления без остатка первого числа на второе
	Z* temp = MUL_ZZ_Z(tmp, result);
	freeZ(result);
	freeZ(tmp);
	result = SUB_ZZ_Z(z, temp); // Разность между исходным первым числом и произведением
	freeZ(temp);
	return result;
}
