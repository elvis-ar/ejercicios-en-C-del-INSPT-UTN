#include <stdio.h>
#include <stdlib.h>
#define TAM 10

/*Escribe un  programa que  almacene, en un vector con  dimensión  10,
los  primeros 10 números de la Quiniela.
El ingreso de los datos será indicando posición-numero,
de modo que puedo ingresar la posición 5 antes que la posición 2.*/

int main()
{
    int vec[TAM];
    int i, indice, valor, j;

    for(i=0; i< TAM; i++){
        do{
        printf("ingrese el indice:\n");
        scanf("%d",&indice);
        }while(indice<0 || indice>=TAM);

        printf("ingrese el valor:\n");
        scanf("%d",&valor);

        vec[indice] = valor;
    }

    for(j=0; j<TAM; j++){
        printf("%d---%d\n",j,vec[j]);
    }
}

