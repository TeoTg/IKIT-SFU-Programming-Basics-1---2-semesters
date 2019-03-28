#include "pch.h"
#include <iostream>
#include <clocale>

using namespace std;

// ������� ������ ��������������� �����
bool findNum(const int *Y, int num, int m) {
	for (int j = 0; j < m; j++) {
		if (num == Y[j]) {
			return true;
		}
	}
	return false;
}

// ������� ���������� �������
void array_fill(int *arr, int n) {
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
}

int main() {
	setlocale(LC_ALL, "");

	int n, m;
	cout << "������� ����������� n: ";
	cin >> n;
	cout << "������� ����������� m: ";
	cin >> m;

	int *X = new int[n];
	cout << "��������� ������ X[n]: ";
	array_fill(X, n);
	int *Y = new int[m];
	cout << "��������� ������ Y[m]: ";
	array_fill(Y, m);

	// ��������� ������ C
	int size = 0;
	int *C = new int[n];
	for (int i = 1, last = 0; i < n; i++) {
		if (!findNum(Y, X[i], m) && !findNum(C, X[i], n)) {
			C[size++] = X[i];
		}
	}

	// ��������� ������ C �� ��������
	for (int i = 1; i < size; ++i) {
		for (int j = 0; j < size - i; j++) {
			if (C[j] < C[j + 1]) {
				int temp = C[j];
				C[j] = C[j + 1];
				C[j + 1] = temp;
			}
		}
	}

	// ������� ������ � � �������
	cout << "����� ������ C: ";
	for (int i = 0; i < size; i++) {
		cout << " " << C[i];
	}
	cout << endl;

	return 0;
}