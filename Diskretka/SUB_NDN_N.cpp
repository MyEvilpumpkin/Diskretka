// N-9
#include "golova.h"

N* SUB_NDN_N(N* a, N* b, int d /*�� ��� ��������*/)
{
	//���������� ��� ��������� �� �����
	N* afterMul = NULL;
	N* result = NULL;
	N* afterMul = (N*)malloc((MUL_NN_N(b, d)) * sizeof N); //��������
	N*	result = (N*)malloc((SUB_NN_N(a, afterMul)) * sizeof N);
	if (result != NULL)
	{
		//��������, ���� ��� ������ ���������� ���������
		return result;
	}
	//���� ������ ����������� ������ ������� - ������
	return 0;
}