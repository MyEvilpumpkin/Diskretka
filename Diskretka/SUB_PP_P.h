#pragma once
// P-2

P* SUB_PP_P(P* First, P* Second)
{
	P* SecondCopy = assignmentP(Second);
	int greatPower = First->len > Second->len ? First->len : Second->len;
	for (int i = 0; i <= Second->len; ++i) // Меняем знак коэффициентов 2го полинома (его копии) 
		SecondCopy->k[i]->num->sign = !Second->k[i]->num->sign;
	SecondCopy = ADD_PP_P(First, SecondCopy);
	return SecondCopy;
}