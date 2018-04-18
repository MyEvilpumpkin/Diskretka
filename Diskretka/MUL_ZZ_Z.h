#pragma once
// Z-8

Z *MUL_ZZ_Z(Z *num1, Z *num2)
{
	Z *mul = initZ();
	N *n1, *n2;
	n1 = assignmentN(num1->number); //Модуль от первого числа
	n2 = assignmentN(num2->number);	//Модуль от второго числа
	mul->number = MUL_NN_N(n1, n2);
	if (num1->sign == num2->sign)
		mul->sign = true;
	else
		mul->sign = false;
	if (mul->number->len == 1 && mul->number->n[0] == 0)
		mul->sign = true;
	return mul;
}