#include <stdio.h>
#include <stdlib.h>
/*
enum semana {
    domingo = 1,
    segunda = 2,
    terca = 3,
    quarta = 4,
    quinta = 5,
    sexta = 6,
    sabado = 7
};
*/

struct dados {
    char nome[255];
    char cidade[255];
    float faturamento;

};

int main()
{
    struct dados m_dados;
    printf("Digite o nome da loja, cidade e faturamento");
    scanf("%s %s %f", &m_dados.nome, &m_dados.cidade, &m_dados.faturamento);

    printf("Nome da loja: %s", m_dados.nome);
    printf("Nome da cidade: %s", m_dados.cidade);
    printf("Faturamento: R$%.2f", m_dados.faturamento);

    /*
    enum semana choice;


    printf("Digite o n�mero da semana");
    scanf("%d", &choice);

    switch(choice){
        case domingo:{
            printf("Domingo");
            break;
        }
        case segunda:{
            printf("Segunda");
            break;
        }
        case terca:{
            printf("Terca");
            break;
        }
        case quarta:{
            printf("Quarta");
            break;
        }
        case quinta:{
            printf("Quinta");
            break;
        }
        case sexta:{
            printf("Sexta");
            break;
        }
        case sabado:{
            printf("Sabado");
            break;
        }
    }*/



    return 0;
}
