#include <stdio.h>
#include <stdlib.h>
void tomarDatos(char* categoriaCliente, char* publicidadCliente, float* importePublicidad, float* recaudadoBueno, float* recaudadoRegular, float* recaudadoMalo, float* recaudacionTotal, float* facturasProcesadas);
void mejorRanting(float recaudadoBueno,float recaudadoRegular,float recaudadoMalo);

/*Una agencia de marketing necesita una aplicación para el proceso de sus clientes y publicidades. Para ello se reúne 
con usted y define: 
1- Construir una función que permita procesar una cantidad desconocida de ids de clientes que finaliza con el 
número 0. Por cada cliente se ingresa su categoría (P-Platinum, G-Gold) y una cantidad desconocida de 
publicidades. Cada publicidad tiene un importe y un rating. Por lo tanto, se debe ingresar: 
a. rating: B (bueno), R (regular), M (malo) -carácter- 
b. Importe: número decimal 
Esta función debe emitir por cada cliente ingresado cuánto dinero se recaudó por cada rating, que se procesan 
en la función 2. Ejemplo: 
 Total de publicidades del cliente 64: $10.000 
Publicidades buenas: $2.000 
 Publicidades regulares: $3.000 
Publicidades malas: $4.000 
2- Construir una función que reciba al menos categoría e importe y devuelva (de alguna manera) a la función 1 
todos los totales de las facturas procesadas por cada cliente. 
3- En main el mensaje final que se emite debe mostrar: 
a. Total de clientes procesados 
b. Qué rating dejo más ganancias en total 
c. Qué categoría de cliente fue la más lucrativa */

int main()
{
    int IdCliente,clientesProcesados=0;
    float importePublicidad, recaudadoBueno, recaudadoRegular, recaudadoMalo, recaudacionTotal,facturasProcesadas;
    char categoriaCliente, publicidadCliente;

    printf("ingrese un ID o 0 SALIR:");
    scanf("%d",&IdCliente);

    while(IdCliente != 0){
        recaudadoBueno=0, recaudadoRegular=0, recaudadoMalo=0, recaudacionTotal=0;
        tomarDatos(&categoriaCliente,&publicidadCliente,&importePublicidad,&recaudadoBueno,
                   &recaudadoRegular,&recaudadoMalo,&recaudacionTotal,&facturasProcesadas);

        printf("la recaudacion total del cliente %d, es: %2.2f\n",IdCliente,recaudacionTotal);
        printf("recaudacion buena: %2.2f\n",recaudadoBueno);
        printf("recaudacion regular: %2.2f\n",recaudadoRegular);
        printf("recaudacion mala: %2.2f\n",recaudadoMalo);

        clientesProcesados++;
        mejorRanting(recaudadoBueno,recaudadoRegular,recaudadoMalo);

        printf("ingrese un ID o 0 SALIR:");
        scanf("%d",&IdCliente);
    }

    printf("el total de los clientes procesados es: %d\n",clientesProcesados);
    printf("el importe total de las facturas procesadas son: %2.2f\n",facturasProcesadas);
}

void tomarDatos(char* categoriaCliente, char* publicidadCliente, float* importePublicidad, float* recaudadoBueno,float* recaudadoRegular,float* recaudadoMalo, float* recaudacionTotal, float* facturasProcesadas)
{
    do{
        printf("ingrese su categoria: \n(p) platinum \n(g) gold\n");
        fflush(stdin);
        scanf("%c",categoriaCliente);
    }while((*categoriaCliente) != 'p' && (*categoriaCliente != 'g'));

    do{
        printf("elija una publicidad o (--Z-- para salir):\n");
        printf("(b) bueno \n(r)regunlar \n(m)malo\n");
        fflush(stdin);
        scanf("%c",publicidadCliente);
    }while(*publicidadCliente != 'b' && *publicidadCliente != 'r' && *publicidadCliente != 'm' && *publicidadCliente != 'z');

    while(*publicidadCliente != 'z'){

        printf("ingrese un importe:\n");
        scanf("%f",importePublicidad);

        (*recaudacionTotal)+=(*importePublicidad);
        (*facturasProcesadas)+=(*importePublicidad);

        switch(*publicidadCliente){
            case 'b': (*recaudadoBueno)+=(*importePublicidad);
                break;
            case 'r': (*recaudadoRegular)+=(*importePublicidad);
                break;
            case 'm': (*recaudadoMalo)+=(*importePublicidad);
        }

        do{
            printf("elija una publicidad o (--Z-- para salir):\n");
            printf("(b) bueno \n(r)regunlar \n(m)malo\n");
            fflush(stdin);
            scanf("%c",publicidadCliente);
        }while(*publicidadCliente != 'b' && *publicidadCliente != 'r' && *publicidadCliente != 'm' && *publicidadCliente != 'z');
    }
}

void mejorRanting(float recaudadoBueno,float recaudadoRegular,float recaudadoMalo)
{
    if(recaudadoBueno >= recaudadoRegular && recaudadoBueno >= recaudadoMalo){
        printf("la categoria que mas vendio fue la B con %2.2f\n",recaudadoBueno);
    }
    if(recaudadoRegular >= recaudadoBueno && recaudadoRegular >= recaudadoMalo) {
            printf("la categoria que mas vendio fue la R con %2.2f\n",recaudadoRegular);
    }
    if(recaudadoMalo >= recaudadoBueno && recaudadoMalo >= recaudadoRegular){
        printf("la categoria que mas vendio fue la M con %2.2f\n",recaudadoMalo);
    }
}
