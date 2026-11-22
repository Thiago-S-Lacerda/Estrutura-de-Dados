#ifndef PILHA_DUPLA_H
#define PILHA_DUPLA_H

struct aluno {
    int   matricula;
    char  nome[30];
    float n1, n2, n3;
};

typedef struct pilha_dupla PilhaDupla;

/* Aloca a estrutura da pilha e um vetor com 'capacidade' posicoes.
   Devolve o ponteiro da pilha, ou NULL se capacidade <= 0 ou se
   qualquer uma das duas alocacoes falhar. */
PilhaDupla* cria_PilhaDupla(int capacidade);

/* Libera o vetor de dados e, em seguida, a estrutura da pilha. */
void libera_PilhaDupla(PilhaDupla* pd);

/* Devolve a quantidade de elementos da pilha p (1 ou 2), ou -1 se pd for NULL. */
int tamanho_PilhaDupla(PilhaDupla* pd, int p);

/* Devolve 1 se a pilha esta cheia, 0 caso contrario, -1 se pd for NULL. */
int PilhaDupla_cheia(PilhaDupla* pd);

/* Devolve 1 se a pilha esta vazia, 0 caso contrario, -1 se pd for NULL. */
int PilhaDupla_vazia(PilhaDupla *pd);

/* Insere no topo da pilha p (1 ou 2) (empilha). Falha se a pilha for invalida
   ou estiver cheia. Custo O(1). */
int insere_PilhaDupla(PilhaDupla* pd, int p, struct aluno al);

/* Remove o elemento do topo da pilha p (1 ou 2) (desempilha). Falha se a pilha
   for invalida ou estiver vazia. Custo O(1). */
int remove_PilhaDupla(PilhaDupla* pd, int p);

/* Copia para *al o elemento do topo da pilha p (1 ou 2), sem remove-lo. Falha se a
   pilha for invalida ou estiver vazia. Custo O(1). */
int consulta_topo_PilhaDupla(PilhaDupla* pd, int p, struct aluno *al);

#endif