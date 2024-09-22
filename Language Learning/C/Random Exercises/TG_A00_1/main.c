#include <stdio.h>
#include <stdlib.h>
#define PI 3.14159
#define PRECISAO 0.5

                                   //Exercício: Fazer um funcao para determinar a distancia entre dois pontos
                                   //           Fazer funcoes para tirar a area e o perimetro do quadrado, retangula, paralelogramo, trapezio e losangulo
                                   //           Fazer funcao para determinar a circunferencia e a area do circulo

                                   //Deixei algumas coisas de lado como tratamento de erro de entrada, pois tenho muito mais coisa pra estudar e o objetivo foi comprido
                                   //Sao coisas simples de implementar, mas seria muito trabalho repetido para um dado q pode ser tratado antes de chegar no program
                                   //

typedef struct{
    double *x, *y;
}Ponto;                            //ponteiros para cada dimensao da coordenada

typedef struct{
    Ponto  *ponto_a, *ponto_b;
    double *distancia;
}Reta;                             //ponteiros para duas estruturas com ponteiros para pontos x e y cada uma

void raizquadrada(double *numero); // Função para calcular a raiz quadrada de um número
void ponto_init(Ponto *ponto);     // Função para inicializar um ponto
void reta_init(Reta *reta);        // Função para inicializar uma reta
void distancia(Reta *reta);        // Função para calcular a distância entre dois pontos
void marcar_ponto(Ponto *ponto);   // Função para marcar um ponto no plano
void tracar_reta(Reta *reta);      // Função para traçar uma reta
void free_reta(Reta *reta);        // Função para liberar a memória alocada para uma reta
void printpontos(Reta *reta);      // Função para imprimir os pontos e a distância de uma reta
void imprimir_reta(Reta *reta);    // Função para imprimir os pontos da reta no plano
void circulo();                    // Funcao para dimensionar o circulo
void triangulo();                  // Funcao para calcular area ou o perimetro
void quadrado(double *area, double *altura, double *base, double *perimetro);
void retangulo();                  // Funcao do paradimensionar um retangulo, um quadrado ou um paralelogramo
void losangulo();                  // Funcao para dimensionar um losangulo
void trapezio();                   // Funcao para dimencionar um trapezio
void menu();                       // Funcao para conectar as outras funcoes
void clear();                      // Limpa console


int main()
{
    menu();
    return 0;
}


void clear(){
     system("@cls||clear");
}

void menu(){
    int *select = (int*)calloc(1,sizeof(int)); // Aloca memoria para selecao
    Reta *reta; //Cria um ponteiro para reta, para caso seja usado

    printf("\nO que voce gostaria de fazer?\n\n"
           "1 - Determinar a distancia entra dois pontos\n"
           "2 - Dimensionar um quadrado/retangulo/paralelogramo\n"
           "3 - Dimensionar um losangulo\n"
           "4 - Dimensionar um tringulo\n"
           "5 - Dimensionar um circulo\n"
           "6 - Dimensionar um trapezio\n"
           "0 - Sair\n\n\n\n\n*Mantenha os dados dentro dos reais\n");
    scanf("%d", select);

    clear(); //Limpa console

    switch(*select){
    case 1:
        reta  = (Reta*)malloc(sizeof(Reta)); // Aloca memoria para toda a reta
        reta_init(reta);    // Inicializa a reta com pontos x=0 y=0
        tracar_reta(reta);  // Define os pontos da reta
        imprimir_reta(reta);// Imprime uma representacao de baixa precisao da reta no plano cartesiano
        printpontos(reta);  // Mostra as coordenados de cada ponto
        free_reta(reta);    // Libera a reta toda
        printf("\nAperte ENTER para prosseguir.\n");
        scanf("%*c%[^\n]"); // Scaneia nada pulando um caracter
        clear();
        break;
    case 2:
        retangulo();        // Dimensiona retangula, quadrado e paralelogramo
        printf("\nAperte ENTER para prosseguir.\n");
        scanf("%*c%[^\n]");
        clear();
        break;
    case 3:
        losangulo();        // Dimensiona losangulo
        printf("\nAperte ENTER para prosseguir.\n");
        scanf("%*c%[^\n]");
        clear();
        break;
    case 4:
        triangulo();        // Dimensiona o triangulo
        printf("\nAperte ENTER para prosseguir.\n");
        scanf("%*c%[^\n]");
        clear();
        break;
    case 5:
        circulo();          // Dimensiona o circulo
        printf("\nAperte ENTER para prosseguir.\n");
        scanf("%*c%[^\n]");
        clear();
        break;
    case 6:
        trapezio();         // Dimensiona o circulo
        printf("\nAperte ENTER para prosseguir.\n");
        scanf("%*c%[^\n]");
        clear();
        break;
    case 0:
        free(select);
        select=NULL;
        exit(0);
    }
    free(select);   // Libera a selecao
    select=NULL;    // Exclui dados
    menu(); // Retorna ao menu ao finalizar, o programa é um loop infinito

}

