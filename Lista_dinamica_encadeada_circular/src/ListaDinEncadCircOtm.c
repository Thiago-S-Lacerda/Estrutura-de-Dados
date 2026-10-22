/* ============================================================
   ListaDinEncadCirc.c
   Estrutura de Dados I - UFPB - Aula 07
   Lista dinamica encadeada circular

   Implementacao identica a apresentada nos slides da Aula 07.
   A definicao de struct elemento esta aqui, e nao no .h: e isso
   que torna Lista um tipo opaco. Quem usa a biblioteca enxerga
   apenas Lista* e os prototipos declarados no cabecalho.

   Qualquer funcao nova que precise percorrer a lista no a no
   tem de ser escrita NESTE arquivo, porque e aqui que os campos
   dados e prox sao visiveis.
   ============================================================ */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/ListaDinEncadCircOtm.h"

/* Definicao do tipo lista: oculta de quem usa a biblioteca. */
struct elemento {
    struct aluno dados;
    struct elemento *prox;
};
typedef struct elemento Elem;

/* --- criacao e destruicao ---------------------------------- */

Lista* cria_lista(void) {
    Lista* lf = (Lista*) malloc(sizeof(Lista));
    if (lf != NULL)
        *lf = NULL;
    return lf;
}

void libera_lista(Lista* lf) {
    if (lf == NULL)
        return;
    if ((*lf) != NULL) {
        Elem *aux, *no = *lf;
        /* para quando o seguinte ao atual e o inicio: uma volta completa */
        while ((*lf) != no->prox) {
            aux = no;
            no = no->prox;   /* avanca antes de liberar */
            free(aux);
        }
        free(no);
    }
    free(lf);              /* libera o bloco do inicio */
}

/* --- informacoes de estado --------------------------------- */

int tamanho_lista(Lista* lf) {
    if (lf == NULL || (*lf) == NULL)
        return 0;
    int cont = 0;
    Elem* no = *lf;
    do {                    /* do-while: o primeiro elemento tem de ser contado */
        cont++;
        no = no->prox;
    } while (no != (*lf));
    return cont;
}

int lista_cheia(Lista* lf) {
    (void) lf;              /* parametro mantido por simetria com as demais */
    return 0;
}

int lista_vazia(Lista* lf) {
    if (lf == NULL)
        return 1;           /* lista invalida */
    if (*lf == NULL)
        return 1;           /* nenhum elemento alocado */
    return 0;
}

/* --- insercao ---------------------------------------------- */

int insere_lista_inicio(Lista* lf, struct aluno al) {
    if (lf == NULL)
        return 0;
    Elem *no = (Elem*) malloc(sizeof(Elem));
    if (no == NULL)
        return 0;           /* sem memoria: a lista esta cheia */
    no->dados = al;
    if ((*lf) == NULL) {    /* lista vazia: o no aponta para si mesmo */
        *lf = no;
        no->prox = no;
    } else {
        Elem *aux = (*lf)->prox;
        (*lf)->prox = no;
        no->prox = aux;
    }
    return 1;
}

int insere_lista_final(Lista* lf, struct aluno al) {
    if (lf == NULL)
        return 0;
    Elem *no = (Elem*) malloc(sizeof(Elem));
    if (no == NULL)
        return 0;
    no->dados = al;
    if ((*lf) == NULL) {    /* lista vazia: o no aponta para si mesmo */
        *lf = no;
        no->prox = no;
    } else {
        Elem *aux = (*lf)->prox;
        (*lf)->prox = no;
        no->prox = aux;
        (*lf) = no;
    }
    return 1;
}

