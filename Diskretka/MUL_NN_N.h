#pragma once
// N-8

N MUL_NN_N(N a, N b)
{
	N result;
	result.len = 1;
	result.n = (int*)malloc(sizeof(int));
	result.n[0] = 0;
	for (int i = 0; i < b.len; i++)							//� ����������, ���������� ������� 0, � ������ ���� ����� ������������ i-�� ����� ������� �����������,
		result = ADD_NN_N(result, MUL_Nk_N(MUL_ND_N(a, b.n[i]), i));  //���������� �� ������ ����������� � �� 10^i
	return result;
}