void raizquadrada(double *numero) {

    double *raiz,*i;
    raiz  = (double *)malloc(sizeof(double));
    i     = (double *)malloc(sizeof(double));
    *raiz = *numero;                        //copia a raiz para reduzirmos até chegar no resultado

    for (*i=0;*i<(*numero);(*i)+=PRECISAO){ //quanto maior a iteracao, maior a precisao da raiz
        *raiz = (*raiz+(*numero)/(*raiz))/2;//a cada iteracao, *raiz se aproxima mais da raiz de *numero,
    }                                       //quando a raiz for exata, nenhuma outra iteracao tera
                                            //efeito em *raiz, mantendo seu resultado

    *numero  = *raiz;                       //copiamos *raiz para *numero

    free(raiz);                             //Libera o espaco de memoria e em seguida anula para evitar leaks
    raiz = NULL;
    free(i);
    i    = NULL;

}
void ponto_init(Ponto *ponto){
    ponto->x = (double*)calloc(1,sizeof(double)); //inicializa *x com 0
    ponto->y = (double*)calloc(1,sizeof(double)); //inicializa *y com 0
}

void reta_init(Reta *reta){
    reta->ponto_a   = (Ponto*)malloc(sizeof(Ponto));
    reta->ponto_b   = (Ponto*)malloc(sizeof(Ponto));//alocacao de memoria para passar pra funcao sem leaks
    reta->distancia = (double*)calloc(1,sizeof(double));//aloca memoria para guardar a distancia

    ponto_init(reta->ponto_a); //passando ponteiro para inicializar ponto com *x=0 e *y=0
    ponto_init(reta->ponto_b); //passando ponteiro para inicializar ponto com *x=0 e *y=0

}
void distancia(Reta *reta){

    //printpontos(reta);

    double *XB_XA, *YB_YA, *temp;
    XB_XA              = (double*)calloc(1,sizeof(double)); //alocamos memoria para as abstracoes
    YB_YA              = (double*)calloc(1,sizeof(double));
    temp               = (double*)calloc(1,sizeof(double));

    *XB_XA             = (*(reta->ponto_b->x))-(*(reta->ponto_a->x)); // Xb-Xa
    *XB_XA            *= *XB_XA;                                      // (Xb-Xa)^2
    *YB_YA             = (*(reta->ponto_b->y))-(*(reta->ponto_a->y)); // Yb-Ya
    *YB_YA            *= *YB_YA;                                      // (Yb-Ya)^2
    *temp              = (*YB_YA)+(*XB_XA);                           // ((Xb-Xa)^2)+((Yb-Ya)^2)

    raizquadrada(temp);                                               // raizquadrada de ((Xb-Xa)^2)+((Yb-Ya)^2)
    *(reta->distancia) = *temp;                                       // copia ponteiro temporario para a distancia da reta

    free(XB_XA);                                                      //Libera o espaco de memoria e em seguida aluna para evitar leaks
    XB_XA = NULL;

    free(YB_YA);
    YB_YA = NULL;

    free(temp);
    temp  = NULL;
}
void marcar_ponto(Ponto *ponto){

    printf("\nDigite o valor de X no plano\n");
    scanf("%lf", ponto->x); //scanf recebe long float e o endereco x apontado por ponto
    printf("\nDigite o valor de Y no plano\n");
    scanf("%lf", ponto->y); //scanf recebe long float e o endereco y apontado por ponto
    clear();
}
void tracar_reta(Reta *reta){

    printf("\nAperte ENTER para digitar inserir as coordenadas dos pontos.\n");
    scanf("%*c%[^\n]"); //pula um caracter
    clear();
    printf("\nPonto A\n");
    marcar_ponto(reta->ponto_a); //marca o ponto no plano
    printf("\nPonto B\n");
    marcar_ponto(reta->ponto_b); //marca o ponto no plano
    distancia(reta);

}

