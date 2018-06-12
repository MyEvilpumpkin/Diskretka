#include "N_modules.h"

// ���� ��������������� ����� int
int getNumber()
{
	char* number = NULL;
	int toReturn;
	char symbol;
	int lenght = 0;
	bool error;
	do
	{
		lenght = 0;
		error = false;
		do
		{
			symbol = getchar();
			if (symbol >= '0' && symbol <= '9')
			{
				number = (char*)realloc(number, (lenght + 1) * sizeof(char));
				*(number + lenght) = symbol;
				lenght++;
			}
			else if (symbol != '\n')
				error = true;
		} while (symbol != '\n');
		if (error)
			printf("������� ������������ ������. ������� ��������������� �����: ");
	} while (error || lenght == 0);
	number = (char*)realloc(number, (lenght + 1) * sizeof(char));
	*(number + lenght) = '\0';
	toReturn = atoi(number);
	free(number);
	return toReturn;
}
// �������� ������ ����� � ������ �����
N* deNULL(N* n)
{
	if (n->len != 0)
	{
		int i = 1,
			l = n->len;
		for (int j = 0; j < l; j++)
			i = n->n[j] == 0 ? i : j + 1;
		n->n = (int*)realloc(n->n, i * sizeof(int));
		n->len = i;
	}
	return n;
}
// ������� �� int � N
N* intToN(int d)
{
	N* n = initN();
	int len = 0, buffer = d;
	while (buffer > 0)
	{
		buffer = buffer / 10;
		len++;
	}
	n->len = len;
	n->n = (int*)realloc(n->n, len * sizeof(int));
	for (int i = len - 1; i >= 0; i--)
	{
		n->n[len - 1 - i] = d % 10;
		d /= 10;
	}
	return n;
}
// ���� ����� N
N* input()
{
	char *symbol = (char*)malloc(sizeof(char));
	int *k = NULL, len = 0;
	N *n = initN();
	bool error = false;
	do
	{
		*symbol = getchar();
		if ('0' <= *symbol && *symbol <= '9')
		{
			k = (int*)realloc(k, (len + 1) * sizeof(int));
			k[len] = atoi(symbol);
			len++;
		}
		else if (*symbol != '\n')
			error = true;
		else if (!error && len == 0)
			n->len = 0;
	} while (*symbol != '\n');
	if (!error && len > 0)
	{
		n->n = (int*)realloc(n->n, len * sizeof(int));
		n->len = len;
		for (int i = 0; i < len; i++)
			n->n[i] = k[len - i - 1];
	}
	free(k);
	free(symbol);
	return n;
}
// �������������
N* initN()
{
	N* n = (N*)malloc(sizeof(N));
	n->n = (int*)malloc(sizeof(int));
	n->len = -1;
	return n;
}
// ����
N* inputN()
{
	N* n = initN();
	do
	{
		freeN(n);
		n = input();
		if (n->len == -1)
			printf("������� ������������ ������. ������� ����������� �����: ");
	} while (n->len < 1);
	n = deNULL(n);
	return n;
}
// ������������� � ����������
N* zeroN()
{
	N* n = initN();
	n->n[0] = 0;
	n->len = 1;
	return n;
}
// ������������
N* assignmentN(N* n)
{
	N* result = initN();
	result->n = (int*)realloc(result->n, n->len * sizeof(int));
	for (int i = 0; i < n->len; i++)
		result->n[i] = n->n[i];
	result->len = n->len;
	return result;
}
// �����
void printN(N* n)
{
	for (int i = n->len - 1; i >= 0; i--)
		printf("%d", n->n[i]);
}
// ������������ ������
N* freeN(N* n)
{
	free(n->n);
	free(n);
	return n;
}

