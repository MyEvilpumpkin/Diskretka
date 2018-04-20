#pragma once
// N-9

N* SUB_NDN_N(N* a, N* b, int d)
{
	N* first, *second;
	N* result;
	N* temp;
	if (COM_NN_D(a, b) == 2) {
		first = assignmentN(a);
		second = assignmentN(b);
	}
	else {
		first = assignmentN(b);
		second = assignmentN(a);
	}
	temp = MUL_ND_N(second, d);
	result = SUB_NN_N(first, temp);
	free(temp);
	freeN(first);
	freeN(second);
	return result;
}