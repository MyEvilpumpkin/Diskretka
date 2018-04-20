#pragma once
// N-9 Марушевский Тихон

N* SUB_NDN_N(N* a, N* b, int d)
{
	N* first, *second;
	N* result;
	N* temp;
	if (COM_NN_D(a, b) == 2) { // если первое число больше второго
		first = assignmentN(a); // присваивание
		second = assignmentN(b);
	}
	else {
		first = assignmentN(b); // присваивание
		second = assignmentN(a);
	}
	temp = MUL_ND_N(second, d); // меньшее домножаем на цифру
	result = SUB_NN_N(first, temp); // вычитаем из большего числа меньшее (домноженное на цифру)
	free(temp);
	freeN(first);
	freeN(second);
	return result;
}