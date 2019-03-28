#include "pch.h"
#include <iostream>
#include <clocale>

using namespace std;

bool compare(int num1, int num2, bool even_greater) {
	if (num1 % 2 == 0 && num2 % 2 == 1) {
		return !even_greater;
	}
	else if (num1 % 2 == 1 && num2 % 2 == 0) {
		return even_greater;
	}
	else {
		return (num1 < num2);
	}
}

void sort(int *arr, int len, bool even_greater) {
	for (int i = 0; i < len; i++) {
		for (int j = 0; j < len - 1; j++) {
			if (!compare(arr[j], arr[j + 1], even_greater)) {
				int d = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = d;
			}
		}
	}
}

int main() {
	setlocale(LC_ALL, "rus");

	int len;
	cout << "Укажите размерность массива: ";
	cin >> len;
	bool even_greater;
	cout << "Укажите значение even_greater: ";
	cin >> even_greater;
	int *arr = new int[len];
	cout << "Заполните массив arr: ";
	for (int i = 0; i < len; i++) {
		cin >> arr[i];
	}

	sort(arr, len, even_greater);
	cout << "Новый массив: ";
	for (int i = 0; i < len; i++) {
		cout << arr[i] << " ";
	}

	return 0;
}