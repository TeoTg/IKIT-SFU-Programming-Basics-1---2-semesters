#include "pch.h"
#include <iostream>
#include <clocale>
#include <cstring>
#include <fstream>

using namespace std;

void print_transposed(const int* const *arr, size_t size, ostream &ost) {
	for (size_t i = 0; i < size; i++) {
		ost << endl;
		for (size_t j = 0; j < size; j++) {
			ost << " " << arr[j][i];
		}
	}
}

int main() {
	setlocale(LC_ALL, "");

	size_t size;
	cout << "Введите значение size: ";
	cin >> size;

	ofstream ost("1.txt", ios::out);
	if (!ost.is_open()) {
		cout << "Не удалось открыть файл! " << endl;
		return -1;
	}

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
	cout << "Текущий массив: ";
	for (size_t i = 0; i < size; i++) {
		cout << endl;
		for (size_t j = 0; j < size; j++) {
			cout << " " << arr[i][j];
		}
	}
	
	print_transposed(arr, size, ost);
	cout << endl << "Проверьте файл! " << endl;
	return 0;
}