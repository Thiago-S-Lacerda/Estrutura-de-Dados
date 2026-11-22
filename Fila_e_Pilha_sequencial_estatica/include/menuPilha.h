#ifndef MENU_PILHA_H
#define MENU_PILHA_H
#include "PilhaSequencial.h"

void menu_pilha();

/* Verifica todas as funções gerais implementadas na lista*/
void caso4(Pilha *pi);

/* Cria Um aluno e escreve na variável passada*/
void criar_aluno(struct aluno *al);

/* Imprime os campos do aluno passado*/
void imprime_aluno_buscado(struct aluno *al);

/*Em uma sequência de Inserções(I) e Remoções(R), sem espaços no meio, retorna 1 se a sequência for válida 
(número de I e R são iguais e nenhuma remoção foi feita com a pilha vazia) e 0 caso contrário*/
int sequencia_valida(const char *s);

/* Verifica se na expressão os delimitadores estão todos corretos*/
int verifica_delimitadores(const char *expr);

#endif