#pragma once
// P-13

P* NMR_P_P(P* a)
{
	P* Result = initP(); // Частное от деления многочленов 
	P* der = (P*)malloc(sizeof(P));
	der->k = (Q**)malloc(a->len * sizeof(P));
	der->len = a->len - 1;
	P* nod = assignmentP(a);
	der = DER_P_P(a);
	nod = GCF_PP_P(a, der);
	Result = DIV_PP_P(a, nod);
	return Result;
}