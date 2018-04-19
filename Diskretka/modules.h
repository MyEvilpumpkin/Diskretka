#pragma once
#include "golova.h"
#include "COM_NN_D.h"  // N-1
#include "NZER_N_B.h"  // N-2
#include "ADD_1N_N.h"  // N-3
#include "ADD_NN_N.h"  // N-4
#include "SUB_NN_N.h"  // N-5
#include "MUL_ND_N.h"  // N-6
#include "MUL_Nk_N.h"  // N-7
#include "MUL_NN_N.h"  // N-8
#include "SUB_NDN_N.h" // N-9
#include "DIV_NN_Dk.h" // N-10
#include "DIV_NN_N.h"  // N-11
#include "MOD_NN_N.h"  // N-12
#include "GCF_NN_N.h"  // N-13
#include "LCM_NN_N.h"  // N-14
#include "ABS_Z_N.h"   // Z-1
#include "POZ_Z_D.h"   // Z-2
#include "MUL_ZM_Z.h"  // Z-3
#include "TRANS_N_Z.h" // Z-4
#include "TRANS_Z_N.h" // Z-5
#include "ADD_ZZ_Z.h"  // Z-6
#include "SUB_ZZ_Z.h"  // Z-7
#include "MUL_ZZ_Z.h"  // Z-8
#include "DIV_ZZ_Z.h"  // Z-9
#include "MOD_ZZ_Z.h"  // Z-10
#include "RED_Q_Q.h"   // Q-1
#include "INT_Q_B.h"   // Q-2
#include "TRANS_Z_Q.h" // Q-3
#include "TRANS_Q_Z.h" // Q-4
#include "ADD_QQ_Q.h"  // Q-5
#include "SUB_QQ_Q.h"  // Q-6
#include "MUL_QQ_Q.h"  // Q-7
#include "DIV_QQ_Q.h"  // Q-8
#include "ADD_PP_P.h"  // P-1
#include "SUB_PP_P.h"  // P-2
#include "MUL_PQ_P.h"  // P-3
#include "MUL_Pxk_P.h" // P-4
#include "LED_P_Q.h"   // P-5
#include "DEG_P_N.h"   // P-6
#include "FAC_P_Q.h"   // P-7
#include "MUL_PP_P.h"  // P-8
#include "DIV_PP_P.h"  // P-9
#include "MOD_PP_P.h"  // P-10
#include "GCF_PP_P.h"  // P-11
#include "DER_P_P.h"   // P-12
#include "NMR_P_P.h"   // P-13

void N_modules(int option) {
	switch (option) {
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
		printN(ADD_1N_N(a));
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
		printN(ADD_NN_N(a, b));
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
		printN(SUB_NN_N(a, b));
		freeN(a);
		freeN(b);
	}
	break;
	case 6:
	{
		printf("¬ведите натуральное число: ");
		N* a = inputN();
		printf("¬ведите число: ");
		int n = getNumber();
		printf("–езультат: ");
		printN(MUL_ND_N(a, n));
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
		printN(MUL_Nk_N(a, n));
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
		printN(MUL_NN_N(a, b));
		freeN(a);
		freeN(b);
	}
	break;
	case 9:
	{
		printf("¬ведите первое натуральное число: ");
		N* a = inputN();
		printf("¬ведите второе натуральное число: ");
		N* b = inputN();
		printf("¬ведите число: ");
		int n = getNumber();
		printf("–езультат: ");
		printN(SUB_NDN_N(a, b, n));
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
		int n = 0;
		printf("–езультат: %d", DIV_NN_Dk(a, b, n));
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
		printN(DIV_NN_N(a, b));
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
		printN(MOD_NN_N(a, b));
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
		printN(GCF_NN_N(a, b));
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
		printN(LCM_NN_N(a, b));
		freeN(a);
		freeN(b);
	}
	break;
	}
	puts("");
	system("pause");
	system("cls");
}

void Z_modules(int option) {
	switch (option)
	{
	case 1:
	{
		printf("¬ведите целое число: ");
		Z* a = inputZ();
		printf("–езультат: ");
		printN(ABS_Z_N(a));
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
		printZ(MUL_ZM_Z(a));
		freeZ(a);
	}
	break;
	case 4:
	{
		printf("¬ведите натуральное число: ");
		N* a = inputN();
		printf("–езультат: ");
		printZ(TRANS_N_Z(a));
		freeN(a);
	}
	break;
	case 5:
	{
		printf("¬ведите целое число: ");
		Z* a = inputZ();
		printf("–езультат: ");
		printN(TRANS_Z_N(a));
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
		printZ(ADD_ZZ_Z(a, b));
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
		printZ(SUB_ZZ_Z(a, b));
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
		printZ(MUL_ZZ_Z(a, b));
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
		printZ(DIV_ZZ_Z(a, b));
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
		printZ(MOD_ZZ_Z(a, b));
		freeZ(a);
		freeN(b);
	}
	break;
	}
	puts("");
	system("pause");
	system("cls");
}

void Q_modules(int option) {
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
		printQ(TRANS_Z_Q(a));
		freeZ(a);
	}
	break;
	case 4:
	{
		puts("¬ведите рациональное число:");
		Q* a = inputQ();
		printf("–езультат: ");
		printZ(TRANS_Q_Z(a));
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
		printQ(ADD_QQ_Q(a, b));
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
		printQ(SUB_QQ_Q(a, b));
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
		printQ(MUL_QQ_Q(a, b));
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
		printQ(DIV_QQ_Q(a, b));
		freeQ(a);
		freeQ(b);
	}
	break;
	}
	puts("");
	system("pause");
	system("cls");
}

void P_modules(int option) {
	switch (option)
	{
	case 1:
	{
		puts("¬ведите первый многочлен:");
		P* a = inputP();
		puts("¬ведите второй многочлен:");
		P* b = inputP();
		printf("–езультат: ");
		printP(ADD_PP_P(a, b));
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
		printP(SUB_PP_P(a, b));
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
		printP(MUL_PQ_P(a, b));
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
		printP(MUL_Pxk_P(a, n));
		freeP(a);
	}
	break;
	case 5:
	{
		puts("¬ведите многочлен:");
		P* a = inputP();
		printf("–езультат: ");
		printQ(LED_P_Q(a));
		freeP(a);
	}
	break;
	case 6:
	{
		puts("¬ведите многочлен:");
		P* a = inputP();
		printf("–езультат: ");
		printN(DEG_P_N(a));
		freeP(a);
	}
	break;
	case 7:
	{
		puts("¬ведите многочлен:");
		P* a = inputP();
		printf("–езультат: ");
		printQ(FAC_P_Q(a));
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
		printP(MUL_PP_P(a, b));
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
		printP(DIV_PP_P(a, b));
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
		printP(MOD_PP_P(a, b));
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
		printP(GCF_PP_P(a, b));
		freeP(a);
		freeP(b);
	}
	break;
	case 12:
	{
		puts("¬ведите многочлен:");
		P* a = inputP();
		printf("–езультат: ");
		printP(DER_P_P(a));
		freeP(a);
	}
	break;
	case 13:
	{
		puts("¬ведите многочлен:");
		P* a = inputP();
		printf("–езультат: ");
		printP(NMR_P_P(a));
		freeP(a);
	}
	break;
	}
	puts("");
	system("pause");
	system("cls");
}