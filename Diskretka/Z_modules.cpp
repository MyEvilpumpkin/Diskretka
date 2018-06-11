#include "Z_modules.h"

Z* initZ() {
	Z* z = (Z*)malloc(sizeof(Z));
	z->number = initN();
	z->sign = true;
	return z;
}

Z* inputZ() {
	Z* z = (Z*)malloc(sizeof(Z));
	char *s = (char*)malloc(sizeof(char));
	bool error;
	do {
		error = false;
		*s = getchar();
		if (*s == '-')
			z->sign = false;
		else if ('0' <= *s && *s <= '9')
			z->sign = true;
		else
			error = true;
		z->number = input();
		if (z->number->len == -1 || (z->number->len == 0 && *s == '-'))
			error = true;
		if (error) {
			printf("������� ������������ ������. ������� ����� �����: ");
			freeN(z->number);
		}
		else if (*s != '-' && (*s != '0' || z->number->len == 0)) {
			z->number->n = (int*)realloc(z->number->n, (z->number->len + 1) * sizeof(int));
			z->number->len++;
			z->number->n[z->number->len - 1] = atoi(s);
		}
	} while (error);
	free(s);
	z->number = deNULL(z->number);
	return z;
}

Z* zeroZ()
{
	Z* z = (Z*)malloc(sizeof(Z));
	z->number = zeroN();
	z->sign = true;
	return z;
}

Z* assignmentZ(Z* z)
{
	Z* a = (Z*)malloc(sizeof(Z));
	a->number = assignmentN(z->number);
	a->sign = z->sign;
	return a;
}

void printZ(Z* z) {
	if (!z->sign)
		printf("-");
	printN(z->number);
}

Z* freeZ(Z* z) {
	freeN(z->number);
	free(z);
	return z;
}

// Z-1 ���������� ����

N* ABS_Z_N(Z *a)
{
	return assignmentN(a->number); // ���������� ����� ����������� ����� ����� (����� = ����������� + ����)
}

// Z-2 ��������� �����

int POZ_Z_D(Z *a)
{
	if (!a->sign) // ���� ����� �������������
		return 1;
	else if (a->number->len == 1 && a->number->n[0] == 0) //���� ����� = 0
		return 0;
	else // ���� ����� �������������
		return 2;
}

// Z-3 ���������� ����

Z* MUL_ZM_Z(Z* a)
{
	Z* resPtr = (Z*)malloc(sizeof(Z));
	resPtr->sign = true;
	resPtr->number = assignmentN(a->number); // ����������� ���������� �������� �����
	if (resPtr->number->len != 1 || resPtr->number->n[0] != 0) // ���� ����� �� ����
		resPtr->sign = !a->sign; // ������ ���� ���������� �� ���������������
	return resPtr;
}

// Z-4 ������� �����

Z *TRANS_N_Z(N *a)
{
	Z *z = (Z*)malloc(sizeof(Z));
	z->number = assignmentN(a); // ����������� ������ ���������� ����������� ����� 
	z->sign = true;
	return z;
}

// Z-5 �������� ������

N *TRANS_Z_N(Z *a)
{
	return assignmentN(a->number); // ���������� ����� ����������� ����� �����
}

// Z-6 �������� �����

Z *ADD_ZZ_Z(Z *num1, Z *num2)
{
	Z* sum = (Z*)malloc(sizeof(Z));
	if (num1->sign == num2->sign) { // ���� ����� ���� ����� ���������
		sum->number = ADD_NN_N(num1->number, num2->number); // ���������� �� ������ ����������� �������� ����� ���� �����
		sum->sign = num1->sign; // ����������� ���������� ����� ���� ���� �����
	}
	else {
		if (COM_NN_D(num1->number, num2->number) == 2) { // ���� ������ ����� ������ ������� �� ������
			sum->number = SUB_NN_N(num1->number, num2->number); // �������� �� �������� ����� �������
			sum->sign = num1->sign; // ����������� ���������� ���� ������� �����
		}
		else if (COM_NN_D(num1->number, num2->number) == 1) { // ���� ������ ����� ������ ������� �� ������
			sum->number = SUB_NN_N(num2->number, num1->number); // ��������
			sum->sign = num2->sign;
		}
		else if (COM_NN_D(num1->number, num2->number) == 0) { // ���� ����� �����
			sum->number = zeroN(); // ��������� ����������� ����
			sum->sign = true; // �� ������ ����
		}
	}
	return sum;
}

// Z-7 �������� �����

Z *SUB_ZZ_Z(Z *num1, Z *num2)
{
	Z *n2 = (Z*)malloc(sizeof(Z));
	n2->number = assignmentN(num2->number); // ����������� ����������� �������� �������� ����� 
	n2->sign = !num2->sign; // �������� ������ ����� �� (-1)
	Z* result = ADD_ZZ_Z(num1, n2); // ��������� �����
	freeZ(n2);
	return result; // ���������� �� �����
}

// Z-8 �������� ������

Z *MUL_ZZ_Z(Z *num1, Z *num2)
{
	Z *mul = (Z*)malloc(sizeof(Z));
	mul->number = MUL_NN_N(num1->number, num2->number); // ����������� ���������� �� ������ �������� ������������ ������� ����� �� ������ �� ������
	if (num1->sign == num2->sign) // ���� ����� ���� ����� �����
		mul->sign = true; // �� ���� ���������� +
	else
		mul->sign = false; // ���� ���������� -
	if (mul->number->len == 1 && mul->number->n[0] == 0) // ���� �������� - 0
		mul->sign = true; // �� ���� ���������� +
	return mul;
}

// Z-9 ������� �����

Z* DIV_ZZ_Z(Z* n1, N* n2)
{
	Z* res = (Z*)malloc(sizeof(Z));
	res->number = DIV_NN_N(n1->number, n2); // ����� ��� ����������� ����� ������� (��������������� � �����) �� �������
	res->sign = n1->sign; // ����������� ����� ���������� ���� �������� �����
	if (res->number->len == 1 && res->number->n[0] == 0) // ���� ��������� ����� ����
		res->sign = true; // �� ���� ���� +
	N* mod = MOD_NN_N(n1->number, n2);
	if (!res->sign && !(mod->len == 1 && mod->n[0] == 0))
	{
		Z* one = zeroZ();
		one->number->n[0] = 1;
		Z* temp = assignmentZ(res);
		freeZ(res);
		res = SUB_ZZ_Z(temp, one);
		freeZ(temp);
		freeZ(one);
	}
	freeN(mod);
	return res;
}

// Z-10 ������� ������

Z* MOD_ZZ_Z(Z* First, N* Second)
{
	Z* tmp = TRANS_N_Z(Second); // ��������������� � ����� ������ �����
	Z *Rest = DIV_ZZ_Z(First, Second); // ��������� �� ������� ��� ������� ������� ����� �� ������
	Z *Temp = MUL_ZZ_Z(Rest, tmp);
	freeZ(tmp);
	freeZ(Rest);
	tmp = SUB_ZZ_Z(First, Temp); // �������� ����� �������� ������ ������ � �������������
	freeZ(Temp);

	if (First->sign) { // ���� ���� ���������� +
		Rest = (Z*)malloc(sizeof(Z));
		Rest->number = assignmentN(tmp->number);
		Rest->sign = true;
	}
	else {
		Temp = TRANS_N_Z(Second);
		Rest = ADD_ZZ_Z(tmp, Temp); // ��������� � ������� ��������������� ������ �����
		freeZ(Temp);
	}
	freeZ(tmp);
	return Rest;
}
