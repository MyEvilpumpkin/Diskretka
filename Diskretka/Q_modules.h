#pragma once
#include "Z_modules.h"

struct Q
{
	Z *num;
	N *denom;
};

Q* initQ();
Q* inputQ();
Q* zeroQ();
Q* assignmentQ(Q*);
void printQ(Q*);
Q* freeQ(Q*);

Q* RED_Q_Q(Q*);
bool INT_Q_B(Q*);
Q* TRANS_Z_Q(Z*);
Z* TRANS_Q_Z(Q*);
Q* ADD_QQ_Q(Q*, Q*);
Q* SUB_QQ_Q(Q*, Q*);
Q* MUL_QQ_Q(Q*, Q*);
Q* DIV_QQ_Q(Q*, Q*);
