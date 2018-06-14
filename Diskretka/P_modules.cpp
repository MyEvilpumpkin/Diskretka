#include "P_modules.h"

P* deNullP(P* p)
{
	int i;
	bool flag = true;
	for (i = p->len; i >= 0 && flag; i--) // ���� �� ��������� ������� ��� ���� ������ ����
		if (p->k[i]->num->number->len != 1 || p->k[i]->num->number->n[0] != 0) // ���� ����������� ����������� - �� ���� 
			flag = false; // �������� ����
	if (i == -1 && flag) {
		freeP(p);
		p = zeroP();
	}
	else {
		int len = p->len;
		p->len = i + 1; // ����������� ������� ���������� �� 1
		P* temp = assignmentP(p);
		p->len = len;
		freeP(p);
		p = assignmentP(temp);
		freeP(temp);
	}
	return p;
}

P* initP() {
	P* p = (P*)malloc(sizeof(P));
	p->k = (Q**)malloc(sizeof(Q*));
	p->k[0] = initQ();
	p->len = -1;
	return p;
}

P* inputP() {
	int *powerBuffer;
	int amount;
	int power;
	int maxPower = -1;
	P* p = (P*)malloc(sizeof(P));
	p->k = (Q**)malloc(sizeof(Q*));
	printf("������� ���������� �������������: ");
	do {
		amount = getNumber();
		if (amount == 0)
			printf("������� ������������ ������. ������� ����� > 0: ");
	} while (amount == 0);
	powerBuffer = (int*)malloc(amount * sizeof(int));
	for (int i = 0; i < amount; i++) {
		printf("***\n����������� %d\n", i + 1);
		Q* temp = inputQ();
		printf("������� ������� x: ");
		power = getNumber();
		if (power > maxPower) {
			maxPower = power;
			p->k = (Q**)realloc(p->k, (maxPower + 1) * sizeof(Q*));
			p->len = maxPower;
		}
		p->k[power] = assignmentQ(temp);
		freeQ(temp);
		powerBuffer[i] = power;
	}
	for (int i = maxPower; i >= 0; i--) {
		bool f = false;
		for (int j = 0; j < amount; j++)
			if (powerBuffer[j] == i) f = true;
		if (!f)
			p->k[i] = zeroQ();
	}
	free(powerBuffer);
	puts("");
	return p;
}

P* zeroP() {
	P* Result = (P*)malloc(sizeof(P));
	Result->k = (Q**)malloc(sizeof(Q*));
	Result->len = 0;
	Result->k[0] = zeroQ();
	return Result;
}

P* assignmentP(P* p) {
	P* a = (P*)malloc(sizeof(P));
	a->len = p->len;
	a->k = (Q**)malloc((a->len + 1) * sizeof(Q*));
	for (int i = 0; i <= a->len; i++)
		a->k[i] = assignmentQ(p->k[i]);
	return a;
}

void printP(P* p) {
	for (int i = p->len; i >= 0; i--) {
		if (!(p->k[i]->num->number->len == 1 && p->k[i]->num->number->n[0] == 0)) {
			if (i != p->len)
				if (p->k[i]->num->sign)
					printf("+ ");
			if (p->k[i]->num->number->len == 1 && p->k[i]->num->number->n[0] == 1 && i != 0 && p->k[i]->denom->len == 1 && p->k[i]->denom->n[0] == 1) {
				if (!p->k[i]->num->sign)
					printf("- ");
			}
			else {
				printQ(p->k[i]);
				if (i != 0)
					printf(" * ");
			}
			if (i > 1)
				printf("x^%d ", i);
			else if (i == 1)
				printf("x ");
		}
		else if (p->len == 0)
			printf("0");
	}
}

P* freeP(P* p) {
	for (int i = 0; i <= p->len; i++)
		freeQ(p->k[i]);
	free(p->k);
	free(p);
	return p;
}

// P-1 ����� ���������

