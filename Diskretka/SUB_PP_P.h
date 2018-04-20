#pragma once
// P-2 Ханов Александр

P* SUB_PP_P(P* First, P* Second)
{
	P* SecondCopy = assignmentP(Second); // копируем значение второго многочлена
	for (int i = 0; i <= Second->len; ++i) 
		SecondCopy->k[i]->num->sign = !Second->k[i]->num->sign; // меняем знак коэффициентов 2го полинома (его копии) 
	P* Result = ADD_PP_P(First, SecondCopy); // суммируем первый многочлен и (-1)*второй многочлен
	freeP(SecondCopy);
	return Result;
}