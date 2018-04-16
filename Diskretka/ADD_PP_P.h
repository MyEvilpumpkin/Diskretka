#pragma once
// P-1

P* ADD_PP_P(P* first, P* second)
{
	int i; // ��� �������� ����������� �� �������� 
	P* Result = (P*)malloc(sizeof(P)); // ����� ����������� 
	int greatPower = first->len > second->len ? first->len : second->len;
	// ����������, � ������ ���������� ������� ������ �, ���� ����, �������� �� ������� 
	Result->k = (Q**)malloc((greatPower + 1) * sizeof(Q*)); // ����������� ������ ��� ������������ ���������� 
	Result->len = greatPower; // ������� ����� ����� ������� �������� �� ����������� 
	for (i = greatPower; i >= 0; i--)
	{
		if (i > second->len) // ���� ����������� ������� ������� ���������� ������ ������� ������� 
			Result->k[i] = RED_Q_Q(first->k[i]); // ����������� ����� ����������� ������� ���������� (�.�. � ������� �� � ������ ���) 
		else
			Result->k[i] = ADD_QQ_Q(first->k[i], second->k[i]); // ����� ���������� �������� ������������� 
	}
	return Result;
}