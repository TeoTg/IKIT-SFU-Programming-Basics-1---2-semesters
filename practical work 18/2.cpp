#include "pch.h"
#include <iostream>
#include <clocale>
#include <ctime>

using namespace std;

struct node {
	int info;
	node *link;
};

// Вывод очереди на экран
void print(node *k) {
	node *new_node = k;
	while (new_node != NULL) {
		cout << new_node->info << " ";
		new_node = new_node->link;
	}
}

// Созднание узла
node *create_node(int num) {
	node *f = new node;
	f->link = nullptr;
	f->info = num;
	return f;
}

// Добавление узла
node *add_node(int num) {
	node *f = new node;
	f->link = nullptr;
	f->info = 1 + rand() % num;
	return f;
}

// Проверка числа на совершенность
bool perfectNum_check(int num) {
	if (num == 0) {
		return false;
	}
	int sum = 0;
	for (int i = num / 2; i >= 1; --i) {
		if (num % i == 0) {
			sum += i;
		}
	}
	return sum == num;
}

int main() {
	setlocale(LC_ALL, "");
	srand(time(NULL));

	int n, t;
	cout << "Введите количество чисел: ";
	cin >> n;
	cout << "Введите сами числа: ";
	cin >> t;

	node *l = nullptr, *r = nullptr, *k = nullptr, *newnode = nullptr;
	k = create_node(t);
	l = r = k;

	for (int i = 1; i < n; i++) {
		cin >> t;
		k = create_node(t);
		r->link = k;
		r = k;
	}
	k = l;

	node *last = k;
	while (k != nullptr) {
		if (perfectNum_check(k->info)) {
			for (int j = 0; j < 5; j++) {
				newnode = add_node(k->info);
				if (k == l) {
					newnode->link = k;
					l = last = newnode;
				}
				else {
					newnode->link = last->link;
					last->link = newnode;
				}
			}
		}
		last = k;
		k = k->link;
	}
	k = l;

	cout << endl << "Получившийся список: ";
	print(k);

	return 0;
}