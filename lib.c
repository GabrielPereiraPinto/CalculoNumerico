#include <stdio.h>
#include <string.h>
#include <math.h>
#include "lib.h"



long int convertToTen (char *NumeroInicial, int baseAtual ){
    long int NumeroBase10 = 0;

    for (int i = 0; strlen(NumeroInicial); i++){
        NumeroBase10 += convertToDecimal(NumeroInicial[strlen(NumeroInicial) - 1 - i ]) * pow (baseAtual,i);
    }

    return NumeroBase10;
}


int convertToDecimal (char digito){

    if (digito >= '0' && digito <= '9')
        return (int) digito - '0';

    else
        return (int) digito - 'A'+10;

}

void convertToBase(long int NumeroBase10, int baseDesejada){

char base_digits[36] =
	 {'0', '1', '2', '3', '4', '5', '6', '7',
	  '8', '9', 'A', 'B', 'C', 'D', 'E', 'F',
      'G','H','I','J','K','L','M','N','O','P',
      'Q','R','S','T','U','V','X','Y','Z'};

    int index=0;
    int convertido[64];

    while(NumeroBase10 != 0){
            convertido [ index ] = ( NumeroBase10 % baseDesejada ) ;
            NumeroBase10 = NumeroBase10 / baseDesejada ;
            index++;
    }

    --index;
    for( ; index >= 0; index--){

        printf ("%c", base_digits[convertido[index]]);
    }
    printf ("\n");
}




