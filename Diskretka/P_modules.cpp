#include "P_modules.h"

P* deNullP(P* p)
{
	int i;
	bool flag = true;
	for (i = p->len; i >= 0 && flag; i--) // цикл до последней степени или пока поднят флаг
		if (p->k[i]->num->number->len != 1 || p->k[i]->num->number->n[0] != 0) // если исследуемый коэффициент - не ноль 
			flag = false; // опускаем флаг
	if (i == -1 && flag) {
		freeP(p);
		p = zeroP();
	}
	else {
		int len = p->len;
		p->len = i + 1; // увеличиваем степень многочлена на 1
		P* temp = assignmentP(p);
		p->len = len;
		freeP(p);
		p = assignmentP(temp);
		freeP(temp);
	}
	return p;
}

P* initP() {
	P* p = (P*)malloc(sizeof(P));
	p->k = (Q**)malloc(sizeof(Q*));
	p->k[0] = initQ();
	p->len = -1;
	return p;
}

P* inputP() {
	int *powerBuffer;
	int amount;
	int power;
	int maxPower = -1;
	P* p = (P*)malloc(sizeof(P));
	p->k = (Q**)malloc(sizeof(Q*));
	printf("Введите количество коэффициентов: ");
	do {
		amount = getNumber();
		if (amount == 0)
			printf("Введены некорректные данные. Введите число > 0: ");
	} while (amount == 0);
	powerBuffer = (int*)malloc(amount * sizeof(int));
	for (int i = 0; i < amount; i++) {
		printf("***\nКоэффициент %d\n", i + 1);
		Q* temp = inputQ();
		printf("Введите степень x: ");
		power = getNumber();
		if (power > maxPower) {
			maxPower = power;
			p->k = (Q**)realloc(p->k, (maxPower + 1) * sizeof(Q*));
			p->len = maxPower;
		}
		p->k[power] = assignmentQ(temp);
		freeQ(temp);
		powerBuffer[i] = power;
	}
	for (int i = maxPower; i >= 0; i--) {
		bool f = false;
		for (int j = 0; j < amount; j++)
			if (powerBuffer[j] == i) f = true;
		if (!f)
			p->k[i] = zeroQ();
	}
	free(powerBuffer);
	puts("");
	return p;
}

P* zeroP() {
	P* Result = (P*)malloc(sizeof(P));
	Result->k = (Q**)malloc(sizeof(Q*));
	Result->len = 0;
	Result->k[0] = zeroQ();
	return Result;
}

P* assignmentP(P* p) {
	P* a = (P*)malloc(sizeof(P));
	a->len = p->len;
	a->k = (Q**)malloc((a->len + 1) * sizeof(Q*));
	for (int i = 0; i <= a->len; i++)
		a->k[i] = assignmentQ(p->k[i]);
	return a;
}

void printP(P* p) {
	for (int i = p->len; i >= 0; i--) {
		if (!(p->k[i]->num->number->len == 1 && p->k[i]->num->number->n[0] == 0)) {
			if (i != p->len)
				if (p->k[i]->num->sign)
					printf("+ ");
			if (p->k[i]->num->number->len == 1 && p->k[i]->num->number->n[0] == 1 && i != 0 && p->k[i]->denom->len == 1 && p->k[i]->denom->n[0] == 1) {
				if (!p->k[i]->num->sign)
					printf("- ");
			}
			else {
				printQ(p->k[i]);
				if (i != 0)
					printf(" * ");
			}
			if (i > 1)
				printf("x^%d ", i);
			else if (i == 1)
				printf("x ");
		}
		else if (p->len == 0)
			printf("0");
	}
}

P* freeP(P* p) {
	for (int i = 0; i <= p->len; i++)
		freeQ(p->k[i]);
	free(p->k);
	free(p);
	return p;
}

// P-1 Ханов Александр

