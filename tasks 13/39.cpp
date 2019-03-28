#include "pch.h"
#include <iostream>
#include <clocale>
#include <cstring>
#include <fstream>

using namespace std;

void wrap_text(ifstream &ist, ofstream &ost, int max_line_len) {
	char line[255];
	int k = 1;
	while (ist.getline(line, 255)) {
		for (int i = 0; i < strlen(line); i++) {
			if (i == max_line_len * k) {
				ost << endl;
				k++;
			}
			ost << line[i];
		}
		ost << endl;
		k = 1;
	}
}


int main() {
	setlocale(LC_ALL, "");

	ifstream ist("in.txt");
	ofstream ost("out.txt");
	
	int a = 12, *ptr;
	ptr = &a;

	if (!ist.is_open()) {
		cout << "Не удалось открыть файл" << endl;
		return -1;
	}

	int max_line_len;
	cout << "Введите значение max_line_len: ";
	cin >> max_line_len;

	wrap_text(ist, ost, max_line_len);

	cout << "Проверьте файл!" << endl;
	ist.close();
	ost.close();
	return 0;
}