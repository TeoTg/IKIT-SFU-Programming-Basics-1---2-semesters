#include "pch.h"
#include <iostream>
#include <clocale>

using namespace std;

int main() {
	setlocale(LC_ALL, "rus");

	int i, x;

	cout << "Введите значение x: ";
	cin >> x;
	cout << "Значение х = " << x << endl;

	do {
		i = x;
		cout << "Введите х: ";
		cin >> x;
		if (x < i) {
			break;
		}
		else {
			cout << "Значение х = " << x << endl;
		}
	} while (i <= x);

	cout << "\nПрограмма завершилась." << endl;

	return 0;
}