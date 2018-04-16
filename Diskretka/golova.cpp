#include "golova.h"

N* deNULL(N* n) {
	if (n->len != 0) {
		int i = 1,
			l = n->len;
		for (int j = 0; j < l; j++)
			i = n->n[j] == 0 ? i : j + 1;
		n->n = (int*)realloc(n->n, i * sizeof(int));
		n->len = i;
	}
	return n;
}

N* assignmentN(N* n) {
	N* a = (N*)malloc(sizeof(N));
	int l = n->len;
	a->n = (int*)malloc(l * sizeof(int));
	for (int i = 0; i < l; i++)
		a->n[i] = n->n[i];
	a->len = l;
	return a;
}

N* initN() {
	N* n = (N*)malloc(sizeof(N));
	n->len = -1;
	return n;
}

N* getZero() {
	N* n = initN();
	n->len = 1;
	n->n = (int*)malloc(sizeof(int));
	n->n[0] = 0;
	return n;
}

N* inputN() {
	N* number = input();
	number = deNULL(number);
	return number;
}

N* input() {
	char *symbol = (char*)malloc(sizeof(char));
	int *k = nullptr, len = 0;
	N *number = nullptr;
	do {
		*symbol = getchar();
		if ('0' <= *symbol && *symbol <= '9') {
			k = (int*)realloc(k, (len + 1) * sizeof(int));
			k[len] = atoi(symbol);
			len++;
		}
	} while ('0' <= *symbol && *symbol <= '9');
	number = (N*)malloc(sizeof(N));
	number->n = (int*)malloc(len * sizeof(int));
	number->len = len;
	for (int i = 0; i < len; i++)
		number->n[i] = k[len - i - 1];
	free(k);
	free(symbol);
	return number;
}

void printN(N* num) {
	for (int i = num->len - 1; i >= 0; i--)
		printf("%d", num->n[i]);
}

N* freeN(N* n) {
	free(n->n);
	free(n);
	return nullptr;
}

Z* initZ() {
	Z* z = (Z*)malloc(sizeof(Z));
	z->number = initN();
	return z;
}

Z* inputZ() {
	Z* z = nullptr;
	z = (Z*)malloc(sizeof(Z));
	char *s = (char*)malloc(sizeof(char));
	*s = getchar();
	if (*s == '-')
		z->sign = false;
	else
		z->sign = true;
	z->number = input();
	if (*s != '-' && (*s != '0' || z->number->len == 0)) {
		z->number->n = (int*)realloc(z->number->n, (z->number->len + 1) * sizeof(int));
		z->number->len++;
		z->number->n[z->number->len - 1] = atoi(s);
	}
	free(s);
	z->number = deNULL(z->number);
	return z;
}

void printZ(Z* z) {
	if (!z->sign)
		printf("-");
	printN(z->number);
}

Z* freeZ(Z* z) {
	freeN(z->number);
	free(z);
	return nullptr;
}

Q* assignmentQ(Q* q) {
	Q* a = initQ();
	a->num->sign = q->num->sign;
	a->num->number = assignmentN(q->num->number);
	a->denom = assignmentN(q->denom);
	return a;
}

Q* initQ() {
	Q* q = (Q*)malloc(sizeof(Q));
	q->num = initZ();
	q->denom = initN();
	return q;
}

Q* inputQ() {
	Q* q = (Q*)malloc(sizeof(Q));
	printf("Enter numerator: ");
	q->num = inputZ();
	printf("Enter denominator: ");
	q->denom = inputN();
	return q;
}

void printQ(Q* q) {
	printZ(q->num);
	printf(" / ");
	printN(q->denom);
}

Q* freeQ(Q* q) {
	freeN(q->denom);
	freeZ(q->num);
	free(q);
	return nullptr;
}

