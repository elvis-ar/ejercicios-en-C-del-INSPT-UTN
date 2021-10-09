#include <stdio.h>
#include <stdlib.h>

/*diseñar un programa el cual reciba un numero y muestre su factorial*/

int main(){
    int dato=0, rrecorrerDato=0, producto=1;

    printf("ingrese un numero para sacar factorial:\n");
    scanf("%d",&dato);

    for(rrecorrerDato=1; rrecorrerDato<=dato; rrecorrerDato++){
        producto*=rrecorrerDato;
        printf("-------%d--------\n",producto);
    }
    printf("el factorial de %d es:%d\n",dato,producto);

    return 0;
}
