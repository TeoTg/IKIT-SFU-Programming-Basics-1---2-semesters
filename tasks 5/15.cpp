#include "pch.h"
#include <iostream>
#include <clocale>

using namespace std;

int main() {
	setlocale(LC_ALL, "rus");

	int N;
	cout << "Введите значение N: ";
	cin >> N;

	int S = 0; 
	int n = 1;
	for (int i = 1; i <= N; i++) {
		n = -n;
		S += i * n;
	}

	cout << "\nОтвет: S = " << S << endl;

	return 0;
}