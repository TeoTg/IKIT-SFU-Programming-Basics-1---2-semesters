#include "pch.h"
#include <iostream>
#include <clocale>

using namespace std;

int find_last_otr(const int *A, int N) {
	int min = 0;
	for (const int *ptr1 = A; ptr1 < A + N; ptr1++) {
		if (*ptr1 < 0) {
			min = *ptr1;
		}
	}
	return min;
}

int main() {
	setlocale(LC_ALL, "rus");

	int N;
	cout << "Введите значение N: ";
	cin >> N;
	int *A = new int[N];
	int *ptr1, *ptr2;

	cout << "Введите элементы массива: ";
	for (ptr1 = A; ptr1 < A + N; ptr1++) {
		cin >> *ptr1;
	}

	int index_last_otr = find_last_otr(A, N);
	int size, *B;
	if (index_last_otr == 0) {
		B = new int[N];
		size = N;
	}
	else {
		B = new int[N - 1];
		size = N - 1;
	}

	for (ptr1 = A, ptr2 = A; ptr1 < A + N; ptr1++) {
		if (*ptr1 != index_last_otr) {
			*ptr2 = *ptr1;
			*ptr2++;
		}
	}
	cout << "Массив B : ";
	for (ptr2 = A; ptr2 < A + size; ptr2++) {
		cout << *ptr2 << " ";
	}

	return 0;
}