#pragma once
// Z-6 Стоянова Алина

Z *ADD_ZZ_Z(Z *num1, Z *num2)
{
	Z* sum = (Z*)malloc(sizeof(Z));
	if (num1->sign == num2->sign) { // если знаки двух чисел одинаковы
		sum->number = ADD_NN_N(num1->number, num2->number); // результату по модулю присваиваем значение суммы двух чисел
		sum->sign = num1->sign; // присваиваем результату общий знак двух чисел
	}
	else {
		if (COM_NN_D(num1->number, num2->number) == 2) { // если первое число больше второго по модулю
			sum->number = SUB_NN_N(num1->number, num2->number); // вычитаем из большего числа меньшее
			sum->sign = num1->sign; // присваиваем результату знак первого числа
		}
		else if (COM_NN_D(num1->number, num2->number) == 1) { // если второе число больше первого по модулю
			sum->number = SUB_NN_N(num2->number, num1->number); // наоборот
			sum->sign = num2->sign;
		}
		else if (COM_NN_D(num1->number, num2->number) == 0) { // если числа равны
			sum->number = zeroN(); // результат присваиваем нулю
			sum->sign = true; // со знаком плюс
		}
	}
	return sum;
}