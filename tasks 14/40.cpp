#include "pch.h"
#include <iostream>
#include <clocale>
#include <fstream>
#include <cstring>

using namespace std;

void write_aa_55(ofstream &ost, size_t N) {
	unsigned char num = 0x55;
	for (size_t i = 0; i < N; i++) {
		num = ~num;
		ost.write((char *)&num, sizeof(num));
	}
}

int main() {
	setlocale(LC_ALL, "");

	ofstream ost("out.txt", ios::binary  | ios::out);

	size_t N;
	cout << "Введите число N: ";
	cin >> N;
	
	write_aa_55(ost, N);

	cout << endl << "Пришло время проверить файл!" << endl;
	ost.close();
	return 0;
}