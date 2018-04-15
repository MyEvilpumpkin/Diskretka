#pragma once
// Q-3

Q* TRANS_Z_Q(Z* First)
{
	Q* Rez = initQ(); // Результат перевода
	Rez->num->number = assignmentN(First->number);
	Rez->num->sign = First->sign;
	Rez->denom->len = 1;
	Rez->denom->n = (int*)malloc(sizeof(int));
	Rez->denom->n[0] = 1;
	return Rez;
}