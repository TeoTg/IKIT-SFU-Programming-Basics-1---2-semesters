/*Для двух целых чисел, введенных с клавиатуры, вычисляет остаток от целочисленного деления, 
частное от целочисленного деления первого числа на второе, а также частное от вещественного деления.*/

#include "pch.h"
#include <iostream>
#include <clocale>

using namespace std;

int main() {
	setlocale(LC_ALL, "rus");

	int num1, num2, mod, div_i;
	float div_f;

	cout << "Введите первое число: " << endl;
	cin >> num1;
	cout << "Введите второе число: " << endl;
	cin >> num2;

	if (num2 != 0) {
		mod = num1 % num2;
		div_i = num1 / num2;
		div_f = float(num1) / num2;

		cout.setf(ios::fixed);
		cout.setf(ios::left);
		cout.width(40);
		cout.precision(2);
		cout.fill('*');
		cout << "Остаток от целочисленного деления = " << mod << endl;
		cout.setf(ios::fixed);
		cout.setf(ios::left);
		cout.width(50);
		cout.precision(7);
		cout.fill('#');
		cout << "Остаток от целочисленного деления = " << mod << endl;
		cout.setf(ios::fixed);
		cout.setf(ios::right);
		cout.width(75);
		cout.precision(5);
		cout.fill('$');
		cout << "Остаток от целочисленного деления = " << mod << endl;

		cout.setf(ios::fixed);
		cout.setf(ios::left);
		cout.width(40);
		cout.precision(2);
		cout.fill('*');
		cout << "Частное от целочисленного деления = " << div_i << endl;
		cout.setf(ios::fixed);
		cout.setf(ios::left);
		cout.width(50);
		cout.precision(7);
		cout.fill('#');
		cout << "Частное от целочисленного деления = " << div_i << endl;
		cout.setf(ios::fixed);
		cout.setf(ios::right);
		cout.width(75);
		cout.precision(5);
		cout.fill('$');
		cout << "Частное от целочисленного деления = " << div_i << endl;

		cout.setf(ios::fixed);
		cout.setf(ios::left);
		cout.width(40);
		cout.precision(2);
		cout.fill('*');
		cout << "Частное от вещественного деления = " << div_f << endl;
		cout.setf(ios::fixed);
		cout.setf(ios::left);
		cout.width(50);
		cout.precision(7);
		cout.fill('#');
		cout << "Частное от вещественного деления = " << div_f << endl;
		cout.setf(ios::fixed);
		cout.setf(ios::right);
		cout.width(75);
		cout.precision(5);
		cout.fill('$');
		cout << "Частное от вещественного деления = " << div_f << endl;
	} else {
		cout << "Произошла ошибка в вычислениях." << endl;
	}
	return 0;
}