#pragma once
// Q-1 ������� �����

Q* RED_Q_Q(Q* fraction) {
	N* d = GCF_NN_N(fraction->num->number, fraction->denom); // ����������� d �������� ���� (������ ��������� �����) � ����������� ����� 
	while (d->len != 1 or d->n[0] != 1) { // �� ��� ��� ���� d �� ������ ������ 1  
		fraction->num = DIV_ZZ_Z(fraction->num, d); // ��������� ��������� �� d
		fraction->denom = DIV_NN_N(fraction->denom, d); // ��������� ����������� �� d
		freeN(d);
		d = GCF_NN_N(fraction->num->number, fraction->denom); // ����������� d �������� ���� (������ ��������� �����) � ����������� �����  
	}
	freeN(d);
	return fraction;
}