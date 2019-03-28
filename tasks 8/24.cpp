#include "pch.h"
#include <iostream>
#include <clocale>

using namespace std;

int splice_array(int *arr1, int *arr2, int *arr_out, int len) {
	int size = 2 * len;
	for (int *K = arr_out, *A = arr1, *B = arr2; K < arr_out + size; K += 2, A++, B++) {
		*K = *A;
		*(K + 1) = *B;
	}
	return size;
}

int main() {
	setlocale(LC_ALL, "rus");

	int len;
	cout << "Введите значение len: ";
	cin >> len;
	cout << "Введите значения массива arr1: ";

	int *arr1 = new int[len];
	for (int *A = arr1; A < arr1 + len; A++) {
		cin >> *A;
	}
	cout << "Введите значения массива arr2: ";
	int *arr2 = new int[len];
	for (int *B = arr2; B < arr2 + len; B++) {
		cin >> *B;
	}

	int *arr_out = new int[2 * len];
	int size = splice_array(arr1, arr2, arr_out, len);
	cout << "Новый массив: ";
	for (int *K = arr_out; K < arr_out + size; K++) {
		cout << *K << " ";
	}

	return 0;
}