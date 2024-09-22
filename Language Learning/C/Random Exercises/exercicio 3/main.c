#include <stdio.h>
#include <stdlib.h>

int main()
{
    int time1, time2;
    char timenome1[15], timenome2[15];

    printf("Qual o nome do primeiro time?\n");
    scanf("%s", &timenome1);
    printf("Qual o nome do segundo time?\n");
    scanf("%s", &timenome2);
    printf("Quantos gols o %s?\n", timenome1);
    scanf("%d", &time1);
    printf("Quantos gols o %s?\n", timenome2);
    scanf("%d", &time2);


    if (time1 < time2){
        printf("%s ganhou a partida\n", timenome2);
    }
    else if (time1 > time2){
        printf("%s ganhou a partida\n", timenome1);
    }
    else {
        printf("Deu empate\n");
    }
    return 0;
}
