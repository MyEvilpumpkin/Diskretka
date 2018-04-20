#pragma once
// P-8 Смирнов Иван

P* MUL_PP_P(P* First, P* Second)
{
	short i = First->len; // Для перебора коэффициентов многочлена
	P* Result; // Результат умножения
	P* Temp,* tmp; // Результат умножения первого многочлена на коэффициент второго
	if (i > 0) {
		Temp = MUL_PQ_P(Second, First->k[i]); // Умножаем второй многочлен поочередно на все коэффициенты первого
		Result = MUL_Pxk_P(Temp, i); // Умножаем произведение на текущую исследуемую степень первого многочлена
		freeP(Temp);
		for (i = First->len - 1; i >= 0; i--) {
			Temp = MUL_PQ_P(Second, First->k[i]); // Умножаем второй многочлен поочередно на все коэффициенты первого
			tmp = MUL_Pxk_P(Temp, i); // Умножаем произведение на текущую исследуемую степень первого многочлена
			freeP(Temp);
			Temp = ADD_PP_P(Result, tmp); // Прибавление к результату произведения
			freeP(Result);
			Result = assignmentP(Temp);
			freeP(Temp);
			freeP(tmp);
		}
	}
	else
		Result = zeroP();
	return Result;
}