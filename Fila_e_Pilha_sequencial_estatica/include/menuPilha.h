#ifndef MENU_PILHA_H
#define MENU_PILHA_H
#include "PilhaSequencial.h"

void menu_pilha();

/* Verifica todas as funções gerais implementadas na lista*/
void caso4(Pilha *pi);

void criar_aluno(struct aluno *al);

void imprime_aluno_buscado(struct aluno *al);

int sequencia_valida(const char *s);

int verifica_delimitadores(const char *expr);

#endif