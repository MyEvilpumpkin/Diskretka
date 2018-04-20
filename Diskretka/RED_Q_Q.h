#pragma once
// Q-1 ������� �����

Q* RED_Q_Q(Q* fraction) {
	Q* temp;
	N* d = GCF_NN_N(fraction->num->number, fraction->denom); // ����������� d �������� ���� (������ ��������� �����) � ����������� ����� 
	while (d->len != 1 or d->n[0] != 1) { // �� ��� ��� ���� d �� ������ ������ 1  
		temp = (Q*)malloc(sizeof(Q));
		temp->num = DIV_ZZ_Z(fraction->num, d); // ��������� ��������� �� d
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
