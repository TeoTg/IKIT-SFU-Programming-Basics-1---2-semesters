#include "pch.h"
#include <iostream>
#include <clocale>
#include <cmath>

using namespace std;

int main() {
	setlocale(LC_ALL, "rus");

	int a, b, c, x, x1, x2;

	cout << "Введите аргументы вида a^2x + bx + c" << endl;
	cout << "Введите значение a: ";
	cin >> a;
	cout << "Введите значение b: ";
	cin >> b;
	cout << "Введите значение c: ";
	cin >> c;

	float D;
	D = (b * b) - (4 * a * c);

	if (D > 0) {
		x1 = ((-b) - sqrt(D)) / (2 * a);
		x2 = ((-b) + sqrt(D)) / (2 * a);
		cout << "Первый корень уравнения = " << x1 << endl;
		cout << "Второй корень уравнения = " << x2 << endl;

		cout << "Проверка с х1 = " << (a * pow(x1, 2) + (b * x1) + c) << endl;
		cout << "Проверка с х2 = " << (a * pow(x2, 2) + (b * x2) + c) << endl;
	}
	else if (D == 0) {
		x = (-b) / (2 * a);
		cout << "Единственный корент уравнения = " << x;
		cout << "Проверка с х = " << a * x*x + b * x + c << endl;
	}
	else {
		cout << "Дискриминант меньше 0. Корней нет." << endl;
	}
	return 0;
}
