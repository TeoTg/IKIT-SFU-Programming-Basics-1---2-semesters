#include "pch.h"
#include <iostream>
#include <clocale>

using namespace std;

void fliplr(int **arr, size_t nrows, size_t ncols) {
	int temp;
	for (size_t i = 0; i < nrows; i++) {
		for (size_t j = 0; j < ncols - 1; j++) {
			temp = arr[i][j];
			arr[i][j] = arr[i][ncols - j - 1];
			arr[i][ncols - j - 1] = temp;
		}
	}
}

int main() {
	setlocale(LC_ALL, "");

	size_t nrows, ncols;
	cout << "������� �������� nrows: ";
	cin >> nrows;
	cout << "������� �������� ncols: ";
	cin >> ncols;

	int **arr = new int *[nrows];
	for (int i = 0; i < nrows; i++) {
		arr[i] = new int[ncols];
	}

	cout << "��������� ������ arr: " << endl;
	for (int i = 0; i < nrows; i++) {
		for (int j = 0; j < ncols; j++) {
			cin >> arr[i][j];
		}
	}

	fliplr(arr, nrows, ncols);
	cout << endl << "����� �������: ";
	for (int i = 0; i < nrows; i++) {
		cout << endl;
		for (int j = 0; j < ncols; j++) {
			cout << arr[i][j] << " ";
		}
	}
	return 0;
}