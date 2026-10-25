#ifndef MENU_OTM_H
#define MENU_OTM_H
#include "ListaDinEncadCircOtm.h"

void menuOtm();

/* Verifica todos os casos implementados de inserção na lista*/
void caso1(Lista *li, struct aluno t);

/* Verifica todos os casos implementados de remoção na lista */
void caso2(Lista *li);

/* Verifica todos os casos de busca implementados na lista*/
void caso3(Lista *li, struct aluno *t);

/* Verifica todas as funções gerais implementadas na lista*/
void caso4(Lista *li, Lista *li2);

#endif