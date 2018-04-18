#pragma once
// P-2

P* SUB_PP_P(P* First, P* Second)
{
	P* Result = initP(); // Разность многочленов 
	P* SecondCopy = assignmentP(Second);
	int greatPower = First->len > Second->len ? First->len : Second->len;
	Result->k = (Q**)malloc((greatPower + 1) * sizeof(Q*)); // Освобождаем память под результат 
	Result->len = greatPower; // Степень разности равна степени бОльшего из многочленов 
	for (int i = 0; i <= Second->len; ++i) // Меняем знак коэффициентов 2го полинома (его копии) 
		SecondCopy->k[i]->num->sign = !Second->k[i]->num->sign;
	return ADD_PP_P(First, SecondCopy);
}