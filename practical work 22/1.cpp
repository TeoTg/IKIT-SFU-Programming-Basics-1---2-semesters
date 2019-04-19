#include "pch.h"
#include <iostream>
#include <clocale>

using namespace std;

struct node {
	int info; // Информационное поле
	node *ll, *rl; // Левый и правый указатели
};

// Построения дерева
node *tree(node *p, int current) {
	if (p == NULL) {
		p = new node;
		p->info = current;
		p->ll = NULL;
		p->rl = NULL;
	}
	else if (current < p->info) {
		p->ll = tree(p->ll, current);
	}
	else {
		p->rl = tree(p->rl, current);
	}
	return p;
}

// Обхода дерева
void treeprint(node *p){
	if (p != NULL) {
		treeprint(p->ll); // по левому указателюъ
		cout << "\t" << p->info << endl;
		treeprint(p->rl); // по правому указателю
	}
}

// Вывод элементов n-ого уровня дерева
void treeprint_level(node *p, int n) {
	if (p != NULL) {
		treeprint_level(p->ll, n - 1); // по левому указателюъ
		if (n == 1) {
			cout << "\t" << p->info << endl;
		}
		treeprint_level(p->rl, n - 1); // по правому указателю
	}
}

int main() {
	setlocale(LC_ALL, "");

	node *root;
	root = NULL; // Обнуляем корень дерева
	int current, n;

	cout << "Введите предельный уровень n: ";
	cin >> n;
	cout << "Введите числа: ";
	cin >> current;

	while (!feof(stdin)) {
		root = tree(root, current);
		cin >> current;
	}

	cout << "Обход дерева: " << endl;
	treeprint(root);
	cout << endl << "<------------------------->" << endl;
	cout << "На " << n << " уровне находятся элементы:" << endl;
	treeprint_level(root, n);

	return 0;
}