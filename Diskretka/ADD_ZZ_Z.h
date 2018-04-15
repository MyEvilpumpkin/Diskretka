#pragma once
#include "SUB_ZZ_Z.h"
// Z-6

Z *ADD_ZZ_Z(Z *num1, Z *num2)
{
	puts("");
	Z *sum = initZ();
	if (num1->sign == true && num2->sign == num1->sign) { //��� �������������
		sum->number = ADD_NN_N(num1->number, num2->number);
		sum->sign = true;
	}
	else if (num1->sign == false && num2->sign == num1->sign) { //��� �������������
		sum->number = ADD_NN_N(num1->number, num2->number);
		sum->sign = false;
	}
	//�������� ������ ������ ����� �������� ������� �������� 
	else if (num1->sign && !num2->sign) { //������ �������������, ������ �������������
		num2->sign = true;
		sum = SUB_ZZ_Z(num1, num2);
	}
	else if (!num1->sign && num2->sign) { //������ �������������, ������ �������������
		num1->sign = true;
		sum = SUB_ZZ_Z(num2, num1);
	}
	return sum;
}