#include "menu.h"
#include "ListaDinEncadCirc.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void menu() {
    int resp;
    int sistema = 1;
    Lista *li = cria_lista();
    Lista *li2 = cria_lista();
    
    struct aluno a;
    if (li == NULL || li2 == NULL) {
        printf("Não foi possivel criar a lista");
        return;
    }

    a.matricula = 10;
    strcpy(a.nome, "Pedro");
    a.n1 = 8.0f;
    a.n2 = 7.5f;
    a.n3 = 9.3f;
    if (!insere_lista_final(li2, a)) {
        printf("Erro ao iniciar\n");
        return;
    }
    a.matricula = 17;
    strcpy(a.nome, "Daniel");
    a.n1 = 9.7f;
    a.n2 = 9.2f;
    a.n3 = 9.5f;
    if (!insere_lista_final(li2, a)) {
        printf("Erro ao iniciar\n");
        return;
    }

    printf("\033[2J\033[H");

    while (sistema) {
        printf("\n================================\n");
        printf("\t      MENU\n");
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
                caso4(li, li2);
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
    libera_lista(li2);
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
    printf("\033[2J\033[H");
    printf("\n================================\n");
    printf("\t      MENU\n");
    printf("<1> : Remover no final\n");
    printf("<2> : Remover no inicio\n");
    printf("<3> : Remover por matricula\n");
    printf("<4> : Remover por posicao\n");
    printf("<5> : Voltar\n");
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
            int mat;
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
        default:
            if (resp != 5) {
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
    printf("<3> : Buscar ciclicamente\n");
    printf("<4> : Voltar\n");
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
        case 3:
            printf("Digite a posicao a ser buscada: ");
            scanf("%d", &pos);
            if (busca_ciclica(li, pos, al)) {
                imprime_aluno_buscado(al);
            } else {
                printf("Lista invalida\n");
            }
            break;
        default:
            if (resp != 4) {
                printf("\033[2J\033[H");
                printf("Digito invalido\n");
            }
            break;
    }
}

void caso4(Lista *li, Lista *li2) {
    int resp;
    int mat = 0;
    int pos = 0;
    printf("\033[2J\033[H");
    printf("\n================================\n");
    printf("\t      MENU\n");
    printf("<1> : Tamanho da lista\n");
    printf("<2> : Verificar se a lista esta cheia\n");
    printf("<3> : Verificar qual a maior matricula dentro da lista\n");
    printf("<4> : Verificar a quantidade de alunos aprovados na lista\n");
    printf("<5> : Verificar se a lista esta vazia\n");
    printf("<6> : Rotacionar a lista\n");
    printf("<7> : Concatenar duas listas\n");
    printf("<8> : Imprimir toda a lista\n");
    printf("<9> : Problema de Josephus\n");
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
            if (maior_matricula(li, &mat)) {
                printf("A maior matricula e: %d\n", mat);
            } else {
                printf("Lista invalida\n");
            }
            break;
        case 4:
            int quant = 0;
            quant = conta_aprovados(li);
            if (quant != -1) {
                printf("A quantidade de aprovados e: %d\n", quant);
            } else {
                printf("Lista invalida\n");
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
            printf("Digite a nova posicao de inicio: ");
            scanf("%d", &pos);
            
            if (rotaciona_lista(li, pos)) {
                imprime_lista(li);
            } else {
                printf("Nao foi possivel rotacionar a lista.\n");
            }
            break;
        case 7:
            if (concatena_listas(li, li2)) {
                imprime_lista(li);
            } else {
                printf("Nao foi possivel concatenar as duas listas.\n");
            }
            break;
        case 8:
            imprime_lista(li);
            break;
        case 9:
            int num = 0;
            printf("Os alunos serao retirados de k em k; Digite o numero k: ");
            scanf("%d", &num);
            if (josephus(li, num, &mat)) {
                printf("\033[2J\033[H");
                printf("\n================================\n");
                printf("Matricula do aluno restante: %d\n", mat);
                printf("\n================================\n");
                printf("Pressione Qualquer tecla para continuar: ");
                getchar();
                getchar();
            } else {
                printf("Nao foi possivel realizar essa operacao.\n");
            }
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