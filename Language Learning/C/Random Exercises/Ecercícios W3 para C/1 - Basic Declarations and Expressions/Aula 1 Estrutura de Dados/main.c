#include <stdio.h>
#include <stdlib.h>

int main()
{
    //Exercicio 1
    /*
    printf("Qual a base da potência?\n");
    int base;
    scanf("%d", &base);
    for(int i=0;i<16;i++){
        long long result = 1;
        for(int w=0;w<=i;w++){//fazendo w<i o loop interno é pulado quando i==0 e os resultados ficam certos sem precisar dividir por 5, mas a lógica fica estranha
            result = result * base;
        }
        printf("%d elevado a %d é: %lld\n", base, i, result/base);
    }*/

    //Exercicio 2
    /*
    int base, expoente;
    printf("Qual a base da potência?\n");
    scanf("%d", &base);
    printf("Qual o expoente da potência?\n");
    scanf("%d", &expoente);
    long long result = 1;
    for(int w=0;w<=expoente;w++){
            result = result * base;
    }
    printf("result %lld \n", result/base);
    */

    //Exercicio 3
    /*
    int a, b, c;

    a = 0;
    c = 1;

    for(int i = 0;i<16;i++){
        printf("%d\n", c);
        b = c;
        c = b + a;
        a = b;
    }
    */

    //Exercicio 4
    /*
    unsigned long long a,b;
    b=a=1;
    char c[50];

    for(int i=1;i<=64;i++){
        //printf("%llu\n", a);
        sprintf(c,"%llu", a);
        printf("%d - %s\n", i, c);

        b = b*2;
        a = a+b;
    }
    */
    /*
    char vetores[5];
    int num, num_maior, num_menor;

    num_maior = num_menor = NULL;


    for(int i=0;i<5;i++){
        printf("Digite um número\n");
        scanf("%d", &num);
        vetores[i] = num;
    }
    int tam = sizeof(vetores);

    int indx = 0;
    int pos_maior;
    int pos_menor;

    while(indx<tam){

        if(num_maior == NULL){
            num_maior = vetores[indx];
            pos_maior = indx;
        }else if(num_maior<vetores[indx]){
            num_maior = vetores[indx];
            pos_maior = indx;
        }
        if(num_menor == NULL){
            num_menor = vetores[indx];
            pos_menor = indx;
        }else if(num_menor>vetores[indx]){
            num_maior = vetores[indx];
            pos_menor = indx;
        }
        indx++;
    }
    indx = 0;
    while(indx<tam){
        printf("\n%d\n", vetores[indx]);
        indx++;
    }
    printf("\nO menor númeor foi %d no index %d \nO menor número foi %d no index %d", num_menor, pos_menor, num_maior, pos_maior);
    */
    /*
    typedef struct cmds{
        char nome[50];
        float largura, comprimento, area;
    }Comodos;
    Comodos Casa[50];

    int w = 1;
    int indx = 0;

    while(w!=0){


        printf("Qual o nome do comodo?");
        scanf("%s", Casa[indx].nome);
        printf("Qual a largura do comodo?");
        scanf("%f", &Casa[indx].largura);
        printf("Qual o comprimento do comodo?");
        scanf("%f", &Casa[indx].comprimento);

        Casa[indx].area = Casa[indx].largura * Casa[indx].comprimento;

        indx++;

        printf("Deseja adicionar mais um comodo? \n1-sim\n0-nao\n");
        scanf("%d", &w);

    }
    float area_total = 0;

    for(int i=0;i<indx;i++){
        area_total += Casa[i].area;
    }
    printf("Area total é de %.2f", area_total);
    */

    //Listas Sequencial - EXERCÍCIO
    /*
    char nomes[3][50];

    for(int i=0;i<3;i++){
        printf("\nDigite um nome:\n");
        scanf("%s", nomes[i]);
    }
    for(int i=0;i<3;i++){
        printf("\n%s\n", nomes[i]);
    }
    printf("Qual nome vc deseja procurar?\n");
    int nome_temp[50];
    scanf("%s", nome_temp);
    int achou = 66;

    for(int i=0;i<3;i++){
        if(strcmp(nomes[i],nome_temp)==0){

            printf("Temos esse nome na lista, no index %d\n", i);
            achou = i;
        }
    }
    if(achou == 66){
        printf("Nao temos esse nome na lista.\n");
    }else{
        printf("Nome procurado: %s\n", nomes[achou]);
    }

    printf("Qual nome deseja apagar?");
    scanf("%s", nome_temp);

    for(int i=0;i<3;i++){
        if(strcmp(nomes[i],nome_temp)==0){
            while(i<3){
                printf("test");
                strcpy(nomes[i],nomes[i+1]);
                i++;
            }
        }
    }
    for(int i=0;i<3;i++){
        if(nomes[i]!=NULL){
            printf("\n%s\n", nomes[i]);
        }

    }
    */


    return 0;
}
