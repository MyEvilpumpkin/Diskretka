#pragma once
// P-8

P* MUL_PP_P(P* First, P* Second)
{
	short i = First->len; // ��� �������� ������������� ����������
	P* Result = initP(); // ��������� ���������
	P* Temp = initP(); // ��������� ��������� ������� ���������� �� ����������� �������
	Result->len = (First->len) + (Second->len); // ������� ���������� ����� ����� �������� ����������
	Result->k = (Q**)malloc((Result->len + 1) * sizeof(Q*)); // ����������� ������ ��� ���������
	if (i > 0) {
		Temp = MUL_PQ_P(Second, First->k[i]); // �������� ������ ��������� ���������� �� ��� ������������ �������
		Temp = MUL_Pxk_P(Temp, i); // �������� ������������ �� ������� ����������� ������� ������� ����������
		Result = assignmentP(Temp); // ����������� � ���������� ������������
		for (i = First->len - 1; i >= 0; i--) {
			Temp = MUL_PQ_P(Second, First->k[i]); // �������� ������ ��������� ���������� �� ��� ������������ �������
			Temp = MUL_Pxk_P(Temp, i); // �������� ������������ �� ������� ����������� ������� ������� ����������
			Result = ADD_PP_P(Result, Temp); // ����������� � ���������� ������������
			freeP(Temp);
		}
	}
	else 
		Result = zeroP();
	return Result;
}