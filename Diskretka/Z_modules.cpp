#include "Z_modules.h"

// ����
Z* inputZ() {
	Z* z = (Z*)malloc(sizeof(Z));
	bool error;
	do
	{
		error = false;
		z->sign = true;
		char symbol;
		int len = 0;
		byte* k = nullptr;
		do
		{
			symbol = getchar();
			if ((symbol >= '0' && symbol <= '9') && !error) {
				k = (byte*)realloc(k, (len + 1) * sizeof(byte));
				k[len++] = symbol - 48;
			}
			else if (symbol == '-' && !len && z->sign)
				z->sign = false;
			else if (symbol != '\n' || !len)
				error = true;
		} while (symbol != '\n');
		if (!error) {
			z->number = (N*)malloc(sizeof(N));
			z->number->n = (byte*)malloc(len * sizeof(byte));
			z->number->len = len;
			for (int i = 0; i < len; i++)
				z->number->n[i] = k[len - i - 1];
			if (len == 1 && !z->number->n[0])
				z->sign = true;
			deNullN(z->number);
		}
		else
			printf("������� ������������ ������. ������� ����� �����: ");
		free(k);
	} while (error);
	return z;
}
// ������������� � ����������
Z* zeroZ()
{
	Z* z = (Z*)malloc(sizeof(Z));
	z->number = zeroN();
	z->sign = true;
	return z;
}
// ������������
Z* assignmentZ(Z* z)
{
	Z* result = (Z*)malloc(sizeof(Z));
	result->number = assignmentN(z->number);
	result->sign = z->sign;
	return result;
}
// �����
void printZ(Z* z)
{
	if (!z->sign)
		printf("-");
	printN(z->number);
}
// ������������ ������
Z* freeZ(Z* z)
{
	freeN(z->number);
	free(z);
	return z;
}

// Z-1
N* ABS_Z_N(Z* z)
{
	return assignmentN(z->number); // ���������� ����� ����������� ����� ����� (����� = ����������� + ����)
}
// Z-2
int POZ_Z_D(Z* z)
{
	if (!NZER_N_B(z->number)) // ���� ����� = 0
		return 0;
	else if (!z->sign) // ���� ����� �������������
		return 1;
	else // ���� ����� �������������
		return 2;
}
// Z-3
Z* MUL_ZM_Z(Z* z)
{
	Z* result = assignmentZ(z); // ����������� ���������� �������� �����
	if (POZ_Z_D(result)) // ���� ����� �� ����
		result->sign = !z->sign; // ������ ���� ���������� �� ���������������
	return result;
}
// Z-4
Z* TRANS_N_Z(N* n)
{
	Z* result = (Z*)malloc(sizeof(Z));
	result->number = assignmentN(n); // ����������� ������ ���������� ����������� ����� 
	result->sign = true;
	return result;
}
// Z-5
N* TRANS_Z_N(Z* z)
{
	return assignmentN(z->number); // ���������� ����� ����������� ����� �����
}
// Z-6
Z* ADD_ZZ_Z(Z* z1, Z* z2)
{
	Z* result = (Z*)malloc(sizeof(Z));
	if (z1->sign == z2->sign) // ���� ����� ���� ����� ���������
	{
		result->number = ADD_NN_N(z1->number, z2->number); // ���������� �� ������ ����������� �������� ����� ���� �����
		result->sign = z1->sign; // ����������� ���������� ����� ���� ���� �����
	}
	else
	{
		int com = COM_NN_D(z1->number, z2->number);
		if (com == 2) // ���� ������ ����� ������ ������� �� ������
		{
			result->number = SUB_NN_N(z1->number, z2->number); // �������� �� �������� ����� �������
			result->sign = z1->sign; // ����������� ���������� ���� ������� �����
		}
		else if (com == 1) // ���� ������ ����� ������ ������� �� ������
		{
			result->number = SUB_NN_N(z2->number, z1->number); // ��������
			result->sign = z2->sign;
		}
		else // ���� ����� �����
		{
			result->number = zeroN(); // ��������� ����������� ����
			result->sign = true; // �� ������ ����
		}
	}
	return result;
}
// Z-7
Z* SUB_ZZ_Z(Z* z1, Z* z2)
{
	Z* result = (Z*)malloc(sizeof(Z));
	if (z1->sign != z2->sign) // ���� ����� ���� ����� ������
	{
		result->number = ADD_NN_N(z1->number, z2->number); // ���������� �� ������ ����������� �������� ����� ���� �����
		result->sign = z1->sign; // ����������� ���������� ����� ���� ���� �����
	}
	else
	{
		int com = COM_NN_D(z1->number, z2->number);
		if (com == 2) // ���� ������ ����� ������ ������� �� ������
		{
			result->number = SUB_NN_N(z1->number, z2->number); // �������� �� �������� ����� �������
			result->sign = z1->sign; // ����������� ���������� ���� ������� �����
		}
		else if (com == 1) // ���� ������ ����� ������ ������� �� ������
		{
			result->number = SUB_NN_N(z2->number, z1->number); // ��������
			result->sign = !z2->sign;
		}
		else // ���� ����� �����
		{
			result->number = zeroN(); // ��������� ����������� ����
			result->sign = true; // �� ������ ����
		}
	}
	return result;
}
// Z-8
Z* MUL_ZZ_Z(Z* z1, Z* z2)
{
	Z* result = (Z*)malloc(sizeof(Z));
	result->number = MUL_NN_N(z1->number, z2->number); // ����������� ���������� �� ������ �������� ������������ ������� ����� �� ������ �� ������
	if (!POZ_Z_D(result)) // ���� �������� - 0
		result->sign = true; // �� ���� ���������� +
	else if (z1->sign == z2->sign) // ���� ����� ���� ����� �����
		result->sign = true; // �� ���� ���������� +
	else
		result->sign = false; // ���� ���������� -
	return result;
}
// Z-9
Z* DIV_ZN_Z(Z* z, N* n)
{
	Z* result = (Z*)malloc(sizeof(Z));
	result->number = DIV_NN_N(z->number, n); // ����� ��� ����������� ����� ������� (��������������� � �����) �� �������
	result->sign = z->sign; // ����������� ����� ���������� ���� �������� �����
	if (!POZ_Z_D(result)) // ���� ��������� ����� ����
		result->sign = true; // �� ���� ���� +
	N* mod = MOD_NN_N(z->number, n);
	if (!result->sign && NZER_N_B(mod))
	{
		Z* one = zeroZ();
		one->number->n[0] = 1;
		Z* temp = result;
		result = SUB_ZZ_Z(temp, one);
		freeZ(temp);
		freeZ(one);
	}
	freeN(mod);
	return result;
}
// Z-10
Z* MOD_ZN_Z(Z* z, N* n)
{
	Z* result = TRANS_N_Z(n); // ��������������� � ����� ������ �����
	Z* tmp = DIV_ZN_Z(z, n); // ��������� �� ������� ��� ������� ������� ����� �� ������
	Z* temp = MUL_ZZ_Z(tmp, result);
	freeZ(result);
	freeZ(tmp);
	result = SUB_ZZ_Z(z, temp); // �������� ����� �������� ������ ������ � �������������
	freeZ(temp);
	return result;
}
