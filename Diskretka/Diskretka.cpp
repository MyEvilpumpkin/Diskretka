#include "modules.h"

int menu(int option) {
	switch (option)
	{
	case 0:
		puts("***MAIN MENU***");
		puts("1 - N modules");
		puts("2 - Z modules");
		puts("3 - Q modules");
		puts("4 - P modules");
		puts("5 - Help");
		puts("0 - Exit");
		break;
	case 1:
		puts("***N modules***");
		break;
	case 2:
		puts("***Z modules***");
		break;
	case 3:
		puts("***Q modules***");
		break;
	case 4:
		puts("***P modules***");
		break;
	case 5:
		puts("***Help***");
		break;
	}
	scanf("%d", &option);
	return option;
}

int main()
{
	puts("Diskretka");
	do
	{
		int n;
		puts("#");
		scanf("%d", &n);
		puts("#");
		//N_modules(n);
		//Z_modules(n);
		Q_modules(n);
		puts("");
		/*N* a = inputN();
		N* b = inputN();
		Z* z = inputZ();
		Z* x = inputZ();
		Q* q = inputQ();
		Q* w = inputQ();
		puts("");
		printN(LCM_NN_N(a, b));
		printZ(MOD_ZZ_Z(z, a));
		printQ(DIV_QQ_Q(q, w));
		printZ(TRANS_Q_Z(q));
		int k = 0;
		printf("%d\n", INT_Q_B(q));
		printf("%d\n", k);
		puts("");
		printN(a);
		printN(b);*/
	} while (1);
    return 0;
}