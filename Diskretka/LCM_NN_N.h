#pragma once
// N-14

N LCM_NN_N(N First, N Second)
{
	N NOD; // ��� ���� �����
	N NOK; // ��� ���� �����
	N Temp; // ������������ ���� �����
	NOD = GCF_NN_N(First, Second); // ��� �����
	Temp = *MUL_NN_N(&First, &Second); // ������������ �����
	NOK = *DIV_NN_N(&Temp, &NOD); // ��� = ��������� ������������ ����� � �� ���
	return NOK;
}