// N-1
int COM_NN_D(N* n1, N* n2)
{
	if (n1->len > n2->len) // ���� ������ ����� ������ �������
		return 2;
	if (n1->len < n2->len) // ���� ������ ����� ������ �������
		return 1;
	else
	{
		for (int i = n1->len - 1; i >= 0; i--) // ���� �� ��������� �����
			if (n1->n[i] > n2->n[i]) // ���� ����� ������� ����� ������ ����� �������
				return 2;
			else if (n1->n[i] < n2->n[i]) // ��������
				return 1;
		return 0; // ���� ����� ���� ����� � ��� �� ����� ��������� ����� (����� �����)
	}
}
// N-2
bool NZER_N_B(N* n)
{
	return (n->len != 1 || n->n[0] != 0); // ����� ����� 0, ���� � ����� ���� ������ ���� ������ � �� ����� 0
}
// N-3
N* ADD_1N_N(N* n)
{
	N* result = assignmentN(n);
	if (result->n[0] != 9) // ���� ��������� ������ ����� �� ����� 9, �� ���������� � ���� �������
		result->n[0]++;
	else // ���� ��������� ������ ����� 9, �� �������� ��� � ��� ����������� ������� �� ���� � ���������� ������� � ������ �� ������� 
	{
		int count = 0;
		while (result->n[count] == 9)
			result->n[count++] = 0;
		if (count == result->len) // ���� � ����� ��� ����� �������, �� ���������� ������� ����� ������
		{
			result->len++; // ����������� ����� ����� �� 1
			result->n = (int*)realloc(result->n, result->len * sizeof(int));  // ������ ����� ������
			result->n[count] = 1; // �������� ������ ������� ����� �������
		}
		else
			result->n[count]++; // ���� � ����� �� ��� �������, �� ������ �� ������� ����������� �� �������
	}
	return result;
}
// N-4
N* ADD_NN_N(N* n1, N* n2)
{
	N* result;
	if (COM_NN_D(n1, n2) == 2) // ���� n1>n2
	{
		result = assignmentN(n1); // ����� ���������� � n1
		int size = n2->len; // ���� � n2 ������ �������� ��� � n1, �� ��� ����� �������� �������, ������� � n2->len+2
		for (int i = 0; i < size; i++)
		{
			result->n[i] += n2->n[i]; // ���������� ��������������� �������
			if (result->n[i]>9)	// ���� ��������� ������ 9, �� ���� ������� �� ������� �� 10 � ��������� ������� � ��������� ������
			{
				result->n[i] %= 10;
				int g = i;
				do
				{
					if (g == result->len - 1) // ���� ���������� ������� ���, �� �� ��������
					{
						result->n = (int*)realloc(result->n, ++result->len * sizeof(int));
						result->n[g + 1] = 1; // ���������� "�������" ������� ������������� �������
					}
					else
						result->n[g + 1]++; // � ������ ���� ��������� ������ ����������, �� ������������� �� �������
					result->n[g + 1] %= 10;
					g++;
				} while (result->n[g] % 10 == 0);
			}
		}
	}
	else // ���� n1<n2
	{
		result = assignmentN(n2); // ����� ���������� � n2
		int size = n1->len; // ���� � n1 ������ �������� ��� � n2, �� ��� ����� �������� �������, ������� � n1->len+2
		for (int i = 0; i < size; i++)
		{
			result->n[i] += n1->n[i]; // ���������� ��������������� �������
			if (result->n[i]>9)	// ���� ��������� ������ 9, �� ���� ������� �� ������� �� 10 � ��������� ������� � ��������� ������
			{
				result->n[i] %= 10;
				int g = i;
				do
				{
					if (g == result->len - 1) // ���� ���������� ������� ���, �� �� ��������
					{
						result->n = (int*)realloc(result->n, ++result->len * sizeof(int));
						result->n[g + 1] = 1; // ���������� "�������" ������� ������������� �������
					}
					else
						result->n[g + 1]++; // � ������ ���� ��������� ������ ����������, �� ������������� �� �������
					result->n[g + 1] %= 10;
					g++;
				} while (result->n[g] % 10 == 0); // � ������ ���� ��������� ������ ����������, �� ������������� �� �������
			}
		}
	}
	return result;
}
// N-5
N* SUB_NN_N(N* n1, N* n2)
{
	N* result = zeroN();
	bool temp = false;
	if (COM_NN_D(n1, n2) == 2) // �������� �� ������������ ��������� ������
	{
		result->n = (int*)realloc(result->n, n1->len * sizeof(int)); // ��������� ������ ��� ��������� ����� ����������
		result->len = n1->len;
		for (int i = 0; i < n1->len; i++) // ���� �� ����� �����
		{
			if (i < n2->len) // ���� ������� ������ ����� �������� ����� (����� "�������������" ���� �� �����)
			{
				if (n1->n[i] >= n2->n[i] + temp) // ���� ����� �������� ����� ������ ��� ����� ����� �������� �����
				{
					result->n[i] = n1->n[i] - n2->n[i] - temp; // �������� ������������ ���������
					temp = false;
				}
				else // ���� ����� �������� ����� ������ ����� �������� �����
				{
					result->n[i] = n1->n[i] + 10 - n2->n[i] - temp;
					temp = true;
				}
			}
			else
			{
				if (temp)
					if (n1->n[i] == 0)
						result->n[i] = 9;
					else
					{
						result->n[i] = n1->n[i] - temp;
						temp = false;
					}
				else
					result->n[i] = n1->n[i]; // ����� �� ������ � ������� �� ������, � ������ "������������" �� � ���������
			}
		}
		deNULL(result); // ����������� �������������� ���������� ����
	}
	return result;
}