P* ADD_PP_P(P* a, P* b)
{
	P* First, *Second;
	// ����������, � ������ ���������� ������� ������ �, ���� ����, �������� �� �������
	if (a->len > b->len) {
		First = assignmentP(a);
		Second = assignmentP(b);
	}
	else {
		First = assignmentP(b);
		Second = assignmentP(a);
	}
	P* Result = (P*)malloc(sizeof(P));
	Result->k = (Q**)malloc((First->len + 1) * sizeof(Q*)); // ����� �����������
	Result->len = First->len; // ������� ����� ����� ������� �������� �� �����������
	for (int i = First->len; i >= 0; i--) // ���� �� ������� ������� �������� ����� �� ��������� 
	{
		if (i > Second->len) // ���� ����������� ������� ������� ���������� ������ ������� �������
			Result->k[i] = assignmentQ(First->k[i]); // ����������� ����� ����������� ������� ���������� (�.�. � ������� �� � ������ ���)
		else
			Result->k[i] = ADD_QQ_Q(First->k[i], Second->k[i]); // ����� ���������� �������� �������������
	}
	freeP(First);
	freeP(Second);
	return deNullP(Result);
}

// P-2 ����� ���������

P* SUB_PP_P(P* First, P* Second)
{
	P* SecondCopy = assignmentP(Second); // �������� �������� ������� ����������
	for (int i = 0; i <= Second->len; i++)
		SecondCopy->k[i]->num->sign = !Second->k[i]->num->sign; // ������ ���� ������������� 2�� �������� (��� �����) 
	P* Result = ADD_PP_P(First, SecondCopy); // ��������� ������ ��������� � (-1)*������ ���������
	freeP(SecondCopy);
	return Result;
}

// P-3 ����� ���������

P* MUL_PQ_P(P* Polyn, Q* Numb)
{
	P* Result = (P*)malloc(sizeof(P));
	Result->k = (Q**)malloc((Polyn->len + 1) * sizeof(Q*));
	Result->len = Polyn->len;
	for (int i = 0; i <= Result->len; i++) // ���� �� �������� ������������ �� ��������
		Result->k[i] = MUL_QQ_Q(Polyn->k[i], Numb); // ����������� �������� ������������ ��������� ������������ �������� ������������ ���������
	return deNullP(Result); // ���������� �� ������������ �����
}

// P-4 ������� �������

P* MUL_Pxk_P(P* Polyn, int k) {
	P* Result = (P*)malloc(sizeof(P));
	Result->k = (Q**)malloc(sizeof(Q*));
	int i; // ��� �������� �������������
	Result->k = (Q**)realloc(Result->k, (Polyn->len + k + 1) * sizeof(Q*)); // ��������� ������
	Result->len = Polyn->len + k; // ����������� ������� ����������-���������� ����� ������� ��������� ���������� � ������� k
	for (i = Result->len; i >= k; i--) // ���� �� �������� ������������ ���������� �� ������� k
		Result->k[i] = assignmentQ(Polyn->k[i - k]); // ����������� �������� ������������ ����������-���������� ����������� ��������� ���������� "���������" �� k
	for (i = k - 1; i >= 0; i--) // ���� �� ������� k-1 �� �������� ������������ ����������
		Result->k[i] = zeroQ(); // ������� ��� ��������� �� ���� �������
	return Result;
}

// P-5 ����� �����

Q* LED_P_Q(P* p) {
	for (int i = p->len; i >= 0; i--) // ���� �� ������� ������� ���������� �� �������
		if (!(p->k[i]->num->number->len == 1 && p->k[i]->num->number->n[0] == 0)) // ���� ������� ����������� = 0
			return assignmentQ(RED_Q_Q(p->k[i])); // ���������� ����������� �������� ����� ������������
	return assignmentQ(RED_Q_Q(p->k[0])); // � ������� ������ ���������� ����������� �������� �������� ������������
}

// P-6 ��������� ������

N* DEG_P_N(P* p) {
	int power = 0; // ������� �������
	bool flag = true; // �������������� ���� ���� ��������
	for (int i = p->len; i >= 0 && flag; i--) // ���� �� �������� ������������ ���������� ��� ���� ������ ����
		if (!(p->k[i]->num->number->len == 1 && p->k[i]->num->number->n[0] == 0)) { // ���� ����������� ����������� = 0
			power = i; // ��������������� � �������� �������
			flag = false; // �������� ����
		}
	return intToN(power);
}

