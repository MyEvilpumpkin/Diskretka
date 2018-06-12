#include "modules.h"

// ������� ������ N-�������
void N_module(int option)
{
	switch (option)
	{
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
		int d = getNumber();
		printf("���������: ");
		N* r = MUL_ND_N(a, d);
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
		printf("������� �����: ");
		int d = getNumber();
		printf("������� ������ ����������� �����: ");
		N* b = inputN();
		printf("���������: ");
		N* r = SUB_NDN_N(a, d, b);
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
		int k = 0;
		printf("���������: %d", DIV_NN_Dk(a, b, k));
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
// ������� ������ Z-�������
void Z_module(int option)
{
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
// ������� ������ Q-�������
void Q_module(int option)
{
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
// ������� ������ P-�������
void P_module(int option)
{
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
