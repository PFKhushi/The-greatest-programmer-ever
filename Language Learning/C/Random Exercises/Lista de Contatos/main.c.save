#include <stdio.h>
#include <stdlib.h>

typedef struct contatos{
    char nome[60], telefone[15], email[50];
}contato;

ty
contato *lista;
int tam;

int main()
{
    tam = 0;
    lista = (contato *)malloc(100/*,*/* sizeof(lista));

    for(int i=0;i<3;i++){
        criar_ctt(tam);
        printf("\n%d\n",tam);
    }

    imprimir(3);
    free(lista);
    return 0;
}

void imprimir(int tamanho){

    for(int i=0; i<tamanho;i++){
        printf("\nContato num: %d\nNome: %s\n", i+1,lista[i].nome);
        printf("Telefone: %s\nEmail: %s\n\n", lista[i].telefone, lista[i].email);
    }
}

void criar_ctt(){

    int placeholder = "NO EMAIL";

    if(tam==100){
        printf("Sua lista ta cheia\n");
    }else{
        printf("Qual o nome do contato?\n");
        scanf("%s", lista[tam].nome);
        printf("Qual o número?\n");
        scanf("%s", lista[tam].telefone);
        int x = 0;
        while(x==0){
            printf("Deseja adicionar um email para esse contato?\n1 - sim\n2 - nao\n");
            scanf("%d", &x);
            if(x==1){
                printf("Digite o email:\n");
                scanf("%s", lista[tam].email);
            }else if(x==2){
                strcpy(lista[tam].email, placeholder);
            }else{
                x = 0;
            }
        }
    tam++;
    }
}

int busca_sequencial(){

        printf("Digite o nome, número ou email que deseja encontrar:\n");
        char pesquisa[50];
        int resultado;
        scanf("%s", pesquisa);

        for(int i=0;i<tam;i++){
            if(pesquisa==lista[i].nome || pesquisa==lista[i].telefone || pesquisa==lista[i].email){
                return i;
            }else{
                return -1;
            }
        }
}

void eliminar(){

    printf("Para eliminar:\n");

    int eliminar = busca_sequencial();

    for(int i=eliminar; i<(tam-1);i++){
        strcpy(lista[i].nome, lista[i+1].nome);
        strcpy(lista[i].email, lista[i+1].email);
        strcpy(lista[i].telefone, lista[i+1].telefone);
    }
    tam--;
}

void menu(){

    printf()
}
