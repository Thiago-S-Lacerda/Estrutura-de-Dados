#include "menuPilha.h"
#include "PilhaSequencial.h"
#include "PilhaChar.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void menu_pilha() {
    int resp;
    int sistema = 1;
    int cap;

    printf("Digite a capacidade total da pilha: ");
    scanf("%d", &cap);
    Pilha *pi = cria_Pilha(cap);
    
    struct aluno a;
    if (pi == NULL) {
        printf("Não foi possivel criar a pilha\n");
        return;
    }

    printf("\033[2J\033[H");

    while (sistema) {
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
                criar_aluno(&a);
                if (!insere_Pilha(pi, a)) {
                    printf("Nao foi possivel inserir o aluno na pilha.\n");
                }
                break;
            case 2:
                if (!remove_Pilha(pi)) {
                    printf("Nao foi possivel remover da pilha\n");
                }   
                break;
            case 3:
                if (!consulta_topo_Pilha(pi, &a)) {
                    printf("Não foi possivel consultar o aluno\n");
                    break;
                }
                imprime_aluno_buscado(&a);
                break;
            case 4:
                caso4(pi);
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
    libera_Pilha(pi);
}

void caso4(Pilha *pi) {
    int resp;
    printf("\033[2J\033[H");
    printf("\n================================\n");
    printf("\t      MENU\n");
    printf("<1> : Tamanho da pilha\n");
    printf("<2> : Verificar se a pilha esta cheia\n");
    printf("<3> : Verificar se a pilha esta vazia\n");
    printf("<4> : Verificar se uma sequencia de insercoes e remocoes e correta\n");
    printf("<5> : Verificar se a sequencia de delimitadores esta correta\n");
    printf("<6> : Voltar\n");
    printf("\n================================\n");
    printf("Digite o que voce quer fazer: ");
    scanf("%d", &resp);
    printf("\033[2J\033[H");
    switch (resp) {
        case 1:
            int tam = tamanho_Pilha(pi);
            if (tam != -1) {
                printf("Tamanho da pilha: %d\n", tam);
            } else {
                printf("Pilha nao existe\n");
            }
            break;
        case 2:
            if (Pilha_cheia(pi)) {
                printf("A pilha esta cheia\n");
            } else {
                printf("A pilha nao esta cheia\n");
            }
            break;
        case 3:
            if (Pilha_vazia(pi)) {
                printf("A pilha esta vazia\n");
            } else {
                printf("A pilha nao esta vazia\n");
            }
            break;
        case 4:
            char sequencia[100];
            printf("Digite uma sequencia de insercoes (I) e remocoes (R) sem espacos: ");
            scanf("%s", sequencia);
            if (sequencia_valida(sequencia)) {
                printf("A sequencia e valida\n");
            } else {
                printf("A sequencia nao e valida\n");
            }
            break;
        case 5:
            char expressao[100];
            printf("Digite uma expressao para verificar se os delimitadores estao corretos: ");
            scanf("%s", expressao);
            if (verifica_delimitadores(expressao)) {
                printf("A expressao esta correta\n");
            } else {
                printf("A expressao esta errada\n");
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

int sequencia_valida(const char *s) {
    int tamanho = strlen(s);
    int controle = 0;
    for (int i = 0; i < tamanho; i++) {
        if (s[i] == 'I') {
            controle++;
        } else {
            controle--;
        }
        if (controle < 0) {
            return 0;
        }
    }

    if (controle != 0) return 0;

    return 1;
}

int verifica_delimitadores(const char *expr) {
    int tam_expr = strlen(expr);
    Pilha *pi = cria_Pilha_char(tam_expr);
    if (pi == NULL) return 0;
    char aux;
    for (int i = 0; i < tam_expr; i++) {
        char c = expr[i];
        if (c == '(' || c == '[' || c == '{') {
            insere_Pilha_char(pi, c);
        } else if (c != ')' && c != ']' && c != '}') {
            continue;
        } else {
            if (Pilha_vazia_char(pi)) { 
                libera_Pilha_char(pi);
                return 0;
            }
            if (c == ')') {
                consulta_topo_Pilha_char(pi, &aux);
                if (aux == '(') {
                    remove_Pilha_char(pi);
                } else {
                    libera_Pilha_char(pi);
                    return 0;
                }
            } else if (c == ']') {
                consulta_topo_Pilha_char(pi, &aux);
                if (aux == '[') {
                    remove_Pilha_char(pi);
                } else {
                    libera_Pilha_char(pi);
                    return 0;
                }
            } else if (c == '}') {
                consulta_topo_Pilha_char(pi, &aux);
                if (aux == '{') {
                    remove_Pilha_char(pi);
                } else {
                    libera_Pilha_char(pi);
                    return 0;
                }
            }
        }
    }

    if (Pilha_vazia_char(pi)) {
        libera_Pilha_char(pi);
        return 1;
    } else {
        libera_Pilha_char(pi);
        return 0;
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
}
