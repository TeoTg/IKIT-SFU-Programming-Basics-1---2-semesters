#include "pch.h"
#include <iostream>
#include <clocale>

using namespace std;

int find_most_frequent(int a, int b, int c, int d);

int main() {
	setlocale(LC_ALL, "rus");
	int a, b, c, d;

	cout << "Введите значение переменной a: ";
	cin >> a;
	cout << "Введите значение переменной b: ";
	cin >> b;
	cout << "Введите значение переменной c: ";
	cin >> c;
	cout << "Введите значение переменной d: ";
	cin >> d;

	if (a != 0 && a != 1 || b != 0 && b != 1 || c != 0 && c != 1 || d != 0 && d != 1) {
		cout << "Переменные могут принимать значения 0 или 1";
	}
	else {
		cout << "Ответ: " << find_most_frequent(a, b, c, d);
	}

	return 0;
}

int find_most_frequent(int a, int b, int c, int d) {
	int sum = a + b + c + d;
	if (sum < 2) {
		return 0;
	}
	else if (sum > 2) {
		return 1;
	}
	return -1;
}	
