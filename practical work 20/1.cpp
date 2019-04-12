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
	student *rlink;
	student *llink;
};

// Созднание узла
student *create_node(ifstream &fin) {
	student *f = new student;
	f->rlink = nullptr;
	f->llink = nullptr;
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
	student buf;
	fout.read((char *)&buf, sizeof(student));
	cout.setf(ios::left);
	cout << setw(20) << buf.surname << setw(20);
	cout << buf.age << setw(20);
	cout << buf.course << setw(20);
	if (buf.department) {
		cout << "Да" << endl;
	}
	else {
		cout << "Нет" << endl;
	}
}

// Вывод файла на экран
void print_console(fstream &fout, student *k) {
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

	student *left = nullptr, *right = nullptr, // Левый и правый указатели
		*current = nullptr, *penultimate = nullptr; // Рабочие указатель
	int n = 0;

	current = create_node(fin);
	right = current;
	penultimate = current; // Второй рабочий указатель хранит адрес предпоследнего узла

	while (!fin.eof()) {
		current = create_node(fin);
		current->rlink = penultimate; // Связываем вновь созданный узел с предыдущим
		penultimate->llink = current; // Связываем предыдущий узел с вновь созданным
		penultimate = current;
		n++;
	}
	penultimate->llink = nullptr;
	left = penultimate;

	cout << "Содержимое входного файла: " << endl;
	while (current != nullptr) {
		print_console(fout, current);
		current = current->rlink;
	}

	cout << endl << "Студенты 4 курса, которые посещают военную кафедру: " << endl;
	fout.seekp(0, ios_base::beg);
	current = left;
	int counter_student = 0; // Счетчик студентов, удовлетворяющих условию
	for (int i = 0; i < n; i++) {
		if (student_filtering(current)) {
			write_data_binar(fout, current);
			counter_student++;
		}
		current = current->rlink;
	}

	fout.seekg(0, ios_base::beg);
	for (int i = 0; i < counter_student; i++) {
		read_data_binar(fout);
	}

	fout.close();
	fin.close();
	cout << endl << "Пришло время проверить выходной файл! " << endl;
	return 0;
}