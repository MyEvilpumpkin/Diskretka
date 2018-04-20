#pragma once
// Z-7 Стоянова Алина

Z *SUB_ZZ_Z(Z *num1, Z *num2)
{
	Z *n2 = (Z*)malloc(sizeof(Z));
	n2->number = assignmentN(num2->number); // присваиваем вычитаемому значение меньшего числа 
	n2->sign = !num2->sign; // умножаем второе число на (-1)
	Z* result = ADD_ZZ_Z(num1, n2); // суммируем числа
	freeZ(n2);
	return result; // возвращаем их сумму
}
