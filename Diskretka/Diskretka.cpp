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
		puts("___N modules___");
		puts(" 1 - COM_NN_D");
		puts(" 2 - NZER_N_B");
		puts(" 3 - ADD_1N_N");
		puts(" 4 - ADD_NN_N");
		puts(" 5 - SUB_NN_N");
		puts(" 6 - MUL_ND_N");
		puts(" 7 - MUL_Nk_N");
		puts(" 8 - MUL_NN_N");
		puts(" 9 - SUB_NDN_N");
		puts("10 - DIV_NN_Dk");
		puts("11 - DIV_NN_N");
		puts("12 - MOD_NN_N");
		puts("13 - GCF_NN_N");
		puts("14 - LCM_NN_N");
		puts(" 0 - Exit");
		break;
	case 2:
		puts("___Z modules___");
		puts(" 1 - ABS_Z_N");
		puts(" 2 - POZ_Z_D");
		puts(" 3 - MUL_ZM_Z");
		puts(" 4 - TRANS_N_Z");
		puts(" 5 - TRANS_Z_N");
		puts(" 6 - ADD_ZZ_Z");
		puts(" 7 - SUB_ZZ_Z");
		puts(" 8 - MUL_ZZ_Z");
		puts(" 9 - DIV_ZZ_Z");
		puts("10 - MOD_ZZ_Z");
		puts(" 0 - Exit");
		break;
	case 3:
		puts("___Q modules___");
		puts("1 - RED_Q_Q");
		puts("2 - INT_Q_B");
		puts("3 - TRANS_Z_Q");
		puts("4 - TRANS_Q_Z");
		puts("5 - ADD_QQ_Q");
		puts("6 - SUB_QQ_Q");
		puts("7 - MUL_QQ_Q");
		puts("8 - DIV_QQ_Q");
		puts("0 - Exit");
		break;
	case 4:
		puts("___P modules___");
		puts(" 1 - ADD_PP_P");
		puts(" 2 - SUB_PP_P");
		puts(" 3 - MUL_PQ_P");
		puts(" 4 - MUL_Pxk_P");
		puts(" 5 - LED_P_Q");
		puts(" 6 - DEG_P_N");
		puts(" 7 - FAC_P_Q");
		puts(" 8 - MUL_PP_P");
		puts(" 9 - DIV_PP_P");
		puts("10 - MOD_PP_P");
		puts("11 - GCF_PP_P");
		puts("12 - DER_P_P");
		puts("13 - NMR_P_P");
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