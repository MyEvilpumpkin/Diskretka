#include "N_modules.h"

// Ввод неотрицательных чисел int
int getNumber()
{
	char* number = NULL, symbol;
	int toReturn, lenght = 0;
	bool error;
	do
	{
		lenght = 0;
		error = false;
		do
		{
			symbol = getchar();
			if (symbol >= '0' && symbol <= '9')
			{
				number = (char*)realloc(number, (lenght + 1) * sizeof(char));
				number[lenght++] = symbol;
			}
			else if (symbol != '\n')
				error = true;
		} while (symbol != '\n');
		if (error)
			printf("Введены некорректные данные. Введите неотрицательное число: ");
	} while (error || lenght == 0);
	number = (char*)realloc(number, (lenght + 1) * sizeof(char));
	number[lenght] = '\0';
	toReturn = atoi(number);
	free(number);
	return toReturn;
}
// Удаление лишних нулей в начале числа
N* deNullN(N* n)
{
	if (n->len != 0)
	{
		int i = 1,
			l = n->len;
		for (int j = 0; j < l; j++)
			i = n->n[j] == 0 ? i : j + 1;
		n->n = (int*)realloc(n->n, i * sizeof(int));
		n->len = i;
	}
	return n;
}
// Перевод из int в N
N* intToN(int d)
{
	N* n = initN();
	int len = 0, buffer = d;
	while (buffer > 0)
	{
		buffer = buffer / 10;
		len++;
	}
	n->len = len;
	n->n = (int*)realloc(n->n, len * sizeof(int));
	for (int i = len - 1; i >= 0; i--)
	{
		n->n[len - 1 - i] = d % 10;
		d /= 10;
	}
	return n;
}
// Ввод чисел N
N* input()
{
	char *symbol = (char*)malloc(sizeof(char));
	int *k = NULL, len = 0;
	N *n = initN();
	bool error = false;
	do
	{
		*symbol = getchar();
		if ('0' <= *symbol && *symbol <= '9')
		{
			k = (int*)realloc(k, (len + 1) * sizeof(int));
			k[len++] = atoi(symbol);
		}
		else if (*symbol != '\n')
			error = true;
		else if (!error && len == 0)
			n->len = 0;
	} while (*symbol != '\n');
	if (!error && len > 0)
	{
		n->n = (int*)realloc(n->n, len * sizeof(int));
		n->len = len;
		for (int i = 0; i < len; i++)
			n->n[i] = k[len - i - 1];
	}
	free(k);
	free(symbol);
	return n;
}

// Инициализация
N* initN()
{
	N* n = (N*)malloc(sizeof(N));
	n->n = (int*)malloc(sizeof(int));
	n->len = -1;
	return n;
}
// Ввод
N* inputN()
{
	N* n;
	do
	{
		n = input();
		if (n->len == -1) {
			printf("Введены некорректные данные. Введите натуральное число: ");
			freeN(n);
		}
	} while (n->len < 1);
	n = deNullN(n);
	return n;
}
// Инициализация с обнулением
N* zeroN()
{
	N* n = initN();
	n->n[0] = 0;
	n->len = 1;
	return n;
}
// Присваивание
N* assignmentN(N* n)
{
	N* result = initN();
	result->n = (int*)realloc(result->n, n->len * sizeof(int));
	for (int i = 0; i < n->len; i++)
		result->n[i] = n->n[i];
	result->len = n->len;
	return result;
}
// Вывод
void printN(N* n)
{
	for (int i = n->len - 1; i >= 0; i--)
		printf("%d", n->n[i]);
}
// Освобождение памяти
N* freeN(N* n)
{
	free(n->n);
	free(n);
	return n;
}

