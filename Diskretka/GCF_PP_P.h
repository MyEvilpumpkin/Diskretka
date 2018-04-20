#pragma once
// P-11 якушев »ль€

P* GCF_PP_P(P* a, P* b)
{
	P* ost;
	P* first = assignmentP(a); 
	P* second = assignmentP(b);
	P* temp;
	while ((second->len != 0 || NZER_N_B(second->k[0]->num->number)) && (first->len != 0 || NZER_N_B(first->k[0]->num->number))) // цикл пока оба многочлена - не нулевые
	{
		if (first->len > second->len) { // если степень первого многочлена больше степени второго
			temp = MOD_PP_P(first, second); // присваиваем ему остаток от делени€ многочленов
			freeP(first);
			first = assignmentP(temp); // наоборот
			freeP(temp);
		}
		else {
			temp = MOD_PP_P(second, first);
			freeP(second);
			second = assignmentP(temp); 
			freeP(temp);
		}
	}
	if (first->len > second->len) // если степень первого многочлена оказалась больше второго
		ost = assignmentP(first); // присваиваем результату (остатку) значение первого многочлена
	else
		ost = assignmentP(second); //наоборот
	freeP(first);
	freeP(second);
	return ost;
}