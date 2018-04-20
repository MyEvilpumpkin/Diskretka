#pragma once
// Z-2 ћакаренко ƒанил

int POZ_Z_D(Z *a)
{
	if (!a->sign) // если число отрицательное
		return 1;
	else if (a->number->len == 1 && a->number->n[0] == 0) //если число = 0
		return 0;
	else // если число положительное
		return 2;
}