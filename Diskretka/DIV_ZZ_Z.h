#pragma once
// Z-9

Z *DIV_ZZ_Z(Z *n1, N *n2)
{
	Z* res = initZ();
	res->number = DIV_NN_N(TRANS_Z_N(n1), n2);
	res->sign = true;
	return res;
}