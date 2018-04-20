#pragma once
// N-13 �������� �����

N* GCF_NN_N(N* a, N* b)
{
	N* First = assignmentN(a);
	N* Second = assignmentN(b);
	N* temp;
	while (NZER_N_B(First) && NZER_N_B(Second)) //���� ��� ����� - �� ����
	{
		if (COM_NN_D(First, Second) > 1) { // ���� ������ ������ �������
			temp = MOD_NN_N(First, Second); // ������� ������� �� ������� ������� �� ������
			freeN(First);
			First = assignmentN(temp);
			freeN(temp);
		}
		else {
			temp = MOD_NN_N(Second, First); // ����� - ������� �� ������� ������� �� ������
			freeN(Second);
			Second = assignmentN(temp);
			freeN(temp);
		}
			
	}
	if (COM_NN_D(First, Second) != 2) { // ���� ������ ����� - ������ �������
		freeN(First);
		First = assignmentN(Second); // ������ �� �������
	}
	freeN(Second);
	return First;
}