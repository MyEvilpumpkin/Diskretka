#pragma once
// N-13 ќранска€ ћари€

N* GCF_NN_N(N* a, N* b)
{
	N* First = assignmentN(a);
	N* Second = assignmentN(b);
	N* temp;
	while (NZER_N_B(First) && NZER_N_B(Second)) //пока оба числа - не нули
	{
		if (COM_NN_D(First, Second) > 1) { // ≈сли первое больше второго
			temp = MOD_NN_N(First, Second); // Ќаходим остаток от делени€ первого на второе
			freeN(First);
			First = assignmentN(temp);
			freeN(temp);
		}
		else {
			temp = MOD_NN_N(Second, First); // »наче - остаток от делени€ второго на первое
			freeN(Second);
			Second = assignmentN(temp);
			freeN(temp);
		}
			
	}
	if (COM_NN_D(First, Second) != 2) { // если первое число - больше второго
		freeN(First);
		First = assignmentN(Second); // мен€ем их местами
	}
	freeN(Second);
	return First;
}