// N-6

N* MUL_ND_N(N* a, int b)
{
	N* c = zeroN();
	int temp = 0, l = 0, temp2 = 0; //������������� ���� ��������� ���������� � ������� ������ ����������
	for (int i = 0; i < a->len; i++) //�� ��� ���, ���� �� �������� �����
	{
		c->n = (int*)realloc(c->n, (l + 1) * sizeof(int)); //��������� ������ ��� ������� �����
		c->n[i] = 0; //��������� ������ ��������� ����������
		temp = a->n[i] * b + temp2; //����������� ��������� ���������� ����� (������������ ����� ��������� ����� �� �����) � ������ ��������� ����������
		temp2 = 0;//��������� ������ ��������� ����������
		if (temp > 9) //���� ������������ ����� ��������� ����� �� ����� ������ 9
		{
			c->n[i] = temp % 10; //����������� ������� ����� ���������� ������� ������ ������ ��������� ����������
			temp2 = temp / 10; //����������� ������ ��������� ���������� ��� ��������� �������
		}
		else
			c->n[i] = temp; //����������� ������� ����� ������ ��������� ����������
		l++; //����������� ������� ������� ����������
	}
	if (temp2 != 0) { //���� ���� ����� ���������� ���������
		c->n = (int*)realloc(c->n, (l + 1) * sizeof(int)); //�������� ������ ��� ����� �����
		c->n[l] = temp2; //����������� ���� ����� ������ ��������� ����������
		l++; //����������� ������� ������� ���������� �� 1
	}
	c->len = l; //����������� ����� ���������� ������� �������
	c = deNULL(c);
	return c;
}

// N-7

N* MUL_Nk_N(N* a, int b)
{
	N* c = zeroN();
	int len = a->len + b; // �������������� ������ ������ ����� ��������� ����� � �������� ������� k
	c->n = (int*)realloc(c->n, len * sizeof(int)); // �������� ������ ��� ������ �����
	for (int i = 0; i < len; i++) // ���� �� ����� �����
	{
		if (i < b) // ���� ������� ������ ������ k
			c->n[i] = 0; // "���������" ���� ����� �� 10
		else
			c->n[i] = a->n[i - b]; // ����������� �� ����� ������� (�� k ������) ����� ��������� �����
	}
	c->len = len; // ����������� ����� ���������� ����� len
	c = deNULL(c);
	return c;
}

// N-8

N* MUL_NN_N(N* a, N* b)
{
	N* result = zeroN();
	N* temp, *tmp;
	for (int i = 0; i < b->len; i++) { // � ����������, ���������� ������� 0, � ������ ���� ����� ������������ i-�� ����� ������� �����������
		tmp = MUL_ND_N(a, b->n[i]);
		temp = MUL_Nk_N(tmp, i); // ���������� �� ������ ����������� � �� 10^i
		freeN(tmp);
		tmp = ADD_NN_N(result, temp);
		freeN(result);
		result = assignmentN(tmp);
		freeN(tmp);
		freeN(temp);
	}
	return result;
}

// N-9

N* SUB_NDN_N(N* a, int d, N* b)
{
	N* first, *second;
	N* result;
	N* temp;
	if (COM_NN_D(a, b) == 2) { // ���� ������ ����� ������ �������
		first = assignmentN(a); // ������������
		second = assignmentN(b);
	}
	else {
		first = assignmentN(b); // ������������
		second = assignmentN(a);
	}
	temp = MUL_ND_N(second, d); // ������� ��������� �� �����
	result = SUB_NN_N(first, temp); // �������� �� �������� ����� ������� (����������� �� �����)
	free(temp);
	freeN(first);
	freeN(second);
	return result;
}

// N-10

int DIV_NN_Dk(N* a, N* b, int& k)
{
	int Result = 1, // ������ ����� �������
		Flag; // ���������� ��� ������ �� �����
	N* Temp; // ��������� ���������� ��� �������� ������������
	k = 0;
	N* First, *Second;
	if (COM_NN_D(a, b) == 2) { // ���� ������� - ������ �����
		First = assignmentN(a); // ������� 
		Second = assignmentN(b); // ��������
	}
	else { // ��������
		First = assignmentN(b);
		Second = assignmentN(a);
	}
	do
	{
		Temp = MUL_Nk_N(Second, k); // �������� �������� �� 10^k
		Flag = COM_NN_D(First, Temp); // ���������� ������� � ������������
		freeN(Temp);
		if (Flag != 1) // ���� ������������ ������, �� ����������� ������� 10
			k++;
	} while (Flag != 1); // ���� ������������ �� ������ ������ ��������
	k--; // ��� ��� ��� ��������� ��������� k ����� ������ �� 1 �� ������������
	Temp = MUL_Nk_N(Second, k); // ��������� ���������� ������������ �������� � 10^k, ������� ��������
	do
	{
		N* tmp = MUL_ND_N(Temp, Result); // ��������� ������������ �� �����
		Flag = COM_NN_D(First, tmp); // ���������� ��� � �������
		if (Flag != 1) // ���� ������������ ������ ��������, ��������� ��������� �����
			Result++;
		freeN(tmp);
	} while (Flag != 1);
	Result--; // ���������� �������� �������
	freeN(Temp);
	freeN(First);
	freeN(Second);
	return Result;
}