P* assignmentP(P* p) {
	P* a = (P*)malloc(sizeof(P));
	a->len = p->len;
	a->k = (Q**)malloc((a->len + 1) * sizeof(Q*));
	for (int i = 0; i <= a->len; i++) {
		a->k[i] = initQ();
		a->k[i]->num->sign = p->k[i]->num->sign;
		a->k[i]->num->number = assignmentN(p->k[i]->num->number);
		a->k[i]->denom = assignmentN(p->k[i]->denom);
	}
	return a;
}

P* initP() {
	P* p = (P*)malloc(sizeof(P));
	p->k = (Q**)malloc(sizeof(Q*));
	p->k[0] = initQ();
	p->len = -1;
	return p;
}

P* inputP() {
	int *powerBuffer;
	int amount;
	int power;
	int maxPower;
	P* p = (P*)malloc(sizeof(P));
	printf("Enter a max power of x: ");
	maxPower = getNumber();
	p->len = maxPower;
	p->k = (Q**)malloc((maxPower + 1) * sizeof(Q*));
	printf("Enter an amount of coefs to input: ");
	amount = getNumber();
	powerBuffer = (int*)malloc(amount * sizeof(int));
	for (int i = 0; i < amount; i++) {
		printf("***\nCoef %d\n", i);
		printf("Enter a power of x: ");
		power = getNumber();
		powerBuffer[i] = power;
		p->k[power] = inputQ();
	}
	for (int i = maxPower; i >= 0; i--) {
		bool f = false;
		for (int j = 0; j < amount; j++)
			if (powerBuffer[j] == i) f = true;
		if (!f) {
			p->k[i] = initQ();
			p->k[i]->num->number->len = 1;
			p->k[i]->num->number->n = (int*)malloc(sizeof(int));
			p->k[i]->num->number->n[0] = 0;
			p->k[i]->num->sign = true;
			p->k[i]->denom->len = 1;
			p->k[i]->denom->n = (int*)malloc(sizeof(int));
			p->k[i]->denom->n[0] = 1;
		}
	}
	free(powerBuffer);
	puts("");
	return p;
}

void printP(P* p) {
	int last = 0;
	for (int i = 0; i <= p->len; i++)
		if (!(p->k[i]->num->number->len == 1 && p->k[i]->num->number->n[0] == 0))
			break;
		else
			last++;
	for (int i = p->len; i >= 0; i--) {
		if (!(p->k[i]->num->number->len == 1 && p->k[i]->num->number->n[0] == 0)) {
			printQ(p->k[i]);
			if (i != 0)
				printf(" * x^%d ", i);
			if (i != last)
				printf("+ ");
		}
	}
}

P* freeP(P* p) {
	for (int i = 0; i < p->len; i++)
		freeQ(p->k[i]);
	free(p->k);
	free(p);
	return nullptr;
}

P* zeroP() {
	P* Result = initP();
	Result->len = 0;
	Result->k = (Q**)malloc(sizeof(Q*));
	Result->k[0] = initQ();
	Result->k[0]->num->number = getZero();
	Result->k[0]->denom = getZero();
	Result->k[0]->denom->n[0] = 1;
	return Result;
}

int getNumber() {
	char* number = nullptr;
	int toReturn;
	char symbol;
	int lenght = 0;

	do {
		do {
			symbol = getchar();
			if (symbol == 8 && lenght > 0) {
				printf("%c %c", 8, 8);
				lenght--;
				number = (char*)realloc(number, lenght * sizeof(char));
			}
			else if (symbol >= '0' && symbol <= '9') {
				number = (char*)realloc(number, (lenght + 1) * sizeof(char));
				*(number + lenght) = symbol;
				lenght++;
			}
		} while (symbol != '\n');
		if (lenght == 0) printf("\n");
	} while (lenght == 0);

	number = (char*)realloc(number, (lenght + 1) * sizeof(char));
	*(number + lenght) = '\0';
	toReturn = atoi(number);
	free(number);
	return toReturn;
}