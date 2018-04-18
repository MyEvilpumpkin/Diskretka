#pragma once
// P-9

P* DIV_PP_P(P* First, P* Second)
{
	P* Result = initP(); // ������� �� ������� �����������
	P* Temp; // ��������� ����������
	P* Part = assignmentP(First); // ������� �� �������
	short i; // ��� �������� �������������
	Q* Coef; // ����������� ��� ����������� ������� ����������
	Result->len = First->len - Second->len;
	if (Result->len < 0)
		Result = zeroP();
	else
	for (i = First->len; i >= Second->len; i--)
	{
		if (i <= Part->len)
			Coef = DIV_QQ_Q(Part->k[i], Second->k[Second->len]); // ���������� ������������ ����� �������� � ����������
		else
			Coef = zeroQ();
		Result->k[i - Second->len] = Coef; // ������� ��������� ����������� � ���� ������
		Temp = MUL_PQ_P(Second, Coef); // ��������� �������� �� "����������" �����������
		Temp = MUL_Pxk_P(Temp, (i - Second->len)); // ���������� � ����������� �������
		Part = SUB_PP_P(Part, Temp); // �������� �� ������� ����� ��������, ���������� �� ��������
	}
	return Result;
}