// P-7 �������� ��������

Q* FAC_P_Q(P* Polyn)
{
	N* NOD = assignmentN(Polyn->k[Polyn->len]->num->number); // ��� ����������, ���������� ����������� ��������, ������ ��������� �������� ������������ ����������
	N* NOK = assignmentN(Polyn->k[Polyn->len]->denom); // ��� ������������, ���������� ����������� ��������, ������ ����������� �������� ������������ ����������
	Q* Result = (Q*)malloc(sizeof(Q)); // ��������� ����� - ��� ����������, ����������� - ��� ������������
	Result->num = (Z*)malloc(sizeof(Z));
	N* temp;
	short i, // ��� �������� ������������� ����������
		Flag; // ��� ���������� ������ ����� 
	for (i = (Polyn->len) - 1; i >= 0; i--) { // ���������� ��� ������������ ����������, ������� � "������������" (�.�. ������� ����� � ��� ����������)
		temp = LCM_NN_N(NOK, Polyn->k[i]->denom); // ������� ���������� ��� ������ ��� � ������� ������������	
		freeN(NOK);
		NOK = assignmentN(temp);
		freeN(temp);
	}
	for (i = (Polyn->len) - 1; i >= 0; i--) // ���������� ��� ������������ ����������, ������� � "������������" (�.�. ������� ����� � ��� ����������)
	{
		Flag = POZ_Z_D(Polyn->k[i]->num); // �������� ������������ �� ����
		if (Flag != 0) {
			temp = GCF_NN_N(NOD, Polyn->k[i]->num->number); // ������� ���������� ��� ������ ��� � ������� ������������
			freeN(NOD);
			NOD = assignmentN(temp);
			freeN(temp);
		}

	}
	Result->num->number = assignmentN(NOD); // ����������� Result->num �������� NOD
	Result->num->sign = true;
	Result->denom = assignmentN(NOK); // ����������� Result->denom �������� ���
	freeN(NOD);
	freeN(NOK);
	return Result;
}

// P-8 ������� ����

P* MUL_PP_P(P* First, P* Second)
{
	int i = First->len; // ��� �������� ������������� ����������
	P* Result; // ��������� ���������
	P* Temp, *tmp; // ��������� ��������� ������� ���������� �� ����������� �������
	if (i > 0) {
		Temp = MUL_PQ_P(Second, First->k[i]); // �������� ������ ��������� ���������� �� ��� ������������ �������
		Result = MUL_Pxk_P(Temp, i); // �������� ������������ �� ������� ����������� ������� ������� ����������
		freeP(Temp);
		for (i = First->len - 1; i >= 0; i--) {
			Temp = MUL_PQ_P(Second, First->k[i]); // �������� ������ ��������� ���������� �� ��� ������������ �������
			tmp = MUL_Pxk_P(Temp, i); // �������� ������������ �� ������� ����������� ������� ������� ����������
			freeP(Temp);
			Temp = ADD_PP_P(Result, tmp); // ����������� � ���������� ������������
			freeP(Result);
			Result = assignmentP(Temp);
			freeP(Temp);
			freeP(tmp);
		}
	}
	else
		Result = zeroP();
	return Result;
}

// P-9 ������� ����

P* DIV_PP_P(P* First, P* Second)
{
	P* Result = (P*)malloc(sizeof(P)); // ������� �� ������� �����������
	P *Temp, *tmp; // ��������� ����������
	P* Part = assignmentP(First); // ������� �� �������
	int i; // ��� �������� �������������
	Q* Coef; // ����������� ��� ����������� ������� ����������
	Result->len = First->len - Second->len;
	Result->k = (Q**)malloc((Result->len + 1) * sizeof(Q*));
	if (Result->len < 0) {
		freeP(Result);
		Result = zeroP();
	}
	else
		for (i = First->len; i >= Second->len; i--)
		{
			if (i <= Part->len)
				Coef = DIV_QQ_Q(Part->k[i], Second->k[Second->len]); // ���������� ������������ ����� �������� � ����������
			else
				Coef = zeroQ();
			Result->k[i - Second->len] = assignmentQ(Coef); // ������� ��������� ����������� � ���� ������
			Temp = MUL_PQ_P(Second, Coef); // ��������� �������� �� "����������" �����������
			tmp = MUL_Pxk_P(Temp, (i - Second->len)); // ���������� � ����������� �������
			freeP(Temp);
			Temp = SUB_PP_P(Part, tmp); // �������� �� ������� ����� ��������, ���������� �� ��������
			freeP(tmp);
			freeP(Part);
			Part = assignmentP(Temp);
			freeP(Temp);
			freeQ(Coef);
		}
	freeP(Part);
	return Result;
}

