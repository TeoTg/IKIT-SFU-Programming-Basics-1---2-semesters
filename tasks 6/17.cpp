#include "pch.h"
#include <iostream>
#include <clocale>
#include <iomanip>

using namespace std;

double f(double x);

int main() {
	setlocale(LC_ALL, "rus");

	float a, b, s;
	cout << "Укажите начало отрезка: ";
	cin >> a;
	cout << "Укажите конец отрезка: ";
	cin >> b;
	cout << "Введите шаг s: ";
	cin >> s;

	for (double i = a; i <= b; i += s) {
		cout.width(15);
		cout.precision(3);
		cout << fixed << i;
	}
	cout << endl;
	for (double i = a; i <= b; i += s) {
		cout.width(15);
		cout.precision(3);
		cout << scientific << f(i);
	}

	return 0;
}

double f(double x) {
	return 5 * x + 2;
}