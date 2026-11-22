#include "menuPilhaDupla.h"
#include "PilhaDupla.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void menu_pilha_dupla() {
    int resp;
    int sistema = 1;
    int cap;

    printf("Digite a capacidade total da pilha: ");
    scanf("%d", &cap);
    PilhaDupla *pd = cria_PilhaDupla(cap);
    
    struct aluno a;
    if (pd == NULL) {
        printf("Não foi possivel criar a pilha\n");
        return;
    }

    printf("\033[2J\033[H");

    while (sistema) {
        int p;
        printf("\n================================\n");
        printf("\t      MENU\n");
        printf("<1> : Adicionar aluno na pilha\n");
        printf("<2> : Remover aluno na pilha\n");
        printf("<3> : Buscar item na pilha\n");
        printf("<4> : Funcoes Gerais\n");
        printf("<5> : Encerrar Programa\n");
        printf("\n================================\n");
        printf("Digite o que voce quer fazer: ");
        scanf("%d", &resp);
        switch (resp) {
            case 1:
                printf("\033[2J\033[H");
                printf("Digite em qual pilha voce vai inserir (1 ou 2): ");
                scanf("%d", &p);
                criar_aluno(&a);
                printf("\033[2J\033[H");
                if (!insere_PilhaDupla(pd, p, a)) {
                    printf("Nao foi possivel inserir o aluno na pilha.\n");
                }
                break;
            case 2:
                printf("\033[2J\033[H");
                printf("Digite em qual pilha voce quer remover (1 ou 2): ");
                scanf("%d", &p);
                if (!remove_PilhaDupla(pd, p)) {
                    printf("Nao foi possivel remover da pilha\n");
                }   
                break;
            case 3:
                printf("\033[2J\033[H");
                printf("Digite em qual pilha voce quer consultar (1 ou 2): ");
                scanf("%d", &p);
                if (!consulta_topo_PilhaDupla(pd, p, &a)) {
                    printf("Não foi possivel consultar o aluno\n");
                    break;
                }
                imprime_aluno_buscado(&a);
                break;
            case 4:
                caso4(pd);
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
    libera_PilhaDupla(pd);
}

void caso4(PilhaDupla *pd) {
    int resp;
    int p;
    printf("\033[2J\033[H");
    printf("\n================================\n");
    printf("\t      MENU\n");
    printf("<1> : Tamanho da pilha\n");
    printf("<2> : Verificar se a pilha esta cheia\n");
    printf("<3> : Verificar se a pilha esta vazia\n");
    printf("<4> : Voltar\n");
    printf("\n================================\n");
    printf("Digite o que voce quer fazer: ");
    scanf("%d", &resp);
    printf("\033[2J\033[H");
    switch (resp) {
        case 1:
            printf("\033[2J\033[H");
            printf("Digite em qual pilha voce quer saber o tamanho (1 ou 2): ");
            scanf("%d", &p);
            int tam = tamanho_PilhaDupla(pd, p);
            if (tam != -1) {
                printf("Tamanho da pilha: %d\n", tam);
            } else {
                printf("Pilha nao existe\n");
            }
            break;
        case 2:
            printf("\033[2J\033[H");
            if (PilhaDupla_cheia(pd)) {
                printf("A pilha esta cheia\n");
            } else {
                printf("A pilha nao esta cheia\n");
            }
            break;
        case 3:
            printf("\033[2J\033[H");
            if (PilhaDupla_vazia(pd)) {
                printf("A pilha esta vazia\n");
            } else {
                printf("A pilha nao esta vazia\n");
            }
            break;
        default:
            if (resp != 4) {
                printf("\033[2J\033[H");
                printf("Digito invalido\n");
                break;
            }
            break;
    }
}

void criar_aluno(struct aluno *al) {
    int matricula = 0;
    char nome[30] = "";
    float nota1 = 0, nota2 = 0, nota3 = 0;

    printf("\033[2J\033[H");
    printf("Digite a matricula do aluno: ");
    scanf("%d", &matricula);
    printf("Digite o nome do aluno: ");
    scanf("%s", nome);
    printf("Digite as 3 notas do aluno; (exemplo: n1/n2/n3)\nDigite aqui: ");
    scanf("%f/%f/%f", &nota1, &nota2, &nota3);

    al->matricula = matricula;
    strcpy(al->nome, nome);
    al->n1 = nota1;
    al->n2 = nota2;
    al->n3 = nota3;
}

void imprime_aluno_buscado(struct aluno *al) {
    printf("\033[2J\033[H");
    printf("\n================================\n");
    printf("Matricula do aluno buscado: %d\n", al->matricula);
    printf("Nome do aluno buscado: %s\n", al->nome);
    printf("Nota 1 do aluno buscado: %.2f\n", al->n1);
    printf("Nota 2 do aluno buscado: %.2f\n", al->n2);
    printf("Nota 3 do aluno buscado: %.2f\n", al->n3);
    printf("\n================================\n");
    printf("Pressione Qualquer tecla para continuar: ");
    getchar();
    getchar();
    printf("\033[2J\033[H");
}
