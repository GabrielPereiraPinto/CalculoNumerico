#define _XOPEN_SOURCE 500

#include <stdio.h>
#include<stdlib.h>
#include <math.h>
#include "lib.h"

int main() {


	FILE *filePath;
	filePath = fopen("seno.dat", "w");
	filePath = fopen("seno.dat", "a");

	for (int i = 0; i < 721; i++) 
	{

		double rad = i * (pi / 180);
		double seno = sen(rad);
		double senFunc = sin(rad);
		double erroAbsoluto = ((double)fabs(senFunc - seno));
		double erroRelativo = ((double)fabs(erroAbsoluto / seno));
		fprintf(filePath, "%d\t%f\t%f\t%f\n", i, seno, erroAbsoluto, erroRelativo);
	}

	fclose(filePath);

	filePath = fopen("cosseno.dat", "w");
	filePath = fopen("cosseno.dat", "a");

	for (int i = 0; i < 721; i++) {

		double rad = i * (pi / 180);
		double cosseno = coss(rad);
		double cosFunc = cos(rad);
		double erroAbsoluto = ((double)fabs(cosFunc - cosseno));
		double erroRelativo = ((double)fabs(erroAbsoluto / cosseno));
		fprintf(filePath, "%d\t%f\t%f\t%f\n", i, cosseno, erroAbsoluto, erroRelativo);
	}

	fclose(filePath);

	free(filePath);


	FILE *gnuplot = popen("gnuplot -persistent", "w");
	fprintf(gnuplot, "%s\n%s", "set terminal png size 400,300\nset output 'seno.png'", "plot 'seno.dat'\n");
	fprintf(gnuplot, "%s\n%s", "set terminal png size 400,300\nset output 'cosseno.png'", "plot 'cosseno.dat'");

	exit(0);
}