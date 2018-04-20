#pragma once
// N-12

N* MOD_NN_N(N* num, N* mod) {
	// num - (num div mod) * mod 
	N* temp,* tmp, *result;
	temp = DIV_NN_N(num, mod);
	if (COM_NN_D(num, mod) == 2) {
		
		tmp = MUL_NN_N(temp, mod);
		result = SUB_NN_N(num, tmp);
	}
	else {
		tmp = MUL_NN_N(temp, num);
		result = SUB_NN_N(mod, tmp);
	}
	freeN(temp);
	freeN(tmp);
	return result;
}