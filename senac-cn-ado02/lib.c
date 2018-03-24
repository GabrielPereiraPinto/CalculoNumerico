#include <stdio.h>
#include<stdlib.h>
#include <math.h>
#include "lib.h"

double fatorial(double x) {

	if (x == 0)
		return 1;
	
	double atual = x;
	double resultado = 1;

	while (atual > 0) {
		resultado *= atual;
		atual--;
	}
	return resultado;

}

double sen(double x) {

	double resultado = 0;
	double temp = 0;
	for (int n = 0; n < 15; n++) {
		temp = 2 * n + 1;
		resultado += (pow(-1, n) * pow(x, temp) / fatorial(temp));
	}

	return resultado;
}

double cos(double x) {

	double resultado = 0;
	double temp = 0;
	for (int n = 0; n < 15; n++) {
		temp = 2 * n;
		resultado += (pow(-1, n) * pow(x, temp) / fatorial(temp));
	}

	return resultado;
}