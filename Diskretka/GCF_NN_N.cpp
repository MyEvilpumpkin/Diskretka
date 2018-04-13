// N-13
#include "golova.h"

N GCF_NN_N(struct N First, struct N Second)
{
	short Temp; // ��������� ��������� ���� �����
	bool FirstCheck; // �������� ������� �� ����
	bool SecondCheck; // �������� ������� �� ����
	FirstCheck = NZER_N_B(First);
	SecondCheck = NZER_N_B(Second);
	while ((FirstCheck == 1) && (SecondCheck == 1))
	{
		Temp = COM_NN_D(First, Second);
		if (Temp > 1) // ���� ������ ������ �������
			First = MOD_NN_N(First, Second); // ������� ������� �� ������� ������� �� ������
		else
			Second = MOD_NN_N(Second, First); // ����� - ������� �� ������� ������� �� ������
		FirstCheck = NZER_N_B(First);
		SecondCheck = NZER_N_B(Second);
	}
	Temp = COM_NN_D(First, Second);
	if (Temp == 2)
		return First;
	else
		return Second;
}