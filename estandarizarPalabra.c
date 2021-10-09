#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*diseñar un programa el cual pida una palabra y pongamos la primera letra en Mayuscula y las demas en minusculas*/

void standarizarPalabra(char* palabra);

int main()
{
    char palabra[20];
    printf("ingrese una palabra\n");
    gets(palabra); fflush(stdin);

    standarizarPalabra(palabra);

    printf("%s",palabra);
}

void standarizarPalabra(char* palabra)
{
    int i=0;

    if(palabra[0] > 96 && palabra[0] < 123){
        palabra[0]=palabra[0]-32;
    }

    for(i=1; palabra[i]!='\0'; i++){
        if(palabra[i] > 64 && palabra[i] < 91){
            palabra[i]=palabra[i]+32;
        }
    }
}
