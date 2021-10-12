#include <stdio.h>
#include <stdlib.h>
#define TAMVEC 10

/*Escribe  un  programa  que,  a  partir  de  un  vector  vacío  de  enteros,  permita  insertar  nuevos números  en  posiciones  válidas  del  mismo.
El  programa  emitirá  repetidamente  al  usuario  un menú con cuatro opciones:
a)Insertar delante: Esta opción agrega un número en la primera posición del vector.
    Deberá desplazar, si fuese necesario, el resto de los elementos una posición a la derecha.
    Si el vector estuviese lleno, se perdería su último elemento.
b)Insertar detrás: agrega un nuevo elemento al final del vector, es decir, en la última celda.
    Si el vector estuviese lleno, el elemento se inserta en la última celda del vector y se perdería el elemento que estaba allí anteriormente.
c)Insertar  en  una  posición  dada:  Dado  un  índice  del  vector,  se  debe  insertar  un  nuevo elemento en dicha posición,
    siempre que el nuevo elemento sea contiguo a los ya existentes.
    Por  ejemplo,  si  en el  vector  hay  tres  elementos  (que  ocupan  las  posiciones  0,  1  y  2)  no  se
    permite agregar un elemento en la posición 7 porque no forma una secuencia continua, pero sí se permite en la posición 3.
    Por otra parte, si la posición dada está ocupada, los elementos se deben desplazar una posición a la derecha y,
    si el vector estaba lleno, se pierde el último elemento.
    d)Finalizar el program*/

    void insertarDelante(int* vector);
    void insertarDetras(int* vector);
    void insertarEnIndice(int* vector);
    int main()
    {
        int vector[TAMVEC]={0},i;
        char opcMenu;


        do{
            printf("A) Insertar delante:\n");
            printf("B) Insertar detras:\n");
            printf("C) Insertar en una Posicion dada:\n");
            printf("D) SALIR:\n");
            fflush(stdin);
            scanf("%c",&opcMenu);

            if(opcMenu == 'a' || opcMenu == 'b' || opcMenu == 'c' || opcMenu == 'd'){
                switch(opcMenu){
                    case 'a': printf("hola A\n"); insertarDelante(vector);
                        break;
                    case 'b': printf("hola B\n");insertarDetras(vector);
                        break;
                    case 'c': printf("hola C\n");insertarEnIndice(vector);
                        break;
                }
            }else{
                printf("ha ingresado una opcion INCORRECTA\n\n");
                opcMenu='a';
            }

        }while(opcMenu == 'a' || opcMenu == 'b' || opcMenu == 'c' && opcMenu != 'd');
    }

    void insertarDelante(int* vector)
    {
        int num,i,posSiguiente,aux;

        printf("ingrese un numero:\n");
        scanf("%d",&num);

        posSiguiente=vector[0];
        vector[0]=num;

        for(i=1; i<10; i++){
            aux=vector[i];
            vector[i]=posSiguiente;
            posSiguiente=aux;
        }

        for(i=0; i<TAMVEC; i++){printf("%d--%d\n",i,vector[i]);}
    }

    void insertarDetras(int* vector)
    {
        int num;
        int i=0;

        printf("ingrese un numero:\n");
        scanf("%d",&num);

        /*for(i=0; i<TAMVEC;i++){
            if(vector[i]==0 || vector[i]==vector[9]){
                    vector[i]=num;
                    printf("%d----%d---\n",vector[i], vector[9]);
                    break;
            }
        }*/

        vector[9]=num;
        for(i=0; i<TAMVEC; i++){printf("%d--%d\n",i,vector[i]);}
    }

    void insertarEnIndice(int* vector)
    {
        int posIndice, num, i;

        printf("ingrese la posicion en la que dea poner un numero:\n");
        scanf("%d",&posIndice);
        printf("ingrese el valor de esa posicion:\n");
        scanf("%d",&num);

        vector[posIndice]=num;

        for(i=0; i<TAMVEC;i++){
            if(vector[i]==0 || vector[i]==vector[9]){
                if(vector[i] == vector[posIndice]);
            }
        }
        for(i=0; i<TAMVEC; i++){printf("%d--%d\n",i,vector[i]);}
    }
