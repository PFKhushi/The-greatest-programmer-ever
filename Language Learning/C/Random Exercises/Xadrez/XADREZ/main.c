#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <windows.h>//errado Beep(300,500); certo Beep(700,500);


char * board[8][8];
char * board_destin[2];

char * tabuleiro[18][18];


void menu();
void character_creation();
void tabular();
void lettering_b();
void print_tabuleiro();
void reset_board();
void saw();

void pontuar(int jogadas);
char converter_posicao(char v_char);

int check_xeque(int vez);
int check_aliada(int v_board, int h_board, int turn);
int check_aliada_ou_notempty(int v_board, int h_board, int turn);
int check_inimigo(int v_board, int h_board, int turn);
int check_rei_proximo(int v_board_atual, int h_board_atual, int vez);
int check_path(int v_board_atual, int h_board_atual, int v_board_destin, int h_board_destin, int v_step, int h_step);
int check_peca(int v_board, int h_board);
int check_neutralizar_ameaca_and_path(int v_alvo,int h_alvo,int turn);
int check_saida_xeque(int v_alvo,int h_alvo, int turn);
int check_xeque_destino(int v_atual, int h_atual, int v_destin, int h_destin, int turn);
int check_neutralizar_path_ameaca(int v_alvo,int h_alvo,int turn);
int check_psbld_movm(int v_atual, int h_atual,int vez);


int king(int v_board_atual, int h_board_atual, int v_board_destin, int h_board_destin, int turn);
int queen(int v_board_atual, int h_board_atual, int v_board_destin, int h_board_destin, int turn);
int bishop(int v_board_atual, int h_board_atual, int v_board_destin, int h_board_destin, int turn);
int horse(int v_board_atual, int h_board_atual, int v_board_destin, int h_board_destin, int turn);
int tower(int v_board_atual, int h_board_atual, int v_board_destin, int h_board_destin, int turn);
int white_pawn(int v_board_atual, int h_board_atual, int v_board_destin, int h_board_destin, int vez);
int black_pawn(int v_board_atual, int h_board_atual, int v_board_destin, int h_board_destin, int vez);

void check_turn();
void reset_board();


void imprimir_atks(int v, int h, int vez);
char plays[784];
char *b_king = " BK ", *b_queen = " BQ ", *b_tower = " BT ", *b_bishop = " BB ", *b_horse = " BH ", *b_pawn = " BP ";
char *w_king = " WK ", *w_queen = " WQ ", *w_tower = " WT ", *w_bishop = " WB ", *w_horse = " WH ", *w_pawn = " WP ";
char *empty = "    ";

char *barra_v = "|";
char *barra_h = "----";
char *ponto = ".";

int letra;

int xeque_mate = 0;


typedef struct player{
    char nome[50];
    int cor, pontos;
}jogadores;

jogadores jogador[2];

typedef struct jogatina{

    int jogadas, pecas_brancas, pecas_pretas, pecas_jogadas;


}gameplay;

gameplay play;

int main() {


    setlocale(LC_ALL, " ");

    jogador[0].cor = jogador[1].cor = jogador[0].pontos = jogador[1].pontos = 0;

    char replay, mudar, escolha;

    play.jogadas = 0;

    menu();


    character_creation();

    do{
        reset_board(); //bota tabuleiro no estado inicial e aloca membros do tabuleiro nos seus espacos

    /*
        board[7][3] = empty;
        board[7][4] = empty;
        board[3][7] = w_king;
        board[0][0] = empty;
        board[0][7] = empty;
        board[3][0] = b_tower;
        board[4][0] = b_tower;
        board[5][4] = w_queen;*/


        jogada(play.jogadas);

        pontuar(play.jogadas);

        printf("Vocês desejam continuar jogando?s-Sim\nn=Nao\n");
        scanf(" %c", &replay);
        if(tolower(replay)== 's'){
            printf("Vocês querem mudar a cor das peças?\n");
            scanf(" %c", &mudar);
            if(tolower(mudar)=='s'){
                while(1){
                    printf("Qual cor você escolhe, %s?\n\n1-Brancas\n2-Pretas\n", jogador[0].nome);
                    scanf("%d", &escolha);
                    if(escolha == 1){
                        jogador[0].cor = 1;
                        jogador[1].cor = 2;
                        break;
                    }else if(escolha==2){
                        jogador[0].cor = 2;
                        jogador[1].cor = 1;
                        break;
                    }else{
                        printf("Sua resposta não corresponde a nenhuma cor!!\n");
                    }
                }
            }
        }
    }while(tolower(replay)=='s');
    refresh();
    printf("PLACAR:\n\n");
    printf("%s, está com %d pontos!!\n", jogador[0].nome,jogador[0].pontos);
    printf("%s, está com %d pontos!!\n", jogador[1].nome,jogador[1].pontos);

return 0;
}

