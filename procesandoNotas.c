#include <stdio.h>
#include <stdlib.h>

/*Una escuela  necesita para  una prueba de competencias una aplicación  que procese  notas de alumnos,
para obtener información estadística de cada curso/año.
Para ello, la secretaria se  reúne  con  usted  y  definen  lo  siguiente:
construir  un  programa  que  permita  procesar  5 años  (1ero.  A  5to.).
Por  cada  año  se  ingresan  una  cantidad  desconocida  de  números de legajos de alumnos que finaliza con legajo 0 (cero).
Por cada legajo se ingresa:
a.División a la cual pertenece el alumno (A, B o C), no están ordenados por división
b.Nota (1 a 10)Esta función debe emitir, por cada año, el promedio de notas por cada división.
Al finalizar, emitir el total de notas procesadas, el mayor promedio de todos con su año y división.*/
void obtenerDivision(char* division);
void devolverNotas(int* notas,int* contarDivisionA, int* contarDivisionB, int* contarDivisionC, int* notasA, int* notasB, int* notasC, char division);
int main()
{
    int recorrerCursos=0,legajo=0,notas=0,contarDivisionA=0,contarDivisionB=0,contarDivisionC=0,notasA=0,notasB=0,notasC=0,contarNotas=0,promedioA=0,notaMayor;
    char division;

    for(recorrerCursos=1; recorrerCursos<=5; recorrerCursos++){
        contarDivisionA=0,contarDivisionB=0,contarDivisionC=0,notasA=0,notasB=0,notasC=0;
        printf("Bien, ingrese los legajos del curso %d\n",recorrerCursos);
        do{
            printf("Ingrese legajo del alumno O (0-SALIR):\n");
            scanf("%d",&legajo);
            while(legajo != 0){
                obtenerDivision(&division);
                devolverNotas(&notas,&contarDivisionA,&contarDivisionB,&contarDivisionC,&notasA,&notasB,&notasC,division);
                contarNotas++;
                printf("Ingrese legajo del alumno O (0-SALIR):\n");
                scanf("%d",&legajo);
            }
            if(contarDivisionA == 0) contarDivisionA=1;
            if(contarDivisionB == 0) contarDivisionB=1;
            if(contarDivisionC == 0) contarDivisionC=1;
            printf("promedio del curso %d y divicion A es:%d\n",recorrerCursos,(notasA/contarDivisionA));
            printf("promedio del curso %d y divicion B es:%d\n",recorrerCursos,(notasB/contarDivisionB));
            printf("promedio del curso %d y divicion B es:%d\n",recorrerCursos,(notasC/contarDivisionC));
        }while(legajo != 0);
    }
    printf("total de notas procesadas es:%d",contarNotas);
}

void obtenerDivision(char* division)
{
    do{
    printf("Ingrese la division a la cual pertenece el alumno A || B || C:\n");
    fflush(stdin);
    scanf("%c",division);
    }while((*division) != 'a' && (*division) != 'b' && (*division) != 'c');
}

void devolverNotas(int* notas, int* contarDivisionA, int* contarDivisionB, int* contarDivisionC, int* notasA, int* notasB, int* notasC,char division)
{
    do{
        printf("ingrese una nota entre 1 Y 10:\n");
        scanf("%d",notas);
    }while((*notas) < 1 || (*notas) > 10);

    switch(division){
        case 'a': (*contarDivisionA)++; (*notasA)+=(*notas); printf("----%d-----\n",*notasA);
            break;
        case 'b': (*contarDivisionB)++; (*notasB)+=(*notas); printf("----%d-----\n",*notasB);
            break;
        case 'c': (*contarDivisionC)++; (*notasC)+=(*notas); printf("----%d-----\n",*notasC);
            break;

    }
}
