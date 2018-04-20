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
	N* Result = zeroN(); // ������� �� �������
	N* Part = assignmentN(First); // ��������� ������� �� �������
	N* TempRes, *Temp; // ��������� ��������
	int Numb, // ������ ����� �� �������
		Flag, // ���������� ��� ������ �� �����
		k = 0; // ������� �������
	if (NZER_N_B(Second))
	do
	{
		Numb = DIV_NN_Dk(Part, Second, k); // ��������� ������ ����� � ������� ������� ��� �������
		TempRes = zeroN(); // 16 - 20 ������ - ��� �������� ������������� ������ ����� ������� �� 10^k
		Temp = ADD_1N_N(TempRes); // �������� 1 - ��� ��� ��� ��������� ��� ����� �� ����� ������ �� ���������
		freeN(TempRes);
		TempRes = MUL_ND_N(Temp, Numb); // �������� 1 �� ������ ����� �������
		freeN(Temp);
		Temp = MUL_Nk_N(TempRes, k); // �������� �� 10^k
		freeN(TempRes);
		TempRes = ADD_NN_N(Result, Temp); // ���������� ���������� ���������� � ������
		freeN(Result);
		Result = assignmentN(TempRes);
		freeN(TempRes);
		TempRes = MUL_NN_N(Temp, Second);
		freeN(Temp);
		Temp = SUB_NN_N(Part, TempRes); // ���������� ���������� �������
		freeN(Part);
		Part = assignmentN(Temp);
		freeN(Temp);
		Flag = COM_NN_D(Part, Second); // ���������� "�������" � ��������
		freeN(TempRes);
	} while (Flag != 1);
	freeN(Part);
	freeN(First);
	freeN(Second);
	return Result;
}