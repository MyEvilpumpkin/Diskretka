#pragma once
// Q-5 Дяченко Виталий

Q* ADD_QQ_Q(Q* f1, Q* f2) {
	Q* ans = (Q*)malloc(sizeof(Q));
	//произведение находим, в знаменатель пишем
	ans->denom = MUL_NN_N(f1->denom, f2->denom);
	Z* q1 = (Z*)malloc(sizeof(Z));
	q1->number = MUL_NN_N(f1->num->number, f2->denom); // присваиваем значению знаменателя f1 произведение числителя f1 и знаменателя f2 
	q1->sign = f1->num->sign; // копируем знак числителя f1
	Z* q2 = (Z*)malloc(sizeof(Z));
	q2->number = MUL_NN_N(f2->num->number, f1->denom); // присваиваем значению знаменателя f2 произведение числителя f2 и знаменателя f1
	q2->sign = f2->num->sign; // копируем знак числителя f2
	ans->num = ADD_ZZ_Z(q1, q2);
	freeZ(q1);
	freeZ(q2);
	return RED_Q_Q(ans); // cокращаем дробь
}