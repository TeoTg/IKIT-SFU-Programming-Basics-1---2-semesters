#include "pch.h"
#include <iostream>
#include <clocale>
#include <cmath>

using namespace std;

float f1(float x) {
	return 100. / (2 * pow(x, 2) + 1);
}
float f2(float x) {
	return cbrt(50 * cos(pow(x, 2))) + 2.13e5;
}

int main() {
	setlocale(LC_ALL, "rus");

	float x;

	cout << "Введите число х: ";
	cin >> x;

	cout.precision(15);
	cout << "\nЗначение y = " << f1(x) + f2(x) << endl;

	return 0;
}