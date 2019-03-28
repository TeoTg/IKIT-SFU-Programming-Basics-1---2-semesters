#include "pch.h"
#include <iostream>
#include <clocale>
#include <cmath>

using namespace std;

void sort(float arr[], int len, float x) {
	for (int i = 0; i < len - 1; i++) {
		for (int j = 0; j < len - i - 1; j++) {
			if (abs(arr[j] - x) > abs(arr[j + 1] - x)) {
				float temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

int main() {
	setlocale(LC_ALL, "rus");

	int len;
	float x;
	cout << "Укажите значение len: ";
	cin >> len;
	cout << "Укажите значение x: ";
	cin >> x;

	float *arr = new float[len];
	cout << "Заполните массив arr: ";
	for (int i = 0; i < len; i++) {
		cin >> arr[i];
	}

	sort(arr, len, x);

	float *dist = new float[len];
	for (int i = 0; i < len; i++) {
		dist[i] = abs(arr[i] - x);
	}
	cout << "Отсортированный массив arr: ";
	for (int i = 0; i < len; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
	cout << "Новый массив dist: ";
	for (int i = 0; i < len; i++) {
		cout << dist[i] << " ";
	}
	cout << endl;
	return 0;
}