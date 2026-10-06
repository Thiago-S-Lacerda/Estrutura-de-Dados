#ifndef MENU_H
#define MENU_H
#include "ListaDinEncad.h"

void menu();

void caso1(ListaTarefas *li, struct tarefa t);

void caso2(ListaTarefas *li);

void caso3(ListaTarefas *li, struct tarefa *t);

void caso4(ListaTarefas *li, ListaTarefas *li2, struct tarefa *t);

#endif