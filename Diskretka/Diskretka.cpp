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
		break;
	case 2:
		puts("***Z modules***");
		break;
	case 3:
		puts("***Q modules***");
		break;
	case 4:
		puts("***P modules***");
		break;
	case 5:
		puts("***Help***");
		break;
	}
	scanf("%d", &option);
	return option;
}

int main()
{
	puts("Diskretka");
	do
	{
		int n = getNumber();
		puts("#");
		//scanf("%d", &n);
		//getchar();
		//puts("#");
		//N_modules(n);
		//Z_modules(n);
		//Q_modules(n);
		//P_modules(n);
		puts("");
	} while (1);
    return 0;
}