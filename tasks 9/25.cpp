#include "pch.h"
#include <iostream>
#include <clocale>

using namespace std;

void sort(float *arr, int len, bool asc) {
	for (int i = 0; i < len; i++) {
		for (int j = 0; j < len - 1; j++) {
			if (asc && arr[j + 1] < arr[j] || !asc && arr[j + 1] > arr[j]) {
				float d = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = d;
			}
		}
	}
}

int main() {
	setlocale(LC_ALL, "rus");

	int len;
	cout << "Укажите длину массива: ";
	cin >> len;

	float *arr = new float[len];
	cout << "Заполните массив: ";
	for (int i = 0; i < len; i++) {
		cin >> arr[i];
	}
	bool asc;
	cout << "Укажите значение asc: ";
	cin >> asc;

	sort(arr, len, asc);
	cout << "Готовый массив: ";
	for (int i = 0; i < len; i++) {
		cout << arr[i] << " ";
	}

	return 0;
}