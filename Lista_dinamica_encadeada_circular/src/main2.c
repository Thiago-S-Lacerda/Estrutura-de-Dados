#include "../include/ListaDinEncadCircOtm.h"
#include <stdio.h>

int main(void) {
    Lista *lf = cria_lista();
    struct aluno al;
    al.matricula = 1;
    insere_lista_final(lf, al);
    imprime_lista(lf);
    al.matricula = 2;
    insere_lista_inicio(lf, al);
    imprime_lista(lf);
    al.matricula = 3;
    insere_lista_final(lf, al);
    imprime_lista(lf);
    al.matricula = 5;
    insere_lista_final(lf, al);
    imprime_lista(lf);
    al.matricula = 7;
    insere_lista_final(lf, al);
    imprime_lista(lf);
    al.matricula = 8;
    insere_lista_final(lf, al);
    imprime_lista(lf);
    al.matricula = 9;
    insere_lista_final(lf, al);
    imprime_lista(lf);
    al.matricula = 11;
    insere_lista_final(lf, al);
    imprime_lista(lf);
    al.matricula = 19;
    insere_lista_final(lf, al);
    imprime_lista(lf);
    al.matricula = 43;
    insere_lista_inicio(lf, al);
    imprime_lista(lf);
    if(!remove_lista_inicio(lf)) {
        printf("Erro");
    }
    remove_lista_inicio(lf);
    imprime_lista(lf);
}