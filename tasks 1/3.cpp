#include "pch.h"
#include <iostream>
#include <clocale>
#include <math.h>

using namespace std;

int main() {
	setlocale(LC_ALL, "rus");

	int d;
	float x;

	cout << "Введите число х: ";
	cin >> x;

	x = abs(x * 10);
	d = int(floor(x)) % 10;

	cout << "Первая дробная цифра числа х = " << d << endl;
	
	return 0;
}