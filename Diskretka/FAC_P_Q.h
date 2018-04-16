#pragma once
// P-7

Q* FAC_P_Q(P* Polyn)
{
	N* NOD = ABS_Z_N(Polyn->k[Polyn->len]->num); // ��� ����������, ���������� ����������� ��������, ������ ��������� �������� ������������ ����������
	N* Module; // ��������� ���������� - ������ ��������� ������������
	N* NOK = Polyn->k[Polyn->len]->denom; // ��� ������������, ���������� ����������� ��������, ������ ����������� �������� ������������ ����������
	Q* Result = initQ(); // ��������� ����� - ��� ����������, ����������� - ��� ������������
	short i, // ��� �������� ������������� ����������
		Flag; // ��� ���������� ������ ����� 
	for (i = (Polyn->len) - 1; i >= 0; i--) // ���������� ��� ������������ ����������, ������� � "������������" (�.�. ������� ����� � ��� ����������)
		NOK = LCM_NN_N(NOK, Polyn->k[i]->denom); // ������� ���������� ��� ������ ��� � ������� ������������		 
	for (i = (Polyn->len) - 1; i >= 0; i--) // ���������� ��� ������������ ����������, ������� � "������������" (�.�. ������� ����� � ��� ����������)
	{
		Flag = POZ_Z_D(Polyn->k[i]->num); // �������� ������������ �� ����
		if (Flag != 0)
		{
			Module = ABS_Z_N(Polyn->k[i]->num); // ��������� ��������� ������������ � �����������
			NOD = GCF_NN_N(NOD, Module); // ������� ���������� ��� ������ ��� � ������� ������������
		}
	}
	Result->num->number = assignmentN(NOD); // ����������� Result->num �������� NOD
	Result->num->sign = true;
	Result->denom = assignmentN(NOK); // ����������� Result->denom �������� ���
	// ���� �������������� ����������
	for (i = Polyn->len; i >= 0; i--) // ���������� ��� ������������ ����������
		Polyn->k[i] = DIV_QQ_Q(Polyn->k[i], Result); // ����� ������ ����������� �� ���������� �����
	return Result;
}