P* ADD_PP_P(P* a, P* b)
{
	P* First, *Second;
	// Определить, у какого многочлена степень больше и, если надо, поменять их местами
	if (a->len > b->len) {
		First = assignmentP(a);
		Second = assignmentP(b);
	}
	else {
		First = assignmentP(b);
		Second = assignmentP(a);
	}
	P* Result = (P*)malloc(sizeof(P));
	Result->k = (Q**)malloc((First->len + 1) * sizeof(Q*)); // Сумма многочленов
	Result->len = First->len; // Степень суммы равна степени большего из многочленов
	for (int i = First->len; i >= 0; i--) // цикл от старшей степени большего числа до последней 
	{
		if (i > Second->len) // Если исследуемая степень первого многочлена больше степени второго
			Result->k[i] = assignmentQ(First->k[i]); // Присваиваем сумме коэффициент первого многочлена (т.к. у второго их в памяти нет)
		else
			Result->k[i] = ADD_QQ_Q(First->k[i], Second->k[i]); // Иначе производим сложение коэффициентов
	}
	freeP(First);
	freeP(Second);
	return deNullP(Result);
}

// P-2 Ханов Александр

P* SUB_PP_P(P* First, P* Second)
{
	P* SecondCopy = assignmentP(Second); // копируем значение второго многочлена
	for (int i = 0; i <= Second->len; i++)
		SecondCopy->k[i]->num->sign = !Second->k[i]->num->sign; // меняем знак коэффициентов 2го полинома (его копии) 
	P* Result = ADD_PP_P(First, SecondCopy); // суммируем первый многочлен и (-1)*второй многочлен
	freeP(SecondCopy);
	return Result;
}

// P-3 Ханов Александр

P* MUL_PQ_P(P* Polyn, Q* Numb)
{
	P* Result = (P*)malloc(sizeof(P));
	Result->k = (Q**)malloc((Polyn->len + 1) * sizeof(Q*));
	Result->len = Polyn->len;
	for (int i = 0; i <= Result->len; i++) // цикл от старшего коэффициента до младшего
		Result->k[i] = MUL_QQ_Q(Polyn->k[i], Numb); // присваиваем текущему коэффициенту результат произведения текущего коэффициента исходного
	return deNullP(Result); // многочлена на рациональное число
}

// P-4 Дяченко Виталий

P* MUL_Pxk_P(P* Polyn, int k) {
	P* Result = (P*)malloc(sizeof(P));
	Result->k = (Q**)malloc(sizeof(Q*));
	int i; // Для перебора коэффициентов
	Result->k = (Q**)realloc(Result->k, (Polyn->len + k + 1) * sizeof(Q*)); // Выделение памяти
	Result->len = Polyn->len + k; // присваиваем степени многочлена-результата сумму степени исходного многочлена и степени k
	for (i = Result->len; i >= k; i--) // цикл от старшего коэффициента многочлена до степени k
		Result->k[i] = assignmentQ(Polyn->k[i - k]); // присваиваем текущему коэффициенту многочлена-результата коэффициент исходного многочлена "отстающий" на k
	for (i = k - 1; i >= 0; i--) // цикл от степени k-1 до младшего коэффициента многочлена
		Result->k[i] = zeroQ(); // смещаем наш многочлен на одну степень
	return Result;
}

// P-5 Львов Денис

Q* LED_P_Q(P* p) {
	for (int i = p->len; i >= 0; i--) // цикл от старшей степени многочлена до младшей
		if (!(p->k[i]->num->number->len == 1 && p->k[i]->num->number->n[0] == 0)) // если текущий коэффициент = 0
			return assignmentQ(RED_Q_Q(p->k[i])); // возвращаем сокращенное значение этого коэффициента
	return assignmentQ(RED_Q_Q(p->k[0])); // в крайнем случае возвращаем сокращенное значение младшего коэффициента
}

// P-6 Тюльников Виктор

N* DEG_P_N(P* p) {
	int power = 0; // счётчик степени
	bool flag = true; // инициализируем флаг каак поднятый
	for (int i = p->len; i >= 0 && flag; i--) // цикл до младшего коэффициента многочлена или пока поднят флаг
		if (!(p->k[i]->num->number->len == 1 && p->k[i]->num->number->n[0] == 0)) { // если исследуемый коэффициент = 0
			power = i; // останавливаемся в подсчёте степени
			flag = false; // опускаем флаг
		}
	return intToN(power);
}

