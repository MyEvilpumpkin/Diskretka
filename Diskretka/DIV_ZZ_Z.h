#pragma once
// Z-9 ћищенко јлина

Z* DIV_ZZ_Z(Z* n1, N* n2)
{
	Z* res = (Z*)malloc(sizeof(Z));
	res->number = DIV_NN_N(n1->number, n2); // делим как натуральные числа большее (преобразованное в целое) на меньшее
	res->sign = n1->sign; // присваиваем знаку результата знак большего числа
	if (res->number->len == 1 && res->number->n[0] == 0) // если результат равен нулю
		res->sign = true; // то знак нул€ +
	return res;
}