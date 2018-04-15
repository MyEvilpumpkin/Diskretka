#pragma once
// Q-6

Q ADD_QQ_Q(Q f1, Q f2) {
	Q ans;
	//НОК находим, в знаменатель пишем
	ans.denom = &LCM_NN_N(*f1.denom, *f2.denom);
	//Тут типо q1 = НОК / знаменатель дроби f1
	Z q1 = { DIV_NN_N(ans.denom, f1.denom), false };
	Z q2 = { DIV_NN_N(ans.denom, f2.denom), false };
	//Числитель будет f1.num * q1 + f2.num * q2
	ans.num = ADD_ZZ_Z(&MUL_ZZ_Z(*f1.num, q1), &MUL_ZZ_Z(*f2.num, q2));
	//Сокращаем дробь
	return RED_Q_Q(ans);
}