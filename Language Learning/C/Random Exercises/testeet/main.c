#include <stdio.h>
#include <stdlib.h>

int main()
{

    /*
    int vetor[15], pares = 0, impares = 0, zeros = 0, i = 0;

    for (i = 0; i<15; i++){

        printf("digite um numero");
        scanf("%d", &vetor[i]);
    }

    for (i = 0; i<15; i++){

        if (vetor[i]==0){
            zeros++;
        }
        else if (vetor[i]%2==0){
            pares++;
        }
        else {
            impares++;
        }


    }


    printf("pares = %d, impares = %d, zeros = %d", pares, impares, zeros);


    */

    int matriz[4][4], i, j, soma=0;

    for (i = 0; i<4; i++){
        for (j = 0; j<4; j++){
            printf("digite um numero ");
            scanf("%d", &matriz[i][j]);

            if (i==j){
                soma = soma+matriz[i][j];
            }

        }


    }
    printf("%d", soma);



    /*
    char string[20], temp[20] = "", tempc = "";
    int  length = 0, i;


    printf("Digite um nome para inverter");
    gets(string);

    length = strlen(string)-1;

    printf("A string tem %d caracteres\n\n", strlen(string));


    for (i = length; i>=0; i--){

        printf("%c", string[i]);




    }
    */
    /*
    int op;
    float total;

    printf("Quantosdeu suas compras?");
    scanf("%f", &total);

    printf("tipo de cliente");
    scanf("%d", &op);

    switch(op){
    case  1: {
        total = total - (total*0.2);
        break;
    }
    case  2: {
        total = total - (total*0.1);
        break;
    }
    case  3: {
        total = total - (total*0.05);
        break;
    }
    }

    printf("Seu total com desconto foi %f", total);

    */


    return 0;
}
