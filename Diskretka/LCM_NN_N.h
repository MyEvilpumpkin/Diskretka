#pragma once
// N-14

N LCM_NN_N(struct N First, struct N Second)
{
	struct N NOD; // ��� ���� �����
	struct N NOK; // ��� ���� �����
	struct N Temp; // ������������ ���� �����
	NOD = GCF_NN_N(First, Second); // ��� �����
	Temp = MUL_NN_N(First, Second); // ������������ �����
	NOK = DIV_NN_N(Temp, NOD); // ��� = ��������� ������������ ����� � �� ���
	return NOK;
}