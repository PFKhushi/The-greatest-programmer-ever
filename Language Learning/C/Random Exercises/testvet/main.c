#include <stdio.h>
#include <stdlib.h>

int main()
{
    /*
    char nome[200], Pnome[20], Mnome[20], Unome[20];


    printf("digite seu primeiro nome\n");
    scanf("%s", Pnome);

    printf("digite seu primeiro nome\n");
    scanf("%s", Mnome);

    printf("digite seu primeiro nome\n");
    scanf("%s", Unome);

    nome[0] = '\0';

    strcat(nome, Pnome);
    strcat(nome, " ");
    strcat(nome, Mnome);
    strcat(nome, " ");
    strcat(nome, Unome);

    printf("%s", nome);
    */

    /*
    for(i = 0; i <= strlen(nome); i++){

        if (nome[i] == 'a' || nome[i] == 'A'){
            a++;
        }
        else if (nome[i] == 'b' || nome[i] == 'B'){
            b++;
        }
        else if (nome[i] == 'c' || nome[i] == 'C'){
            c++;
        }
    }

    printf("A -- %d \nB -- %d \nC -- %d\n", a, b, c);


    printf("%s", nome);
    */
    /*
    char nome[200], Pnome[20], Mnome[20], Unome[20];
    int i = 0, contador = 0;


    printf("digite seu primeiro nome\n");
    scanf("%s", Pnome);

    printf("digite seu primeiro nome\n");
    scanf("%s", Mnome);

    printf("digite seu primeiro nome\n");
    scanf("%s", Unome);

    nome[0] = '\0';

    strcat(nome, Pnome);
    strcat(nome, " ");
    strcat(nome, Mnome);
    strcat(nome, " ");
    strcat(nome, Unome);

    while (nome[i] != '\0'){
        contador++;
        i++;
    }
    printf("%d\n", contador);

    for (i = 0; i <= contador; i++){
        printf("%c\n", nome[i]);
    }
    */

    char temp, nome[20], copia[20];
    int i, comparacao;

    printf("digite seu noem");
    scanf("%[ -~]", nome);
    strcpy (copia, nome);
    strcat(copia, nome);

    comparacao = strcmp(nome, copia);

    printf("%s, %s", nome, copia);

    printf("%d", comparacao);



    return 0;
}
