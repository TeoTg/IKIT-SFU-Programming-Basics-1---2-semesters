#include "pch.h"
#include <iostream>
#include <string>
#include <clocale>

using namespace std;

void print_rect(int x, int y, int sx, int sy);

int main() {
	setlocale(LC_ALL, "rus");

	int x, y, sx, sy;

	cout << "Введите значение х: ";
	cin >> x;
	cout << "Введите значение y: ";
	cin >> y;
	cout << "Введите значение sх: ";
	cin >> sx;
	cout << "Введите значение sy: ";
	cin >> sy;

	print_rect(x, y, sx, sy);

	return 0;
}

void print_rect(int x, int y, int sx, int sy) {
	for (int i = 0; i < y; i++) {
		cout << endl;
	}
	for (int i = 1; i <= sy; i++) {
		for (int k = 0; k < x; k++) {
			cout << " ";
		}
		for (int j = 0; j < sx; j++) {
			cout << "@";
		}
		cout << endl;
	}
}