#pragma once
// Z-7 �������� �����

Z *SUB_ZZ_Z(Z *num1, Z *num2)
{
	Z *n2 = (Z*)malloc(sizeof(Z));
	n2->number = assignmentN(num2->number); // ����������� ����������� �������� �������� ����� 
	n2->sign = !num2->sign; // �������� ������ ����� �� (-1)
	Z* result = ADD_ZZ_Z(num1, n2); // ��������� �����
	freeZ(n2);
	return result; // ���������� �� �����
}
