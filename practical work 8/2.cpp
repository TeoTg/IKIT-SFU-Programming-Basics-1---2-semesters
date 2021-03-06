#include "pch.h"
#include <iostream>
#include <clocale>

using namespace std;

int find_last_otr(const int *A, int N) {
	int min = -1;
	for (int i = 0; i < N; i++) {
		if (A[i] < 0) {
			min = i;
		}
	}
	return min;
}

int main() {
	setlocale(LC_ALL, "");

	int N;
	cout << "Введите значение N: ";
	cin >> N;
	int *A = new int[N];

	cout << "Заполните массив A: ";
	for (int i = 0; i < N; i++) {
		cin >> A[i];	
	}

	int index_last_otr = find_last_otr(A, N);
	int size, *B;
	if (index_last_otr == -1) {
		B = new int[N];
		size = N;
	}
	else {
		B = new int[N - 1];
		size = N - 1;
	}

	for (int i = 0, j = 0; i < N; i++) {
		if (i != index_last_otr) {
			B[j] = A[i];
			j++;
		}
	}
	cout << "Массив B : ";
	for (int i = 0; i < size; i++) {
		cout << B[i] << " ";
	}

	return 0;
}