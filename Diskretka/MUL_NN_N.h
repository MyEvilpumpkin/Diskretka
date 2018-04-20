#pragma once
// N-8

N* MUL_NN_N(N* a, N* b)
{
	N* result = zeroN(); //� ����������, ���������� ������� 0, � ������ ���� ����� ������������ i-�� ����� ������� �����������
	N* temp, *tmp;
	for (int i = 0; i < b->len; i++) {
		tmp = MUL_ND_N(a, b->n[i]);
		temp = MUL_Nk_N(tmp, i);
		freeN(tmp);
		tmp = ADD_NN_N(result, temp);
		freeN(result);
		result = assignmentN(tmp);
		freeN(tmp);
		freeN(temp);
	}
	return result;
}