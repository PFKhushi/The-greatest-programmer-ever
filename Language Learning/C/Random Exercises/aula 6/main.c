#include <stdio.h>
#include <stdlib.h>

#define tam 50

typedef struct elementos{
        char nome[31];
        char endereco[31];
        char telefone[31];
        } t_elemento ;

typedef struct lista{
        struct elementos vetor[tam];
        int n;
        } t_lista;

struct lista * criar(){

       struct lista * exercicio1 = (struct lista*)malloc(sizeof(struct lista));

       if(exercicio1)
          exercicio1-> n = -1;
       return exercicio1;

       }
int isVazia(t_lista * lista) {
	return (lista->n == -1);
}

int isCheia(t_lista * lista) {
	return (lista->n == tam-1);
}

int tamanho(t_lista * lista) {
	return lista->n + 1;
}

t_elemento * geElemento(t_lista * lista, int pos) {
	// Retorna 0 se a posiÃ§Ã£o for invÃ¡lida. Caso contrÃ¡rio, retorna o elemento

	// verifica se pos eh valida
	if ( (pos > lista->n) || (pos < 0) )
		return 0;
	return &(lista->vetor[pos]);
}

int compara(t_elemento * dado1, t_elemento * dado2) {
	if (strcmp(dado1->nome, dado2->nome)==0)
	{
		return 1;
	}

	return 0;
}

int getPosicao(t_lista * lista, t_elemento * dado) {
	// Retorna a posiÃ§Ã£o do elemento, ou 0 caso nÃ£o seja encontrado
	int i;
	for (i=0; i<= lista->n; i++)
		if (compara(&(lista->vetor[i]), dado))
			return i;

	return 0;
}

// desloca os elementos da lista para a direita a partir de pos
int deslocaDireita(t_lista * lista, int pos) {
	// Retorna 0 se a posiÃ§Ã£o for invÃ¡lida ou se a lista estiver cheia
	// Caso contrÃ¡rio, retorna 1
	int i;

	if (pos > lista->n)
		return 0;

	for (i=lista->n + 1; i>pos; i--)
		lista->vetor[i] = lista->vetor[i-1];

	return 1;
}

// desloca os elementos da lista para a esquerda a partir de pos
int deslocaEsquerda(t_lista * lista, int pos) {
	// Retorna 0 se a posiÃ§Ã£o for invÃ¡lida ou se a lista estiver cheia
	// Caso contrÃ¡rio, retorna 1
	int i;

	if (pos > lista->n)
		return 0;

	for (i=pos; i<=(lista->n); i++)
		lista->vetor[i] = lista->vetor[i+1];

	return 1;
}


int inserir (t_lista * lista, int pos, t_elemento * dado) {

	if ( isCheia(lista) || (pos > lista->n + 1) )
		return 0;

	deslocaDireita(lista, pos);
	lista->vetor[pos] = *dado;
	(lista->n)++;
	return 1;
}

int remover (t_lista *lista, int pos) {

	if ( (pos > lista->n) || (pos < 0) )
		return 0;

	deslocaEsquerda(lista, pos);

	(lista->n)--;
	return 1;
}





