#pragma once
// Z-7

Z *SUB_ZZ_Z(Z *num1, Z *num2)
{
	Z *n2 = initZ();
	n2->number = assignmentN(num2->number);
	n2->sign = !num2->sign;
	return ADD_ZZ_Z(num1, n2);
}
