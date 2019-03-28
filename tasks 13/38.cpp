#include "pch.h"
#include <iostream>
#include <clocale>
#include <cstring>
#include <fstream>

using namespace std;

void rev_lines(istream &ist, ofstream &ost) {
	char buf[50][255];
	int k = 0;
	while (ist.getline(buf[k], 255)) {
		k++;
	}
	for (int i = k; i > 0; i--) {
		ost << buf[i - 1];
		if (i - 1 != 0) {
			ost << endl;
		}
	}
}

int main() {
	setlocale(LC_ALL, "");

	ifstream ist("in.txt");
	ofstream ost("out.txt");

	if (!ist.is_open()) {
		cout << "Ôאיכ םו םאיהום!\n";
	}
	else {
		rev_lines(ist, ost);
	}

	cout << "Ïנמגונüעו פאיכ!" << endl;
	ist.close();
	ost.close();
	return 0;
}