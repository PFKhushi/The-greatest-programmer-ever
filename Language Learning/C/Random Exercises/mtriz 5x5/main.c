#include <stdio.h>
#include <stdlib.h>

int main()
{
    int matriz[6][6],c, i;

    for (i=0; i<6; i++)
        for (c=0; c<6; c++)
        {
            printf("Digite um numero:\n");
            scanf("%d", &matriz[i][c]);

        }
    for (i=0; i<6; i++){
        for (c=0; c<5; c++)
        {
            if (i==c){
                printf("%d", matriz[i][c]);
            }



        }

    }


    return 0;
}
