#include <stdio.h>
#include <stdlib.h>
#include "PilhaDupla.h"

struct pilha_dupla {
    int qtd1;
    int qtd2;
    int capacidade;
    struct aluno* dados;
};
 
PilhaDupla* cria_PilhaDupla(int capacidade) {
    if (capacidade <= 0) return NULL;
    PilhaDupla *pd = (PilhaDupla*)malloc(sizeof(struct pilha_dupla));
    if (pd == NULL) return NULL;
    pd->dados = (struct aluno*)malloc(capacidade*sizeof(struct aluno));
    if (pd->dados == NULL) {
        free(pd);
        return NULL;
    }
    pd->capacidade = capacidade;
    pd->qtd1 = 0;
    pd->qtd2 = 0;
    return pd;
}

void libera_PilhaDupla(PilhaDupla* pd) {
    if (pd != NULL) {
        free(pd->dados);
        free(pd);
    }
}

int tamanho_PilhaDupla(PilhaDupla* pd, int p) {
    if (pd == NULL) return -1;
    if (p == 1) {
        return pd->qtd1;
    } else if (p == 2) {
        return pd->qtd2;
    } else {
        return -1;
    }
}

int PilhaDupla_cheia(PilhaDupla* pd) {
    if (pd == NULL) return 0;
    return (pd->qtd1 + pd->qtd2 == pd->capacidade);
}

int insere_PilhaDupla(PilhaDupla* pd, int p, struct aluno al) {
    if (pd == NULL) return 0;
    if (PilhaDupla_cheia(pd)) return 0;
    if (p == 1) {
        pd->dados[pd->qtd1] = al;
        pd->qtd1++;
        return 1;
    } else if (p == 2) {
        pd->dados[pd->capacidade - (pd->qtd2 + 1)];
        pd->qtd2++;
        return 1;
    } else {
        return 0;
    }
}

int remove_PilhaDupla(PilhaDupla* pd, int p) {
    if (pd == NULL) return 0;
    if (p == 1) {
        if (pd->qtd1 == 0) return 0;
        pd->qtd1--;
        return 1;
    } else if (p == 2) {
        if (pd->qtd2 == 0) return 0;
        pd->qtd2--;
        return 1;
    } else {
        return 0;
    }
}

int consulta_topo_PilhaDupla(PilhaDupla* pd, int p, struct aluno *al) {
    if (pd == NULL || al == NULL) return 0;
    if (p == 1) {
        if (pd->qtd1 == 0) return 0;
        *al = pd->dados[pd->qtd1-1];
        return 1;
    } else if (p == 2) {
        if (pd->qtd2 == 0) return 0;
        *al = pd->dados[pd->capacidade - pd->qtd2];
        return 1;
    } else {
        return 0;
    }
}