// P-7 Зерцалов Владимир

Q* FAC_P_Q(P* Polyn)
{
	N* NOD = assignmentN(Polyn->k[Polyn->len]->num->number); // НОД числителей, изначально присваиваем значение, равное числителю старшего коэффициента многочлена
	N* NOK = assignmentN(Polyn->k[Polyn->len]->denom); // НОК знаменателей, изначально присваиваем значение, равное знаменателю старшего коэффициента многочлена
	Q* Result = (Q*)malloc(sizeof(Q)); // Числитель дроби - НОД числителей, знаменатель - НОК знаменателей
	Result->num = (Z*)malloc(sizeof(Z));
	N* temp;
	short i, // Для перебора коэффициентов многочлена
		Flag; // Для корректной работы цикла 
	for (i = (Polyn->len) - 1; i >= 0; i--) { // Перебираем все коэффициенты многочлена, начиная с "предстаршего" (т.к. старший занес в НОК изначально)
		temp = LCM_NN_N(NOK, Polyn->k[i]->denom); // Находим поочередно НОК общего НОК и данного коэффициента	
		freeN(NOK);
		NOK = assignmentN(temp);
		freeN(temp);
	}
	for (i = (Polyn->len) - 1; i >= 0; i--) // Перебираем все коэффициенты многочлена, начиная с "предстаршего" (т.к. старший занес в НОД изначально)
	{
		Flag = POZ_Z_D(Polyn->k[i]->num); // Проверка коэффициента на нуль
		if (Flag != 0) {
			temp = GCF_NN_N(NOD, Polyn->k[i]->num->number); // Находим поочередно НОД общего НОД и данного коэффициента
			freeN(NOD);
			NOD = assignmentN(temp);
			freeN(temp);
		}

	}
	Result->num->number = assignmentN(NOD); // Присваиваем Result->num значение NOD
	Result->num->sign = true;
	Result->denom = assignmentN(NOK); // Присваиваем Result->denom значение НОК
	freeN(NOD);
	freeN(NOK);
	return Result;
}

// P-8 Смирнов Иван

P* MUL_PP_P(P* First, P* Second)
{
	int i = First->len; // Для перебора коэффициентов многочлена
	P* Result; // Результат умножения
	P* Temp, *tmp; // Результат умножения первого многочлена на коэффициент второго
	if (i > 0) {
		Temp = MUL_PQ_P(Second, First->k[i]); // Умножаем второй многочлен поочередно на все коэффициенты первого
		Result = MUL_Pxk_P(Temp, i); // Умножаем произведение на текущую исследуемую степень первого многочлена
		freeP(Temp);
		for (i = First->len - 1; i >= 0; i--) {
			Temp = MUL_PQ_P(Second, First->k[i]); // Умножаем второй многочлен поочередно на все коэффициенты первого
			tmp = MUL_Pxk_P(Temp, i); // Умножаем произведение на текущую исследуемую степень первого многочлена
			freeP(Temp);
			Temp = ADD_PP_P(Result, tmp); // Прибавление к результату произведения
			freeP(Result);
			Result = assignmentP(Temp);
			freeP(Temp);
			freeP(tmp);
		}
	}
	else
		Result = zeroP();
	return Result;
}

// P-9 Смирнов Иван

P* DIV_PP_P(P* First, P* Second)
{
	P* Result = (P*)malloc(sizeof(P)); // Частное от деления многочленов
	P *Temp, *tmp; // Временная переменная
	P* Part = assignmentP(First); // Остаток от деления
	int i; // Для перебора коэффициентов
	Q* Coef; // Коэффициент при исследуемой степени результата
	Result->len = First->len - Second->len;
	Result->k = (Q**)malloc((Result->len + 1) * sizeof(Q*));
	if (Result->len < 0) {
		freeP(Result);
		Result = zeroP();
	}
	else
		for (i = First->len; i >= Second->len; i--)
		{
			if (i <= Part->len)
				Coef = DIV_QQ_Q(Part->k[i], Second->k[Second->len]); // Вычисления коэффициента перед степенью в результате
			else
				Coef = zeroQ();
			Result->k[i - Second->len] = assignmentQ(Coef); // Заносим найденный коэффициент в поле ответа
			Temp = MUL_PQ_P(Second, Coef); // Умножение делителя на "подходящий" коэффициент
			tmp = MUL_Pxk_P(Temp, (i - Second->len)); // Возведение в необходимую степень
			freeP(Temp);
			Temp = SUB_PP_P(Part, tmp); // Вычитаем из остатка часть частного, умноженную на делитель
			freeP(tmp);
			freeP(Part);
			Part = assignmentP(Temp);
			freeP(Temp);
			freeQ(Coef);
		}
	freeP(Part);
	return Result;
}

