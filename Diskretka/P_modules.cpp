#include "P_modules.h"

// Удаление незначащих слагаемых со старшими коэффициентами
P* deNullP(P* p)
{
	if (p->len > 0)
	{
		int i;
		bool flag = true;
		for (i = p->len; i >= 0 && flag; i--) // Цикл до последней степени или пока поднят флаг
			if (POZ_Z_D(p->k[i]->num)) // Если исследуемый коэффициент - не ноль 
				flag = false; // Опускаем флаг
		if (!flag || i == -1)
		{
			for (int len = p->len; len > i + 1; len--)
				freeQ(p->k[len]);
			p->len = i + 1;
			p->k = (Q**)realloc(p->k, (p->len + 1) * sizeof(Q*));
		}
	}
	return p;
}

// Ввод
P* inputP()
{
	int amount;
	int maxPower = -1;
	P* p = (P*)malloc(sizeof(P));
	p->k = (Q**)malloc(sizeof(Q*));
	printf("Введите количество коэффициентов: ");
	do
	{
		amount = getNumber();
		if (amount == 0)
			printf("Введены некорректные данные. Введите число > 0: ");
	} while (amount == 0);
	int* powerBuffer = (int*)malloc(amount * sizeof(int));
	for (int i = 0; i < amount; i++)
	{
		printf("***\nКоэффициент %d\n", i + 1);
		Q* temp = inputQ();
		printf("Введите степень x: ");
		int power = getNumber();
		if (power > maxPower)
		{
			maxPower = power;
			p->k = (Q**)realloc(p->k, (maxPower + 1) * sizeof(Q*));
			p->len = maxPower;
		}
		bool f = false;
		for (int j = 0; j < i && !f; j++)
			if (powerBuffer[j] == power) f = true;
		if (f)
			freeQ(p->k[power]);
		p->k[power] = assignmentQ(temp);
		freeQ(temp);
		powerBuffer[i] = power;
	}
	for (int i = maxPower; i >= 0; i--)
	{
		bool f = false;
		for (int j = 0; j < amount && !f; j++)
			if (powerBuffer[j] == i) f = true;
		if (!f)
			p->k[i] = zeroQ();
	}
	free(powerBuffer);
	puts("");
	return p;
}
// Инициализация с обнулением
P* zeroP()
{
	P* p = (P*)malloc(sizeof(P));
	p->k = (Q**)malloc(sizeof(Q*));
	p->len = 0;
	p->k[0] = zeroQ();
	return p;
}
// Присваивание
P* assignmentP(P* p)
{
	P* result = (P*)malloc(sizeof(P));
	result->len = p->len;
	result->k = (Q**)malloc((result->len + 1) * sizeof(Q*));
	for (unsigned int i = 0; i <= result->len; i++)
		result->k[i] = assignmentQ(p->k[i]);
	return result;
}
// Вывод
void printP(P* p)
{
	for (int i = p->len; i >= 0; i--)
	{
		if (!(p->k[i]->num->number->len == 1 && p->k[i]->num->number->n[0] == 0))
		{
			if (i != p->len)
				if (p->k[i]->num->sign)
					printf("+ ");
			if (p->k[i]->num->number->len == 1 && p->k[i]->num->number->n[0] == 1 && i != 0 && p->k[i]->denom->len == 1 && p->k[i]->denom->n[0] == 1)
			{
				if (!p->k[i]->num->sign)
					printf("- ");
			}
			else
			{
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
// Освобождение памяти
P* freeP(P* p)
{
	for (unsigned int i = 0; i <= p->len; i++)
		freeQ(p->k[i]);
	free(p->k);
	free(p);
	return p;
}

// P-1
P* ADD_PP_P(P* p1, P* p2)
{
	P* result = (P*)malloc(sizeof(P));
	P *first, *second;
	if (p1->len > p2->len) // Определить, у какого многочлена степень больше и, если надо, поменять их местами
	{
		first = p1;
		second = p2;
	}
	else
	{
		first = p2;
		second = p1;
	}
	result->k = (Q**)malloc((first->len + 1) * sizeof(Q*)); // Выделяем память для суммы многочленов
	result->len = first->len; // Степень суммы равна степени большего из многочленов
	for (unsigned int i = 0; i <= first->len; i++) // Цикл от младшей степени большего числа до последней 
	{
		if (i > second->len) // Если исследуемая степень первого многочлена больше степени второго
			result->k[i] = assignmentQ(first->k[i]); // Присваиваем сумме коэффициент первого многочлена (т.к. у второго их в памяти нет)
		else
			result->k[i] = ADD_QQ_Q(first->k[i], second->k[i]); // Иначе производим сложение коэффициентов
	}
	return deNullP(result);
}
// P-2
P* SUB_PP_P(P* p1, P* p2)
{
    P* result = (P*)malloc(sizeof(P));
    P *first, *second;
    if (p1->len > p2->len) // Определить, у какого многочлена степень больше и, если надо, поменять их местами
    {
        first = p1;
        second = p2;
    }
    else
    {
        first = p2;
        second = p1;
    }
    result->k = (Q**)malloc((first->len + 1) * sizeof(Q*)); // Выделяем память для разности многочленов
    result->len = first->len; // Степень разности равна степени большего из многочленов
    for (unsigned int i = 0; i <= first->len; i++) // Цикл от младшей степени большего числа до последней
    {
        if (i > second->len) // Если исследуемая степень первого многочлена больше степени второго
		{
            result->k[i] = assignmentQ(first->k[i]); // Присваиваем разности коэффициент первого многочлена (т.к. у второго их в памяти нет)
            result->k[i]->num->sign = !result->k[i]->num->sign; // Меняем знак
        }
        else
            result->k[i] = SUB_QQ_Q(p1->k[i], p2->k[i]); // Иначе производим вычитание коэффициентов
    }
    return deNullP(result);
}
// P-3
P* MUL_PQ_P(P* p, Q* q)
{
	P* result = (P*)malloc(sizeof(P));
	result->k = (Q**)malloc((p->len + 1) * sizeof(Q*));
	result->len = p->len;
	for (unsigned int i = 0; i <= result->len; i++) // Цикл от старшего коэффициента до младшего
		result->k[i] = MUL_QQ_Q(p->k[i], q); // Присваиваем текущему коэффициенту результат произведения текущего коэффициента исходного
	return deNullP(result); // Многочлена на рациональное число
}
// P-4
P* MUL_Pxk_P(P* p, int k)
{
	P* result = (P*)malloc(sizeof(P));
	result->k = (Q**)malloc((p->len + k + 1) * sizeof(Q*)); // Выделение памяти
	result->len = p->len + k; // Присваиваем степени многочлена-результата сумму степени исходного многочлена и степени k
	for (int i = result->len; i >= k; i--) // Цикл от старшего коэффициента многочлена до степени k
		result->k[i] = assignmentQ(p->k[i - k]); // Присваиваем текущему коэффициенту многочлена-результата коэффициент исходного многочлена "отстающий" на k
	for (int i = k - 1; i >= 0; i--) // Цикл от степени k-1 до младшего коэффициента многочлена
		result->k[i] = zeroQ(); // Смещаем наш многочлен на одну степень
	return deNullP(result);
}
// P-5
Q* LED_P_Q(P* p)
{
	for (int i = p->len; i >= 0; i--) // Цикл от старшей степени многочлена до младшей
		if (POZ_Z_D(p->k[i]->num)) // Если текущий коэффициент != 0
			return assignmentQ(RED_Q_Q(p->k[i])); // Возвращаем сокращенное значение этого коэффициента
	return assignmentQ(RED_Q_Q(p->k[0])); // В крайнем случае возвращаем сокращенное значение младшего коэффициента
}
// P-6
N* DEG_P_N(P* p)
{
	int power = 0; // Счётчик степени
	bool flag = true; // Инициализируем флаг как поднятый
	for (int i = p->len; i >= 0 && flag; i--) // Цикл до младшего коэффициента многочлена или пока поднят флаг
		if (POZ_Z_D(p->k[i]->num)) // Если исследуемый коэффициент != 0
		{
			power = i; // Останавливаемся в подсчёте степени
			flag = false; // Опускаем флаг
		}
	return intToN(power);
}
// P-7
Q* FAC_P_Q(P* p)
{
	N* nod = assignmentN(p->k[p->len]->num->number); // НОД числителей, изначально присваиваем значение, равное числителю старшего коэффициента многочлена
	N* nok = assignmentN(p->k[p->len]->denom); // НОК знаменателей, изначально присваиваем значение, равное знаменателю старшего коэффициента многочлена
	Q* result = (Q*)malloc(sizeof(Q)); // Числитель дроби - НОД числителей, знаменатель - НОК знаменателей
	result->num = (Z*)malloc(sizeof(Z));
	N* temp;
	int i; // Для перебора коэффициентов многочлена
	for (i = (p->len) - 1; i >= 0; i--) // Перебираем все коэффициенты многочлена, начиная с "предстаршего" (т.к. старший занес в НОК изначально)
	{
		temp = LCM_NN_N(nok, p->k[i]->denom); // Находим поочередно НОК общего НОК и данного коэффициента	
		freeN(nok);
		nok = temp;
	}
	for (i = (p->len) - 1; i >= 0; i--) // Перебираем все коэффициенты многочлена, начиная с "предстаршего" (т.к. старший занес в НОД изначально)
	{
		int flag = POZ_Z_D(p->k[i]->num); // Проверка коэффициента на нуль
		if (flag) {
			temp = GCF_NN_N(nod, p->k[i]->num->number); // Находим поочередно НОД общего НОД и данного коэффициента
			freeN(nod);
			nod = temp;
		}
	}
	result->num->number = nod; // Присваиваем result->num значение nod
	result->num->sign = true;
	result->denom = nok; // Присваиваем result->denom значение НОК
	return result;
}
// P-8
P* MUL_PP_P(P* p1, P* p2)
{
	P *result = zeroP();
	for (unsigned int i = 0; i <= p1->len; i++)
	{
		P* temp = MUL_PQ_P(p2, p1->k[i]); // Умножаем второй многочлен поочередно на все коэффициенты первого
		P* tmp = MUL_Pxk_P(temp, i); // Умножаем произведение на текущую исследуемую степень первого многочлена
		freeP(temp);
		temp = ADD_PP_P(result, tmp); // Прибавление к результату произведения
		freeP(result);
		result = temp;
		freeP(tmp);
	}
	return result;
}
// P-9
P* DIV_PP_P(P* p1, P* p2)
{
	P* result; // Частное от деления многочленов
	if (p1->len < p2->len)
		result = zeroP();
	else
	{
		result = (P*)malloc(sizeof(P));
		result->len = p1->len - p2->len;
		result->k = (Q**)malloc((result->len + 1) * sizeof(Q*));
		P* part = assignmentP(p1); // Остаток от деления
		for (unsigned int i = p1->len; i >= p2->len; i--)
		{
			if (i <= part->len)
				result->k[i - p2->len] = DIV_QQ_Q(part->k[i], p2->k[p2->len]); // Вычисления коэффициента перед степенью в результате
			else
				result->k[i - p2->len] = zeroQ();
			P* temp = MUL_PQ_P(p2, result->k[i - p2->len]); // Умножение делителя на "подходящий" коэффициент
			P* tmp = MUL_Pxk_P(temp, (i - p2->len)); // Возведение в необходимую степень
			freeP(temp);
			temp = SUB_PP_P(part, tmp); // Вычитаем из остатка часть частного, умноженную на делитель
			freeP(tmp);
			freeP(part);
			part = temp;
		}
		freeP(part);
	}	
	return result;
}
// P-10
P* MOD_PP_P(P* p1, P* p2)
{
	P* result = DIV_PP_P(p1, p2); // Результат деления большего многочлена на меньший без остатка
	P* temp = MUL_PP_P(result, p2); // Произведение результата от деления и меньшего многочлена
	freeP(result);
	result = SUB_PP_P(p1, temp); // Разность большего многочлена и произведения
	freeP(temp);
	return result;
}
// P-11
P* GCF_PP_P(P* p1, P* p2)
{
	P *result, *temp;
	P* first = assignmentP(p1);
	P* second = assignmentP(p2);
	while ((second->len != 0 || NZER_N_B(second->k[0]->num->number)) && (first->len != 0 || NZER_N_B(first->k[0]->num->number))) // Цикл пока оба многочлена - не нулевые
	{
		if (first->len > second->len) // Если степень первого многочлена больше степени второго
		{
			temp = MOD_PP_P(first, second); // Присваиваем ему остаток от деления многочленов
			freeP(first);
			first = temp;
		}
		else
		{
			temp = MOD_PP_P(second, first);
			freeP(second);
			second = temp;
		}
	}
	if (first->len > second->len) // Если степень первого многочлена оказалась больше второго
	{
		result = first; // Присваиваем результату (остатку) значение первого многочлена
		freeP(second);
	}
	else
	{
		result = second; // Наоборот
		freeP(first);
	}
	return result;
}
// P-12
P* DER_P_P(P* p)
{
	P* result = (P*)malloc(sizeof(P));
	result->k = (Q**)malloc(p->len * sizeof(Q*));
	result->len = p->len - 1;
	for (int i = p->len - 1; i >= 0; i--) // Цикл до младшего коэффициента многочлена
	{
		N* iton = intToN(i + 1);
		Z* temp = TRANS_N_Z(iton);
		freeN(iton);
		Q* tmp = TRANS_Z_Q(temp);
		result->k[i] = MUL_QQ_Q(p->k[i + 1], tmp); // Присваиваем текущему коэффициенту значение 
		freeZ(temp);
		freeQ(tmp);
	}
	return result;
}
// P-13
P* NMR_P_P(P* p)
{
	P* result = DER_P_P(p); // Инициализируем результат производной от исходного многочлена
	P* temp = GCF_PP_P(p, result); // Присваиваем результату значение НОКа исходного многочлена и результата
	freeP(result);
	result = DIV_PP_P(p, temp); // Частное от деления многочленов  
	freeP(temp);
	Q* q = zeroQ();
	q->num->number->n[0] = 1;
	Q* tmp = FAC_P_Q(result);
	Q* tmpr = DIV_QQ_Q(q, tmp);
	temp = result;
	result = MUL_PQ_P(temp, tmpr); // Присваиваем результату значение произведения
	freeQ(tmp);
	freeQ(tmpr);
	freeP(temp);
	freeQ(q);
	return result;
}
