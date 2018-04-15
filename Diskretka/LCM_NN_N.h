#pragma once
// N-14

N* LCM_NN_N(N* First, N* Second)
{
	N* NOD = GCF_NN_N(First, Second); // НОД двух чисел
	N* Temp = MUL_NN_N(First, Second); // Произведение двух чисел
	N* NOK = DIV_NN_N(Temp, NOD); // НОК двух чисел
	return NOK;
}