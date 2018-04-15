#pragma once
// Z-1

N* ABS_Z_N(Z *a)
{
	N* x = initN();
	x->n = (int*)malloc(sizeof(int) * a->number->len);
	for (int i = 0; i < a->number->len; i++)
		x->n[i] = a->number->n[i];
	x->len = a->number->len;
	return x;
}