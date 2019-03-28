#include "pch.h"
#include <iostream>
#include <clocale>
#include <fstream>
#include <cstring>

using namespace std;

void write_filling_ones(ofstream &ost, size_t N) {
	unsigned char num = 0b0000'0000;
	for (size_t i = 0; i < N; i++) {
		ost.write((char *)&num, sizeof(num));
		if (num == 0b1111'1111) {
			num = 0b0000'0000;
		}
		else {
			num = num << 1 | 1;
		}
	}
}

int main() {
	setlocale(LC_ALL, "");

	ofstream ost("out.txt", ios::binary);

	size_t N;
	cout << "Введите число N: ";
	cin >> N;

	write_filling_ones(ost, N);

	cout << endl << "Пришло время проверить файл!" << endl;
	ost.close();
	return 0;
}