#include <stdio.h>
#include <stdlib.h>


typedef struct No {// Definição da estrutura do nó
  char disciplinas[50];
  float nota;
  struct No* next;
}materia;


typedef struct aluno{//Definição de estrutura final
    char matricula[50];
    materia* materias;

}alunos;


materia* novaDisciplina(char *disciplina, float nota) {// Função para criar um novo nó

  materia* no = (materia*)malloc(sizeof(materia));
  strcpy(no->disciplinas,*disciplina);
  no->nota = nota;
  no->next = NULL;
  return no;
}

void menu(){
    printf("");
}


int main()
{
    char frase[] = "test";
    int i=0;
    alunos matriculados[60];
    strcpy(matriculados[0].matricula, frase);
    //matriculados[0].matricula = "sdfg";
    printf("czf");

    //matriculados[0].materias = novaDisciplina(frase,5.5);
    printf("%s", matriculados[0].matricula);

    while(matriculados[i].matricula!=NULL){
        printf("%s", matriculados[i].matricula);
        i++;
    }/*
    for(alunos elementos : matriculados){
        printf("234234");
    }*/




    return 0;
}
