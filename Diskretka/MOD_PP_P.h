#pragma once
// P-10

P* MOD_PP_P(P * a, P * b)//��������� �� ���� a, b, result � ���������� � result ������� �� ������� a �� b 
{
	P* result = DIV_PP_P(a, b);
	result = MUL_PP_P(result, b);
	result = SUB_PP_P(a, result);
	return result;
}