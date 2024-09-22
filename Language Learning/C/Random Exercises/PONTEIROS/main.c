#include <stdio.h>
#include <stdlib.h>

int main()
{
    arrayAsFunctionArgs();
    return 0;
}

void testes1(){

    int num = 1026; // 4 bytes B4-00000000 B3-00000000 B2-00000100 B1-00000010
    int *ponteiro_int,**pdep_int, ***pdpdp_int;


    ponteiro_int = &num;
    pdep_int = &ponteiro_int;
    pdpdp_int = &pdep_int;

    char *ponteiro_char = (char*)ponteiro_int;//Como char so tem 1 byte, o ponteiro vai guardar o primeiro byte de num 00000010 = 2
    char *ponteiro2_char = ((char*)ponteiro_int)+1;//Aqui vamos para o segundo byte de num q contém 00000100 = 4
    char *ponteiro3_char = ((char*)ponteiro_int)+2;//Acessando o terceiro byte para garantir q é zero 00000000 = 0
    char str[32];

    printf("O valor de num: %d\n",num);
    printf("O endereco de num: %d\n",&num);
    printf("Valor em binario: %s\n", itoa(1026,str,2));
    printf("\n\n");

    printf("O valor do endereco do ponteiro_int: %d\n", *ponteiro_int);
    printf("O endereco guardado no ponteiro_int: %d\n", ponteiro_int);
    printf("Valor em binario: %s\n", itoa(*ponteiro_int,str,2));
    printf("\n\n");

    printf("O valor de ponteiro_char: %d\n",*ponteiro_char);
    printf("O endereco de ponteiro_char: %d\n", ponteiro_char);
    printf("Valor em binario: %s\n", itoa(*ponteiro_char,str,2));
    printf("\n\n");

    printf("O valor de ponteiro2_char: %d\n",*ponteiro2_char);
    printf("O endereco de ponteiro2_char: %d\n", ponteiro2_char);
    printf("Valor em binario: %s\n", itoa(*ponteiro2_char,str,2));
    printf("\n\n");

    printf("O valor de ponteiro3_char: %d\n",*ponteiro3_char);
    printf("O endereco de ponteiro3_char: %d\n", ponteiro3_char);
    printf("Valor em binario: %s\n", itoa(*ponteiro3_char,str,2));
    printf("\n\n");

    printf("Quantos byes tem um ponteiro void: %d\n\n", sizeof(void*));

    printf("O endereco guardado em pdep_int: %d\n",pdep_int);
    printf("A desreferenciacao de pdep_int ou *pdep_int ou ponteiro_int ou &num: %d\n",*pdep_int);
    printf("A desreferenciacao da desreferenciacao de pdep_int ou **pdep_int ou *ponteiro_int ou num: %d\n\n",**pdep_int);

    printf("O endereco guardado em pdpdp_int ou &pdep_int: %d\n",pdpdp_int); //pdpdp_int>pdep_int>ponteiro_int>num
    printf("A desreferenciacao de pdpdp_int ou *pdpdp_int ou pdep_int ou &ponteiro_int: %d\n",*pdpdp_int);
    printf("A desreferenciacao da desreferenciacao de pdpdp_int ou **pdpdp_int ou ponteiro_int ou &num: %d\n",**pdpdp_int);
    printf("A desreferenciacao da desreferenciacao da desreferenciacao de pdpdp_int ou ***pdpdp_int ou pdep_int ou **pdep_int ou *ponteiro_int ou num: %d\n",***pdpdp_int);

}

void soma(int *num1, int *num2, int *result){
    *result = (*num1)+(*num2);
}

void numes(){
    int a, b, ans, *num1, *num2, *result,**pp_num, ***ppp_num;

    num1 = &a;
    pp_num = &num1;
    ppp_num = &pp_num;
    num2 = &b;
    result = &ans;
    ***ppp_num=5;
    *num2=6;
    soma(**ppp_num,&b,result);

    printf("O resultado foi %d", ans);
}
void ptoarray(){
    int A[]={2,4,6,8,10};
    int *p=A;

    for(int i=0;i<5;i++){

        printf("Endereco: %d\n",(p+i));
        printf("Valor: %d\n",*(p+i));

        printf("Endereco: %d\n",A+i);
        printf("Valor: %d\n",*(A+i));//A++ would be invalid, somehow p++ works

        printf("Endereco: %d\n",&A[i]);
        printf("Valor: %d\n",A[i]);

    }
}
void arrayAsFunctionArgs(){
    int A[] = {2,3,4,5,6};
    int* p = A;

    int size = sizeof(A)/sizeof((A[0]));
    int total = sum(p,size);
    printf("A soma: %d\n", total);
}
int sum(int p[], int size){
    //pode usar ou int p[] ou int* p
    int i, soma = 0;
    for(i=0;i<size;i++){
        printf("Some %d\n", p[i]);
        soma += p[i];
    }
    return soma;
}
