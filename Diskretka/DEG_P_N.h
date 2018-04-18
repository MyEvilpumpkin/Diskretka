#pragma once
// P-6

N* DEG_P_N(P* p) {
	int power = 0;
	bool flag = true;
	for (int i = p->len; i >= 0 && flag; i--)
		if (!(p->k[i]->num->number->len == 1 && p->k[i]->num->number->n[0] == 0)) {
			power = i;
			flag = false;
		}
	return intToN(power);
}