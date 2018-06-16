#pragma once
#include "Z_modules.h"

// Описание рационального числа
struct Q
{
	Z *num;   // Числитель (целое число)
	N *denom; // Знаменатель (натуральное число)
};

Q* initQ();         // Инициализация
Q* inputQ();        // Ввод
Q* zeroQ();         // Инициализация с обнулением
Q* assignmentQ(Q*); // Присваивание
void printQ(Q*);
Q* freeQ(Q*);

Q* RED_Q_Q(Q*);
bool INT_Q_B(Q*);
Q* TRANS_Z_Q(Z*);
Z* TRANS_Q_Z(Q*);
Q* ADD_QQ_Q(Q*, Q*);
Q* SUB_QQ_Q(Q*, Q*);
Q* MUL_QQ_Q(Q*, Q*);
Q* DIV_QQ_Q(Q*, Q*);
