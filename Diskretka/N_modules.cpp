#include "N_modules.h"

// Ввод неотрицательных чисел int
int getNumber()
{
	char* number = NULL;
	int toReturn;
	char symbol;
	int lenght = 0;
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
				*(number + lenght) = symbol;
				lenght++;
			}
			else if (symbol != '\n')
				error = true;
		} while (symbol != '\n');
		if (error)
			printf("Введены некорректные данные. Введите неотрицательное число: ");
	} while (error || lenght == 0);
	number = (char*)realloc(number, (lenght + 1) * sizeof(char));
	*(number + lenght) = '\0';
	toReturn = atoi(number);
	free(number);
	return toReturn;
}
// Удаление лишних нулей в начале числа
N* deNULL(N* n)
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
			k[len] = atoi(symbol);
			len++;
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
	N* n = initN();
	do
	{
		freeN(n);
		n = input();
		if (n->len == -1)
			printf("Введены некорректные данные. Введите натуральное число: ");
	} while (n->len < 1);
	n = deNULL(n);
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
			result->len++; // Увеличиваем длину числа на 1
			result->n = (int*)realloc(result->n, result->len * sizeof(int));  // Создаём новый разряд
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
		int size = n2->len; // Если у n2 меньше разрядов чем у n1, то нет нужды изменять разряды, начиная с n2->len+2
		for (int i = 0; i < size; i++)
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
						result->n[g + 1] = 1; // Следующему "пустому" разряду присваивается единица
					}
					else
						result->n[g + 1]++; // В случае если следующий разряд существует, он увеличивается на единицу
					result->n[g + 1] %= 10;
					g++;
				} while (result->n[g] % 10 == 0);
			}
		}
	}
	else // Если n1<n2
	{
		result = assignmentN(n2); // Будем прибавлять к n2
		int size = n1->len; // Если у n1 меньше разрядов чем у n2, то нет нужды изменять разряды, начиная с n1->len+2
		for (int i = 0; i < size; i++)
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
						result->n[g + 1] = 1; // Следующему "пустому" разряду присваивается единица
					}
					else
						result->n[g + 1]++; // В случае если следующий разряд существует, он увеличивается на единицу
					result->n[g + 1] %= 10;
					g++;
				} while (result->n[g] % 10 == 0); // В случае если следующий разряд существует, он увеличивается на единицу
			}
		}
	}
	return result;
}
// N-5
N* SUB_NN_N(N* n1, N* n2)
{
	N* result = zeroN();
	bool temp = false;
	if (COM_NN_D(n1, n2) == 2) // Проверка на правильность введенных данных
	{
		result->n = (int*)realloc(result->n, n1->len * sizeof(int)); // Выделение памяти под очередную цифру результата
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
		deNULL(result); // Отбрасываем образовавшиеся незначащие нули
	}
	return result;
}

// N-6

N* MUL_ND_N(N* a, int b)
{
	N* c = zeroN();
	int temp = 0, l = 0, temp2 = 0; //инициализация двух временных переменных и степени нашего результата
	for (int i = 0; i < a->len; i++) //до тех пор, пока не кончится число
	{
		c->n = (int*)realloc(c->n, (l + 1) * sizeof(int)); //выделение памяти под текущую цифру
		c->n[i] = 0; //обнуление первой временной переменной
		temp = a->n[i] * b + temp2; //присваиваем временной переменной сумму (произведения цифры исходного числа на цифру) и второй временной переменной
		temp2 = 0;//обнуление второй временной переменной
		if (temp > 9) //если произведение цифры исходного числа на цифру больше 9
		{
			c->n[i] = temp % 10; //присваиваем текущей цифре результата младший разряд первой временной переменной
			temp2 = temp / 10; //присваиваем второй временной переменной все остальные разряды
		}
		else
			c->n[i] = temp; //присваиваем текущей цифре первую временную переменную
		l++; //увеличиваем счётчик степени результата
	}
	if (temp2 != 0) { //если наше число необходимо увеличить
		c->n = (int*)realloc(c->n, (l + 1) * sizeof(int)); //выделяем память под новую цифру
		c->n[l] = temp2; //присваиваем этой цифре вторую временную переменную
		l++; //увеличиваем счётчик степени результата на 1
	}
	c->len = l; //присваиваем длине результата счётчик степени
	c = deNULL(c);
	return c;
}

