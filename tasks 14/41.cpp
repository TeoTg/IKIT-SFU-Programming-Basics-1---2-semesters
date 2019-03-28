#include "pch.h"
#include <iostream>
#include <clocale>
#include <fstream>
#include <cstring>

using namespace std;

void write_cyclic_one(ofstream &ost, size_t N) {
	unsigned char num = 0x01;
	for (size_t i = 0; i < N; i++) {
		ost.write((char *)&num, sizeof(num));
		if (num != 0x80) {
			num <<= 1;
		}
		else {
			num = 0x01;
		}
	}
}

int main() {
	setlocale(LC_ALL, "");

	ofstream ost("out.txt", ios::binary);

	size_t N;
	cout << "Введите число N: ";
	cin >> N;

	write_cyclic_one(ost, N);

	cout << endl << "Пришло время проверить файл!" << endl;
	ost.close();
	return 0;
}