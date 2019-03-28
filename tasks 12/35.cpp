#include "pch.h"
#include <iostream>
#include <clocale>
#include <cstring>
#include <fstream>

using namespace std;

void print_fliplr(const int* const *arr, size_t nrows, size_t ncols, ostream &ost) {
	for (int i = 0; i < nrows; i++) {
		ost << endl;
		for (int j = ncols - 1; j >= 0; j--) {
			ost << " " << arr[i][j];
		}
	}
}

int main() {
	setlocale(LC_ALL, "");

	size_t ncols, nrows;
	cout << "Введите значение nrows: ";
	cin >> nrows;
	cout << "Введите значение ncols: ";
	cin >> ncols;

	ofstream ost("1.txt", ios::out);
	if (!ost.is_open()) {
		cout << "Не удалось открыть файл! " << endl;
		return -1;
	}

	int **arr = new int *[nrows];
	for (size_t i = 0; i < nrows; i++) {
		arr[i] = new int[ncols];
	}
	cout << "Заполните массив arr: ";
	for (size_t i = 0; i < nrows; i++) {
		for (size_t j = 0; j < ncols; j++) {
			cin >> arr[i][j];
		}
	}
	cout << "Текущий массив: ";
	for (size_t i = 0; i < nrows; i++) {
		cout << endl;
		for (size_t j = 0; j < ncols; j++) {
			cout << " " << arr[i][j];
		}
	}
	
	print_fliplr(arr, nrows, ncols, ost);
	cout << endl << "Проверьте файл! " << endl;
	return 0;
}