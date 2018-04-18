#include "modules.h"

int menu(int option) {
	switch (option)
	{
	case 0:
		puts("***MAIN MENU***");
		puts("1 - N modules");
		puts("2 - Z modules");
		puts("3 - Q modules");
		puts("4 - P modules");
		puts("5 - Help");
		puts("0 - Exit");
		break;
	case 1:
		puts("***N modules***");
		puts("0 - Exit");
		break;
	case 2:
		puts("***Z modules***");
		puts("0 - Exit");
		break;
	case 3:
		puts("***Q modules***");
		puts("0 - Exit");
		break;
	case 4:
		puts("***P modules***");
		puts("0 - Exit");
		break;
	}
	option = getNumber();
	system("cls");
	return option;
}

void help() {
	puts("***Help***");
	puts("Here could be your advertisement");
	system("pause");
	system("cls");
}

int main()
{
	puts("Diskretka");
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
					puts("Incorrect data entered. Please select menu item");
			} while (choice2 != 0);
			break;
		case 2:
			do {
				choice2 = menu(choice);
				if (choice2 > 0 && choice2 < 11)
					Z_modules(choice2);
				else if (choice2 != 0)
					puts("Incorrect data entered. Please select menu item");
			} while (choice2 != 0);
			break;
		case 3:
			do {
				choice2 = menu(choice);
				if (choice2 > 0 && choice2 < 9)
					Q_modules(choice2);
				else if (choice2 != 0)
					puts("Incorrect data entered. Please select menu item");
			} while (choice2 != 0);
			break;
		case 4:
			do {
				choice2 = menu(choice);
				if (choice2 > 0 && choice2 < 14)
					P_modules(choice2);
				else if (choice2 != 0)
					puts("Incorrect data entered. Please select menu item");
			} while (choice2 != 0);
			break;
		case 5:
			help();
			break;
		case 0:
			printf("Exit...");
			break;
		default:
			puts("Incorrect data entered. Please select menu item");
			break;
		}
	} while (choice != 0);
    return 0;
}