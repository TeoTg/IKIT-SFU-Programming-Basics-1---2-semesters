/*8. Определить расстояние d между двумя точками на числовой плоскости с координатами (x1, y1), (x2, y2). 
Вычисление расстояния оформить как функцию float dist(float x1, float y1, float x2, float y2).
Проверочные значения: x1 = 0, y1 = 1, x2 = 3,5, y2 = 0,5 ⇨ d≈3,54.*/

#include "pch.h"
#include <iostream>
#include <clocale>

using namespace std;

float dist(float x1, float y1, float x2, float y2);

int main() {
	setlocale(LC_ALL, "rus");

	float x1, x2, y1, y2;

	cout << "Введите коортинаты точки (x1, y1): ";
	cin >> x1 >> y1;
	cout << "Введите коортинаты точки (x2, y2): ";
	cin >> x2 >> y2;

	float d = dist(x1, y1, x2, y2);
	cout.precision(3);
	cout << "\nРасстояние между двумя точками = " << d << endl;

	return 0;
}

float dist(float x1, float y1, float x2, float y2) {
	return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}