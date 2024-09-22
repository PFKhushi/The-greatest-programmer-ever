#include <stdio.h>
#include <stdlib.h>

int main()
{
    int j, i, op = 0;
    for (i=0;i<5;i++){
        for(j=0;j<5;j++){
            printf("X");
        }
        printf("\n");
    }
    printf("Qual o tamanho do quadrado?\n");
    scanf("%d", &op);

    for (i=0;i<op;i++){
        for(j=0;j<op;j++){
            printf("X");
        }
        printf("\n");
    }


    return 0;
}
