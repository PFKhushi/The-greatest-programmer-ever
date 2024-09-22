#include <stdio.h>
#include <stdlib.h>

int main()
{
    /*
    int num = 0;
    int x;
    for (x = 0; x <= 10; x++)
        printf("%d\n",x);

    for (x = 100; x >= 0; x--)
        printf("%d\n",x);

    for (x = 0; x <= 100; x+=2)
        printf("%d\n",x);


    int numero_idades, idade, media, i, soma;
    numero_idades = 0;
    idade = 0;
    media = 0;
    i = 0;
    soma = 0;
    printf("Quantas idades vc quer digitar");
    scanf("%d", &numero_idades);

    for (i = 1; i <= numero_idades; i++){



        printf("digite uma idade");
        scanf("%d", &idade);
        soma = soma+idade;
    }
    soma = soma/numero_idades;
    printf("%d", soma);



    int media, n1, n2, n3, i;
    media = 0;
    n1 = 0;
    n2 = 0;
    n3 = 0;
    i = 0;
    for (i=0; i<=2; i++){

        printf("Digite nota 1\n");
        scanf("%d\n",&n1);
        printf("Digite nota 2\n");
        scanf("%d\n",&n2);
        printf("Digite nota 3\n");
        scanf("%d\n",&n3);

        media = (n1 + n2 + n3 ) / 3;

        printf("%d\n", media);
    }

    int numeros, total = 0, i;

    for (i = 0; i < 10; i++){
        printf("Digite um numero");
        scanf("%d", &numeros);
        if (numeros >= 10 && numeros <= 35){
            total = total + 1;
        }
        printf("%d", total);
    }*/

   /* int i = 1, idade, numero_idades, numero_temp, media, soma;

    while (i <= 100){

        printf("%d\n", i);
        i++;


    }
    i = 100;
    while (i >= 0){

        printf("%d\n", i);
        i--;


    }
    i = 0;
    while (i <= 100){

        printf("%d\n", i);
        i += 2;


    }


    printf("Quantas idades vc quer digitar?\n");
    scanf("%d", &numero_idades);
    numero_temp = numero_idades;
    while (numero_temp > 0){

        numero_temp--;
        printf("Digite uma idade\n");
        scanf("%d", &idade);
        soma = soma + idade;

    }
    media = soma/numero_idades;
    printf("%d", media);

    i = 0;
    int n1, n2, n3, contador, numero;
    while (i <= 2){

        printf("Digite nota 1\n");
        scanf("%d\n",&n1);
        printf("Digite nota 2\n");
        scanf("%d\n",&n2);
        printf("Digite nota 3\n");
        scanf("%d\n",&n3);

        media = (n1 + n2 + n3 ) / 3;

        printf("%d\n", media);
        i++;



    }*/

    /*int i = 1, numero, contador=0;


    while (i <= 10){
        printf("Digite um numero");
        scanf("%d", &numero);

        if (numero >= 10 && numero <= 35){
            contador++;
        }
        i++;


    }printf("%d", contador);
    */
    /*
    int i = 1;

    do {
        printf("%d\n", i);
        i++;

    }while(i <= 100);
    i = 100;
     do {
        printf("%d\n", i);
        i--;


    }while(i >= 0);
    i = 0;
    do {
        printf("%d\n", i);
        i+=2;

    }while(i <= 100);
    */
    /*
    int numero_temp = 0, idade;
    float media = 0, soma = 0, numero_idades = 0;

    printf("Quantas idades vc quer digitar?\n");
    scanf("%f", &numero_idades);
    numero_temp = numero_idades;


    do{
        printf("Digite uma idade");
        scanf("%d", &idade);
        soma = soma + idade;
        numero_temp--;



    }while(numero_temp > 0);
    media = soma/numero_idades;
    printf("%f", media);

    */
    /*
    float n1, n2, n3, contador = 3, numero, media;

    do{

        printf("Digite nota suas 3 notas\n");

        scanf("%f %f %f",&n1, &n2, &n3);
        printf("%f %f %f\n", n1, n2, n3);



        media = (n1 + n2 + n3 ) / 3;

        printf("%f\n", media);
        contador--;

    }while(contador >0);

    */
    int numero, contador = 0, i = 10;
    do{
        printf("Digite um numero");
        scanf("%d", &numero);

        if (numero >= 10 && numero <= 35){
            contador++;
        }
        i--;

    }while(i>0);
    printf("%d", contador);



    return 0;
}
