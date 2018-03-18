#include <stdio.h>
#include <stdlib.h>
#include "lib.h"


int main() {   

    int baseAtual,baseDesejada;
    long int NumeroBase10;
    char* NumeroInicial[12];

	printf("n2m ");
    scanf ("%c %d %d", &NumeroInicial, &baseAtual, &baseDesejada);
    printf("\n");

    if (baseAtual >= 2 && baseAtual <= 36 && baseDesejada >= 2 && baseDesejada <= 36){
        return 1;
    }

    NumeroBase10 = convertToTen(NumeroInicial, baseAtual);

    if (NumeroBase10 <= ( pow ( 2 , 36 ) ) && NumeroBase10 >= 0 ){               
       
       convertToBase(NumeroBase10, baseDesejada);
       return 0;
    }   

    return 1;
}