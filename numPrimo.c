#include <stdio.h>
#include <stdlib.h>

/* crear un programa que pida por pantalla 2 numeros y devolver los numeros primos entre esos intervalos */

int main()
{
    int num1, num2, recorrerNum2=0, divisor=0, contDivisores=0,contarCantidad=0;
    printf("ingrese un numero:\n");
    scanf("%d",&num1);
    printf("ingrese otro numero:\n");
    scanf("%d",&num2);

    recorrerNum2=num1;

    while(recorrerNum2 <= num2){
        contDivisores=0;

        for(divisor=1; divisor <= recorrerNum2; divisor++){
            if(recorrerNum2%divisor == 0){
                contDivisores++;
            }
        }
        if(contDivisores==2){
            printf("numero primo: %d\n",recorrerNum2);
            contarCantidad++;
        }
        recorrerNum2++;
    }
    printf("tiene %d numeros primos",contarCantidad);
}