// N-11

N* DIV_NN_N(N* a, N* b)
{
	N* First, *Second;
	if (COM_NN_D(a, b) == 2) {
		First = assignmentN(a);
		Second = assignmentN(b);
	}
	else {
		First = assignmentN(b);
		Second = assignmentN(a);
	}
	N* Result = zeroN(); // ������� �� �������
	N* Part = assignmentN(First); // ��������� ������� �� �������
	N* TempRes, *Temp; // ��������� ��������
	int Numb, // ������ ����� �� �������
		Flag, // ���������� ��� ������ �� �����
		k = 0; // ������� �������
	if (NZER_N_B(Second))
		do
		{
			Numb = DIV_NN_Dk(Part, Second, k); // ��������� ������ ����� � ������� ������� ��� �������
			TempRes = zeroN(); // 16 - 20 ������ - ��� �������� ������������� ������ ����� ������� �� 10^k
			Temp = ADD_1N_N(TempRes); // �������� 1 - ��� ��� ��� ��������� ��� ����� �� ����� ������ �� ���������
			freeN(TempRes);
			TempRes = MUL_ND_N(Temp, Numb); // �������� 1 �� ������ ����� �������
			freeN(Temp);
			Temp = MUL_Nk_N(TempRes, k); // �������� �� 10^k
			freeN(TempRes);
			TempRes = ADD_NN_N(Result, Temp); // ���������� ���������� ���������� � ������
			freeN(Result);
			Result = assignmentN(TempRes);
			freeN(TempRes);
			TempRes = MUL_NN_N(Temp, Second);
			freeN(Temp);
			Temp = SUB_NN_N(Part, TempRes); // ���������� ���������� �������
			freeN(Part);
			Part = assignmentN(Temp);
			freeN(Temp);
			Flag = COM_NN_D(Part, Second); // ���������� "�������" � ��������
			freeN(TempRes);
		} while (Flag != 1);
		freeN(Part);
		freeN(First);
		freeN(Second);
		return Result;
}

// N-12

N* MOD_NN_N(N* num, N* mod) {
	// num - (num div mod) * mod
	N* temp, *tmp, *result;
	temp = DIV_NN_N(num, mod); // ��������� �� ������� �������� ����� �� �������
	if (COM_NN_D(num, mod) == 2) {

		tmp = MUL_NN_N(temp, mod); // ������������ ��������� � �������� �����
		result = SUB_NN_N(num, tmp); // �������� �������� ����� � ������������
	}
	else {
		tmp = MUL_NN_N(temp, num); // ������������ ��������� � �������� �����
		result = SUB_NN_N(mod, tmp); // �������� �������� ����� � ������������
	}
	freeN(temp);
	freeN(tmp);
	return result;
}

// N-13

N* GCF_NN_N(N* a, N* b)
{
	N* First = assignmentN(a);
	N* Second = assignmentN(b);
	N* temp;
	while (NZER_N_B(First) && NZER_N_B(Second)) //���� ��� ����� - �� ����
	{
		if (COM_NN_D(First, Second) > 1) { // ���� ������ ������ �������
			temp = MOD_NN_N(First, Second); // ������� ������� �� ������� ������� �� ������
			freeN(First);
			First = assignmentN(temp);
			freeN(temp);
		}
		else {
			temp = MOD_NN_N(Second, First); // ����� - ������� �� ������� ������� �� ������
			freeN(Second);
			Second = assignmentN(temp);
			freeN(temp);
		}

	}
	if (COM_NN_D(First, Second) != 2) { // ���� ������ ����� - ������ �������
		freeN(First);
		First = assignmentN(Second); // ������ �� �������
	}
	freeN(Second);
	return First;
}

// N-14

N* LCM_NN_N(N* First, N* Second)
{
	N* NOD = GCF_NN_N(First, Second); // ��� ���� �����
	N* Temp = MUL_NN_N(First, Second); // ������������ ���� �����
	N* NOK = DIV_NN_N(Temp, NOD); // ��� ���� �����
	freeN(NOD);
	freeN(Temp);
	return NOK;
}
