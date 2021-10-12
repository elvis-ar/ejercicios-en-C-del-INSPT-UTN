#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a=5;
    int* b=NULL;

    printf("SIN MODIFICAR a:%d b:%d\n",a,b);

    b=&a;
    printf("MODIFICADO a:%d b:%d\n",a,b);

    printf("%d--%d\n",a,*b);

    int c=25;
    int* ptr1=NULL;
    int* ptr2=NULL;
    int* ptr3=NULL;
    int* ptr4=NULL;

    /*a C le asignamos un nnumero y despues lo desferenciamos y a los demas le pasamos la direccion d ememoria*/
    ptr1=&c;
    ptr2=ptr1;
    ptr3=ptr2;
    ptr4=ptr3;

    printf("c %d  || ptr1 %d || ptr2 %d || ptr3 %d || ptr4 %d\n",&c,ptr1,ptr2,ptr3,ptr4);
    printf("c %d  || ptr1 %d || ptr2 %d || ptr3 %d || ptr4 %d\n",c,*ptr1,*ptr2,*ptr3,*ptr4);
}
