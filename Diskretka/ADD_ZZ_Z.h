#pragma once
#include "SUB_ZZ_Z.h"
// Z-6

Z *ADD_ZZ_Z(Z *n1, Z *n2)
{
	Z* num1 = initZ();
	num1->number = assignmentN(n1->number);
	num1->sign = n1->sign;
	Z* num2 = initZ();
	num2->number = assignmentN(n2->number);
	num2->sign = n2->sign;
	Z* sum = initZ();
	if (num1->sign == true && num2->sign == num1->sign) { //Оба положительные
		sum->number = ADD_NN_N(num1->number, num2->number);
		sum->sign = true;
	}
	else if (num1->sign == false && num2->sign == num1->sign) { //Оба отрицательные
		sum->number = ADD_NN_N(num1->number, num2->number);
		sum->sign = false;
	}
	//Сложение разных знаков будет вызывать функцию разности 
	else if (num1->sign && !num2->sign) { //Первое положительное, второе отрицательное
		num2->sign = true;
		sum = SUB_ZZ_Z(num1, num2);
	}
	else if (!num1->sign && num2->sign) { //Первое отрицательное, второе положитлеьное
		num1->sign = true;
		sum = SUB_ZZ_Z(num2, num1);
	}
	return sum;
}