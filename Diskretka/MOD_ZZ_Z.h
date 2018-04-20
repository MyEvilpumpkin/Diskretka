#pragma once
// Z-10

Z* MOD_ZZ_Z(Z* First, N* Second)
{
	Z* tmp = TRANS_N_Z(Second);
	Z *Rest = DIV_ZZ_Z(First, Second);
	Z *Temp = MUL_ZZ_Z(Rest, tmp);
	freeZ(tmp);
	freeZ(Rest);
	tmp = SUB_ZZ_Z(First, Temp); // Остаток от деления
	freeZ(Temp);
	
	if (First->sign) {
		Rest = initZ();
		Rest->number = assignmentN(tmp->number);
	}
	else {
		Temp = TRANS_N_Z(Second);
		Rest = ADD_ZZ_Z(tmp, Temp);
		freeZ(Temp);
	}
	freeZ(tmp);
	return Rest;
}