void imprimir_atks(int v, int h, int vez){//////////////////////////////////////////////////////////////////////////////////////////////DONE//////////////////////////////////
    switch (check_peca(v,h)){
        case 1:{//peaop
            for(int i=0;i<8;i++){
                    printf("\n");
                for(int w=0;w<8;w++){
                    if(black_pawn(v,h,i,w,vez)==1){
                        printf("%d", black_pawn(v,h,i,w,vez));
                     }else{
                         printf("%d", black_pawn(v,h,i,w,vez));
                    }
                }
            }
            break;
        }
        case 2:{//peaob
            for(int i=0;i<8;i++){
                    printf("\n");
                for(int w=0;w<8;w++){
                   if(white_pawn(v,h,i,w,vez)==1){
                        printf("%d", white_pawn(v,h,i,w,vez));
                     }else{
                         printf("%d", white_pawn(v,h,i,w,vez));
                    }
                }
            }
            break;
        }
        case 3:{//rei
            for(int i=0;i<8;i++){
                    printf("\n");
                for(int w=0;w<8;w++){
                    if(king(v,h,i,w,vez)==1){
                         printf("%d", king(v,h,i,w,vez));
                     }else{
                         printf("%d", king(v,h,i,w,vez));
                    }
                }
            }
            break;
        }
        case 4:{//rainha
            for(int i=0;i<8;i++){
                    printf("\n");
                for(int w=0;w<8;w++){
                    if(queen(v,h,i,w,vez)==1){
                        printf("%d", queen(v,h,i,w,vez));
                     }else{
                         printf("%d", queen(v,h,i,w,vez));
                    }
                }
            }
            break;
        }
        case 5:{//bispo
            for(int i=0;i<8;i++){
                    printf("\n");
                for(int w=0;w<8;w++){
                    if(bishop(v,h,i,w,vez)==1){
                        printf("%d", bishop(v,h,i,w,vez));
                     }else{
                         printf("%d", bishop(v,h,i,w,vez));
                    }
                }
            }
            break;
        }
        case 6:{//cavalo
            for(int i=0;i<8;i++){
                    printf("\n");
                for(int w=0;w<8;w++){
                    if(horse(v,h,i,w,vez)==1){
                        printf("%d", horse(v,h,i,w,vez));
                     }else{
                         printf("%d", horse(v,h,i,w,vez));
                    }
                }
            }
            break;
        }
        case 7:{//torre
            for(int i=0;i<8;i++){
                    printf("\n");
                for(int w=0;w<8;w++){
                    if(tower(v,h,i,w,vez)==1){
                         printf("%d", tower(v,h,i,w,vez));
                     }else{
                         printf("%d", tower(v,h,i,w,vez));
                    }
                }
            }
            break;

        }case 0:{
            break;
        }
    }
}
void jogada(int vez){///////////////////////////////////////////////////////////////////////////////////////////////////////////////////DONE//////////////////////////////////



    char letra_char, test;
    int xeque = 0,ok = 0;
    int v_board_atual,h_board_atual,v_board_destin,h_board_destin;
    do{
        refresh();
        if (vez%2==0){
            if(jogador[0].cor==1){
                printf("\n%s, sua vez!\n", jogador[0].nome);
            }else{
                printf("\n%s, sua vez!\n", jogador[1].nome);
            }
        }else{
            if(jogador[0].cor==2){
                printf("\n%s, sua vez!\n", jogador[0].nome);
            }else{
                printf("\n%s, sua vez!\n", jogador[1].nome);
            }
        }
        do{
            if(check_xeque(vez)==1){
                Beep(300,500);
                Beep(270,500);
                printf("Você está em xeque!\n");
                Sleep(2);
            }else if(check_xeque(vez)==2){
                xeque_mate = 1;
                printf("xeque mate!!\n");

                goto Mate;

            }
            do{
                xeque = 0;

                do{
                    printf("\nDigite a letra correspondente a posição da peça a ser movida:\n");
                    scanf(" %c", &letra_char);
                    printf("\nDigite o número correspondente a posição da peça a ser movida:\n");
                    scanf("%d", &h_board_atual);
                    test = converter_posicao(letra_char);
                    v_board_atual = letra;//a funcao converter aloca o numero da letra correspondente numa variavel global chamada letra
                    h_board_atual--;
                    if(test == 'n'){
                        Beep(300,500);
                        printf("Letra não corresponde a nenhuma posição!\n");
                        ok = 0;
                        Sleep(1);
                    }else if(h_board_atual<0 || h_board_atual>7){
                        Beep(300,500);
                        printf("Número não corresponde a nenhuma posição!\n");
                        ok = 0;
                        Sleep(1);
                    }else{

                        ok = check_aliada_ou_notempty(v_board_atual,h_board_atual,vez);

                        if(ok == 0){
                            Beep(300,500);
                            if(board[v_board_atual][h_board_atual]==empty){
                                printf("Você não pode mover um espaço vazio!\n");
                                ok = 0;
                            }else{
                                printf("Essa peça não é sua!");
                            }

                            Sleep(1);
                        }else{
                            ok = check_psbld_movm(v_board_atual,h_board_atual,vez);
                            if(ok == 1){
                                Beep(700,500);
                                printf("Peça escolhida. Viva com suas escolhas!\n");


                            }else{
                                Beep(300,500);
                                printf("Essa peça não consegue se mover!\n");
                                ok = 0;
                            }
                            Sleep(1);
                        }
                    }
                }while(ok == 0);
                refresh();


                do{ ok = 0;
                    printf("\nDigite a letra correspondente a posição de destino:\n");
                    scanf(" %c", &letra_char);
                    printf("\nDigite o número correspondente a posição de destino:\n");
                    scanf("%d", &h_board_destin);
                    test = converter_posicao(letra_char);
                    v_board_destin = letra;//a funcao converter aloca o numero da letra correspondente numa variavel global chamada letra
                    h_board_destin--;
                    if(test == 'n'){
                        Beep(300,500);
                        printf("Letra não corresponde a nenhuma posição!\n");
                        ok = 0;
                        Sleep(1);
                    }else if(h_board_destin<0 || h_board_destin>7){
                        Beep(300,500);
                        printf("Número não corresponde a nenhuma posição!\n");
                        ok = 0;
                        Sleep(1);
                    }else{

                        ok = check_inimigo(v_board_destin,h_board_destin,vez);
                        if(ok == 0){
                            Beep(300,500);
                            printf("Essa casa não é uma peça inimiga, nem espaço vazio!\n");
                            Sleep(1);
                        }else{
                            switch(check_peca(v_board_atual,h_board_atual)){

                                case 1:{
                                    if(black_pawn(v_board_atual,h_board_atual,v_board_destin,h_board_destin,vez)==1){


                                        if(ok == 1 && check_xeque_destino(v_board_atual,h_board_atual,v_board_destin,h_board_destin,vez)==0){
                                            Beep(700,500);
                                            printf("Peça escolhida. Viva com suas escolhas!\n");
                                            Sleep(2);
                                            break;
                                        }else{
                                            ok = 1;
                                            xeque = 1;
                                            Beep(300,500);
                                            printf("Mover essa peça, deixará seu rei em xeque!\nEscolha outra!\n");
                                            Sleep(1);
                                        }
                                        break;

                                    }else{
                                        ok = 0;
                                        Beep(300,500);
                                        printf("Sua peça não chega lá!\n");
                                    }
                                    break;
                                }case 2:{
                                    if(white_pawn(v_board_atual,h_board_atual,v_board_destin,h_board_destin,vez)==1){


                                        if(ok == 1 && check_xeque_destino(v_board_atual,h_board_atual,v_board_destin,h_board_destin,vez)==0){
                                            Beep(700,500);
                                            printf("Peça escolhida. Viva com suas escolhas!\n");
                                            Sleep(2);
                                            break;
                                        }else{
                                            ok = 1;
                                            xeque = 1;
                                            Beep(300,500);
                                            printf("Mover essa peça, deixará seu rei em xeque!\nEscolha outra!\n");
                                            Sleep(1);
                                        }
                                        break;

                                    }else{
                                        ok = 0;
                                        Beep(300,500);
                                        printf("Sua peça não chega lá!\n");
                                        Sleep(1);
                                    }
                                    break;

                                }case 3:{
                                    if(king(v_board_atual,h_board_atual,v_board_destin,h_board_destin,vez)==1){
                                        if(ok == 1 && check_xeque_destino(v_board_atual,h_board_atual,v_board_destin,h_board_destin,vez)==0){
                                            Beep(700,500);
                                            printf("Peça escolhida. Viva com suas escolhas!\n");
                                            Sleep(2);
                                            break;
                                        }else{
                                            ok = 1;
                                            xeque = 1;
                                            Beep(300,500);
                                            printf("Mover essa peça, deixará seu rei em xeque!\nEscolha outra!\n");
                                            Sleep(1);
                                        }
                                        break;
                                    }else{
                                        ok = 0;
                                        Beep(300,500);
                                        printf("Sua peça não chega lá!\n");
                                        Sleep(1);
                                    }
                                    break;
                                }case 4:{
                                    if(queen(v_board_atual,h_board_atual,v_board_destin,h_board_destin,vez)==1){
                                        if(ok == 1 && check_xeque_destino(v_board_atual,h_board_atual,v_board_destin,h_board_destin,vez)==0){
                                            Beep(700,500);
                                            printf("Peça escolhida. Viva com suas escolhas!\n");
                                            Sleep(2);
                                            break;
                                        }else{
                                            ok = 1;
                                            xeque = 1;
                                            Beep(300,500);
                                            printf("Mover essa peça, deixará seu rei em xeque!\nEscolha outra!\n");
                                            Sleep(1);
                                        }
                                        break;
                                    }else{
                                        ok = 0;
                                        Beep(300,500);
                                        printf("Sua peça não chega lá!\n");
                                        Sleep(1);
                                    }
                                    break;
                                }case 5:{
                                    if(bishop(v_board_atual,h_board_atual,v_board_destin,h_board_destin,vez)==1){
                                        if(ok == 1 && check_xeque_destino(v_board_atual,h_board_atual,v_board_destin,h_board_destin,vez)==0){
                                            Beep(700,500);
                                            printf("Peça escolhida. Viva com suas escolhas!\n");
                                            Sleep(2);
                                            break;
                                        }else{
                                            ok = 1;
                                            xeque = 1;
                                            Beep(300,500);
                                            printf("Mover essa peça, deixará seu rei em xeque!\nEscolha outra!\n");
                                            Sleep(2);
                                        }
                                        break;
                                    }else{
                                        ok = 0;
                                        Beep(300,500);
                                        printf("Sua peça não chega lá!\n");
                                        Sleep(1);
                                    }
                                    break;
                                }case 6:{
                                    if(horse(v_board_atual,h_board_atual,v_board_destin,h_board_destin,vez)==1){
                                        if(ok == 1 && check_xeque_destino(v_board_atual,h_board_atual,v_board_destin,h_board_destin,vez)==0){
                                            Beep(700,500);
                                            printf("Peça escolhida. Viva com suas escolhas!\n");
                                            Sleep(2);
                                            break;
                                        }else{
                                            ok = 1;
                                            xeque = 1;
                                            Beep(300,500);
                                            printf("Mover essa peça, deixará seu rei em xeque!\nEscolha outra!\n");
                                            Sleep(1);
                                        }
                                        break;
                                    }else{
                                        ok = 0;
                                        Beep(300,500);
                                        printf("Sua peça não chega lá!\n");
                                        Sleep(1);
                                    }
                                    break;
                                }case 7:{
                                    if(tower(v_board_atual,h_board_atual,v_board_destin,h_board_destin,vez)==1){
                                        if(ok == 1 && check_xeque_destino(v_board_atual,h_board_atual,v_board_destin,h_board_destin,vez)==0){
                                            Beep(700,500);
                                            printf("Peça escolhida. Viva com suas escolhas!\n");
                                            Sleep(2);
                                            break;
                                        }else{
                                            ok = 1;
                                            xeque = 1;
                                            Beep(300,500);
                                            printf("Mover essa peça, deixará seu rei em xeque!\nEscolha outra!\n");
                                            Sleep(1);
                                        }
                                        break;
                                    }else{
                                        ok = 0;
                                        Beep(300,500);
                                        printf("Sua peça não chega lá!\n");
                                        Sleep(1);
                                    }
                                    break;
                                }
                            }
                        }
                    }
                }while(ok == 0);
            }while(xeque == 1);
                board[v_board_destin][h_board_destin] = board[v_board_atual][h_board_atual];
                board[v_board_atual][h_board_atual] = empty;
        }while (check_xeque(vez)==1);
        Beep(650,500);
        Beep(700,500);
        vez++;
        play.jogadas = vez;
        Mate:;
    }while(xeque_mate==0);
}
int refresh(int turn){//////////////////////////////////////////////////////////////////////////////////////////////////////////////////DONE//////////////////////////////////

    system("cls");
    tabular();
    print_tabuleiro();
return 0;
}
void menu(){////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////DONE//////////////////////////////////
    char nops[34];
    printf("        ██╗░░██╗░█████╗░██████╗░██████╗░███████╗███████╗\n"
           "        ╚██╗██╔╝██╔══██╗██╔══██╗██╔══██╗██╔════╝╚════██║\n"
           "        ░╚███╔╝░███████║██║░░██║██████╔╝█████╗░░░░███╔═╝\n"
           "        ░██╔██╗░██╔══██║██║░░██║██╔══██╗██╔══╝░░██╔══╝░░\n"
           "        ██╔╝╚██╗██║░░██║██████╔╝██║░░██║███████╗███████╗\n"
           "        ╚═╝░░╚═╝╚═╝░░╚═╝╚═════╝░╚═╝░░╚═╝╚══════╝╚══════╝\n\n\n\n");

    printf("          ▄▀█ █▀█ █▀▀ █▀█ ▀█▀ █▀▀   █▀▀ █▄░█ ▀█▀ █▀▀ █▀█\n"
           "          █▀█ █▀▀ ██▄ █▀▄ ░█░ ██▄   ██▄ █░▀█ ░█░ ██▄ █▀▄\n");
    saw();
    gets(nops);
    system("cls");
}
void character_creation(){//////////////////////////////////////////////////////////////////////////////////////////////////////////////DONE//////////////////////////////////
    for(int i=0;i<2;i++){
        printf("Insira o nome do Jogador-%d: ", i + 1);
        scanf(" %s", jogador[i].nome);
        system("cls");
        Beep(700,500);
    }
    while(1){

        printf("%s!\nDigite o numero da cor que você quer jogar?\nBrancas - 1\nPretas  - 2\n", jogador[0].nome);
        scanf("%d", &jogador[0].cor);
        if(jogador[0].cor==1){
            jogador[1].cor=2;
            Beep(700,500);
            break;
        }else if(jogador[0].cor==2){
            jogador[1].cor=1;
            Beep(700,500);
            break;
        }else{
            Beep(300,500);

        }
    }
   system("cls");
}
void tabular(){/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////DONE//////////////////////////////////
    int casas_v, casas_h, b_casas_v, b_casas_h, h;
    for(casas_v = 0; casas_v<=18;casas_v++){
        for(casas_h=0;casas_h<=18;casas_h++){
            tabuleiro[casas_v][casas_h] = ponto;
            h = casas_h + 1;
            tabuleiro[casas_v][h] = barra_h;
            casas_h++;
        }
        casas_v++;
    }
    for(casas_v=1;casas_v<17;casas_v++){
        for(casas_h=0;casas_h<17;casas_h++){
            tabuleiro[casas_v][casas_h] = barra_v;
            casas_h++;
        }
        casas_v++;
    }
    for(b_casas_v=0;b_casas_v<=8;b_casas_v++){

        for(b_casas_h=0;b_casas_h<8;b_casas_h++){
            int tab_b_v, tab_b_h;
            tab_b_v = b_casas_v * 2 + 1;
            tab_b_h = b_casas_h * 2 + 1;
            tabuleiro[tab_b_v][tab_b_h] = board[b_casas_v][b_casas_h];
        }
    }
}
void lettering_b(int num_lett){/////////////////////////////////////////////////////////////////////////////////////////////////////////DONE//////////////////////////////////
    int h;
        if (num_lett%2==1) {
            h = num_lett;
            int letras_brd = (h / 2 + 1);
            switch(letras_brd){
                case 1:
                    printf(" A ");
                    break;
                case 2:
                    printf(" B ");
                    break;
                case 3:
                    printf(" C ");
                    break;
                case 4:
                    printf(" D ");
                    break;
                case 5:
                    printf(" E ");
                    break;
                case 6:
                    printf(" F ");
                    break;
                case 7:
                    printf(" G ");
                    break;
                case 8:
                    printf(" H ");
                    break;
            }
        }else{
            printf("   ");
        }
}
void print_tabuleiro(){/////////////////////////////////////////////////////////////////////////////////////////////////////////////////DONE//////////////////////////////////
    int v, h;
    printf("\n     01   02   03   04   05   06   07   08  \n");
    for(v=0;v<17;v++){
        lettering_b(v);
        for(h=0;h<17;h++){
            printf("%s", tabuleiro[v][h]);
        }
        printf("\n");
    }
}
void reset_board(){/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////DONE//////////////////////////////////
    board[0][0] = b_tower;
    board[0][1] = b_horse;
    board[0][2] = b_bishop;
    board[0][3] = b_queen;
    board[0][4] = b_king;
    board[0][5] = b_bishop;
    board[0][6] = b_horse;
    board[0][7] = b_tower;
    for(int i=0;i<8;i++){
        board[1][i] = b_pawn;
    }
    for(int i=2;i<6;i++){
        for(int y=0;y<8;y++){
            board[i][y] = empty;
        }
    }
    for(int i=0;i<8;i++){
        board[6][i] = w_pawn;
    }
    board[7][0] = w_tower;
    board[7][1] = w_horse;
    board[7][2] = w_bishop;
    board[7][3] = w_king;
    board[7][4] = w_queen;
    board[7][5] = w_bishop;
    board[7][6] = w_horse;
    board[7][7] = w_tower;
    tabular();
}
void saw(){/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////DONE//////////////////////////////////
    Beep(293, 200);//re
    Beep(329, 200);//mi
    Beep(349, 500);//fa
    Sleep(1);
    Beep(293, 200);//re
    Beep(329, 200);//mi
    Beep(349, 500);//fa
    Beep(329, 200);//mi
    Beep(293, 200);//re
    Beep(329, 200);//mi
    Beep(349, 200);//fa
    Beep(392, 500);//sol
    Beep(0,50);
    Beep(293, 200);//re
    Beep(329, 200);//mi
    Beep(349, 500);//fa
    Sleep(1);
    Beep(293, 200);//re
    Beep(329, 200);//mi
    Beep(349, 500);//fa
    Beep(329, 200);//mi
    Beep(293, 200);//re
    Beep(329, 200);//mi
    Beep(349, 200);//fa
    Beep(392, 500);//sol
    Beep(0,50);
}
void pontuar(int jogadas){//////////////////////////////////////////////////////////////////////////////////////////////////////////////DONE//////////////////////////////////
    /*
    ao completar um movimento o numero de jogadas é sofre um acrescimo de 1
    se o jogo terminar em check, jogadas sofre um decrescimo de 1
    se o jogo terminar com um numero de jogadas par*/
    if (jogadas%2==0){
        if(jogador[0].cor==1){
            jogador[1].pontos++;
            printf("Parabéns, %s. Você ganhou!!!!", jogador[1].nome);
        }else{
            jogador[0].pontos++;
            printf("Parabéns, %s. Você ganhou!!!!", jogador[0].nome);
        }
    }else{
        if(jogador[0].cor==2){
            jogador[1].pontos++;
            printf("Parabéns, %s. Você ganhou!!!!", jogador[1].nome);
        }else{
            jogador[0].pontos++;
            printf("Parabéns, %s. Você ganhou!!!!", jogador[1].nome);
        }
    }
}
char converter_posicao(char v_char){////////////////////////////////////////////////////////////////////////////////////////////////////DONE//////////////////////////////////
    //recebe letre corresponednte a vertival e troca pelo vetor correspondente
    char ok;
    switch (tolower(v_char)){
        case 'a':{
            letra = 0;
            ok = 's';
            break;
        }
        case 'b':{
            letra= 1;
            ok = 's';
            break;
        }
        case 'c':{
            letra = 2;
            ok = 's';
            break;
        }
        case 'd':{
            letra = 3;
            ok = 's';
            break;
        }
        case 'e':{
            letra = 4;
            ok = 's';
            break;
        }
        case 'f':{
            letra = 5;
            ok = 's';
            break;
        }
        case 'g':{
            letra = 6;
            ok = 's';
            break;
        }
        case 'h':{
            letra = 7;
            ok = 's';
            break;
        }
        default :{
            ok = 'n';
        }
    }
    return ok;
}

