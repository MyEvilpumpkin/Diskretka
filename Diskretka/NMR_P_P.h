#pragma once
// P-13

P* NMR_P_P(P* a)
{
	P* Result = DER_P_P(a);
	P* Temp = GCF_PP_P(a, Result);
	freeP(Result);
	Result = DIV_PP_P(a, Temp); // Частное от деления многочленов  
	freeP(Temp);
	Q* q = zeroQ();
	q->num->number->n[0] = 1;
	Q* tmp = FAC_P_Q(Result);
	Q* tmpr = DIV_QQ_Q(q, tmp);
	Temp = assignmentP(Result);
	freeP(Result);
	Result = MUL_PQ_P(Temp, tmpr);
	freeQ(tmp);
	freeQ(tmpr);
	freeP(Temp);
	freeQ(q);
	return Result;
}