#pragma once
// N-8

N* MUL_NN_N(N* a, N* b)
{
	N* result = zeroN();
	for (int i = 0; i < b->len; i++)							//К результату, изначально равному 0, в каждом шаге цикла прибавляется i-ая цифра первого сомножителя,
		result = ADD_NN_N(result, MUL_Nk_N(MUL_ND_N(a, b->n[i]), i));  //умноженная на второй сомножитель и на 10^i
	return result;
}