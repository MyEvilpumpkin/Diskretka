#pragma once
// Z-8 Манжиков Леонид

Z *MUL_ZZ_Z(Z *num1, Z *num2)
{
	Z *mul = (Z*)malloc(sizeof(Z));
	mul->number = MUL_NN_N(num1->number, num2->number); // присваиваем результату по модулю значение произведения первого числа на второе по модулю
	if (num1->sign == num2->sign) // если знаки двух чисел равны
		mul->sign = true; // то знак результата +
	else
		mul->sign = false; // знак результата -
	if (mul->number->len == 1 && mul->number->n[0] == 0) // если результа - 0
		mul->sign = true; // то знак результата +
	return mul;
}