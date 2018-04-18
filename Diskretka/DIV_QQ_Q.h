#pragma once
// Q-8

Q* DIV_QQ_Q(Q* First, Q* Second)
{
	N* Temp1 = ABS_Z_N(First->num); // ����������� ������������� ������� ���������
	N* Temp2 = ABS_Z_N(Second->num); // ����������� ������������� ������� ���������
	Q* Result = initQ(); // ��������� ���������
	if (Temp2->len == 1 && Temp2->n[0] == 0)
		Result = zeroQ();
	else {
		Result->num->sign = First->num->sign == Second->num->sign;
		Result->num->number = MUL_NN_N(Temp1, Second->denom);
		Result->denom = MUL_NN_N(First->denom, Temp2);
	}
	return RED_Q_Q(Result);
}