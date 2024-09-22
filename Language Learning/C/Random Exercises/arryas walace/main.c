#include <stdio.h>
#include <stdlib.h>

int main()
{
    int kar[3][3], i, c;
// entrada de dados

    /*
    kar[0][0] = 300;
    kar[0][1] = 5;
    kar[0][2] = 3;
    kar[1][0] = 4;
    kar[1][1] = 10;
    kar[1][2] = 337;
    kar[2][0] = 12;
    kar[2][1] = 2;
    kar[2][2] = 5;
    */

    for (i=0; i<3; i++)
        for (c=0; c<3; c++)
        {
            printf("Digite um numero:\n");
            scanf("%d", &kar[i][c]);
        }

    i=0;
    c=0;
        // percorrer todos os pontos da matrix e imprimi-los
        for (i=0; i<3; i++){
        for (c=0; c<2; c++)
        {
            printf("%d - ", kar[i][c]);

            //condicao para imprimir traco
            //if (c < 2){printf(" - ");            }

        }
        printf("%d \n", kar[i][c]);
        }

    return 0;
}
