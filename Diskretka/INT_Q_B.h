#pragma once
// Q-2

bool INT_Q_B(Q* Numb)
{
	return (RED_Q_Q(Numb)->denom->len == 1 && RED_Q_Q(Numb)->denom->n[0] == 1);
}