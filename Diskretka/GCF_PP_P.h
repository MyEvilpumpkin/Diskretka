#pragma once
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