#pragma once
// N-10

int DIV_NN_Dk(N* a, N* b, int &k)
{
	int Result = 1, // ������ ����� �������
		Flag; // ���������� ��� ������ �� �����
	N* Temp; // ��������� ���������� ��� �������� ������������
	k = 0;
	N* First, *Second;
	if (COM_NN_D(a, b) == 2) {
		First = assignmentN(a);
		Second = assignmentN(b);
	}
	else {
		First = assignmentN(b);
		Second = assignmentN(a);
	}
	do
	{
		Temp = MUL_Nk_N(Second, k); // �������� �������� �� 10^k
		Flag = COM_NN_D(First, Temp); // ���������� ������� � ������������
		freeN(Temp);
		if (Flag != 1) // ���� ������������ ������, �� ����������� ������� 10
			k++;
	} while (Flag != 1); // ���� ������������ �� ������ ������ ��������
	k--; // ��� ��� ��� ��������� ��������� k ����� ������ �� 1 �� ������������
	Temp = MUL_Nk_N(Second, k); // ��������� ���������� ������������ �������� � 10^k, ������� ��������
	do
	{
		N* tmp = MUL_ND_N(Temp, Result); // ��������� ������������ �� �����
		Flag = COM_NN_D(First, tmp); // ���������� ��� � �������
		if (Flag != 1) // ���� ������������ ������ ��������, ��������� ��������� �����
			Result++;
		freeN(tmp);
	} while (Flag != 1);
	Result--; // ���������� �������� �������
	freeN(Temp);
	freeN(First);
	freeN(Second);
	return Result;
}