#pragma once
// P-4 Дяченко Виталий

P* MUL_Pxk_P(P* Polyn, int k) {
	P* Result = (P*)malloc(sizeof(P));
	Result->k = (Q**)malloc(sizeof(Q*));
	int i; // Для перебора коэффициентов
	Result->k = (Q**)realloc(Result->k, (Polyn->len + k + 1) * sizeof(Q*)); // Выделение памяти
	Result->len = Polyn->len + k; // присваиваем степени многочлена-результата сумму степени исходного многочлена и степени k
	for (i = Result->len; i >= k; i--) // цикл от старшего коэффициента многочлена до степени k
		Result->k[i] = assignmentQ(Polyn->k[i - k]); // присваиваем текущему коэффициенту многочлена-результата коэффициент исходного многочлена "отстающий" на k
	for (i = k - 1; i >= 0; i--) // цикл от степени k-1 до младшего коэффициента многочлена
		Result->k[i] = zeroQ(); // смещаем наш многочлен на одну степень
	return Result;
}