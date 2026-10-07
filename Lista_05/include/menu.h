#ifndef MENU_H
#define MENU_H
#include "ListaDinEncad.h"

void menu();

/* Verifica todos os casos implementados de inserção na lista*/
void caso1(ListaTarefas *li, struct tarefa t);

/* Verifica todos os casos implementados de remoção na lista */
void caso2(ListaTarefas *li);

/* Verifica todos os casos de busca implementados na lista*/
void caso3(ListaTarefas *li, struct tarefa *t);

/* Verifica todas as funções gerais implementadas na lista*/
void caso4(ListaTarefas *li, ListaTarefas *li2, struct tarefa *t);

#endif