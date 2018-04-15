#pragma once
// Z-10

Z *MOD_ZZ_Z(Z *First, N *Second)
{
	Z *Result; // ������� �� �������
	Z *Temp; // ������������ �������� �� ��������
	Z *Rest; // ������� �� �������
	Result = DIV_ZZ_Z(First, Second);
	Temp = MUL_ZZ_Z(Result, TRANS_N_Z(Second));
	Rest = SUB_ZZ_Z(First, Temp);
	return Rest;
}