#pragma once
// N-9

N* SUB_NDN_N(N* a, N* b, int d)
{
	N* result = zeroN();
	if (COM_NN_D(a, b) == 2) {
		N* first = assignmentN(a);
		N* second = assignmentN(b);
		result = SUB_NN_N(first, MUL_ND_N(second, d));
	}
	else {
		N* first = assignmentN(b);
		N* second = assignmentN(a);
		result = SUB_NN_N(first, MUL_ND_N(second, d));
	}
	return result;
}