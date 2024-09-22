#include <stdio.h>
#include <stdlib.h>
typedef struct pessoa{
    char nome[50];
    int idade;
    float peso, salario;
}personel;

personel humanos[10];

int main()
{
    tratar();
    return 0;
}

void tratar(){



    for(int i=0;i<10;i++){
        printf("Qual seu nome?\n");
        scanf("%s", humanos[i].nome);

        printf("%s", humanos[i].nome);

        printf("Qual a sua idade");
    }
}
