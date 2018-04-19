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

int getNumber();
N* deNULL(N*);
N* intToN(int);
N* input();

N* initN();
N* inputN();
N* zeroN();
N* assignmentN(N* n);
void printN(N*);
N* freeN(N*);

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