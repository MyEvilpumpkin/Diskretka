#include "ALL.h"

int main()
{
	puts("Diskretka");
	N* a,* b;
	Z* z,* x;
	do
	{
		a = inputN();
		b = inputN();
		//z = inputZ();
		//x = inputZ();
		int k = 0;
		//printf("%d\n", DIV_NN_Dk(a, b, k));
		puts("");
		//printf("%d\n", k);
		N* c = MOD_NN_N(a, b);
		printN(c);
		puts("");
		//printN(a);
		puts("");
		//printN(b);
	} while (1);
    return 0;
}