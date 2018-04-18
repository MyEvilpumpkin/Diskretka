#pragma once
// N-6

N* MUL_ND_N(N* a, int b)
{
	N* c = zeroN();
	int temp = 0, l = 0, temp2 = 0;
	for (int i = 0; i < a->len; i++)
	{
		c->n = (int*)realloc(c->n, (l + 1) * sizeof(int));
		c->n[i] = 0;
		temp = a->n[i] * b + temp2;
		temp2 = 0;
		if (temp > 9)
		{
			c->n[i] = temp % 10;
			temp2 = temp / 10;
		}
		else
			c->n[i] = temp;
		l++;
	}
	if (temp2 != 0) {
		c->n = (int*)realloc(c->n, (l + 1) * sizeof(int));
		c->n[l] = temp2;
		l++;
	}
	c->len = l;
	c = deNULL(c);
	return c;
}