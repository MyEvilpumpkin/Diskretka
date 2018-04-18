#pragma once
// Q-5

Q* ADD_QQ_Q(Q* f1, Q* f2) {
	Q* ans = initQ();
	//произведение находим, в знаменатель пишем
	ans->denom = MUL_NN_N(f1->denom, f2->denom);
	//Тут типо q1 =  / знаменатель дроби f1
	Z* q1 = initZ();
	q1->number = MUL_NN_N(f1->num->number, f2->denom); 
	q1->sign = f1->num->sign;
	Z* q2 = initZ();
	q2->number = MUL_NN_N(f2->num->number, f1->denom);
	q2->sign = f2->num->sign;
	//Числитель будет f1->num * q1 + f2->num * q2
	ans->num = ADD_ZZ_Z(q1, q2);
	//Сокращаем дробь
	return RED_Q_Q(ans);
}