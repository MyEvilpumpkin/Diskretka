#pragma once
// N-5

N* SUB_NN_N(N* a, N* b)
{
	N* c = zeroN();
	int l = 0;
	if (COM_NN_D(a, b) == 2) {
		for (int i = 0; i < a->len; i++)
		{
			c->n = (int*)realloc(c->n, (l + 1) * sizeof(int));
			if (i < b->len)
			{
				if (a->n[i] >= b->n[i])
					c->n[i] = a->n[i] - b->n[i];
				else if (a->n[i] < b->n[i])
				{
					c->n[i] = a->n[i] + 10 - b->n[i];
					int g = i;
					bool flag = false;
					do
					{
						a->n[g] += 9;
						g++;
						flag = true;
					} while (a->n[g] == 0);
					if (flag)
						a->n[g]--;
				}
			}
			else
				c->n[i] = a->n[i];
			l++;
		}
		for (int i = l - 1; i >= 0 && c->n[i] == 0; i--)
		{
			c->n = (int*)realloc(c->n, sizeof(int) * (l - 1));
			l--;
		}
		c->len = l;
	}
	return c;
}