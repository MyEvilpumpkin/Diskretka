#pragma once
// P-5

Q* LED_P_Q(P* p) {
	for (int i = p->len; i >= 0; i--)
		if (!(p->k[i]->num->number->len == 1 && p->k[i]->num->number->n[0] == 0))
			return RED_Q_Q(p->k[i]);
	return RED_Q_Q(p->k[0]);
}