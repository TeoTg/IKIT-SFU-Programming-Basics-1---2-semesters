#include "pch.h"
#include <iostream>
#include <clocale>

using namespace std;

int main() {
	setlocale(LC_ALL, "rus");

	int a, b;

	cout << "Введите число а: " << endl;
	cin >> a;
	cout << "Введите число b: " << endl;
	cin >> b;

	cout << "Вы ввели: а = " << a << " и b = " << b << endl;

	a = a + b;
	b = b - a;
	b = -b; // b = -(b - a)
	a = a - b;

	cout << "Результат: а = " << a << " и b = " << b << endl;

	return 0;
}