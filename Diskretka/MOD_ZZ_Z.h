#pragma once
// Z-10  ожанов ƒаниил

Z* MOD_ZZ_Z(Z* First, N* Second)
{
	Z* tmp = TRANS_N_Z(Second); // преобразованное в целое второе число
	Z *Rest = DIV_ZZ_Z(First, Second); // результат от делени€ без остатка первого числа на второе
	Z *Temp = MUL_ZZ_Z(Rest, tmp);
	freeZ(tmp);
	freeZ(Rest);
	tmp = SUB_ZZ_Z(First, Temp); // разность между исходным первым числом и произведением
	freeZ(Temp);
	
	if (First->sign) { // если знак реузльтата +
		Rest = (Z*)malloc(sizeof(Z));
		Rest->number = assignmentN(tmp->number);
		Rest->sign = true;
	}
	else {
		Temp = TRANS_N_Z(Second);
		Rest = ADD_ZZ_Z(tmp, Temp); // добавл€ем к остатку преобразованное второе число
		freeZ(Temp);
	}
	freeZ(tmp);
	return Rest;
}