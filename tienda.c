#include <stdio.h>
#include <stdlib.h>

/*Se desea procesar las compras realizadas por los clientes de una empresa mayorista.
La empresa tiene un grupo de N clientes. El valor de N se ingresa por teclado.
Para cada uno, se ingresa el código de cliente,
la zona de compra (puede ser ‘a’, ‘b’, ‘c’, ‘d’, ‘e’ o ‘f’)
y una serie de importes correspondientes a las compras que realizaron.
El número de compras por cada cliente es variable y se ingresa un -1 para terminar el ingreso de las compras.
La empresa tiene un sistema especial de premios para los clientes de algunas zonas.
Si el cliente reside en zona ‘a’ o ‘b’ se le bonifica el 20% de la compra.
Si reside en ‘c’ la bonificación es del 10%.
Si la zona es ‘d’ o ‘e’ participan en un sorteo de un automóvil.

Se desea realizar un programa en C que:
a. Para cada cliente emitir el importe total de compras sin la bonificación, con la bonificación.y si ha participado o no del sorteo.
b. Emitir el total de ventas de la zona ‘f’.
c. Emitir un mensaje indicando cuantos clientes corresponden a la zona ‘a’ o ‘c’*/

int tomarDatos(int* cantClientes, int* codigoDeCliente, char* zonaDeCliente,int* precioDeCompra, int* importeTotal, int* zonaF, int* contZonaA, int* contZonaC);
int buscarPremios(char* zonaDeCliente, int* importeTotal, int* importeBonificado,int* zonaF);
int main()
{
    int cantClientes, i=0, codigoDeCliente, precioDeCompra, importeTotal, importeBonificado, zonaF, contZonaA=0, contZonaC=0;
    char zonaDeCliente;

    printf("ingrese cuantos clientes desea procesar:\n");
    scanf("%d",&cantClientes);

    for(i=0; (i+1)<=cantClientes; i++){
        importeTotal=0;
        tomarDatos(&cantClientes, &codigoDeCliente, &zonaDeCliente,&precioDeCompra,&importeTotal,&zonaF,&contZonaA,&contZonaC);
        buscarPremios(&zonaDeCliente,&importeTotal,&importeBonificado,&zonaF);
    }
    printf("%d pertenecen a zona A\n",contZonaA);
    printf("%d pertenecen a zona C\n",contZonaC);
}

int tomarDatos(int* cantClientes, int* codigoDeCliente, char* zonaDeCliente,int* precioDeCompra, int* importeTotal, int* zonaF, int* contZonaA,int* contZonaC)
{
    printf("ingrese el codigo del cliente:\n");
        scanf("%d",codigoDeCliente);
        do{
            printf("ingrese la zona de compra a || b || c || d || e || f:\n");
            fflush(stdin);
            scanf("%c",zonaDeCliente);
            if((*zonaDeCliente)=='a')(*contZonaA)++;
            if((*zonaDeCliente)=='c')(*contZonaC)++;
        }while((*zonaDeCliente)!='a' && (*zonaDeCliente)!='b' && (*zonaDeCliente)!='c' &&
               (*zonaDeCliente)!='d' && (*zonaDeCliente)!='e' && (*zonaDeCliente)!='f');

        printf("ingrese el importe de la compra o (-1 para salir):\n");
        scanf("%d",precioDeCompra);
        while(*precioDeCompra!= -1){
            (*zonaF)+= (*precioDeCompra);
            if(*precioDeCompra != -1){(*importeTotal)+=(*precioDeCompra);}
            printf("ingrese el importe de la compra o (-1 para salir):\n");
            scanf("%d",precioDeCompra);
        }

}

int buscarPremios(char* zonaDeCliente, int* importeTotal, int* importeBonificado,int* zonaF)
{
    switch(*zonaDeCliente){
    case 'a':
    case 'b': (*importeBonificado)=(*importeTotal)-(20*(*importeTotal)/100);
              printf("el importe total es de:%d\n",(*importeTotal));
              printf("el importe bonificado es de: %d\n",*importeBonificado);

        break;
    case 'c': (*importeBonificado)=(*importeTotal)-(10*(*importeTotal)/100);
              printf("el importe total es de:%d\n",(*importeTotal));
              printf("el importe bonificado es de: %d\n",*importeBonificado);
        break;
    case 'd':
    case 'e': printf("participa por un automovil\n");
              printf("el importe total es de:%d\n",(*importeTotal));
        break;
    case 'f': printf("total de importe zona F %d\n",*zonaF);
        break;
    }
}
