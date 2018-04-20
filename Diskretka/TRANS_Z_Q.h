#pragma once
// Q-3 Соцкова Ирина

Q* TRANS_Z_Q(Z* First)
{
	Q* Rez = (Q*)malloc(sizeof(Q));
	Rez->denom = zeroN();
	Rez->denom->n[0] = 1;
	Rez->num = (Z*)malloc(sizeof(Z));
	Rez->num->number = assignmentN(First->number); // присваивание числителю результата значения целого числа
	Rez->num->sign = First->sign; // копируем знак числа
	if (First->number->len == 1 && First->number->n[0] == 0) // если число равно нулю
		Rez->num->sign = true; // то число положительно
	return Rez; // результат перевода
}