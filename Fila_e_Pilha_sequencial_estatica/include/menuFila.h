#ifndef MENU_FILA_H
#define MENU_FILA_H
#include "FilaEstatica.h"

void menu_fila();

/* Verifica todas as funções gerais implementadas na lista*/
void caso4(Fila *fi);

/* Cria Um aluno e escreve na variável passada*/
void criar_aluno(struct aluno *al);

/* Imprime os campos do aluno passado*/
void imprime_aluno_buscado(struct aluno *al);

/* De 1 a n, retira os elementos da fila de k em k posições, imprime a ordem das matrículas saídas e
retorna a matrícula do último aluno que ficou na fila.*/
int josefo(int n, int k);

#endif