#pragma once
// P-2

P* SUB_PP_P(P* First, P* Second)
{
	short i, k; // Для перебора коэффициентов многочлена 
	P* Result = (P*)malloc(sizeof(P)); // Разность многочленов 
	P* SecondCopy = Second;
	int greatPower = First->len > Second->len ? First->len : Second->len;
	// Определение бОльшего из многочленов (перестановка при необходимости) 
	Result->k = (Q**)malloc((greatPower + 1) * sizeof(Q*)); // Освобождаем память под результат 
	Result->len = First->len; // Степень разности равна степени бОльшего из многочленов 
	for (int i = 0; i <= Second->len; ++i) // Меняем знак коэффициентов 2го полинома (его копии) 
		Second->k[i]->num->sign ^= 1;
	return ADD_PP_P(First, SecondCopy);
}