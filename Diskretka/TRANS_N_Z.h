#pragma once
// Z-4

Z *TRANS_N_Z(N *a)
{
	Z *z = initZ();
	z->number->n = (int*)malloc(a->len * sizeof(int));
	z->number->len = a->len;
	for (int i = 0; i < a->len; i++)
		z->number->n[i] = a->n[i];
	return z;
}