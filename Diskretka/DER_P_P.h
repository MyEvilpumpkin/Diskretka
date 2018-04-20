#pragma once
// P-12

P* DER_P_P(P* p) {
	//Выделение память под многочлен
	P* res = initP();
	res->k = (Q**)malloc(p->len * sizeof(P));
	res->len = p->len - 1;
	Z* temp;
	Q* tmp;
	//Расчет коэффициентов
	for (int i = p->len - 1; i >= 0; i--) {
		temp = TRANS_N_Z(intToN(i + 1));
		tmp = TRANS_Z_Q(temp);
		res->k[i] = MUL_QQ_Q(p->k[i + 1], tmp);
		freeZ(temp);
		freeQ(tmp);
	}
	return res;
}