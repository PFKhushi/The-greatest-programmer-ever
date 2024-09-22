#include <stdio.h>
#include <stdlib.h>
/*
enum estrutura
criar estrutura para matriz e filial
pergntar se é matriz ou filial
imprimr dados
*/
struct store{
        char nome[25];
        char endereco[25];
        float faturamento;
};
int main()
{
    int choice = 2;
    struct store _matriz = {"Farmacia", "Rua sem saida", 100000};
    struct store _filial = {"Pague menos", "Rua com saida", 20000};
    printf("Matriz - 0\nFilial - 1\n");
    scanf("%d", &choice);
    switch(choice){
    case 0:{
        printf("MATRIZ\nNome: %s\nEndereço: %s\nFaturamento: R$%.2f", _matriz.nome, _matriz.endereco, _matriz.faturamento);
        break;
    }
    case 1:
        printf("FILIAL\nNome: %s\nEndereço: %s\nFaturamento: R$%.2f", _filial.nome, _filial.endereco, _filial.faturamento);
        break;
    }
    return 0;
}
