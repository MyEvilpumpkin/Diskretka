#pragma once
// Z-4 ������� �����

Z *TRANS_N_Z(N *a)
{
	Z *z = (Z*)malloc(sizeof(Z));
	z->number = assignmentN(a); // ����������� ������ ���������� ����������� ����� 
	z->sign = true;
	return z;
}