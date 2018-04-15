#pragma once
// Z-2

int POZ_Z_D(Z *a)
{
	if (a->sign == 0) //esli minus
		return 1;
	else
		if (a->number->len == 1 && a->number->n[0] == 0) //esli zero
			return 0;
		else //esli plus
			return 2;
}