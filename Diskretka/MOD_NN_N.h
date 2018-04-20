#pragma once
// N-12 Макаренко Данил

N* MOD_NN_N(N* num, N* mod) {
	// num - (num div mod) * mod
	N* temp,* tmp, *result;
	temp = DIV_NN_N(num, mod); // числитель от деления большего числа на меньшее
	if (COM_NN_D(num, mod) == 2) {
		
		tmp = MUL_NN_N(temp, mod); // произведение числителя и меньшего числа
		result = SUB_NN_N(num, tmp); // разность большего числа и произведения
	}
	else {
		tmp = MUL_NN_N(temp, num); // произведение числителя и меньшего числа
		result = SUB_NN_N(mod, tmp); // разность большего числа и произведения
	}
	freeN(temp);
	freeN(tmp);
	return result;
}