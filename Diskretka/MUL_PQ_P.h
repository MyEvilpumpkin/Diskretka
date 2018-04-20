#pragma once
// P-3 Ханов Александр

P* MUL_PQ_P(P* Polyn, Q* Numb)
{
	P* Result = (P*)malloc(sizeof(P));
	Result->k = (Q**)malloc((Polyn->len + 1) * sizeof(Q*));
	Result->len = Polyn->len;
	for (int i = Polyn->len; i >= 0; i--) // цикл от старшего коэффициента до младшего
		Result->k[i] = MUL_QQ_Q(Polyn->k[i], Numb); // присваиваем текущему коэффициенту результат произведения текущего коэффициента исходного
	return Result; // многочлена на рациональное число
}