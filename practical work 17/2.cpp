#include "pch.h"
#include <iostream>
#include <clocale>
#include <fstream>
#include <cstring>
#include <vector>
#include <iomanip>

using namespace std;

enum enum_user{
	users,
	moder,
	admin
};

struct user {
	char surname[20];
	char log[20];
	char pass[20];
	enum_user user_role;
};

// Заполнение структуры
void fill_user(ifstream &fin, vector<user> &buf) {
	user buffer;
	fin >> buffer.surname >> buffer.log >> buffer.pass;
	char role[20];
	fin >> role;
	if (strcmp(role,"user") == 0) {
		buffer.user_role = users;
	}
	else if (strcmp(role,"admin") == 0) {
		buffer.user_role = admin;
	}
	else {
		buffer.user_role = moder;
	}
	buf.push_back(buffer);
}

// Сортировка списка пользователей
void sort(vector<user> &buf, int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (buf[i].user_role > buf[j].user_role) {
				swap(buf[i], buf[j]);
			}
		}
	}
}

// Вывод данных пользователя
void print_user_console(const user *buf) {
	cout.setf(ios::left);
	cout << setw(20) << buf->surname;
	cout << "\t" << setw(20) << buf->log << "\t" << setw(20) << buf->pass;
	cout << "\t" << setw(20);
	if (buf->user_role == 0) {
		cout << "пользователь" << endl;
	}
	else if (buf->user_role == 1) {
		cout << "модератор" << endl;
	}
	else {
		cout << "администратор" << endl;
	}
}

// Запись данных пользователя в двоичный файл
void write_user_binar(fstream &fout, user &s) {
	fout.write((char*)&s, sizeof(s));
}

int main() {
	setlocale(LC_ALL, "");

	ifstream fin("in.txt");
	cout << "Программа сортирует данные пользователей по их роли." << endl << endl;

	if (!fin.is_open()) {
		cout << "Не удалось открыть файл!" << endl;
		return -1;
	}

	char files_name[255];
	cout << "Введите название файла и расширение: ";
	cin.getline(files_name, 255);
	fstream fout(files_name, ios::binary | ios::in | ios::out | ios::trunc);

	cout << "Список пользователей: ";

	vector<user> buf;
	int n;

	fout.seekp(0, ios_base::beg);
	for (n = 0; !fin.eof(); ++n) {
		fill_user(fin, buf);
		write_user_binar(fout, buf.back());
	}

	cout << endl;
	user buffer;
	fout.seekp(0, ios_base::beg);
	for (int i = 0; i < n; i++) {
		fout.read((char *)&buffer, sizeof(buffer));
		print_user_console(&buffer);
	}

	sort(buf, n);
		
	cout << endl << "Список пользователей после сортировки: " << endl;
	fout.seekp(0, ios_base::beg);
	
	for (int i = 0; i < n; i++) {
		fout.write((char *)&buf[i], sizeof(buf[i]));
	}

	fout.seekg(0, ios_base::beg);
	for (int i = 0; i < n; i++) {
		fout.read((char *)&buffer, sizeof(buffer));
		print_user_console(&buffer);
	}

	cout << endl << "Пришло время проверить файл!" << endl;
	fout.close();
	fin.close();
	return 0;
}