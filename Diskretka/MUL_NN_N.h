#pragma once
// N-8 Калимулин Вячеслав

N* MUL_NN_N(N* a, N* b)
{
	N* result = zeroN();
	N* temp, *tmp;
	for (int i = 0; i < b->len; i++) { // К результату, изначально равному 0, в каждом шаге цикла прибавляется i-ая цифра первого сомножителя
		tmp = MUL_ND_N(a, b->n[i]);
		temp = MUL_Nk_N(tmp, i); // умноженная на второй сомножитель и на 10^i
		freeN(tmp);
		tmp = ADD_NN_N(result, temp);
		freeN(result);
		result = assignmentN(tmp);
		freeN(tmp);
		freeN(temp);
	}
	return result;
}