#include "modules.h"

// ������� ������ N-�������
void N_module(int option)
{
	switch (option)
	{
	case 1:
	{
		printf("������� ������ ����������� �����: ");
		N* n1 = inputN();
		printf("������� ������ ����������� �����: ");
		N* n2 = inputN();
		printf("���������: %d", COM_NN_D(n1, n2));
		freeN(n1);
		freeN(n2);
	}
	break;
	case 2:
	{
		printf("������� ����������� �����: ");
		N* n = inputN();
		printf("���������: %d", NZER_N_B(n));
		freeN(n);
	}
	break;
	case 3:
	{
		printf("������� ����������� �����: ");
		N* n = inputN();
		printf("���������: ");
		N* result = ADD_1N_N(n);
		printN(result);
		freeN(result);
		freeN(n);
	}
	break;
	case 4:
	{
		printf("������� ������ ����������� �����: ");
		N* n1 = inputN();
		printf("������� ������ ����������� �����: ");
		N* n2 = inputN();
		printf("���������: ");
		N* result = ADD_NN_N(n1, n2);
		printN(result);
		freeN(result);
		freeN(n1);
		freeN(n2);
	}
	break;
	case 5:
	{
		printf("������� ������ ����������� �����: ");
		N* n1 = inputN();
		printf("������� ������ ����������� �����: ");
		N* n2 = inputN();
		printf("���������: ");
		N* result = SUB_NN_N(n1, n2);
		printN(result);
		freeN(result);
		freeN(n1);
		freeN(n2);
	}
	break;
	case 6:
	{
		printf("������� ����������� �����: ");
		N* n = inputN();
		printf("������� �����: ");
		int d = getNumber();
		printf("���������: ");
		N* result = MUL_ND_N(n, d);
		printN(result);
		freeN(result);
		freeN(n);
	}
	break;
	case 7:
	{
		printf("������� ����������� �����: ");
		N* n = inputN();
		printf("������� �����: ");
		int k = getNumber();
		printf("���������: ");
		N* result = MUL_Nk_N(n, k);
		printN(result);
		freeN(result);
		freeN(n);
	}
	break;
	case 8:
	{
		printf("������� ������ ����������� �����: ");
		N* n1 = inputN();
		printf("������� ������ ����������� �����: ");
		N* n2 = inputN();
		printf("���������: ");
		N* result = MUL_NN_N(n1, n2);
		printN(result);
		freeN(result);
		freeN(n1);
		freeN(n2);
	}
	break;
	case 9:
	{
		printf("������� ������ ����������� �����: ");
		N* n1 = inputN();
		printf("������� �����: ");
		int d = getNumber();
		printf("������� ������ ����������� �����: ");
		N* n2 = inputN();
		printf("���������: ");
		N* result = SUB_NDN_N(n1, d, n2);
		printN(result);
		freeN(result);
		freeN(n1);
		freeN(n2);
	}
	break;
	case 10:
	{
		printf("������� ������ ����������� �����: ");
		N* n1 = inputN();
		printf("������� ������ ����������� �����: ");
		N* n2 = inputN();
		int k = 0;
		printf("���������: %d", DIV_NN_Dk(n1, n2, k));
		freeN(n1);
		freeN(n2);
	}
	break;
	case 11:
	{
		printf("������� ������ ����������� �����: ");
		N* n1 = inputN();
		printf("������� ������ ����������� �����: ");
		N* n2 = inputN();
		printf("���������: ");
		N* result = DIV_NN_N(n1, n2);
		printN(result);
		freeN(result);
		freeN(n1);
		freeN(n2);
	}
	break;
	case 12:
	{
		printf("������� ������ ����������� �����: ");
		N* n1 = inputN();
		printf("������� ������ ����������� �����: ");
		N* n2 = inputN();
		printf("���������: ");
		N* result = MOD_NN_N(n1, n2);
		printN(result);
		freeN(result);
		freeN(n1);
		freeN(n2);
	}
	break;
	case 13:
	{
		printf("������� ������ ����������� �����: ");
		N* n1 = inputN();
		printf("������� ������ ����������� �����: ");
		N* n2 = inputN();
		printf("���������: ");
		N* result = GCF_NN_N(n1, n2);
		printN(result);
		freeN(result);
		freeN(n1);
		freeN(n2);
	}
	break;
	case 14:
	{
		printf("������� ������ ����������� �����: ");
		N* n1 = inputN();
		printf("������� ������ ����������� �����: ");
		N* n2 = inputN();
		printf("���������: ");
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
// ������� ������ Z-�������
void Z_module(int option)
{
	switch (option)
	{
	case 1:
	{
		printf("������� ����� �����: ");
		Z* z = inputZ();
		printf("���������: ");
		N* result = ABS_Z_N(z);
		printN(result);
		freeN(result);
		freeZ(z);
	}
	break;
	case 2:
	{
		printf("������� ����� �����: ");
		Z* z = inputZ();
		printf("���������: %d", POZ_Z_D(z));
		freeZ(z);
	}
	break;
	case 3:
	{
		printf("������� ����� �����: ");
		Z* z = inputZ();
		printf("���������: ");
		Z* result = MUL_ZM_Z(z);
		printZ(result);
		freeZ(result);
		freeZ(z);
	}
	break;
	case 4:
	{
		printf("������� ����������� �����: ");
		N* n = inputN();
		printf("���������: ");
		Z* result = TRANS_N_Z(n);
		printZ(result);
		freeZ(result);
		freeN(n);
	}
	break;
	case 5:
	{
		printf("������� ����� �����: ");
		Z* z = inputZ();
		printf("���������: ");
		N* result = TRANS_Z_N(z);
		printN(result);
		freeN(result);
		freeZ(z);
	}
	break;
	case 6:
	{
		printf("������� ������ ����� �����: ");
		Z* z1 = inputZ();
		printf("������� ������ ����� �����: ");
		Z* z2 = inputZ();
		printf("���������: ");
		Z* result = ADD_ZZ_Z(z1, z2);
		printZ(result);
		freeZ(result);
		freeZ(z1);
		freeZ(z2);
	}
	break;
	case 7:
	{
		printf("������� ������ ����� �����: ");
		Z* z1 = inputZ();
		printf("������� ������ ����� �����: ");
		Z* z2 = inputZ();
		printf("���������: ");
		Z* result = SUB_ZZ_Z(z1, z2);
		printZ(result);
		freeZ(result);
		freeZ(z1);
		freeZ(z2);
	}
	break;
	case 8:
	{
		printf("������� ������ ����� �����: ");
		Z* z1 = inputZ();
		printf("������� ������ ����� �����: ");
		Z* z2 = inputZ();
		printf("���������: ");
		Z* result = MUL_ZZ_Z(z1, z2);
		printZ(result);
		freeZ(result);
		freeZ(z1);
		freeZ(z2);
	}
	break;
	case 9:
	{
		printf("������� ����� �����: ");
		Z* z = inputZ();
		printf("������� ����������� �����: ");
		N* n = inputN();
		printf("���������: ");
		Z* result = DIV_ZN_Z(z, n);
		printZ(result);
		freeZ(result);
		freeZ(z);
		freeN(n);
	}
	break;
	case 10:
	{
		printf("������� ����� �����: ");
		Z* z = inputZ();
		printf("������� ����������� �����: ");
		N* n = inputN();
		printf("���������: ");
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
