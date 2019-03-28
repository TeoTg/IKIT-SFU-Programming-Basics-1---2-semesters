#include "pch.h"
#include <iostream>
#include <clocale>

using namespace std;

int count_equal(int arr[], int len, int x) {
	int sum = 0;
	for (int i = 0; i < len; i++) {
		if (arr[i] == x) {
			sum++;
		}
	}
	return sum;
}

int main() {
	setlocale(LC_ALL, "rus");

	int len, *arr, x;
	cout << "Введите значение len: ";
	cin >> len;
	cout << "Введите значение х: ";
	cin >> x;
	cout << "Введите значения массива: ";
	arr = new int[len];
	for (int i = 0; i < len; i++) {
		cin >> arr[i];
	}

	cout << "\nКоличество элементов массива равных х: " << count_equal(arr, len, x);

	return 0;
}