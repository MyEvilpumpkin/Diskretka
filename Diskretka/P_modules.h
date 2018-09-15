#pragma once
#include "Q_modules.h"

// Описание многочлена
struct P
{
	Q **k;            // Указатель на адрес свободного коэффициента, представленного в виде рационального числа
	unsigned int len; // Степень многочлена
};

P* deNullP(P*); // Удаление незначащих слагаемых со старшими коэффициентами

P* inputP();        // Ввод
P* zeroP();         // Инициализация с обнулением
P* assignmentP(P*); // Присваивание
void printP(P*);    // Вывод
P* freeP(P*);       // Освобождение памяти

P* ADD_PP_P(P*, P*);   // P-1
P* SUB_PP_P(P*, P*);   // P-2
P* MUL_PQ_P(P*, Q*);   // P-3
P* MUL_Pxk_P(P*, int); // P-4
Q* LED_P_Q(P*);        // P-5
N* DEG_P_N(P*);        // P-6
Q* FAC_P_Q(P*);        // P-7
P* MUL_PP_P(P*, P*);   // P-8
P* DIV_PP_P(P*, P*);   // P-9
P* MOD_PP_P(P*, P*);   // P-10
P* GCF_PP_P(P*, P*);   // P-11
P* DER_P_P(P*);        // P-12
P* NMR_P_P(P*);        // P-13
