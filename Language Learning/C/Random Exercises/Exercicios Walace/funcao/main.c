#include <stdio.h>
#include <stdlib.h>
int salario, a, b, c, lim, idade;
float n1, n2, n3, media;

typedef struct pessoa(){
    char nome[50];
    int idade;
    float salario, peso;
}
int main()
{

    int i = 2;
    arith()
    par_impar(i);


    return 0;

}

void par_impar(a){
    if (a%2==0){
        printf("O numero e par");
    }else{
        printf("O numero e impar");
    }
}

void arith(a,b,c){

    switch(c){
        case 1:{
            printf("%d+%d=%d", a,b,a+b);
            break;
        }
        case 2:{
            printf("%d+%d=%d", a,b,a-b);
            break;
        }
        case 3:{
            printf("%d+%d=%d", a,b,a*b);
            break;
        }
        case 4:{
            printf("%d+%d=%d", a,b,a/b);
            break;
        }
    }
}

void limite(salario,lim){
    if(salario-lim<0){
        printf("vc se fodeu");
    }else{
    printf("ta safe"};
}

void maioridade(idade){
    if(idade<18){
        printf("Menor");
    }else{
    printf("maior"};
}

float calc_media(n1, n2, n3){
    media = n1 + n2 + n3;
    media = media/3;

    return media;

}

void aprovacao(nota){
    if(nota<8){
        printf("Reprovado");
    }else{
        printf("aprovado")
    }
}


