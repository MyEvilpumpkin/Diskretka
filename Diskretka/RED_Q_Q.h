#pragma once
// Q-1 Мищенко Алина

Q* RED_Q_Q(Q* fraction) {
	Q* temp;
	N* d = GCF_NN_N(fraction->num->number, fraction->denom); // присваиваем d значение НОДа (модуля числителя дроби) и знаменателя дроби 
	while (d->len != 1 or d->n[0] != 1) { // до тех пор пока d не станет равным 1  
		temp = (Q*)malloc(sizeof(Q));
		temp->num = DIV_ZZ_Z(fraction->num, d); // сокращаем числитель на d
		temp->denom = DIV_NN_N(fraction->denom, d); // сокращаем знаменатель на d
		freeZ(fraction->num);
		fraction->num = (Z*)malloc(sizeof(Z));
		fraction->num->number = assignmentN(temp->num->number);
		fraction->num->sign = temp->num->sign;
		freeN(fraction->denom);
		fraction->denom = assignmentN(temp->denom);
		freeQ(temp);
		freeN(d);
		d = GCF_NN_N(fraction->num->number, fraction->denom); // присваиваем d значение НОДа (модуля числителя дроби) и знаменателя дроби  
	}
	freeN(d);
	return fraction;
}
