#pragma once
// P-10 Якушев Илья

P* MOD_PP_P(P* a, P* b) //Принимает на вход a, b, result и записывает в result остаток от деления a на b 
{
	P* result = DIV_PP_P(a, b); // результат деления большего многочлена на меньший без остатка
	P* temp = MUL_PP_P(result, b); // произведение результата от деления и меньшего многочлена
	freeP(result);
	result = SUB_PP_P(a, temp); // разность большего многочлена и произведения
	freeP(temp);
	return result;
}