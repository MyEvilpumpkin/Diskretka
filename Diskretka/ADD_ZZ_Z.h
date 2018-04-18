#pragma once
// Z-6

Z *ADD_ZZ_Z(Z *num1, Z *num2)
{
	Z* sum = initZ();
	if (num1->sign == num2->sign) {
		sum->number = ADD_NN_N(num1->number, num2->number);
		sum->sign = num1->sign;
	}
	else {
		if (COM_NN_D(num1->number, num2->number) == 2) {
			sum->number = SUB_NN_N(num1->number, num2->number);
			sum->sign = num1->sign;
		}
		else if (COM_NN_D(num1->number, num2->number) == 1) {
			sum->number = SUB_NN_N(num2->number, num1->number);
			sum->sign = num2->sign;
		}
		else if (COM_NN_D(num1->number, num2->number) == 0) {
			sum->number = zeroN();
			sum->sign = true;
		}
	}
	return sum;
}