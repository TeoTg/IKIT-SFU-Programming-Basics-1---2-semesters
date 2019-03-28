#include "pch.h"
#include <iostream>
#include <clocale>

using namespace std;

double ai(int i);

int main() {
	setlocale(LC_ALL, "rus");

	int N;
	cout << "Введите значение числа N: ";
	cin >> N;

	double s = 0;
	for (int i = 1; i <= N; i++) {
		s += ai(i);
	}

	cout.precision(3);
	cout << "Сумма = " << s << endl;

	return 0;
}

double ai(int i) {
	return i / (i + 1.);
}