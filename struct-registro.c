#include <stdio.h>
#include <stdlib.h>
#define DIM 10
#define TAMNOTAS 3

/*Desarrollar  un  programa  que  lea  registros  de  alumnos  y  procese  sus  notas.
Se  ingresarán  10 alumnos
de los cuales se ingresa su legajo y 3 notas.
Se pide calcular el promedio de las 3 notas y
guardar el promedio de cada alumno para listarlo al final en la forma “legajo:promedio” y
además mostrar el mayor promedio al final de ese listado resaltado.*/

 typedef struct{
    int legajo;
    int notas[3];
    int promedio;
 }registro;

 void cargarRegistro(registro alumno[]);
 void mostrarRegistro(registro alumno[]);
  int calcularPromedio(registro alumno[], int* legajoMejorAlum);

 int main()
 {
    registro alumno[DIM];
    int i, maxPromedio,legajoMejorAlum;

    cargarRegistro(alumno);
    maxPromedio=calcularPromedio(alumno,&legajoMejorAlum);
    mostrarRegistro(alumno);

    for(i=0; i<DIM; i++){
        printf("legajo: %d || promedio: %d\n", alumno[i].legajo,alumno[i].promedio);
    }
    printf("el mayor promedio es del alumno: %d con promedio de: %d\n",legajoMejorAlum ,maxPromedio);
 }

 void cargarRegistro(registro alumno[])
 {
     int i, j, legajoAlum, notaAlum;

     for(i=0; i<DIM; i++){
        printf("ingrese el legajo del alumno %d:\n",i+1);
        scanf("%d",&legajoAlum);
        alumno[i].legajo=legajoAlum;

        for(j=0; j<TAMNOTAS; j++){
            printf("ingrese la nota %d:\n",j+1);
            scanf("%d",&notaAlum);
            alumno[i].notas[j]=notaAlum;
        }
    }
 }

 void mostrarRegistro(registro alumno[])
 {
     int i, j;
     for(i=0; i<DIM; i++){
        printf("legajo: %d \n",alumno[i].legajo);
        printf("promedio: %d \n",alumno[i].promedio);
        for(j=0; j<3; j++){
            printf("nota_%d: %d\t",j+1,alumno[i].notas[j]);
        }
        printf("\n\n");
    }
 }

 int calcularPromedio(registro alumno[], int* legajoMejorAlum)
 {
    int i, j, mayorPromedio=0, promedio=0;

     for(i=0; i<DIM; i++){
        promedio=0;
        for(j=0; j<TAMNOTAS; j++){
            promedio+=alumno[i].notas[j];
        }
        alumno[i].promedio=(promedio/TAMNOTAS);
     }

     for(i=0; i<DIM; i++){
            if(i!=0){
                if(mayorPromedio < alumno[i].promedio){
                    mayorPromedio=alumno[i].promedio;
                    *legajoMejorAlum=alumno[i].legajo;
                }
            }else{
                mayorPromedio=alumno[i].promedio;
                *legajoMejorAlum=alumno[i].legajo;
            }
     }

     return mayorPromedio;
 }
