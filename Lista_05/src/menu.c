#include "menu.h"
#include "ListaDinEncad.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void menu() {
    int resp;
    int sistema = 1;
    ListaTarefas *li = cria_lista();
    ListaTarefas *li2 = cria_lista();
    
    struct tarefa t, t2;
    if (li == NULL || li2 == NULL) {
        printf("Não foi possivel criar a lista");
        return;
    }

    t2.codigo = 10;
    strcpy(t2.descricao, "Fazer a atividade da CortechX");
    t2.prioridade = 2;
    if (!insere_tarefa_ordenada(li2, t2)) {
        libera_lista(li);
        libera_lista(li2);
        return;
    }
    t2.codigo = 11;
    strcpy(t2.descricao, "Estudar para Estrutura de Dados");
    t2.prioridade = 1;
    if (!insere_tarefa_ordenada(li2, t2)) {
        libera_lista(li);
        libera_lista(li2);
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
                caso1(li, t);
                break;
            case 2:
                caso2(li);
                break;
            case 3:
                caso3(li, &t);
                break;
            case 4:
                caso4(li, li2, &t);
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

void caso1(ListaTarefas *li, struct tarefa t) {
    int resp;
    int codigo = 0;
    int prioridade = 0;
    char descricao[40];
    printf("\033[2J\033[H");
    printf("\n================================\n");
    printf("\t      MENU\n");
    printf("<1> : Inserir no final\n");
    printf("<2> : Inserir no inicio\n");
    printf("<3> : Inserir ordenado\n");
    printf("<4> : Inserir pela prioridade (insere ao final dos produtos com a mesma prioridade)\n");
    printf("<5> : Voltar\n");
    printf("\n================================\n");
    printf("Digite o que voce quer fazer: ");
    scanf("%d", &resp);
    printf("\033[2J\033[H");
    switch (resp) {
        case 1:
            printf("Digite o codigo do produto: ");
            scanf("%d", &codigo);
            getchar();
            printf("Digite a descricao do produto: ");
            fgets(descricao, sizeof(descricao), stdin);
            descricao[strcspn(descricao, "\r\n")] = '\0';
            printf("Digite a prioridade do produto: ");
            scanf("%d", &prioridade);
            t.codigo = codigo;
            strcpy(t.descricao, descricao);
            t.prioridade = prioridade;
            if (!insere_tarefa_final(li, t)) {
                printf("Nao foi possivel inserir na lista\n");
            }
            break;
        case 2:
            printf("Digite o codigo do produto: ");
            scanf("%d", &codigo);
            getchar();
            printf("Digite a descricao do produto: ");
            fgets(descricao, sizeof(descricao), stdin);
            descricao[strcspn(descricao, "\r\n")] = '\0';
            printf("Digite a prioridade do produto: ");
            scanf("%d", &prioridade);
            t.codigo = codigo;
            strcpy(t.descricao, descricao);
            t.prioridade = prioridade;
            if (!insere_tarefa_inicio(li, t)) {
                printf("Nao foi possivel inserir na lista\n");
            }
            break;
        case 3:
            printf("Digite o codigo do produto: ");
            scanf("%d", &codigo);
            getchar();
            printf("Digite a descricao do produto: ");
            fgets(descricao, sizeof(descricao), stdin);
            descricao[strcspn(descricao, "\r\n")] = '\0';
            printf("Digite a prioridade do produto: ");
            scanf("%d", &prioridade);
            t.codigo = codigo;
            strcpy(t.descricao, descricao);
            t.prioridade = prioridade;
            if (!insere_tarefa_ordenada(li, t)) {
                printf("Nao foi possivel inserir na lista\n");
            }
            break;
        case 4:
            printf("Digite o codigo do produto: ");
            scanf("%d", &codigo);
            getchar();
            printf("Digite a descricao do produto: ");
            fgets(descricao, sizeof(descricao), stdin);
            descricao[strcspn(descricao, "\r\n")] = '\0';
            printf("Digite a prioridade do produto: ");
            scanf("%d", &prioridade);
            t.codigo = codigo;
            strcpy(t.descricao, descricao);
            t.prioridade = prioridade;
            if (!insere_tarefa_final_prioridade(li, t)) {
                printf("Nao foi possivel inserir na lista\n");
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

void caso2(ListaTarefas *li) {
    int resp;
    printf("\033[2J\033[H");
    printf("\n================================\n");
    printf("\t      MENU\n");
    printf("<1> : Remover no final\n");
    printf("<2> : Remover no inicio\n");
    printf("<3> : Remover por codigo especifico\n");
    printf("<4> : Remover todos de uma prioridade especifica\n");
    printf("<5> : Remover por posicao\n");
    printf("<6> : Voltar\n");
    printf("\n================================\n");
    printf("Digite o que voce quer fazer: ");
    scanf("%d", &resp);
    printf("\033[2J\033[H");
    switch (resp) {
        case 1:
            if (!remove_tarefa_final(li)) {
                printf("Nao foi possivel remover da lista\n");
            }   
            break;
        case 2:
            if (!remove_tarefa_inicio(li)) {
                printf("Nao foi possivel remover da lista\n");
            }
            break;
        case 3:
            int cod;
            printf("Digite o codigo do produto a ser removido: ");
            scanf("%d", &cod);
            if (!remove_tarefa(li, cod)) {
                printf("Nao foi possivel remover da lista\n");
            }
            break;
        case 4:
            int prd = 0;
            printf("Digite a prioridade que voce quer retirar: ");
            scanf("%d", &prd);
            printf("%d tarefas de prioridade %d foram removidas\n", remove_tarefas_prioridade(li, prd), prd);
            break;
        case 5:
            int pos;
            printf("Digite a posicao que voce quer remover: ");
            scanf("%d", &pos);
            if (!remove_tarefa_pos(li, pos)) {
                printf("Nao foi possivel remover da lista\n");
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

void caso3(ListaTarefas *li, struct tarefa *t) {
    int resp;
    printf("\033[2J\033[H");
    printf("\n================================\n");
    printf("\t      MENU\n");
    printf("<1> : Buscar por posicao\n");
    printf("<2> : Buscar por codigo\n");
    printf("<3> : Buscar pela descricao (SubString)\n");
    printf("<4> : Voltar\n");
    printf("\n================================\n");
    printf("Digite o que voce quer fazer: ");
    scanf("%d", &resp);
    printf("\033[2J\033[H");
    switch (resp) {
        case 1:
            int pos;
            printf("Digite a posicao a ser buscada: ");
            scanf("%d", &pos);
            if (busca_tarefa_pos(li, pos, t)) {
                printar_tarefa(t);
            } else {
                printf("Posicao invalida");
            }
            break;
        case 2:
            int cod;
            printf("Digite o codigo a ser buscado: ");
            scanf("%d", &cod);
            if (busca_tarefa_cod(li, cod, t)) {
                printar_tarefa(t);
            } else {
                printf("Produto nao encontrado");
            }
            break;
        case 3:
            char descricao[30];
            printf("Digite a descricao da tarefa a ser buscado (Nao precisa ser tudo igual): ");
            getchar();
            fgets(descricao, sizeof(descricao), stdin);
            descricao[strcspn(descricao, "\r\n")] = '\0';
            if (busca_tarefa_desc(li, descricao, t)) {
                printar_tarefa(t);
            } else {
                printf("Produto nao encontrado");
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

void caso4(ListaTarefas *li, ListaTarefas *li2, struct tarefa *t) {
    int resp;
    printf("\033[2J\033[H");
    printf("\n================================\n");
    printf("\t      MENU\n");
    printf("<1> : Tamanho da lista\n");
    printf("<2> : Verificar se a lista esta cheia\n");
    printf("<3> : Verificar a quantidade de tarefas de determinada prioridade\n");
    printf("<4> : Verificar qual e a tarefa mais urgente (o menor numero)\n");
    printf("<5> : Verificar se a lista esta vazia\n");
    printf("<6> : Inverte a lista\n");
    printf("<7> : Mesclar duas listas\n");
    printf("<8> : Printar toda a lista\n");
    printf("<9> : Voltar\n");
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
            int prd = -1;
            printf("Digite a prioridade: ");
            scanf("%d", &prd);
            int quant = conta_tarefas_prioridade(li, prd);
            if (quant != -1) {
                printf("A quantidade de tarefas que possuem a prioridade '%d' e: %d\n", prd, quant);
            } else {
                printf("Falha na criacao da lista\n");
            }
            break;
        case 4:
            if (tarefa_mais_urgente(li, t)) {
                printf("Codigo da tarefa buscada: %d\n", t->codigo);
                printf("Descricao da tarefa buscada: %s\n", t->descricao);
                printf("Prioridade da tarefa buscada: %d\n", t->prioridade);
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
            if (!inverte_lista(li)) {
                printf("Nao foi possivel inverter a lista\n");
            }
            break;
        case 7:
            int count = mescla_tarefas(li, li2);
            if (quant != -1) {
                printf("%d tarefas foram mescladas\n", quant);
                printf("Lista depois da mesclagem: \n\n");
                printar_lista(li);
            } else {
                printf("Nao foi possivel realizar essa operacao\n");
            }
            break;
        case 8:
            printar_lista(li);
            break;
        default:
            if (resp != 9) {
                printf("\033[2J\033[H");
                printf("Digito invalido\n");
                break;
            }
    }
}