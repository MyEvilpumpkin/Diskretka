#pragma once
// Q-3 ������� �����

Q* TRANS_Z_Q(Z* First)
{
	Q* Rez = (Q*)malloc(sizeof(Q));
	Rez->denom = zeroN();
	Rez->denom->n[0] = 1;
	Rez->num = (Z*)malloc(sizeof(Z));
	Rez->num->number = assignmentN(First->number); // ������������ ��������� ���������� �������� ������ �����
	Rez->num->sign = First->sign; // �������� ���� �����
	if (First->number->len == 1 && First->number->n[0] == 0) // ���� ����� ����� ����
		Rez->num->sign = true; // �� ����� ������������
	return Rez; // ��������� ��������
}