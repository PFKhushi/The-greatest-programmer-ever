#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numero;
    printf("Selecione a opercao: 1-adicao 2-subtracao 3-mutiplicacao 4-divisao\n");
    scanf("%d",&numero);

    switch (numero){

        case 1:{
            int num1, num2, resultado;

            printf("Digite numero:  ");
            scanf("%d",&num1);
            printf("Digite numero:  ");
            scanf("%d",&num2);
            resultado = num1 + num2;
            printf("Resultado: %d", resultado);

            break;
            }
        case 2:{
            int num1, num2, resultado;

            printf("Digite numero:  ");
            scanf("%d",&num1);
            printf("Digite numero:  ");
            scanf("%d",&num2);
            resultado = num1 - num2;
            printf("Resultado: %d", resultado);

            break;}
        case 3: {
            int num1, num2, resultado;

            printf("Digite numero:  ");
            scanf("%d",&num1);
            printf("Digite numero:  ");
            scanf("%d",&num2);
            resultado = num1 * num2;
            printf("Resultado: %d", resultado);

            break;
        case 4: {
            int num1, num2, resultado;

            printf("Digite numero:  ");
            scanf("%d",&num1);
            printf("Digite numero:  ");
            scanf("%d",&num2);
            resultado = num1 / num2;
            printf("Resultado: %d", resultado);

            break;
        }
        }
    }
    return 0;
}
