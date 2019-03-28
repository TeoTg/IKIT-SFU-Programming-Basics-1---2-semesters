#include "pch.h"
#include <iostream>
#include <clocale>

using namespace std;

int main() {
	setlocale(LC_ALL, "rus");

	int n;
	cout << "¬ведите значение n: ";
	cin >> n;

	int **A;
	A = new int *[n];
	for (int i = 0; i < n; i++) {
		A[i] = new int[n];
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == j) {
				A[i][j] = 1;
			}
			else if (i < j) {
				A[i][j] = 0;
			}
			else {
				A[i][j] = 2;
			}
		}
	}

	cout << endl << "ƒвумерный массив: ";
	for (int i = 0; i < n; i++) {
		cout << endl;
		for (int j = 0; j < n; j++) {
			cout << A[i][j] << " ";
		}
	}
	cout << endl << endl;

	return 0;
}