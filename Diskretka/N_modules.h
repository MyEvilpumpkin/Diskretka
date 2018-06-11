#pragma once
#include <iostream>
#include "malloc.h"

struct N
{
	int *n;
	int len;
};

int getNumber(); // ввод неотрицательных чисел int
N* deNULL(N*); // удаление лишних нулей в начале числа
N* intToN(int); // перевод из int в N
N* input(); // ввод чисел N

N* initN(); // инициализация
N* inputN(); // ввод
N* zeroN(); // инициализация с обнулением
N* assignmentN(N*); // присваивание
void printN(N*); // вывод
N* freeN(N*); // освобождание памяти

int COM_NN_D(N*, N*);
bool NZER_N_B(N*);
N* ADD_1N_N(N*);
N* ADD_NN_N(N*, N*);
N* SUB_NN_N(N*, N*);
N* MUL_ND_N(N*, int);
N* MUL_Nk_N(N*, int);
N* MUL_NN_N(N*, N*);
N* SUB_NDN_N(N*, N*, int);
int DIV_NN_Dk(N*, N*, int&);
N* DIV_NN_N(N*, N*);
N* MOD_NN_N(N*, N*);
N* GCF_NN_N(N*, N*);
N* LCM_NN_N(N*, N*);
