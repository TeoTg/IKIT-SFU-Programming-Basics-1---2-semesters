#include "pch.h"
#include <iostream>
#include <clocale>

using namespace std;

int main() {
	setlocale(LC_ALL, "rus");

	int n;
	cout << "Введите число n: ";
	cin >> n;

	double S = 1;

	for (int i = 0; i < n; i++) {
		S += (i + 1) / (i + 2.);
	}

	cout << "Сумма ряда = " << S << endl;

	return 0;
}