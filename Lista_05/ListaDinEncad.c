#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "ListaDinEncad.h"

/* Cada elemento guarda os dados e o endereco do proximo elemento.
   O ultimo elemento aponta para NULL. */
struct elemento {
    struct tarefa dados;
    struct elemento *prox;
};
typedef struct elemento Elem;

/* ------------------------------------------------------------
   Criacao e destruicao
   ------------------------------------------------------------ */

ListaTarefas* cria_lista(void) {
    ListaTarefas* li = (ListaTarefas*) malloc(sizeof(ListaTarefas));
    if (li != NULL)
        *li = NULL;               /* lista vazia: o inicio aponta para NULL */
    return li;
}

void libera_lista(ListaTarefas* li) {
    if (li != NULL) {
        Elem* no;
        while ((*li) != NULL) {
            no = *li;
            *li = (*li)->prox;    /* avanca ANTES de liberar */
            free(no);
        }
        free(li);                 /* libera o bloco do inicio */
    }
}

/* ------------------------------------------------------------
   Informacoes de estado
   ------------------------------------------------------------ */
int tamanho_lista(ListaTarefas* li) {
    if (li == NULL)
        return -1;
    int cont = 0;
    Elem* no = *li;
    while (no != NULL) {          /* nao ha campo qtd: e preciso percorrer */
        cont++;
        no = no->prox;
    }
    return cont;
}

int lista_cheia(ListaTarefas* li) {
    if (li == NULL)
        return -1;
    return 0;                     /* so falta memoria quando o malloc falha */
}

int lista_vazia(ListaTarefas* li) {
    if (li == NULL)
        return -1;
    if (*li == NULL)
        return 1;
    return 0;
}

/* ------------------------------------------------------------
   Insercao
   ------------------------------------------------------------ */
int insere_tarefa_inicio(ListaTarefas* li, struct tarefa t) {
    if (li == NULL) return 0;
    Elem* no = (Elem*) malloc(sizeof(Elem));
    if (no == NULL) return 0;     /* falta de memoria: lista cheia */
    no->dados = t;
    no->prox = (*li);             /* 1o: liga o novo no ao antigo primeiro */
    *li = no;                     /* 2o: so entao altera o inicio */
    return 1;
}

int insere_tarefa_final(ListaTarefas* li, struct tarefa t) {
    if (li == NULL) return 0;
    Elem* no = (Elem*) malloc(sizeof(Elem));
    if (no == NULL) return 0;
    no->dados = t;
    no->prox = NULL;              /* o novo no sera o ultimo */
    if ((*li) == NULL) {          /* lista vazia: insere no inicio */
        *li = no;
    } else {
        Elem* aux = *li;
        while (aux->prox != NULL) /* para NO ultimo, e nao depois dele */
            aux = aux->prox;
        aux->prox = no;
    }
    return 1;
}

int insere_tarefa_ordenada(ListaTarefas* li, struct tarefa t) {
    if (li == NULL) return 0;
    Elem* no = (Elem*) malloc(sizeof(Elem));
    if (no == NULL) return 0;
    no->dados = t;
    if ((*li) == NULL) {          /* lista vazia: insere no inicio */
        no->prox = NULL;
        *li = no;
        return 1;
    } else {
        Elem *ant = NULL, *atual = *li;
        /* procura o primeiro elemento com prioridade maior ou igual */
        while (atual != NULL &&
               atual->dados.prioridade < t.prioridade) {
            ant = atual;
            atual = atual->prox;
        }
        if (atual == *li) {       /* insere no inicio */
            no->prox = (*li);
            *li = no;
        } else {                  /* insere entre ant e atual */
            no->prox = atual;
            ant->prox = no;
        }
        return 1;
    }
}

/* ------------------------------------------------------------
   Remocao
   ------------------------------------------------------------ */

int remove_tarefa_inicio(ListaTarefas* li) {
    if (li == NULL) return 0;
    if ((*li) == NULL)            /* lista vazia */
        return 0;
    Elem *no = *li;
    *li = no->prox;               /* religa antes do free */
    free(no);
    return 1;
}

