#include "pch.h"
#include <iostream>
#include <clocale>
#include <string>
#include <fstream>

using namespace std;

void join(const char *sep, istream &ist, ostream &ost) {
	char buf[255];
	bool frst_str = true;
	while (ist >> buf) {
		if (frst_str) {
			frst_str = false;
		}
		else {
			ost << sep;
		}
		ost << buf;
	}
}

int main() {
	setlocale(LC_ALL, "");

	ifstream ist("in.txt");
	ofstream ost("out.txt");

	if (!ist.is_open()) {
		cout << "Файл не найден!\n";
		return -1;
	}

	char sep[255];
	cout << "Введите строку sep: ";
	cin.getline(sep, 255);
	
	join(sep, ist, ost);

	cout << "Проверьте файл!" << endl;
	ist.close();
	ost.close();
	return 0;
}