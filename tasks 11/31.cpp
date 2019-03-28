#include "pch.h"
#include <iostream>
#include <clocale>

using namespace std;

int **make2d(size_t nrows, size_t ncols, int val) {
	int **arr = new int *[nrows];
	for (int i = 0; i < nrows; i++) {
		arr[i] = new int[ncols];
	}
	for (int i = 0; i < nrows; i++) {
		for (int j = 0; j < ncols; j++) {
			arr[i][j] = val;
		}
	}
	return arr;
}

int main() {
	setlocale(LC_ALL, "");

	size_t nrows, ncols;
	int val;
	cout << "Заполните nrows: ";
	cin >> nrows;
	cout << "Заполните nclos: ";
	cin >> ncols;
	cout << "Укажите значение val: ";
	cin >> val;

	int **arr = make2d(nrows, ncols, val);
	cout << endl << "Новый массив: ";
	for (int i = 0; i < nrows; i++) {
		cout << endl;
		for (int j = 0; j < ncols; j++) {
			cout << arr[i][j] << " ";
		}
	}
	

	return 0;
}