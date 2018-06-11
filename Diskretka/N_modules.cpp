#include "N_modules.h"

int getNumber() {
	char* number = NULL;
	int toReturn;
	char symbol;
	int lenght = 0;
	bool error;
	do {
		lenght = 0;
		error = false;
		do {
			symbol = getchar();
			if (symbol >= '0' && symbol <= '9') {
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

N* deNULL(N* n) {
	if (n->len != 0) {
		int i = 1,
			l = n->len;
		for (int j = 0; j < l; j++)
			i = n->n[j] == 0 ? i : j + 1;
		n->n = (int*)realloc(n->n, i * sizeof(int));
		n->len = i;
	}
	return n;
}

N* intToN(int x) {
	N* n = initN();
	int len = 0, buffer = x;
	while (buffer > 0) {
		buffer = buffer / 10;
		len++;
	}
	n->len = len;
	n->n = (int*)realloc(n->n, len * sizeof(int));
	for (int i = len - 1; i >= 0; i--) {
		n->n[len - 1 - i] = x % 10;
		x /= 10;
	}
	return n;
}

N* input() {
	char *symbol = (char*)malloc(sizeof(char));
	int *k = NULL, len = 0;
	N *number = initN();
	bool error = false;
	do {
		*symbol = getchar();
		if ('0' <= *symbol && *symbol <= '9') {
			k = (int*)realloc(k, (len + 1) * sizeof(int));
			k[len] = atoi(symbol);
			len++;
		}
		else if (*symbol != '\n')
			error = true;
		else if (!error && len == 0)
			number->len = 0;
	} while (*symbol != '\n');
	if (!error && len > 0) {
		number->n = (int*)realloc(number->n, len * sizeof(int));
		number->len = len;
		for (int i = 0; i < len; i++)
			number->n[i] = k[len - i - 1];
	}
	free(k);
	free(symbol);
	return number;
}

N* initN() {
	N* n = (N*)malloc(sizeof(N));
	n->n = (int*)malloc(sizeof(int));
	n->len = -1;
	return n;
}

N* inputN() {
	N* number = initN();
	do {
		freeN(number);
		number = input();
		if (number->len == -1)
			printf("Введены некорректные данные. Введите натуральное число: ");
	} while (number->len < 1);
	number = deNULL(number);
	return number;
}

N* zeroN() {
	N* n = initN();
	n->len = 1;
	n->n[0] = 0;
	return n;
}

N* assignmentN(N* n) {
	N* a = initN();
	int l = n->len;
	a->n = (int*)realloc(a->n, l * sizeof(int));
	for (int i = 0; i < l; i++)
		a->n[i] = n->n[i];
	a->len = l;
	return a;
}

void printN(N* num) {
	for (int i = num->len - 1; i >= 0; i--)
		printf("%d", num->n[i]);
}

N* freeN(N* n) {
	free(n->n);
	free(n);
	return n;
}

// N-1 Масленникова Дарья

int COM_NN_D(N* a, N* b)
{
	if (a->len > b->len) // если первое число больше второго
		return 2;
	if (a->len < b->len) // если второе число больше первого
		return 1;
	else
	{
		for (int i = a->len - 1; i >= 0; i--) // цикл до последней числа
		{
			if (a->n[i] > b->n[i]) // если цифра первого числа больше цифры второго
				return 2;
			if (a->n[i] < b->n[i]) // наоборот
				return 1;
		}
		return 0; // если длины двух чисел и все их цифры оказались равны (числа равны)
	}
}

// N-2 Малюкова Мария

bool NZER_N_B(N* a) {
	return (a->len != 1 || a->n[0] != 0); // число не состоит из одного знака или не имеет на конце 0,
} // если оба этих условия выполняются, то число - ноль

// N-3 Сапрунов Степан

N* ADD_1N_N(N* n)
{
	N* a = assignmentN(n);
	if (a->n[0] != 9) // Если последний разряд числа не равен 9, то прибавляем к нему единицу
		(a->n[0])++;
	else // Если последний разряд равен 9, то заменяем его и все последующие девятки на нули и прибавляем единицу к первой не девятке 
	{
		unsigned int count = 0;
		while (a->n[count] == 9)
			(a->n[count++]) = 0;
		if (count == a->len) // Если в числе все цифры девятки, то необходимо создать новый разряд
		{
			a->len++; // Увеличиваем длину числа на 1
			a->n = (int*)realloc(a->n, (a->len) * sizeof(int));  // Создаём новый разряд
			a->n[count] = 1;  // Значение нового разряда равно единице
		}
		else
			(a->n[count])++;  // Если в числе не все девятки, то первую не девятку увеличиваем на единицу
	}
	return a;
}

// N-4 Мартынова Ксения

N* ADD_NN_N(N* a, N* b)
{
	N* result;
	if (COM_NN_D(a, b) == 2) // Если a>b
	{
		result = assignmentN(a); // Будем прибавлять к а
		int size = b->len; // Если у b меньше разрядов чем у а, то нет нужды изменять разряды, начиная с b->len+2
		for (int i = 0; i < size; i++)
		{
			result->n[i] += b->n[i]; // Складываем соответствующие разряды
			if (result->n[i]>9)	// Если результат больше 9, то берём остаток от деления на 10 и добавляем единицу в следующий разряд
			{
				result->n[i] %= 10;
				int g = i;
				do {
					if (g == result->len - 1) // Если следующего разряда нет, то он создаётся
					{
						result->n = (int*)realloc(result->n, (++result->len) * sizeof(int));
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
	else // Если a<b
	{
		result = assignmentN(b); // Будем прибавлять к b
		int size = a->len; // Если у а меньше разрядов чем у b, то нет нужды изменять разряды, начиная с a->len+2
		for (int i = 0; i < size; i++)
		{
			result->n[i] += a->n[i]; // Складываем соответствующие разряды
			if (result->n[i]>9)	// Если результат больше 9, то берём остаток от деления на 10 и добавляем единицу в следующий разряд
			{
				result->n[i] %= 10;
				int g = i;
				do {
					if (g == result->len - 1) // Если следующего разряда нет, то он создаётся
					{
						result->n = (int*)realloc(result->n, (++result->len) * sizeof(int));
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

// N-5 Марушевский Тихон

N* SUB_NN_N(N* a, N* b) {
	N* c = zeroN();
	bool temp = false;
	if (COM_NN_D(a, b) == 2) { // проверка на правильность введенных данных
		c->n = (int*)realloc(c->n, a->len * sizeof(int)); // выделение памяти под очередную цифру результата
		c->len = a->len;
		for (int i = 0; i < a->len; i++) { // цикл до конца числа
			if (i < b->len) { // если счётчик меньше длины меньшего числа (числа "накладываются" друг на друга)
				if (a->n[i] >= b->n[i] + temp) { // если цифра большего числа больше или равна цифре меньшего числа
					c->n[i] = a->n[i] - b->n[i] - temp; // проводим обыкновенное вычитание
					temp = false;
				}
				else { // если цифра большего числа меньше цифры меньшего числа
					c->n[i] = a->n[i] + 10 - b->n[i] - temp;
					temp = true;
				}
			}
			else {
				if (temp) {
					if (a->n[i] == 0)
						c->n[i] = 9;
					else {
						c->n[i] = a->n[i] - temp;
						temp = false;
					}
				}
				else
					c->n[i] = a->n[i]; // иначе мы ничего с цифрами не делаем, а просто "переписываем" их в результат
			}
		}
		deNULL(c); // (отбрасываем образовавшиеся незначащие нули)
	}
	return c;
}

// N-6 Скуфин Демид

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

// N-7 Скуфин Демид

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

// N-8 Калимулин Вячеслав

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

// N-9 Марушевский Тихон

N* SUB_NDN_N(N* a, N* b, int d)
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

// N-10 Павлов Андрей

int DIV_NN_Dk(N* a, N* b, int &k)
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

// N-11 Павлов Андрей

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

// N-12 Макаренко Данил

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

// N-13 Оранская Мария

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

// N-14 Оранская Мария

N* LCM_NN_N(N* First, N* Second)
{
	N* NOD = GCF_NN_N(First, Second); // НОД двух чисел
	N* Temp = MUL_NN_N(First, Second); // Произведение двух чисел
	N* NOK = DIV_NN_N(Temp, NOD); // НОК двух чисел
	freeN(NOD);
	freeN(Temp);
	return NOK;
}
