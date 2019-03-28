#include "pch.h"
#include <iostream>
#include <clocale>

using namespace std;

void transpose(int **arr, size_t size) {
	for (size_t i = 0, j = 0; j < size - 1; j++, i++) {
		for (size_t j = i; j < size; j++) {
			int t = arr[i][j];
			arr[i][j] = arr[j][i];
			arr[j][i] = t;
		}
	}
}

int main() {
	setlocale(LC_ALL, "");

	size_t size;
	cout << "Введите значение size: ";
	cin >> size;

	int **arr = new int *[size];
	for (size_t i = 0; i < size; i++) {
		arr[i] = new int[size];
	}
	cout << "Заполните массив arr: ";
	for (size_t i = 0; i < size; i++) {
		for (size_t j = 0; j < size; j++) {
			cin >> arr[i][j];
		}
	}
	transpose(arr, size);
	cout << endl << "Новый массив: ";
	for (size_t i = 0; i < size; i++) {
		cout << endl;
		for (size_t j = 0; j < size; j++) {
			cout << " " << arr[i][j];
		}
	}

	return 0;
}