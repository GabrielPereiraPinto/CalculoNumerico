#define _XOPEN_SOURCE 500

#include <stdio.h>
#include<stdlib.h>
#include <math.h>
#include "lib.h"

int main() {


	//FILE *filePath;
	//filePath = fopen("seno.dat", "w");
	//filePath = fopen("seno.dat", "a");

	for (int i = 0; i < 721; i++) {

		double rad = i * (pi / 180);
		double seno = sen(rad);
		double erroAbsoluto = fabs(sin(rad) - sen(rad));
		double erroRelativo = fabs(erroAbsoluto / sen(rad));/*
		fprintf(filePath, "%d\t%f\t%f\t%f\n", i, sen(rad), erroAbsoluto, erroRelativo);*/
	}

	//fclose(filePath);

	//filePath = fopen("cosseno.dat", "w");
	//filePath = fopen("cosseno.dat", "a");

	for (int i = 0; i < 721; i++) {

		double rad = i * (pi / 180);
		double cosseno = cos(rad);
		double erroAbsoluto = fabs(cos(rad) - cos(rad));
		double erroRelativo = fabs(erroAbsoluto / cos(rad));
		/*fprintf(filePath, "%d\t%f\t%f\t%f\n", i, cos(rad), erroAbsoluto, erroRelativo);*/
	}

	//fclose(filePath);

	//free(filePath);


	//FILE *gnuplot = popen("gnuplot -persistent", "w");
	//fprintf(gnuplot, "%s\n%s", "set terminal png size 400,300\nset output 'seno.png'", "plot 'seno.dat'\n");
	//fprintf(gnuplot, "%s\n%s", "set terminal png size 400,300\nset output 'cosseno.png'", "plot 'cosseno.dat'");

	exit(0);
}