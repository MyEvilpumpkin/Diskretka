#pragma once
// P-9

P* DIV_PP_P(P* First, P* Second)
{
	P* Result = initP(); // ������� �� ������� �����������
	P* Temp; // ��������� ����������
	P* Part = First; // ������� �� �������
	short i; // ��� �������� �������������
	Q* Coef; // ����������� ��� ����������� ������� ����������
	for (i = First->len; i >= Second->len; i--)
	{
		Coef = DIV_QQ_Q(First->k[i], Second->k[Second->len]); // ���������� ������������ ����� �������� � ����������
		Result->k[i - Second->len] = Coef; // ������� ��������� ����������� � ���� ������
		Temp = MUL_PQ_P(Second, Coef); // ��������� �������� �� "����������" �����������
		Temp = MUL_Pxk_P(Temp, (i - Second->len)); // ���������� � ����������� �������
		Part = SUB_PP_P(Part, Temp); // �������� �� ������� ����� ��������, ���������� �� ��������
	}
	return Result;
}