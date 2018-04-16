#pragma once
// P-3

P* MUL_PQ_P(P* Polyn, Q* Numb)
{
	short i; // Для пересчета коэффициентов многочлена
	P* Result = initP(); // Результат умножения
	Result->len = Polyn->len; // Длина результата равна длине многочлена
	Result->k = (Q**)malloc((Polyn->len + 1) * sizeof(Q*)); // Освобождение памяти под коэффициенты
	for (i = Polyn->len; i >= 0; i--)
		Result->k[i] = MUL_QQ_Q(Polyn->k[i], Numb);
	return Result;
}