#include <stdio.h>
#include <stdlib.h>


void mostrarVector(int* vector, int tam);
void ordenarVector(int* vector, int tam);

int main()
{
    int i;       // vector cargado manual
    int vec[10];//={10,9,8,7,6,5,4,3,2,1};

    //cargandio el vector de forma aleatorea
    for(i=0; i<10; i++){
        vec[i]=10+rand()%(35-10+1);
    }

    printf("vector sin ordenar:\n");
    mostrarVector(vec,10);
    printf("\n\n");

    ordenarVector(vec,10);

    printf("vector ordenado:\n");
    mostrarVector(vec,10);
    printf("\n\n");

    return 0;
}

void mostrarVector(int* vector, int tam)
{
    int i;

    for(i=0; i<tam; i++){
        printf("%d ",vector[i]);
    }
}

void ordenarVector(int* vector, int tam)
{
    int i, flag, aux;
    flag = 1;

    while(flag != 0){
        flag = 0;
        for(i=0; i<tam-1; i++){
            if(vector[i+1] < vector[i]){
                flag = 1;
                aux=vector[i];
                vector[i]=vector[i+1];
                vector[i+1]=aux;
            }
        }
    }
}
