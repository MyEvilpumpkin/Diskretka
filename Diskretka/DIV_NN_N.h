#pragma once
// N-11

N* DIV_NN_N(N* a, N* b)
{
	N* result = getZero();
	int k = 0,
		p = DIV_NN_Dk(a, b, k);
	result->len = k + 1;
	result->n = (int*)realloc(result->n, result->len * sizeof(int));
	/*for (int i = result->len - 1; i >= 0; i--)
		result->n[i] = 0;*/
	for (int i = result->len - 1; i >= 0; i--) {
		result->n[i] = p;
		N* temp = getZero();
		temp->n = (int*)realloc(temp->n, (k + 1) * sizeof(int));

	}
	return result;
}