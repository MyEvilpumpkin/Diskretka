#pragma once
// Z-3

Z* MUL_ZM_Z(Z* a)
{
	Z* resPtr = initZ();
	resPtr->number = assignmentN(a->number);
	resPtr->sign = !a->sign;
	return resPtr;
}