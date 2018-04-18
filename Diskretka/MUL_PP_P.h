#pragma once
// P-8

P* MUL_PP_P(P* First, P* Second)
{
	short i = First->len; // Для перебора коэффициентов многочлена
	P* Result = initP(); // Результат умножения
	P* Temp = initP(); // Результат умножения первого многочлена на коэффициент второго
	Result->len = (First->len) + (Second->len); // Степень результата равна сумме степеней множителей
	Result->k = (Q**)malloc((Result->len + 1) * sizeof(Q*)); // Освобождаем память под результат
	if (i > 0) {
		Temp = MUL_PQ_P(Second, First->k[i]); // Умножаем второй многочлен поочередно на все коэффициенты первого
		Temp = MUL_Pxk_P(Temp, i); // Умножаем произведение на текущую исследуемую степень первого многочлена
		Result = assignmentP(Temp); // Прибавление к результату произведения
		for (i = First->len - 1; i >= 0; i--) {
			Temp = MUL_PQ_P(Second, First->k[i]); // Умножаем второй многочлен поочередно на все коэффициенты первого
			Temp = MUL_Pxk_P(Temp, i); // Умножаем произведение на текущую исследуемую степень первого многочлена
			Result = ADD_PP_P(Result, Temp); // Прибавление к результату произведения
			freeP(Temp);
		}
	}
	else 
		Result = zeroP();
	return Result;
}