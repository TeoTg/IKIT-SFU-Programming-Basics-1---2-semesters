/*9. Даны действительные числа a, b, c. Если a больше 0,5, вывести большее из чисел b, c. 
Иначе вывести меньшее из чисел b, c. Вычисление оформить как функцию float min_or_max(float a, float b, float c).
Проверочные значения: 1) a = −1,1, b = −2, c = 1,1⇨ −2; 2) a = 0,6, b = −2, c = 1,1⇨ 1,1.*/

#include "pch.h"
#include <iostream>
#include <clocale>
#include <algorithm>

using namespace std;

float min_or_max(float a, float b, float c);

int main() {
	setlocale(LC_ALL, "rus");

	float a, b, c;

	cout << "Введите значение числа a: ";
	cin >> a;
	cout << "Введите значение числа b: ";
	cin >> b;
	cout << "Введите значение числа c: ";
	cin >> c;

	cout << "\nОтвет: " << min_or_max(a, b, c);

	return 0;
}

float min_or_max(float a, float b, float c) {
	if (a > 0.5) {
		return max(b, c);
	}
	else {
		return min(b, c);
	}
}