#pragma once
// P-8 ������� ����

P* MUL_PP_P(P* First, P* Second)
{
	short i = First->len; // ��� �������� ������������� ����������
	P* Result; // ��������� ���������
	P* Temp,* tmp; // ��������� ��������� ������� ���������� �� ����������� �������
	if (i > 0) {
		Temp = MUL_PQ_P(Second, First->k[i]); // �������� ������ ��������� ���������� �� ��� ������������ �������
		Result = MUL_Pxk_P(Temp, i); // �������� ������������ �� ������� ����������� ������� ������� ����������
		freeP(Temp);
		for (i = First->len - 1; i >= 0; i--) {
			Temp = MUL_PQ_P(Second, First->k[i]); // �������� ������ ��������� ���������� �� ��� ������������ �������
			tmp = MUL_Pxk_P(Temp, i); // �������� ������������ �� ������� ����������� ������� ������� ����������
			freeP(Temp);
			Temp = ADD_PP_P(Result, tmp); // ����������� � ���������� ������������
			freeP(Result);
			Result = assignmentP(Temp);
			freeP(Temp);
			freeP(tmp);
		}
	}
	else
		Result = zeroP();
	return Result;
}