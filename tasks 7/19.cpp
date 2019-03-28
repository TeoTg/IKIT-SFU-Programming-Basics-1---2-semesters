#include "pch.h"
#include <iostream>
#include <clocale>

using namespace std;

void print_array(int arr[], int len) {
	for (int i = 0; i < len; i++) {
		cout << arr[i] << " ";
	}
}

int main() {
	setlocale(LC_ALL, "rus");

	int N, len, *arr;
	cout << "Введите значение N: ";
	cin >> N;
	cout << "Введите значение len: ";
	cin >> len;
	cout << "Введите значения массива: ";
	arr = new int[N];
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	cout << "Новый массив: ";
	print_array(arr, len);

	return 0;
}