#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{

    char nome[256], maius[256], minus[256];
    int i, espacos = 0, num_palavras = 0, j, vetor[100], temp, w, p, z;

    setlocale(LC_ALL, "Portuguese");

    printf("Digite seu nome completo\n");
    scanf("%[^\n]", nome);

    printf("\n\n\n\nNome impresso com mascara de string:\n%s\n\n", nome);


    for(i=0;i<strlen(nome);i++){
        maius[i]=toupper(nome[i]);
        minus[i]=tolower(nome[i]);
    }
    printf("Onome em maiúsculo:\n%s\n\nO nome em minúsculo\n%s\n\n", maius, minus);

    //imprimir texto caracter a caracter invertido
    printf("Nome impresso carácter a caracter invertido:\n");
    for(i=strlen(nome)-1; i>=0; i--){

        printf("%c", nome[i]);
    }
    printf("\n\n");

    //imprimeir texto caracter a caracter
    printf("Nome impresso caráracter á caracter:\n");
    for(i=0; i<strlen(nome); i++){

        printf("%c", nome[i]);
    }
    printf("\n");

    i = 0;

    while (nome[i] != '\0'){//percorre array
        if (nome[i] != ' '){//checa se char nao é um espaco para q nao seja removido por nao ser alpha e incrementa i
            if (isalpha(nome[i])){//checa se o char no index i for alpha, o programa n faz nada
            }
            else{//checa se o char no index i nao for nem letra nem um espaco
                p = i;
                while (p <= strlen(nome)){//tira o espaco
                    z = p + 1;
                    nome[p] = nome[z];
                    p++;
                }
            }
            i++;
        }
        else{//se o valor no index i for uma letra ou espaco, incremente i
            i++;
        }
    }
    i = strlen(nome)-1; //uma string com seis itens, comeca do zero e vai até o cinco, por isso o -1
    if (nome[i] == ' '){//um if para retirar o espaco do ultimo index, se houver
        nome[i] = '\0';
    }
    i = 0;
    if (nome[0] == ' '){//checa se o primeiro item é um espaco
        while (nome[i] != '\0'){//percorre o vetor para tirar o primeiro expaco
            w = i + 1;
            nome[i] = nome[w];//troca o index com o seguinte
            i++;
        }
    }
    i = 0;
    while (nome[i] != '\0'){//percorre o array
        w = i + 1;
        if (nome[i] == ' ' && nome[w] == ' '){//checa se existem dois espacos seguido, se houver, decrementa o i para checar o mesmo index apos remocao
                p = i;
                i--;
            while (p <= strlen(nome)){//remove espaco duplo
                z = p + 1;
                nome[p] = nome[z];
                p++;
            }
        }
        else{//incrementa o i se nao houverem espacos duplos
            i++;
        }
    }
    i = 0;
    j = 0;
    vetor[0] = i - i;
    while (nome[i] != '\0'){//percorrendo a string para saber a quantidade de espacos
                            //e adicionar seus respectivos index no vetor
        if (nome[i] == ' '){
            j++;
            espacos++;
            vetor[j] = i;
        } //adiciona o index do final da string
        i++;
    }
    num_palavras = espacos + 1;//conta o numero de palavras para o for loop
    vetor[j+1] = strlen(nome);//determina q o ultimo index contem o final da string
    i = 1;//zero é null ent comeca do 1
    j=0;
    w=0;
    p = j+1;
    printf("\nCada nome em sua linha:\n");
    for (i=0; i < num_palavras; i++){
        for (w=vetor[j]; w<=vetor[p]; w++){
            if (nome[w] != ' '){
                printf("%c", nome[w]);
            }
        }//Percorre a parte selecionada da string
        printf("\n");
        j++;
        p = j+1;
    }
    z = num_palavras;//num_palavras é o numero de vetores, contanto com o zero
    printf("\n\nCada nome em sua linha, mas invertido:\n");
    for (i=0; i < z; i++){
        for (w=vetor[num_palavras-1]; w<=vetor[num_palavras]; w++){
            if (nome[w] != ' '){
                printf("%c", nome[w]);
            }
        }//Percorre a parte selecionada da string
        printf("\n");
        num_palavras--;
    }


    return 0;
}
