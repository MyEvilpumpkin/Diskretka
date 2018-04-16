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
	N* Result = getZero(); // Частное от деления
	N* Part = assignmentN(First); // Временный остаток от деления
	N* TempRes; // Временный делитель
	int Numb, // Первая цифра от деления
		Flag, // Переменная для выхода из цикла
		k; // Степень десятки
	if (NZER_N_B(Second))
	do
	{
		Numb = DIV_NN_Dk(Part, Second, k); // Вычисляем первую цифру и степень десятки при делении
		TempRes = getZero(); // 16 - 20 строки - это создание ппроизведения первой цифры деления на 10^k
		TempRes = ADD_1N_N(TempRes); // Прибавим 1 - так как при умножении она никак не будет влиять на результат
		TempRes = MUL_ND_N(TempRes, Numb); // Умножаем 1 на первую цифру деления
		TempRes = MUL_Nk_N(TempRes, k); // Умножаем на 10^k
		Result = ADD_NN_N(Result, TempRes); // Добавление временного результата к общему
		TempRes = MUL_NN_N(TempRes, Second);
		Part = SUB_NN_N(Part, TempRes); // Вычисление временного остатка
		Flag = COM_NN_D(Part, Second); // Сравниваем "делимое" и делитель
	} while (Flag != 1);
	return Result;
}