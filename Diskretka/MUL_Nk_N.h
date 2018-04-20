#pragma once
// N-7 ������ �����

N* MUL_Nk_N(N* a, int b)
{
	N* c = zeroN();
	int len = a->len + b; // �������������� ������ ������ ����� ��������� ����� � �������� ������� k
	c->n = (int*)realloc(c->n, len * sizeof(int)); // �������� ������ ��� ������ �����
	for (int i = 0; i < len; i++) // ���� �� ����� �����
	{
		if (i < b) // ���� ������� ������ ������ k
			c->n[i] = 0; // "���������" ���� ����� �� 10
		else
			c->n[i] = a->n[i - b]; // ����������� �� ����� ������� (�� k ������) ����� ��������� �����
	}
	c->len = len; // ����������� ����� ���������� ����� len
	c = deNULL(c);
	return c;
}