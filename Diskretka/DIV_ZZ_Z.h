#pragma once
// Z-9

Z* DIV_ZZ_Z(Z* n1, N* n2)
{
	Z* res = initZ();
	res->number = DIV_NN_N(n1->number, n2);
	res->sign = n1->sign;
	if (res->number->len == 1 && res->number->n[0] == 0)
		res->sign = true;
	return res;
}