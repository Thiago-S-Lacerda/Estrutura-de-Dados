#include "menuFila.h"
#include "FilaEstatica.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void menu_fila() {
    int resp;
    int sistema = 1;
    int cap;

    printf("Digite a capacidade total da fila: ");
    scanf("%d", &cap);
    Fila *fi = cria_Fila(cap);
    
    struct aluno a;
    if (fi == NULL) {
        printf("Não foi possivel criar a fila\n");
        return;
    }

    printf("\033[2J\033[H");

    while (sistema) {
        printf("\n================================\n");
        printf("\t      MENU\n");
        printf("<1> : Adicionar aluno na fila\n");
        printf("<2> : Remover aluno na fila\n");
        printf("<3> : Buscar item na fila\n");
        printf("<4> : Funcoes Gerais\n");
        printf("<5> : Encerrar Programa\n");
        printf("\n================================\n");
        printf("Digite o que voce quer fazer: ");
        scanf("%d", &resp);
        switch (resp) {
            case 1:
                criar_aluno(&a);
                if (!insere_Fila(fi, a)) {
                    printf("Nao foi possivel inserir o aluno na fila.\n");
                }
                break;
            case 2:
                if (!remove_Fila(fi)) {
                    printf("Nao foi possivel remover da fila\n");
                }   
                break;
            case 3:
                if (!consulta_Fila(fi, &a)) {
                    printf("Não foi possivel consultar o aluno\n");
                    break;
                }
                imprime_aluno_buscado(&a);
                break;
            case 4:
                caso4(fi);
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
    libera_Fila(fi);
}

void caso4(Fila * fi) {
    int resp;
    printf("\033[2J\033[H");
    printf("\n================================\n");
    printf("\t      MENU\n");
    printf("<1> : Tamanho da fila\n");
    printf("<2> : Verificar se a fila esta cheia\n");
    printf("<3> : Verificar se a fila esta vazia\n");
    printf("<4> : Furar a fila (adicionar no inicio)\n");
    printf("<5> : Problema de Josefo\n");
    printf("<6> : Voltar\n");
    printf("\n================================\n");
    printf("Digite o que voce quer fazer: ");
    scanf("%d", &resp);
    printf("\033[2J\033[H");
    switch (resp) {
        case 1:
            int tam = tamanho_Fila(fi);
            if (tam != -1) {
                printf("Tamanho da fila: %d\n", tam);
            } else {
                printf("Fila nao existe\n");
            }
            break;
        case 2:
            if (Fila_cheia(fi)) {
                printf("A fila esta cheia\n");
            } else {
                printf("A fila nao esta cheia\n");
            }
            break;
        case 3:
            if (Fila_vazia(fi)) {
                printf("A fila esta vazia\n");
            } else {
                printf("A fila nao esta vazia\n");
            }
            break;
        case 4:
            struct aluno al;
            criar_aluno(&al);
            if (!fura_Fila(fi, al)) {
                printf("Nao foi possivel furar a fila\n");
            }
            break;
        case 5:
            int n = 0, k = 0;
            printf("Os alunos de 1 a 'n' serao retirados de k em k; Digite o numero n, k; Formatacao: <n, k>: ");
            scanf("%d, %d", &n, &k);
            int sobrv = josefo(n, k);
            if (sobrv == -1) {
                printf("Nao foi possivel realizar a operacao\n");
            } else {
                printf("A matricula do aluno restante e: %d\n", sobrv);
            }
            break;
        default:
            if (resp != 6) {
                printf("\033[2J\033[H");
                printf("Digito invalido\n");
                break;
            }
            break;
    }
}

int josefo(int n, int k) {
    if (n < 1 || k < 1) return -1;
    Fila *fi = cria_Fila(n);
    if (fi == NULL) return -1;
    struct aluno al;
    for (int i = 1; i <= n; i++) {
        al.matricula = i;
        if (!insere_Fila(fi, al)) {
            libera_Fila(fi);
            return -1;
        };
    }
    while (tamanho_Fila(fi) > 1) {
        for (int i = 0; i < k-1; i++) {
            if (!consulta_Fila(fi, &al)) {
                libera_Fila(fi);
                return -1;
            }
            if (!remove_Fila(fi)) {
                libera_Fila(fi);
                return -1;
            }
            if (!insere_Fila(fi, al)) {
                libera_Fila(fi);
                return -1;
            }
        }
        if (!consulta_Fila(fi, &al)) {
            libera_Fila(fi);
            return -1;
        }
        printf("%d ", al.matricula);
        if (!remove_Fila(fi)) {
            libera_Fila(fi);
            return -1;
        }
    }

    printf("\n");
    if (!consulta_Fila(fi, &al)) {
        libera_Fila(fi);
        return -1;
    }
    libera_Fila(fi);
    return al.matricula;
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
}
