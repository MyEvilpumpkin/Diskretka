#pragma once
// Q-2

bool INT_Q_B(Q Numb)
{
	Z Temp; // ������� �� ������� ��������� �� �����������
	N Module; // ������� �� ������
	bool Rez;
	Temp = MOD_ZZ_Z(*Numb.num, *Numb.denom);
	Module = ABS_Z_N(Temp);
	Rez = NZER_N_B(Module);
	return Rez;
}