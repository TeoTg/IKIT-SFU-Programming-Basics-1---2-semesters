#include "pch.h"
#include <iostream>
#include <clocale>

using namespace std;

int count_equal(int *arr, int len, int x) {
	int k = 0;
	for (int *B = arr; B < arr + len; B++) {
		if (*B == x) {
			k++;
		}
	}
	return k;
}

int main() {
	setlocale(LC_ALL, "rus");

	int len, x, n;
	cout << "������� ����� len: ";
	cin >> len;
	cout << "������� ����� x: ";
	cin >> x;

	int *arr = new int[len];
	cout << "������� ������ arr: ";
	for (int *B = arr; B < arr + len; B++) {
		cin >> *B;
	}

	cout << endl << "���������� ��������� ������� ������ x: " << count_equal(arr, len, x) << endl;

	return 0;
}