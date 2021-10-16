#include <stdio.h>
#include <stdlib.h>

/*Definir  un  tipo  de  dato  llamado Fecha compuesto  por  3  campos  llamados día, mesy año.
Además    defina    y    desarrolle    sus    operaciones getDia(), getMes(), getAnio()y isBisiesto().*/

typedef struct{
    int dia;
    int mes;
    int anio;
}fecha;

int getDia(){
    int dia;

    do{
     printf("ingrese el dia:\n");
     scanf("%d",&dia);
     if(dia<1 || dia>31)printf("recuerde ingresar dias entre el 1 y el 31\n");
    }while(dia<1 || dia>31);

     return dia;
}

int getMes()
{
    int mes;

    do{
     printf("ingrese el mes:\n");
     scanf("%d",&mes);
     if(mes<1 || mes>12)printf("recuerde ingresar mes entre el 1 y el 12\n");
    }while(mes<1 || mes>12);

     return mes;
}

int getAnio()
{
    int anio;

    do{
     printf("ingrese el anio:\n");
     scanf("%d",&anio);
     if(anio<1899 || anio>2021)printf("recuerde ingresar anio entre el 1899 y el 2021\n");
    }while(anio<1899 || anio>2021);

     return anio;
}
int main()
{
    fecha fechaIngresada;

    fechaIngresada.dia=getDia();
    fechaIngresada.mes=getMes();
    fechaIngresada.anio=getAnio();

    printf("%d/%d/%d",fechaIngresada.dia, fechaIngresada.mes, fechaIngresada.anio);

}
