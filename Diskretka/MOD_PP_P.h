#pragma once
// P-10

P* MOD_PP_P(P* a, P* b)//��������� �� ���� a, b, result � ���������� � result ������� �� ������� a �� b 
{
	return SUB_PP_P(a, MUL_PP_P(DIV_PP_P(a, b), b));
}