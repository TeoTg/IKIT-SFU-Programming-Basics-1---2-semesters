#include "pch.h"
#include <iostream>
#include <clocale>
#include <cstring>

using namespace std;

void crypt(char *line) {
	/* a - 1, e - 2, i - 3, o - 4, u - 5, y - 6 */
	const char *alphabet = "aeiouyAEIOUY";
	const char *digit = "123456";
	for (int i = 0; line[i] != '\0'; i++) {
		for (int j = 0; alphabet[j] != '\0' && digit[j] != '\0'; j++) {
			if (line[i] == alphabet[j] || line[i] == alphabet[j + 6]) {
				line[i] = digit[j];
			}
		}
	}
	cout << endl << "Новая сторока: " << line << endl;
}

int main() {
	setlocale(LC_ALL, "rus");

	char *line = new char[255];
	cout << "Введите строку: ";
	cin.getline(line, 255);
	
	crypt(line);

	return 0;
}