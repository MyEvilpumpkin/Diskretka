#pragma once
// Z-10

Z *MOD_ZZ_Z(Z *First, N *Second)
{
	Z *Result; // Частное от деления
	Z *Temp; // Произведение частного на делитель
	Z *Rest; // Остаток от деления
	Result = DIV_ZZ_Z(First, Second);
	Temp = MUL_ZZ_Z(Result, TRANS_N_Z(Second));
	Rest = SUB_ZZ_Z(First, Temp);
	return Rest;
}