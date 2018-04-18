#pragma once
// P-2

P* SUB_PP_P(P* First, P* Second)
{
	P* Result = initP(); // �������� ����������� 
	P* SecondCopy = assignmentP(Second);
	int greatPower = First->len > Second->len ? First->len : Second->len;
	Result->k = (Q**)malloc((greatPower + 1) * sizeof(Q*)); // ����������� ������ ��� ��������� 
	Result->len = greatPower; // ������� �������� ����� ������� �������� �� ����������� 
	for (int i = 0; i <= Second->len; ++i) // ������ ���� ������������� 2�� �������� (��� �����) 
		SecondCopy->k[i]->num->sign = !Second->k[i]->num->sign;
	return ADD_PP_P(First, SecondCopy);
}