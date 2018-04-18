#pragma once
// Z-5

N *TRANS_Z_N(Z *a)
{
	N* n = initN();
	n->n = (int*)malloc(a->number->len * sizeof(int));
	n->len = a->number->len;
	for (int i = 0; i < n->len; i++)
		n->n[i] = a->number->n[i];
	return n;
}