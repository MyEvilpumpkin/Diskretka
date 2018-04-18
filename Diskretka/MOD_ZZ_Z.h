#pragma once
// Z-10

Z* MOD_ZZ_Z(Z* First, N* Second)
{
	Z *Rest = SUB_ZZ_Z(First, MUL_ZZ_Z(DIV_ZZ_Z(First, Second), TRANS_N_Z(Second))); // Остаток от деления
	if (First->sign)
		return Rest;
	else
		return ADD_ZZ_Z(Rest, TRANS_N_Z(Second));
}