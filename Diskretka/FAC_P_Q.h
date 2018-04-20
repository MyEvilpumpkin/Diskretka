#pragma once
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