#pragma once
// P-1

P* ADD_PP_P(P* first, P* second)
{
	int i; // Для перебора многочленов по степеням 
	P* Result = (P*)malloc(sizeof(P)); // Сумма многочленов 
	int greatPower = first->len > second->len ? first->len : second->len;
	// Определить, у какого многочлена степень больше и, если надо, поменять их местами 
	Result->k = (Q**)malloc((greatPower + 1) * sizeof(Q*)); // Освобождаем память под коэффициенты результата 
	Result->len = greatPower; // Степень суммы равна степени большего из многочленов 
	for (i = greatPower; i >= 0; i--)
	{
		if (i > second->len) // Если исследуемая степень первого многочлена больше степени второго 
			Result->k[i] = RED_Q_Q(first->k[i]); // Присваиваем сумме коэффициент первого многочлена (т.к. у второго их в памяти нет) 
		else
			Result->k[i] = ADD_QQ_Q(first->k[i], second->k[i]); // Иначе производим сложение коэффициентов 
	}
	return Result;
}