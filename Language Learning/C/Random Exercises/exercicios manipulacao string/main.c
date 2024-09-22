#include <stdio.h>
#include <stdlib.h>
#include <string.h>




int main()
{

    /*
    1) Criar uma aplicação, para ler dois nomes. Em seguida deve serexibido o tamanho de cada nome, e se eles são iguais, se o primeiro é maior, ou se o primeiro é menor.
    */

    /*
    char nome1[20], nome2[20];
    int size;

    printf("Digite um nome:\n");
    scanf("%s", &nome1);

    printf("Digite outro nome:\n");
    scanf("%s", &nome2);

    size = strcmp(nome1, nome2);




    if(size<0){
        printf("O primeiro nome eh menor que o segundo.");
    }
    else if(size>0){
        printf("O primeiro nome eh maior que o segundo.");
    }
    else{
        printf("Os nomes sao iguais.");
    }
    */

    /*
    strcmp function
    menor que 0 se nome1<nome2
    maior que 0 se nome1>nome2
    igual a 0 se nome1==nome2
    */




    /*
    2. Fazer um programa que inverta um string. "Parabens a voce" vira "ecova snebaraP".
    */

    //pegar tamanho da string e usar ele dentro do for comecando na posicao -1


    /*
    char nome[20], emon[20];
    int size, i, j;

    printf("Digite um nome para inverter");
    scanf("%s", &nome);

    j = 0;


    for (i = strlen(nome) -1; i>=0; i--){
        emon[j] = nome[i];
        j++;
        printf("%d %s", j, emon);
    }

    printf("%s", emon);

    */


    char string[20], temp[20] = "", tempc = "";
    int  length = 0, i;


    printf("Digite um nome para inverter");
    scanf("%s", string);

    length = strlen(string)-1;


    for (i = length; i>=0; i--){

        printf("%c", string[i]);
        strcpy(tempc, string[i]);
        strcat(temp, tempc);




    }
    printf("%s", temp);

        //o codigo como ta, inverte qualquer string, mas quando eu tento usar strcpy e strcat,
        //o loop se quebra e apenas ultima letra é impressa
        //strcpy(tempc, string[i]);
        //strcat(temp, tempc);


    //3. Converter um string para maiúsculo, e depois para minúsculo.

    /*

    char nome[20];
    int i;

    printf("Digete um nome\n");
    scanf("%s", nome);

    for (i = 0; i <= strlen(nome); i++){
            printf("%c", toupper(nome[i]));
    }

    for (i = 0; i <= strlen(nome); i++){
            printf("%c", tolower(nome[i]));
    }
    //Dificuldades para colocar em uma variavel
    */

    //4. Leia o nome completo de uma pessoa (nome /sobrenome / nome do meio).
    //Em seguida, exiba cada um dos em linhas diferentes.
    //Ex.: João da Silva Cavalcanti.
    //João
    //da
    //Silva
    //Cavalcanti


    /*
    char string[50];

    printf("Qual o nome completo?");
    scanf("%[^\n]", &string);


    char * separador = strtok(string, " ");

    while( separador != NULL ) {
        printf( "%s\n", separador );
        separador = strtok(NULL, " ");

    }
    */

    //


    return 0;
}
