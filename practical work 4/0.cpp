#include "pch.h"
#include <iostream>
#include <clocale>

using namespace std;

float f1(float x);
float f2(float x);

int main() {
	setlocale(LC_ALL, "");

	float x, y;

	cout << "Введите число х: ";
	cin >> x;

	y = f1(x) + f1(pow(x, 2)) + f2(x) + f2(x - 1);

	cout << "\nЗначение y = " << y << endl;

	return 0;
}

float f1(float x) {
	return x + 3.14;
}
float f2(float x) {
	return sqrt(pow(x, 2) + 2);
}