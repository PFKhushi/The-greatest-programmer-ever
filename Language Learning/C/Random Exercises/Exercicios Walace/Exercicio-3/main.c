#include <stdio.h>
#include <stdlib.h>

int main()
{

    //receber os dados percorrer o mes e imprimir os resultados no maior e o dia

    int mes, vendas[29], maior=0, maior_indx=0,i;




    for(i=1;i<29;i++){
        printf("Qual foi o número de vendas no dia %d?", i);
        scanf("%d", &vendas[i]);
    }

    for(i=1;i<29;i++){

        if(maior<vendas[i]){
            maior=vendas[i];
            maior_indx = i;
        }

    }

    printf("O dia com mais vendas foi o dia %d, com %d pratos vendidos", maior_indx, maior);

    return 0;
}
