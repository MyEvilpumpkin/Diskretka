#pragma once
// P-1
#include "DEG_P_N.h"

P* ADD_PP_P(P* a, P* b)
{
	P* First, *Second;
	// ����������, � ������ ���������� ������� ������ �, ���� ����, �������� �� �������
	if (a->len > b->len) { 
		First = assignmentP(a);
		Second = assignmentP(b);
	}
	else {
		First = assignmentP(b);
		Second = assignmentP(a);
	}
	P* Result = initP(); // ����� �����������
	Result->k = (Q**)realloc(Result->k, (First->len+1)* sizeof(Q*)); // ����������� ������ ��� ������������ ����������
	Result->len = First->len; // ������� ����� ����� ������� �������� �� �����������
		for (int i = First->len; i >= 0; i--)
		{
			if (i > Second->len) // ���� ����������� ������� ������� ���������� ������ ������� �������
				Result->k[i] = assignmentQ(First->k[i]); // ����������� ����� ����������� ������� ���������� (�.�. � ������� �� � ������ ���)
			else
				Result->k[i] = ADD_QQ_Q(First->k[i], Second->k[i]); // ����� ���������� �������� �������������
		}
		Result->len = DEG_P_N(Result);
	return Result;
}