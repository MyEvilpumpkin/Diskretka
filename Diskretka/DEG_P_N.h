#pragma once
// P-6

int DEG_P_N(P* p) {
	int power = 0;
	for (int i = p->len; i >= 0; i--)
		if (!(p->k[i]->num->number->len == 1 && p->k[i]->num->number->n[0] == 0)) {
			power = i;
			break;
		}
	return power;
}