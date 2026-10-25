/* ============================================================
   ListaDinEncadCirc.h
   Estrutura de Dados I - UFPB - Aula 07
   Lista dinamica encadeada circular

   Referencia: BACKES, A. R. Algoritmos e Estruturas de Dados em
   Linguagem C. Rio de Janeiro: LTC, 2023. Capitulo 5.

   Este arquivo declara tudo o que e visivel para quem usa a
   biblioteca. A definicao de struct elemento fica oculta em
   ListaDinEncadCirc.c: Lista e um tipo opaco.

   A DIFERENCA PARA A LISTA DINAMICA ENCADEADA DA AULA 06 NAO
   ESTA AQUI. Os tipos sao identicos: um elemento continua tendo
   um campo de dado e um campo prox. O que muda e a implementacao
   das funcoes, porque o campo prox do ultimo elemento guarda o
   endereco do primeiro, e nao a constante NULL.

   Consequencia pratica para quem for estender esta biblioteca:
   nenhum percurso pode terminar comparando prox com NULL. Todo
   percurso para ao voltar ao inicio da lista, (*li).
   ============================================================ */

#ifndef LISTA_DIN_ENCAD_CIRC_OTM_H
#define LISTA_DIN_ENCAD_CIRC_OTM_H

/* Tipo do dado armazenado na lista. */
struct aluno {
    int matricula;
    char nome[30];
    float n1, n2, n3;
};

/* Tipo opaco. Lista ja inclui um ponteiro (struct elemento*), de modo que
   Lista* e um ponteiro para ponteiro: o usuario declara Lista *li, e as
   funcoes podem alterar o inicio da lista alterando o conteudo de *li. */
typedef struct elemento* Lista;

/* --- criacao e destruicao ---------------------------------- */

/* Aloca o bloco do inicio e o inicializa com NULL (lista vazia).
   Devolve o ponteiro da lista, ou NULL se a alocacao falhar.
   Identica a da lista nao circular: a circularidade so aparece
   a partir da primeira insercao. */
Lista* cria_lista(void);

/* lfbera todos os elementos e, por fim, o bloco do inicio.
   O percurso para quando o elemento seguinte ao atual e o inicio
   da lista, e nao quando encontra NULL. Custo O(n). */
void libera_lista(Lista* lf);

/* --- informacoes de estado --------------------------------- */

/* Devolve a quantidade de elementos; devolve 0 se li for NULL ou
   se a lista estiver vazia. Usa do-while: em um while a condicao
   de parada ja seria falsa na primeira avaliacao. Custo O(n). */
int tamanho_lista(Lista* lf);

/* Devolve sempre 0. Uma lista com alocacao dinamica so fica cheia
   quando falta memoria para o malloc, o que e detectado dentro das
   funcoes de insercao. */
int lista_cheia(Lista* lf);

/* Devolve 1 se a lista estiver vazia ou se li for NULL (lista
   invalida), 0 caso contrario. */
int lista_vazia(Lista* lf);

/* --- insercao ----------------------------------------------
   Todas devolvem 1 em caso de sucesso e 0 caso contrario
   (lista invalida ou falta de memoria).

   Em uma lista circular, inserir no inicio e inserir no final
   colocam o novo elemento na MESMA posicao fisica: entre o
   ultimo e o primeiro. A unica diferenca entre as duas funcoes
   e a atribuicao final *lf = no, presente apenas na insercao
   no final. ------------------------------------------------ */

/* Insere depois do final. Custo O(1) */
int insere_lista_inicio(Lista* lf, struct aluno al);

/* Insere depois do final. Custo O(1). */
int insere_lista_final(Lista* lf, struct aluno al);

/* Insere mantendo a lista ordenada de forma crescente por
   matricula. O ponto de insercao pode ser no inicio, no meio ou
   no final. Custo O(n). */
int insere_lista_ordenada(Lista* lf, struct aluno al);

/* --- remocao -----------------------------------------------
   Todas devolvem 1 em caso de sucesso e 0 caso contrario
   (lista invalida, lista vazia ou elemento inexistente).

   As tres tratam antes de tudo o caso do elemento unico, que e
   reconhecido pelo teste (*lf) == (*lf)->prox: o no aponta para
   si mesmo e a lista fica vazia apos a remocao. -------------- */

/* Usa o ponteiro armazenando o final da lista e remove o inicio. Custo O(1) */
int remove_lista_inicio(Lista* lf);

/* Percorre a lista mantendo o antecessor, remove o ultimo e
   religa o antecessor ao inicio. Custo O(n). */
int remove_lista_final(Lista* lf);

/* Remove o elemento de matricula igual a passada, esteja ele no
   inicio, no meio ou no final. Custo O(n). */
int remove_lista(Lista* lf, int mat);

/* --- busca -------------------------------------------------
   Copiam o elemento encontrado para *al e devolvem 1; devolvem 0
   quando a busca falha.

   As duas tem duas condicoes de parada: encontrar o que se
   procura e completar uma volta na lista. Omitir a segunda
   transforma a busca de uma chave ausente em laco infinito. -- */

/* Busca pela posicao na lista, contada a partir de 1 no inicio.
   Posicoes maiores que o numero de elementos devolvem 0.
   Custo O(n). */
int busca_lista_pos(Lista* lf, int pos, struct aluno *al);

/* Busca pelo conteudo do campo matricula. Custo O(n). */
int busca_lista_mat(Lista* lf, int mat, struct aluno *al);

// Funções implementadas requeridas pela atividade:

/* Imprime todos os elementos da lista. Custo O(n)*/
void imprime_lista(Lista* lf);

/* Imprime a maior matricula presente na lista. Custo O(n)*/
int maior_matricula(Lista* lf, int *mat);

/* Imprime a quantidade de alunos na lista que possuem uma media maior ou igual a 7. Custo O(n)*/
int conta_aprovados(Lista* lf); 

/* Busca um elemento dentro da lista, permitindo ultrapassar a quantidade de elementos (dá voltas na lista
aproveitando a circularidade). Para k maior que o numero de elementos da lista, o custo é O(n)*/
int busca_ciclica(Lista* lf, int k, struct aluno *al);

/* Remove o elemento da posição passada da lista. Custo O(n)*/
int remove_lista_pos(Lista* lf, int pos);

/* Muda o inicio da lista para a posicao k+1. Para k maior que o numero de elementos da lista
o custo é O(n)*/
int rotaciona_lista(Lista* lf, int k);

/* Junta as duas listas passadas na primeira lista e esvazia a segunda lista. Custo O(1)*/
int concatena_listas(Lista* lf1, Lista* lf2);

/* Resolve o problema de josephus e imprime a ultima matricula restante da lista (
ao final esvazia a lista). Custo O(n)*/
int josephus(Lista* lf, int k, int *sobrevivente);

/* Cria um aluno, pedindo que o usuario digite os campos*/
void criar_aluno(struct aluno *al);

/* Imprime os campos do aluno buscado*/
void imprime_aluno_buscado(struct aluno *al);

#endif
