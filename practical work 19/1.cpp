#include "pch.h"
#include <iostream>
#include <clocale>
#include <fstream>
#include <vector>
#include <iomanip>

using namespace std;

struct student {
	char surname[20];
	int age;
	int course;
	bool department;
	student *link;
};

// Созднание узла
student *create_node(ifstream &fin) {
	student *f = new student;
	f->link = nullptr;
	fin >> f->surname >> f->age >> f->course;
	char department[20];
	fin >> department;
	f->department = !strcmp(department, "Да");
	return f;
}

// Проверка данных на удовлетворения условию
bool student_filtering(student *k) {
	return k->course == 4 && k->department == true;
}

// Запись данных в двоичный файл
void write_data_binar(fstream &fout, student *k) {
	fout.write((char*)k, sizeof(student));
}

// Чтение данных из двоичного файла
void read_data_binar(fstream &fout) {
	student *buf = new student;
	fout.read((char *)buf, sizeof(student));
	cout.setf(ios::left);
	cout << setw(20) << buf->surname << setw(20);
	cout << buf->age << setw(20);
	cout << buf->course << setw(20);
	if (buf->department) {
		cout << "Да" << endl;
	}
	else {
		cout << "Нет" << endl;
	}
	delete[] buf;
}

// Вывод файла на экран
void print_console(student *k) {
	cout.setf(ios::left);
	cout << setw(20) << k->surname << setw(20) << k->age << setw(20) << k->course << setw(20);
	if (k->department) {
		cout << "Да" << endl;
	}
	else {
		cout << "Нет" << endl;
	}
}

int main() {
	setlocale(LC_ALL, "");

	ifstream fin("in.txt");
	fstream fout("out.bin", ios::binary | ios::out | ios::in | ios::trunc);

	if (!fin.is_open()) {
		cout << "Входящий файл не найден! " << endl;
		return -1;
	}

	student *l = nullptr, *r = nullptr, *k = nullptr;
	int n = 0; // Количество узлов

	k = create_node(fin);
	l = r = k;

	while (!fin.eof()) {
		k = create_node(fin);
		r->link = k;
		r = k;
		n++;
	}
	k = l;

	cout << "Содержимое входного файла: " << endl;
	for (int i = 0; i < n; i++) {
		print_console(k);
		r->link = k;
		r = k;
		k = k->link;
	}
	k = l;

	int size_sort_buf = 0;
	fout.seekp(0, ios_base::beg);
	for (int i = 0; i < n; i++) {
		if (student_filtering(k)) {
			write_data_binar(fout, k);
			size_sort_buf++;
		}
		r->link = k;
		r = k;
		k = k->link;
	}
	k = l;

	if (size_sort_buf == 0) {
		cout << endl << "Нет студентов, которые посещают военную кафедру. " << endl;
	}
	else {
		cout << endl << "Студенты 4 курса, которые посещают военную кафедру: " << endl;
		fout.seekg(0, ios_base::beg);
		for (int i = 0; i < size_sort_buf; i++) {
			read_data_binar(fout);
		}
	}

	fout.close();
	fin.close();
	cout << endl << "Пришло время проверить выходной файл! " << endl;
	return 0;
}