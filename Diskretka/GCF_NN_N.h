#pragma once
// N-13

N* GCF_NN_N(N* a, N* b)
{
	N* First = assignmentN(a);
	N* Second = assignmentN(b);
	while (NZER_N_B(First) && NZER_N_B(Second))
	{
		if (COM_NN_D(First, Second) > 1) // ≈сли первое больше второго
			First = MOD_NN_N(First, Second); // Ќаходим остаток от делени€ первого на второе
		else
			Second = MOD_NN_N(Second, First); // »наче - остаток от делени€ второго на первое
	}
	if (COM_NN_D(First, Second) != 2)
		First = assignmentN(Second);
	freeN(Second);
	return First;
}