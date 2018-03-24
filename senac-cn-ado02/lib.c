#include <stdio.h>
#include<stdlib.h>
#include <math.h>
#include "lib.h"

double fatorial(double x) {


	if (x == 0 || x == 1)
		return 1;

	else
		return (x * fatorial(x - 1));
}

double sen(double x) {

	double resultado = 0;
	double temp = 0;
	for (int n = 0; n < 20; n++) {
		temp = 2 * n + 1;
		resultado += (pow(-1, n) * pow(x, temp) / fatorial(temp));
	}

	return resultado;
}

double cos(double x) {

	double resultado = 0;
	double temp = 0;
	for (int n = 0; n < 20; n++) {
		temp = 2 * n;
		resultado += (pow(-1, n) * pow(x, temp) / fatorial(temp));
	}

	return resultado;
}