// P-10 Якушев Илья

P* MOD_PP_P(P* a, P* b) //Принимает на вход a, b, result и записывает в result остаток от деления a на b 
{
	P* result = DIV_PP_P(a, b); // результат деления большего многочлена на меньший без остатка
	P* temp = MUL_PP_P(result, b); // произведение результата от деления и меньшего многочлена
	freeP(result);
	result = SUB_PP_P(a, temp); // разность большего многочлена и произведения
	freeP(temp);
	return result;
}

// P-11 Якушев Илья

P* GCF_PP_P(P* a, P* b)
{
	P* ost;
	P* first = assignmentP(a);
	P* second = assignmentP(b);
	P* temp;
	while ((second->len != 0 || NZER_N_B(second->k[0]->num->number)) && (first->len != 0 || NZER_N_B(first->k[0]->num->number))) // цикл пока оба многочлена - не нулевые
	{
		if (first->len > second->len) { // если степень первого многочлена больше степени второго
			temp = MOD_PP_P(first, second); // присваиваем ему остаток от деления многочленов
			freeP(first);
			first = assignmentP(temp); // наоборот
			freeP(temp);
		}
		else {
			temp = MOD_PP_P(second, first);
			freeP(second);
			second = assignmentP(temp);
			freeP(temp);
		}
	}
	if (first->len > second->len) // если степень первого многочлена оказалась больше второго
		ost = assignmentP(first); // присваиваем результату (остатку) значение первого многочлена
	else
		ost = assignmentP(second); //наоборот
	freeP(first);
	freeP(second);
	return ost;
}

// P-12 Львов Денис

P* DER_P_P(P* p) {
	//Выделение память под многочлен
	P* res = (P*)malloc(sizeof(P));
	res->k = (Q**)malloc(p->len * sizeof(Q*));
	res->len = p->len - 1;
	Z* temp;
	Q* tmp;
	//Расчет коэффициентов
	for (int i = p->len - 1; i >= 0; i--) { // цикл до младшего коэффициента многочлена
		N* iton = intToN(i + 1);
		temp = TRANS_N_Z(iton);
		freeN(iton);
		tmp = TRANS_Z_Q(temp);
		res->k[i] = MUL_QQ_Q(p->k[i + 1], tmp); //присваиваем текущему коэффициенту значение 
		freeZ(temp); //(произведения следующего коэффициента и (преобразованной в дробное число степени следующего коэффициента))
		freeQ(tmp);
	}
	return res;
}

// P-13 Якубов Владислав

P* NMR_P_P(P* a)
{
	P* Result = DER_P_P(a); // инициализируем результат производной от исходного многочлена
	P* Temp = GCF_PP_P(a, Result); // присваиваем результату значение НОКа исходного многочлена и результата
	freeP(Result);
	Result = DIV_PP_P(a, Temp); // частное от деления многочленов  
	freeP(Temp);
	Q* q = zeroQ();
	q->num->number->n[0] = 1;
	Q* tmp = FAC_P_Q(Result);
	Q* tmpr = DIV_QQ_Q(q, tmp);
	Temp = assignmentP(Result);
	freeP(Result);
	Result = MUL_PQ_P(Temp, tmpr); // присваиваем результату значение произведения (предыдущего значения результата и 
	freeQ(tmp); // (вынесенного из многочлена НОК знаменателей коэффициентов и НОД числителей в степени -1))
	freeQ(tmpr);
	freeP(Temp);
	freeQ(q);
	return Result;
}
