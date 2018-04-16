#pragma once
// P-9

P* DIV_PP_P(P* First, P* Second)
{
	P* Result = initP(); // Частное от деления многочленов
	P* Temp; // Временная переменная
	P* Part = First; // Остаток от деления
	short i; // Для перебора коэффициентов
	Q* Coef; // Коэффициент при исследуемой степени результата
	for (i = First->len; i >= Second->len; i--)
	{
		Coef = DIV_QQ_Q(First->k[i], Second->k[Second->len]); // Вычисления коэффициента перед степенью в результате
		Result->k[i - Second->len] = Coef; // Заносим найденный коэффициент в поле ответа
		Temp = MUL_PQ_P(Second, Coef); // Умножение делителя на "подходящий" коэффициент
		Temp = MUL_Pxk_P(Temp, (i - Second->len)); // Возведение в необходимую степень
		Part = SUB_PP_P(Part, Temp); // Вычитаем из остатка часть частного, умноженную на делитель
	}
	return Result;
}