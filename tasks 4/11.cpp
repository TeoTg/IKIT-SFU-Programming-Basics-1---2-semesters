#include "pch.h"
#include <iostream>
#include <string>
#include <clocale>

using namespace std;

void print_diag(int s);

int main() {
	setlocale(LC_ALL, "rus");

	int s;
	cout << "Введите значение S: ";
	cin >> s;

	print_diag(s);

	return 0;
}

void print_diag(int s) {
	for (int i = 1; i <= s; i++) {
		cout.width(i);
		cout << "*" << endl;
	}
}