#pragma once
#include "Q_modules.h"

struct P
{
	Q **k;
	int len;
};

P* initP();
P* inputP();
P* zeroP();
P* assignmentP(P*);
void printP(P*);
P* freeP(P*);

P* ADD_PP_P(P*, P*);
P* SUB_PP_P(P*, P*);
P* MUL_PQ_P(P*, Q*);
P* MUL_Pxk_P(P*, int);
Q* LED_P_Q(P*);
N* DEG_P_N(P*);
Q* FAC_P_Q(P*);
P* MUL_PP_P(P*, P*);
P* DIV_PP_P(P*, P*);
P* MOD_PP_P(P*, P*);
P* GCF_PP_P(P*, P*);
P* DER_P_P(P*);
P* NMR_P_P(P*);
