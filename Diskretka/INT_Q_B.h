#pragma once
// Q-2 ћищенко јлина

bool INT_Q_B(Q* Numb)
{
	return (RED_Q_Q(Numb)->denom->len == 1 && RED_Q_Q(Numb)->denom->n[0] == 1); // возвращаем истинность высказывани€ о том, что знаменатель дроби = 1
}