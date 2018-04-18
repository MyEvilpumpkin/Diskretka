#pragma once
// N-9

N* SUB_NDN_N(N* a, N* b, int d)
{
	N* first, *second;
	N* result = zeroN();
	if (COM_NN_D(a, b) == 2) {
		first = assignmentN(a);
		second = assignmentN(b);
		result = SUB_NN_N(first, MUL_ND_N(second, d));
	}
	else {
		first = assignmentN(b);
		second = assignmentN(a);
		result = SUB_NN_N(first, MUL_ND_N(second, d));
	}
	freeN(first);
	freeN(second);
	return result;
}