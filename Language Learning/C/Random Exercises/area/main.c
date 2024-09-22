#include <stdio.h>
#include <stdlib.h>

#define PI 3.14
int main()
{/*
    float area, raio;


    prinft("Informe o valor do raio da cirunferencia");
    scanf("%f", %raio);

    area = PI
    */
    /*
    int hora_trabalho;
    float preco_hora, inss, salario_liquido, salario_bruto;

    printf("Quantas horas voce trabalhou no mes?");
    scanf("%d", &hora_trabalho);

    printf("Quanto voce cobra pela hora?");
    scanf("%f", &preco_hora);

    printf("Quanto quantos porcentos vc paga de inss?");
    scanf("%f", &inss);

    inss = inss/100;

    salario_bruto = preco_hora * hora_trabalho;

    salario_liquido = salario_bruto - (salario_bruto * inss);

    printf("Seu salario bruto eh: R$%.2f", salario_liquido);
    */
    /*
    float preco_casa;

    printf("Quanto custa a casa?");
    scanf("%f", &preco_casa);

    if (preco_casa < 80000){
        printf("Casa em promacao");
    }else{
        printf("preco normal")
    }



    */
    /*
    int ano;
    float valor_carro, taxa;

    printf("Qual o ano e o valor do carro?");
    scanf("%d %f", &ano, &valor_carro);

    if (ano < 1990){
        taxa = valor_carro * 0.01;
    }else{
            taxa = valor_carro * 0.015;
    }

    printf("voce pagara R$%.2f de impostos", taxa);
    */
    /*

    while (1==1){
        printf("|\b");
        printf("/\b");
        printf("-\b");
        printf("\\\b");

    }
    */

    unsigned long long graos, cont, total_graos;

    cont = 1;
    graos = 1;

    while (cont < 64){
            total_graos = total_graos + graos;
            cont++;
            graos = graos * 2;

            printf("%llu\n", graos);
    }
    printf("%llu", total_graos);

    return 0;
}
