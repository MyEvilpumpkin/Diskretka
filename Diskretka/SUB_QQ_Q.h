#pragma once
// Q-6 Зерцалов Владимир

Q* SUB_QQ_Q(Q* f1, Q* f2) {
	Q* q = assignmentQ(f2);
	q->num->sign = !f2->num->sign;
	Q* result = ADD_QQ_Q(f1, q); // складываем первую дробь со второй * (-1)
	freeQ(q);
	return result;
}