#pragma once
// Z-8

Z *MUL_ZZ_Z(Z *num1, Z *num2)
{
	Z *mul = initZ();
	N *n1, *n2;
	n1 = ABS_Z_N(num1); //������ �� ������� �����
	n2 = ABS_Z_N(num2);	//������ �� ������� �����
	printf("%d\n", NZER_N_B(num1->number));
	if (!(NZER_N_B(num1->number) || NZER_N_B(num2->number))) {
		mul->sign = true;
		mul->number->len = 1;
		mul->number->n[0] = 0;
		return mul;
	}
	mul->number = MUL_NN_N(n1, n2);
	if (num1->sign == num2->sign)
		mul->sign = true;
	else
		mul->sign = false;
	return mul;
}