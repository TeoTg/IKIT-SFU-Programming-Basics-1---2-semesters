#include "pch.h"
#include <iostream>
#include <clocale>

using namespace std;

int main() {
	setlocale(LC_ALL, "rus");

	float x, a, b, c, d;


	cout << "Введите границу а = ";
	cin >> a;
	cout << "Введите границу b = ";
	cin >> b;
	cout << "Введите границу c = ";
	cin >> c;
	cout << "Введите границу d = ";
	cin >> d;
	cout << "Введите число x = ";
	cin >> x;

	if (x >= a && x <= b || x >= c && x <= d) {
		cout << "X принадлежит объединению отрезков [a; b], [c; d]" << endl;
	} else {
		cout << "\nX не принадлежит объединению" << endl;
	}

	return 0;
}