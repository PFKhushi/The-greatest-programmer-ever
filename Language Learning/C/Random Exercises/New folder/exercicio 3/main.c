#include <stdio.h>
#include <stdlib.h>

int main()
{
   /* int numero;

    printf("digite um numero inteiro");
    scanf("%d", &numero);

    if (numero % 2 == 0){
        printf("o numero %d e par", numero);
    }
    else {
        printf("o numero %d e impar", numero);
    }*/


    int idade, ano, ano_atual, resp;

    printf("digite seu ano de nascimento");
    scanf("%d", &ano);
    printf("ja fez aniversario \n1 - sim / 2- nao");
    scanf("%d", &resp);




    ano_atual = 2022;
    idade = ano_atual- ano;

    if (resp == 2){
            idade = idade - 1;
            }

    if (idade >= 5 && idade <= 7){
        printf("infantil a");

    }else if (idade >= 8 && idade <=10){
        printf("infantil b");
    }else if (idade >= 11 && idade <= 13){
        printf("Juvenil a");
    }else if (idade >= 14 && idade <= 17){
        printf("juvenil b");
    }else if (idade > 17){
        printf("senior");
    }else{
        printf("fora da faixa");
    }

    return 0;
}