int remove_tarefa_final(ListaTarefas* li) {
    if (li == NULL) return 0;
    if ((*li) == NULL)            /* lista vazia */
        return 0;
    Elem *ant = NULL, *no = *li;
    while (no->prox != NULL) {
        ant = no;
        no = no->prox;
    }
    if (no == (*li))              /* unico elemento: a lista fica vazia */
        *li = no->prox;
    else
        ant->prox = no->prox;     /* o penultimo passa a apontar para NULL */
    free(no);
    return 1;
}

int remove_tarefa(ListaTarefas* li, int codigo) {
    if (li == NULL) return 0;
    if ((*li) == NULL)            /* lista vazia */
        return 0;
    Elem *ant = NULL, *no = *li;
    while (no != NULL && no->dados.codigo != codigo) {
        ant = no;
        no = no->prox;
    }
    if (no == NULL)               /* elemento nao encontrado */
        return 0;
    if (no == *li)                /* remove o primeiro */
        *li = no->prox;
    else
        ant->prox = no->prox;     /* contorna o no removido */
    free(no);
    return 1;
}

/* ------------------------------------------------------------
   Busca
   ------------------------------------------------------------ */

int busca_tarefa_pos(ListaTarefas* li, int pos, struct tarefa *t) {
    if (li == NULL || pos <= 0)
        return 0;
    Elem *no = *li;
    int i = 1;
    while (no != NULL && i < pos) { /* nao ha indice: percorre ate a posicao */
        no = no->prox;
        i++;
    }
    if (no == NULL)               /* posicao maior que o tamanho */
        return 0;
    else {
        *t = no->dados;
        return 1;
    }
}

int busca_tarefa_cod(ListaTarefas* li, int codigo, struct tarefa *t) {
    if (li == NULL)
        return 0;
    Elem *no = *li;
    while (no != NULL && no->dados.codigo != codigo)
        no = no->prox;
    if (no == NULL)               /* elemento nao encontrado */
        return 0;
    else {
        *t = no->dados;
        return 1;
    }
}

// FUNÇÕES NOVAS IMPLEMENTADAS, REQUERIDAS PELA ATIVIDADE

int conta_tarefas_prioridade(ListaTarefas* li, int prioridade) {
    if (li == NULL) return -1;
    if ((*li) == NULL) return 0;
    Elem* no = *li;
    int count = 0;
    while (no != NULL) {
        if (no->dados.prioridade == prioridade) {
            count++;
        }
        no = no->prox;
    }
    return count;
}

int tarefa_mais_urgente(ListaTarefas* li, struct tarefa *t) {
    if (li == NULL) return 0;
    if ((*li) == NULL) return 0;
    Elem* no = *li, *aux = *li;
    int menor = no->dados.prioridade;
    no = no->prox;
    while (no != NULL) {
        if (no->dados.prioridade < menor) {
            menor = no->dados.prioridade;
            aux = no;
        }
        no = no->prox;
    }
    
    *t = aux->dados;
    return 1;
}

int busca_tarefa_desc(ListaTarefas* li, char *texto, struct tarefa *t) {
    if (li == NULL) return 0;
    if ((*li) == NULL) return 0;
    Elem* no = *li;
    while (no != NULL) {
        if (strstr(no->dados.descricao, texto) != NULL) {
            break;
        }
        no = no->prox;
    }
    if (no == NULL) return 0;
    *t = no->dados;
    return 1;
}

