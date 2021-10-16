#include <stdio.h>
#include <stdlib.h>
#define DIM1 5
#define DIM2 7

/*Mc Donaldnecesita registrar los ingresos de sus 5 sucursales de Mar Del Plata por semana.
Para ello  necesita  un  programa  que  pueda  cargar, en  forma  aleatoria,  los  ingresos  por  día  de  cada sucursal.
Una vez cargados los datos, se pide:
a)Calcular qué sucursal tuvo más ingresos en un día y cual fue ese día
b)Calcular qué sucursal tuvo más ingresos en la semana
c)Calcular el promedio de ventas por día en Mar Del Plata*/

void mostrarDiasSemana(int* opcionDias);
void buscarOpcion(int* opcionDias, int cargarDatos[DIM1][DIM2],int TAM1,int TAM2,int numeroSucursal, int* valorDia);
void calcularIngresosSucursalDia(int cargarDatos[DIM1][DIM2], int* maxIngresosDia, int* sucursal, int* dia);
int maxIngresosSemana(int cargarDatos[DIM1][DIM2],int* maxIngrsesosSemana,int* sucursal);

int main()
{
    int i=0, j=0,k=0, opcionDias=0, numeroSucursal=0, valorDia=0, sucursal=0,dia=0;
    int cargarDatos[DIM1][DIM2];
    int maxIngresosDia,maxIngrsesosSemana=0, ventaTotal;



    for(i=0; i<DIM1; i++){
        for(j=0; j<DIM2; j++){
            cargarDatos[i][j]=0;
        }
    }

    maxIngresosDia=cargarDatos[0][0];

    for(i=0; i<DIM1; i++){
        printf("ingrese el dia que desea cargar de la sucursal: %d\n",i+1);
        numeroSucursal=i;
        mostrarDiasSemana(&opcionDias);
        buscarOpcion(&opcionDias,cargarDatos,DIM1,DIM2,numeroSucursal,&valorDia);
        for(j=0;j<DIM1; j++){
            for(k=0; k<DIM2; k++){
                printf("%d\t",cargarDatos[j][k]);
            }
            printf("\n");
        }


    }
    calcularIngresosSucursalDia(cargarDatos,&maxIngresosDia,&sucursal,&dia);
    printf("el valor que mas fue es: %d y fue el dia: %d en la sucursal: %d\n",maxIngresosDia,dia+1,sucursal+1);
    // retornamos la suma total de todos los dias para despues sacar el promedio
    ventaTotal = maxIngresosSemana(cargarDatos,&maxIngrsesosSemana,&sucursal);
    printf("mas ingresos en la semana fue de la sucursal %d y su ingreso de la semana fue: %d\n", sucursal+1, maxIngrsesosSemana);
    printf("el promedio de vanta por dia en la semana es de %d", ventaTotal/7);
}

void mostrarDiasSemana(int* opcionDias)
{
    do{
    printf("Elija el dia a cargar:\n");
    printf("1)- lunes\n");
    printf("2)- martes\n");
    printf("3)- miercoles\n");
    printf("4)- jueves\n");
    printf("5)- viernes\n");
    printf("6)- sabado\n");
    printf("7)- domingo\n");
    printf("0)- SALIR\n");
    scanf("%d",opcionDias);
    }while(*opcionDias<0 || *opcionDias>7);
}

void buscarOpcion(int* opcionDias, int cargarDatos[DIM1][DIM2],int TAM1,int TAM2,int numeroSucursal, int* valorDia)
{
    int i=1,j=0,k=0;

    while(*opcionDias!=0){
        printf("ingrese el valor del dia\n");
        scanf("%d",valorDia);
        cargarDatos[numeroSucursal][*opcionDias-1]=(*valorDia);
        i++;
        mostrarDiasSemana(opcionDias);
    }
}

void calcularIngresosSucursalDia(int cargarDatos[DIM1][DIM2], int* maxIngresosDia, int* sucursal, int* dia)
{
    int i=0, j=0;

    for(i=0; i<DIM1; i++){
        for(j=0; j<DIM2; j++){
            if(cargarDatos[i][j]>(*maxIngresosDia)){
                (*maxIngresosDia)=cargarDatos[i][j];
                (*dia)=j;
                (*sucursal)=i;
            }
        }
    }
}

int maxIngresosSemana(int cargarDatos[DIM1][DIM2],int* maxIngrsesosSemana,int* sucursal)
{
    int i, j, sumarIngresoDia=0, ventaTotal=0;
        printf("%d  \n",ventaTotal);
    for(i=0; i<DIM1; i++){
            sumarIngresoDia=0;
        for(j=0; j<DIM2; j++){
            sumarIngresoDia += cargarDatos[i][j];
            ventaTotal += cargarDatos[i][j];
            printf("%d  \n",ventaTotal);
        }
        if(sumarIngresoDia > *maxIngrsesosSemana){
            (*maxIngrsesosSemana)=sumarIngresoDia;
            (*sucursal)=i;
        }
    }

    return ventaTotal;
}
