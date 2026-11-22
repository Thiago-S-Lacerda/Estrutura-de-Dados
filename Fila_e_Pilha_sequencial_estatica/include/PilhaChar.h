#ifndef PILHA_CHAR_H
#define PILHA_CHAR_H

/* Tipo opaco: o usuario da biblioteca so pode declarar Pilha *pi. */
typedef struct pilha Pilha;

/* --- criacao e destruicao ---------------------------------- */

/* Aloca a estrutura da pilha e um vetor com 'capacidade' posicoes.
   Devolve o ponteiro da pilha, ou NULL se capacidade <= 0 ou se
   qualquer uma das duas alocacoes falhar. */
Pilha* cria_Pilha_char(int capacidade);

/* Libera o vetor de dados e, em seguida, a estrutura da pilha. */
void libera_Pilha_char(Pilha* pi);

/* --- informacoes de estado --------------------------------- */

/* Devolve a quantidade de elementos, ou -1 se pi for NULL. */
int tamanho_Pilha_char(Pilha* pi);

/* Devolve 1 se a pilha esta cheia, 0 caso contrario, -1 se pi for NULL. */
int Pilha_cheia_char(Pilha* pi);

/* Devolve 1 se a pilha esta vazia, 0 caso contrario, -1 se pi for NULL. */
int Pilha_vazia_char(Pilha* pi);

/* --- operacoes da pilha -------------------------------------
   Todas acontecem no topo, isto e, na posicao qtd - 1 do vetor.
   Devolvem 1 em caso de sucesso e 0 caso contrario. ---------- */

/* Insere no topo da pilha (empilha). Falha se a pilha for invalida
   ou estiver cheia. Custo O(1). */
int insere_Pilha_char(Pilha* pi, char c);

/* Remove o elemento do topo da pilha (desempilha). Falha se a pilha
   for invalida ou estiver vazia. Custo O(1). */
int remove_Pilha_char(Pilha* pi);

/* Copia para *al o elemento do topo, sem remove-lo. Falha se a
   pilha for invalida ou estiver vazia. Custo O(1). */
int consulta_topo_Pilha_char(Pilha* pi, char *c);


#endif /* PILHA_SEQUENCIAL_H */