void free_reta(Reta *reta){

    free(reta->ponto_a->x);  //Libera o espaco de memoria e em seguida aluna, para
    reta->ponto_a->x = NULL; //evitar leaks, em todos os ponteiros da estrutura e por final, na estrutura
    free(reta->ponto_a->y);
    reta->ponto_a->y = NULL;
    free(reta->ponto_b->x);
    reta->ponto_b->x = NULL;
    free(reta->ponto_b->y);
    reta->ponto_b->y = NULL;
    free(reta->ponto_a);
    reta->ponto_a    = NULL;
    free(reta->ponto_b);
    reta->ponto_b    = NULL;
    free(reta->distancia);
    reta->distancia  = NULL;
    free(reta);
    reta             = NULL;
}
void printpontos(Reta *reta){
    printf("\nPonto A={ X %.2lf, Y %.2lf}\n", *(reta->ponto_a->x),*(reta->ponto_a->y)); // Imprime os dados de cada ponto
    printf("\nPonto B={ X %.2lf, Y %.2lf}\n", *(reta->ponto_b->x),*(reta->ponto_b->y));
    printf("\nA dstancia entre os dois pontos e de: %.2f\n", *(reta->distancia));
}

void imprimir_reta(Reta *reta){

    int *XMenor, *XMaior, *XDifer, *YMenor, *YMaior, *YDifer; //representacao das dimensoes do plano

    XMenor = (int*)calloc(1,sizeof(int));
    XMaior = (int*)calloc(1,sizeof(int));
    XDifer = (int*)calloc(1,sizeof(int));

    YMenor = (int*)calloc(1,sizeof(int));
    YMaior = (int*)calloc(1,sizeof(int));
    YDifer = (int*)calloc(1,sizeof(int));

    //decide quem sao os maiores e menores e aumenta em 1 unidade a matriz
    *XMenor = (*(reta->ponto_a->x)) <= (*(reta->ponto_b->x)) ? (int)(1-(*(reta->ponto_a->x))) : (int)(1-(*(reta->ponto_b->x)));
    *XMaior = (*(reta->ponto_a->x)) >= (*(reta->ponto_b->x)) ? (int)(1+(*(reta->ponto_a->x))) : (int)(1+(*(reta->ponto_b->x)));
    *YMenor = (*(reta->ponto_a->y)) <= (*(reta->ponto_b->x)) ? (int)(1-(*(reta->ponto_a->y))) : (int)(1-(*(reta->ponto_b->y)));
    *YMaior = (*(reta->ponto_a->y)) >= (*(reta->ponto_b->x)) ? (int)(1+(*(reta->ponto_a->y))) : (int)(1+(*(reta->ponto_b->y)));

    *XDifer = (*XMaior)-(*XMenor); //estabelece a distancia entre Xa e Xb
    *YDifer = (*YMaior)-(*YMenor); //estabelece a distancia entre Ya e Yb

    int *x,*y; // X = abscisas Y = ordenadas
    x = (int*)calloc(1,sizeof(int));
    y = (int*)calloc(1,sizeof(int));
    printf("\n");
    for((*y)=(*YMaior);(*y)>=(*YMenor);(*y)--){//percorre as ordenadas
        printf("%d",abs(*y)%10); // imprime aprenos as unidade de um numero absoluto representando a distancia no eixo
        for((*x)=(*XMenor);(*x)<=(*XMaior);(*x)++){//percorre as abscisas
            if(((int)(*(reta->ponto_a->x))==(*x))&&((int)(*(reta->ponto_a->y))==(*y))){
                printf("A"); // Quando o ponto for representado pelo loop, é marcado
            }else if(((int)(*(reta->ponto_b->x))==(*x))&&((int)(*(reta->ponto_b->y))==(*y))){
                printf("B"); // Se quando o ponto for representado pelo loop, é marcado
            }else{
                if(((*y)==0)^((*x)==0)){
                    (*y)==0?printf("-"):printf("|"); // Traca o eixo das ordenadas ou das abscisas no plano visualmente
                }else if((*y)==0 && 0==(*x)){
                    printf("+"); // Marco o zero dos dois eixos
                }else{
                    printf("*"); // Serve de espacamento e de marcador de pontos vazios
                }
            }
        }
        printf("\n");
    }
    printf(" ");
    for(*x=(*XMenor);(*x)<=(*XMaior);(*x)++){
        printf("%d",abs(*x)%10); // Imprime a representacao das medidas no eixo das abscisas sem sinal e sem dezenas
    }
    printf("\n\n\nReta AB\n");

    free(XMaior); // Libera tudo
    XMaior=NULL;
    free(XMenor);
    XMenor=NULL;
    free(YMaior);
    YMaior=NULL;
    free(YMenor);
    YMenor=NULL;
}

