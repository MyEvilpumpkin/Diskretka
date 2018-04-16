#pragma once
// P-11

P* GCF_PP_P(P* first, P* second)
{
	P* ost = (P*)malloc(sizeof(P));
	while (DEG_P_N(second) != 0 || NZER_N_B(second->k[0]->num->number))
	{
		ost = MOD_PP_P(first, second);
		first = second;
		second = ost;
	}
	return first;
}