int insere_lista_ordenada(Lista* lf, struct aluno al) {
    if (lf == NULL)
        return 0;
    Elem *no = (Elem*) malloc(sizeof(Elem));
    if (no == NULL)
        return 0;
    no->dados = al;
    if ((*lf) == NULL) {    /* lista vazia */
        *lf = no;
        no->prox = no;
        return 1;
    }
    if ((*lf)->dados.matricula > al.matricula) {   /* insercao no inicio */
        Elem *atual = *lf;
        while (atual->prox != (*lf))               /* procura o ultimo */
            atual = atual->prox;
        no->prox = *lf;
        atual->prox = no;
        *lf = no;
        return 1;
    }
    /* insercao no meio ou no final: ant acompanha atual uma posicao atras */
    Elem *ant = *lf, *atual = (*lf)->prox;
    while (atual != (*lf) && atual->dados.matricula < al.matricula) {
        ant = atual;
        atual = atual->prox;
    }
    ant->prox = no;
    no->prox = atual;
    return 1;
}

/* --- remocao ----------------------------------------------- */

int remove_lista_inicio(Lista* lf) {
    if (lf == NULL)
        return 0;
    if ((*lf) == NULL)
        return 0;           /* lista vazia */
    if ((*lf) == (*lf)->prox) {   /* elemento unico: a lista fica vazia */
        free(*lf);
        *lf = NULL;
        return 1;
    }
    Elem *aux = (*lf)->prox;
    (*lf)->prox = aux->prox;
    free(aux);
    return 1;
}

int remove_lista_final(Lista* lf) {
    if (lf == NULL)
        return 0;
    if ((*lf) == NULL)
        return 0;           /* lista vazia */
    if ((*lf) == (*lf)->prox) {   /* elemento unico: a lista fica vazia */
        free(*lf);
        *lf = NULL;
        return 1;
    }
    Elem *ant = NULL, *no = *lf;
    while (no->prox != (*lf)) {   /* procura o ultimo, guardando o anterior */
        ant = no;
        no = no->prox;
    }
    ant->prox = no->prox;         /* o penultimo passa a apontar para o inicio */
    free(no);
    return 1;
}

int remove_lista(Lista* lf, int mat) {
    if (lf == NULL)
        return 0;
    if ((*lf) == NULL)
        return 0;           /* lista vazia */
    Elem *no = *lf;
    if (no->dados.matricula == mat) {      /* remocao do inicio */
        if (no == no->prox) {              /* a lista fica vazia */
            free(no);
            *lf = NULL;
            return 1;
        } else {
            Elem *ult = *lf;
            while (ult->prox != (*lf))     /* procura o ultimo */
                ult = ult->prox;
            ult->prox = (*lf)->prox;
            *lf = (*lf)->prox;
            free(no);
            return 1;
        }
    }
    Elem *ant = no;
    no = no->prox;
    /* para ao encontrar a matricula ou ao completar uma volta */
    while (no != (*lf) && no->dados.matricula != mat) {
        ant = no;
        no = no->prox;
    }
    if (no == (*lf))
        return 0;           /* chave ausente */
    ant->prox = no->prox;
    free(no);
    return 1;
}

/* --- busca ------------------------------------------------- */

int busca_lista_pos(Lista* lf, int pos, struct aluno *al) {
    if (lf == NULL || (*lf) == NULL || pos <= 0)
        return 0;
    Elem *no = *lf;
    int i = 1;
    /* para no ultimo elemento ou ao alcancar a posicao desejada */
    while (no->prox != (*lf) && i < pos) {
        no = no->prox;
        i++;
    }
    if (i != pos)
        return 0;           /* posicao inexistente */
    else {
        *al = no->dados;
        return 1;
    }
}

int busca_lista_mat(Lista* lf, int mat, struct aluno *al) {
    if (lf == NULL || (*lf) == NULL)
        return 0;
    Elem *no = *lf;
    /* para no ultimo elemento ou ao encontrar a matricula */
    while (no->prox != (*lf) && no->dados.matricula != mat)
        no = no->prox;
    if (no->dados.matricula != mat)
        return 0;           /* chave ausente */
    else {
        *al = no->dados;
        return 1;
    }
}

// Funções implementadas requeridas pela atividade:

void imprime_lista(Lista* lf) {
    if (lf == NULL) return;
    if ((*lf) == NULL) return;
    Elem *no = (*lf)->prox;
    do {
        printf("%d ", no->dados.matricula);
        no = no->prox;
    } while (no != (*lf)->prox);
    printf("\n");
}

