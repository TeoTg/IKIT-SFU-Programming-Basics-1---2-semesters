/* 5. По введенным с клавиатуры курсу доллара и евро на текущий день и имеющуюся рублевую сумму, 
и рассчитать, сколько долларов и сколько евро можно купить на эти деньги.*/

#include "pch.h"
#include <iostream>
#include <locale>

int main() {
	setlocale(LC_ALL, "rus");

	float usd, eur, sum, quantityUSD, quantityEUR;

	printf("Введите курс доллара: ");
	scanf_s("%f", &usd);
	printf("Введите курс евро: ");
	scanf_s("%f", &eur);
	printf("Введите рублевую сумму: ");
	scanf_s("%f", &sum);

	quantityUSD = sum / usd;
	quantityEUR = sum / eur;

	printf("Вы можете приобрести: %f", quantityUSD);
	printf(" долларов\n");
	printf("Вы можете приобрести: %f", quantityEUR);
	printf(" евро");


	return 0;
}