// P-10 ������ ����

P* MOD_PP_P(P* a, P* b) //��������� �� ���� a, b, result � ���������� � result ������� �� ������� a �� b 
{
	P* result = DIV_PP_P(a, b); // ��������� ������� �������� ���������� �� ������� ��� �������
	P* temp = MUL_PP_P(result, b); // ������������ ���������� �� ������� � �������� ����������
	freeP(result);
	result = SUB_PP_P(a, temp); // �������� �������� ���������� � ������������
	freeP(temp);
	return result;
}

// P-11 ������ ����

P* GCF_PP_P(P* a, P* b)
{
	P* ost;
	P* first = assignmentP(a);
	P* second = assignmentP(b);
	P* temp;
	while ((second->len != 0 || NZER_N_B(second->k[0]->num->number)) && (first->len != 0 || NZER_N_B(first->k[0]->num->number))) // ���� ���� ��� ���������� - �� �������
	{
		if (first->len > second->len) { // ���� ������� ������� ���������� ������ ������� �������
			temp = MOD_PP_P(first, second); // ����������� ��� ������� �� ������� �����������
			freeP(first);
			first = assignmentP(temp); // ��������
			freeP(temp);
		}
		else {
			temp = MOD_PP_P(second, first);
			freeP(second);
			second = assignmentP(temp);
			freeP(temp);
		}
	}
	if (first->len > second->len) // ���� ������� ������� ���������� ��������� ������ �������
		ost = assignmentP(first); // ����������� ���������� (�������) �������� ������� ����������
	else
		ost = assignmentP(second); //��������
	freeP(first);
	freeP(second);
	return ost;
}

// P-12 ����� �����

P* DER_P_P(P* p) {
	//��������� ������ ��� ���������
	P* res = (P*)malloc(sizeof(P));
	res->k = (Q**)malloc(p->len * sizeof(Q*));
	res->len = p->len - 1;
	Z* temp;
	Q* tmp;
	//������ �������������
	for (int i = p->len - 1; i >= 0; i--) { // ���� �� �������� ������������ ����������
		N* iton = intToN(i + 1);
		temp = TRANS_N_Z(iton);
		freeN(iton);
		tmp = TRANS_Z_Q(temp);
		res->k[i] = MUL_QQ_Q(p->k[i + 1], tmp); //����������� �������� ������������ �������� 
		freeZ(temp); //(������������ ���������� ������������ � (��������������� � ������� ����� ������� ���������� ������������))
		freeQ(tmp);
	}
	return res;
}

// P-13 ������ ���������

P* NMR_P_P(P* a)
{
	P* Result = DER_P_P(a); // �������������� ��������� ����������� �� ��������� ����������
	P* Temp = GCF_PP_P(a, Result); // ����������� ���������� �������� ���� ��������� ���������� � ����������
	freeP(Result);
	Result = DIV_PP_P(a, Temp); // ������� �� ������� �����������  
	freeP(Temp);
	Q* q = zeroQ();
	q->num->number->n[0] = 1;
	Q* tmp = FAC_P_Q(Result);
	Q* tmpr = DIV_QQ_Q(q, tmp);
	Temp = assignmentP(Result);
	freeP(Result);
	Result = MUL_PQ_P(Temp, tmpr); // ����������� ���������� �������� ������������ (����������� �������� ���������� � 
	freeQ(tmp); // (����������� �� ���������� ��� ������������ ������������� � ��� ���������� � ������� -1))
	freeQ(tmpr);
	freeP(Temp);
	freeQ(q);
	return Result;
}
