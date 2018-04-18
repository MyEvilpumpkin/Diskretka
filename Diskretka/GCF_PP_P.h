#pragma once
// P-11

P* GCF_PP_P(P* a, P* b)
{
	P* ost = initP();
	P* first = assignmentP(a); 
	P* second = assignmentP(b);
	while ((second->len != 0 || NZER_N_B(second->k[0]->num->number)) && (first->len != 0 || NZER_N_B(first->k[0]->num->number)))
	{
		if (first->len > second->len)
			first = MOD_PP_P(first, second);
		else 
			second = MOD_PP_P(second, first);
	}
	if (first->len > second->len)
		ost = assignmentP(first);
	else
		ost = assignmentP(second);
	freeP(first);
	freeP(second);
	return ost;
}