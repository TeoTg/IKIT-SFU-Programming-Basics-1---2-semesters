#include "pch.h"
#include <iostream>
#include <clocale>

using namespace std;

int splice_array(int *arr1, int *arr2, int *arr_out, int len) {
	int size =  2 * len;
	for (int i = 0, j = 0; i < size; i += 2, j++) {
		arr_out[i] = arr1[j];
		arr_out[i + 1] = arr2[j];
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
	for (int i = 0; i < len; i++) {
		cin >> arr1[i];
	}
	cout << "Введите значения массива arr2: ";
	int *arr2 = new int[len];
	for (int i = 0; i < len; i++) {
		cin >> arr2[i];
	}

	int *arr_out = new int[2 * len];
	int size_splice = splice_array(arr1, arr2, arr_out, len);
	cout << "Новый массив: ";
	for (int i = 0; i < size_splice; i++) {
		cout << arr_out[i] << " ";
	}

	return 0;
}