#pragma once
// Q-7

Q MUL_QQ_Q(Q First, Q Second)
{
	Q Result; // Результат умножения
	Result.denom = MUL_NN_N(First.denom, Second.denom);
	Result.num = MUL_ZZ_Z(First.num, Second.num);
	return Result;
}