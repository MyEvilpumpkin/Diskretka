#pragma once
// Q-6

Q* SUB_QQ_Q(Q* f1, Q* f2) {
	Q* q = initQ();
	q->denom = assignmentN(f2->denom);
	q->num->number = assignmentN(f2->num->number);
	q->num->sign = !f2->num->sign;
	return ADD_QQ_Q(f1, q);
}