#pragma once
// Z-3 Андрианова Вера

Z* MUL_ZM_Z(Z* a)
{
	Z* resPtr = (Z*)malloc(sizeof(Z));
	resPtr->sign = true;
	resPtr->number = assignmentN(a->number); // присваиваем результату исходное число
	if (resPtr->number->len != 1 || resPtr->number->n[0] != 0) // если число не ноль
		resPtr->sign = !a->sign; // меняем знак результата на противоположный
	return resPtr;
}