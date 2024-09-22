#include <stdio.h>
#include <stdlib.h>

int main()
{

    float prc_atual, vnd_mensal, renda;

    printf("Qual o preco atual do produto?\n");
    scanf("%f", &prc_atual);
    printf("Quanto se vende mensalmente desse produto?\n");
    scanf("%f", &vnd_mensal);

    if(vnd_mensal < 500 && prc_atual < 30){

        prc_atual = prc_atual + (prc_atual * 0.1);

    }else if(vnd_mensal >= 500 && vnd_mensal <1200 && prc_atual < 80 && prc_atual < 1200){

        prc_atual = prc_atual + (prc_atual * 0.15);

    }else if(vnd_mensal >= 1200 && prc_atual >= 80){

        prc_atual = prc_atual - (prc_atual * 0.2);

    }

    printf("%f", prc_atual);

    return 0;
}