void triangulo(){
    double *perimetro, *base, *altura, *ladoA, *ladoB, *area; // Aloca memoria para as dimensoes do triangulo e do select
    area        = (double*)calloc(1,sizeof(double));
    perimetro   = (double*)calloc(1,sizeof(double));
    base        = (double*)calloc(1,sizeof(double));
    altura      = (double*)calloc(1,sizeof(double));
    ladoA       = (double*)calloc(1,sizeof(double));
    ladoB       = (double*)calloc(1,sizeof(double));
    int *select = (int*)calloc(1,sizeof(int));

    printf("\nO que voce quer saber sobre o triangulo?\n"
           "\n1 - Area"
           "\n2 - Perimetro\n\n");
    scanf("%d", select);    // Se prepara para calcular de forma preguicosa o triangulo

    switch(*select){
    case 1: // Calcula a area = base * altura
        printf("\n\nQual a base?\n");
        scanf("%lf", base);
        printf("\nQual a altura?\n");
        scanf("%lf", altura);
        *area = ((*base)*(*altura))/2;
        printf("\nA area desse triangulo é de %.2lf\n", *area);
        break;
    case 2: // Calcula o perimetro = A + B + C
        printf("\nQual o lado A?\n");
        scanf("%lf", base);
        printf("\nQual o lado B?\n");
        scanf("%lf", ladoA);
        printf("\nQual o lado C?\n");
        scanf("%lf", ladoB);
        *perimetro = (*base)+(*ladoA)+(*ladoB);
        printf("\nO perimetro do triangulo é de %.2lf\n", *perimetro);

    }
    free(perimetro); // Libera tudo
    perimetro=NULL;
    free(base);
    base=NULL;
    free(altura);
    altura=NULL;
    free(ladoA);
    ladoA=NULL;
    free(ladoB);
    ladoB=NULL;
    free(select);
    select=NULL;
    free(area);
    area=NULL;
}
void retangulo(){
    double *base,*lado,*altura,*area,*perimetro; // Aloca memoria para as dimensoes
    int *select = (int*)calloc(1,sizeof(int));

    base        = (double*)calloc(1,sizeof(double));
    altura      = (double*)calloc(1,sizeof(double));
    area        = (double*)calloc(1,sizeof(double));
    perimetro   = (double*)calloc(1,sizeof(double));
    lado        = (double*)calloc(1,sizeof(double));

    printf("\nQual forma voce quer saber as dimensoes?\n\n"
           "1 - Quadrado\n2 - Retangulo\n3 - Paralelogramo\n\n");
    scanf("%d", select);
    clear();

    switch(*select){
    case 1: // Como é um quadrado so precisa de um dado para conhecer os outros ent ele so recebe ou n os dados e para para a funcao q calcula
        printf("\nVoce sabe a area do quadrado?\n1 - Sim\n2 - Nao\n\n");
        scanf("%d", select);
        if((*select)==1){
            printf("Digite a area:\n");
            scanf("%lf",area);
            *select=0;
            clear();
        }
        printf("\nVoce sabe o lado do quadrado?\n1 - Sim\n2 - Nao\n\n");
        scanf("%d", select);
        if((*select)==1){
            printf("Digite a lado:\n");
            scanf("%lf",base);
            *lado = *base; // Calculo feito para acelerar o processo da funcao q faz os outros calculos
            *select=0;
            clear();
        }
        printf("\nVoce sabe o perimetro do quadrado?\n1 - Sim\n2 - Nao\n\n");
        scanf("%d", select);
        if((*select)==1){
            printf("Digite a perimetro:\n");
            scanf("%lf",perimetro);
            *select=0;
            clear();
        }
        (((*area)*(*altura)*(*base)*(*perimetro))!=0) ? printf("Voce ja sabia de tudo.\n") : printf("Computando..\n"); // Se faltar alguma coisa n tem como ser diferente de zero
        quadrado(area,altura,base,perimetro); // Recebe os dados para calcular o resto
        (((*area)*(*altura)*(*base)*(*perimetro))==0) ? printf("Voce nao sabe de nada.\n") : printf("Computacao terminada\n");
        break;

    case 2: // Vai basicamente fazer o mesmo do anterior, mas tendo cuidado para q base e altura n sejam iguais ou vai so dimensionar um quadrado
        printf("\nVoce sabe a area do retangulo?\n1 - Sim\n2 - Nao\n\n");
        scanf("%d", select);
        clear();
        if((*select)==1){
            printf("Digite a area:\n");
            scanf("%lf",area);
            *select=0;
            clear();
        }
        printf("\nVoce sabe a base do retangulo?\n1 - Sim\n2 - Nao\n\n");
        scanf("%d", select);
        clear();
        if((*select)==1){
            printf("Digite a lado:\n");
            scanf("%lf",base);
            *select=0;
            clear();
        }
        printf("\nVoce sabe a altura do retangulo?\n1 - Sim\n2 - Nao\n\n");
        scanf("%d", select);
        clear();
        if((*select)==1){
            printf("Digite a lado:\n");
            scanf("%lf",altura);
            *select=0;
            clear();
        }
        printf("\nVoce sabe o perimetro do retangulo?\n1 - Sim\n2 - Nao\n\n");
        scanf("%d", select);
        clear();
        if((*select)==1){
            printf("Digite a perimetro:\n");
            scanf("%lf",perimetro);
            *select=0;
            clear();
        }
        (((*area)*(*altura)*(*base)*(*perimetro))!=0) ? printf("\nVoce ja sabia de tudo.\n") : printf("\n\nComputando..\n");
        quadrado(area,altura,base,perimetro); // Se faltar dados vai dimensionar como se fosse um quadrado
        (((*area)*(*altura)*(*base)*(*perimetro))==0) ? printf("\nVoce nao sabe de nada.\n") : printf("\nComputacao terminada\n");
        break;

    case 3: // Vai fazer o mesmo do retangulo, mas dessa vez vai tentar calcular o lado, sabendo q é maior q a altura, caso tenho informacao suficiente
        printf("\nVoce sabe a area do paralelogramo?\n1 - Sim\n2 - Nao\n\n");
        scanf("%d", select);
        clear();
        if((*select)==1){
            printf("Digite a area:\n");
            scanf("%lf",area);
            *select=0;
            clear();
        }
        printf("\nVoce sabe a base do paralelogramo?\n1 - Sim\n2 - Nao\n\n");
        scanf("%d", select);
        clear();
        if((*select)==1){
            printf("Digite a base:\n");
            scanf("%lf",base);
            *select=0;
            clear();
        }
        printf("\nVoce sabe a altura do paralelogramo?\n1 - Sim\n2 - Nao\n\n");
        scanf("%d", select);
        clear();
        if((*select)==1){
            printf("Digite a altura:\n");
            scanf("%lf",altura);
            *select=0;
            clear();
        }
        printf("\nVoce sabe o lado do paralelogramo?\n1 - Sim\n2 - Nao\n\n");
        scanf("%d", select);
        clear();
        if((*select)==1){
            printf("Digite o lado:\n");
            scanf("%lf",lado);
            *select=0;
            clear();
        }
        printf("\nVoce sabe o perimetro do paralelogramo?\n1 - Sim\n2 - Nao\n\n");
        scanf("%d", select);
        clear();
        if((*select)==1){
            printf("Digite a perimetro:\n");
            scanf("%lf",perimetro);
            *select=0;
            clear();
        }
        (((*area)*(*altura)*(*base)*(*perimetro))!=0) ? printf("Voce ja sabia de tudo.\n") : 0;
        quadrado(area,altura,base,perimetro);
        ((*lado)!=0) ? printf("\nLado: %.2lf\n", *lado):0; // Se o lado n for zero ele sera impresso
        ((*lado)!=0) ? ((*perimetro)=2*((*lado)+(*base))) : printf("\nO perimetro do paralelogramo com os dados disponíveis, é menor que o perímetro real\n");
        // Se lado é conhecido, o perimetro certo será impresso, caso contrario, sera explicado q o perimetro é menor q o real
        (((*area)*(*altura)*(*base)*(*perimetro))==0) ? printf("Voce nao sabe de nada.\n") : 0;
        printf("\nAperte ENTER para prosseguir.\n");
        scanf("%*c%[^\n]");

        break;
    }

    free(base); // Libera tudo
    base=NULL;
    free(lado);
    lado=NULL;
    free(altura);
    altura=NULL;
    free(area);
    area=NULL;
    free(perimetro);
    perimetro=NULL;
}
void quadrado(double *area, double *altura, double *base, double *perimetro){
    // Para esse funcao tudo q n tenha base ou altura, é um quadrado
    if((*base)!=0 && (*altura)!=0){ // Se nos tivermos a altura e a base de um retangulo ou quadrado, temos o resto
        *area      = (*base)*(*altura);
        *perimetro = 2*((*base)+(*altura));// Isso tbm serve para o paralelogramo, mas o lado é tratado pelo proprio switch

    }else if(((*area)!=0) && ((*altura)==0) ^ ((*base)==0)){ // Se tivermos a area e exclusivamente a base ou altura, temos o resto
        ((*base)==0) ? ((*base)= ((*area)/(*altura))) : ((*altura)= ((*area)/(*base)));
        *perimetro = 2*((*base)+(*altura));

    }else if((*perimetro)!=0 && (((*base)!=0) ^ ((*altura)!=0) ^ ((*area)!=0))){ // Se tivermos o perimetro e exlusivamente a base ou altura ou area, temos o resto
        if((*area)!=0){// Aqui temos a area e a base será a raiz quadrado da area
            *base   = (*area);
            raizquadrada(base);
            *altura = (*base); // Se for um retangulo e chegou aqui, lhe falta dados e sera considerado um quardrado

        }else{
            ((*base)==0) ? ((*base)=( (*perimetro) - (2*(*altura) ))/2) : ((*altura)=((*perimetro)-(2*(*base)))/2);
            *area = (*base)*(*altura); // Aqui tbm tratamos como um quadrado, so vamos decidir se falta a base ou a altura para preenchermos um com o outro, pois supostamente é um quadrado
        }
    }else{
        if((*area)!=0){// Se só tivermos a area, tratamos como um quadrado e encontramos o resto
            *base = *area;
            raizquadrada(base);
            *altura = *base;
            *perimetro = 4*(*base);
        }else if((*perimetro)!=0){// aqui so temos o perimetro, ent tbm é quadrado
            *base = (*perimetro)/4;
            *altura = *base;
            *area = (*base)*(*altura);
        }else if(((*base)==0) ^ ((*altura)==0)){// aqui so temos ou a base ou a altura
            (*base==0) ? ((*base)=(*altura)) : ((*altura)=(*base));
            *area = (*base)*(*altura);
            *perimetro = 2*((*base)+(*altura));

        }
    }

    printf("Area: %.2lf\nPerimetro: %.2lf\nAltura: %.2lf\nBase: %.2lf\n", *area,*perimetro,*altura,*base);

}
void losangulo(){
    int *select;
    double *lado, *D1, *D2, *area, *perimetro;
                                                // Aloca memoria para as dimensoes do losangulo inicializando tudo cmo 0
    select    = (int*)calloc(1,sizeof(int));    // Zero nos ajuda a indentificar algo q falta
    lado      = (double*)calloc(1,sizeof(double));
    D1        = (double*)calloc(1,sizeof(double));
    D2        = (double*)calloc(1,sizeof(double));
    area      = (double*)calloc(1,sizeof(double));
    perimetro = (double*)calloc(1,sizeof(double));

    printf("\nVoce o lado do losangulo?\n\n1 - Sim\n2 - Nao\n\n");
    scanf("%d", select);
    clear();
    if((*select)==1){ // Pede o lado do losangulo para calcular o perimetro certo e imprimir a dimensao do lada
        printf("Digite o lado?");
        scanf("%lf", lado);
        *perimetro = (*lado)*4;
        *select=0;
        clear();

    }
    printf("\nVoce o sabe quantas diagonais do losangulo?\n\n");
    scanf("%d", select); // Se tivermos o tamanho do lado e uma diagonal, conseguimos encontrar o resto
    clear();
    if((*select)!=0){    // se tivermos as duas diagonais conseguimos saber o resto
        switch(*select){ // Se tivermos apenas uma diagonal, n conseguimos saber o resto e tratamos como um quadrado
        case 1:           // Nao estou preocupado com as dimensoes sendo zero, pois a limitacao foi intencional e n causara erro
            printf("\nDigite a diagonal conhecida:\n\n");
            scanf("%lf", D1);
            ((*lado)!=0)? ((*D2)=((*lado)*(*lado))-((*D1)/2)*((*D1)/2)):printf("\nNao e possivel calcular a area nem a outra diagonal apenas com uma diagonal\n");
            raizquadrada(D1);
            *area=((*D1)*(*D2))/2;
            *perimetro = 4*(*lado);
            clear();
            break;
        case 2:
            printf("\nDigite a primeira diagonal do losangulo\n");
            scanf("%lf", D1);
            clear();
            printf("\nDigite a segunda diagonal do losangulo\n");
            scanf("%lf", D2);
            clear();
            if((*lado)==0){
                *area = ((*D1)*(*D2))/2; // Definimos a area
                *lado = (((*D1)/2)*((*D1)/2))+(((*D2)/2)*((*D2)/2)); // Com as duas diagonais conseguimos encontrar o lado^2
                raizquadrada(lado); // Aqui tiramos a raiz de lado^2
                *perimetro = (*lado)*4;
            }else{ // Trantando o losangulo como um quadrado, pois faltam informacoes
                *perimetro = (*lado)*4;
                *area = ((*D1)*(*D2))/2;
            }
            clear();
            break;

        }
        printf("\n\nDimensoes do losangulo\n\n");
        printf("Lado: %.2lf\nDiagonal1: %.2lf\nDiagonal2: %.2lf\nArea: %.2lf\nPerimetro: %.2lf\n", *lado,*D1,*D2,*area,*perimetro);
        ((*lado)*(*D1)*(*D2)*(*area)*(*perimetro))==0?printf("\nFaltam informacoes\n"):printf("\nDeu tudo certo\n"); // Se o produto for zero, falta alguma informacoa, se n for, tudo foi preenchido

    }
    free(select);       //Libera tudo
    select=NULL;
    free(lado);
    lado=NULL;
    free(D1);
    D1=NULL;
    free(D2);
    D2=NULL;
    free(area);
    area=NULL;
    free(perimetro);
    perimetro=NULL;
}

