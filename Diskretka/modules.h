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
		printf("������� ������ ����������� �����: ");
		N* a = inputN();
		printf("������� ������ ����������� �����: ");
		N* b = inputN();
		printf("���������: %d", COM_NN_D(a, b));
		freeN(a);
		freeN(b);
	}
	break;
	case 2:
	{
		printf("������� ����������� �����: ");
		N* a = inputN();
		printf("���������: %d", NZER_N_B(a));
		freeN(a);
	}
	break;
	case 3:
	{
		printf("������� ����������� �����: ");
		N* a = inputN();
		printf("���������: ");
		N* r = ADD_1N_N(a);
		printN(r);
		freeN(r);
		freeN(a);
	}
	break;
	case 4:
	{
		printf("������� ������ ����������� �����: ");
		N* a = inputN();
		printf("������� ������ ����������� �����: ");
		N* b = inputN();
		printf("���������: ");
		N* r = ADD_NN_N(a, b);
		printN(r);
		freeN(r);
		freeN(a);
		freeN(b);
	}
	break;
	case 5:
	{
		printf("������� ������ ����������� �����: ");
		N* a = inputN();
		printf("������� ������ ����������� �����: ");
		N* b = inputN();
		printf("���������: ");
		N* r = SUB_NN_N(a, b);
		printN(r);
		freeN(r);
		freeN(a);
		freeN(b);
	}
	break;
	case 6:
	{
		printf("������� ����������� �����: ");
		N* a = inputN();
		printf("������� �����: ");
		int n = getNumber();
		printf("���������: ");
		N* r = MUL_ND_N(a, n);
		printN(r);
		freeN(r);
		freeN(a);
	}
	break;
	case 7:
	{
		printf("������� ����������� �����: ");
		N* a = inputN();
		printf("������� �����: ");
		int n = getNumber();
		printf("���������: ");
		N* r = MUL_Nk_N(a, n);
		printN(r);
		freeN(r);
		freeN(a);
	}
	break;
	case 8:
	{
		printf("������� ������ ����������� �����: ");
		N* a = inputN();
		printf("������� ������ ����������� �����: ");
		N* b = inputN();
		printf("���������: ");
		N* r = MUL_NN_N(a, b);
		printN(r);
		freeN(r);
		freeN(a);
		freeN(b);
	}
	break;
	case 9:
	{
		printf("������� ������ ����������� �����: ");
		N* a = inputN();
		printf("������� ������ ����������� �����: ");
		N* b = inputN();
		printf("������� �����: ");
		int n = getNumber();
		printf("���������: ");
		N* r = SUB_NDN_N(a, b, n);
		printN(r);
		freeN(r);
		freeN(a);
		freeN(b);
	}
	break;
	case 10:
	{
		printf("������� ������ ����������� �����: ");
		N* a = inputN();
		printf("������� ������ ����������� �����: ");
		N* b = inputN();
		int n = 0;
		printf("���������: %d", DIV_NN_Dk(a, b, n));
		freeN(a);
		freeN(b);
	}
	break;
	case 11:
	{
		printf("������� ������ ����������� �����: ");
		N* a = inputN();
		printf("������� ������ ����������� �����: ");
		N* b = inputN();
		printf("���������: ");
		N* r = DIV_NN_N(a, b);
		printN(r);
		freeN(r);
		freeN(a);
		freeN(b);
	}
	break;
	case 12:
	{
		printf("������� ������ ����������� �����: ");
		N* a = inputN();
		printf("������� ������ ����������� �����: ");
		N* b = inputN();
		printf("���������: ");
		N* r = MOD_NN_N(a, b);
		printN(r);
		freeN(r);
		freeN(a);
		freeN(b);
	}
	break;
	case 13:
	{
		printf("������� ������ ����������� �����: ");
		N* a = inputN();
		printf("������� ������ ����������� �����: ");
		N* b = inputN();
		printf("���������: ");
		N* r = GCF_NN_N(a, b);
		printN(r);
		freeN(r);
		freeN(a);
		freeN(b);
	}
	break;
	case 14:
	{
		printf("������� ������ ����������� �����: ");
		N* a = inputN();
		printf("������� ������ ����������� �����: ");
		N* b = inputN();
		printf("���������: ");
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

void Z_modules(int option) {
	switch (option)
	{
	case 1:
	{
		printf("������� ����� �����: ");
		Z* a = inputZ();
		printf("���������: ");
		N* r = ABS_Z_N(a);
		printN(r);
		freeN(r);
		freeZ(a);
	}
	break;
	case 2:
	{
		printf("������� ����� �����: ");
		Z* a = inputZ();
		printf("���������: %d", POZ_Z_D(a));
		freeZ(a);
	}
	break;
	case 3:
	{
		printf("������� ����� �����: ");
		Z* a = inputZ();
		printf("���������: ");
		Z* r = MUL_ZM_Z(a);
		printZ(r);
		freeZ(r);
		freeZ(a);
	}
	break;
	case 4:
	{
		printf("������� ����������� �����: ");
		N* a = inputN();
		printf("���������: ");
		Z* r = TRANS_N_Z(a);
		printZ(r);
		freeZ(r);
		freeN(a);
	}
	break;
	case 5:
	{
		printf("������� ����� �����: ");
		Z* a = inputZ();
		printf("���������: ");
		N* r = TRANS_Z_N(a);
		printN(r);
		freeN(r);
		freeZ(a);
	}
	break;
	case 6:
	{
		printf("������� ������ ����� �����: ");
		Z* a = inputZ();
		printf("������� ������ ����� �����: ");
		Z* b = inputZ();
		printf("���������: ");
		Z* r = ADD_ZZ_Z(a, b);
		printZ(r);
		freeZ(r);
		freeZ(a);
		freeZ(b);
	}
	break;
	case 7:
	{
		printf("������� ������ ����� �����: ");
		Z* a = inputZ();
		printf("������� ������ ����� �����: ");
		Z* b = inputZ();
		printf("���������: ");
		Z* r = SUB_ZZ_Z(a, b);
		printZ(r);
		freeZ(r);
		freeZ(a);
		freeZ(b);
	}
	break;
	case 8:
	{
		printf("������� ������ ����� �����: ");
		Z* a = inputZ();
		printf("������� ������ ����� �����: ");
		Z* b = inputZ();
		printf("���������: ");
		Z* r = MUL_ZZ_Z(a, b);
		printZ(r);
		freeZ(r);
		freeZ(a);
		freeZ(b);
	}
	break;
	case 9:
	{
		printf("������� ����� �����: ");
		Z* a = inputZ();
		printf("������� ����������� �����: ");
		N* b = inputN();
		printf("���������: ");
		Z* r = DIV_ZZ_Z(a, b);
		printZ(r);
		freeZ(r);
		freeZ(a);
		freeN(b);
	}
	break;
	case 10:
	{
		printf("������� ����� �����: ");
		Z* a = inputZ();
		printf("������� ����������� �����: ");
		N* b = inputN();
		printf("���������: ");
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

void Q_modules(int option) {
	switch (option)
	{
	case 1:
	{
		puts("������� ������������ �����:");
		Q* a = inputQ();
		printf("���������: ");
		printQ(RED_Q_Q(a));
		freeQ(a);
	}
	break;
	case 2:
	{
		puts("������� ������������ �����:");
		Q* a = inputQ();
		printf("���������: %d", INT_Q_B(a));
		freeQ(a);
	}
	break;
	case 3:
	{
		printf("������� ����� �����: ");
		Z* a = inputZ();
		printf("���������: ");
		Q* r = TRANS_Z_Q(a);
		printQ(r);
		freeQ(r);
		freeZ(a);
	}
	break;
	case 4:
	{
		puts("������� ������������ �����:");
		Q* a = inputQ();
		printf("���������: ");
		Z* r = TRANS_Q_Z(a);
		printZ(r);
		freeZ(r);
		freeQ(a);
	}
	break;
	case 5:
	{
		puts("������� ������ ������������ �����:");
		Q* a = inputQ();
		puts("������� ������ ������������ �����:");
		Q* b = inputQ();
		printf("���������: ");
		Q* r = ADD_QQ_Q(a, b);
		printQ(r);
		freeQ(r);
		freeQ(a);
		freeQ(b);
	}
	break;
	case 6:
	{
		puts("������� ������ ������������ �����:");
		Q* a = inputQ();
		puts("������� ������ ������������ �����:");
		Q* b = inputQ();
		printf("���������: ");
		Q* r = SUB_QQ_Q(a, b);
		printQ(r);
		freeQ(r);
		freeQ(a);
		freeQ(b);
	}
	break;
	case 7:
	{
		puts("������� ������ ������������ �����:");
		Q* a = inputQ();
		puts("������� ������ ������������ �����:");
		Q* b = inputQ();
		printf("���������: ");
		Q* r = MUL_QQ_Q(a, b);
		printQ(r);
		freeQ(r);
		freeQ(a);
		freeQ(b);
	}
	break;
	case 8:
	{
		puts("������� ������ ������������ �����:");
		Q* a = inputQ();
		puts("������� ������ ������������ �����:");
		Q* b = inputQ();
		printf("���������: ");
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

void P_modules(int option) {
	switch (option)
	{
	case 1:
	{
		puts("������� ������ ���������:");
		P* a = inputP();
		puts("������� ������ ���������:");
		P* b = inputP();
		printf("���������: ");
		P* r = ADD_PP_P(a, b);
		printP(r);
		freeP(r);
		freeP(a);
		freeP(b);
	}
	break;
	case 2:
	{
		puts("������� ������ ���������:");
		P* a = inputP();
		puts("������� ������ ���������:");
		P* b = inputP();
		printf("���������: ");
		P* r = SUB_PP_P(a, b);
		printP(r);
		freeP(r);
		freeP(a);
		freeP(b);
	}
	break;
	case 3:
	{
		puts("������� ���������:");
		P* a = inputP();
		puts("������� ������������ �����:");
		Q* b = inputQ();
		printf("���������: ");
		P* r = MUL_PQ_P(a, b);
		printP(r);
		freeP(r);
		freeP(a);
		freeQ(b);
	}
	break;
	case 4:
	{
		puts("������� ���������:");
		P* a = inputP();
		printf("������� �����: ");
		int n = getNumber();
		printf("���������: ");
		P* r = MUL_Pxk_P(a, n);
		printP(r);
		freeP(r);
		freeP(a);
	}
	break;
	case 5:
	{
		puts("������� ���������:");
		P* a = inputP();
		printf("���������: ");
		Q* r = LED_P_Q(a);
		printQ(r);
		freeQ(r);
		freeP(a);
	}
	break;
	case 6:
	{
		puts("������� ���������:");
		P* a = inputP();
		printf("���������: ");
		N* r = DEG_P_N(a);
		printN(r);
		freeN(r);
		freeP(a);
	}
	break;
	case 7:
	{
		puts("������� ���������:");
		P* a = inputP();
		printf("���������: ");
		Q* r = FAC_P_Q(a);
		printQ(r);
		freeQ(r);
		freeP(a);
	}
	break;
	case 8:
	{
		puts("������� ������ ���������:");
		P* a = inputP();
		puts("������� ������ ���������:");
		P* b = inputP();
		printf("���������: ");
		P* r = MUL_PP_P(a, b);
		printP(r);
		freeP(r);
		freeP(a);
		freeP(b);
	}
	break;
	case 9:
	{
		puts("������� ������ ���������:");
		P* a = inputP();
		puts("������� ������ ���������:");
		P* b = inputP();
		printf("���������: ");
		P* r = DIV_PP_P(a, b);
		printP(r);
		freeP(r);
		freeP(a);
		freeP(b);
	}
	break;
	case 10:
	{
		puts("������� ������ ���������:");
		P* a = inputP();
		puts("������� ������ ���������:");
		P* b = inputP();
		printf("���������: ");
		P* r = MOD_PP_P(a, b);
		printP(r);
		freeP(r);
		freeP(a);
		freeP(b);
	}
	break;
	case 11:
	{
		puts("������� ������ ���������:");
		P* a = inputP();
		puts("������� ������ ���������:");
		P* b = inputP();
		printf("���������: ");
		P* r = GCF_PP_P(a, b);
		printP(r);
		freeP(r);
		freeP(a);
		freeP(b);
	}
	break;
	case 12:
	{
		puts("������� ���������:");
		P* a = inputP();
		printf("���������: ");
		P* r = DER_P_P(a);
		printP(r);
		freeP(r);
		freeP(a);
	}
	break;
	case 13:
	{
		puts("������� ���������:");
		P* a = inputP();
		printf("���������: ");
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