#include "golova.h"
#include "conio.h"

N* deNULL(N* n) {
	int i = 1,
		l = n->len;
	for (int j = 0; j < l; j++)
		i = n->n[j] == 0 ? i : j + 1;
	n->n = (int*)realloc(n->n, i * sizeof(int));
	n->len = i;
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
	n->n = (int*)malloc(4);
	n->n[0] = 0;
	return n;
}

N* inputN() {
	char *symbol = (char*)malloc(1);
	int *k = nullptr, len = 0;
	N *number = nullptr;
	do {
		*symbol = _getch();
		if ('0' <= *symbol && *symbol <= '9') {
			printf("%c", *symbol);
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
	//puts("q1");
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
	char *s = (char*)malloc(1);
	*s = _getche();
	if (*s == '-')
		z->sign = false;
	else
		z->sign = true;
	z->number = inputN();
	if (*s != '-') {
		z->number->n = (int*)realloc(z->number->n, (z->number->len + 1) * 4);
		z->number->len++;
		z->number->n[z->number->len - 1] = atoi(s);
	}
	free(s);
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
	puts("");
	printf("Enter denominator: ");
	q->denom = inputN();
	puts("");
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

P* initP() {
	return nullptr;
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
	p->minPower = maxPower;
	p->k = (Q**)malloc((maxPower + 1) * sizeof(Q*));
	printf("Enter an amount of coefs to input: ");
	amount = getNumber();
	powerBuffer = (int*)malloc(4 * amount);
	for (int i = 0; i < amount; i++) {
		printf("***\nCoef %d\n", i);
		printf("Enter a power of x: ");
		power = getNumber();
		powerBuffer[i] = power;
		p->k[power] = inputQ();
		if (p->minPower > power)
			p->minPower = power;
	}
	for (int i = maxPower; i >= 0; i--) {
		bool f = false;
		for (int j = 0; j < amount; j++)
			if (powerBuffer[j] == i) f = true;
		if (!f) {
			p->k[i] = initQ();
			p->k[i]->num->number->len = 1;
			p->k[i]->num->number->n = (int*)malloc(4);
			p->k[i]->num->number->n[0] = 0;
			p->k[i]->num->sign = true;
			p->k[i]->denom->len = 1;
			p->k[i]->denom->n = (int*)malloc(4);
			p->k[i]->denom->n[0] = 1;
		}
	}
	free(powerBuffer);
	return p;
}

void printP(P* p) {
	for (int i = p->len; i >= 0; i--) {
		if (!(p->k[i]->num->number->len == 1 && p->k[i]->num->number->n[0] == 0)) {
			printQ(p->k[i]);
			printf(" * x^%d ", i);
			if (i != p->minPower)
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

int getNumber() {
	char* number = nullptr;
	int toReturn;
	char symbol;
	int lenght = 0;

	do {
		do {
			symbol = _getch();
			if (symbol == 8 && lenght > 0) {
				printf("%c %c", 8, 8);
				lenght--;
				number = (char*)realloc(number, lenght * sizeof(char));
			}
			else if (symbol >= '0' && symbol <= '9') {
				printf("%c", symbol);
				number = (char*)realloc(number, (lenght + 1) * sizeof(char));
				*(number + lenght) = symbol;
				lenght++;
			}
		} while (symbol != '\r');
		if (lenght == 0) printf("\n");
	} while (lenght == 0);

	number = (char*)realloc(number, (lenght + 1) * sizeof(char));
	*(number + lenght) = '\0';
	puts("");
	toReturn = atoi(number);
	free(number);
	return toReturn;
}