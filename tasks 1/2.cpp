#include "pch.h"
#include <iostream>
#include <clocale>
#include <math.h>

using namespace std;

int main() {
	setlocale(LC_ALL, "rus");

	int num_people, num_seats, num_free_seats, num_buses;

	cout << "Введите количество людей: ";
	cin >> num_people;
	cout << "Введите количество мест в одном автобусе: ";
	cin >> num_seats;

	num_buses = ceil(float(num_people) / num_seats);
	cout << "\nНам потребуется: " << num_buses << " автобус(а/ов)" << endl;

	num_free_seats = (num_buses * num_seats) - num_people;
	cout << "Свободных мест осталось:: " << num_free_seats << endl;

	return 0;
}