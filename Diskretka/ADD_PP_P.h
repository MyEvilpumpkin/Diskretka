#pragma once
// P-1

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
	P* Result = initP(); // Сумма многочленов
	Result->k = (Q**)realloc(Result->k, (First->len+1)* sizeof(Q*)); // Освобождаем память под коэффициенты результата
	Result->len = First->len; // Степень суммы равна степени большего из многочленов
	for (int i = First->len; i >= 0; i--)
	{
		if (i > Second->len) // Если исследуемая степень первого многочлена больше степени второго
			Result->k[i] = assignmentQ(First->k[i]); // Присваиваем сумме коэффициент первого многочлена (т.к. у второго их в памяти нет)
		else
			Result->k[i] = ADD_QQ_Q(First->k[i], Second->k[i]); // Иначе производим сложение коэффициентов
	}
	bool flag = true;
	int i;
	for (i = First->len; i >= 0 && flag; i--)
		if (Result->k[i]->num->number->len != 1 || Result->k[i]->num->number->n[0] != 0)
			flag = false;
	if (i == -1 && flag)
		Result = zeroP();
	else {
		Result->k = (Q**)realloc(Result->k, (i + 2) * sizeof(Q*));
		Result->len = i + 1;
	}
	return Result;
}