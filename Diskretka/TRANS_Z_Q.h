#pragma once
// Q-3

Q* TRANS_Z_Q(Z* First)
{
	Q* Rez = initQ(); // Результат перевода
	Rez->num->number = assignmentN(First->number);
	Rez->num->sign = First->sign;
	if (First->number->len == 1 && First->number->n[0] == 0)
		Rez->num->sign = true;
	Rez->denom->len = 1;
	Rez->denom->n = (int*)malloc(sizeof(int));
	Rez->denom->n[0] = 1;
	return Rez;
}