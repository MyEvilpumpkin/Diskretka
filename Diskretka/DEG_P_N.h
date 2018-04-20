#pragma once
// P-6 Тюльников Виктор

N* DEG_P_N(P* p) {
	int power = 0; // счётчик степени
	bool flag = true; // инициализируем флаг каак поднятый
	for (int i = p->len; i >= 0 && flag; i--) // цикл до младшего коэффициента многочлена или пока поднят флаг
		if (!(p->k[i]->num->number->len == 1 && p->k[i]->num->number->n[0] == 0)) { // если исследуемый коэффициент = 0
			power = i; // останавливаемся в подсчёте степени
			flag = false; // опускаем флаг
		}
	return intToN(power);
}