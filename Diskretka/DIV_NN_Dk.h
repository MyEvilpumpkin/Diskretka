#pragma once
// N-10

int DIV_NN_Dk(N* a, N* b, int &k)
{
	int rez = 0;
	if (COM_NN_D(a, b) == 2) {
		N* mk = assignmentN(b);
		k = a->len;
		int temp = 0;
		int i = 1;
		do
		{
			temp = temp * 10 + a->n[a->len - i];
			if (mk->n[mk->len - 1] == 0)
				rez = -1;
			else
				rez = temp / mk->n[mk->len - 1];
			i++;
			k--;
		} while (rez == 0);
	}
	else {
		N* mk = assignmentN(a);
		k = b->len;
		int temp = 0;
		int i = 1;
		do
		{
			temp = temp * 10 + b->n[b->len - i];
			if (mk->n[mk->len - 1] == 0)
				rez = -1;
			else
				rez = temp / mk->n[mk->len - 1];
			i++;
			k--;
		} while (rez == 0);
	}
	return rez == -1 ? 0 : rez;
}