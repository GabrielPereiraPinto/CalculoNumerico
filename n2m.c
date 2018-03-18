#include <stdio.h>
#include <stdlib.h>
#include "lib.h"

int main(int argc, char *argv[]
) {

	if (argc < 4) {
		printf("Argumentos insuficientes\n");
		return 1;
	}

	else if (argc > 4) {
		printf("Argumentos em excesso \n");
		return 1;
	}

	else{
		int baseAtual = atoi(argv[2]);
		int baseDesejada = atoi(argv[3]);;
		long int NumeroBase10 = 0;

		printf("\n");

		if (baseAtual <= 2 &&  baseAtual>=36){
			printf("Bases atual invalida, menor do que 2 ou maior do que 36 \n");
			return 1;
		}
		if (baseDesejada <= 2 && baseDesejada >= 36){
			printf("Bases atual invalida, menor do que 2 ou maior do que 36 \n");
			return 1;
		}

		if (baseAtual != 10)
			NumeroBase10 = convertToTen(argv[1], baseAtual);

		else
			NumeroBase10 = atoi(argv[1]);

		if (NumeroBase10 <= 68719476736 && NumeroBase10 >= 0) {

			convertToBase(NumeroBase10, baseDesejada);

			
			return 0;
		}		

		printf("Numero Invalido, menor do que 0 ou maior do que 2^32 \n");
		return 1;
	}
}