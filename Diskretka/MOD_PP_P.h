#pragma once
// P-10
/*
P* MOD_PP_P(P * a, P * b)//��������� �� ���� a, b, result � ���������� � result ������� �� ������� a �� b
{
	P* quotient;//������� �� ������� a �� b
	P* result;
	quotient = DIV_PP_P(a, b);//��������� ��� �������
	P* temp;
	temp = MUL_PP_P(quotient, b, );//��������� ������� �� ��������
	result = SUB_PP_P(a, temp);//�������� �� �������� ������������ �������� �� ������� = ��������� �������
	return result;
}
*/