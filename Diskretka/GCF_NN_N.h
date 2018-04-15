#pragma once
// N-13

N* GCF_NN_N(N* a, N* b)
{
	N* First = assignmentN(a);
	N* Second = assignmentN(b);
	short Temp; // Результат сравнения двух чисел
	bool FirstCheck; // Проверка первого на ноль
	bool SecondCheck; // Проверка второго на ноль
	FirstCheck = NZER_N_B(First);
	SecondCheck = NZER_N_B(Second);
	while ((FirstCheck == 1) && (SecondCheck == 1))
	{
		Temp = COM_NN_D(First, Second);
		if (Temp > 1) // Если первое больше второго
			First = MOD_NN_N(First, Second); // Находим остаток от деления первого на второе
		else
			Second = MOD_NN_N(Second, First); // Иначе - остаток от деления второго на первое
		FirstCheck = NZER_N_B(First);
		SecondCheck = NZER_N_B(Second);
	}
	Temp = COM_NN_D(First, Second);
	if (Temp == 2)
		return First;
	else
		return Second;
}