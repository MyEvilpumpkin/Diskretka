#include "ALL.h"

void N_modules(int option) {
	switch (option) {
		case 1:
		{
			printf("Enter first number: ");
			N* a = inputN();
			printf("\nEnter second number: ");
			N* b = inputN();
			printf("\nResult: %d",COM_NN_D(a, b));
			freeN(a);
			freeN(b);
		}
			break;
		case 2:
		{
			printf("Enter number: ");
			N* a = inputN();
			printf("\nResult: %d", NZER_N_B(a));
			freeN(a);
		}
			break;
		case 3:
		{
			printf("Enter number: ");
			N* a = inputN();
			printf("\nResult: ");
			printN(ADD_1N_N(a));
			freeN(a);
		}
			break;
		case 4:
		{
			printf("Enter first number: ");
			N* a = inputN();
			printf("\nEnter second number: ");
			N* b = inputN();
			printf("\nResult: ");
			printN(ADD_NN_N(a, b));
			freeN(a);
			freeN(b);
		}
			break;
		case 5:
		{
			printf("Enter first number: ");
			N* a = inputN();
			printf("\nEnter second number: ");
			N* b = inputN();
			printf("\nResult: ");
			printN(SUB_NN_N(a, b));
			freeN(a);
			freeN(b);
		}
			break;
		case 6:
		{
			printf("Enter first number: ");
			N* a = inputN();
			printf("\nEnter second number: ");
			int n;
			scanf("%d", &n);
			printf("Result: ");
			printN(MUL_ND_N(a, n));
			freeN(a);
		}
			break;
		case 7:
		{
			printf("Enter first number: ");
			N* a = inputN();
			printf("\nEnter second number: ");
			int n;
			scanf("%d", &n);
			printf("Result: ");
			printN(MUL_Nk_N(a, n));
			freeN(a);
		}
			break;
		case 8:
		{
			printf("Enter first number: ");
			N* a = inputN();
			printf("\nEnter second number: ");
			N* b = inputN();
			printf("\nResult: ");
			printN(MUL_NN_N(a, b));
			freeN(a);
			freeN(b);
		}
			break;
		case 9:
		{
			printf("Enter first number: ");
			N* a = inputN();
			printf("\nEnter second number: ");
			N* b = inputN();
			printf("\nEnter third number: ");
			int n;
			scanf("%d", &n);
			printf("Result: ");
			printN(SUB_NDN_N(a, b, n));
			freeN(a);
			freeN(b);
		}
			break;
		case 10:
		{
			printf("Enter first number: ");
			N* a = inputN();
			printf("\nEnter second number: ");
			N* b = inputN();
			int n = 0;
			printf("\nResult: %d", DIV_NN_Dk(a, b, n));
			freeN(a);
			freeN(b);
		}
			break;
		case 11:
		{
			printf("Enter first number: ");
			N* a = inputN();
			printf("\nEnter second number: ");
			N* b = inputN();
			printf("\nResult: ");
			printN(DIV_NN_N(a, b));
			freeN(a);
			freeN(b);
		}
			break;
		case 12:
		{
			printf("Enter first number: ");
			N* a = inputN();
			printf("\nEnter second number: ");
			N* b = inputN();
			printf("\nResult: ");
			printN(MOD_NN_N(a, b));
			freeN(a);
			freeN(b);
		}
			break;
		case 13:
		{
			printf("Enter first number: ");
			N* a = inputN();
			printf("\nEnter second number: ");
			N* b = inputN();
			printf("\nResult: ");
			printN(GCF_NN_N(a, b));
			freeN(a);
			freeN(b);
		}
			break;
		case 14:
		{
			printf("Enter first number: ");
			N* a = inputN();
			printf("\nEnter second number: ");
			N* b = inputN();
			printf("\nResult: ");
			printN(LCM_NN_N(a, b));
			freeN(a);
			freeN(b);
		}
			break;
	}
}

