#pragma once
#include "Z_modules.h"

// Описание рационального числа
struct Q
{
	Z *num;   // Числитель (целое число)
	N *denom; // Знаменатель (натуральное число)
};

Q* inputQ();        // Ввод
Q* zeroQ();         // Инициализация с обнулением
Q* assignmentQ(Q*); // Присваивание
void printQ(Q*);    // Вывод
Q* freeQ(Q*);       // Освобождение памяти

Q* RED_Q_Q(Q*);      // Q-1
bool INT_Q_B(Q*);    // Q-2
Q* TRANS_Z_Q(Z*);    // Q-3
Z* TRANS_Q_Z(Q*);    // Q-4
Q* ADD_QQ_Q(Q*, Q*); // Q-5
Q* SUB_QQ_Q(Q*, Q*); // Q-6
Q* MUL_QQ_Q(Q*, Q*); // Q-7
Q* DIV_QQ_Q(Q*, Q*); // Q-8
