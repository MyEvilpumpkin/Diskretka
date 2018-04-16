#pragma once
// P-4

P* MUL_Pxk_P(P* p, int k) {
	//Ğàñøèğåíèå ìàññèâà êîıôôèöèåíòîâ
	p->k = (Q**)realloc(p->k, (p->len + k) * sizeof(Q*));
	//Ñìåùåíèå íà k ïîçèöèé
	for (int i = p->len; i >= 0; i--) {
		p->k[i + k] = p->k[i];
	}
	p->len += k;
	//Çàïîëíåíèå íîâûõ ïîçèöèé íóëÿìè
	for (int i = k - 1; i >= 0; i--) {
		p->k[i] = (Q*)malloc(sizeof(Q));
		p->k[i]->num = (Z*)malloc(sizeof(Z));
		p->k[i]->num->number = (N*)malloc(sizeof(N));
		p->k[i]->num->number->len = 1;
		p->k[i]->num->number->n = (int*)malloc(4);
		p->k[i]->num->number->n[0] = 0;
		p->k[i]->denom = (N*)malloc(sizeof(N));
		p->k[i]->denom->len = 1;
		p->k[i]->denom->n = (int*)malloc(4);
		p->k[i]->denom->n[0] = 1;
	}
	return p;
}