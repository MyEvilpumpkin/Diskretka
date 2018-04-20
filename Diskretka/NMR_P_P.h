#pragma once
// P-13 Якубов Владислав

P* NMR_P_P(P* a)
{
	P* Result = DER_P_P(a); // инициализируем результат производной от исходного многочлена
	P* Temp = GCF_PP_P(a, Result); // присваиваем результату значение НОКа исходного многочлена и результата
	freeP(Result);
	Result = DIV_PP_P(a, Temp); // частное от деления многочленов  
	freeP(Temp);
	Q* q = zeroQ();
	q->num->number->n[0] = 1;
	Q* tmp = FAC_P_Q(Result);
	Q* tmpr = DIV_QQ_Q(q, tmp);
	Temp = assignmentP(Result);
	freeP(Result);
	Result = MUL_PQ_P(Temp, tmpr); // присваиваем результату значение произведения (предыдущего значения результата и 
	freeQ(tmp); // (вынесенного из многочлена НОК знаменателей коэффициентов и НОД числителей в степени -1))
	freeQ(tmpr);
	freeP(Temp);
	freeQ(q);
	return Result;
}