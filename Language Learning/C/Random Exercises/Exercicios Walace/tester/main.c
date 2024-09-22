#include <stdio.h>
#include <stdlib.h>

char *board[8][8];
char *board_destin[2];
char **tabuleiro[18][18];

char *b_king = " BK ", *b_queen = " BQ ", *b_tower = " BT ", *b_bishop = " BB ", *b_horse = " BH ", *b_pawn = " BP ";
char *w_king = " WK ", *w_queen = " WQ ", *w_tower = " WT ", *w_bishop = " WB ", *w_horse = " WH ", *w_pawn = " WP ";
char *empty = "    ";
char *pretas[6] = {
    " BK ",
    " BQ ",
    " BB ",
    " BH ",
    " BT ",
    " BP "
};
char *brancas[6] = {
    " WK ",
    " WQ ",
    " WB ",
    " WH ",
    " WT ",
    " WP "
};

char barra_v[] = "|";
char barra_h[] = "----";
char ponto[] = ".";


int main()
{

    /*
    int j = 0;
        while (*(pretas[0] + j) != '\0') {
            printf("%c", *(pretas[0]+j));
	    j++;
        }
        // print a new line after printing the ith string
        printf("\n");

     j = 0;
        while (*(pretas[1] + j) != '\0') {
            printf("%c", *(pretas[1]+j));
	    j++;
        }
        // print a new line after printing the ith string
        printf("\n");

    j = 0;
        while (*(pretas[2] + j) != '\0') {
            printf("%c", *(pretas[2]+j));
	    j++;
        }
        // print a new line after printing the ith string
        printf("\n");

    j = 0;
        while (*(pretas[3] + j) != '\0') {
            printf("%c", *(pretas[3]+j));
	    j++;
        }
        // print a new line after printing the ith string
        printf("\n");

    j = 0;
        while (*(pretas[4] + j) != '\0') {
            printf("%c", *(pretas[4]+j));
	    j++;
        }
        // print a new line after printing the ith string
        printf("\n");
    */

    board[0][0] = pretas[3];
    puts(board[0][0]);
    board[0][0] = b_horse;
    puts(board[0][0]);
    printf("[%s]", board[0][0]);
    printf("[%s]", board[0][0]);



    reset_board();
    //tabular();
    print_tabuleiro();
    return 0;
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
