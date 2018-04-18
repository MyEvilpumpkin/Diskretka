#pragma once
// Q-4

Z* TRANS_Q_Z(Q* First)
{
	Z* Rez = initZ(); // Результат перевода
	Rez->sign = First->num->sign;
	if (First->num->number->len == 1 && First->num->number->n[0] == 0)
		Rez->sign = true;
	Rez->number = assignmentN(First->num->number);
	return Rez;
}