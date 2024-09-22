#include <stdio.h>
#include <stdlib.h>

int main()
{
    int idade;
    printf("qual a sua idade");
    scanf("%d", &idade);

    if (idade >= 5 && idade <= 12){
        printf("infantil");

    }
    else if (idade >= 13 && idade <= 20){
        printf("juvenil");

    }
    else if (idade >= 21 && idade <= 35){
        printf("adulto");

    }
    else if (idade >= 36 && idade <= 60){
        printf("master");

    }
    else{
        printf("idade invalida");
    }

    return 0;
}

//leonardo.souto@unipe.edu.br
