#pragma once
// Z-5

N *TRANS_Z_N(Z *a)
{
	N* n = (N*)malloc(sizeof(N));
	n->n = (int*)malloc(4 * a->number->len);
	n->len = a->number->len;
	for (int i = 0; i < n->len; i++)
		n->n[i] = a->number->n[i];
	return n;
}