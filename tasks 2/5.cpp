#include "pch.h"
#include <iostream>
#include <clocale>

using namespace std;

int main() {
	setlocale(LC_ALL, "rus");

	float a1, a2, b1, b2;

	cout << "Введите значение a1: ";
	cin >> a1;
	cout << "Введите значение a2: ";
	cin >> a2;
	cout << "Введите значение b1: ";
	cin >> b1;
	cout << "Введите значение b2: ";
	cin >> b2;

	if (a1 == b1 && a2 == b2) {
		cout << "A равно B" << endl;
	}
	else if (b1 <= a1 && a2 <= b2) {
		cout << "А внутри В" << endl;
	}
	else if (a1 <= b1 && b2 <= a2) {
		cout << "B внутри А" << endl;
	}
	else if ((b1 >= a1 && b1 <= a2) || (b1 <= a1 && b2 >= a1)) {
		cout << "Другое пересечение" << endl;
	}
	else {
		cout << "Нет пересечений" << endl;
	}
	return 0;
}