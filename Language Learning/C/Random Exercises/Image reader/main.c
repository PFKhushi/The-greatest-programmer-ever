#include <stdio.h>
#include <stdlib.h>
#define ETB 23

typedef struct pixels{
    int *r,*g,*b;
    struct pixels *next;
}Pixels;

typedef struct ppm{//estrutura da imagem
    char *format, *height, *width,*scale, *end;
    Pixels *pixels;
}PPM;

void innit_PPM(PPM *image);
void innit_pixels(Pixels *pixel);
void get_color(Pixels *pixel, FILE *fp);

void write_new_file();
void write_pixels(FILE *fp, Pixels *pixels);
void copy_image(FILE *fp, PPM *image);
void get_header(PPM *image, FILE *fp);

void write_p3(FILE *foutput, PPM* image);



void print_header(FILE *fp);
void skip_header(FILE *fp);


int main()
{
    FILE *finput, *foutput;
    PPM *image;
    image=(PPM*)malloc(sizeof(PPM));

    Pixels *pixel;
    pixel = (Pixels*)malloc(sizeof(Pixels));

    innit_PPM(image);
    innit_pixels(pixel);
    image->pixels=pixel;

    char header;
    int pular, cor, count;
    finput = fopen("erPUC.ppm","r");
    foutput = fopen("TESTECARAI.ppm", "w");
    copy_image(finput,image);

    write_p3(foutput, image);

    //count=0;
    //write_new_file();

    //get_color(pixel,fp);
    fclose(finput);
    fclose(foutput);





    /*
    fp = fopen("erPUC.ppm","r");
    pular=0;
    while(((header = getc(fp))!=EOF)&&pular<3){
        header=='\n'?pular++:0;
        printf("%c", header);
    }
    count=0;
    while(((cor = getc(fp))!=EOF)){
        (count%3==0)?printf("\n", count):0;
        printf("[%03d]", cor);

        count++;

    }
    printf("\n\n%d", count);
    fclose(fp);
    */


    return 0;
}

void write_p3(FILE *foutput, PPM* image){

    fprintf(foutput,"P3\n50 50\n255\n");

    write_pixels(foutput,image->pixels);

}


void innit_PPM(PPM *image){
    image->format=(char*)malloc(sizeof(char));
    image->height=(char*)malloc(sizeof(char));
    image->width=(char*)malloc(sizeof(char));
    image->scale=(char*)malloc(sizeof(char));
    image->end=(char*)malloc(sizeof(char));
    image->end="23";
    image->pixels=NULL;
}

void innit_pixels(Pixels *pixel){
    pixel->r = (int*)calloc(1,sizeof(int));
    pixel->b = (int*)calloc(1,sizeof(int));
    pixel->g = (int*)calloc(1,sizeof(int));
    pixel->next=NULL;
}

void get_color(Pixels *pixel, FILE *fp){

    int *cor,r,g,b;
    cor=(int*)calloc(1,sizeof(int));

    *(pixel->r)=getc(fp);
    *(pixel->g)=getc(fp);
    *(pixel->b)=getc(fp);
    //printf("[%03d,%03d,%03d]\n", *(pixel->r),*(pixel->g),*(pixel->b));
    //pixel->next==NULL?printf("[NULL]"):printf("[NOT NULL]");

    if(((cor=getc(fp))!=EOF)&&(cor!=ETB)){
        ungetc(cor,fp);

        (pixel->next)=(Pixels*)malloc(sizeof(Pixels));

        innit_pixels(pixel->next);

        get_color(pixel->next,fp);
        printf("[%03d,%03d,%03d]\n", *(pixel->r),*(pixel->g),*(pixel->b));
    }
    //pixel->next==NULL?printf("[NULL]"):printf("[NOT NULL]");


}
void write_new_file(){

    FILE *fp;
    fp = fopen("erPUCTEST.ppm","wb");
    //char header[] = "P6\n8 8\n255\n";
    //fwrite(header,1,sizeof(header),fp);
            //image->format,image->width,image->height, image->scale);
    char format[]="P6\n16 16\n255\n";

    fwrite(format,1, sizeof(format), fp);

    int num = 0;
    for(int i=0;i<64; i++){
        printf("test");


        fwrite(&num,1,sizeof(num), fp);
        printf("[%d]", num);
        num = 255;
        fwrite(&num,1,sizeof(num), fp);
        printf("[%d]", num);
        //num = 255;
        fwrite(&num,1,sizeof(num), fp);
        printf("[%d]", num);
        //num = 255;
        fwrite(&num,1,sizeof(num), fp);
        printf("[%d]", num);
        //num = 0;
        //num-=(i-2)*(i-1);
        printf("\n");
    }
    //system("magick erPUCTEST.ppm erPUCTEST.png");

    fclose(fp);


}
void write_pixels(FILE *fp,Pixels *pixels){

    //fprintf(fp,"%d%d%d",255,255,255);
    fprintf(fp,"%d %d %d ", *pixels->r,*pixels->g,*pixels->b);
    printf("[%03d,%03d,%03d]\n", *(pixels->r),*(pixels->g),*(pixels->b));
    pixels->next==NULL?printf("[NULL]"):printf("[NOT NULL]");
    pixels->next?write_pixels(fp,pixels->next):0;


}

void copy_image(FILE *fp, PPM *image){
    get_header(image,fp);
    get_color(image->pixels,fp);

    printf("%s%s%s", image->format,image->width,image->height);
}

void get_header(PPM *image, FILE *fp){

    int i=0;
    for(;((*(image->format+i)=getc(fp))!='\n');i++);//pega formato ate encontrar nova linha
    i=0;
    for(;((*(image->width+i)=getc(fp))!=' ');i++);//pega largura a seguir, ate encontrar um espaco
    i=0;
    for(;((*(image->height+i)=getc(fp))!='\n');i++);//pega altura a seguir, ate encontrar nova linha
    i=0;
    for(;((*(image->scale+i)=getc(fp))!='\n');i++);//pega escala de cor a seguir, ate encontrar nova linha
    i=0;

}

void print_header(FILE *fp){
    char header;
    int pular=0;
    while(((header = getc(fp))!=EOF)&&pular<3){
        header=='\n'?pular++:0;
        printf("%c", header);
    }

}

void skip_header(FILE *fp){
    char header;
    int pular=0;
    while(((header = getc(fp))!=EOF)&&pular<3){
        header=='\n'?pular++:0;
    }

}
