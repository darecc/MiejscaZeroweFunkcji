#include <iostream>
#include <string>
#include <stdio.h>
#include "funkcje.h"

int main(int argc, char** argv) {

	int steps = 0;
	double a = 0;
	double b = 20;
	double epsilon = 0.0001;
	double res = bisekcja(a, b, epsilon,steps);
	printf("\n\nRozwi¹zanie: f(%f) = %f",res,f(res));
	printf("\n\nW %i krokach",steps);
	
	char c;
	scanf("%c", &c);
}
