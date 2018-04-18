#pragma once
// N-13

N* GCF_NN_N(N* a, N* b)
{
	N* First = assignmentN(a);
	N* Second = assignmentN(b);
	while (NZER_N_B(First) && NZER_N_B(Second))
	{
		if (COM_NN_D(First, Second) > 1) // ���� ������ ������ �������
			First = MOD_NN_N(First, Second); // ������� ������� �� ������� ������� �� ������
		else
			Second = MOD_NN_N(Second, First); // ����� - ������� �� ������� ������� �� ������
	}
	if (COM_NN_D(First, Second) != 2)
		First = assignmentN(Second);
	freeN(Second);
	return First;
}