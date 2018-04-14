#pragma once
// Z-6

Z ADD_ZZ_Z(Z num1, Z num2)
{
	N n1, n2;
	Z sum;
	n1 = ABS_Z_N(num1);	//������ �� ������� �����
	n2 = ABS_Z_N(num2);	//������ �� ������� �����
	if (POZ_Z_D(num1) == 2 || POZ_Z_D(num1) == 0)	//������ ����� ���� �������������, ���� '0'
		if (POZ_Z_D(num2) == 2 || POZ_Z_D(num2) == 0)	//������ ����� ���� �������������, ���� '0'
		{
			sum.number = &ADD_NN_N(n1, n2);
			sum.sign = num1.sign;
			return sum;
		}
		else
			if (COM_NN_D(n1, n2) == 2 || COM_NN_D(n1, n2) == 0)	//������ �����(�� ������) ������ �������, ���� ����� ���
			{
				sum.number = &SUB_NN_N(n1, n2);
				sum.sign = num1.sign;
				return sum;
			}
			else     //������ �����(�� ������) ������ �������
			{
				sum.number = &SUB_NN_N(n2, n1);
				sum.sign = num1.sign;
				sum = MUL_ZM_Z(sum);
				return sum;
			}
	else       //������ ����� �������������
		if (POZ_Z_D(num2) == 2 || POZ_Z_D(num2) == 0)	// ������ ����� ���� �������������, ���� '0'
			if (COM_NN_D(n1, n2) == 2 || COM_NN_D(n1, n2) == 0)//������ �����(�� ������) ������ �������, ���� ����� ���
			{
				sum.number = &SUB_NN_N(n1, n2);
				sum.sign = num2.sign;
				sum = MUL_ZM_Z(sum);
				return sum;
			}
			else   //������ �����(�� ������) ������ �������
			{
				sum.number = &ADD_NN_N(n1, n2);
				sum.sign = num1.sign;
				return sum;
			}
}