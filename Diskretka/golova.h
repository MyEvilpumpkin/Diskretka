#pragma once
#include "malloc.h"
#include "locale.h"
#include <iostream>

struct N {
	int *n = nullptr;
	int len;
};

struct Z {
	N *number;
	bool sign = true;
};

struct Q {
	Z *num;
	N *denom;
};

struct P {
	Q **k;
	int len = -1;
};

int getNumber(); // ввод неотрицательных чисел int
N* deNULL(N*); // удаление лишних нулей в начале числа
N* intToN(int); // перевод из int в N
N* input(); // ввод чисел N

N* initN(); // инициализация
N* inputN(); // ввод
N* zeroN(); // инициализация с обнулением
N* assignmentN(N* n); // присваивание
void printN(N*); // вывод
N* freeN(N*); // освобождание памяти

Z* initZ();
Z* inputZ();
void printZ(Z*);
Z* freeZ(Z*);

Q* initQ();
Q* inputQ();
Q* zeroQ();
Q* assignmentQ(Q*);
void printQ(Q*);
Q* freeQ(Q*);

P* initP();
P* inputP();
P* zeroP();
P* assignmentP(P*);
void printP(P*);
P* freeP(P*);