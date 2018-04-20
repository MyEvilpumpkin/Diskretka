#pragma once
// P-9 Смирнов Иван

P* DIV_PP_P(P* First, P* Second)
{
	P* Result = (P*)malloc(sizeof(P)); // Частное от деления многочленов
	Result->k = (Q**)malloc(sizeof(Q*));
	P* Temp,* tmp; // Временная переменная
	P* Part = assignmentP(First); // Остаток от деления
	short i; // Для перебора коэффициентов
	Q* Coef; // Коэффициент при исследуемой степени результата
	Result->len = First->len - Second->len;
	Result->k = (Q**)realloc(Result->k, (Result->len + 1) * sizeof(Q));
	if (Result->len < 0) {
		freeP(Result);
		Result = zeroP();
	}	
	else
	for (i = First->len; i >= Second->len; i--)
	{
		if (i <= Part->len)
			Coef = DIV_QQ_Q(Part->k[i], Second->k[Second->len]); // Вычисления коэффициента перед степенью в результате
		else
			Coef = zeroQ();
		Result->k[i - Second->len] = assignmentQ(Coef); // Заносим найденный коэффициент в поле ответа
		Temp = MUL_PQ_P(Second, Coef); // Умножение делителя на "подходящий" коэффициент
		tmp = MUL_Pxk_P(Temp, (i - Second->len)); // Возведение в необходимую степень
		Part = SUB_PP_P(Part, tmp); // Вычитаем из остатка часть частного, умноженную на делитель
		freeP(tmp);
		freeP(Temp);
		freeQ(Coef);
	}
	freeP(Part);
	return Result;
}