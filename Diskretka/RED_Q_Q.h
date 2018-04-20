#pragma once
// Q-1 Мищенко Алина

Q* RED_Q_Q(Q* fraction) {
	N* d = GCF_NN_N(fraction->num->number, fraction->denom); // присваиваем d значение НОДа (модуля числителя дроби) и знаменателя дроби 
	while (d->len != 1 or d->n[0] != 1) { // до тех пор пока d не станет равным 1  
		fraction->num = DIV_ZZ_Z(fraction->num, d); // сокращаем числитель на d
		fraction->denom = DIV_NN_N(fraction->denom, d); // сокращаем знаменатель на d
		freeN(d);
		d = GCF_NN_N(fraction->num->number, fraction->denom); // присваиваем d значение НОДа (модуля числителя дроби) и знаменателя дроби  
	}
	freeN(d);
	return fraction;
}