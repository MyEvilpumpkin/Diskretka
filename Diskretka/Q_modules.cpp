#include "Q_modules.h"

Q* initQ() {
	Q* q = (Q*)malloc(sizeof(Q));
	q->num = initZ();
	q->denom = initN();
	return q;
}

Q* inputQ() {
	Q* q = (Q*)malloc(sizeof(Q));
	printf("������� ���������: ");
	q->num = inputZ();
	printf("������� �����������: ");
	bool error;
	do {
		error = false;
		q->denom = inputN();
		if (q->denom->len == 1 && q->denom->n[0] == 0) {
			error = true;
			freeN(q->denom);
			printf("������� ������������ ������. ������� ����������� > 0: ");
		}
	} while (error);
	return q;
}

Q* zeroQ() {
	Q* q = (Q*)malloc(sizeof(Q));
	q->num = (Z*)malloc(sizeof(Z));
	q->num->sign = true;
	q->num->number = zeroN();
	q->denom = zeroN();
	q->denom->n[0] = 1;
	return q;
}

Q* assignmentQ(Q* q) {
	Q* a = (Q*)malloc(sizeof(Q));
	a->num = assignmentZ(q->num);
	a->denom = assignmentN(q->denom);
	return a;
}

void printQ(Q* q) {
	if (!q->num->sign)
		printf("- ");
	printN(q->num->number);
	if (q->denom->len != 1 || q->denom->n[0] != 1) {
		printf("/");
		printN(q->denom);
	}
}

Q* freeQ(Q* q) {
	freeN(q->denom);
	freeZ(q->num);
	free(q);
	return q;
}

// Q-1 ������� �����

Q* RED_Q_Q(Q* fraction) {
	Q* temp;
	N* d = GCF_NN_N(fraction->num->number, fraction->denom); // ����������� d �������� ���� (������ ��������� �����) � ����������� ����� 
	while (d->len != 1 or d->n[0] != 1) { // �� ��� ��� ���� d �� ������ ������ 1  
		temp = (Q*)malloc(sizeof(Q));
		temp->num = DIV_ZN_Z(fraction->num, d); // ��������� ��������� �� d
		temp->denom = DIV_NN_N(fraction->denom, d); // ��������� ����������� �� d
		freeZ(fraction->num);
		fraction->num = (Z*)malloc(sizeof(Z));
		fraction->num->number = assignmentN(temp->num->number);
		fraction->num->sign = temp->num->sign;
		freeN(fraction->denom);
		fraction->denom = assignmentN(temp->denom);
		freeQ(temp);
		freeN(d);
		d = GCF_NN_N(fraction->num->number, fraction->denom); // ����������� d �������� ���� (������ ��������� �����) � ����������� �����  
	}
	freeN(d);
	return fraction;
}

// Q-2 ������� �����

bool INT_Q_B(Q* Numb)
{
	return (RED_Q_Q(Numb)->denom->len == 1 && RED_Q_Q(Numb)->denom->n[0] == 1); // ���������� ���������� ������������ � ���, ��� ����������� ����� = 1
}

// Q-3 ������� �����

Q* TRANS_Z_Q(Z* First)
{
	Q* Rez = (Q*)malloc(sizeof(Q));
	Rez->denom = zeroN();
	Rez->denom->n[0] = 1;
	Rez->num = (Z*)malloc(sizeof(Z));
	Rez->num->number = assignmentN(First->number); // ������������ ��������� ���������� �������� ������ �����
	Rez->num->sign = First->sign; // �������� ���� �����
	if (First->number->len == 1 && First->number->n[0] == 0) // ���� ����� ����� ����
		Rez->num->sign = true; // �� ����� ������������
	return Rez; // ��������� ��������
}

// Q-4 ������� �����

Z* TRANS_Q_Z(Q* First)
{
	return assignmentZ(RED_Q_Q(First)->num); // ���������� �������� ��������� ����������� ����� 
}

// Q-5 ������� �������

Q* ADD_QQ_Q(Q* f1, Q* f2) {
	Q* ans = (Q*)malloc(sizeof(Q));
	//������������ �������, � ����������� �����
	ans->denom = MUL_NN_N(f1->denom, f2->denom);
	Z* q1 = (Z*)malloc(sizeof(Z));
	q1->number = MUL_NN_N(f1->num->number, f2->denom); // ����������� �������� ����������� f1 ������������ ��������� f1 � ����������� f2 
	q1->sign = f1->num->sign; // �������� ���� ��������� f1
	Z* q2 = (Z*)malloc(sizeof(Z));
	q2->number = MUL_NN_N(f2->num->number, f1->denom); // ����������� �������� ����������� f2 ������������ ��������� f2 � ����������� f1
	q2->sign = f2->num->sign; // �������� ���� ��������� f2
	ans->num = ADD_ZZ_Z(q1, q2);
	freeZ(q1);
	freeZ(q2);
	return RED_Q_Q(ans); // c�������� �����
}

// Q-6 �������� ��������

Q* SUB_QQ_Q(Q* f1, Q* f2) {
	Q* q = assignmentQ(f2);
	q->num->sign = !f2->num->sign;
	Q* result = ADD_QQ_Q(f1, q); // ���������� ������ ����� �� ������ * (-1)
	freeQ(q);
	return result;
}

// Q-7 ������� �������

Q* MUL_QQ_Q(Q* First, Q* Second)
{
	Q* Result = (Q*)malloc(sizeof(Q));
	Result->denom = MUL_NN_N(First->denom, Second->denom); // ����������� ���������
	Result->num = MUL_ZZ_Z(First->num, Second->num); // ����������� �����������
	return RED_Q_Q(Result); // ��������� ���������
}

// Q-8 ������� ������

Q* DIV_QQ_Q(Q* First, Q* Second)
{
	Q* Result;
	if (Second->num->number->len == 1 && Second->num->number->n[0] == 0) // ���� ��������� = 0
		Result = zeroQ();
	else {
		Result = (Q*)malloc(sizeof(Q));
		Result->num = (Z*)malloc(sizeof(Z));
		Result->num->sign = First->num->sign == Second->num->sign; // ��������� ����� ���������� ������������ ������ ���� ����������
		Result->num->number = MUL_NN_N(First->num->number, Second->denom); // ��������� ��������� ���������� ������������ ������� ��������� � ������� �����������
		Result->denom = MUL_NN_N(First->denom, Second->num->number); // ��������� ����������� ���������� ������������ ������� ����������� � ������� ���������
	}
	return RED_Q_Q(Result);
}
