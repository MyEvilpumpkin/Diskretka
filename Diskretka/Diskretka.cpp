#include "modules.h"

int menu(int option) {
	switch (option)
	{
	case 0:
		puts("___MAIN MENU___");
		puts("1 - N modules");
		puts("2 - Z modules");
		puts("3 - Q modules");
		puts("4 - P modules");
		puts("0 - Exit");
		break;
	case 1:
		puts("_______________________________________________N modules_______________________________________________");
		puts(" № - Название  - Описание");
		puts(" 1 - COM_NN_D  - Сравнение натуральных чисел");
		puts(" 2 - NZER_N_B  - Проверка на ноль");
		puts(" 3 - ADD_1N_N  - Добавление 1 к натуральному числу");
		puts(" 4 - ADD_NN_N  - Сложение натуральных чисел");
		puts(" 5 - SUB_NN_N  - Вычитание натуральных чисел");
		puts(" 6 - MUL_ND_N  - Умножение натурального числа на цифру");
		puts(" 7 - MUL_Nk_N  - Умножение натурального числа на 10^k");
		puts(" 8 - MUL_NN_N  - Умножение натуральных чисел");
		puts(" 9 - SUB_NDN_N - Вычитание из натурального другого натурального, умноженного на цифру");
		puts("10 - DIV_NN_Dk - Вычисление первой цифры деления большего натурального на меньшее, домноженное на 10^k");
		puts("11 - DIV_NN_N  - Частное от деления большего натурального числа на меньшее");
		puts("12 - MOD_NN_N  - Остаток от деления большего натурального числа на меньшее");
		puts("13 - GCF_NN_N  - НОД натуральных чисел");
		puts("14 - LCM_NN_N  - НОК натуральных чисел");
		puts(" 0 -   Exit    - Выход");
		break;
	case 2:
		puts("___Z modules___");
		puts(" 1 - Абсолютная величина числа (ABS_Z_N)");
		puts(" 2 - Определение положительности числа (POZ_Z_D)");
		puts(" 3 - Умножение целого на (-1) (MUL_ZM_Z)");
		puts(" 4 - Преобразование натурального в целое (TRANS_N_Z)");
		puts(" 5 - Преобразование целого неотрицательного в натуральное (TRANS_Z_N)");
		puts(" 6 - Сложение целых чисел (ADD_ZZ_Z)");
		puts(" 7 - Вычитание целых чисел (SUB_ZZ_Z)");
		puts(" 8 - Умножение целых чисел (MUL_ZZ_Z)");
		puts(" 9 - Частное от деления большего целого числа на меньшее (DIV_ZZ_Z)");
		puts("10 - Остаток от деления большего целого числа на меньшее (MOD_ZZ_Z)");
		puts(" 0 - Exit");
		break;
	case 3:
		puts("___Q modules___");
		puts("1 - Сокращение дроби (RED_Q_Q)");
		puts("2 - Проверка на целое (INT_Q_B)");
		puts("3 - Преобразование целого в дробное (TRANS_Z_Q)");
		puts("4 - Преобразование дробного в целое (если знаменатель равен 1) (TRANS_Q_Z)");
		puts("5 - Сложение дробей (ADD_QQ_Q)");
		puts("6 - Вычитание дробей (SUB_QQ_Q)");
		puts("7 - Умножение дробей (MUL_QQ_Q)");
		puts("8 - Деление дробей (делитель отличен от нуля) (DIV_QQ_Q)");
		puts("0 - Exit");
		break;
	case 4:
		puts("___P modules___");
		puts(" 1 - Сложение многочленов (ADD_PP_P)");
		puts(" 2 - Вычитание многочленов (SUB_PP_P)");
		puts(" 3 - Умножение многочлена на рациональное число (MUL_PQ_P)");
		puts(" 4 - Умножение многочлена на x^k (MUL_Pxk_P)");
		puts(" 5 - Старший коэффициент многочлена (LED_P_Q)");
		puts(" 6 - Степень многочлена (DEG_P_N)");
		puts(" 7 - Вынесение из многочлена НОК знаменателей коэффициентов");
		puts("и НОД числителей(FAC_P_Q)");
		puts(" 8 - Умножение многочленов (MUL_PP_P)");
		puts(" 9 - Частное от деления многочлена на многочлен с остатком (DIV_PP_P)");
		puts("10 - Остаток от деления многочлена на многочлен с остатком (MOD_PP_P)");
		puts("11 - НОД многочленов (GCF_PP_P)");
		puts("12 - Производная многочлена (DER_P_P)");
		puts("13 - Преобразование многочлена — кратные корни в простые (NMR_P_P)");
		puts(" 0 - Exit");
		break;
	}
	printf("Select a menu item: ");
	option = getNumber();
	system("cls");
	return option;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	int choice, choice2;
	do
	{
		choice = menu(0);
		choice2;
		switch (choice)
		{
		case 1:
			do {
				choice2 = menu(choice);
				if (choice2 > 0 && choice2 < 15)
					N_modules(choice2);
				else if (choice2 != 0)
					puts("Incorrect data entered. Please select a menu item");
			} while (choice2 != 0);
			break;
		case 2:
			do {
				choice2 = menu(choice);
				if (choice2 > 0 && choice2 < 11)
					Z_modules(choice2);
				else if (choice2 != 0)
					puts("Incorrect data entered. Please select a menu item");
			} while (choice2 != 0);
			break;
		case 3:
			do {
				choice2 = menu(choice);
				if (choice2 > 0 && choice2 < 9)
					Q_modules(choice2);
				else if (choice2 != 0)
					puts("Incorrect data entered. Please select a menu item");
			} while (choice2 != 0);
			break;
		case 4:
			do {
				choice2 = menu(choice);
				if (choice2 > 0 && choice2 < 14)
					P_modules(choice2);
				else if (choice2 != 0)
					puts("Incorrect data entered. Please select a menu item");
			} while (choice2 != 0);
			break;
		case 0:
			printf("Exit...");
			break;
		default:
			puts("Incorrect data entered. Please select a menu item");
			break;
		}
	} while (choice != 0);
    return 0;
}