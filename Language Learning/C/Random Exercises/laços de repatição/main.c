#include <stdio.h>
#include <stdlib.h>

int main()
{
    /*float n1, n2, media;
    int i;
/*
    for (i=1; i<=3;i++){
        printf("Digite suas notas?\n");
        scanf("%f&f", &n1, &n2);

        printf("Digite suas notas?\n");
        scanf("%f&f", &n1, &n2);

        media = (n1 + n2)/2.0;
        printf("%f", media);
    }



    printf("Quantas repetições:");
    scanf("%d", &i);

    while (i<=3){

        printf("Qual sua primeira nota?\n");
        scanf("%f", &n1);

        printf("Digite sua segunda nota?\n");
        scanf("%f", &n2);

        media = (n1+n2)/2;

        printf("sua media foi %.2f\n", media);

        i++;

    }
    int num;

    for(num = 1; num <= 10; num++){
        if (num%2==0){
            printf("%d", num);
        }
    }*/

    char slc;
    float n1, n2, media;

    do{
        printf("Quais suas notas?\n");
        scanf("%f %f", &n1, &n2);
        getchar();

        media = (n1+n2)/2;

        printf("sua media foi %.2f\n", media);

        printf("Que\ns/n");


        slc = getchar();

    }while(slc=='s');

    return 0;
}
