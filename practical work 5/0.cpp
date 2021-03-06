#include "pch.h"
#include <iostream>
#include <clocale>

using namespace std;

int main() {
	setlocale(LC_ALL, "rus");

	int N;
	cout << "Введите значение N: ";
	cin >> N;

	cout << "Вывод через for: " << endl;
	for (int i = 0; i <= N; i++) {
		cout << "Число " << i << endl;
	}

	int i = 0;
	cout << "\nВывод через do - while: " << endl;
	do {
		cout << "Число " << i << endl;
		i++;
	} while (i <= N);
	
	int j = 0;
	cout << "\nВывод через while: " << endl;
	while (j <= N) {
		cout << "Число " << j << endl;
		j++;
	}

	return 0;
}