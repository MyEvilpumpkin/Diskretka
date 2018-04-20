#pragma once
// P-3

P* MUL_PQ_P(P* Polyn, Q* Numb)
{
	P* Result = assignmentP(Polyn);
	for (int i = Polyn->len; i >= 0; i--)
		Result->k[i] = MUL_QQ_Q(Polyn->k[i], Numb);
	return Result;
}