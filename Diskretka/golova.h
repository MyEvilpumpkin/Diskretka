#pragma once
#include "malloc.h"
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
	int minPower = -1;
};

N* initN();
N* inputN();
void printN(N*);
N* freeN(N*);
N* deNULL(N*);
N* assignmentN(N* n);

Z* initZ();
Z* inputZ();
void printZ(Z*);
Z* freeZ(Z*);

Q* initQ();
Q* inputQ();
void printQ(Q*);
Q* freeQ(Q*);

P* initP();
P* inputP();
void printP(P*);
P* freeP(P*);

int getNumber();