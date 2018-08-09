#include "modules.h"
#include <ctime>
// ‘ункци€ вызова N-модулей
void N_module(int option)
{
	switch (option)
	{
	case 1:
	{
		printf("¬ведите первое натуральное число: ");
		N* n1 = inputN();
		printf("¬ведите второе натуральное число: ");
		N* n2 = inputN();
		printf("–езультат: %d", COM_NN_D(n1, n2));
		freeN(n1);
		freeN(n2);
	}
	break;
	case 2:
	{
		printf("¬ведите натуральное число: ");
		N* n = inputN();
		printf("–езультат: %d", NZER_N_B(n));
		freeN(n);
	}
	break;
	case 3:
	{
		printf("¬ведите натуральное число: ");
		N* n = inputN();
		printf("–езультат: ");
		N* result = ADD_1N_N(n);
		printN(result);
		freeN(result);
		freeN(n);
	}
	break;
	case 4:
	{
		printf("¬ведите первое натуральное число: ");
		N* n1 = inputN();
		printf("¬ведите второе натуральное число: ");
		N* n2 = inputN();
		printf("–езультат: ");
		N* result = ADD_NN_N(n1, n2);
		printN(result);
		freeN(result);
		freeN(n1);
		freeN(n2);
	}
	break;
	case 5:
	{
		printf("¬ведите первое натуральное число: ");
		N* n1 = inputN();
		printf("¬ведите второе натуральное число: ");
		N* n2 = inputN();
		printf("–езультат: ");
		N* result = SUB_NN_N(n1, n2);
		printN(result);
		freeN(result);
		freeN(n1);
		freeN(n2);
	}
	break;
	case 6:
	{
		printf("¬ведите натуральное число: ");
		N* n = inputN();
		printf("¬ведите число: ");
		int d = getNumber();
		printf("–езультат: ");
		N* result = MUL_ND_N(n, d);
		printN(result);
		freeN(result);
		freeN(n);
	}
	break;
	case 7:
	{
		printf("¬ведите натуральное число: ");
		N* n = inputN();
		printf("¬ведите число: ");
		int k = getNumber();
		printf("–езультат: ");
		N* result = MUL_Nk_N(n, k);
		printN(result);
		freeN(result);
		freeN(n);
	}
	break;
	case 8:
	{
		printf("¬ведите первое натуральное число: ");
		N* n1 = inputN();
		printf("¬ведите второе натуральное число: ");
		N* n2 = inputN();
		printf("–езультат: ");
		N* result = MUL_NN_N(n1, n2);
		printN(result);
		freeN(result);
		freeN(n1);
		freeN(n2);
	}
	break;
	case 9:
	{
		printf("¬ведите первое натуральное число: ");
		N* n1 = inputN();
		printf("¬ведите число: ");
		int d = getNumber();
		printf("¬ведите второе натуральное число: ");
		N* n2 = inputN();
		printf("–езультат: ");
		N* result = SUB_NDN_N(n1, d, n2);
		printN(result);
		freeN(result);
		freeN(n1);
		freeN(n2);
	}
	break;
	case 10:
	{
		printf("¬ведите первое натуральное число: ");
		N* n1 = inputN();
		printf("¬ведите второе натуральное число: ");
		N* n2 = inputN();
		int k = 0;
		printf("–езультат: %d", DIV_NN_Dk(n1, n2, k));
		freeN(n1);
		freeN(n2);
	}
	break;
	case 11:
	{
		printf("¬ведите первое натуральное число: ");
		N* n1 = inputN();
		printf("¬ведите второе натуральное число: ");
		N* n2 = inputN();
		printf("–езультат: ");
		N* result = DIV_NN_N(n1, n2);
		printN(result);
		freeN(result);
		freeN(n1);
		freeN(n2);
	}
	break;
	case 12:
	{
		printf("¬ведите первое натуральное число: ");
		N* n1 = inputN();
		printf("¬ведите второе натуральное число: ");
		N* n2 = inputN();
		printf("–езультат: ");
		N* result = MOD_NN_N(n1, n2);
		printN(result);
		freeN(result);
		freeN(n1);
		freeN(n2);
	}
	break;
	case 13:
	{
		printf("¬ведите первое натуральное число: ");
		N* n1 = inputN();
		printf("¬ведите второе натуральное число: ");
		N* n2 = inputN();
		printf("–езультат: ");
		N* result = GCF_NN_N(n1, n2);
		printN(result);
		freeN(result);
		freeN(n1);
		freeN(n2);
	}
	break;
	case 14:
	{
		printf("¬ведите первое натуральное число: ");
		N* n1 = inputN();
		printf("¬ведите второе натуральное число: ");
		N* n2 = inputN();
		printf("–езультат: ");
		N* result = LCM_NN_N(n1, n2);
		printN(result);
		freeN(result);
		freeN(n1);
		freeN(n2);
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
		Z* z = inputZ();
		printf("–езультат: ");
		N* result = ABS_Z_N(z);
		printN(result);
		freeN(result);
		freeZ(z);
	}
	break;
	case 2:
	{
		printf("¬ведите целое число: ");
		Z* z = inputZ();
		printf("–езультат: %d", POZ_Z_D(z));
		freeZ(z);
	}
	break;
	case 3:
	{
		printf("¬ведите целое число: ");
		Z* z = inputZ();
		printf("–езультат: ");
		Z* result = MUL_ZM_Z(z);
		printZ(result);
		freeZ(result);
		freeZ(z);
	}
	break;
	case 4:
	{
		printf("¬ведите натуральное число: ");
		N* n = inputN();
		printf("–езультат: ");
		Z* result = TRANS_N_Z(n);
		printZ(result);
		freeZ(result);
		freeN(n);
	}
	break;
	case 5:
	{
		printf("¬ведите целое число: ");
		Z* z = inputZ();
		printf("–езультат: ");
		N* result = TRANS_Z_N(z);
		printN(result);
		freeN(result);
		freeZ(z);
	}
	break;
	case 6:
	{
		printf("¬ведите первое целое число: ");
		Z* z1 = inputZ();
		printf("¬ведите второе целое число: ");
		Z* z2 = inputZ();
		printf("–езультат: ");
		Z* result = ADD_ZZ_Z(z1, z2);
		printZ(result);
		freeZ(result);
		freeZ(z1);
		freeZ(z2);
	}
	break;
	case 7:
	{
		printf("¬ведите первое целое число: ");
		Z* z1 = inputZ();
		printf("¬ведите второе целое число: ");
		Z* z2 = inputZ();
		printf("–езультат: ");
		Z* result = SUB_ZZ_Z(z1, z2);
		printZ(result);
		freeZ(result);
		freeZ(z1);
		freeZ(z2);
	}
	break;
	case 8:
	{
		printf("¬ведите первое целое число: ");
		Z* z1 = inputZ();
		printf("¬ведите второе целое число: ");
		Z* z2 = inputZ();
		printf("–езультат: ");
		Z* result = MUL_ZZ_Z(z1, z2);
		printZ(result);
		freeZ(result);
		freeZ(z1);
		freeZ(z2);
	}
	break;
	case 9:
	{
		printf("¬ведите целое число: ");
		Z* z = inputZ();
		printf("¬ведите натуральное число: ");
		N* n = inputN();
		printf("–езультат: ");
		Z* result = DIV_ZN_Z(z, n);
		printZ(result);
		freeZ(result);
		freeZ(z);
		freeN(n);
	}
	break;
	case 10:
	{
		printf("¬ведите целое число: ");
		Z* z = inputZ();
		printf("¬ведите натуральное число: ");
		N* n = inputN();
		printf("–езультат: ");
		Z* result = MOD_ZN_Z(z, n);
		printZ(result);
		freeZ(result);
		freeZ(z);
		freeN(n);
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
		Q* q = inputQ();
		printf("–езультат: ");
		printQ(RED_Q_Q(q));
		freeQ(q);
	}
	break;
	case 2:
	{
		puts("¬ведите рациональное число:");
		Q* q = inputQ();
		printf("–езультат: %d", INT_Q_B(q));
		freeQ(q);
	}
	break;
	case 3:
	{
		printf("¬ведите целое число: ");
		Z* z = inputZ();
		printf("–езультат: ");
		Q* result = TRANS_Z_Q(z);
		printQ(result);
		freeQ(result);
		freeZ(z);
	}
	break;
	case 4:
	{
		puts("¬ведите рациональное число:");
		Q* q = inputQ();
		printf("–езультат: ");
		Z* result = TRANS_Q_Z(q);
		printZ(result);
		freeZ(result);
		freeQ(q);
	}
	break;
	case 5:
	{
		puts("¬ведите первое рациональное число:");
		Q* q1 = inputQ();
		puts("¬ведите второе рациональное число:");
		Q* q2 = inputQ();
		printf("–езультат: ");
		Q* result = ADD_QQ_Q(q1, q2);
		printQ(result);
		freeQ(result);
		freeQ(q1);
		freeQ(q2);
	}
	break;
	case 6:
	{
		puts("¬ведите первое рациональное число:");
		Q* q1 = inputQ();
		puts("¬ведите второе рациональное число:");
		Q* q2 = inputQ();
		printf("–езультат: ");
		Q* result = SUB_QQ_Q(q1, q2);
		printQ(result);
		freeQ(result);
		freeQ(q1);
		freeQ(q2);
	}
	break;
	case 7:
	{
		puts("¬ведите первое рациональное число:");
		Q* q1 = inputQ();
		puts("¬ведите второе рациональное число:");
		Q* q2 = inputQ();
		printf("–езультат: ");
		Q* result = MUL_QQ_Q(q1, q2);
		printQ(result);
		freeQ(result);
		freeQ(q1);
		freeQ(q2);
	}
	break;
	case 8:
	{
		puts("¬ведите первое рациональное число:");
		Q* q1 = inputQ();
		puts("¬ведите второе рациональное число:");
		Q* q2 = inputQ();
		printf("–езультат: ");
		Q* result = DIV_QQ_Q(q1, q2);
		printQ(result);
		freeQ(result);
		freeQ(q1);
		freeQ(q2);
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
		P* p1 = inputP();
		puts("¬ведите второй многочлен:");
		P* p2 = inputP();
		printf("–езультат: ");
		P* result = ADD_PP_P(p1, p2);
		printP(result);
		freeP(result);
		freeP(p1);
		freeP(p2);
	}
	break;
	case 2:
	{
		puts("¬ведите первый многочлен:");
		P* p1 = inputP();
		puts("¬ведите второй многочлен:");
		P* p2 = inputP();
		printf("–езультат: ");
		P* result = SUB_PP_P(p1, p2);
		printP(result);
		freeP(result);
		freeP(p1);
		freeP(p2);
	}
	break;
	case 3:
	{
		puts("¬ведите многочлен:");
		P* p = inputP();
		puts("¬ведите рациональное число:");
		Q* q = inputQ();
		printf("–езультат: ");
		P* result = MUL_PQ_P(p, q);
		printP(result);
		freeP(result);
		freeP(p);
		freeQ(q);
	}
	break;
	case 4:
	{
		puts("¬ведите многочлен:");
		P* p = inputP();
		printf("¬ведите число: ");
		int k = getNumber();
		printf("–езультат: ");
		P* result = MUL_Pxk_P(p, k);
		printP(result);
		freeP(result);
		freeP(p);
	}
	break;
	case 5:
	{
		puts("¬ведите многочлен:");
		P* p = inputP();
		printf("–езультат: ");
		Q* result = LED_P_Q(p);
		printQ(result);
		freeQ(result);
		freeP(p);
	}
	break;
	case 6:
	{
		puts("¬ведите многочлен:");
		P* p = inputP();
		printf("–езультат: ");
		N* result = DEG_P_N(p);
		printN(result);
		freeN(result);
		freeP(p);
	}
	break;
	case 7:
	{
		puts("¬ведите многочлен:");
		P* p = inputP();
		printf("–езультат: ");
		Q* result = FAC_P_Q(p);
		printQ(result);
		freeQ(result);
		freeP(p);
	}
	break;
	case 8:
	{
		puts("¬ведите первый многочлен:");
		P* p1 = inputP();
		puts("¬ведите второй многочлен:");
		P* p2 = inputP();
		printf("–езультат: ");
		P* result = MUL_PP_P(p1, p2);
		printP(result);
		freeP(result);
		freeP(p1);
		freeP(p2);
	}
	break;
	case 9:
	{
		puts("¬ведите первый многочлен:");
		P* p1 = inputP();
		puts("¬ведите второй многочлен:");
		P* p2 = inputP();
		printf("–езультат: ");
		int t = clock();
		P* result = DIV_PP_P(p1, p2);
		printf("%d\n", clock() - t);
		printP(result);
		freeP(result);
		freeP(p1);
		freeP(p2);
	}
	break;
	case 10:
	{
		puts("¬ведите первый многочлен:");
		P* p1 = inputP();
		puts("¬ведите второй многочлен:");
		P* p2 = inputP();
		printf("–езультат: ");
		P* result = MOD_PP_P(p1, p2);
		printP(result);
		freeP(result);
		freeP(p1);
		freeP(p2);
	}
	break;
	case 11:
	{
		puts("¬ведите первый многочлен:");
		P* p1 = inputP();
		puts("¬ведите второй многочлен:");
		P* p2 = inputP();
		printf("–езультат: ");
		P* result = GCF_PP_P(p1, p2);
		printP(result);
		freeP(result);
		freeP(p1);
		freeP(p2);
	}
	break;
	case 12:
	{
		puts("¬ведите многочлен:");
		P* p = inputP();
		printf("–езультат: ");
		P* result = DER_P_P(p);
		printP(result);
		freeP(result);
		freeP(p);
	}
	break;
	case 13:
	{
		puts("¬ведите многочлен:");
		P* p = inputP();
		printf("–езультат: ");
		P* result = NMR_P_P(p);
		printP(result);
		freeP(result);
		freeP(p);
	}
	break;
	}
	puts("");
	system("pause");
	system("cls");
}
