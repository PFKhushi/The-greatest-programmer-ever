#include <stdio.h>
#include <stdlib.h>

int main()
{
    //ler numeros e imprimir com os resultados
    int a, b, c, d, i;

    printf("Digite quator n�meors, separados por enter:\n");
    scanf("%d",a);
    scanf("%d",b);
    scanf("%d",c);
    scanf("%d",d);


    printf("%d*%d=%d\n\n", a, c, a + c);
    printf("%d+%d=%d\n\n", b, d, b+d);

    return 0;
}
