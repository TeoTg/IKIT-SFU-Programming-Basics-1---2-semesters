#include "pch.h"
#include <iostream>
#include <clocale>
#include <cstring>
#include <fstream>

using namespace std;

void print2d(const int* const *arr, size_t nrows, size_t ncols, ostream &ost) {
	for (size_t i = 0; i < nrows; i++) {
		ost << endl;
		for (size_t j = 0; j < ncols; j++) {
			ost << " " << arr[i][j];
		}
	}
}

int main() {
	setlocale(LC_ALL, "");
	ofstream ost("1.txt", ios::out);

	size_t ncols, nrows;
	cout << "Введите значение nrows: ";
	cin >> nrows;
	cout << "Введите значение ncols: ";
	cin >> ncols;

	int **arr = new int *[nrows];
	for (size_t i = 0; i < nrows; i++) {
		arr[i] = new int[ncols];
	}

	cout << "Заполните массив: ";
	for (size_t i = 0; i < nrows; i++) {
		for (size_t j = 0; j < ncols; j++) {
			cin >> arr[i][j];
		}
	}

	print2d(arr, nrows, ncols, ost);
	cout << "Проверьте файл! " << endl;
	return 0;
}