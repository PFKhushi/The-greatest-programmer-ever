#include <stdio.h>
#include <stdlib.h>

int main()
{

    float notas[10][4], media;
    int i, c;

    //receber notas


    for (i = 0; i < 10; i++){


            printf("Quais foram suas notas?\n");
            scanf("%f %f %f", &notas[i][0], &notas[i][1], &notas[i][2]);


            //printf(" %f %f %f ", notas[i][0], notas[i][1], notas[i][2]);

            //calcular
            media = (notas[i][0] + notas[i][1] + notas[i][2]) / 3;
            notas[i][3] = media;



    }
    //percorrer matriz
    for (i=0; i<10; i++){
        for (c=0; c<4; c++)
        {
            //imprimir
            printf(" %.2f ", notas[i][c]);

        }

        printf("\n");

    }

    return 0;
}
