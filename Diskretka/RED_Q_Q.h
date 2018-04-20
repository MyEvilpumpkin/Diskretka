#pragma once
// Q-1

Q* RED_Q_Q(Q* fraction) {
	N* d = GCF_NN_N(fraction->num->number, fraction->denom);
	while (d->len != 1 or d->n[0] != 1) {
		fraction->num = DIV_ZZ_Z(fraction->num, d);
		fraction->denom = DIV_NN_N(fraction->denom, d);
		freeN(d);
		d = GCF_NN_N(fraction->num->number, fraction->denom);
	}
	freeN(d);
	return fraction;
}