#include "pch.h"
#include <iostream>
#include <clocale>
#include <fstream>
#include <cstring>

using namespace std;

void convert_string(const char *text, ofstream &fout) {
	int len = strlen(text);
	int index = 0, index_out = 0;
	for (int i = 0; i < len; i++) {
		if (text[i] == '\\') {
			index = i;
		}
	}
	if (index == 2) {
		fout << "\\";
	}
	else {
		for (int i = index - 1; text[i] != '\\'; i--) {
			index_out = i;
		}
		for (int i = index_out; text[i] != '\\'; i++) {
			fout << text[i];
		}
	}
}

int main() {
	setlocale(LC_ALL, "");

	ifstream fin("in.txt");
	ofstream fout("out.txt");
	if (!fout.is_open()) {
		cout << "Файл не может быть открыт или создан. " << endl;
		return -1;
	}

	char text[255];
	while (fin.getline(text, 255)) {
		convert_string(text, fout);
		fout << endl;
	}

	fin.close();
	fout.close();
	cout << "Проверьте файл!" << endl;
	return 0;
}