#define _XOPEN_SOURCE 500

#include <stdio.h>
#include<stdlib.h>
#include <math.h>
#include "lib.h"

int main() {


	FILE *filePath;
	filePath = fopen("seno.dat", "a");
	filePath = fopen("seno.dat", "b");

	for (int i = 0; i < 721; i++) {

		double rad = i * (pi / 180);
		double erroAbsoluto = fabs(sin(rad) - sen(rad));
		double erroRelativo = fabs(erroAbsoluto / sen(rad));
		fprintf(filePath, "%d\t%f\t%f\t%f\n", i, sen(rad), erroAbsoluto, erroRelativo);
	}

	fclose(filePath);

	filePath = fopen("cosseno.dat", "a");
	filePath = fopen("cosseno.dat", "b");

	for (int i = 0; i < 721; i++) {

		double rad = i * (pi / 180);
		double erroAbsoluto = fabs(cos(rad) - cos(rad));
		double erroRelativo = fabs(erroAbsoluto / cos(rad));
		fprintf(filePath, "%d\t%f\t%f\t%f\n", i, cos(rad), erroAbsoluto, erroRelativo);
	}

	fclose(filePath);

	free(filePath);

}