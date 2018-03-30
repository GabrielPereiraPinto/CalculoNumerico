#define _XOPEN_SOURCE 500
#include <stdio.h>
#include<stdlib.h>
#include <math.h>
#include "lib.h"


void euler_flt() {

	FILE *gnuplot = popen("gnuplot -persistent", "w");

	fprintf(gnuplot, "set terminal png \nset output 'euler_flt.png'\nset logscale x\n");

	fprintf(gnuplot, "plot '-' w l\n");

	float euler = 0.0;
	float n;

	for (int i = 0; i < 21; i++) {
		n = pow(10, i);
		euler = pow((1 + (1 / n)), n);

		fprintf(gnuplot, "%f %f\n", n, euler);
	}

	fprintf(gnuplot, "e");

	pclose(gnuplot);
}

void euler_dbl() {

	FILE *gnuplot = popen("gnuplot -persistent", "w");

	fprintf(gnuplot, "set terminal png\nset output 'euler_dbl.png'\nset logscale x\n");

	fprintf(gnuplot, "plot '-' w l\n");

	double euler = 0.0;
	double n;

	for (int i = 0; i < 21; i++) {
		n = pow(10, i);
		euler = pow((1 + (1 / n)), n);

		fprintf(gnuplot, "%lf %lf\n", n, euler);
	}

	fprintf(gnuplot, "e");

	pclose(gnuplot);

}

void euler_ldbl() {

	FILE *gnuplot = popen("gnuplot -persistent", "w");

	fprintf(gnuplot, "set terminal png \nset output 'euler_ldbl.png'\nset logscale x\n");

	fprintf(gnuplot, "plot '-' w l\n");

	long double euler = 0.0;
	long double n;

	for (int i = 0; i < 21; i++) {
		n = powl(10, i);
		euler = powl((1 + (1 / n)), n);

		fprintf(gnuplot, "%Lf %Lf\n", n, euler);
	}

	fprintf(gnuplot, "e");

	pclose(gnuplot);

}