#include <stdio.h>
#include <stdlib.h>
#define TAMVEC 10

/*Escribe un programa con un menú que defina las siguientes funciones y emita los resultados,
la dimensión del vector será de 10 (elementos):
a)Cargar m elementos de un vector por teclado.
Deberá considerar que no podrá superar el máximo de elementos de vector: void cargar(int vect[], int unNum);
b)Leer  elementos  de  un  vector  hasta  encontrar  el  número  entero a.
Deberá  retornar  el número   de   elementos   que   ha   leído   sin  contar   el   entero   a. int  leerMarca(int vect[]);
c)Dado  un  elemento  y  dado  un  vector  de  enteros, desarrolle una  función  que  devuelva  el número  de  apariciones  del  elemento  en  el  vector.
int  veces(int  valor,  int vect[], int unNum);
d)Invertir los elementos del vector sin utilizar otro vector. Por ejemplo, el vector formado por los  enteros:  1  2  3,  debe  quedar  3  2  1.
void invertirOrden(int  vect[],  int unNum);*/

void llamarMenu(int* opcMenu);
void buscarOpcionMenu(int opcMenu, int* vector, int* unNum);
void cargarVec(int* vector, int* cantElementos);
void leerVector(int* vector, int* cantElementos);
int  leerMarca(int* vector, int* TAM);
int contarRepeticiones(int* vector);
void invertirVector(int* vector,int* TAM);


int main()
{
    int vector[TAMVEC]={1,2,3,4,5,6,7,8,9,10}, opcMenu, unNum=0;

    do{
        printf("Elija una opcion del menu o 0 para salir:\n");
        llamarMenu(&opcMenu);
        buscarOpcionMenu(opcMenu,vector,&unNum);
    }while(opcMenu != 0);
}

void llamarMenu(int* opcMenu)
{
    do{
        printf("1- Cargar numeros en el vector\n");
        printf("2- Leer vector\n");
        printf("3- Leer hasta\n");
        printf("4- Contar repeticiones\n");
        printf("5- Invertir vector\n");
        printf("0- SALIR\n");
        scanf("%d",opcMenu);
    }while((*opcMenu)<0 || (*opcMenu)>5);
}

void buscarOpcionMenu(int opcMenu, int* vector, int* unNum)
{
    switch(opcMenu){
        case 1: cargarVec(vector,unNum);
            break;
        case 2: leerVector(vector,unNum);
            break;
        case 3: leerMarca(vector,unNum);
            break;
        case 4: contarRepeticiones(vector);
            break;
        case 5: invertirVector(vector,unNum);
            break;
    }
}
void cargarVec(int* vector, int* cantElementos)
{
    int i=0,j;
    do{
        printf("recuerde que la cantidad de elementos debe ser entre 1 y 10:\n");
        printf("cuantos elementos desea agregar al vector:\n");
        scanf("%d",cantElementos);
    }while((*cantElementos) < 1 || (*cantElementos) > 10);

    for(i=0; i<(*cantElementos); i++){
        printf("ingrese el valor de la posicion %d:\n",i);
        scanf("%d",&vector[i]);
    }
}

void leerVector(int* vector, int* cantElementos)
{
    int i;
    if(*cantElementos == 0){
        printf("no ha modificado el vector:\n");
        for(i=0; i < TAMVEC; i++){
            printf("%d----%d\n",i,vector[i]);
        }
    }else{
        printf("los numeros han sido modificados por estos:\n");
        for(i=0; i < (*cantElementos); i++){
            printf("%d----%d\n",i,vector[i]);
        }
    }
}

int  leerMarca(int* vector, int* TAM)
{
    int i,contador=0,limite;
        if(*TAM != 0){
        printf("hasta que numero desea buscar:\n");
        scanf("%d",&limite);

        for(i=0; i<*TAM && limite!=vector[i]; i++){
            if(limite != vector[i]){
                contador++;
            }
        }

        if(i<*TAM){
            printf("tiene %d numeros antes que el %d\n",contador, limite);
        }else{
            printf("el numero ingresado no se encuentra en el vector\n");
        }
    }else{

    }
}

int contarRepeticiones(int* vector)
{
    int contRepeticiones=0, i, num;

    printf("que numero desea buscar cuantas veces se repite:\n");
    scanf("%d",&num);

    for(i=0; i<TAMVEC; i++){
        if(num == vector[i]){
            contRepeticiones++;
        }
    }
    if(contRepeticiones==0){
        printf("el numero ingresado no se encuentra en el vector\n");
    }else{
        printf("el numero %d, se repite %d\n", num, contRepeticiones);
        }
}

void invertirVector(int* vector,int* TAM)
{
    int i, invertir=(*TAM-1);
    for(i=0; i< *TAM; i++){
        printf("------%d----%d\n",vector[i],vector[invertir]);
        invertir--;
    }

}
