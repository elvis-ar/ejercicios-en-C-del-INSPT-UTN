#include <stdio.h>
#include <stdlib.h>
#define DIM 10
/*El ejército de EE. UU. necesita desarrollar un programa para modelar el avance de sus tropas en el frente  de  batalla.
Para ello se requiere  que  el programa  modele un  mapa  de  10 x  10  km.
En dicho mapa se deberán modelar la cantidad de tropas.
Cada tropa puede tener una cantidad de soldados,  otra  cantidad  de  humvees  y  otra  cantidad  de  tanques.
Con  este  programa,  el comandante de la ofensiva puede armar tropas y ubicarlas en el mapa para un ataque efectivo.
Además, cada tropa debe poder identificase como “aliado” o “enemigo”,
de manera que el comandante pueda evaluar la cantidad de fuerzas aliadas y enemigas con el mismo programa.*/
typedef struct{
    int soldado;
    int humvees;
    int tanques;
    char bando;
}Tropa;

void diagramarMapa(Tropa mapa[DIM][DIM], int dimV, int dinH);
void cargarTropa(Tropa mapa[DIM][DIM]);
void mostrarMapa(Tropa mapa[DIM][DIM], int dimV, int dimH);
void contarAliados(Tropa mapa[DIM][DIM]);
void contarEnemigos(Tropa mapa[DIM][DIM]);

int main()
{
    Tropa mapa[DIM][DIM];
    diagramarMapa(mapa,DIM,DIM);
    int opcionMenu;

    do{
        printf("\n\n");
        printf("1)- Cargar tropa\n");
        printf("2)- Mostrar mapa\n");
        printf("3)- Contar aliados\n");
        printf("4)- Contar enemigos\n");
        printf("0)- SALIR\n");
        scanf("%d",&opcionMenu);
        printf("\n");

        switch(opcionMenu){
            case 1: cargarTropa(mapa);
                break;
            case 2: mostrarMapa(mapa,DIM,DIM);
                break;
            case 3: contarAliados(mapa);
                break;
            case 4: contarEnemigos(mapa);
                break;
        }
    }while(opcionMenu != 0);


    return 0;
}

void diagramarMapa(Tropa mapa[DIM][DIM], int dimV, int dimH)
{
    int i, j;

    for(i=0; i<dimV; i++){
        printf("%d: ",i);
        for(j=0; j<dimH; j++){
            mapa[i][j].soldado=0;
            mapa[i][j].humvees=0;
            mapa[i][j].tanques=0;
            mapa[i][j].bando='-';

            printf("S:%dH:%dT:%dB:%c |", mapa[i][j].soldado, mapa[i][j].humvees, mapa[i][j].tanques, mapa[i][j].bando);
        }
        printf("\n");

    }
}

void mostrarMapa(Tropa mapa[DIM][DIM], int dimV, int dimH)
{
    int i, j;

    for(i=0; i<dimV; i++){
        printf("-%d-: ",i);
        for(j=0; j<dimH; j++){
            printf("S:%dH:%dT:%dB:%c |", mapa[i][j].soldado, mapa[i][j].humvees, mapa[i][j].tanques, mapa[i][j].bando);
        }
        printf("\n");
    }
}

void cargarTropa(Tropa mapa[DIM][DIM])
{
    int soldados, tanques, humvees, posV, posH;
    char bando;

    printf("ingrese la cantidad de soldados que tiene su tropa:\n");
    scanf("%d",&soldados);
    printf("ingrese la cantidad de humvees que tiene su tropa:\n");
    scanf("%d",&humvees);
    printf("ingrese la cantidad de tanques que tiene su tropa:\n");
    scanf("%d",&tanques);
    do{
        printf("ingrese el bando de su tropa:\n");
        fflush(stdin);
        scanf("%c",&bando);
        if(bando != 'a' && bando != 'e')printf("se debe ingresar A o E\n");
    }while(bando != 'a' && bando != 'e');
    do{
        printf("ingrese la posicion vertical en la que va a insertar su tropa:\n");
        scanf("%d",&posV);
        printf("ingrese la posicion horizontal en la que va a insertar su tropa:\n");
        scanf("%d",&posH);
        if(posV < 0 || posV > 9 || posH < 0 || posH > 9)printf("recuerde cargar con valores entre 1 y 9\n");
    }while(posV < 0 || posV > 9 || posH < 0 || posH > 9);

    mapa[posH][posV].soldado=soldados;
    mapa[posH][posV].humvees=humvees;
    mapa[posH][posV].tanques=tanques;
    mapa[posH][posV].bando=bando;
}

void contarAliados(Tropa mapa[DIM][DIM])
{
    int conAliados=0,i,j;

    for(i=0; i<DIM; i++){
        for(j=0; j<DIM; j++){
            if(mapa[i][j].bando == 'a')conAliados++;
        }
    }
    printf("las tropas ALIADAS que tiene son: %d\n", conAliados);
}

void contarEnemigos(Tropa mapa[DIM][DIM])
{
    int conEnemigos=0,i,j;

    for(i=0; i<DIM; i++){
        for(j=0; j<DIM; j++){
            if(mapa[i][j].bando == 'e')conEnemigos++;
        }
    }
    printf("las tropas ENEMIGAS que tiene son: %d\n", conEnemigos);
}
