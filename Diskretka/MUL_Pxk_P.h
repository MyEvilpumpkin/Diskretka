#pragma once
// P-4 ������� �������

P* MUL_Pxk_P(P* Polyn, int k) {
	P* Result = (P*)malloc(sizeof(P));
	Result->k = (Q**)malloc(sizeof(Q*));
	int i; // ��� �������� �������������
	Result->k = (Q**)realloc(Result->k, (Polyn->len + k + 1) * sizeof(Q*)); // ��������� ������
	Result->len = Polyn->len + k; // ����������� ������� ����������-���������� ����� ������� ��������� ���������� � ������� k
	for (i = Result->len; i >= k; i--) // ���� �� �������� ������������ ���������� �� ������� k
		Result->k[i] = assignmentQ(Polyn->k[i - k]); // ����������� �������� ������������ ����������-���������� ����������� ��������� ���������� "���������" �� k
	for (i = k - 1; i >= 0; i--) // ���� �� ������� k-1 �� �������� ������������ ����������
		Result->k[i] = zeroQ(); // ������� ��� ��������� �� ���� �������
	return Result;
}