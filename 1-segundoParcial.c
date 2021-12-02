#include <stdio.h>
#include <stdlib.h>

/*El geólogo Máximo Roca está estudiando un predio de 20 x 50 hectáreas para analizar la posibilidad de explotar una mina de oro.
Para ello mapea el área y por cada hectárea anota:
densidad de flora, densidad de fauna, densidad de roca y densidad de metales. Las densidades se miden de 0 a 9.
Se pide un programa que implemente:
-Una función para cargar los valores de una hectárea en una entidad hectárea (crear una hectárea).
-Una función que ubique una hectárea en su respectivo lugar del mapa.
-Una función que obtenga la hectárea con mayor vida (flora + fauna).
-Una función que obtenga la hectárea más “metalosa”.
-Una función que obtenga la hectárea más prometedora (aquella que tiene una relación metalosa/vida más alta).
-Utilice las funciones anteriores para desarrollar un programa que pueda cargar un mapa
 con los valores de las hectáreas y mostrar la hectárea con más vida,
 la más “metalosa” y la más prometedora.
 IMPORTANTE: Prohibido utilizar variables globales. Utilice memoria estática, estructuras, punteros y funciones según necesite.
 Se evalúa el diseño de la solución. Para aprobar es necesario implementar al menos el 60% de las funcionalidades requeridas
 y que funcionen correctamente*/

 typedef struct{
     int denFlora;
     int denFauna;
     int denRoca;
     int denMetales;
     int vida;
 }Densidades;

void mostrarMenu();
void buscarOpcionMenu(int opcMenu, Densidades mapa[20][50]);
void inicializarMapa(Densidades mapa[20][50]);
void cargarHectarea(Densidades mapa[20][50]);
void ubicarHectarea(int dFlora,int dFauna,int dRoca,int dMetales, Densidades mapa[20][50]);
void hectareaMayorVida(Densidades mapa[20][50]);
void HectareaMetalosa(Densidades mapa[20][50]);
void hectareaPrometedora(Densidades mapa[20][50]);
void verMapa(Densidades mapa[20][50]);

int main()
{
    Densidades mapa[20][50];
    int opcMenu;

    inicializarMapa(mapa);

    do{
        mostrarMenu();
        scanf("%d",&opcMenu);
        if(opcMenu!=0)buscarOpcionMenu(opcMenu,mapa);
    }while(opcMenu != 0);
}

void mostrarMenu()
{
    printf("1)- Cargar una hectarea:\n");
    printf("2)- Hectarea con mayor vida:\n");
    printf("3)- Hectarea mas metalosa:\n");
    printf("4)- Hectarea mas prometedora:\n");
    printf("5)- Ver mapa (RECORDATORIO se va a ver mal por que son muchas hectareas.)\n");
    printf("0)- SALIR\n");
}

void buscarOpcionMenu(int opcMenu, Densidades mapa[20][50])
{
    switch(opcMenu){
        case 1: cargarHectarea(mapa);
            break;
        case 2: hectareaMayorVida(mapa);
            break;
        case 3: HectareaMetalosa(mapa);
            break;
        case 4: hectareaPrometedora(mapa);
            break;
        case 5: verMapa(mapa);
            break;
        default: printf("opcion incorrecta\n");
            break;
    }
}

void inicializarMapa(Densidades mapa[20][50])
{
    printf("Aca tiene su mapa de 20 por 50 hectareas:\n");
    int i,j ;
    for(i=0; i<20; i++){
        for(j=0; j<50; j++){
            mapa[i][j].denFlora=0;
            mapa[i][j].denFauna=0;
            mapa[i][j].denRoca=0;
            mapa[i][j].denMetales=0;
            mapa[i][j].vida=0;
            printf("0|",j);
        }
        printf("\n");
    }
    printf("\n\n");
}

void cargarHectarea(Densidades mapa[20][50])
{
    int dFlora, dFauna, dRoca, dMetales;

    printf("recuerde que las densidades se miden de 0 a 9:\n");
    printf("ingrese la densidad de flora:\n");
    scanf("%d",&dFlora);
    printf("ingrese la densidad de fauna:\n");
    scanf("%d",&dFauna);
    printf("ingrese la densidad de roca:\n");
    scanf("%d",&dRoca);
    printf("ingrese la densidad de metales:\n");
    scanf("%d",&dMetales);

    ubicarHectarea(dFlora,dFauna,dRoca,dMetales,mapa);

}

void ubicarHectarea(int dFlora,int dFauna,int dRoca,int dMetales, Densidades mapa[20][50])
{
    int x,y;

    printf("\n POSICIONEMOS SU HECTAREA:\n");
    printf("ingrese la posicion horizontal:\n");
    scanf("%d",&y);
    printf("ingrese la posicion vertical:\n");
    scanf("%d",&x);

    mapa[x][y].denFlora=dFlora;
    mapa[x][y].denFauna=dFauna;
    mapa[x][y].denRoca=dRoca;
    mapa[x][y].denMetales=dMetales;
    mapa[x][y].vida=dFlora+dFauna;
}

void hectareaMayorVida(Densidades mapa[20][50])
{
    int i, j, posV=0, posH=0,aux;

    aux=mapa[0][0].vida;


    for(i=0; i<20; i++){
        for(j=0; j<50; j++){
            if(mapa[i][j].vida>aux){
                posV=i;
                posH=j;
                aux=mapa[i][j].vida;
            }
        }
    }

    printf("la hectarea con mayor vida se encuentra en la posicion horizontal %d, y posicion vertical %d\n",posV,posH);
}


void HectareaMetalosa(Densidades mapa[20][50])
{
    int i,j,aux,masMetalosa, posV=0,posH=0;

    aux=mapa[0][0].denMetales;

    for(i=0; i<20; i++){
        for(j=0; j<50; j++){
            if(mapa[i][j].denMetales>aux){
                posV=i;
                posH=j;
                aux=mapa[i][j].denMetales;
            }
        }
    }
     printf("la hectarea mas metalosa se encuentra en la posicion Horizontal %d, y posicion vertical %d\n",posH,posV);
}

void hectareaPrometedora(Densidades mapa[20][50])
{
    int i,j,aux,hecPrometedora, posV=0,posH=0;

    aux=0;

    for(i=0; i<20; i++){
        for(j=0; j<50; j++){
            if(mapa[i][j].vida!=0 && mapa[i][j].denMetales!=0){
                if((mapa[i][j].denMetales/mapa[i][j].vida)>aux){
                    posV=i;
                    posH=j;
                    aux=(mapa[i][j].denMetales/mapa[i][j].vida);
                    printf("%d-%d-%d",i,j,mapa[i][j].denMetales/mapa[i][j].vida);
                }
            }
        }
    }
     printf("la hectarea mas prometedora se encuentra en la posicion horizontal %d, y posicion vertical %d\n",posV,posH);
}

void verMapa(Densidades mapa[20][50])
{
    int i,j;
    for(i=0; i<20; i++){
        for(j=0; j<50; j++){
            printf("%d%d%d%d%d|",mapa[i][j].denFlora,mapa[i][j].denFauna,mapa[i][j].denRoca,mapa[i][j].denMetales,mapa[i][j].vida);
        }
        printf("\n");
    }
}