int maior_matricula(Lista* lf, int *mat) {
    if (lf == NULL) return 0;
    if ((*lf) == NULL) return 0;
    Elem *no = (*lf);
    int max = no->dados.matricula;
    no = no->prox;
    while (no != (*lf)) {
        if (no->dados.matricula > max) {
            max = no->dados.matricula;
        }
        no = no->prox;
    }

    *mat = max;
    return 1;
}

int conta_aprovados(Lista* lf) {
    if (lf == NULL) return -1;
    if ((*lf) == NULL) return -1;
    Elem *no = (*lf);
    int count = 0;
    do {
        float media = (no->dados.n1 + no->dados.n2 + no->dados.n3) / 3.0f;
        if (media >= 7.0f) {
            count++;
        }
        no = no->prox;
    } while (no != (*lf));
    return count;
}

int busca_ciclica(Lista* lf, int k, struct aluno *al) {
    if (lf == NULL || (*lf) == NULL || k <= 0) return 0;
    Elem *no = (*lf);
    int i = 1, tam_lista = tamanho_lista(lf), pos;

    if (k > tam_lista) {
        pos = k % tam_lista;
    } else {
        pos = k;
    }

    while (i < pos) {
        no = no->prox;
        i++;
    }
    *al = no->dados;
    return 1;
}

int remove_lista_pos(Lista* lf, int pos) {
    if (lf == NULL || (*lf) == NULL || pos <= 0) return 0;
    if (pos == 1) {
        if (!remove_lista_inicio(lf)) return 0;
        return 1;
    } else {
        Elem *no = (*lf), *ant = NULL;
        int i = 1;
        do {
            ant = no;
            no = no->prox;
            i++;
        } while (i < pos && no != (*lf));

        if (no == (*lf)) {
            return 0; // Posição fora da lista (Voltou para o inicio)
        } else {
            ant->prox = no->prox;
            free(no);
            return 1;
        }   
    }
}

int rotaciona_lista(Lista* lf, int k) {
    if (lf == NULL || (*lf) == NULL || k < 0) return 0;
    int i = 0;
    while (i < k) {
        (*lf) = (*lf)->prox;
        i++;
    }
    return 1;
}

int concatena_listas(Lista* lf1, Lista* lf2) {
    if (lf1 == NULL || lf2 == NULL) return 0;
    if ((*lf1) == NULL) {
        (*lf1) = (*lf2);
        (*lf2) = NULL;
        return 1;
    } else if ((*lf2) == NULL) {
        return 1;
    } else if ((*lf1) == NULL && (*lf2) == NULL) {
        return 0;
    } else {
        Elem *no = (*lf1);
        while (no->prox != (*lf1)) {
            no = no->prox;
        }
        no->prox = (*lf2);

        Elem *no2 = (*lf2);
        while (no2->prox != (*lf2)) {
            no2 = no2->prox;
        }
        no2->prox = (*lf1);
        (*lf2) = NULL;
        return 1;
    }
}

int josephus(Lista* lf, int k, int *sobrevivente) {
    if (lf == NULL || (*lf) == NULL || k <= 0) return 0;
    Elem *no = (*lf), *ant = NULL;
    if (k == 1) {
        no = no->prox;
        while (no->prox != (*lf)) {
            ant = no;
            no = no->prox;
            free(ant);
        }
        *sobrevivente = no->dados.matricula;
        ant = no;
        no = no->prox;
        free(ant);
        free(no);
        (*lf) = NULL;
        return 1;
    }
    int i = 1;
    while (no->prox != no) {
        ant = no;
        no = no->prox;
        i++;
        if (i == k) {
            i = 1;
            ant->prox = no->prox;
            free(no);
            no = ant->prox;
        }
    }
    *sobrevivente = no->dados.matricula;
    free(no);
    (*lf) = NULL;
    return 1;
}

void criar_aluno(struct aluno *al) {
    int matricula = 0;
    char nome[30] = "";
    float nota1 = 0, nota2 = 0, nota3 = 0;

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