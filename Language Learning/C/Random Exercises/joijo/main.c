#include <stdio.h>
#include <string.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "Portuguese");

    int numeros[10], i, maior, menor, tres, busca, contag_busca;
    char op = 'a', vezes[6], vezes_b[6];

    i = maior = menor = tres = busca = contag_busca = 0;
    numeros[0] = vezes [0] = vezes_b[0] = '\0';
    printf("Digite 10 n�meros:\n");

    //receber, ver se op � a. se op for a, maior/menor recebem numeros[index referente], contar os 3
    for(i=0;i<10;i++){
        scanf("%d", &numeros[i]);
        if(op == 'a'){
            op = 'b';
            maior = menor = numeros[i];
        }
        else{
            if(menor > numeros[i]){
                menor = numeros[i];
            }
            else if(maior < numeros[i]){
                maior = numeros[i];
            }
        }
    }
    i=0;
    printf("Qual n�mero voc� deseja procurar no array:\n");
    scanf("%d", &busca);

    printf("\n\n\n\n");

    printf("%d\n", busca);



    for(i = 0; i < 10; i++){
        if(numeros[i]==3){
        tres++;
        }
        if(numeros[i] == busca){
            contag_busca++;
        }

    }
    printf("b %d", busca);

    if(tres == 1){
        strcat(vezes, "vez.");
    }
    else{
        strcat(vezes, "vezes.");
    }

    if(contag_busca == 1){
        strcat(vezes_b, "vez.");
    }
    else{
        strcat(vezes_b, "vezes.");
    }
    printf("\nO n�mero \"3\" aparece %d %s\n", tres, vezes);
    printf("O maior n�mero digitado foi o n�mero %d.\n", maior);
    printf("O menor n�mero digitado foi o n�meo %d.\n", menor);
    printf("O n�mero pesquisado, \"%d\", aparece %d %s", busca, contag_busca, vezes_b);
    return 0;
}
