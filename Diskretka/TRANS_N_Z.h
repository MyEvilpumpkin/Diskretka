#pragma once
// Z-4 Мищенко Алина

Z *TRANS_N_Z(N *a)
{
	Z *z = (Z*)malloc(sizeof(Z));
	z->number = assignmentN(a); // присваиваем целому результату натуральное число 
	z->sign = true;
	return z;
}