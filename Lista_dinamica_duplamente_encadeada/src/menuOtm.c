#include "menuOtm.h"
#include "ListaDinEncadDuplaOtm.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void menuOtm() {
    int resp;
    int sistema = 1;
    Lista *li = cria_lista();
    
    struct aluno a;
    if (li == NULL) {
        printf("Não foi possivel criar a lista");
        return;
    }

    printf("\033[2J\033[H");

    while (sistema) {
        if (!lista_consistente(li)) {
            printf("Erro nos ponteiros\n.");
            return;
        }
        printf("\n================================\n");
        printf("\t      MENU OTIMIZADO\n");
        printf("<1> : Adicionar produto na lista\n");
        printf("<2> : Remover produto na lista\n");
        printf("<3> : Buscar item na lista\n");
        printf("<4> : Funcoes Gerais\n");
        printf("<5> : Encerrar Programa\n");
        printf("\n================================\n");
        printf("Digite o que voce quer fazer: ");
        scanf("%d", &resp);
        switch (resp) {
            case 1:
                caso1(li, a);
                break;
            case 2:
                caso2(li);
                break;
            case 3:
                caso3(li, &a);
                break;
            case 4:
                caso4(li);
                break;
            default:
                if (resp == 5) {
                    sistema = 0;
                } else {
                    printf("\033[2J\033[H");
                    printf("Digito invalido\n");
                }
                break;
        }
    }
    libera_lista(li);
}

void caso1(Lista *li, struct aluno al) {
    int resp;
    printf("\033[2J\033[H");
    printf("\n================================\n");
    printf("\t      MENU\n");
    printf("<1> : Inserir no final\n");
    printf("<2> : Inserir no inicio\n");
    printf("<3> : Inserir ordenado\n");
    printf("<4> : Voltar\n");
    printf("\n================================\n");
    printf("Digite o que voce quer fazer: ");
    scanf("%d", &resp);
    printf("\033[2J\033[H");
    switch (resp) {
        case 1:
            criar_aluno(&al);
            if (!insere_lista_final(li, al)) {
                printf("Nao foi possivel inserir o aluno na lista.\n");
            }
            break;
        case 2:
            criar_aluno(&al);
            if (!insere_lista_inicio(li, al)) {
                printf("Nao foi possivel inserir o aluno na lista.\n");
            }
            break;
        case 3:
            criar_aluno(&al);
            if (!insere_lista_ordenada(li, al)) {
                printf("Nao foi possivel inserir o aluno na lista.\n");
            }
            break;
        default:
            if (resp != 4) {
                printf("\033[2J\033[H");
                printf("Digito Invalido\n");
            }
            break;
    }
}

void caso2(Lista *li) {
    int resp;
    int mat;
    printf("\033[2J\033[H");
    printf("\n================================\n");
    printf("\t      MENU\n");
    printf("<1> : Remover no final\n");
    printf("<2> : Remover no inicio\n");
    printf("<3> : Remover por matricula\n");
    printf("<4> : Remover por posicao\n");
    printf("<5> : Remove todos por matricula\n");
    printf("<6> : Voltar\n");
    printf("\n================================\n");
    printf("Digite o que voce quer fazer: ");
    scanf("%d", &resp);
    printf("\033[2J\033[H");
    switch (resp) {
        case 1:
            if (!remove_lista_final(li)) {
                printf("Nao foi possivel remover da lista\n");
            }   
            break;
        case 2:
            if (!remove_lista_inicio(li)) {
                printf("Nao foi possivel remover da lista\n");
            }
            break;
        case 3:
            printf("Digite a matricula do aluno a ser removido: ");
            scanf("%d", &mat);
            if (!remove_lista(li, mat)) {
                printf("Nao foi possivel remover da lista\n");
            }
            break;
        case 4:
            int pos;
            printf("Digite a posicao que voce quer remover: ");
            scanf("%d", &pos);
            if (!remove_lista_pos(li, pos)) {
                printf("Nao foi possivel remover da lista\n");
            }
            break;
        case 5:
            printf("Digite a matricula dos alunos a serem removidos: ");
            scanf("%d", &mat);
            int cont = remove_todos(li, mat);
            if (cont == 0) {
                printf("Nao foi possivel remover da lista\n");
            } else {
                printf("%d alunos foram removidos da lista\n", cont);
            }
            break;
        default:
            if (resp != 6) {
                printf("\033[2J\033[H");
                printf("Digito Invalido\n");
            }
            break;
    }
}

