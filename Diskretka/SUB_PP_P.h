#pragma once
// P-2

P* SUB_PP_P(P* First, P* Second)
{
	P* SecondCopy = assignmentP(Second);
	for (int i = 0; i <= Second->len; ++i) // ������ ���� ������������� 2�� �������� (��� �����) 
		SecondCopy->k[i]->num->sign = !Second->k[i]->num->sign;
	P* Result = ADD_PP_P(First, SecondCopy);
	freeP(SecondCopy);
	return Result;
}