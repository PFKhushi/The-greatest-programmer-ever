#include <stdio.h>
#include <stdlib.h>

int main()
{

/*
1) Criar uma aplicação, para ler dois nomes. Em seguida deve ser
exibido o tamanho de cada nome, e se eles são iguais, se o primeiro é
maior, ou se o primeiro é menor.
*/

/*

    char nome1[256], nome2[256];
    int ordem, i, tam1, tam2, espaco1, espaco2, num_nome1, num_nome2;
    ordem = i = tam1 = tam2 = espaco1 = espaco2 = num_nome1 = num_nome2 = 0;

    nome1[0] = '\0';
    nome2[0] = '\0';

    printf("Digite o primeiro nome completo.\n");
    gets(nome1);

    printf("Digite o segundo nome completo\n");
    gets(nome2);


    ordem = strcmp (nome1, nome2);


    while (nome1[i] != '\0'){

        if (nome1[i] != ' '){
            tam1++;
        }else {
            espaco1++;
        }
        i++;
    }

    if (nome1[i] == ' '){
        nome1[i] = '\0';
        espaco1--;
    }

    i = 0;

    while (nome2[i] != '\0'){

        if (nome1[i] != ' '){
            tam2++;
        }else {
            espaco2++;
        }
        i++;
    }

    if (nome2[i] == ' '){
        nome2[i] = '\0';
        espaco2--;
    }

    num_nome1 = espaco1 + 1;
    num_nome2 = espaco2 + 1;

    printf("\n\n");

    if (tam1 > tam2){
        printf("O primeiro nome com %d partes e com %d letras é mais longo que o segundo com %d partes e com %d letras, ", num_nome1, tam1, num_nome2, tam2);
    }
    else if ( tam1 < tam2) {
        printf("O primeiro nome com %d partes e com %d letras é mais curto que o segundo com %d partes e com %d letras, ", num_nome1, tam1, num_nome2, tam2);
    }
    else {
        printf("O primeiro nome com %d partes e com %d letras tem o mesmo tamnho que o segundo com %d partes e com %d letras, ", num_nome1, tam1, num_nome2, tam2);
    }


    if (ordem == -1){
        printf("e o primeiro nome vem lexicalmente antes do segundo.");
    }
    else if ( ordem == 1){
        printf("e o primeiro nome vem lexicalmente depois do segundo.");
    }else {
        printf("e os nomes sao lexicalmente iguais.");
    }

    printf("\n\n");

*/













/*
2. Fazer um programa que inverta um string. "Parabens a voce" vira "ecov
a snebaraP".
*/

/*
    char frase[256], frase_b[256];
    int i, j;

    printf("Digite umas frase:\n");
    gets(frase);

    j = 0;

    for (i = strlen(frase)-1; i >= 0; i--){

        frase_b[j] = frase[i];
        j++;

    }
    printf("%s", frase_b);
*/












/*
3. Converter um string para maiúsculo, e depois para minúsculo.
*/

/*

    char frase[256], frase_mai[256], frase_min[256];
    int i, tam;


    printf("Digite uma frase\n");
    gets(frase);
    tam = strlen(frase);

    //for maiusculo
    for (i=0; i <= tam; i++){

        frase_mai[i] = tolower(frase[i]);
        frase_min[i] = toupper(frase[i]);
    }
    printf("\n%s\n%s\n%s\n", frase, frase_mai, frase_min);
*/











/*
4. Leia o nome completo de uma pessoa (nome /
sobrenome / nome do meio). Em seguida, exiba cada
um dos em linhas diferentes e depois, exiba cada um
dos nomes em linhas diferentes, mas na ordem inversa das palavras.

Ex.: João da Silva Cavalcanti.
João
da
Silva
Cavalcanti

Ex.: João da Silva Cavalcanti.
Cavalcanti
Silva
da
João



*/

/*
    char nome[256];
    int i, espacos = 0, num_palavras = 0, j, vetor[100], temp, w, p, z;

    printf("Digite seu nome completo\n");
    scanf("%[^\n]", nome);

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
    printf("\n\nCada nome em sua linha:\n");
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

*/
/*
6. Fazer uma função que recebe uma string como parâmetro e retorna uma
string obtido ao se eliminar os espaços em branco no início e fim do string:

" Bom dia, senhor " deve ser transformado em "Bom dia, senhor"
"Bom dia, senhor "  deve ser transformado em "Bom dia, senhor"
" Bom dia, senhor"  deve ser transformado em "Bom dia, senhor"
*/

/*
    char frase[256], ch;
    int i, p, z, w, d = 1;

    w = z = p = i = 0;

    printf("Digite uma frase;\n");
    scanf("%[^\n]", frase);

    while (frase[i] != '\0'){//percorre array
        if (frase[i] != ' '){//checa se char nao é um espaco para q nao seja removido por nao ser alpha e incrementa i
            if (!isdigit(frase[i])){//checa se o char no index i nao é um digit, o programa n faz nada
            }
            else{//checa se o char no index i nao for nem letra nem um espaco
                p = i;
                while (p <= strlen(frase)){//tira o espaco
                    z = p + 1;
                    frase[p] = frase[z];
                    p++;
                }
            }
            i++;
        }
        else{//se o valor no index i for uma letra ou espaco, incremente i
            i++;
        }
    }

    while (frase[strlen(frase)-1] == ' '){//um while para retirar o espaco do ultimo index, se houver
        frase[strlen(frase)-1] = '\0';
    }

    i = 0;
    while (frase[i] != '\0'){//percorre o array
            w = i + 1;
            if (frase[i] == ' ' && frase[w] == ' '){//checa se existem dois espacos seguido, se houver, decrementa o i para checar o mesmo index apos remocao
                    p = i;

                while (p <= strlen(frase)){//remove espaco duplo
                    z = p + 1;
                    frase[p] = frase[z];
                    p++;
                }

            }
            else{//incrementa o i se nao houverem espacos duplos
                i++;
            }
        }

    if (frase[0] == ' '){
        d = 0;
    }else{d=1;}
    i=0;
    while(d == 0){
        ch = frase[0];
        if(ch == ' '){
            do{
                z = i + 1;
                frase[i] = frase[z];
                i++;
            }while(frase[i] != '\0');
        }

        if (ch == ' '){
            d = 0;
        }else{d=1;};
    }

    printf("%s", frase);
*/

/*
7. Fazer uma função que codifica um string pelo método
ZENIT-POLAR

Z E N I T
P O L A R

Ou seja, onde aparece um 'Z' no string de entrada, aparecerá um'P' na saída;
e, semelhantemente, onde aparece um 'P' nostring de entrada, aparecerá um 'Z' na saída.
Isto deve ocorrerpara todos os pares em ZENIT-POLAR, maiúsculas eminúsculas. As outras letras não são alteradas.

Por exemplo, o string "Parabens a voce" é codificadopara "Zitibols i veco".
Ao se aplicar duas vezes atransformação, obtém-se o mesmo string, ou seja, acodificação de "Zitibols i veco" é "Parabens a voce".
*/


    char frase[256], zenit[]="ZENITzenit", polar[]="POLARpolar";
    int i, j, w;

    j = i = 0;

    //checar se frase[i] ta dentro de zenit ou polar para trocar as letras com o index da string correspondente usando uma atribuicao de variavel por index

    printf("Digite uma string:\n");
    gets(frase);
    while(frase[i] != '\0'){
            for (w = 0; w <= 9; w++){
                if (frase[i] == zenit[w]){
                    frase[i] = polar[w];
                }
                else if(frase[i] == polar[w]){
                    frase[i] = zenit[w];
                    }
                }
            i++;
            }

    printf("%s", frase);





    return 0;
}