void main(){

     char opcao, nome[50];
     int pos,i;
     t_elemento cadastrar;
     t_lista exibir = *criar();// t_lista exibir recebe  o ponteiro criar para zerar a funçao exibir.

     do{
         system("cls") ;
         system("color 80");
         printf("\n\t\t\t  ESCOLHA UMA DAS OPCOES ABAIXO:");
         printf("\n");
         printf("\n");
         printf("\n\t\t\t  1 - EXIBIR LISTA");
         printf("\n\t\t\t  2 - INSERIR PELA POSICAO");
         printf("\n\t\t\t  3 - REMOVER PELA POSICAO");
         printf("\n\t\t\t  4 - EXIBIR ELEMENTO");
         printf("\n\t\t\t  5 - EXIBIR POSICAO");
         printf("\n\t\t\t  6 - ESVAZIAR");
         printf("\n\t\t\t  7 - SAIR");
         opcao=getch();

         switch(opcao){
                       case '1':system("cls");

                                 printf("\n\t 1 - EXIBINDO A LISTA ");
                                 printf("\n\t =====================");
                                 printf("\n");

                                for(i=0;i<tamanho(&exibir);++i)
                                {
                                 printf("\n\t     O NOME CADASTRADO eh: %s",exibir.vetor[i].nome);
                                 printf("\n\t     O ENDERECO CADASTRADO eh: %s",exibir.vetor[i].endereco);
                                 printf("\n\t     O TELEFONE CADASTRADO eh: %s",exibir.vetor[i].telefone);
                                 printf("\n");
                                }
                                getch(); break;

                       case '2':system("cls");

                                 printf("\n\t 2 - INSERINDO PELA POSICAO");
                                 printf("\n\t ==========================");
                                 printf("\n");
                                 printf("\n\t     PORFAVOR DIGITE UMA POSICAO DA SUA PREFERENCIA: ");
                                 scanf("%d",&pos);
                                 printf("\n\t     INFORME O SEU NOME: ");
                                 scanf("%s",&cadastrar.nome);
                                 printf("\n\t     INFORME O SEU ENDERECO: ");
                                 scanf("%s",&cadastrar.endereco);
                                 printf("\n\t     INFORME O SEU TELEFONE: ");
                                 scanf("%s",&cadastrar.telefone);
                                 printf("\n\t     CADASTRO REALIZADO COM SUCESSO.");
                                 inserir(&exibir, pos, &cadastrar);
                                 getch(); break;

                       case '3':system("cls");

                                 printf("\n\t 3 - REMOVENDO PELA POSICAO");
                                 printf("\n\t ==========================");
                                 printf("\n");
                                 printf("\n\t     PORFAVOR INFORME UMA POSICAO QUE VOCE QUER REMOVER: ");
                                 scanf("%d",&pos);
                                 remover(&exibir,pos);
                                 printf("\n\t     POSICAO REMOVIDO COM SUCESSO.");
                                 getch();break;

                       case '4':system("cls");

                                 printf("\n\t 4 - EXIBIR ELEMENTO");
                                 printf("\n\t ===================");
                                 printf("\n");
                                 printf("\n\t     PROFAVOR INFORME UMA POSICAO: ");
                                 scanf("%d",&pos);
                                 cadastrar = *geElemento(&exibir,pos);
                                 printf("\n\t     NA POSICAO [%d] ESTAM OS ELEMENTOS:  ",pos);
                                 printf("\n");
                                 printf("\n\t     NOME: %s",cadastrar.nome);
                                 printf("\n\t     ENDERECO: %s",cadastrar.endereco);
                                 printf("\n\t     TELEFONE: %s",cadastrar.telefone);
                                 getch();break;


                       case '5':system("cls");

                                 printf("\n\t 5 - EXIBINDO A  POSICAO DO NOME");
                                 printf("\n\t ===============================");
                                 printf("\n");
                                 printf("\n\t     PORFAVOR DIGITE UM NOME JA CADASTRADO: ");
                                 scanf("%s",cadastrar.nome);
                                 pos = getPosicao(&exibir, &cadastrar);
                                 printf("\n");
                                 printf("\n\t     ESTE NOME %s ESTA NA POSICAO [%d] JUNTO COM OS ELEMENTOS: ",cadastrar.nome, pos);
                                 printf("\n");
                                 printf("\n\t     ENDERECO: %s",cadastrar.endereco,pos);
                                 printf("\n\t     TELEFONE: %s",cadastrar.telefone,pos);

                                 getch();break;

                       case '6':system("cls");

                                 printf("\n informe a posicao que vc quer apagar: ");
                                 scanf("%d",&pos);
                                 //cadastrar=isVazia(&exibir,pos);
                                    exibir.n = -1;
                                break;

                       case '7':;break;

                       default :printf("\n\t\t\t  OPCAO INVALIDA POR FAVOR TENTE NOVAMENTE.");
                       getch();
                      }//feicha o switch
         fflush(stdin);
         }while(opcao!= '7');//feicha o do e o while


     }//feicha o programa primcipal
