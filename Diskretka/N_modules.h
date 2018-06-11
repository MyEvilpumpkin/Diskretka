#pragma once
#include <iostream>
#include "malloc.h"

struct N
{
	int *n;
	int len;
};

int getNumber(); // ���� ��������������� ����� int
N* deNULL(N*); // �������� ������ ����� � ������ �����
N* intToN(int); // ������� �� int � N
N* input(); // ���� ����� N

N* initN(); // �������������
N* inputN(); // ����
N* zeroN(); // ������������� � ����������
N* assignmentN(N*); // ������������
void printN(N*); // �����
N* freeN(N*); // ������������ ������

int COM_NN_D(N*, N*);
bool NZER_N_B(N*);
N* ADD_1N_N(N*);
N* ADD_NN_N(N*, N*);
N* SUB_NN_N(N*, N*);
N* MUL_ND_N(N*, int);
N* MUL_Nk_N(N*, int);
N* MUL_NN_N(N*, N*);
N* SUB_NDN_N(N*, N*, int);
int DIV_NN_Dk(N*, N*, int&);
N* DIV_NN_N(N*, N*);
N* MOD_NN_N(N*, N*);
N* GCF_NN_N(N*, N*);
N* LCM_NN_N(N*, N*);
