#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>
#include <windows.h>
int zufall(int range) {
	int erg;
	erg = rand() % range + 1;
	return erg;
}
int eingabe(int type) {
	int eing;
	switch (type) {
	case 1:
		do {
			printf("Gew%cnschter Bereich:\n", 129);
			scanf_s("%i", &eing);
			if (eing <= 7)
				printf("\aFalsche Eingabe!\n");
		} while (eing <= 7);
		break;
	case 2:
		printf("Beenden?\n1: ja\n2: nein\n");
		scanf_s("%i", &eing);
		break;
	default:
		eing = 0;
		break;
	}
	return eing;
}
bool gewinn(int range) {
	int rand1 = 0, rand2 = 0, rand3 = 0;
	bool exit = false;
	printf("Enter zum Start von Zahl 1\n");
	system("pause >nul");
	printf("Enter zum Stoppen!\n");
	Sleep(500);
	while (_kbhit() == 0){
		rand1 = zufall(range);
		printf("%2i\r", rand1);
		fflush(stdout);
		Sleep(100);
	}
	printf("\n\n%i\n\n", rand1);
	printf("Enter zum Start von Zahl 2\n");
	system("pause >nul");
	printf("Enter zum Stoppen!\n");
	Sleep(500);
	while (_kbhit() == 0) {
		rand2 = zufall(range);
		printf("%i\r", rand2);
		fflush(stdout);
		Sleep(100);
	}
	printf("\n\n%i\n\n", rand2);
	printf("Enter zum Start von Zahl 3\n");
	system("pause >nul");
	printf("Enter zum Stoppen!\n");
	Sleep(500);
	while (_kbhit() == 0) {
		rand3 = zufall(range);
		printf("%2i\r", rand3);
		fflush(stdout);
		Sleep(100);
	}
	printf("\n\n%i\n\n", rand3);
	printf("\n");
	if (rand1 == 7 && rand2 == 7 && rand3 == 7)
		return true;
	else
		return false;
}

void start() {
	printf("AIT19A - illegaler Gl%csspielring \n", 129);
}

int main() {
	bool gewinn_main;
	int range_main, wdh_main;
	const char ch[] = "dml7";
	do {
		start();
		range_main = eingabe(1);
		gewinn_main = gewinn(range_main);
		if (gewinn_main == true)
			printf("\n\n\aGewinn!\n\n");
		else
			printf("\n\nNiederlage\n\n");
		wdh_main = eingabe(2);
	} while (wdh_main != 1);
	return 0;
}
