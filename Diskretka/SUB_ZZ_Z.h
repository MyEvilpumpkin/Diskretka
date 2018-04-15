#pragma once
#include "ADD_ZZ_Z.h"
// Z-7

Z *ADD_ZZ_Z(Z*, Z*);
Z *SUB_ZZ_Z(Z *num1, Z *num2)
{
	Z *res = initZ();
	if (num1->sign == true && num1->sign == num2->sign) { //Если одного оба положительные
		if (COM_NN_D(num1->number, num2->number) == 1)
			res->number = SUB_NN_N(num2->number, num1->number);
		else
			res->number = SUB_NN_N(num1->number, num2->number);

		if (COM_NN_D(num1->number, num2->number) == 2 || COM_NN_D(num1->number, num2->number) == 0)
			res->sign = true;
		else
			res->sign = false;
		return res;
	}
	if (num1->sign == false && num1->sign == num2->sign) { //Если оба отрицательные
		num2->sign = true;
		return ADD_ZZ_Z(num1, num2);
	}
	if (num1->sign && !num2->sign) { //положительное - отрицательное
		num2->sign = true;
		return ADD_ZZ_Z(num1, num2);
	}

	if (!num1->sign && num2->sign) { // отрицательное - положительное
		num2->sign = false;
		return ADD_ZZ_Z(num1, num2);
	}
	return nullptr;
}