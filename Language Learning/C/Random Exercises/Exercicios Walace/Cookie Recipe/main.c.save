#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{

    //programa tem q perguntar, se quer alterar o preço de algum item
    //perguntar quantas gramas de fumo e quanto custaram
    //cada variavel vai ter dois index, no index 0 está a quantidade e no index 1 está o preço

    setlocale(LC_ALL,"portuguese");
    float kunk[2], sugar[2], br_sugar[2], flour[2], butter[2], vanilla[2], eggs[2], ba_soda[2], ba_powder[2], salt[2], chocolate[2];
    float m_kunk[2], m_sugar[2], m_br_sugar[2], m_flour[2], m_butter[2], m_vanilla[2], m_eggs[2], m_ba_soda[2], m_ba_powder[2], m_salt[2], m_chocolate[2];

    m_kunk     [0] =   50;
    m_sugar    [0] = 1000;
    m_br_sugar [0] =  400;
    m_flour    [0] = 1000;
    m_butter   [0] =  200;
    m_vanilla  [0] =   30;
    m_eggs     [0] = 1320;
    m_ba_soda  [0] =   80;
    m_ba_powder[0] =  100;
    m_salt     [0] = 1000;
    m_chocolate[0] =   87;

    m_kunk     [1] =    750;
    m_sugar    [1] =   4.29;
    m_br_sugar [1] =   4.99;
    m_flour    [1] =   6.69;
    m_butter   [1] =  13;
    m_vanilla  [1] =   9.09;
    m_eggs     [1] =  18.99;
    m_ba_soda  [1] =  10.19;
    m_ba_powder[1] =   3.59;
    m_salt     [1] =   2.29;
    m_chocolate[1] =   5.09;

    char altera_prod = '\0';
    int prod = 0;
        printf("Quer alteral algum produto?\ns = sim\nn = nao\n\n");
        scanf(" %c", &altera_prod);

    while(1){

        if(tolower(altera_prod) == 's'){

            while(1){
                altera_prod = 'n';
                printf("Qual?\n  1 - Açúcar\n  2 - Açúcar Mascavo\n  3 - Manteiga\n  4 - Farinha\n  5 - Kunk\n  6 - Essencia de Baunilha\n  7 - Bicarbonato de Sódio\n  8 - Fermento\n  9 - Ovos\n 10 - Sal\n 11 - Chocolate\n");
                scanf("%d", &prod);

                switch(prod){

                    case 1:{
                        printf("Quantas gramas de açúcar a comprar?\n");
                        scanf("%f", &m_sugar[0]);
                        printf("Quanto custa?\n");
                        scanf("%f", &m_sugar[1]);
                        break;
                    }
                    case 2:{
                        printf("Quantas gramas de açúcar mascavo a comprar?\n");
                        scanf("%f", &m_br_sugar[0]);
                        printf("Quanto custa?\n");
                        scanf("%f", &m_br_sugar[1]);
                        break;
                    }
                    case 3:{
                        printf("Quantas gramas de manteiga a comprar?\n");
                        scanf("%f", &m_butter[0]);
                        printf("Quanto custa?\n");
                        scanf("%f", &m_butter[1]);
                        break;
                    }
                    case 4:{
                        printf("Quantas gramas de farinha a comprar?\n");
                        scanf("%f", &m_flour[0]);
                        printf("Quanto custa?\n");
                        scanf("%f", &m_flour[1]);
                        break;
                    }
                    case 5:{
                        printf("Quantas gramas de kunk a comprar?\n");
                        scanf("%f", &m_kunk[0]);
                        printf("Quanto custa?\n");
                        scanf("%f", &m_kunk[1]);
                        break;
                    }
                    case 6:{
                        printf("Quantas gramas de essência de baunilha a comprar?\n");
                        scanf("%f", &m_vanilla[0]);
                        printf("Quanto custa?\n");
                        scanf("%f", &m_vanilla[1]);
                        break;
                    }
                    case 7:{
                        printf("Quantas gramas de bicarbonato se sódio a comprar?\n");
                        scanf("%f", &m_ba_soda[0]);
                        printf("Quanto custa?\n");
                        scanf("%f", &m_ba_soda[1]);
                        break;
                    }
                    case 8:{
                        printf("Quantas gramas de fermento químico a comprar?\n");
                        scanf("%f", &m_ba_powder[0]);
                        printf("Quanto custa?\n");
                        scanf("%f", &m_ba_powder[1]);
                        break;
                    }
                    case 9:{
                        printf("Quantas gramas de ovos a comprar?\n");
                        scanf("%f", &m_eggs[0]);
                        printf("Quanto custa?\n");
                        scanf("%f", &m_eggs[1]);
                        break;
                    }
                    case 10:{
                        printf("Quantas gramas de sal a comprar?\n");
                        scanf("%f", &m_salt[0]);
                        printf("Quanto custa?\n");
                        scanf("%f", &m_salt[1]);
                        break;
                    }
                    case 11:{
                        printf("Quantas gramas de chocolate a comprar?\n");
                        scanf("%f", &m_chocolate[0]);
                        printf("Quanto custa?\n");
                        scanf("%f", &m_chocolate[1]);
                        break;
                    }
                }
                printf("Quer alterar mais algum produto?\ns = sim\nn = nao\n\n");
                scanf(" %c", &altera_prod);
                break;
            }
        }else if(tolower(altera_prod) == 'n'){
            printf("OK!\n");
            break;
        }else{
            printf("Resposta inválida.\n");
            printf("Quer alteral algum produto?\ns = sim\nn = nao\n\n");
            scanf(" %c", &altera_prod);
        }
        printf("\n");
    }

    kunk     [0] =  0.7;
    sugar    [0] =  8;
    br_sugar [0] =  8.8;
    flour    [0] = 14.4;
    butter   [0] = 11.8;
    vanilla  [0] =  0.8;
    eggs     [0] =  4.8;
    ba_soda  [0] =  0.24;
    ba_powder[0] =  0.08;
    salt     [0] =  0.24;
    chocolate[0] = 10;

    float peso_massa, peso_cookie, pr_massa, pr_cookie, mat_prima;
    int num_cookies = 0;

    printf("Quantas gramas de matéria prima?\n");
    scanf("%f", &mat_prima);

    printf("\nmateria prima %f", mat_prima);

    num_cookies = mat_prima / kunk[0];

    printf(" cookies: %d", num_cookies);

    kunk     [0] =  num_cookies * kunk      [0];
    sugar    [0] =  num_cookies * sugar     [0];
    br_sugar [0] =  num_cookies * br_sugar  [0];
    flour    [0] =  num_cookies * flour     [0];
    butter   [0] =  num_cookies * butter    [0];
    vanilla  [0] =  num_cookies * vanilla   [0];
    eggs     [0] =  num_cookies * eggs      [0];
    ba_soda  [0] =  num_cookies * ba_soda   [0];
    ba_powder[0] =  num_cookies * ba_powder [0];
    salt     [0] =  num_cookies * salt      [0];
    chocolate[0] =  num_cookies * chocolate [0];

    kunk     [1]  =  (kunk     [0]  *  m_kunk     [1])  /  m_kunk     [0];
    sugar    [1]  =  (sugar    [0]  *  m_sugar    [1])  /  m_sugar    [0];
    br_sugar [1]  =  (br_sugar [0]  *  m_br_sugar [1])  /  m_br_sugar [0];
    flour    [1]  =  (flour    [0]  *  m_flour    [1])  /  m_flour    [0];
    butter   [1]  =  (butter   [0]  *  m_butter   [1])  /  m_butter   [0];
    vanilla  [1]  =  (vanilla  [0]  *  m_vanilla  [1])  /  m_vanilla  [0];
    eggs     [1]  =  (eggs     [0]  *  m_eggs     [1])  /  m_eggs     [0];
    ba_soda  [1]  =  (ba_soda  [0]  *  m_ba_soda  [1])  /  m_ba_soda  [0];
    ba_powder[1]  =  (ba_powder[0]  *  m_ba_powder[1])  /  m_ba_powder[0];
    salt     [1]  =  (salt     [0]  *  m_salt     [1])  /  m_salt     [0];
    chocolate[1]  =  (chocolate[0]  *  m_chocolate[1])  /  m_chocolate[0];


    peso_massa = sugar[0] + br_sugar[0] + flour[0] + butter[0] + vanilla[0] + eggs[0] + ba_soda[0] + ba_powder[0] + salt[0] + chocolate[0];
    pr_massa   = sugar[1] + br_sugar[1] + flour[1] + butter[1] + vanilla[1] + eggs[1] + ba_soda[1] + ba_powder[1] + salt[1] + chocolate[1];

    peso_cookie = peso_massa / num_cookies;
    pr_cookie   = pr_massa   / num_cookies;


    printf("\n\n\n\n\n\nReceita para fazer %d cookies:\n\n", num_cookies);
    printf(" Manteiga:............%.2fg\n Açúcar:...............%.2fg\n Açúcar Mascavo:.......%.2fg\n Farainha:............%.2fg\n Baunilha:.............%.2fml\n Ovos:.................%.2fg\n Bicarbonato de sódio:..%.2fg\n Fermento químico:......%.2fg\n Sal:...................%.2fg\n Chocolate:...........%.2fg\n\n", butter[0],sugar[0], br_sugar[0], flour[0], vanilla[0], eggs[0],  ba_soda[0],  ba_powder[0], salt[0], chocolate[0]);


    printf("Peso da massa:   %.2fg\nPeso do cookie:   %.2fg\n\n", peso_massa, peso_cookie);

    printf("Preço da massa:  R$%.2f\nPreço do cookie:  R$%.2f\n", pr_massa, pr_cookie);


        return 0;
}
