#pragma once
// P-2

P* SUB_PP_P(P* First, P* Second)
{
	short i, k; // ��� �������� ������������� ���������� 
	P* Result = (P*)malloc(sizeof(P)); // �������� ����������� 
	P* SecondCopy = Second;
	int greatPower = First->len > Second->len ? First->len : Second->len;
	// ����������� �������� �� ����������� (������������ ��� �������������) 
	Result->k = (Q**)malloc((greatPower + 1) * sizeof(Q*)); // ����������� ������ ��� ��������� 
	Result->len = First->len; // ������� �������� ����� ������� �������� �� ����������� 
	for (int i = 0; i <= Second->len; ++i) // ������ ���� ������������� 2�� �������� (��� �����) 
		Second->k[i]->num->sign ^= 1;
	return ADD_PP_P(First, SecondCopy);
}