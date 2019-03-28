#include "pch.h"
#include <iostream>
#include <clocale>
#include <fstream>
#include <cstring>

using namespace std;

int main() {
	setlocale(LC_ALL, "rus");

	int n;
	cout << "Введите значение n: ";
	cin >> n;

	int **A;
	A = new int *[n];
	for (int i = 0; i < n; i++) {
		A[i] = new int[n];
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i + j == n - 1) {
				A[i][j] = 1;
			}
			else if (i + j < n - 1) {
				A[i][j] = 0;
			}
			else {
				A[i][j] = 2;
			}
		}
	}

	ofstream out;
	out.open("out.txt");
	for (int i = 0; i < n; i++) {
		out << endl;
		for (int j = 0; j < n; j++) {
			out << A[i][j] << " ";
		}
	}

	cout << "Проверьте файл! " << endl;
	out.close();
	return 0;
}