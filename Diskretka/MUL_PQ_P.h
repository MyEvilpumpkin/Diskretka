#pragma once
// P-3

P* MUL_PQ_P(P* Polyn, Q* Numb)
{
	short i; // ��� ��������� ������������� ����������
	P* Result = initP(); // ��������� ���������
	Result->len = Polyn->len; // ����� ���������� ����� ����� ����������
	Result->k = (Q**)malloc((Polyn->len + 1) * sizeof(Q*)); // ������������ ������ ��� ������������
	for (i = Polyn->len; i >= 0; i--)
		Result->k[i] = MUL_QQ_Q(Polyn->k[i], Numb);
	return Result;
}