#pragma once
// Z-4

Z *TRANS_N_Z(N *a)
{
	Z *z = initZ();
	z->number = assignmentN(a);
	return z;
}