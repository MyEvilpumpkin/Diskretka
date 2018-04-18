#pragma once
// P-13

P* NMR_P_P(P* a)
{
	P* Result = initP(); // Частное от деления многочленов 
	P* der = initP();
	der->k = (Q**)malloc(a->len * sizeof(Q*));
	der->len = a->len - 1;
	Result = DIV_PP_P(a, GCF_PP_P(a, DER_P_P(a)));
	Q* q = zeroQ();
	q->num->number->n[0] = 1;
	return MUL_PQ_P(Result, DIV_QQ_Q(q, FAC_P_Q(Result)));
}