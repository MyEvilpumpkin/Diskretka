#pragma once
#include "SUB_ZZ_Z.h"
// Z-6

Z *ADD_ZZ_Z(Z *num1, Z *num2)
{
	puts("");
	N *n1, *n2;
	Z *sum = initZ();
	if (num1->sign == true && num2->sign == num1->sign) { //Оба положительные
		sum->number = ADD_NN_N(num1->number, num2->number);
		sum->sign = true;
		return sum;
	}
	if (num1->sign == false && num2->sign == num1->sign) { //Оба отрицательные
		sum->number = ADD_NN_N(num1->number, num2->number);
		sum->sign = false;
		return sum;
	}
	//Сложение разных знаков будет вызывать функцию разности 
	if (num1->sign && !num2->sign) { //Первое положительное, второе отрицательное
		num2->sign = true;
		return SUB_ZZ_Z(num1, num2);
	}
	if (!num1->sign && num2->sign) { //Первое отрицательное, второе положитлеьное
		num1->sign = true;
		return SUB_ZZ_Z(num2, num1);
	}
}