#include "pch.h"
#include <iostream>
#include <clocale>
#include <fstream>
#include <cstring>

using namespace std;

void read_write_arr(int n, int m, ifstream &fin, fstream &fout) {
	int *buf = new int[m];
	for (int i = 0; i < n; i++) {
		cout << endl;
		for (int j = 0; j < m; j++) {
			fin >> buf[j];
			cout << " " << buf[j];
		}
		fout.write((char *)buf, sizeof(int)*m);
	}
	cout << endl;
	delete [] buf;
}

int find_max_element(int *arr, int m) {
	int max = arr[0];
	for (int i = 1; i < m; i++) {
		if (arr[i] > max) {
			max = arr[i];
		}
	}
	return max;
}

int find_number_of(int *arr, int m, int max) {
	int number_of = 0;
	for (int i = 0; i < m; i++) {
		if (max == arr[i]) {
			number_of++;
		}
	}
	return number_of;
}

int main() {
	setlocale(LC_ALL, "");

	ifstream fin("in.txt");
	fstream fout("out.txt", ios::binary | ios::out | ios::in);

	int n, m, k;
	fin >> n >> m;
	cout << "Значение n в файле = " << n << endl;
	cout << "Значение m в файле = " << m << endl;

	fout.write((char *)&n, sizeof(int));
	fout.write((char *)&m, sizeof(int));
	
	cout << endl << "Матрица в файле: ";
	int *arr = new int[m];
	read_write_arr(n, m, fin, fout);

	cout << endl << "Введите значение k: ";
	cin >> k;

	if (k > n) {
		cout << endl << "Число k должно быть меньше либо равно n" << endl;
		return -1;
	}


	fout.seekg(sizeof(int)*m*(k - 1) + sizeof(int)*2, ios_base::beg);
	fout.read((char *)arr, sizeof(int)*m);
	int max = find_max_element(arr, m);
	cout << endl << "Максимальный элемент k-той строки = " << max << endl;

	fout.seekg(sizeof(int)*m * (k - 1), ios_base::beg);
	cout << "Количество элементов равных max = " << find_number_of(arr, m, max) << endl;

	cout << endl << "Пришло время проверить файл!" << endl;
	fin.close();
	fout.close();
	return 0;
}