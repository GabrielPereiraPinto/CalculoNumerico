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

		if (baseAtual >= 2 && baseAtual <= 36 && baseDesejada >= 2 && baseDesejada <= 36) {
			printf("Bases Invalidas, menores do que 2 ou maiores do que 36 \n");
			return 1;
		}

		NumeroBase10 = convertToTen(argv[1], baseAtual);

		if (NumeroBase10 <= (Exponencial(2, 36)) && NumeroBase10 >= 0) {

			convertToBase(NumeroBase10, baseDesejada);

			
			return 0;
		}		

		printf("Numero Invalido, menor do que 0 ou maior do que 2^32 \n");
		return 1;
	}
}