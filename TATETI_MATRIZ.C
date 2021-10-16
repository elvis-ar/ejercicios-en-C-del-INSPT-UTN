#include <stdio.h>
#include <stdlib.h>
#define DIM 3

/*Programar  el  juego  TA-TE-TI.
Para  ello  se  requiere  modelar  un  tablero  de  3  x  3
en  el  que  el jugador 1 ingresará una coordenada en la que guardará una ‘x’.
Luego el jugador 2 ingresara otra coordenada en la que se guardara una ‘o’.
Si la  posición  ya  esta  ocupada,  el  programa deberá pedir el reingreso de otra coordenada.
Una vez completados todos los casilleros (el programa de  darse  cuenta  cuando  esta  condición  se  dé),
el  programa  debe  decir  qué  jugador  gano  la partida o si hubo empate (ningún jugador ganó).*/

void buscarGanador(int posicion[DIM][DIM]);
void mostrarTablero(int posicion[DIM][DIM]);

int main()
{
    int posicion[DIM][DIM];
    int x=0, y=0, i=0, j=0;

    for(i=0; i<DIM; i++){
        for(j=0; j<DIM; j++){
            posicion[i][j]=0;
            printf("%d:%d\t",i,j);
        }
        printf("\n");
    }
    printf("\n\n");

    i=0;

    while(i<9){
        if(i%2==0){
            do{
                printf("jugador 1\n");
                printf("ingrese la coordenada X\n");
                scanf("%d",&x);
                printf("ingrese la coordenada Y\n");
                scanf("%d",&y);
                if(posicion[x][y]!=0 && x<0 || x>2 && y<0 || y>2)
                    printf("--la posicion esta OCUPADA o ingrese una posicion INCORRECTA--\n");
            }while(posicion[x][y]!=0 && x<0 || x>2 && y<0 || y>2);
            posicion[x][y]=1;
            i++;
        }else{
            do{
                printf("jugador 2\n");
                printf("ingrese la coordenada X\n");
                scanf("%d",&x);
                printf("ingrese la coordenada Y\n");
                scanf("%d",&y);
                if(posicion[x][y]!=0 && x<0 || x>2 && y<0 || y>2)
                    printf("--la posicion esta OCUPADA o ingrese una posicion INCORRECTA--\n");
            }while(posicion[x][y]!=0 && x<0 || x>2 && y<0 || y>2);
            posicion[x][y]=2;
            i++;
        }
        mostrarTablero(posicion);
    }
    buscarGanador(posicion);


}

void mostrarTablero(int posicion[DIM][DIM])
{
    int i=0,j=0;

    for(i=0; i<DIM; i++){
        for(j=0; j<DIM; j++){

            if(posicion[i][j]==0){
            posicion[i][j]=0;
            printf("%d:%d\t",i,j);
            }else{printf("%d\t",posicion[i][j]);}
        }
        printf("\n");
    }
}

void buscarGanador(int posicion[DIM][DIM])
{
    int i=0, j=0, ganador1=0, ganador2=0;

    //solo corroboramos las filas horizontales NO las verticales ni las diagonales.
    for(i=0; i<DIM; i++){
        if(posicion[i][i]==posicion[i][j] && posicion[i][i]==posicion[i][j+1] && posicion[i][i]==posicion[i][j+2]){
            if(posicion[i][i]==1){
                ganador1=1;
            }else{
                ganador2=1;
            }
        }
    }

    if(ganador1 == 1 || ganador2 == 1){
        if(ganador1==1 && ganador2==1){
            printf("empate ambos ganaron\n");
        }else{
            if(ganador1==1 && ganador2==0){
                printf("el ganador es el jugador 1");
            }else{
                printf("el ganador es el jugador 2");
            }
        }
    }else{
        printf("ambos PERDIERON\n");
    }
}
