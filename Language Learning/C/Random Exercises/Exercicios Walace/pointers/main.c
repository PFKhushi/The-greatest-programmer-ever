#include <stdio.h>
#include <stdlib.h>

int main()
{

    int x;

    int y;
    int *p;



    p = &x;
    x = 15;
    int w = 2 * *p;


    y = *p;

    printf("Endereco de x = %p\n", p);
    printf("Endereco de x = %x\n", p);
    printf("Valor apontado por P = %d\n", *p);
    printf("valor de y = %d\n", y);

    printf("Valor apontadao por p, multiplicado por 2 %d", w);
    return 0;
}
