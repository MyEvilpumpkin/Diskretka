#pragma once
// Z-10

Z* MOD_ZZ_Z(Z* First, N* Second)
{
	Z *Result = DIV_ZZ_Z(First, Second); // Частное от деления
	Z *Temp = MUL_ZZ_Z(Result, TRANS_N_Z(Second)); // Произведение частного на делитель
	Z *Rest = SUB_ZZ_Z(First, Temp); // Остаток от деления
	if (First->sign)
		return Rest;
	else
		return ADD_ZZ_Z(Rest, TRANS_N_Z(Second));
}