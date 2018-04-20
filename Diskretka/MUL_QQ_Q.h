#pragma once
// Q-7 ƒ€ченко ¬италий

Q* MUL_QQ_Q(Q* First, Q* Second)
{
	Q* Result = (Q*)malloc(sizeof(Q));
	Result->denom = MUL_NN_N(First->denom, Second->denom); // перемножаем числители
	Result->num = MUL_ZZ_Z(First->num, Second->num); // перемножаем знаменатели
	return RED_Q_Q(Result); // результат умножени€
}