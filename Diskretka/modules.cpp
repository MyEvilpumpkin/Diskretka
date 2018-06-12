#include "modules.h"

// ‘ункци€ вызова N-модулей
void N_module(int option)
{
	switch (option)
	{
	case 1:
	{
		printf("¬ведите первое натуральное число: ");
		N* a = inputN();
		printf("¬ведите второе натуральное число: ");
		N* b = inputN();
		printf("–езультат: %d", COM_NN_D(a, b));
		freeN(a);
		freeN(b);
	}
	break;
	case 2:
	{
		printf("¬ведите натуральное число: ");
		N* a = inputN();
		printf("–езультат: %d", NZER_N_B(a));
		freeN(a);
	}
	break;
	case 3:
	{
		printf("¬ведите натуральное число: ");
		N* a = inputN();
		printf("–езультат: ");
		N* r = ADD_1N_N(a);
		printN(r);
		freeN(r);
		freeN(a);
	}
	break;
	case 4:
	{
		printf("¬ведите первое натуральное число: ");
		N* a = inputN();
		printf("¬ведите второе натуральное число: ");
		N* b = inputN();
		printf("–езультат: ");
		N* r = ADD_NN_N(a, b);
		printN(r);
		freeN(r);
		freeN(a);
		freeN(b);
	}
	break;
	case 5:
	{
		printf("¬ведите первое натуральное число: ");
		N* a = inputN();
		printf("¬ведите второе натуральное число: ");
		N* b = inputN();
		printf("–езультат: ");
		N* r = SUB_NN_N(a, b);
		printN(r);
		freeN(r);
		freeN(a);
		freeN(b);
	}
	break;
	case 6:
	{
		printf("¬ведите натуральное число: ");
		N* a = inputN();
		printf("¬ведите число: ");
		int d = getNumber();
		printf("–езультат: ");
		N* r = MUL_ND_N(a, d);
		printN(r);
		freeN(r);
		freeN(a);
	}
	break;
	case 7:
	{
		printf("¬ведите натуральное число: ");
		N* a = inputN();
		printf("¬ведите число: ");
		int n = getNumber();
		printf("–езультат: ");
		N* r = MUL_Nk_N(a, n);
		printN(r);
		freeN(r);
		freeN(a);
	}
	break;
	case 8:
	{
		printf("¬ведите первое натуральное число: ");
		N* a = inputN();
		printf("¬ведите второе натуральное число: ");
		N* b = inputN();
		printf("–езультат: ");
		N* r = MUL_NN_N(a, b);
		printN(r);
		freeN(r);
		freeN(a);
		freeN(b);
	}
	break;
	case 9:
	{
		printf("¬ведите первое натуральное число: ");
		N* a = inputN();
		printf("¬ведите число: ");
		int d = getNumber();
		printf("¬ведите второе натуральное число: ");
		N* b = inputN();
		printf("–езультат: ");
		N* r = SUB_NDN_N(a, d, b);
		printN(r);
		freeN(r);
		freeN(a);
		freeN(b);
	}
	break;
	case 10:
	{
		printf("¬ведите первое натуральное число: ");
		N* a = inputN();
		printf("¬ведите второе натуральное число: ");
		N* b = inputN();
		int k = 0;
		printf("–езультат: %d", DIV_NN_Dk(a, b, k));
		freeN(a);
		freeN(b);
	}
	break;
	case 11:
	{
		printf("¬ведите первое натуральное число: ");
		N* a = inputN();
		printf("¬ведите второе натуральное число: ");
		N* b = inputN();
		printf("–езультат: ");
		N* r = DIV_NN_N(a, b);
		printN(r);
		freeN(r);
		freeN(a);
		freeN(b);
	}
	break;
	case 12:
	{
		printf("¬ведите первое натуральное число: ");
		N* a = inputN();
		printf("¬ведите второе натуральное число: ");
		N* b = inputN();
		printf("–езультат: ");
		N* r = MOD_NN_N(a, b);
		printN(r);
		freeN(r);
		freeN(a);
		freeN(b);
	}
	break;
	case 13:
	{
		printf("¬ведите первое натуральное число: ");
		N* a = inputN();
		printf("¬ведите второе натуральное число: ");
		N* b = inputN();
		printf("–езультат: ");
		N* r = GCF_NN_N(a, b);
		printN(r);
		freeN(r);
		freeN(a);
		freeN(b);
	}
	break;
	case 14:
	{
		printf("¬ведите первое натуральное число: ");
		N* a = inputN();
		printf("¬ведите второе натуральное число: ");
		N* b = inputN();
		printf("–езультат: ");
		N* r = LCM_NN_N(a, b);
		printN(r);
		freeN(r);
		freeN(a);
		freeN(b);
	}
	break;
	}
	puts("");
	system("pause");
	system("cls");
}
// ‘ункци€ вызова Z-модулей
void Z_module(int option)
{
	switch (option)
	{
	case 1:
	{
		printf("¬ведите целое число: ");
		Z* a = inputZ();
		printf("–езультат: ");
		N* r = ABS_Z_N(a);
		printN(r);
		freeN(r);
		freeZ(a);
	}
	break;
	case 2:
	{
		printf("¬ведите целое число: ");
		Z* a = inputZ();
		printf("–езультат: %d", POZ_Z_D(a));
		freeZ(a);
	}
	break;
	case 3:
	{
		printf("¬ведите целое число: ");
		Z* a = inputZ();
		printf("–езультат: ");
		Z* r = MUL_ZM_Z(a);
		printZ(r);
		freeZ(r);
		freeZ(a);
	}
	break;
	case 4:
	{
		printf("¬ведите натуральное число: ");
		N* a = inputN();
		printf("–езультат: ");
		Z* r = TRANS_N_Z(a);
		printZ(r);
		freeZ(r);
		freeN(a);
	}
	break;
	case 5:
	{
		printf("¬ведите целое число: ");
		Z* a = inputZ();
		printf("–езультат: ");
		N* r = TRANS_Z_N(a);
		printN(r);
		freeN(r);
		freeZ(a);
	}
	break;
	case 6:
	{
		printf("¬ведите первое целое число: ");
		Z* a = inputZ();
		printf("¬ведите второе целое число: ");
		Z* b = inputZ();
		printf("–езультат: ");
		Z* r = ADD_ZZ_Z(a, b);
		printZ(r);
		freeZ(r);
		freeZ(a);
		freeZ(b);
	}
	break;
	case 7:
	{
		printf("¬ведите первое целое число: ");
		Z* a = inputZ();
		printf("¬ведите второе целое число: ");
		Z* b = inputZ();
		printf("–езультат: ");
		Z* r = SUB_ZZ_Z(a, b);
		printZ(r);
		freeZ(r);
		freeZ(a);
		freeZ(b);
	}
	break;
	case 8:
	{
		printf("¬ведите первое целое число: ");
		Z* a = inputZ();
		printf("¬ведите второе целое число: ");
		Z* b = inputZ();
		printf("–езультат: ");
		Z* r = MUL_ZZ_Z(a, b);
		printZ(r);
		freeZ(r);
		freeZ(a);
		freeZ(b);
	}
	break;
	case 9:
	{
		printf("¬ведите целое число: ");
		Z* a = inputZ();
		printf("¬ведите натуральное число: ");
		N* b = inputN();
		printf("–езультат: ");
		Z* r = DIV_ZZ_Z(a, b);
		printZ(r);
		freeZ(r);
		freeZ(a);
		freeN(b);
	}
	break;
	case 10:
	{
		printf("¬ведите целое число: ");
		Z* a = inputZ();
		printf("¬ведите натуральное число: ");
		N* b = inputN();
		printf("–езультат: ");
		Z* r = MOD_ZZ_Z(a, b);
		printZ(r);
		freeZ(r);
		freeZ(a);
		freeN(b);
	}
	break;
	}
	puts("");
	system("pause");
	system("cls");
}
// ‘ункци€ вызова Q-модулей
void Q_module(int option)
{
	switch (option)
	{
	case 1:
	{
		puts("¬ведите рациональное число:");
		Q* a = inputQ();
		printf("–езультат: ");
		printQ(RED_Q_Q(a));
		freeQ(a);
	}
	break;
	case 2:
	{
		puts("¬ведите рациональное число:");
		Q* a = inputQ();
		printf("–езультат: %d", INT_Q_B(a));
		freeQ(a);
	}
	break;
	case 3:
	{
		printf("¬ведите целое число: ");
		Z* a = inputZ();
		printf("–езультат: ");
		Q* r = TRANS_Z_Q(a);
		printQ(r);
		freeQ(r);
		freeZ(a);
	}
	break;
	case 4:
	{
		puts("¬ведите рациональное число:");
		Q* a = inputQ();
		printf("–езультат: ");
		Z* r = TRANS_Q_Z(a);
		printZ(r);
		freeZ(r);
		freeQ(a);
	}
	break;
	case 5:
	{
		puts("¬ведите первое рациональное число:");
		Q* a = inputQ();
		puts("¬ведите второе рациональное число:");
		Q* b = inputQ();
		printf("–езультат: ");
		Q* r = ADD_QQ_Q(a, b);
		printQ(r);
		freeQ(r);
		freeQ(a);
		freeQ(b);
	}
	break;
	case 6:
	{
		puts("¬ведите первое рациональное число:");
		Q* a = inputQ();
		puts("¬ведите второе рациональное число:");
		Q* b = inputQ();
		printf("–езультат: ");
		Q* r = SUB_QQ_Q(a, b);
		printQ(r);
		freeQ(r);
		freeQ(a);
		freeQ(b);
	}
	break;
	case 7:
	{
		puts("¬ведите первое рациональное число:");
		Q* a = inputQ();
		puts("¬ведите второе рациональное число:");
		Q* b = inputQ();
		printf("–езультат: ");
		Q* r = MUL_QQ_Q(a, b);
		printQ(r);
		freeQ(r);
		freeQ(a);
		freeQ(b);
	}
	break;
	case 8:
	{
		puts("¬ведите первое рациональное число:");
		Q* a = inputQ();
		puts("¬ведите второе рациональное число:");
		Q* b = inputQ();
		printf("–езультат: ");
		Q* r = DIV_QQ_Q(a, b);
		printQ(r);
		freeQ(r);
		freeQ(a);
		freeQ(b);
	}
	break;
	}
	puts("");
	system("pause");
	system("cls");
}
// ‘ункци€ вызова P-модулей
void P_module(int option)
{
	switch (option)
	{
	case 1:
	{
		puts("¬ведите первый многочлен:");
		P* a = inputP();
		puts("¬ведите второй многочлен:");
		P* b = inputP();
		printf("–езультат: ");
		P* r = ADD_PP_P(a, b);
		printP(r);
		freeP(r);
		freeP(a);
		freeP(b);
	}
	break;
	case 2:
	{
		puts("¬ведите первый многочлен:");
		P* a = inputP();
		puts("¬ведите второй многочлен:");
		P* b = inputP();
		printf("–езультат: ");
		P* r = SUB_PP_P(a, b);
		printP(r);
		freeP(r);
		freeP(a);
		freeP(b);
	}
	break;
	case 3:
	{
		puts("¬ведите многочлен:");
		P* a = inputP();
		puts("¬ведите рациональное число:");
		Q* b = inputQ();
		printf("–езультат: ");
		P* r = MUL_PQ_P(a, b);
		printP(r);
		freeP(r);
		freeP(a);
		freeQ(b);
	}
	break;
	case 4:
	{
		puts("¬ведите многочлен:");
		P* a = inputP();
		printf("¬ведите число: ");
		int n = getNumber();
		printf("–езультат: ");
		P* r = MUL_Pxk_P(a, n);
		printP(r);
		freeP(r);
		freeP(a);
	}
	break;
	case 5:
	{
		puts("¬ведите многочлен:");
		P* a = inputP();
		printf("–езультат: ");
		Q* r = LED_P_Q(a);
		printQ(r);
		freeQ(r);
		freeP(a);
	}
	break;
	case 6:
	{
		puts("¬ведите многочлен:");
		P* a = inputP();
		printf("–езультат: ");
		N* r = DEG_P_N(a);
		printN(r);
		freeN(r);
		freeP(a);
	}
	break;
	case 7:
	{
		puts("¬ведите многочлен:");
		P* a = inputP();
		printf("–езультат: ");
		Q* r = FAC_P_Q(a);
		printQ(r);
		freeQ(r);
		freeP(a);
	}
	break;
	case 8:
	{
		puts("¬ведите первый многочлен:");
		P* a = inputP();
		puts("¬ведите второй многочлен:");
		P* b = inputP();
		printf("–езультат: ");
		P* r = MUL_PP_P(a, b);
		printP(r);
		freeP(r);
		freeP(a);
		freeP(b);
	}
	break;
	case 9:
	{
		puts("¬ведите первый многочлен:");
		P* a = inputP();
		puts("¬ведите второй многочлен:");
		P* b = inputP();
		printf("–езультат: ");
		P* r = DIV_PP_P(a, b);
		printP(r);
		freeP(r);
		freeP(a);
		freeP(b);
	}
	break;
	case 10:
	{
		puts("¬ведите первый многочлен:");
		P* a = inputP();
		puts("¬ведите второй многочлен:");
		P* b = inputP();
		printf("–езультат: ");
		P* r = MOD_PP_P(a, b);
		printP(r);
		freeP(r);
		freeP(a);
		freeP(b);
	}
	break;
	case 11:
	{
		puts("¬ведите первый многочлен:");
		P* a = inputP();
		puts("¬ведите второй многочлен:");
		P* b = inputP();
		printf("–езультат: ");
		P* r = GCF_PP_P(a, b);
		printP(r);
		freeP(r);
		freeP(a);
		freeP(b);
	}
	break;
	case 12:
	{
		puts("¬ведите многочлен:");
		P* a = inputP();
		printf("–езультат: ");
		P* r = DER_P_P(a);
		printP(r);
		freeP(r);
		freeP(a);
	}
	break;
	case 13:
	{
		puts("¬ведите многочлен:");
		P* a = inputP();
		printf("–езультат: ");
		P* r = NMR_P_P(a);
		printP(r);
		freeP(r);
		freeP(a);
	}
	break;
	}
	puts("");
	system("pause");
	system("cls");
}
