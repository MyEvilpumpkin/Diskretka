#pragma once
// P-10

P* MOD_PP_P(P* a, P* b)//Принимает на вход a, b, result и записывает в result остаток от деления a на b 
{
	return SUB_PP_P(a, MUL_PP_P(DIV_PP_P(a, b), b));
}