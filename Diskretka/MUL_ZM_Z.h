#pragma once
// Z-3

Z* MUL_ZM_Z(Z* a)
{
	Z* resPtr = initZ();
	resPtr->number = assignmentN(a->number);
	if (resPtr->number->len != 1 || resPtr->number->n[0] != 0)
		resPtr->sign = !a->sign;
	return resPtr;
}