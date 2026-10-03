#include "menu.h"
#include "lista.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void menu() {
    int resp;
    int sistema = 1;
    Lista *li = cria_lista();
    struct produto p;
    if (li == NULL) {
        printf("Não foi possivel criar a lista");
        return;
    }
    
    printf("\033[2J\033[H");

    while (sistema) {
        printf("\n================\n");
        printf("\tMENU\n");
        printf("<1> : Adicionar produto na lista\n");
        printf("<2> : Remover produto na lista\n");
        printf("<3> : Buscar item na lista\n");
        printf("<4> : Funcoes Gerais\n");
        printf("<5> : Encerrar Programa\n");
        printf("\n================\n");
        printf("Digite o que voce quer fazer: ");
        scanf("%d", &resp);
        switch (resp) {
            case 1:
                caso1(li, p);
                break;
            case 2:
                caso2(li);
                break;
            case 3:
                caso3(li, &p);
                break;
            case 4:
                caso4(li, &p);
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

void caso1(Lista *li, struct produto p) {
    int resp;
    int codigo = 0;
    float preco = 0;
    char nome[30];
    printf("\033[2J\033[H");
    printf("\n================\n");
    printf("\tMENU\n");
    printf("<1> : Inserir no final\n");
    printf("<2> : Inserir no inicio\n");
    printf("<3> : Inserir ordenado\n");
    printf("<4> : Inserir ordenado decrescente\n");
    printf("<5> : Voltar\n");
    printf("\n================\n");
    printf("Digite o que voce quer fazer: ");
    scanf("%d", &resp);
    printf("\033[2J\033[H");
    switch (resp) {
        case 1:
            printf("Digite o nome do produto: ");
            scanf("%s", nome);
            printf("Digite o codigo do produto: ");
            scanf("%d", &codigo);
            printf("Digite o preco do produto: ");
            scanf("%f", &preco);
            p.codigo = codigo;
            p.preco = preco;
            strcpy(p.nome, nome);
            insere_lista_final(li, p);
            break;
        case 2:
            printf("Digite o nome do produto: ");
            scanf("%s", nome);
            printf("Digite o codigo do produto: ");
            scanf("%d", &codigo);
            printf("Digite o preco do produto: ");
            scanf("%f", &preco);
            p.codigo = codigo;
            p.preco = preco;
            strcpy(p.nome, nome);
            insere_lista_inicio(li, p);
            break;
        case 3:
            printf("Digite o nome do produto: ");
            scanf("%s", nome);
            printf("Digite o codigo do produto: ");
            scanf("%d", &codigo);
            printf("Digite o preco do produto: ");
            scanf("%f", &preco);
            p.codigo = codigo;
            p.preco = preco;
            strcpy(p.nome, nome);
            insere_lista_ordenada(li, p);
            break;
        case 4:
            printf("Digite o nome do produto: ");
            scanf("%s", nome);
            printf("Digite o codigo do produto: ");
            scanf("%d", &codigo);
            printf("Digite o preco do produto: ");
            scanf("%f", &preco);
            p.codigo = codigo;
            p.preco = preco;
            strcpy(p.nome, nome);
            insere_lista_decrescente(li, p);
            break;
        default:
            if (resp != 5) {
                printf("\033[2J\033[H");
                printf("Digito Invalido\n");
            }
            break;
    }
}

void caso2(Lista *li) {
    int resp;
    printf("\033[2J\033[H");
    printf("\n================\n");
    printf("\tMENU\n");
    printf("<1> : Remover no final\n");
    printf("<2> : Remover no inicio\n");
    printf("<3> : Remover por codigo especifico\n");
    printf("<4> : Remover mais caro\n");
    printf("<5> : Remover abaixo de certo preco\n");
    printf("<6> : Voltar\n");
    printf("\n================\n");
    printf("Digite o que voce quer fazer: ");
    scanf("%d", &resp);
    printf("\033[2J\033[H");
    switch (resp) {
        case 1:
            remove_lista_final(li);
            break;
        case 2:
            remove_lista_inicio(li);
            break;
        case 3:
            int cod;
            printf("Digite o codigo do produto a ser removido: ");
            scanf("%d", &cod);
            remove_lista_otimizado(li, cod);
            break;
        case 4:
            struct produto *p2 = malloc(sizeof(struct produto));
            remove_mais_caro(li, p2);
            printar_produto(p2);
            free(p2);
            p2 = NULL;
        case 5:
            float preco;
            printf("Digite o preco do produto a ser removido: ");
            scanf("%f", &preco);
            remove_abaixo_de(li, preco);
        default:
            if (resp != 6) {
                printf("\033[2J\033[H");
                printf("Digito Invalido\n");
            }
            break;
    }
}

void caso3(Lista *li, struct produto *p) {
    int resp;
    printf("\033[2J\033[H");
    printf("\n================\n");
    printf("\tMENU\n");
    printf("<1> : Buscar por posicao\n");
    printf("<2> : Buscar por codigo\n");
    printf("<3> : Buscar por nome\n");
    printf("<4> : Voltar\n");
    printf("\n================\n");
    printf("Digite o que voce quer fazer: ");
    scanf("%d", &resp);
    printf("\033[2J\033[H");
    switch (resp) {
        case 1:
            int pos;
            printf("Digite a posicao a ser buscada: ");
            scanf("%d", &pos);
            busca_lista_pos(li, pos, p);
            printf("Nome do produto buscado: %s\n", p->nome);
            printf("Codigo do produto buscado: %d\n", p->codigo);
            printf("Preco do produto buscado: %.2f", p->preco);
            break;
        case 2:
            int cod;
            printf("Digite o codigo a ser buscado: ");
            scanf("%d", &cod);
            busca_lista_cod(li, cod, p);
            printf("Nome do produto buscado: %s\n", p->nome);
            printf("Codigo do produto buscado: %d\n", p->codigo);
            printf("Preco do produto buscado: %.2f", p->preco);
            break;
        case 3:
            char nome[30];
            printf("Digite o nome do produto a ser buscado: ");
            scanf("%s", nome);
            busca_por_nome(li, nome, p);
            printf("Nome do produto buscado: %s\n", p->nome);
            printf("Codigo do produto buscado: %d\n", p->codigo);
            printf("Preco do produto buscado: %.2f", p->preco);
            break;
        default:
            if (resp != 4) {
                printf("\033[2J\033[H");
                printf("Digito invalido\n");
            }
            break;
    }
}

void caso4(Lista *li, struct produto *p) {
    int resp;
    printf("\033[2J\033[H");
    printf("\n================\n");
    printf("\tMENU\n");
    printf("<1> : Tamanho da lista\n");
    printf("<2> : Verificar se tem espaco na lista\n");
    printf("<3> : Soma dos precos de todos os produtos da lista\n");
    printf("<4> : Verificar quantos produtos tem em certa faixa de preco\n");
    printf("<5> : Verificar se a lista esta vazia\n");
    printf("<6> : Mesclar duas listas\n");
    printf("<7> : Printar toda a lista\n");
    printf("<8> : Voltar");
    printf("\n================\n");
    printf("Digite o que voce quer fazer: ");
    scanf("%d", &resp);
    printf("\033[2J\033[H");
    switch (resp) {
        case 1:
            int tam = tamanho_lista(li);
            if (tam != -1) {
                printf("Tamanho da lista: %d", tam);
            } else {
                printf("Lista nao existe");
            }
            break;
        case 2:
            int n;
            printf("Digite a quantidade de valores que voce quer para saber se ainda tera espaco: ");
            scanf("%d", &n);
            if (lista_tem_espaco(li, n)) {
                printf("A lista tem espaco\n");
            } else {
                printf("A lista nao tem espaco\n");
            }
            break;
        case 3:
            printf("A soma dos precos e: %.2f", soma_precos(li));
            break;
        case 4:
            float min, max;
            printf("Digite o preco minimo: ");
            scanf("%f", &min);
            printf("Digite o preco maximo: ");
            scanf("%f", &max);
            printf("A quantidade de produtos nessa faixa de preco e: %d", conta_faixa_preco(li, min, max));
            break;
        case 5:
            if (lista_vazia(li)) {
                printf("A lista esta vazia\n");
            } else {
                printf("A lista nao esta vazia\n");
            }
            break;
        case 6:
            p->codigo = 1010;
            strcpy(p->nome, "Arroz");
            p->preco = 7.9f;
            Lista *li2 = cria_lista();
            insere_lista_final(li2, *p);
            p->codigo = 1011;
            strcpy(p->nome, "Feijao");
            p->preco = 9.99f;
            insere_lista_final(li2, *p);
            mescla_listas(li, li2);
            libera_lista(li2);
            li2 = NULL;
            printar_lista(li);
            break;
        case 7:
            printar_lista(li);
            break;
        default:
            if (resp != 8) {
                printf("\033[2J\033[H");
                printf("Digito invalido\n");
                break;
            }
    }
}