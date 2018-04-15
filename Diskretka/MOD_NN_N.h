#pragma once
// N-12

N* MOD_NN_N(N* num, N* mod) {
	// num - (num div mod) * mod 
	if (COM_NN_D(num, mod) == 2)
		return SUB_NN_N(num, MUL_NN_N(DIV_NN_N(num, mod), mod));
	else
		return SUB_NN_N(mod, MUL_NN_N(DIV_NN_N(num, mod), num));
}