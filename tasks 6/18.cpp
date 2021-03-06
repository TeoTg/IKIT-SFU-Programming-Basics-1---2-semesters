#include "pch.h"
#include <iostream>
#include <clocale>
#include <iomanip>

using namespace std;

double f(double x);

int main() {
	setlocale(LC_ALL, "rus");

	double a, b, s;
	cout << "Укажите начало отрезка: ";
	cin >> a;
	cout << "Укажите конец отрезка: ";
	cin >> b;
	cout << "Введите шаг s: ";
	cin >> s;
	int scale;
	cout << "Введите масштабный коэффициент: ";
	cin >> scale;

	for (double i = a; i <= b; i += s) {
		cout.setf(ios::right);
		cout << setw(ceil(scale * f(i))) << "$" << "(" << i << ", " << f(i) << ")" << endl;
	}
	
	return 0;
}

double f(double x) {
	static const double pi = acos(-1);
	return pow(sin(pi*x), 2);
}