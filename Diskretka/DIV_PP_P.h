#pragma once
// P-9 ������� ����

P* DIV_PP_P(P* First, P* Second)
{
	P* Result = (P*)malloc(sizeof(P)); // ������� �� ������� �����������
	Result->k = (Q**)malloc(sizeof(Q*));
	P* Temp,* tmp; // ��������� ����������
	P* Part = assignmentP(First); // ������� �� �������
	short i; // ��� �������� �������������
	Q* Coef; // ����������� ��� ����������� ������� ����������
	Result->len = First->len - Second->len;
	Result->k = (Q**)realloc(Result->k, (Result->len + 1) * sizeof(Q));
	if (Result->len < 0) {
		freeP(Result);
		Result = zeroP();
	}	
	else
	for (i = First->len; i >= Second->len; i--)
	{
		if (i <= Part->len)
			Coef = DIV_QQ_Q(Part->k[i], Second->k[Second->len]); // ���������� ������������ ����� �������� � ����������
		else
			Coef = zeroQ();
		Result->k[i - Second->len] = assignmentQ(Coef); // ������� ��������� ����������� � ���� ������
		Temp = MUL_PQ_P(Second, Coef); // ��������� �������� �� "����������" �����������
		tmp = MUL_Pxk_P(Temp, (i - Second->len)); // ���������� � ����������� �������
		Part = SUB_PP_P(Part, tmp); // �������� �� ������� ����� ��������, ���������� �� ��������
		freeP(tmp);
		freeP(Temp);
		freeQ(Coef);
	}
	freeP(Part);
	return Result;
}