#include "N_modules.h"

// ���� ��������������� ����� int
int getNumber()
{
	char* number = NULL, symbol;
	int toReturn, lenght = 0;
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
				number[lenght++] = symbol;
			}
			else if (symbol != '\n')
				error = true;
		} while (symbol != '\n');
		if (error)
			printf("������� ������������ ������. ������� ��������������� �����: ");
	} while (error || lenght == 0);
	number = (char*)realloc(number, (lenght + 1) * sizeof(char));
	number[lenght] = '\0';
	toReturn = atoi(number);
	free(number);
	return toReturn;
}
// �������� ������ ����� � ������ �����
N* deNullN(N* n)
{
	if (n->len > 1)
	{
		int i;
		bool flag = false;
		for (i = n->len - 1; i >= 0 && !flag; i--)
			flag = n->n[i];
		n->n = (int*)realloc(n->n, (i + 2) * sizeof(int));
		n->len = i + 2;
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
			k[len++] = atoi(symbol);
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
	N* n;
	do
	{
		n = input();
		if (n->len == -1) {
			printf("������� ������������ ������. ������� ����������� �����: ");
			freeN(n);
		}
	} while (n->len < 1);
	deNullN(n);
	return n;
}
// ������������� � ����������
N* zeroN()
{
	N* n = (N*)malloc(sizeof(N));
	n->n = (int*)malloc(sizeof(int));
	n->n[0] = 0;
	n->len = 1;
	return n;
}
// ������������
N* assignmentN(N* n)
{
	N* result = (N*)malloc(sizeof(N));
	result->n = (int*)malloc(n->len * sizeof(int));
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
	else if (n1->len < n2->len) // ���� ������ ����� ������ �������
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
			result->n = (int*)realloc(result->n, ++result->len * sizeof(int));  // ������ ����� ������
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
	N* result = (N*)malloc(sizeof(N));
	int temp = 0;
	if (COM_NN_D(n1, n2) == 2) // ���� n1>n2
	{
		result->n = (int*)malloc(n1->len * sizeof(int));
		result->len = n1->len;
		for (int i = 0; i < n1->len; i++)
		{
			if (i < n2->len)
			{
				result->n[i] = n1->n[i] + n2->n[i] + temp; // ���������� ��������������� �������
				temp = result->n[i] / 10;
				result->n[i] %= 10; // ���������� ������
			}
			else if(temp)
			{
				result->n[i] = n1->n[i] + temp; // ����������� ��������������� �������
				temp = result->n[i] / 10;
				result->n[i] %= 10; // ���������� ������
			}
			else
				result->n[i] = n1->n[i];
		}
		if (temp) // ������� ������, ���� �����
		{
			result->n = (int*)realloc(result->n, ++result->len * sizeof(int));
			result->n[result->len - 1] = temp;
		}
	}
	else // ���� n1<n2
	{
		result->n = (int*)malloc(n2->len * sizeof(int));
		result->len = n2->len;
		for (int i = 0; i < n2->len; i++)
		{
			if (i < n1->len)
			{
				result->n[i] = n1->n[i] + n2->n[i] + temp; // ���������� ��������������� �������
				temp = result->n[i] / 10;
				result->n[i] %= 10; // ���������� ������
			}
			else if (temp)
			{
				result->n[i] = n2->n[i] + temp; // ����������� ��������������� �������
				temp = result->n[i] / 10;
				result->n[i] %= 10; // ���������� ������
			}
			else
				result->n[i] = n2->n[i];
		}
		if (temp) // ������� ������, ���� �����
		{
			result->n = (int*)realloc(result->n, ++result->len * sizeof(int));
			result->n[result->len - 1] = temp;
		}
	}
	return result;
}
// N-5
N* SUB_NN_N(N* n1, N* n2)
{
	N* result;
	bool temp = false;
	if (COM_NN_D(n1, n2) == 2) // �������� �� ������������ ��������� ������
	{
		result = (N*)malloc(sizeof(N));
		result->n = (int*)malloc(n1->len * sizeof(int)); // ��������� ������ ��� ��������� ����� ����������
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
		deNullN(result); // ����������� �������������� ���������� ����
	}
	else
		result = zeroN();
	return result;
}
// N-6
N* MUL_ND_N(N* n, int d)
{
	N* result;
	if (!d)
		result = zeroN();
	else if (d == 1)
		result = assignmentN(n);
	else
	{
		result = (N*)malloc(sizeof(N));
		result->len = n->len;
		result->n = (int*)malloc(result->len * sizeof(int));
		int temp = 0;
		for (int i = 0; i < n->len; i++)
		{
			result->n[i] = n->n[i] * d + temp; // ������������� ��������� = ������ * ����� + �������
			temp = result->n[i] / 10; // ���������� �������
			result->n[i] = result->n[i] % 10; // ���������� ������
		}
		if (temp) // ������ ��� ���� ������, ���� ������� �� 0
		{
			result->n = (int*)realloc(result->n, ++result->len * sizeof(int));
			result->n[result->len - 1] = temp;
		}
	}
	return result;
}
// N-7
N* MUL_Nk_N(N* n, int k)
{
	N* result = (N*)malloc(sizeof(N));
	result->len = n->len + k; // �������������� ������ ������ ����� ��������� ����� � �������� ������� k
	result->n = (int*)malloc(result->len * sizeof(int)); // �������� ������ ��� ������ �����
	for (int i = 0; i < result->len; i++) // ���� �� ����� �����
		if (i < k) // T��� ������� ������ ������ k
			result->n[i] = 0; // "���������" ���� ����� �� 10
		else
			result->n[i] = n->n[i - k]; // ����������� �� ����� ������� (�� k ������) ����� ��������� �����
	result = deNullN(result);
	return result;
}
// N-8
N* MUL_NN_N(N* n1, N* n2)
{
	N *result = zeroN(), *temp, *tmp;
	for (int i = 0; i < n2->len; i++) // � ����������, ���������� ������� 0, � ������ ���� ����� ������������ i-�� ����� ������� �����������
	{
		tmp = MUL_ND_N(n1, n2->n[i]);
		temp = MUL_Nk_N(tmp, i); // ���������� �� ������ ����������� � �� 10^i
		freeN(tmp);
		tmp = ADD_NN_N(result, temp);
		freeN(result);
		freeN(temp);
		result = tmp;
	}
	return result;
}
// N-9
N* SUB_NDN_N(N* n1, int d, N* n2)
{
	N *result, *temp;
	if (COM_NN_D(n1, n2) == 2) // ���� ������ ����� ������ �������
	{
		temp = MUL_ND_N(n2, d); // ������� ��������� �� �����
		result = SUB_NN_N(n1, temp); // �������� �� �������� ����� ������� (����������� �� �����)
	}
	else
	{
		temp = MUL_ND_N(n1, d); // ������� ��������� �� �����
		result = SUB_NN_N(n2, temp); // �������� �� �������� ����� ������� (����������� �� �����)
	}
	freeN(temp);
	return result;
}
// N-10
int DIV_NN_Dk(N* n1, N* n2, int& k)
{
	int result = 1, flag;
	N* temp;
	k = 0;
	if (COM_NN_D(n1, n2) == 2) // ���� ������� - ������ �����
	{
		k = n1->len - n2->len;
		temp = MUL_Nk_N(n2, k);
		if (COM_NN_D(n1, temp) == 1)
		{
			freeN(temp);
			temp = MUL_Nk_N(n2, --k); // ��������� ���������� ������������ �������� � 10^k, ������� ��������
		}
		do
		{
			N* tmp = MUL_ND_N(temp, ++result); // ��������� ������������ �� �����
			flag = COM_NN_D(n1, tmp); // ���������� ��� � �������
			freeN(tmp);
		} while (flag != 1);
		result--; // ���������� �������� �������
		freeN(temp);
	}
	else if (COM_NN_D(n1, n2) == 1) // ���� ������� - ������ �����
	{
		k = n2->len - n1->len;
		temp = MUL_Nk_N(n1, k);
		if (COM_NN_D(n2, temp) == 1)
		{
			freeN(temp);
			temp = MUL_Nk_N(n1, --k); // ��������� ���������� ������������ �������� � 10^k, ������� ��������
		}
		do
		{
			N* tmp = MUL_ND_N(temp, ++result); // ��������� ������������ �� �����
			flag = COM_NN_D(n2, tmp); // ���������� ��� � �������
			freeN(tmp);
		} while (flag != 1);
		result--; // ���������� �������� �������
		freeN(temp);
	}
	return result;
}
// N-11
N* DIV_NN_N(N* n1, N* n2)
{
	N* result = zeroN(); // ������� �� �������
	N *tempRes, *temp;
	if (COM_NN_D(n1, n2) == 2)
	{
		N* part = assignmentN(n1); // ��������� ������� �� �������
		int k = 0;
		if (NZER_N_B(n2))
			do
			{
				tempRes = zeroN(); // C������� ������������ ������ ����� ������� �� 10^k
				tempRes->n[0] = DIV_NN_Dk(part, n2, k); // ��������� ������ ����� � ������� ������� ��� �������
				temp = MUL_Nk_N(tempRes, k); // �������� �� 10^k
				freeN(tempRes);
				tempRes = ADD_NN_N(result, temp); // ���������� ���������� ���������� � ������
				freeN(result);
				result = tempRes;
				tempRes = MUL_NN_N(temp, n2);
				freeN(temp);
				temp = SUB_NN_N(part, tempRes); // ���������� ���������� �������
				freeN(part);
				part = temp;
				freeN(tempRes);
			} while (COM_NN_D(part, n2) != 1);
			freeN(part);
	}
	else
	{
		N* part = assignmentN(n2); // ��������� ������� �� �������
		int k = 0;
		if (NZER_N_B(n1))
			do
			{
				tempRes = zeroN(); // C������� ������������ ������ ����� ������� �� 10^k
				tempRes->n[0] = DIV_NN_Dk(part, n1, k); // ��������� ������ ����� � ������� ������� ��� �������
				temp = MUL_Nk_N(tempRes, k); // �������� �� 10^k
				freeN(tempRes);
				tempRes = ADD_NN_N(result, temp); // ���������� ���������� ���������� � ������
				freeN(result);
				result = tempRes;
				tempRes = MUL_NN_N(temp, n1);
				freeN(temp);
				temp = SUB_NN_N(part, tempRes); // ���������� ���������� �������
				freeN(part);
				part = temp;
				freeN(tempRes);
			} while (COM_NN_D(part, n1) != 1);
			freeN(part);
	}
	return result;
}
// N-12
N* MOD_NN_N(N* n1, N* n2)
{
	N *temp, *tmp, *result;
	temp = DIV_NN_N(n1, n2); // ��������� �� ������� �������� ����� �� �������
	if (COM_NN_D(n1, n2) == 2)
	{
		tmp = MUL_NN_N(temp, n2); // ������������ ��������� � �������� �����
		result = SUB_NN_N(n1, tmp); // �������� �������� ����� � ������������
	}
	else
	{
		tmp = MUL_NN_N(temp, n1); // ������������ ��������� � �������� �����
		result = SUB_NN_N(n2, tmp); // �������� �������� ����� � ������������
	}
	freeN(temp);
	freeN(tmp);
	return result;
}
// N-13
N* GCF_NN_N(N* n1, N* n2)
{
	N *result, *temp;
	N* first = assignmentN(n1);
	N* second = assignmentN(n2);
	while (NZER_N_B(first) && NZER_N_B(second)) // ���� ��� ����� - �� ����
	{
		if (COM_NN_D(first, second) > 1) // ���� ������ ������ �������
		{
			temp = MOD_NN_N(first, second); // ������� ������� �� ������� ������� �� ������
			freeN(first);
			first = temp;
		}
		else
		{
			temp = MOD_NN_N(second, first); // ����� - ������� �� ������� ������� �� ������
			freeN(second);
			second = temp;
		}
	}
	if (COM_NN_D(first, second) != 2) // ���� ������ ����� - ������ �������
	{
		result = second;
		freeN(first);
	}
	else
	{
		result = first;
		freeN(second);
	}
	return result;
}
// N-14
N* LCM_NN_N(N* n1, N* n2)
{
	N* nod = GCF_NN_N(n1, n2); // ��� ���� �����
	N* temp = MUL_NN_N(n1, n2); // ������������ ���� �����
	N* nok = DIV_NN_N(temp, nod); // ��� ���� �����
	freeN(nod);
	freeN(temp);
	return nok;
}