int check_aliada(int v_board, int h_board, int turn){///////////////////////////////////////////////////////////////////////////////////DONE//////////////////////////////////
    int ok = 0;
        if(turn%2==0){
            if(board[v_board][h_board]==b_king || board[v_board][h_board]==b_queen || board[v_board][h_board]==b_bishop || board[v_board][h_board]==b_horse || board[v_board][h_board]==b_tower || board[v_board][h_board]==b_pawn){
                ok = 0;
            }else{
                ok = 1;
            }
        }else{
            if(board[v_board][h_board]==b_king || board[v_board][h_board]==b_queen || board[v_board][h_board]==b_bishop || board[v_board][h_board]==b_horse || board[v_board][h_board]==b_tower || board[v_board][h_board]==b_pawn){
                ok = 1;
            }else{
                ok = 0;
            }
        }
return ok;
}
int check_aliada_ou_notempty(int v_board, int h_board, int turn){///////////////////////////////////////////////////////////////////////DONE//////////////////////////////////
    int ok = 0;
    /*recebe a posicao(y,x) e o numero de jogadas
      verifica se é empty
      verifica se é par ou impar
      se for par, peca branca ok = 1*/
    if(board[v_board][h_board]==empty){
        ok = 0;
    }else{
        if(turn%2==0){
            if(board[v_board][h_board]==b_king || board[v_board][h_board]==b_queen || board[v_board][h_board]==b_bishop || board[v_board][h_board]==b_horse || board[v_board][h_board]==b_tower || board[v_board][h_board]==b_pawn){
                ok = 0;
            }else{
                ok = 1;
            }
        }else{
            if(board[v_board][h_board]==b_king || board[v_board][h_board]==b_queen || board[v_board][h_board]==b_bishop || board[v_board][h_board]==b_horse || board[v_board][h_board]==b_tower || board[v_board][h_board]==b_pawn){
                ok = 1;
            }else{
                ok = 0;
            }
        }
    }
return ok;
}
int check_inimigo(int v_board, int h_board, int turn){//////////////////////////////////////////////////////////////////////////////////DONE//////////////////////////////////
    int ok = 0;
    /*recebe a posicao(y,x) e o numero de jogadas
      verifica se é par ou impar
      se for par, peca branca ok = 1*/
    if(board[v_board][h_board] != empty){
        if(turn%2==0){
            if(board[v_board][h_board]==b_queen || board[v_board][h_board]==b_bishop || board[v_board][h_board]==b_horse || board[v_board][h_board]==b_tower || board[v_board][h_board]==b_pawn){
                ok = 1;
            }else{
                ok = 0;
            }
        }else{
            if(board[v_board][h_board]==b_queen || board[v_board][h_board]==b_bishop || board[v_board][h_board]==b_horse || board[v_board][h_board]==b_tower || board[v_board][h_board]==b_pawn){
                ok = 0;
            }else{
                ok = 1;
            }
        }
    }else{
        ok = 1;
    }
    //if ok iqual 1, é inimigo
return ok;
}
int check_neutralizar_ameaca_and_path(int v_alvo,int h_alvo,int turn){//////////////////////////////////////////////////////////////////DONE//////////////////////////////////
    int ok = 0;
    for(int v=0;v<8;v++){
        for(int h=0;h<8;h++){
            if(turn%2==0){
                switch(check_peca(v,h)){
                    //1-PeaoP/2-PeaoB/3-Rei/4-Rainha/5-Bispo/6-Cavalo/7-Torre
                    case 2:{
                        if(white_pawn(v,h,v_alvo,h_alvo,turn) == 1){
                            ok = 1;
                            goto Done;
                        }else if(check_saida_xeque(v_alvo,h_alvo,turn)==1){
                            ok = 1;
                            goto Done;
                        }else{
                            ok = 0;
                        }
                    }
                    case 3:{
                        if(king(v,h,v_alvo,h_alvo,turn) == 1){
                            ok = 1;
                            goto Done;
                        }else if(check_saida_xeque(v_alvo,h_alvo,turn)==1){
                            ok = 1;
                            goto Done;
                        }else{
                            ok = 0;
                            break;
                        }
                    }
                    case 4:{
                        if(queen(v,h,v_alvo,h_alvo,turn) == 1){
                            ok = 1;
                            goto Done;
                        }else if(check_saida_xeque(v_alvo,h_alvo,turn)==1){
                            ok = 1;
                            goto Done;
                        }else{
                            ok = 0;
                            break;
                        }
                    }
                    case 5:{
                        if(bishop(v,h,v_alvo,h_alvo,turn) == 1){
                            ok = 1;
                            goto Done;
                        }else if(check_saida_xeque(v_alvo,h_alvo,turn)==1){
                            ok = 1;
                            goto Done;
                        }else{
                            ok = 0;
                            break;
                        }
                    }
                    case 6:{
                        if(horse(v,h,v_alvo,h_alvo,turn) == 1){
                            ok = 1;
                            goto Done;
                        }else{
                            ok = 0;
                            break;
                        }
                    }
                    case 7:{
                        if(tower(v,h,v_alvo,h_alvo,turn) == 1){
                            ok = 1;
                            goto Done;
                        }else if(check_saida_xeque(v_alvo,h_alvo,turn)==1){
                            ok = 1;
                            goto Done;
                        }else{
                            ok = 0;
                            break;
                        }
                    }
                }
            }else{
                switch(check_peca(v,h)){
                    case 1:{
                        if(black_pawn(v,h,v_alvo,h_alvo,turn) == 1){
                            ok = 1;
                            goto Done;
                        }else if(check_saida_xeque(v_alvo,h_alvo,turn)==1){
                            ok = 1;
                            goto Done;
                        }else{
                            ok = 0;
                            break;
                        }
                    }
                    case 3:{
                        if(king(v,h,v_alvo,h_alvo,turn) == 1){
                            ok = 1;
                            goto Done;
                        }else if(check_saida_xeque(v_alvo,h_alvo,turn)==1){
                            ok = 1;
                            goto Done;
                        }else{
                            ok = 0;
                            break;
                        }
                    }
                    case 4:{
                        if(queen(v,h,v_alvo,h_alvo,turn) == 1){
                            ok = 1;
                            goto Done;
                        }else if(check_saida_xeque(v_alvo,h_alvo,turn)==1){
                            ok = 1;
                            goto Done;
                        }else{
                            ok = 0;
                            break;
                        }
                    }
                    case 5:{
                        if(bishop(v,h,v_alvo,h_alvo,turn) == 1){
                            ok = 1;
                            goto Done;
                        }else if(check_saida_xeque(v_alvo,h_alvo,turn)==1){
                            ok = 1;
                            goto Done;
                        }else{
                            ok = 0;
                            break;
                        }
                    }
                    case 6:{
                        if(horse(v,h,v_alvo,h_alvo,turn) == 1){
                            ok = 1;
                            goto Done;
                        }else if(check_saida_xeque(v_alvo,h_alvo,turn)==1){
                            ok = 1;
                            goto Done;
                        }else{
                            ok = 0;
                            break;
                        }
                    }
                    case 7:{
                        if(tower(v,h,v_alvo,h_alvo,turn) == 1){
                            ok = 1;
                            goto Done;
                        }else if(check_saida_xeque(v_alvo,h_alvo,turn)==1){
                            ok = 1;
                            goto Done;
                        }else{
                            ok = 0;
                            break;
                        }
                    }
                }
            }
        }
    }
Done:;

return ok;
}
int check_neutralizar_path_ameaca(int v_alvo,int h_alvo,int turn){//////////////////////////////////////////////////////////////////////DONE//////////////////////////////////
    int ok = 0;
    for(int v=0;v<8;v++){
        for(int h=0;h<8;h++){//Percorre tabuleiro
            if(turn%2==0){//Se rei branco tiver em xeque
                switch(check_peca(v,h)){
                    //1-PeaoP/2-PeaoB/3-Rei/4-Rainha/5-Bispo/6-Cavalo/7-Torre
                    case 1:{
                        ok = 0;
                        break;
                    }
                    case 2:{
                        ok = white_pawn(v,h,v_alvo,h_alvo,turn);
                        if(ok == 1 && check_xeque_destino(v,h,v_alvo,h_alvo,turn)==0){
                            goto Done;
                        }else{
                            ok = 0;
                            break;
                        }
                    }
                    case 3:{
                        ok = 0;
                        break;
                    }
                    case 4:{
                        ok = queen(v,h,v_alvo,h_alvo,turn);
                        if(ok == 1 && check_xeque_destino(v,h,v_alvo,h_alvo,turn)==0){
                            goto Done;
                        }else{
                            ok = 0;
                            break;
                        }
                    }
                    case 5:{
                        ok = bishop(v,h,v_alvo,h_alvo,turn);
                        if(ok == 1 && check_xeque_destino(v,h,v_alvo,h_alvo,turn)==0){
                            goto Done;
                        }else{
                            ok = 0;
                            break;
                        }
                    }
                    case 6:{
                        ok = horse(v,h,v_alvo,h_alvo,turn);
                        if(ok == 1 && check_xeque_destino(v,h,v_alvo,h_alvo,turn)==0){
                            goto Done;
                        }else{
                            ok = 0;
                            break;
                        }
                    }
                    case 7:{
                        ok = tower(v,h,v_alvo,h_alvo,turn);
                        if(ok == 1 && check_xeque_destino(v,h,v_alvo,h_alvo,turn)==0){
                            goto Done;
                        }else{
                            ok = 0;
                            break;
                        }
                    }
                    default:{
                        ok = 0;
                    }

                }
            }else{
                switch(check_peca(v,h)){
                    case 1:{
                        ok = black_pawn(v,h,v_alvo,h_alvo,turn);
                        if(ok == 1 && check_xeque_destino(v,h,v_alvo,h_alvo,turn)==0){
                            goto Done;
                        }else{
                            ok = 0;
                            break;
                        }
                    }
                    case 2:{
                        ok = 0;
                        break;
                    }
                    case 3:{
                        ok = 0;
                        break;
                    }
                    case 4:{
                        ok = queen(v,h,v_alvo,h_alvo,turn);
                        if(ok == 1 && check_xeque_destino(v,h,v_alvo,h_alvo,turn)==0){
                            goto Done;
                        }else{
                            ok = 0;
                            break;
                        }
                    }
                    case 5:{
                        ok = bishop(v,h,v_alvo,h_alvo,turn);
                        if(ok == 1 && check_xeque_destino(v,h,v_alvo,h_alvo,turn)==0){
                            goto Done;
                        }else{
                            ok = 0;
                            break;
                        }
                    }
                    case 6:{
                        ok = horse(v,h,v_alvo,h_alvo,turn);
                        if(ok == 1 && check_xeque_destino(v,h,v_alvo,h_alvo,turn)==0){
                            goto Done;
                        }else{
                            ok = 0;
                            break;
                        }
                    }
                    case 7:{
                        ok = tower(v,h,v_alvo,h_alvo,turn);
                        if(ok == 1 && check_xeque_destino(v,h,v_alvo,h_alvo,turn)==0){
                            goto Done;
                        }else{
                            ok = 0;
                            break;
                        }
                    }default:{
                        ok = 0;
                    }
                }
            }
        }
    }
Done:;
return ok;
}
int check_path(int v_board_atual, int h_board_atual, int v_board_destin, int h_board_destin, int v_step, int h_step){///////////////////DONE//////////////////////////////////
    int ok;
    if(h_step==0){
        v_board_atual+=v_step;
        for(int i=v_board_atual;i!=v_board_destin;i+=v_step){
            if(board[i][h_board_atual]!=empty){
                ok = 0;
                break;
            }else{
                ok = 1;
            }
        }
    }else if(v_step==0){
        h_board_atual+=h_step;
        for(int i=h_board_atual;i!=h_board_destin;i+=h_step){
            if(board[v_board_atual][i]!=empty){
                ok = 0;
                break;
            }else{
                ok = 1;
            }
        }
    }else if(abs(v_step)==abs(h_step)){
        v_board_atual+=v_step;
        h_board_atual+=h_step;
        for(int i=h_board_atual;i!=h_board_destin;i+=h_step){
            if(board[v_board_atual][h_board_atual]!=empty){
                ok = 0;
                break;
            }else{
                ok = 1;
                v_board_atual+=v_step;
                h_board_atual+=h_step;
            }
        }
    }else{
        ok = 0;
    }
return ok;
}
int check_peca(int v_board, int h_board){// 1-PeaoP/2-PeaoB/3-Rei/4-Rainha/5-Bispo/6-Cavalo/7-Torre/0-!peca/////////////////////////////DONE//////////////////////////////////
    int ok = 0;
    if(board[v_board][h_board]==b_pawn){
        ok = 1;
    }else if(board[v_board][h_board]==w_pawn){
        ok = 2;
    }else if(board[v_board][h_board]==b_king || board[v_board][h_board]==w_king){
        ok = 3;
    }else if(board[v_board][h_board]==b_queen || board[v_board][h_board]==w_queen){
        ok = 4;
    }else if(board[v_board][h_board]==b_bishop || board[v_board][h_board]==w_bishop){
        ok = 5;
    }else if(board[v_board][h_board]==b_horse || board[v_board][h_board]==w_horse){
        ok = 6;
    }else if(board[v_board][h_board]==b_tower || board[v_board][h_board]==w_tower){
        ok = 7;
    }else{
        ok = 0;
    }
return ok;
}
int check_psbld_movm(int v_atual, int h_atual,int vez){/////////////////////////////////////////////////////////////////////////////////DONE//////////////////////////////////
    int atk = 0;
    int ok = 0;
    switch (check_peca(v_atual,h_atual)){
        case 1:{//peaop
            for(int v_destin=0;v_destin<8;v_destin++){
                for(int h_destin=0;h_destin<8;h_destin++){
                    if(black_pawn(v_atual,h_atual,v_destin,h_destin,vez)==1 && check_xeque_destino(v_atual,h_atual,v_destin,h_destin,vez) == 0){

                        ok = 1;
                        goto Done;
                    }
                }
            }
            break;
        }
        case 2:{//peaob
            for(int v_destin=0;v_destin<8;v_destin++){
                for(int h_destin=0;h_destin<8;h_destin++){
                   if(white_pawn(v_atual,h_atual,v_destin,h_destin,vez)==1 && check_xeque_destino(v_atual,h_atual,v_destin,h_destin,vez) == 0){
                        ok = 1;
                        goto Done;
                    }
                }
            }
            break;
        }
        case 3:{//rei
            for(int v_destin=0;v_destin<8;v_destin++){
                for(int h_destin=0;h_destin<8;h_destin++){
                    if(king(v_atual,h_atual,v_destin,h_destin,vez)==1 && check_xeque_destino(v_atual,h_atual,v_destin,h_destin,vez) == 0){
                        ok = 1;
                        goto Done;
                    }
                }
            }
            break;
        }
        case 4:{//rainha
            for(int v_destin=0;v_destin<8;v_destin++){
                for(int h_destin=0;h_destin<8;h_destin++){
                    if(queen(v_atual,h_atual,v_destin,h_destin,vez)==1 && check_xeque_destino(v_atual,h_atual,v_destin,h_destin,vez) == 0){
                        ok = 1;
                        goto Done;
                    }
                }
            }
            break;
        }
        case 5:{//bispo
            for(int v_destin=0;v_destin<8;v_destin++){
                for(int h_destin=0;h_destin<8;h_destin++){
                    if(bishop(v_atual,h_atual,v_destin,h_destin,vez)==1 && check_xeque_destino(v_atual,h_atual,v_destin,h_destin,vez) == 0){
                        ok = 1;
                        goto Done;
                    }
                }
            }
            break;
        }
        case 6:{//cavalo
            for(int v_destin=0;v_destin<8;v_destin++){
                for(int h_destin=0;h_destin<8;h_destin++){
                    if(horse(v_atual,h_atual,v_destin,h_destin,vez)==1 && check_xeque_destino(v_atual,h_atual,v_destin,h_destin,vez) == 0){
                        ok = 1;
                        goto Done;
                    }
                }
            }
            break;
        }
        case 7:{//torre
            for(int v_destin=0;v_destin<8;v_destin++){
                for(int h_destin=0;h_destin<8;h_destin++){
                    if(tower(v_atual,h_atual,v_destin,h_destin,vez)==1 && check_xeque_destino(v_atual,h_atual,v_destin,h_destin,vez) == 0){
                        ok = 1;
                        goto Done;
                    }
                }
            }
        }
    }
    Done:;
return ok;
}
int check_rei_proximo(int v_board_atual, int h_board_atual, int vez){///////////////////////////////////////////////////////////////////DONE//////////////////////////////////
    int ok = 0;
    int v, h;
    for(v = -1;v<=1;v++){
        for(h = -1;h<=1;h++){
            if(vez%2==0){
                if(board[v_board_atual+v][h_board_atual+h] == b_king && ok == 0){
                    ok = 1;
                    goto Done;
                }else{
                    ok = 0;
                }
            }else{
                if(board[v_board_atual+v][h_board_atual+h] == w_king && ok == 0){
                    ok = 1;
                    goto Done;
                }else{
                    ok = 0;
                }
            }
        }
    }
Done:;
return ok;
}
int check_saida_xeque(int v_alvo,int h_alvo, int turn){/////////////////////////////////////////////////////////////////////////////////DONE//////////////////////////////////
    int v_rei, h_rei, ok = 0;
    for(int i=0;i<8;i++){//procura o rei aliado
        for(int w=0;w<8;w++){
            if(turn%2==0){
                if(board[i][w] == w_king){
                v_rei = i;
                h_rei = w;
                }
            }else{
                if(board[i][w] == b_king){
                v_rei = i;
                h_rei = w;
                }
            }
        }
    }//retorna a posicao do rei aliado
    int step_v,step_h;
    int num_steps_v = v_rei - v_alvo;
    int num_steps_h = h_rei - h_alvo;
    if(num_steps_h == 0){
        step_v = num_steps_v/abs(num_steps_v);
        step_h = 0;
    }else if(num_steps_v == 0){
        step_v = 0;
        step_h = num_steps_h/abs(num_steps_h);
    }else if((abs(num_steps_v)+abs(num_steps_v))>0){
        step_v = num_steps_v/abs(num_steps_v);
        step_h = num_steps_h/abs(num_steps_h);
    }else{
        ok = 0;
    }
    if(step_h==0 && step_v!=0){
        for(int i = num_steps_v;i!=0;i-=step_v){
            v_alvo += step_v;
            h_alvo += step_h;
            if(check_neutralizar_path_ameaca(v_alvo,h_alvo, turn)==1){
                ok = 1;
                goto Done;
            }else{
                ok = 0;
            }
        }
    }else if(step_v==0 && step_h!=0){
        for(int i = num_steps_h;i!=0;i-=step_h){
            v_alvo += step_v;
            h_alvo += step_h;
            if(check_neutralizar_path_ameaca(v_alvo,h_alvo, turn)==1){
                ok = 1;
                goto Done;
            }else{
                ok = 0;
            }
        }
    }else if(abs(step_h) == abs(step_h)){
        for(int i = num_steps_h;i!=0;i-=step_h){
            v_alvo += step_v;
            h_alvo += step_h;
            if(check_neutralizar_path_ameaca(v_alvo,h_alvo, turn)==1){
                ok = 1;
                goto Done;
            }else{

                ok = 0;
            }
        }
    }else{
        ok = 0;
    }
Done:;
return ok;
}
int check_xeque(int vez){///////////////////////////////////////////////////////////////////////////////////////////////////////////////DONE//////////////////////////////////
    int v, h, ok = 0;
    for(int i=0;i<8;i++){//procura o rei aliado
        for(int w=0;w<8;w++){
            if(vez%2==0){
                if(board[i][w] == w_king){
                v = i;
                h = w;
                goto Rei_Done;
                }
            }else{
                if(board[i][w] == b_king){
                v = i;
                h = w;
                goto Rei_Done;
                }
            }
        }
    }//retorna a posicao do rei aliado
    Rei_Done:;
    if(vez%2==0){
        for(int i=0;i<8;i++){
            for(int w=0;w<8;w++){
                if(board[i][w] != empty){
                    if(board[i][w]==b_pawn){
                        ok = black_pawn(i,w,v,h,vez+1);//retorna 1 caso ataque possivel
                        if(ok == 1){
                            if(check_neutralizar_ameaca_and_path(i,w,vez)==1){
                                printf("Rei branco ameaçado pelo Peão Preto\n");
                                goto Done;
                            }else{
                                if(check_psbld_movm(v,h,vez)==1){
                                    goto Done;
                                }else{
                                    ok = 2;
                                    goto Done;
                                }
                            }
                        }
                    }else if(board[i][w]==b_tower){
                        ok = tower(i,w,v,h,vez+1);
                        if(ok == 1){

                            if(check_neutralizar_ameaca_and_path(i,w,vez)==1){
                                printf("Rei branco ameaçado pela Torre Preta\n");

                                goto Done;
                            }else{
                                if(check_psbld_movm(v,h,vez)==1){
                                    goto Done;
                                }else{
                                    ok = 2;
                                    goto Done;
                                }
                            }
                        }
                    }else if(board[i][w]==b_horse){
                        ok = horse(i,w,v,h,vez+1);
                        if(ok == 1){
                            if(check_neutralizar_ameaca_and_path(i,w,vez)==1){
                                printf("Rei branco ameaçado pelo Cavalo Preto\n");
                                goto Done;
                            }else{
                                if(check_psbld_movm(v,h,vez)==1){
                                    goto Done;
                                }else{
                                    ok = 2;
                                    goto Done;
                                }
                            }
                        }
                    }else if(board[i][w]==b_bishop){
                        ok = bishop(i,w,v,h,vez+1);
                        if(ok == 1){
                            if(check_neutralizar_ameaca_and_path(i,w,vez)==1){
                                printf("Rei branco ameaçado pelo Bispo Preto\n");
                                goto Done;
                            }else{
                                if(check_psbld_movm(v,h,vez)==1){
                                    goto Done;
                                }else{
                                    ok = 2;
                                    goto Done;
                                }
                            }
                        }
                    }else if(board[i][w]==b_queen){
                        ok = queen(i,w,v,h,vez+1);
                        if(ok == 1){
                            if(check_neutralizar_ameaca_and_path(i,w,vez)==1){
                                printf("Rei branco ameaçado pela Rainha Preta\n");
                                goto Done;
                            }else{
                                if(check_psbld_movm(v,h,vez)==1){
                                    goto Done;
                                }else{
                                    ok = 2;
                                    goto Done;
                                }
                            }
                        }
                    }else if(board[i][w]==b_king){
                        ok = king(i,w,v,h,vez+1);
                        if(ok == 1){
                            if(check_neutralizar_ameaca_and_path(i,w,vez)==1){
                                printf("Rei branco ameaçado pelo Rei Preto\n");
                                goto Done;
                            }else{
                                if(check_psbld_movm(v,h,vez)==1){
                                    goto Done;
                                }else{
                                    ok = 2;
                                    goto Done;
                                }
                            }
                        }
                    }else{
                        ok = 0;
                    }
                }
            }
        }
    }else{
        for(int i=0;i<8;i++){
            for(int w=0;w<8;w++){
                if(board[i][w] != empty){
                    if(board[i][w] == w_pawn){
                        ok = white_pawn(i,w,v,h,vez+1);//retorna 1 caso ataque possivel
                        if(ok == 1){
                            if(check_neutralizar_ameaca_and_path(i,w,vez)==1){
                                printf("Rei Preto ameaçado pelo Peão Branco\n");
                                goto Done;
                            }else{
                                if(check_psbld_movm(v,h,vez)==1){
                                    goto Done;
                                }else{
                                    ok = 2;
                                    goto Done;
                                }
                            }
                        }
                    }else if(board[i][w] == w_tower){
                        ok = tower(i,w,v,h,vez+1);
                        if(ok == 1){
                            if(check_neutralizar_ameaca_and_path(i,w,vez)==1){
                                printf("Rei Preto ameaçado pela Torre Branca\n");
                                goto Done;
                            }else{
                                if(check_psbld_movm(v,h,vez)==1){
                                    goto Done;
                                }else{
                                    ok = 2;
                                    goto Done;
                                }
                            }
                        }
                    }else if(board[i][w] == w_horse){
                        ok = horse(i,w,v,h,vez+1);
                        if(ok == 1){
                            if(check_neutralizar_ameaca_and_path(i,w,vez)==1){
                                printf("Rei Preto ameaçado pelo Cavalo Branco\n");
                                goto Done;
                            }else{
                                if(check_psbld_movm(v,h,vez)==1){
                                    goto Done;
                                }else{
                                    ok = 2;
                                    goto Done;
                                }
                            }
                        }
                    }else if(board[i][w] == w_bishop){
                        ok = bishop(i,w,v,h,vez+1);
                        if(ok == 1){
                            if(check_neutralizar_ameaca_and_path(i,w,vez)==1){
                                printf("Rei Preto ameaçado pelo Bispo Branco\n");
                                goto Done;
                            }else{
                                if(check_psbld_movm(v,h,vez)==1){
                                    goto Done;
                                }else{
                                    ok = 2;
                                    goto Done;
                                }
                            }
                        }
                    }else if(board[i][w] == w_queen){
                        ok = queen(i,w,v,h,vez+1);
                        if(ok == 1){
                            if(check_neutralizar_ameaca_and_path(i,w,vez)==1){
                                printf("Rei Preto ameaçado pela Rainha Branca\n");
                                goto Done;
                            }else{
                                if(check_psbld_movm(v,h,vez)==1){
                                    goto Done;
                                }else{
                                    ok = 2;
                                    goto Done;
                                }
                            }
                        }
                    }else if(board[i][w] == w_king){
                        ok = king(i,w,v,h,vez+1);
                        if(ok == 1){
                            if(check_neutralizar_ameaca_and_path(i,w,vez)==1){
                                printf("Rei Preto ameaçado pelo Rei Branco\n");
                                goto Done;
                            }else{
                                if(check_psbld_movm(v,h,vez)==1){
                                    goto Done;
                                }else{
                                    ok = 2;
                                    goto Done;
                                }
                            }
                        }
                    }else{
                        ok = 0;
                    }
                }
            }
        }
    }
    Done:;

return ok;//retorna 1 se tiver em check
}
int check_xeque_destino(int v_atual, int h_atual, int v_destin, int h_destin, int turn){////////////////////////////////////////////////DONE//////////////////////////////////
    int ok = 0, pass = 0;
    board_destin[0] = board[v_atual][h_atual];
    board_destin[1] = board[v_destin][h_destin];//reserva itens originais para reverter a alteracao de teste
    board[v_destin][h_destin] = board_destin[0];
    board[v_atual][h_atual] = empty;//simula o tabuleiro destino procurando um check
    ok = check_xeque_tester(turn);//checa de tabuleiro simulado esta em check
    board[v_atual][h_atual] = board_destin[0];
    board[v_destin][h_destin] = board_destin[1];//realoca os elementos originais
    ////0 = nao tem xeque /// 1 = tem xeque
return ok;
}

