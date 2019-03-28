#include "pch.h"
#include <iostream>
#include <clocale>
#include <cmath>

using namespace std;

double func(double x) {
	return 3 * sin(x) - 5 * x;
}

int main() {
	setlocale(LC_ALL, "");

	double a, b, h;
	cout << "Введите значение a: ";
	cin >> a;
	cout << "Введите значение b: ";
	cin >> b;
	cout << "Введите значение шага h: ";
	cin >> h;

	double min = func(a), arg;
	cout << "Табулирование функции: ";
	for (double i = a; i <= b; i += h) {
		double value_func = func(i);
		cout << value_func << endl;
		if (value_func < min) {
			min = value_func;
			arg = i;
		}
	}
	cout << endl << "Наименьшее значение функции = " << min << endl;
	cout << "Значение аргумента = " << arg << endl;
 
	return 0;
}
