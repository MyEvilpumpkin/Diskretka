#pragma once
// Q-6

Q* ADD_QQ_Q(Q* f1, Q* f2) {
	Q* ans = initQ();
	//��� �������, � ����������� �����
	ans->denom = LCM_NN_N(f1->denom, f2->denom);
	//��� ���� q1 = ��� / ����������� ����� f1
	Z* q1 = initZ();
	q1->number = DIV_NN_N(ans->denom, f1->denom); 
	q1->sign = true;
	Z* q2 = initZ();
	q2->number = DIV_NN_N(ans->denom, f2->denom);
	q2->sign = true;
	//��������� ����� f1->num * q1 + f2->num * q2
	ans->num = ADD_ZZ_Z(MUL_ZZ_Z(f1->num, q1), MUL_ZZ_Z(f2->num, q2));
	//��������� �����
	return RED_Q_Q(ans);
}