// N-7

N* MUL_Nk_N(N* a, int b)
{
	N* c = zeroN();
	int len = a->len + b; // инициализируем размер суммой длины исходного числа и заданной степени k
	c->n = (int*)realloc(c->n, len * sizeof(int)); // выделяем память для нашего числа
	for (int i = 0; i < len; i++) // цикл до конца числа
	{
		if (i < b) // если счётчик меньше степни k
			c->n[i] = 0; // "домножаем" наше число на 10
		else
			c->n[i] = a->n[i - b]; // подставляем на новую позицию (на k больше) цифру исходного числа
	}
	c->len = len; // присваиваем длине результата сумму len
	c = deNULL(c);
	return c;
}

// N-8

N* MUL_NN_N(N* a, N* b)
{
	N* result = zeroN();
	N* temp, *tmp;
	for (int i = 0; i < b->len; i++) { // К результату, изначально равному 0, в каждом шаге цикла прибавляется i-ая цифра первого сомножителя
		tmp = MUL_ND_N(a, b->n[i]);
		temp = MUL_Nk_N(tmp, i); // умноженная на второй сомножитель и на 10^i
		freeN(tmp);
		tmp = ADD_NN_N(result, temp);
		freeN(result);
		result = assignmentN(tmp);
		freeN(tmp);
		freeN(temp);
	}
	return result;
}

// N-9

N* SUB_NDN_N(N* a, int d, N* b)
{
	N* first, *second;
	N* result;
	N* temp;
	if (COM_NN_D(a, b) == 2) { // если первое число больше второго
		first = assignmentN(a); // присваивание
		second = assignmentN(b);
	}
	else {
		first = assignmentN(b); // присваивание
		second = assignmentN(a);
	}
	temp = MUL_ND_N(second, d); // меньшее домножаем на цифру
	result = SUB_NN_N(first, temp); // вычитаем из большего числа меньшее (домноженное на цифру)
	free(temp);
	freeN(first);
	freeN(second);
	return result;
}

// N-10

int DIV_NN_Dk(N* a, N* b, int& k)
{
	int Result = 1, // Первая цифра деления
		Flag; // Переменная для выхода из цикла
	N* Temp; // Временная переменная для хранения произведения
	k = 0;
	N* First, *Second;
	if (COM_NN_D(a, b) == 2) { // если делимое - первое число
		First = assignmentN(a); // делимое 
		Second = assignmentN(b); // делитель
	}
	else { // наоборот
		First = assignmentN(b);
		Second = assignmentN(a);
	}
	do
	{
		Temp = MUL_Nk_N(Second, k); // Умножаем делитель на 10^k
		Flag = COM_NN_D(First, Temp); // Сравниваем делимое и произведение
		freeN(Temp);
		if (Flag != 1) // Если произведение меньше, то увеличиваем степень 10
			k++;
	} while (Flag != 1); // Пока произведение не станет больше делителя
	k--; // Так как при последнем сравнении k стало больше на 1 от необходимого
	Temp = MUL_Nk_N(Second, k); // Вычисляем наибольшее произведение делителя и 10^k, меньшее делимого
	do
	{
		N* tmp = MUL_ND_N(Temp, Result); // Вычисляем произведение на цифру
		Flag = COM_NN_D(First, tmp); // Сравниваем его с делимым
		if (Flag != 1) // Если произведение меньше делимого, проверяем следующую цифру
			Result++;
		freeN(tmp);
	} while (Flag != 1);
	Result--; // Аналогично значению степени
	freeN(Temp);
	freeN(First);
	freeN(Second);
	return Result;
}

