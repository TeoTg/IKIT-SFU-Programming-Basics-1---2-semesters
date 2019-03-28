#include "pch.h"
#include <iostream>
#include <clocale>

using namespace std;

int main() {
	setlocale(LC_ALL, "rus");

	int N;
	float x;

	cout << "Введите значение N: ";
	cin >> N;
	cout << "Введите значение Х: ";
	cin >> x;

	float P = 1, degree = 1;

	for (int i = 0; i < N; i++) {
		degree *= x;
		P *= 2 * degree;
	}

	cout << "\nP = " << P << endl;

	return 0;
}