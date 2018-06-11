#pragma once
#include "N_modules.h"

struct Z
{
	N *number;
	bool sign;
};

Z* initZ();
Z* inputZ();
Z* zeroZ();
Z* assignmentZ(Z*);
void printZ(Z*);
Z* freeZ(Z*);

N* ABS_Z_N(Z*);
int POZ_Z_D(Z*);
Z* MUL_ZM_Z(Z*);
Z *TRANS_N_Z(N*);
N *TRANS_Z_N(Z*);
Z *ADD_ZZ_Z(Z*, Z*);
Z *SUB_ZZ_Z(Z*, Z*);
Z *MUL_ZZ_Z(Z*, Z*);
Z* DIV_ZZ_Z(Z*, N*);
Z* MOD_ZZ_Z(Z*, N*);
