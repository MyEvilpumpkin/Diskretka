#pragma once
// P-3

P* MUL_PQ_P(P* Polyn, Q* Numb)
{
	short i; // Для пересчета коэффициентов многочлена
	P* Result = assignmentP(Polyn);
	for (i = Polyn->len; i >= 0; i--)
		Result->k[i] = MUL_QQ_Q(Polyn->k[i], Numb);
	return Result;
}