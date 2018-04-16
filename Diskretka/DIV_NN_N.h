#pragma once
// N-11

N* DIV_NN_N(N* a, N* b)
{
	N* First,* Second;
	if (COM_NN_D(a, b) == 2) {
		First = assignmentN(a);
		Second = assignmentN(b);
	}
	else {
		First = assignmentN(b);
		Second = assignmentN(a);
	}
	N* Result = getZero(); // ������� �� �������
	N* Part = assignmentN(First); // ��������� ������� �� �������
	N* TempRes; // ��������� ��������
	int Numb, // ������ ����� �� �������
		Flag, // ���������� ��� ������ �� �����
		k; // ������� �������
	if (NZER_N_B(Second))
	do
	{
		Numb = DIV_NN_Dk(Part, Second, k); // ��������� ������ ����� � ������� ������� ��� �������
		TempRes = getZero(); // 16 - 20 ������ - ��� �������� ������������� ������ ����� ������� �� 10^k
		TempRes = ADD_1N_N(TempRes); // �������� 1 - ��� ��� ��� ��������� ��� ����� �� ����� ������ �� ���������
		TempRes = MUL_ND_N(TempRes, Numb); // �������� 1 �� ������ ����� �������
		TempRes = MUL_Nk_N(TempRes, k); // �������� �� 10^k
		Result = ADD_NN_N(Result, TempRes); // ���������� ���������� ���������� � ������
		TempRes = MUL_NN_N(TempRes, Second);
		Part = SUB_NN_N(Part, TempRes); // ���������� ���������� �������
		Flag = COM_NN_D(Part, Second); // ���������� "�������" � ��������
	} while (Flag != 1);
	return Result;
}