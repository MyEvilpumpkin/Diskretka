#include "ALL.h"

int main()
{
	puts("Diskretka");
	do
	{
		//N* a = inputN();
		//N* b = inputN();
		//Z* z = inputZ();
		//Z* x = inputZ();
		Q* q = inputQ();
		Q* w = inputQ();
		puts("");
		//printN(LCM_NN_N(a, b));
		//printZ(MOD_ZZ_Z(z, a));
		printQ(DIV_QQ_Q(q, w));
		//printZ(TRANS_Q_Z(q));
		//int k = 0;
		//printf("%d\n", INT_Q_B(q));
		
		//printf("%d\n", k);
		
		puts("");
		//printN(a);
		puts("");
		//printN(b);
	} while (1);
    return 0;
}