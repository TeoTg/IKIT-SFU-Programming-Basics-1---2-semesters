#include "pch.h"
#include <iostream>
#include <clocale>

using namespace std;

void strip(char *s, const char *chars) {
	bool end_s;
	for (int i = strlen(s) - 1; i >= 0; i--) {
		end_s = false;
		for (int j = 0; j < strlen(chars); j++) {
			if (s[i] == chars[j]) {
				s[i] = 0;
				end_s = true;
				break;
			}
		}
		if (!end_s)
			break;
	}
	for (int i = 0; i < strlen(s); i++) {
		end_s = false;
		for (int j = 0; j <= strlen(chars); j++) {
			if (s[i] == chars[j]) {
				for (int k = 0; k < strlen(s); k++)
					s[k] = s[k + 1];
				end_s = true;
				i = -1;
				break;
			}
		}
		if (!end_s)
			break;
	}
}

int main() {
	setlocale(LC_ALL, "");

	char s[255], chars[255];
	cout << "Введите строку s: ";
	cin.getline(s, 255);
	cout << "Введите строку chars: ";
	cin.getline(chars, 255);

	strip(s, chars);
	cout << "Новая строка s: " << s << endl;

	return 0;
}