void trapezio(){
    double *base,*baseM,*ladoA,*ladoB,*altura,*perimetro,*area; // é uma implementacao preguicosa de uma formula basica de perimetro e area sem espaco pra erro, se faltar a altura, area sera zero
    base      = (double*)calloc(1,sizeof(double));              //
    baseM     = (double*)calloc(1,sizeof(double));
    ladoA     = (double*)calloc(1,sizeof(double));
    ladoB     = (double*)calloc(1,sizeof(double));
    altura    = (double*)calloc(1,sizeof(double));
    perimetro = (double*)calloc(1,sizeof(double));
    area      = (double*)calloc(1,sizeof(double));

    printf("\nQual a base menor?\n");
    scanf("%lf", base);
    clear();
    printf("\n\nQual a base maior?\n");
    scanf("%lf", baseM);
    clear();
    printf("\n\nQual a altura?\n");
    scanf("%lf", altura);
    clear();
    printf("\n\nQual o lado A?\n");
    scanf("%lf", ladoA);
    clear();
    printf("\n\nQual o lado B?\n");
    scanf("%lf",ladoB);
    clear();
    *perimetro = ((*ladoA)+(*ladoB)+(*base)+(*baseM));
    *area = (((*base)/2+(*baseM)/2))*(*altura);


    printf("\nTrapezio\n\nBase maior: %lf\nBase menor: %lf\nLado A: %lf\nLado B: %lf\nAltura: %lf\nPerimetro: %lf\nArea: %lf\n",*baseM,*base,*ladoA,*ladoB,*altura,*perimetro,*area);

    free(base);
    base=NULL;
    free(baseM);
    baseM=NULL;
    free(ladoA);
    ladoA=NULL;
    free(ladoB);
    ladoB=NULL;
    free(altura);
    altura=NULL;
    free(perimetro);
    perimetro=NULL;
    free(area);
    area=NULL;


}
void circulo(){
    int *selecao;
    double *dado,*circunferencia,*raio,*diametro,*area; // Aloca as dimensoes do circulo incializando tudo com 0
    selecao        = (int*)calloc(1,sizeof(int));
    dado           = (double*)calloc(1,sizeof(double));
    circunferencia = (double*)calloc(1,sizeof(double));
    raio           = (double*)calloc(1,sizeof(double));
    diametro       = (double*)calloc(1,sizeof(double));
    area           = (double*)calloc(1,sizeof(double));

    printf("\nQual dado você tem sobre o circulo:\n\n1 - Circunferencia\n2 - Raio\n3 - Diametro\n4 - Area\n\n");
    scanf("%d", selecao); // Usa apenas um dado para determinar os outros
    clear();
    printf("\nQual o dado?\n");
    scanf("%lf",dado);
    clear();

    switch(*selecao){
    case 1: // se o dado for igual a circunferencia
        *circunferencia = *dado;
        *raio = (*circunferencia)/(2*PI);
        *diametro = (*raio)*2;
        *area = (*raio)*(*raio)*PI;
        break;
    case 2: // se o dado for igual ao raio
        *raio = *dado;
        *diametro = (*raio)/2;
        *circunferencia = 2*PI*(*raio);
        *area = (*raio)*(*raio)*PI;
        break;
    case 3: // se o dado for igual ao diametro
        *diametro = *dado;
        *raio = (*diametro)/2;
        *circunferencia = 2*PI*(*raio);
        *area = (*raio)*(*raio)*PI;
        break;
    case 4: // se o dado for igual a area
        *area = *dado;
        *raio = (*area)/PI;
        raizquadrada(raio);
        *diametro = (*raio)/2;
        *circunferencia = 2*PI*(*raio);
        break;
    }

    printf("\nArea do circulo: %f\n"
           "Circunferencia do circulo: %f\n"
           "Diametro do circulo: %f\n"
           "Raio do circulo: %f\n", *area,*circunferencia,*diametro,*raio); // Imprime os dados determinados pelas formulas e em seguida lebera e anula tudo


    free(selecao);
    selecao       =NULL;
    free(dado);
    dado          =NULL;
    free(circunferencia);
    circunferencia=NULL;
    free(raio);
    raio          =NULL;
    free(diametro);
    diametro      =NULL;
    free(area);
    area          =NULL;

}
