#pragma once
// P-9

P* DIV_PP_P(P* First, P* Second)
{
	P* Result = initP(); // Частное от деления многочленов
	P* Temp; // Временная переменная
	P* Part = assignmentP(First); // Остаток от деления
	short i; // Для перебора коэффициентов
	Q* Coef; // Коэффициент при исследуемой степени результата
	Result->len = First->len - Second->len;
	if (Result->len < 0)
		Result = zeroP();
	else
	for (i = First->len; i >= Second->len; i--)
	{
		if (i <= Part->len)
			Coef = DIV_QQ_Q(Part->k[i], Second->k[Second->len]); // Вычисления коэффициента перед степенью в результате
		else
			Coef = zeroQ();
		Result->k[i - Second->len] = Coef; // Заносим найденный коэффициент в поле ответа
		Temp = MUL_PQ_P(Second, Coef); // Умножение делителя на "подходящий" коэффициент
		Temp = MUL_Pxk_P(Temp, (i - Second->len)); // Возведение в необходимую степень
		Part = SUB_PP_P(Part, Temp); // Вычитаем из остатка часть частного, умноженную на делитель
	}
	return Result;
}