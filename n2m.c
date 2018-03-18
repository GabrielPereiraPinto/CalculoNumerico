#include <stdio.h>
#include <stdlib.h>
#include "lib.h"



int main() {
    int baseAtual,baseDesejada,temp;
    char* NumeroInicial[12];

	printf("n2m");
    scanf ("%c %d %d", &NumeroInicial, &baseAtual, &baseDesejada);

    if (baseAtual >= 2 && baseAtual <= 36 && baseDesejada >= 2 && baseDesejada <= 36){
        return 1;
    }

    temp = convertToTen(NumeroInicial, baseAtual);

    if (temp <= ( pow ( 2 , 36 ) ) && temp >= 0 ){
        
        
        printf("\n");


        return 0;
    }
   

    return 1;
}