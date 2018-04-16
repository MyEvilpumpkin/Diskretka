#pragma once
// P-8

P* MUL_PP_P(P* First, P* Second)
{
	short i; // ��� �������� ������������� ����������
	P* Result = initP(); // ��������� ���������
	P* Temp = initP(); // ��������� ��������� ������� ���������� �� ����������� �������
	Result->len = (First->len) + (Second->len); // ������� ���������� ����� ����� �������� ����������
	Result->k = (Q**)malloc((Result->len) * sizeof(Q*)); // ����������� ������ ��� ���������
	for (i = First->len; i <= 0; i--) {
		Temp = MUL_PQ_P(Second, First->k[i]); // �������� ������ ���������� ���������� �� ��� ������������ �������
		Temp = MUL_Pxk_P(Temp, i); // �������� ������������ �� ������� ����������� ������� ������� ����������
		Result = ADD_PP_P(Result, Temp); // ����������� � ���������� ������������
	}
	return Result;
}