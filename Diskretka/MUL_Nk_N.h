#pragma once
// N-7

N* MUL_Nk_N(N* a, int b)
{
	N* c = getZero();
	int len = a->len + b;
	c->n = (int*)malloc(len * sizeof(int));
	for (int i = 0; i < len; i++)
	{
		if (i < b)
			c->n[i] = 0;
		else
			c->n[i] = a->n[i - b];
	}
	c->len = len;
	c = deNULL(c);
	return c;
}