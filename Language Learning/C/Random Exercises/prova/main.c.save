#include <stdio.h>
#include <stdlib.h>

int main()
{

    int maior = 0, menor = 0,num_idades = 0, i, soma = 0;
    char  op = 'a', op2 = 'a';

    maior = "\0";
    menor = "\0";

    printf("Quantas idades vc quer digitar\n");
    scanf("%d", &num_idades);

    printf("Digite as idades que vc quer calculadr a media: \n");

    int idades[num_idades];


    for (i = 0; i < num_idades; i++){

        scanf("%d", &idades[i]);

        soma = soma + idades[i];

        if (op == 'a' || op2 == 'a'){
            op = 'b';
            op2 = 'b';
            maior = idades[i];
            menor = idades[i];
            printf("maior1 - %d\n", maior);
            printf("menor1 - %d\n", menor);
        }

        if (menor >= idades[i]){
            menor = idades[i];
            printf("menor2 - %d\n", menor);

        }
        if (maior <= idades[i]){
            maior = idades[i];
            printf("maior2- %d\n", maior);
        }



    }
    printf("%d\n", soma/num_idades);
    printf("O maior numero foi %d\nO menor numero foi %d", maior, menor);

/*

    char op;
    int num1, num2, resultado;

    num1 = num2 = 0;

    printf("Qual operacao vc deseja realizar? \n | / | ... | * | ... | - | ... | + |\n ");
    scanf("%c", &op);

    printf("Digite os numeors:\n");
    scanf("%d", &num1);
    scanf("%d", &num2);


    if (op == '/'){
        resultado = num1 / num2;
    }else if(op == '*'){
        resultado = num1 * num2;
    }else if(op == '-'){
        resultado = num1 - num2;
    }else if(op == '+'){
        resultado = num1 + num2;
    }

    printf("O resultade de %d%c%d=%d", num1,op,num2,resultado);
*/
/*
    char nome[256], emon[256];
    int i=0,j=0;

    emon[0] = '\0';

    printf("Digite um nome\n");
    scanf("%[^\n]", nome);

    printf("Texto string: %s\n", nome);

    j = strlen(nome) - 1;

    for (i = 0; i < strlen(nome); i++){

            emon[i] = nome[j];
            j--;
        }


    printf("Texto invertido: %s\n", emon);

    printf("Texto com case invertido: ");

    for (i = 0; i < strlen(nome); i++){

            if(isupper(nome[i])){
                nome[i]=tolower(nome[i]);
            }else if(islower(nome[i])){
                nome[i]=toupper(nome[i]);
            }
            printf("%c", nome[i]);
        }


*/
    return 0;
}