int king(int v_board_atual, int h_board_atual, int v_board_destin, int h_board_destin, int turn){///////////////////////////////////////DONE//////////////////////////////////
    int ok = 0;
    int mov_v, mov_h;
    mov_v = v_board_destin - v_board_atual;
    mov_h = h_board_destin - h_board_atual;
    if(abs(mov_v)+abs(mov_h) == 0){
        ok = 0;
    }else if(check_aliada_ou_notempty(v_board_atual,h_board_atual,turn) && check_inimigo(v_board_destin,h_board_destin,turn)==1 && check_rei_proximo(v_board_destin,h_board_destin,turn)==0){
        if(abs(mov_v)<2 && abs(mov_h)<2){
            ok = 1;
        }else{
            ok = 0;
        }
    }else{
        ok = 0;
    }
return ok;
}
int queen(int v_board_atual, int h_board_atual, int v_board_destin, int h_board_destin, int turn){//////////////////////////////////////DONE//////////////////////////////////
    int ok = 1;
    int mov_v, mov_h,s_mov_v,s_mov_h;
    mov_v = v_board_destin - v_board_atual;//procura a difereca pra saber a direcao
    mov_h = h_board_destin - h_board_atual;
    if(check_aliada(v_board_atual,h_board_atual,turn)==1 && check_inimigo(v_board_destin,h_board_destin,turn)==1){
        if(abs(mov_v)==abs(mov_h)){
            if(abs(mov_v)==1){
                ok = 1;
            }else if(abs(mov_v)>1){
                s_mov_v = mov_v/abs(mov_v);
                s_mov_h = mov_h/abs(mov_h);
                ok = check_path(v_board_atual,h_board_atual,v_board_destin,h_board_destin,s_mov_v,s_mov_h);
            }else{
            ok = 0;
            }
        }else if(mov_v!=0 && mov_h==0){
            s_mov_v = mov_v/abs(mov_v);
            s_mov_h = 0;
            if(abs(mov_v) == 1){
                ok = 1;
            }else if(abs(mov_v)>1){
                ok = check_path(v_board_atual,h_board_atual,v_board_destin,h_board_destin,s_mov_v,s_mov_h);
            }else{
                ok = 0;
            }
        }else if(mov_v==0 && mov_h!=0){
            s_mov_v = 0;
            s_mov_h = mov_h/abs(mov_h);
            if(abs(mov_h) == 1){
                ok = 1;
            }else if(abs(mov_h)>1){
                ok = check_path(v_board_atual,h_board_atual,v_board_destin,h_board_destin,s_mov_v,s_mov_h);
            }else{
                ok = 0;
            }
        }else{
            ok = 0;
        }
    }else{
        ok = 0;
    }
return ok;
}
int bishop(int v_board_atual, int h_board_atual, int v_board_destin, int h_board_destin, int turn){/////////////////////////////////////DONE//////////////////////////////////
    int ok = 1;
    int mov_v, mov_h, s_mov_v, s_mov_h;
    mov_v = v_board_destin - v_board_atual;
    mov_h = h_board_destin - h_board_atual;
    if(check_aliada_ou_notempty(v_board_atual,h_board_atual,turn)==1 && check_inimigo(v_board_destin,h_board_destin,turn)==1 && abs(mov_v)==abs(mov_h) && mov_v!=0){
        if(abs(mov_v)==1){
            ok = 1;
        }else if(abs(mov_v)>1){
            s_mov_v = mov_v/abs(mov_v);
            s_mov_h = mov_h/abs(mov_h);
            ok = check_path(v_board_atual,h_board_atual,v_board_destin,h_board_destin,s_mov_v,s_mov_h);
        }else{
        ok = 0;
        }
    }else{
    ok = 0;
    }
return ok;
}
int horse(int v_board_atual, int h_board_atual, int v_board_destin, int h_board_destin, int turn){//////////////////////////////////////DONE//////////////////////////////////
    int ok = 0;
    int mov_v, mov_h;
    mov_v = v_board_destin - v_board_atual;
    mov_h = h_board_destin - h_board_atual;
    if(check_aliada_ou_notempty(v_board_atual,h_board_atual,turn)==1 && check_inimigo(v_board_destin,h_board_destin,turn)==1){
        if(abs(mov_v) == 2 && abs(mov_h) == 1){
            ok = 1;
        }else if(abs(mov_v) == 1 && abs(mov_h) == 2){
            ok = 1;
        }else{
            ok = 0;
        }
    }else{
        ok = 0;
    }
return ok;
}
int tower(int v_board_atual, int h_board_atual, int v_board_destin, int h_board_destin, int turn){//////////////////////////////////////DONE//////////////////////////////////
    int ok;
    int temp = 0;
    int mov_v, mov_h, s_mov_v, s_mov_h;
    mov_v = v_board_destin - v_board_atual;
    mov_h = h_board_destin - h_board_atual;
    if(check_aliada(v_board_atual,h_board_atual,turn)==1 && check_inimigo(v_board_destin,h_board_destin,turn)==1){
        if(mov_v!=0 && mov_h==0){
            s_mov_v = mov_v/abs(mov_v);
            s_mov_h = 0;
            if(abs(mov_v) == 1){
                ok = 1;
            }else if(abs(mov_v)>1){
                ok = check_path(v_board_atual,h_board_atual,v_board_destin,h_board_destin,s_mov_v,s_mov_h);
            }else{
                ok = 0;
            }
        }else if(mov_v==0 && mov_h!=0){
            s_mov_v = 0;
            s_mov_h = mov_h/abs(mov_h);
            if(abs(mov_h) == 1){
                    ok = 1;
            }else if(abs(mov_h)>1){
                ok = check_path(v_board_atual,h_board_atual,v_board_destin,h_board_destin,s_mov_v,s_mov_h);
            }else{
                ok = 0;
            }
        }else{
            ok = 0;
        }
    }else{
        ok = 0;
    }
return ok;
}
int white_pawn(int v_board_atual, int h_board_atual, int v_board_destin, int h_board_destin, int vez){//////////////////////////////////DONE//////////////////////////////////
    int ok = 0;
    int mov_v, mov_h;
    mov_v = v_board_destin - v_board_atual;
    mov_h = h_board_destin - h_board_atual;
    if(check_aliada(v_board_atual, h_board_atual,vez) == 1 && check_inimigo(v_board_destin,h_board_destin,vez) == 1){
        if (mov_h == 0 && mov_v == -1){//verifica se movimento sera de uma casa para frente e n tem inimigo
            if(board[v_board_destin][h_board_destin] != empty){
                ok = 0;
            }else{
                ok = 1;
            }
        }else if(mov_h == 0 && mov_v == -2){//verifica se movimento sera de duas casas para frente casos peao esteja na posicao 6 do
            if (v_board_atual == 6 && board[v_board_destin][h_board_destin] == empty && board[v_board_destin+1][h_board_destin] == empty){
                ok = 1;
            }else{
                ok = 0;
            }
        }else if(abs(mov_h)*abs(mov_v)==1){//se houver um inimigo na diagonal a frente diretamente a seguir, o peao pode capturar
            if(v_board_atual>v_board_destin){
                if(check_inimigo(v_board_destin, h_board_destin, vez) == 1 && board[v_board_destin][h_board_destin] != empty){
                    ok = 1;
                }else{
                    ok = 0;
                }
            }else{
                ok = 0;
            }
        }else{
            ok = 0;
        }
    }else{
        ok = 0;
    }
    return ok;
}
int black_pawn(int v_board_atual, int h_board_atual, int v_board_destin, int h_board_destin, int vez){//////////////////////////////////DONE//////////////////////////////////
    int ok = 0;
    int mov_v, mov_h;
    mov_v = v_board_destin - v_board_atual;
    mov_h = h_board_destin - h_board_atual;
    if(check_aliada(v_board_atual, h_board_atual,vez) == 1 && check_inimigo(v_board_destin,h_board_destin,vez) == 1){
        if (mov_h == 0 && mov_v == 1){//verifica se movimento sera de uma casa para frente e n tem inimigo
            if(board[v_board_destin][h_board_destin] != empty){
                ok = 0;
            }else{
                ok = 1;
            }
        }else if(mov_h == 0 && mov_v == 2){//verifica se movimento sera de duas casas para frente casos peao esteja na posicao 6 do
            if (v_board_atual == 1 && board[v_board_destin][h_board_destin] == empty && board[v_board_destin-1][h_board_destin] == empty){
                ok = 1;
            }else{
                ok = 0;
            }
        }else if(abs(mov_h)*abs(mov_v)==1){//se houver um inimigo na diagonal a frente diretamente a seguir, o peao pode capturar
            if(v_board_atual<v_board_destin){
                if(check_inimigo(v_board_destin, h_board_destin, vez) == 1 && board[v_board_destin][h_board_destin] != empty){
                    ok = 1;
                }else{
                    ok = 0;
                }
            }else{
                ok = 0;
            }
        }else{
            ok = 0;
        }
    }else{
        ok = 0;
    }
return ok;
}
int check_xeque_tester(int vez){////////////////////////////////////////////////////////////////////////////////////////////////////////DONE//////////////////////////////////
    int v, h, ok = 0;
    for(int i=0;i<8;i++){//procura o rei aliado
        for(int w=0;w<8;w++){
            if(vez%2==0){
                if(board[i][w] == w_king){
                v = i;
                h = w;
                goto Rei_Done;
                }
            }else{
                if(board[i][w] == b_king){
                v = i;
                h = w;
                goto Rei_Done;
                }
            }
        }
    }//retorna a posicao do rei aliado
    Rei_Done:;
    if(vez%2==0){
        for(int i=0;i<8;i++){
            for(int w=0;w<8;w++){
                if(board[i][w] != empty){
                    if(board[i][w]==b_pawn){
                        ok = black_pawn(i,w,v,h,vez+1);//retorna 1 caso ataque possivel
                        if(ok == 1){
                            goto Done;
                        }
                    }else if(board[i][w]==b_tower){
                        ok = tower(i,w,v,h,vez+1);
                        if(ok == 1){
                            goto Done;
                        }
                    }else if(board[i][w]==b_horse){
                        ok = horse(i,w,v,h,vez+1);
                        if(ok == 1){
                            goto Done;
                        }
                    }else if(board[i][w]==b_bishop){
                        ok = bishop(i,w,v,h,vez+1);
                        if(ok == 1){
                            goto Done;
                        }
                    }else if(board[i][w]==b_queen){
                        ok = queen(i,w,v,h,vez+1);
                        if(ok == 1){
                            goto Done;
                        }
                    }else if(board[i][w]==b_king){
                        ok = king(i,w,v,h,vez+1);
                        if(ok == 1){
                            goto Done;
                        }
                    }else{
                        ok = 0;
                    }
                }
            }
        }
    }else{
        for(int i=0;i<8;i++){
            for(int w=0;w<8;w++){
                if(board[i][w] != empty){
                    if(board[i][w] == w_pawn){
                        ok = white_pawn(i,w,v,h,vez+1);//retorna 1 caso ataque possivel
                        if(ok == 1){
                            goto Done;
                        }
                    }else if(board[i][w] == w_tower){
                        ok = tower(i,w,v,h,vez+1);
                        if(ok == 1){
                            goto Done;
                        }
                    }else if(board[i][w] == w_horse){
                        ok = horse(i,w,v,h,vez+1);
                        if(ok == 1){
                            goto Done;
                        }
                    }else if(board[i][w] == w_bishop){
                        ok = bishop(i,w,v,h,vez+1);
                        if(ok == 1){
                            goto Done;
                        }
                    }else if(board[i][w] == w_queen){
                        ok = queen(i,w,v,h,vez+1);
                        if(ok == 1){
                            goto Done;
                        }
                    }else if(board[i][w] == w_king){
                        ok = king(i,w,v,h,vez+1);
                        if(ok == 1){
                            goto Done;
                        }
                    }else{
                        ok = 0;
                    }
                }
            }
        }
    }
    Done:;
return ok;//retorna 1 se tiver em check
}