void caso3(Lista *li, struct aluno *al) {
    int resp;
    int pos;
    int mat;
    printf("\033[2J\033[H");
    printf("\n================================\n");
    printf("\t      MENU\n");
    printf("<1> : Buscar por posicao\n");
    printf("<2> : Buscar por matricula\n");
    printf("<3> : Voltar\n");
    printf("\n================================\n");
    printf("Digite o que voce quer fazer: ");
    scanf("%d", &resp);
    printf("\033[2J\033[H");
    switch (resp) {
        case 1:
            printf("Digite a posicao a ser buscada: ");
            scanf("%d", &pos);
            if (busca_lista_pos(li, pos, al)) {
                imprime_aluno_buscado(al);
            } else {
                printf("Posicao invalida\n");
            }
            break;
        case 2:
            printf("Digite a matricula a ser buscada: ");
            scanf("%d", &mat);
            if (busca_lista_mat(li, mat, al)) {
                imprime_aluno_buscado(al);
            } else {
                printf("Matricula nao encontrada\n");
            }
            break;
        default:
            if (resp != 3) {
                printf("\033[2J\033[H");
                printf("Digito invalido\n");
            }
            break;
    }
}

void caso4(Lista *li) {
    int resp;
    printf("\033[2J\033[H");
    printf("\n================================\n");
    printf("\t      MENU\n");
    printf("<1> : Tamanho da lista\n");
    printf("<2> : Verificar se a lista esta cheia\n");
    printf("<3> : Verificar se a lista e consistente\n");
    printf("<4> : Mover um aluno para o inicio\n");
    printf("<5> : Verificar se a lista esta vazia\n");
    printf("<6> : Inverter a lista\n");
    printf("<7> : Verificar se a lista e um palindromo\n");
    printf("<8> : Imprimir a lista inversa\n");
    printf("<9> : Imprimir a lista\n");
    printf("<10> : Voltar\n");
    printf("\n================================\n");
    printf("Digite o que voce quer fazer: ");
    scanf("%d", &resp);
    printf("\033[2J\033[H");
    switch (resp) {
        case 1:
            int tam = tamanho_lista(li);
            if (tam != -1) {
                printf("Tamanho da lista: %d\n", tam);
            } else {
                printf("Lista nao existe\n");
            }
            break;
        case 2:
            if (lista_cheia(li)) {
                printf("A lista esta cheia\n");
            } else {
                printf("A lista nao esta cheia\n");
            }
            break;
        case 3:
            if (lista_consistente(li)) {
                printf("A lista e consistente\n");
            } else {
                printf("A lista nao e consistente\n");
            }
            break;
        case 4:
            int mat;
            printf("Digite a matricula do aluno a ser movido para o inicio: ");
            scanf("%d", &mat);
            if (!move_para_inicio(li, mat)) {
                printf("Nao foi possivel mover o aluno\n");
            }
            break;
        case 5:
            if (lista_vazia(li)) {
                printf("A lista esta vazia\n");
            } else {
                printf("A lista nao esta vazia\n");
            }
            break;
        case 6:
            inverte_lista(li);
            printf("Lista depois de invertida:\n");
            imprime_lista(li);
            break;
        case 7:
            if (eh_palindromo(li)) {
                printf("A lista e um palindromo\n");
            } else {
                printf("A lista nao e um palindromo\n");
            }
            break;
        case 8:
            imprime_lista_inversa(li);
            break;
        case 9:
            imprime_lista(li);
            break;
        default:
            if (resp != 10) {
                printf("\033[2J\033[H");
                printf("Digito invalido\n");
                break;
            }
            break;
    }
}