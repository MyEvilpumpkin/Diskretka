#pragma once
// Q-8  ожанов ƒаниил

Q* DIV_QQ_Q(Q* First, Q* Second)
{
	Q* Result; 
	if (Second->num->number->len == 1 && Second->num->number->n[0] == 0) // если числитель = 0
		Result = zeroQ();
	else {
		Result = (Q*)malloc(sizeof(Q));
		Result->num = (Z*)malloc(sizeof(Z));
		Result->num->sign = First->num->sign == Second->num->sign; // присвоить знаку результата эквиваленцию знаков двух числителей
		Result->num->number = MUL_NN_N(First->num->number, Second->denom); // присвоить числителю результата произведение первого числител€ и второго знаменател€
		Result->denom = MUL_NN_N(First->denom, Second->num->number); // присвоить знаменателю результата произведение первого знаменател€ и второго числител€
	}
	return RED_Q_Q(Result);
}