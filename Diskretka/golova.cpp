#include "golova.h"

int getNumber() {
	char* number = nullptr;
	int toReturn;
	char symbol;
	int lenght = 0;
	bool error;
	do {
		lenght = 0;
		error = false;
		do {
			symbol = getchar();
			if (symbol >= '0' && symbol <= '9') {
				number = (char*)realloc(number, (lenght + 1) * sizeof(char));
				*(number + lenght) = symbol;
				lenght++;
			}
			else if (symbol != '\n')
				error = true;
		} while (symbol != '\n');
		if (error)
			printf("Incorrect data entered. Please enter a positive number: ");
	} while (error || lenght == 0);
	number = (char*)realloc(number, (lenght + 1) * sizeof(char));
	*(number + lenght) = '\0';
	toReturn = atoi(number);
	free(number);
	return toReturn;
}

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

N* intToN(int x) {
	N* n = (N*)malloc(sizeof(N));
	int len = 0, buffer = x;
	while (buffer > 0) {
		buffer = buffer / 10;
		len++;
	}
	n->len = len;
	n->n = (int*)malloc(len * sizeof(int));
	for (int i = len - 1; i >= 0; i--) {
		n->n[len - 1 - i] = x % 10;
		x /= 10;
	}
	return n;
}

N* input() {
	char *symbol = (char*)malloc(sizeof(char));
	int *k = nullptr, len = 0;
	N *number = initN();
	bool error = false;
	do {
		*symbol = getchar();
		if ('0' <= *symbol && *symbol <= '9') {
			k = (int*)realloc(k, (len + 1) * sizeof(int));
			k[len] = atoi(symbol);
			len++;
		}
		else if (*symbol != '\n')
			error = true;
		else if (!error && len == 0)
			number->len = 0;
	} while (*symbol != '\n');
	if (!error && len > 0) {
		number->n = (int*)malloc(len * sizeof(int));
		number->len = len;
		for (int i = 0; i < len; i++)
			number->n[i] = k[len - i - 1];
	}
	free(k);
	free(symbol);
	return number;
}

N* initN() {
	N* n = (N*)malloc(sizeof(N));
	n->n = (int*)malloc(sizeof(int));
	n->len = -1;
	return n;
}

N* inputN() {
	N* number = initN();
	do {
		number = input();
		if (number->len == -1)
			printf("Incorrect data entered. Please enter a number: ");
	} while (number->len < 1);
	number = deNULL(number);
	return number;
}

N* zeroN() {
	N* n = initN();
	n->len = 1;
	n->n = (int*)malloc(sizeof(int));
	n->n[0] = 0;
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
	z->sign = true;
	return z;
}

Z* inputZ() {
	Z* z = initZ();
	char *s = (char*)malloc(sizeof(char));
	bool error;
	do {
		error = false;
		*s = getchar();
		if (*s == '-')
			z->sign = false;
		else if ('0' <= *s && *s <= '9')
			z->sign = true;
		else
			error = true;
		z->number = input();
		if (z->number->len == -1 || (z->number->len == 0 && *s == '-'))
			error = true;
		if (error)
			printf("Incorrect data entered. Please enter a number: ");
		else if (*s != '-' && (*s != '0' || z->number->len == 0)) {
			z->number->n = (int*)realloc(z->number->n, (z->number->len + 1) * sizeof(int));
			z->number->len++;
			z->number->n[z->number->len - 1] = atoi(s);
		}
	} while (error);
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

Q* zeroQ() {
	Q* q = initQ();
	q->num->number = zeroN();
	q->denom = zeroN();
	q->denom->n[0] = 1;
	return q;
}

Q* assignmentQ(Q* q) {
	Q* a = initQ();
	a->num->sign = q->num->sign;
	a->num->number = assignmentN(q->num->number);
	a->denom = assignmentN(q->denom);
	return a;
}

void printQ(Q* q) {
	if (!q->num->sign)
		printf("- ");
	printN(q->num->number);
	if (q->denom->len != 1 || q->denom->n[0] != 1) {
		printf("/");
		printN(q->denom);
	}
}

Q* freeQ(Q* q) {
	freeN(q->denom);
	freeZ(q->num);
	free(q);
	return nullptr;
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
	int maxPower = -1;
	P* p = initP();
	printf("Enter an amount of coefs to input: ");
	do {
		amount = getNumber();
		if (amount == 0)
			printf("Incorrect data entered. Please enter an amount of coefs > 0: ");
	} while (amount == 0);
	powerBuffer = (int*)malloc(amount * sizeof(int));
	for (int i = 0; i < amount; i++) {
		printf("***\nCoef %d\n", i + 1);
		Q* temp = inputQ();
		printf("Enter a power of x: ");
		power = getNumber();
		if (power > maxPower) {
			maxPower = power;
			p->k = (Q**)realloc(p->k, (maxPower + 1) * sizeof(Q*));
			p->len = maxPower;
		}
		p->k[power] = assignmentQ(temp);
		freeQ(temp);
		powerBuffer[i] = power;
	}
	for (int i = maxPower; i >= 0; i--) {
		bool f = false;
		for (int j = 0; j < amount; j++)
			if (powerBuffer[j] == i) f = true;
		if (!f)
			p->k[i] = zeroQ();
	}
	free(powerBuffer);
	puts("");
	return p;
}

P* zeroP() {
	P* Result = initP();
	Result->len = 0;
	Result->k[0] = zeroQ();
	return Result;
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

void printP(P* p) {
	for (int i = p->len; i >= 0; i--) {
		if (!(p->k[i]->num->number->len == 1 && p->k[i]->num->number->n[0] == 0)) {
			if (i != p->len)
				if (p->k[i]->num->sign)
					printf("+ ");
			if (p->k[i]->num->number->len == 1 && p->k[i]->num->number->n[0] == 1 && i != 0 && p->k[i]->denom->len == 1 && p->k[i]->denom->n[0] == 1) {
				if (!p->k[i]->num->sign)
					printf("- ");
			}
			else {
				printQ(p->k[i]);
				if (i != 0)
					printf(" * ");
			}
			if (i > 1)
				printf("x^%d ", i);
			else if (i == 1)
				printf("x ");
		}
		else if (p->len == 0)
			printf("0");
	}
}

P* freeP(P* p) {
	for (int i = 0; i < p->len; i++)
		freeQ(p->k[i]);
	free(p->k);
	free(p);
	return nullptr;
}