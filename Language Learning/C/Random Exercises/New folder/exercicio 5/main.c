#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "Portuguese");
    int mes, a, b, c, ano;
    a = 31;
    b = 30;
    c = 29;
    printf("Qual o número do mês?\n");
    scanf("%d", &mes);
    printf("Qual o ano?\n");
    scanf("%d", &ano);

    if (ano % 4 == 0){ c-- ;}


    switch(mes){
        case 1 : {
            printf("Janeiro possui %d dias em %d",a,ano);
            break;
        }
        case 2 : {
            printf("Fevereiro possui %d dias em %d",c,ano);
            break;
        }
        case 3 : {
            printf("Marco possui %d dias em %d",a,ano);
            break;
        }
        case 4 : {
            printf("Abril possui %d dias em %d",b,ano);
            break;
        }
        case 5 : {
            printf("Maio possui %d dias em %d",a,ano);
            break;
        }
        case 6 : {
            printf("Junho possui %d dias em %d",b,ano);
            break;
        }
        case 7 : {
            printf("Juho possui %d dias em %d",a,ano);
            break;
        }
        case 8 : {
            printf("Agosto possui %d dias em %d",a,ano);
            break;
        }
        case 9 : {
            printf("Setembro possui %d dias em %d",b,ano);
            break;
        }
        case 10 : {
            printf("Outubro possui %d dias em %d",a,ano);
            break;
        }
        case 11 : {
            printf("Novembro possui %d dias em %d",b,ano);
            break;
        }
        case 12 : {
            printf("Dezembro possui %d dias em %d",a,ano);
            break;
        }
    }
    return 0;
}
//Dizer qual mes e quantos dias baseado no numero do mes
