#pragma once
// Q-8

Q* DIV_QQ_Q(Q* First, Q* Second)
{
	Q* Result; // Результат умножения
	if (Second->num->number->len == 1 && Second->num->number->n[0] == 0)
		Result = zeroQ();
	else {
		Result = initQ();
		Result->num->sign = First->num->sign == Second->num->sign;
		Result->num->number = MUL_NN_N(First->num->number, Second->denom);
		Result->denom = MUL_NN_N(First->denom, Second->num->number);
	}
	return RED_Q_Q(Result);
}