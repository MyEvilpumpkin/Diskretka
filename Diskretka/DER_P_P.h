#pragma once
// P-12 Львов Денис

P* DER_P_P(P* p) {
	//Выделение память под многочлен
	P* res = (P*)malloc(sizeof(P));
	res->k = (Q**)malloc(p->len * sizeof(P));
	res->len = p->len - 1;
	Z* temp;
	Q* tmp;
	//Расчет коэффициентов
	for (int i = p->len - 1; i >= 0; i--) { // цикл до младшего коэффициента многочлена
		temp = TRANS_N_Z(intToN(i + 1));
		tmp = TRANS_Z_Q(temp);
		res->k[i] = MUL_QQ_Q(p->k[i + 1], tmp); //присваиваем текущему коэффициенту значение 
		freeZ(temp); //(произведения следующего коэффициента и (преобразованной в дробное число степени следующего коэффициента))
		freeQ(tmp);
	}
	return res;
}