int insere_tarefa_final_prioridade(ListaTarefas* li, struct tarefa t) {
    if (li == NULL) return 0;
    Elem* no = *li, *aux = NULL, *ant = NULL;
    Elem* no_inserir = (Elem*)malloc(sizeof(Elem));
    if (no_inserir == NULL) return 0;
    no_inserir->dados = t;
    if ((*li) == NULL) {
        no_inserir->prox = (*li);
        *li = no_inserir;
        return 1;
    }
    int prd = t.prioridade, flag = 0;
    while (no != NULL) {
        if (flag == 1) {
            if (no->dados.prioridade != prd) {
                break;
            }
        }
        if (no->dados.prioridade == prd) {
            aux = no;
            flag = 1;
        }
        ant = no;
        no = no->prox;
    }
    if (no == NULL) {
        ant->prox = no_inserir;
        no_inserir->prox = NULL;
    }
    no_inserir->prox = no;
    ant->prox = no_inserir;
    return 1;
}

int remove_tarefas_prioridade(ListaTarefas* li, int prioridade) {
    if (li == NULL) return -1;
    if ((*li) == NULL) return 0;
    Elem *no = *li, *ant = *li, *aux = NULL;
    int count = 0;
    while (no != NULL) {
        if (no->dados.prioridade == prioridade) {
            if (no == *li) {
                aux = no;
                no = no->prox;
                *li = no;
                free(aux);
            } else {
                aux = no;
                ant->prox = no->prox;
                no = no->prox;
                free(aux);
            }
            count++;
            continue;
        }
        ant = no;
        no = no->prox;
    }
    return count;
}

int inverte_lista(ListaTarefas* li) {
    if (li == NULL) return 0;
    if ((*li) == NULL) return 1;
    Elem *no = (*li), *ant = NULL, *aux = (*li);
    if (no->prox == NULL) return 1;
    ant = no;
    no = no->prox;
    aux->prox = NULL;
    while (no != NULL) {
        aux = no;
        no = no->prox;
        aux->prox = ant;
        ant = aux;
    }
    *li = ant;
    return 1;
}

int remove_tarefa_pos(ListaTarefas* li, int pos) {
    if (li == NULL || pos <= 0) return 0;
    if ((*li) == NULL) return 0;
    Elem *no = (*li), *ant = NULL;
    int i = 1;
    while (no != NULL && i < pos) {
        ant = no;
        no = no->prox;
        i++;
    }
    if (no == (*li)) {
        *li = NULL;
        return 1;
    }
    if (no == NULL) return 0;
    ant->prox = no->prox;
    free(no);
    return 1;
}

int mescla_tarefas(ListaTarefas* dst, ListaTarefas* src) {
    if (dst == NULL || src == NULL) return -1;
    if ((*src) == NULL) return 0;
    if ((*dst) == NULL) {
        *dst = *src;
    } else {
        Elem *no = (*dst);
        while (no->prox != NULL) {
            no = no->prox;
        }
        no->prox = (*src);
    }
    Elem *no2 = (*src);
    int count = 0;
    while (no2 != NULL) {
        no2 = no2->prox;
        count++;
    }
    *src = NULL;
    return count;
}

// FUNÇÕES IMPLEMENTADAS A PARTE:

void printar_tarefa(struct tarefa *t) {
    printf("\033[2J\033[H");
    printf("\n================================\n");
    printf("Codigo da tarefa buscada: %d\n", t->codigo);
    printf("Descricao da tarefa buscada: %s\n", t->descricao);
    printf("Prioridade da tarefa buscada: %d\n", t->prioridade);
    printf("\n================================\n");
    printf("Pressione Qualquer tecla para continuar: ");
    getchar();
    getchar();
}

void printar_lista(ListaTarefas *li) {
    if (li == NULL) return;
    printf("\033[2J\033[H");
    printf("\n================================\n");
    Elem *no = (*li);
    int i = 1;
    while (no != NULL) {
        printf("Codigo da %d tarefa: %d\n", i, no->dados.codigo);
        printf("Descricao da %d tarefa: %s\n", i, no->dados.descricao);
        printf("Prioridade da %d tarefa: %d\n", i, no->dados.prioridade);
        no = no->prox;
        i++;
        printf("\n");
    }
    printf("\n================================\n");
    printf("Pressione Qualquer tecla para continuar: ");
    getchar();
    getchar();
}