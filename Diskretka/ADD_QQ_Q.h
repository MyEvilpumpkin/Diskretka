#pragma once
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