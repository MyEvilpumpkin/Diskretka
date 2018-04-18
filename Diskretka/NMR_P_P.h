#pragma once
// P-13

P* NMR_P_P(P* a)
{
	P* Result = DER_P_P(a);
	Result = GCF_PP_P(a, Result);
	Result = DIV_PP_P(a, Result); // Частное от деления многочленов  
	Q* q = zeroQ();
	q->num->number->n[0] = 1;
	Result = MUL_PQ_P(Result, DIV_QQ_Q(q, FAC_P_Q(Result)));
	freeQ(q);
	return Result;
}