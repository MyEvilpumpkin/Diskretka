#pragma once
// P-13

P* NMR_P_P(P* a)
{
	P* Result = initP(); // Частное от деления многочленов 
	P* der = initP();
	der->k = (Q**)malloc(a->len * sizeof(P));
	der->len = a->len - 1;
	P* nod = assignmentP(a);
	Result = DIV_PP_P(a, GCF_PP_P(a, DER_P_P(a)));
	return Result;
}