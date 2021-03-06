#include "pch.h"
#include <iostream>
#include <clocale>

using namespace std;

bool number_check(int number) {
	for (int j = 2; j * j <= number; j++) {
		if (number % j == 0) {
			return false;
		}
	}
	return true;
}

int main() {
	setlocale(LC_ALL, "rus");

	int N;
	cout << "Введите значение числа N: ";
	cin >> N;

	cout << "\nПростые числа < N: " << endl;
	for (int i = 2; i < N; i++) {
		if (number_check(i)) {
			cout << i << endl;
		}
	}	

	return 0;
}