// N-1
int COM_NN_D(N* n1, N* n2)
{
	if (n1->len > n2->len) // Если первое число больше второго
		return 2;
	if (n1->len < n2->len) // Если второе число больше первого
		return 1;
	else
	{
		for (int i = n1->len - 1; i >= 0; i--) // Цикл до последней числа
			if (n1->n[i] > n2->n[i]) // Если цифра первого числа больше цифры второго
				return 2;
			else if (n1->n[i] < n2->n[i]) // Наоборот
				return 1;
		return 0; // Если длины двух чисел и все их цифры оказались равны (числа равны)
	}
}
// N-2
bool NZER_N_B(N* n)
{
	return (n->len != 1 || n->n[0] != 0); // Число равно 0, если в числе есть только один разряд и он равен 0
}
// N-3
N* ADD_1N_N(N* n)
{
	N* result = assignmentN(n);
	if (result->n[0] != 9) // Если последний разряд числа не равен 9, то прибавляем к нему единицу
		result->n[0]++;
	else // Если последний разряд равен 9, то заменяем его и все последующие девятки на нули и прибавляем единицу к первой не девятке 
	{
		int count = 0;
		while (result->n[count] == 9)
			result->n[count++] = 0;
		if (count == result->len) // Если в числе все цифры девятки, то необходимо создать новый разряд
		{
			result->n = (int*)realloc(result->n, ++result->len * sizeof(int));  // Создаём новый разряд
			result->n[count] = 1; // Значение нового разряда равно единице
		}
		else
			result->n[count]++; // Если в числе не все девятки, то первую не девятку увеличиваем на единицу
	}
	return result;
}
// N-4
N* ADD_NN_N(N* n1, N* n2)
{
	N* result;
	if (COM_NN_D(n1, n2) == 2) // Если n1>n2
	{
		result = assignmentN(n1); // Будем прибавлять к n1
		for (int i = 0; i < n2->len; i++)
		{
			result->n[i] += n2->n[i]; // Складываем соответствующие разряды
			if (result->n[i]>9)	// Если результат больше 9, то берём остаток от деления на 10 и добавляем единицу в следующий разряд
			{
				result->n[i] %= 10;
				int g = i;
				do
				{
					if (g == result->len - 1) // Если следующего разряда нет, то он создаётся
					{
						result->n = (int*)realloc(result->n, ++result->len * sizeof(int));
						result->n[++g] = 1; // Следующему "пустому" разряду присваивается единица
					}
					else
						result->n[++g]++; // В случае если следующий разряд существует, он увеличивается на единицу
					result->n[g] %= 10;
				} while (result->n[g] % 10 == 0);
			}
		}
	}
	else // Если n1<n2
	{
		result = assignmentN(n2); // Будем прибавлять к n2
		for (int i = 0; i < n1->len; i++)
		{
			result->n[i] += n1->n[i]; // Складываем соответствующие разряды
			if (result->n[i]>9)	// Если результат больше 9, то берём остаток от деления на 10 и добавляем единицу в следующий разряд
			{
				result->n[i] %= 10;
				int g = i;
				do
				{
					if (g == result->len - 1) // Если следующего разряда нет, то он создаётся
					{
						result->n = (int*)realloc(result->n, ++result->len * sizeof(int));
						result->n[++g] = 1; // Следующему "пустому" разряду присваивается единица
					}
					else
						result->n[++g]++; // В случае если следующий разряд существует, он увеличивается на единицу
					result->n[g] %= 10;
				} while (result->n[g] % 10 == 0); // В случае если следующий разряд существует, он увеличивается на единицу
			}
		}
	}
	return result;
}
// N-5
N* SUB_NN_N(N* n1, N* n2)
{
	N* result;
	bool temp = false;
	if (COM_NN_D(n1, n2) == 2) // Проверка на правильность введенных данных
	{
		result = (N*)malloc(sizeof(N));
		result->n = (int*)malloc(n1->len * sizeof(int)); // Выделение памяти под очередную цифру результата
		result->len = n1->len;
		for (int i = 0; i < n1->len; i++) // Цикл до конца числа
		{
			if (i < n2->len) // Если счётчик меньше длины меньшего числа (числа "накладываются" друг на друга)
			{
				if (n1->n[i] >= n2->n[i] + temp) // Если цифра большего числа больше или равна цифре меньшего числа
				{
					result->n[i] = n1->n[i] - n2->n[i] - temp; // Проводим обыкновенное вычитание
					temp = false;
				}
				else // Если цифра большего числа меньше цифры меньшего числа
				{
					result->n[i] = n1->n[i] + 10 - n2->n[i] - temp;
					temp = true;
				}
			}
			else
			{
				if (temp)
					if (n1->n[i] == 0)
						result->n[i] = 9;
					else
					{
						result->n[i] = n1->n[i] - temp;
						temp = false;
					}
				else
					result->n[i] = n1->n[i]; // Иначе мы ничего с цифрами не делаем, а просто "переписываем" их в результат
			}
		}
		deNullN(result); // Отбрасываем образовавшиеся незначащие нули
	}
	else
		result = zeroN();
	return result;
}
// N-6
N* MUL_ND_N(N* n, int d)
{
	N* result;
	if (!d)
		result = zeroN();
	else
	{
		result = (N*)malloc(sizeof(N));
		result->len = n->len;
		result->n = (int*)malloc(result->len * sizeof(int));
		int temp = 0;
		for (int i = 0; i < n->len; i++)
		{
			int tmp = n->n[i] * d + temp; // Промежуточный результат = разряд * цифру + остаток
			result->n[i] = tmp % 10; // Определяем разряд
			temp = tmp / 10; // Определяем остаток
		}
		if (temp) // Создаём ещё один разряд, если остаток не 0
		{
			result->len++;
			result->n = (int*)realloc(result->n, result->len * sizeof(int));
			result->n[result->len - 1] = temp;
		}
	}
	return result;
}
// N-7
N* MUL_Nk_N(N* n, int k)
{
	N* result = (N*)malloc(sizeof(N));
	result->len = n->len + k; // Инициализируем размер суммой длины исходного числа и заданной степени k
	result->n = (int*)malloc(result->len * sizeof(int)); // Выделяем память для нашего числа
	for (int i = 0; i < result->len; i++) // Цикл до конца числа
		if (i < k) // Tсли счётчик меньше степни k
			result->n[i] = 0; // "Домножаем" наше число на 10
		else
			result->n[i] = n->n[i - k]; // Подставляем на новую позицию (на k больше) цифру исходного числа
	result = deNullN(result);
	return result;
}
// N-8
N* MUL_NN_N(N* n1, N* n2)
{
	N *result = zeroN(), *temp, *tmp;
	for (int i = 0; i < n2->len; i++) // К результату, изначально равному 0, в каждом шаге цикла прибавляется i-ая цифра первого сомножителя
	{
		tmp = MUL_ND_N(n1, n2->n[i]);
		temp = MUL_Nk_N(tmp, i); // Умноженная на второй сомножитель и на 10^i
		freeN(tmp);
		tmp = ADD_NN_N(result, temp);
		freeN(result);
		freeN(temp);
		result = tmp;
	}
	return result;
}
// N-9
N* SUB_NDN_N(N* n1, int d, N* n2)
{
	N *result, *temp;
	if (COM_NN_D(n1, n2) == 2) // Если первое число больше второго
	{
		temp = MUL_ND_N(n2, d); // Меньшее домножаем на цифру
		result = SUB_NN_N(n1, temp); // Вычитаем из большего числа меньшее (домноженное на цифру)
	}
	else
	{
		temp = MUL_ND_N(n1, d); // Меньшее домножаем на цифру
		result = SUB_NN_N(n2, temp); // Вычитаем из большего числа меньшее (домноженное на цифру)
	}
	freeN(temp);
	return result;
}
// N-10
int DIV_NN_Dk(N* n1, N* n2, int& k)
{
	int result = 1, flag;
	N* temp;
	k = 0;
	if (COM_NN_D(n1, n2) == 2) // Если делимое - первое число
	{
		k = n1->len - n2->len;
		temp = MUL_Nk_N(n2, k);
		if (COM_NN_D(n1, temp) == 1)
		{
			freeN(temp);
			temp = MUL_Nk_N(n2, --k); // Вычисляем наибольшее произведение делителя и 10^k, меньшее делимого
		}
		do
		{
			N* tmp = MUL_ND_N(temp, ++result); // Вычисляем произведение на цифру
			flag = COM_NN_D(n1, tmp); // Сравниваем его с делимым
			freeN(tmp);
		} while (flag != 1);
		result--; // Аналогично значению степени
		freeN(temp);
	}
	else if (COM_NN_D(n1, n2) == 1) // Если делимое - второе число
	{
		k = n2->len - n1->len;
		temp = MUL_Nk_N(n1, k);
		if (COM_NN_D(n2, temp) == 1)
		{
			freeN(temp);
			temp = MUL_Nk_N(n1, --k); // Вычисляем наибольшее произведение делителя и 10^k, меньшее делимого
		}
		do
		{
			N* tmp = MUL_ND_N(temp, ++result); // Вычисляем произведение на цифру
			flag = COM_NN_D(n2, tmp); // Сравниваем его с делимым
			freeN(tmp);
		} while (flag != 1);
		result--; // Аналогично значению степени
		freeN(temp);
	}
	return result;
}
// N-11
N* DIV_NN_N(N* n1, N* n2)
{
	N* result = zeroN(); // Частное от деления
	N *tempRes, *temp;
	if (COM_NN_D(n1, n2) == 2)
	{
		N* part = assignmentN(n1); // Временный остаток от деления
		int k = 0;
		if (NZER_N_B(n2))
			do
			{
				tempRes = zeroN(); // Cоздание произведения первой цифры деления на 10^k
				tempRes->n[0] = DIV_NN_Dk(part, n2, k); // Вычисляем первую цифру и степень десятки при делении
				temp = MUL_Nk_N(tempRes, k); // Умножаем на 10^k
				freeN(tempRes);
				tempRes = ADD_NN_N(result, temp); // Добавление временного результата к общему
				freeN(result);
				result = tempRes;
				tempRes = MUL_NN_N(temp, n2);
				freeN(temp);
				temp = SUB_NN_N(part, tempRes); // Вычисление временного остатка
				freeN(part);
				part = temp;
				freeN(tempRes);
			} while (COM_NN_D(part, n2) != 1);
			freeN(part);
	}
	else
	{
		N* part = assignmentN(n2); // Временный остаток от деления
		int k = 0;
		if (NZER_N_B(n1))
			do
			{
				tempRes = zeroN(); // Cоздание произведения первой цифры деления на 10^k
				tempRes->n[0] = DIV_NN_Dk(part, n1, k); // Вычисляем первую цифру и степень десятки при делении
				temp = MUL_Nk_N(tempRes, k); // Умножаем на 10^k
				freeN(tempRes);
				tempRes = ADD_NN_N(result, temp); // Добавление временного результата к общему
				freeN(result);
				result = tempRes;
				tempRes = MUL_NN_N(temp, n1);
				freeN(temp);
				temp = SUB_NN_N(part, tempRes); // Вычисление временного остатка
				freeN(part);
				part = temp;
				freeN(tempRes);
			} while (COM_NN_D(part, n1) != 1);
			freeN(part);
	}
	return result;
}
// N-12
N* MOD_NN_N(N* n1, N* n2)
{
	N *temp, *tmp, *result;
	temp = DIV_NN_N(n1, n2); // Числитель от деления большего числа на меньшее
	if (COM_NN_D(n1, n2) == 2)
	{
		tmp = MUL_NN_N(temp, n2); // Произведение числителя и меньшего числа
		result = SUB_NN_N(n1, tmp); // Разность большего числа и произведения
	}
	else
	{
		tmp = MUL_NN_N(temp, n1); // Произведение числителя и меньшего числа
		result = SUB_NN_N(n2, tmp); // Разность большего числа и произведения
	}
	freeN(temp);
	freeN(tmp);
	return result;
}
// N-13
N* GCF_NN_N(N* n1, N* n2)
{
	N *result, *temp;
	N* first = assignmentN(n1);
	N* second = assignmentN(n2);
	while (NZER_N_B(first) && NZER_N_B(second)) // Пока оба числа - не нули
	{
		if (COM_NN_D(first, second) > 1) // Если первое больше второго
		{
			temp = MOD_NN_N(first, second); // Находим остаток от деления первого на второе
			freeN(first);
			first = temp;
		}
		else
		{
			temp = MOD_NN_N(second, first); // Иначе - остаток от деления второго на первое
			freeN(second);
			second = temp;
		}
	}
	if (COM_NN_D(first, second) != 2) // Если первое число - больше второго
	{
		result = second;
		freeN(first);
	}
	else
	{
		result = first;
		freeN(second);
	}
	return result;
}
// N-14
N* LCM_NN_N(N* n1, N* n2)
{
	N* nod = GCF_NN_N(n1, n2); // НОД двух чисел
	N* temp = MUL_NN_N(n1, n2); // Произведение двух чисел
	N* nok = DIV_NN_N(temp, nod); // НОК двух чисел
	freeN(nod);
	freeN(temp);
	return nok;
}