// N-11

N* DIV_NN_N(N* a, N* b)
{
	N* First, *Second;
	if (COM_NN_D(a, b) == 2) {
		First = assignmentN(a);
		Second = assignmentN(b);
	}
	else {
		First = assignmentN(b);
		Second = assignmentN(a);
	}
	N* Result = zeroN(); // Частное от деления
	N* Part = assignmentN(First); // Временный остаток от деления
	N* TempRes, *Temp; // Временный делитель
	int Numb, // Первая цифра от деления
		Flag, // Переменная для выхода из цикла
		k = 0; // Степень десятки
	if (NZER_N_B(Second))
		do
		{
			Numb = DIV_NN_Dk(Part, Second, k); // Вычисляем первую цифру и степень десятки при делении
			TempRes = zeroN(); // 16 - 20 строки - это создание ппроизведения первой цифры деления на 10^k
			Temp = ADD_1N_N(TempRes); // Прибавим 1 - так как при умножении она никак не будет влиять на результат
			freeN(TempRes);
			TempRes = MUL_ND_N(Temp, Numb); // Умножаем 1 на первую цифру деления
			freeN(Temp);
			Temp = MUL_Nk_N(TempRes, k); // Умножаем на 10^k
			freeN(TempRes);
			TempRes = ADD_NN_N(Result, Temp); // Добавление временного результата к общему
			freeN(Result);
			Result = assignmentN(TempRes);
			freeN(TempRes);
			TempRes = MUL_NN_N(Temp, Second);
			freeN(Temp);
			Temp = SUB_NN_N(Part, TempRes); // Вычисление временного остатка
			freeN(Part);
			Part = assignmentN(Temp);
			freeN(Temp);
			Flag = COM_NN_D(Part, Second); // Сравниваем "делимое" и делитель
			freeN(TempRes);
		} while (Flag != 1);
		freeN(Part);
		freeN(First);
		freeN(Second);
		return Result;
}

// N-12

N* MOD_NN_N(N* num, N* mod) {
	// num - (num div mod) * mod
	N* temp, *tmp, *result;
	temp = DIV_NN_N(num, mod); // числитель от деления большего числа на меньшее
	if (COM_NN_D(num, mod) == 2) {

		tmp = MUL_NN_N(temp, mod); // произведение числителя и меньшего числа
		result = SUB_NN_N(num, tmp); // разность большего числа и произведения
	}
	else {
		tmp = MUL_NN_N(temp, num); // произведение числителя и меньшего числа
		result = SUB_NN_N(mod, tmp); // разность большего числа и произведения
	}
	freeN(temp);
	freeN(tmp);
	return result;
}

// N-13

N* GCF_NN_N(N* a, N* b)
{
	N* First = assignmentN(a);
	N* Second = assignmentN(b);
	N* temp;
	while (NZER_N_B(First) && NZER_N_B(Second)) //пока оба числа - не нули
	{
		if (COM_NN_D(First, Second) > 1) { // Если первое больше второго
			temp = MOD_NN_N(First, Second); // Находим остаток от деления первого на второе
			freeN(First);
			First = assignmentN(temp);
			freeN(temp);
		}
		else {
			temp = MOD_NN_N(Second, First); // Иначе - остаток от деления второго на первое
			freeN(Second);
			Second = assignmentN(temp);
			freeN(temp);
		}

	}
	if (COM_NN_D(First, Second) != 2) { // если первое число - больше второго
		freeN(First);
		First = assignmentN(Second); // меняем их местами
	}
	freeN(Second);
	return First;
}

// N-14

N* LCM_NN_N(N* First, N* Second)
{
	N* NOD = GCF_NN_N(First, Second); // НОД двух чисел
	N* Temp = MUL_NN_N(First, Second); // Произведение двух чисел
	N* NOK = DIV_NN_N(Temp, NOD); // НОК двух чисел
	freeN(NOD);
	freeN(Temp);
	return NOK;
}
