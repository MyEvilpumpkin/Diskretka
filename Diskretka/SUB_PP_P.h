#pragma once
// P-2 ����� ���������

P* SUB_PP_P(P* First, P* Second)
{
	P* SecondCopy = assignmentP(Second); // �������� �������� ������� ����������
	for (int i = 0; i <= Second->len; ++i) 
		SecondCopy->k[i]->num->sign = !Second->k[i]->num->sign; // ������ ���� ������������� 2�� �������� (��� �����) 
	P* Result = ADD_PP_P(First, SecondCopy); // ��������� ������ ��������� � (-1)*������ ���������
	freeP(SecondCopy);
	return Result;
}