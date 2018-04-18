#pragma once
// Z-8

Z *MUL_ZZ_Z(Z *num1, Z *num2)
{
	Z *mul = initZ();
	mul->number = MUL_NN_N(num1->number, num2->number);
	if (num1->sign == num2->sign)
		mul->sign = true;
	else
		mul->sign = false;
	if (mul->number->len == 1 && mul->number->n[0] == 0)
		mul->sign = true;
	return mul;
}