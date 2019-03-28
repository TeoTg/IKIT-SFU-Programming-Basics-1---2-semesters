#include "pch.h"
#include <iostream>
#include <clocale>
#include <cstring>

using namespace std;

void rstrip(char *s, const char *chars) {
	bool end_s;
	int len_s = strlen(s), len_chars = strlen(chars);
	for (int i = len_s - 1; i >= 0; i--) {
		end_s = false;
		for (int j = 0; j < len_chars; j++) {
			if (s[i] == chars[j]) {
				s[i] = 0;
				end_s = true;
			}
		}
		if (!end_s)
			break;
	}
}

int main() {
	setlocale(LC_ALL, "rus");

	char *s = new char[255];
	cout << "Введите строку s: ";
	cin.getline(s, 255);
	char *chars = new char[255];
	cout << "Введите строку chars: ";
	cin.getline(chars, 255);

	rstrip(s, chars);

	cout << endl << "Новая строка: " << s;
	return 0;
}