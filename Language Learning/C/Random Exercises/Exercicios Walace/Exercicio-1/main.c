#include "stdio.h"  // adicionado a cerquilha e as aspas
#include "stdlib.h"
#include "locale.h" // adicionado hearder file para acentuar o output
/*
O programa de exemplo apresenta quatro erros: 1 - Erro de syntax, falta um sinal de maior ou menor, ou aspas na header file.
                                              2 - Falta o endereçador "&" no scanf, para que o input seja guardado no espaco de memoria indicado pela variavel.
                                              3 - Falta uma cerquilha "#" no directivo include.
                                              4 - Falta a header file para incluir caracteres acentuados no output
*/
int main()
{
    int numero = 0;
    setlocale(LC_ALL, "Portuguese"); //permite output

    printf("Informe o valor de um número: ");
    scanf("%d", &numero); //enderecador adicionado
    printf("O número informado foi: %d", numero);

    return 0;
}
