#include "pch.h"
#include <cstdio>
#include <clocale>


int main() {
	setlocale(LC_ALL, "rus");

	int firstNum, secondNum, sum, diff, comp;
	float average;

	printf("Введите первое число: \n");
	scanf_s("%d", &firstNum);
	printf("Введите второе число: \n");
	scanf_s("%d", &secondNum);

	sum = firstNum + secondNum;
	comp = firstNum * secondNum;
	average = float(firstNum + secondNum) / 2;
	diff = firstNum - secondNum;

	printf("\nСумма чисел = %d\n", sum);
	printf("Сумма чисел = %10d\n", sum);
	printf("Сумма чисел = %-10d\n\n", sum);

	printf("Разность чисел = %d\n", diff);
	printf("Разность чисел = %10d\n", diff);
	printf("Разность чисел = %-10d\n\n", diff);

	printf("Произведение чисел = %d\n", comp);
	printf("Произведение чисел = %10d\n", comp);
	printf("Произведение чисел = %-10d\n\n", comp);

	printf("Среднее арифметическое чисел = %f\n", average);
	printf("Среднее арифметическое чисел = %15.4f\n", average);
	printf("Среднее арифметическое чисел = %-15.4f\n", average);
	printf("Среднее арифметическое чисел = %0.15f\n", average);
	printf("Среднее арифметическое чисел = %30.15f\n", average);

	return 0;
}