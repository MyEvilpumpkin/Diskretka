#pragma once
// N-10

int DIV_NN_Dk(N* a, N* b, int &k)
{
	int Result = 1, // Первая цифра деления
		Flag; // Переменная для выхода из цикла
	N* Temp; // Временная переменная для хранения произведения
	k = 0;
	N* First, *Second;
	if (COM_NN_D(a, b) == 2) {
		First = assignmentN(a);
		Second = assignmentN(b);
	}
	else {
		First = assignmentN(b);
		Second = assignmentN(a);
	}
	do
	{
		Temp = MUL_Nk_N(Second, k); // Умножаем делитель на 10^k
		Flag = COM_NN_D(First, Temp); // Сравниваем делимое и произведение
		freeN(Temp);
		if (Flag != 1) // Если произведение меньше, то увеличиваем степень 10
			k++;
	} while (Flag != 1); // Пока произведение не станет больше делителя
	k--; // Так как при последнем сравнении k стало больше на 1 от необходимого
	Temp = MUL_Nk_N(Second, k); // Вычисляем наибольшее произведение делителя и 10^k, меньшее делимого
	do
	{
		N* tmp = MUL_ND_N(Temp, Result); // Вычисляем произведение на цифру
		Flag = COM_NN_D(First, tmp); // Сравниваем его с делимым
		if (Flag != 1) // Если произведение меньше делимого, проверяем следующую цифру
			Result++;
		freeN(tmp);
	} while (Flag != 1);
	Result--; // Аналогично значению степени
	freeN(Temp);
	freeN(First);
	freeN(Second);
	return Result;
}