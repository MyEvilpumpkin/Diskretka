#pragma once
// Q-4

Z* TRANS_Q_Z(Q* First)
{
	Z* Rez; // ��������� ��������
	Rez = initZ();
	Rez->sign = First->num->sign;
	Rez->number = assignmentN(First->num->number);
	return Rez;
}