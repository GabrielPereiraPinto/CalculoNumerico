#include <stdio.h>
#include <stdlib.h>
#include "lib.h"
#include "n2m.h"


int main(int argc, char *argv[]
) {
	char* NumeroInicial = argv[1];
	int baseAtual = atoi(argv[2]);
	int baseDesejada = atoi(argv[3]);;
    long int NumeroBase10 = 0;

    printf("\n");

    if (baseAtual >= 2 && baseAtual <= 36 && baseDesejada >= 2 && baseDesejada <= 36){
		free(NumeroInicial);
        return 1;
    }

    NumeroBase10 = convertToTen(NumeroInicial, baseAtual);

    if (NumeroBase10 <= ( Exponencial ( 2 , 36 ) ) && NumeroBase10 >= 0 ){               
       
       convertToBase(NumeroBase10, baseDesejada);

	   free(NumeroInicial);
       return 0;
    }   
	free(NumeroInicial);
    return 1;
}