void Z_modules(int option) {
	switch (option)
	{
		case 1:
		{
			printf("Enter number: ");
			Z* a = inputZ();
			printf("\nResult: ");
			printN(ABS_Z_N(a));
			freeZ(a);
		}
			break;
		case 2:
		{
			printf("Enter first number: ");
			Z* a = inputZ();
			printf("\nResult: %d", POZ_Z_D(a));
			freeZ(a);
		}
			break;
		case 3:
		{
			printf("Enter number: ");
			Z* a = inputZ();
			printf("\nResult: ");
			printZ(MUL_ZM_Z(a));
			freeZ(a);
		}
			break;
		case 4:
		{
			printf("Enter number: ");
			N* a = inputN();
			printf("\nResult: ");
			printZ(TRANS_N_Z(a));
			freeN(a);
		}
			break;
		case 5:
		{
			printf("Enter number: ");
			Z* a = inputZ();
			printf("\nResult: ");
			printN(TRANS_Z_N(a));
			freeZ(a);
		}
			break;
		case 6:
		{
			printf("Enter first number: ");
			Z* a = inputZ();
			printf("\nEnter second number: ");
			Z* b = inputZ();
			printf("\nResult: ");
			printZ(ADD_ZZ_Z(a, b));
			freeZ(a);
			freeZ(b);
		}
			break;
		case 7:
		{
			printf("Enter first number: ");
			Z* a = inputZ();
			printf("\nEnter second number: ");
			Z* b = inputZ();
			printf("\nResult: ");
			printZ(SUB_ZZ_Z(a, b));
			freeZ(a);
			freeZ(b);
		}
			break;
		case 8:
		{
			printf("Enter first number: ");
			Z* a = inputZ();
			printf("\nEnter second number: ");
			Z* b = inputZ();
			printf("\nResult: ");
			printZ(MUL_ZZ_Z(a, b));
			freeZ(a);
			freeZ(b);
		}
			break;
		case 9:
		{
			printf("Enter first number: ");
			Z* a = inputZ();
			printf("\nEnter second number: ");
			N* b = inputN();
			printf("\nResult: ");
			printZ(DIV_ZZ_Z(a, b));
			freeZ(a);
			freeN(b);
		}
			break;
		case 10:
		{
			printf("Enter first number: ");
			Z* a = inputZ();
			printf("\nEnter second number: ");
			N* b = inputN();
			printf("\nResult: ");
			printZ(MOD_ZZ_Z(a, b));
			freeZ(a);
			freeN(b);
		}
			break;
	}
}

void Q_modules(int option) {
	switch (option)
	{
		case 1: 
		{
			puts("Enter number:");
			Q* a = inputQ();
			printf("Result: ");
			printQ(RED_Q_Q(a));
			freeQ(a);
		}
			break;
		case 2:
		{
			puts("Enter number:");
			Q* a = inputQ();
			printf("Result: %d", INT_Q_B(a));
			freeQ(a);
		}
			break;
		case 3:
		{
			printf("Enter number: ");
			Z* a = inputZ();
			printf("\nResult: ");
			printQ(TRANS_Z_Q(a));
			freeZ(a);
		}
			break;
		case 4:
		{
			puts("Enter number:");
			Q* a = inputQ();
			printf("Result: ");
			printZ(TRANS_Q_Z(a));
			freeQ(a);
		}
			break;
		case 5:
		{
			puts("Enter first number:");
			Q* a = inputQ();
			puts("Enter second number:");
			Q* b = inputQ();
			printf("Result: ");
			printQ(ADD_QQ_Q(a, b));
			freeQ(a);
			freeQ(b);
		}
			break;
		case 6:
		{
			puts("Enter first number:");
			Q* a = inputQ();
			puts("Enter second number:");
			Q* b = inputQ();
			printf("Result: ");
			printQ(SUB_QQ_Q(a, b));
			freeQ(a);
			freeQ(b);
		}
			break;
		case 7:
		{
			puts("Enter first number:");
			Q* a = inputQ();
			puts("Enter second number: ");
			Q* b = inputQ();
			printf("Result: ");
			printQ(MUL_QQ_Q(a, b));
			freeQ(a);
			freeQ(b);
		}
			break;
		case 8:
		{
			puts("Enter first number:");
			Q* a = inputQ();
			puts("Enter second number: ");
			Q* b = inputQ();
			printf("Result: ");
			printQ(DIV_QQ_Q(a, b));
			freeQ(a);
			freeQ(b);
		}
			break;
	}
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