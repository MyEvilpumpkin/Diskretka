#pragma once
#include <iostream>
#include "malloc.h"

// Определение типа byte
typedef char byte;

// Описание натурального числа
struct N
{
	byte *n;           // Указатель на младший разряд числа
	unsigned int len;  // Количество разрядов в числе
};

int getNumber(); // Ввод неотрицательных чисел int
N* deNullN(N*);  // Удаление лишних нулей в начале числа
N* intToN(int);  // Перевод из int в N

N* inputN();        // Ввод
N* zeroN();         // Инициализация с обнулением
N* assignmentN(N*); // Присваивание
void printN(N*);    // Вывод
N* freeN(N*);       // Освобождение памяти

int COM_NN_D(N*, N*);        // N-1
bool NZER_N_B(N*);           // N-2
N* ADD_1N_N(N*);             // N-3
N* ADD_NN_N(N*, N*);         // N-4
N* SUB_NN_N(N*, N*);         // N-5
N* MUL_ND_N(N*, int);        // N-6
N* MUL_Nk_N(N*, int);        // N-7
N* MUL_NN_N(N*, N*);         // N-8
N* SUB_NDN_N(N*, int, N*);   // N-9
int DIV_NN_Dk(N*, N*, int&); // N-10
N* DIV_NN_N(N*, N*);         // N-11
N* MOD_NN_N(N*, N*);         // N-12
N* GCF_NN_N(N*, N*);         // N-13
N* LCM_NN_N(N*, N*);         // N-14
