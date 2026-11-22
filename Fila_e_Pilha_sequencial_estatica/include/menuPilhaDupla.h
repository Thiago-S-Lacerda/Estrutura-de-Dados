#ifndef MENU_PILHA_DUPLA_H
#define MENU_PILHA_DUPLA_H
#include "PilhaDupla.h"

void menu_pilha_dupla();

/* Verifica todas as funções gerais implementadas na lista*/
void caso4(PilhaDupla *pi);

/* Cria Um aluno e escreve na variável passada*/
void criar_aluno(struct aluno *al);

/* Imprime os campos do aluno passado*/
void imprime_aluno_buscado(struct aluno *al);

#endif