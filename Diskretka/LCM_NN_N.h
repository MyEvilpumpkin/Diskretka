#pragma once
// N-14 �������� �����

N* LCM_NN_N(N* First, N* Second)
{
	N* NOD = GCF_NN_N(First, Second); // ��� ���� �����
	N* Temp = MUL_NN_N(First, Second); // ������������ ���� �����
	N* NOK = DIV_NN_N(Temp, NOD); // ��� ���� �����
	freeN(NOD);
	freeN(Temp);
	return NOK;
}