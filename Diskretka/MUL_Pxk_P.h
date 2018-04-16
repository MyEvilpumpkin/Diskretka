#pragma once
// P-4

P* MUL_Pxk_P(P* Polyn, int k) {
	P* Result = initP(); // ��������� ���������
	int i; // ��� �������� �������������
	Result->k = (Q**)malloc((Polyn->len + k) * sizeof(Q*)); // ��������� ������
	Result->len = Polyn->len + k;
	for (i = Result->len; i >= k; i--)
		Result->k[i] = assignmentQ(Polyn->k[i - k]);
	for (i = k - 1; i >= 0; i--)
	{
		Result->k[i] = initQ();
		Result->k[i]->num->number = getZero();
		Result->k[i]->denom = getZero();
		Result->k[i]->denom->n[0] = 1;
	}
	return Result;
}