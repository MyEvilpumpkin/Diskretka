#include "modules.h"
#include <ctime>
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
		Q* q = inputQ();
		printf("���������: ");
		printQ(RED_Q_Q(q));
		freeQ(q);
	}
	break;
	case 2:
	{
		puts("������� ������������ �����:");
		Q* q = inputQ();
		printf("���������: %d", INT_Q_B(q));
		freeQ(q);
	}
	break;
	case 3:
	{
		printf("������� ����� �����: ");
		Z* z = inputZ();
		printf("���������: ");
		Q* result = TRANS_Z_Q(z);
		printQ(result);
		freeQ(result);
		freeZ(z);
	}
	break;
	case 4:
	{
		puts("������� ������������ �����:");
		Q* q = inputQ();
		printf("���������: ");
		Z* result = TRANS_Q_Z(q);
		printZ(result);
		freeZ(result);
		freeQ(q);
	}
	break;
	case 5:
	{
		puts("������� ������ ������������ �����:");
		Q* q1 = inputQ();
		puts("������� ������ ������������ �����:");
		Q* q2 = inputQ();
		printf("���������: ");
		Q* result = ADD_QQ_Q(q1, q2);
		printQ(result);
		freeQ(result);
		freeQ(q1);
		freeQ(q2);
	}
	break;
	case 6:
	{
		puts("������� ������ ������������ �����:");
		Q* q1 = inputQ();
		puts("������� ������ ������������ �����:");
		Q* q2 = inputQ();
		printf("���������: ");
		Q* result = SUB_QQ_Q(q1, q2);
		printQ(result);
		freeQ(result);
		freeQ(q1);
		freeQ(q2);
	}
	break;
	case 7:
	{
		puts("������� ������ ������������ �����:");
		Q* q1 = inputQ();
		puts("������� ������ ������������ �����:");
		Q* q2 = inputQ();
		printf("���������: ");
		Q* result = MUL_QQ_Q(q1, q2);
		printQ(result);
		freeQ(result);
		freeQ(q1);
		freeQ(q2);
	}
	break;
	case 8:
	{
		puts("������� ������ ������������ �����:");
		Q* q1 = inputQ();
		puts("������� ������ ������������ �����:");
		Q* q2 = inputQ();
		printf("���������: ");
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
// ������� ������ P-�������
void P_module(int option)
{
	switch (option)
	{
	case 1:
	{
		puts("������� ������ ���������:");
		P* p1 = inputP();
		puts("������� ������ ���������:");
		P* p2 = inputP();
		printf("���������: ");
		P* result = ADD_PP_P(p1, p2);
		printP(result);
		freeP(result);
		freeP(p1);
		freeP(p2);
	}
	break;
	case 2:
	{
		puts("������� ������ ���������:");
		P* p1 = inputP();
		puts("������� ������ ���������:");
		P* p2 = inputP();
		printf("���������: ");
		P* result = SUB_PP_P(p1, p2);
		printP(result);
		freeP(result);
		freeP(p1);
		freeP(p2);
	}
	break;
	case 3:
	{
		puts("������� ���������:");
		P* p = inputP();
		puts("������� ������������ �����:");
		Q* q = inputQ();
		printf("���������: ");
		P* result = MUL_PQ_P(p, q);
		printP(result);
		freeP(result);
		freeP(p);
		freeQ(q);
	}
	break;
	case 4:
	{
		puts("������� ���������:");
		P* p = inputP();
		printf("������� �����: ");
		int k = getNumber();
		printf("���������: ");
		P* result = MUL_Pxk_P(p, k);
		printP(result);
		freeP(result);
		freeP(p);
	}
	break;
	case 5:
	{
		puts("������� ���������:");
		P* p = inputP();
		printf("���������: ");
		Q* result = LED_P_Q(p);
		printQ(result);
		freeQ(result);
		freeP(p);
	}
	break;
	case 6:
	{
		puts("������� ���������:");
		P* p = inputP();
		printf("���������: ");
		N* result = DEG_P_N(p);
		printN(result);
		freeN(result);
		freeP(p);
	}
	break;
	case 7:
	{
		puts("������� ���������:");
		P* p = inputP();
		printf("���������: ");
		Q* result = FAC_P_Q(p);
		printQ(result);
		freeQ(result);
		freeP(p);
	}
	break;
	case 8:
	{
		puts("������� ������ ���������:");
		P* p1 = inputP();
		puts("������� ������ ���������:");
		P* p2 = inputP();
		printf("���������: ");
		P* result = MUL_PP_P(p1, p2);
		printP(result);
		freeP(result);
		freeP(p1);
		freeP(p2);
	}
	break;
	case 9:
	{
		puts("������� ������ ���������:");
		P* p1 = inputP();
		puts("������� ������ ���������:");
		P* p2 = inputP();
		printf("���������: ");
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
		puts("������� ������ ���������:");
		P* p1 = inputP();
		puts("������� ������ ���������:");
		P* p2 = inputP();
		printf("���������: ");
		P* result = MOD_PP_P(p1, p2);
		printP(result);
		freeP(result);
		freeP(p1);
		freeP(p2);
	}
	break;
	case 11:
	{
		puts("������� ������ ���������:");
		P* p1 = inputP();
		puts("������� ������ ���������:");
		P* p2 = inputP();
		printf("���������: ");
		P* result = GCF_PP_P(p1, p2);
		printP(result);
		freeP(result);
		freeP(p1);
		freeP(p2);
	}
	break;
	case 12:
	{
		puts("������� ���������:");
		P* p = inputP();
		printf("���������: ");
		P* result = DER_P_P(p);
		printP(result);
		freeP(result);
		freeP(p);
	}
	break;
	case 13:
	{
		puts("������� ���������:");
		P* p = inputP();
		printf("���������: ");
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
