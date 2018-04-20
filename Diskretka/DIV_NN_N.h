#pragma once
// N-11

N* DIV_NN_N(N* a, N* b)
{
	N* First,* Second;
	if (COM_NN_D(a, b) == 2) {
		First = assignmentN(a);
		Second = assignmentN(b);
	}
	else {
		First = assignmentN(b);
		Second = assignmentN(a);
	}
	N* Result = zeroN(); // Частное от деления
	N* Part = assignmentN(First); // Временный остаток от деления
	N* TempRes, *Temp; // Временный делитель
	int Numb, // Первая цифра от деления
		Flag, // Переменная для выхода из цикла
		k = 0; // Степень десятки
	if (NZER_N_B(Second))
	do
	{
		Numb = DIV_NN_Dk(Part, Second, k); // Вычисляем первую цифру и степень десятки при делении
		TempRes = zeroN(); // 16 - 20 строки - это создание ппроизведения первой цифры деления на 10^k
		Temp = ADD_1N_N(TempRes); // Прибавим 1 - так как при умножении она никак не будет влиять на результат
		freeN(TempRes);
		TempRes = MUL_ND_N(Temp, Numb); // Умножаем 1 на первую цифру деления
		freeN(Temp);
		Temp = MUL_Nk_N(TempRes, k); // Умножаем на 10^k
		freeN(TempRes);
		TempRes = ADD_NN_N(Result, Temp); // Добавление временного результата к общему
		freeN(Result);
		Result = assignmentN(TempRes);
		freeN(TempRes);
		TempRes = MUL_NN_N(Temp, Second);
		freeN(Temp);
		Temp = SUB_NN_N(Part, TempRes); // Вычисление временного остатка
		freeN(Part);
		Part = assignmentN(Temp);
		freeN(Temp);
		Flag = COM_NN_D(Part, Second); // Сравниваем "делимое" и делитель
		freeN(TempRes);
	} while (Flag != 1);
	freeN(Part);
	freeN(First);
	freeN(Second);
	return Result;
}