/* ============================================================
   ListaDinEncadDupla.c
   Estrutura de Dados I - UFPB - Aula 08
   Lista dinamica duplamente encadeada

   Implementacao identica a apresentada nos slides da Aula 08.
   A definicao de struct elemento esta aqui, e nao no .h: e isso
   que torna Lista um tipo opaco. Quem usa a biblioteca enxerga
   apenas Lista* e os prototipos declarados no cabecalho.

   Qualquer funcao nova que precise percorrer a lista no a no
   tem de ser escrita NESTE arquivo, porque e aqui que os campos
   ant, dados e prox sao visiveis.
   ============================================================ */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ListaDinEncadDuplaOtm.h"

/* Definicao do tipo lista: oculta de quem usa a biblioteca.
   Com struct aluno de 48 bytes, sizeof(Elem) = 64 bytes em uma
   plataforma de 64 bits, contra 56 na lista encadeada simples. */
struct elemento {
    struct elemento *ant;
    struct aluno dados;
    struct elemento *prox;
};
typedef struct elemento Elem;

/* --- criacao e destruicao ---------------------------------- */

Lista* cria_lista(void) {
    Lista* li = (Lista*) malloc(sizeof(Lista));
    if (li != NULL)
        *li = NULL;
    return li;
}

void libera_lista(Lista* li) {
    if (li == NULL) return;
    if ((*li) != NULL) {
        Elem* inicio = (*li), *no = NULL;
        do {
            no = *li;
            *li = (*li)->prox;   /* avanca antes de liberar */
            free(no);
        } while ((*li) != inicio); 
    }
    free(li); 
}

/* --- informacoes de estado --------------------------------- */

int tamanho_lista(Lista* li) {
    if (li == NULL)
        return 0;
    int cont = 0;
    Elem* no = *li;
    do {
        cont++;
        no = no->prox;
    } while (no != (*li));
    return cont;
}

int lista_cheia(Lista* li) {
    (void) li;               /* parametro mantido por simetria com as demais */
    return 0;
}

int lista_vazia(Lista* li) {
    if (li == NULL)
        return 1;            /* lista invalida */
    if (*li == NULL)
        return 1;            /* nenhum elemento alocado */
    return 0;
}

/* --- insercao ---------------------------------------------- */

int insere_lista_inicio(Lista* li, struct aluno al) {
    if (li == NULL) return 0;
    Elem* no = (Elem*) malloc(sizeof(Elem));
    if (no == NULL) return 0;    /* sem memoria: a lista esta cheia */
    no->dados = al;
    if ((*li) != NULL) {
        no->prox = (*li);
        no->ant = (*li)->ant;
        (*li)->ant->prox = no;
        (*li)->ant = no;    
    } else {
        no->prox = no;
        no->ant = no;
    }
    (*li) = no;
    return 1;
}

int insere_lista_final(Lista* li, struct aluno al) {
    if (li == NULL) return 0;
    Elem* no = (Elem*) malloc(sizeof(Elem));
    if (no == NULL) return 0;
    no->dados = al;
    if ((*li) == NULL) {         /* lista vazia: insere inicio */
        no->prox = no;
        no->ant = no;
        (*li) = no;
    } else {
        Elem* ult = (*li)->ant;
        ult->prox = no;
        no->prox = (*li);
        (*li)->ant = no;
        no->ant = ult;
    }
    return 1;
}

int insere_lista_ordenada(Lista* li, struct aluno al) {
    if (li == NULL) return 0;
    Elem* no = (Elem*) malloc(sizeof(Elem));
    if (no == NULL) return 0;
    no->dados = al;
    if ((*li) == NULL) {         /* lista vazia: insere inicio */
        no->prox = no;
        no->ant = no;
        (*li) = no;
        return 1;
    }
    else {
        /* O livro declara ante sem valor inicial. A inicializacao com
           NULL nao altera o comportamento e elimina o aviso
           "may be used uninitialized" do gcc com -O2. */
        Elem *ante = (*li), *atual = (*li);
        if (atual->dados.matricula >= al.matricula) {
            no->ant = (*li)->ant;
            (*li)->ant->prox = no;
            (*li)->ant = no;
            no->prox = (*li);
            (*li) = no;
            return 1;
        } else {
            atual = atual->prox;
        }
        while (atual != (*li) &&
               atual->dados.matricula < al.matricula) {
            ante = atual;
            atual = atual->prox;
        }
        if (atual == (*li)) {
            Elem* ult = (*li)->ant;
            ult->prox = no;
            no->prox = (*li);
            (*li)->ant = no;
            no->ant = ult;
        } else {                 /* insere no meio*/
            no->prox = ante->prox;
            no->ant = ante;
            ante->prox = no;
            atual->ant = no;
        }
        return 1;
    }
}

/* --- remocao ----------------------------------------------- */

int remove_lista_inicio(Lista* li) {
    if (li == NULL) return 0;
    if ((*li) == NULL) return 0;   /* lista vazia */
    Elem* no = (*li), *ult = (*li)->ant;
    if (no->prox == no) {
        free(no);
        (*li) = NULL;
    } else {
        (*li) = no->prox;
        no->prox->ant = ult;
        ult->prox = no->prox;
        free(no);
    }
    return 1;
}

int remove_lista_final(Lista* li) {
    if (li == NULL) return 0;
    if ((*li) == NULL) return 0;   /* lista vazia */
    Elem* ult = (*li)->ant;
    if (ult->prox == ult) {
        free(ult);
        (*li) = NULL;
    } else {
        Elem *pen = (*li)->ant->ant;
        pen->prox = (*li);
        (*li)->ant = pen;
        free(ult);
    }
    return 1;
}

int remove_lista(Lista* li, int mat) {
    if (li == NULL) return 0;
    if ((*li) == NULL) return 0;   /* lista vazia */
    Elem* no = (*li), *ult = (*li)->ant;
    if (no->dados.matricula == mat) {
        if (no->prox == no) {
            free(no);
            (*li) = NULL;
        } else {
            (*li) = no->prox;
            no->prox->ant = ult;
            ult->prox = no->prox;
            free(no);
        }
        return 1;
    }
    no = no->prox;
    while (no != (*li) && no->dados.matricula != mat)
        no = no->prox;
    if (no->dados.matricula != mat)                /* chave ausente */
        return 0;
    no->ant->prox = no->prox;
    no->prox->ant = no->ant;
    free(no);
    return 1;
}

/* --- busca ------------------------------------------------- */

int busca_lista_pos(Lista* li, int pos, struct aluno *al) {
    if (li == NULL || (*li) == NULL || pos <= 0)
        return 0;
    Elem *no = (*li);
    int i = 1;
    while (no->prox != (*li) && i < pos) {
        no = no->prox;
        i++;
    }
    if (i != pos)
        return 0;
    else {
        *al = no->dados;
        return 1;
    }
}

int busca_lista_mat(Lista* li, int mat, struct aluno *al) {
    if (li == NULL || (*li) == NULL)
        return 0;
    Elem *no = (*li);
    while (no->prox != (*li) && no->dados.matricula != mat)
        no = no->prox;
    if (no->dados.matricula != mat)
        return 0;
    else {
        *al = no->dados;
        return 1;
    }
}

// Funções implementadas requeridas pela atividade:

void imprime_lista_inversa(Lista* li) {
    if (li == NULL || (*li) == NULL) {
        printf("Lista vazia\n");
        return;
    }
    Elem *no = (*li)->ant;
    while (no != (*li)) {
        printf("%d ", no->dados.matricula);
        no = no->ant;
    } 
    printf("%d ", no->dados.matricula);
    printf("\n");
}

int lista_consistente(Lista* li) {
    if (li == NULL) return 0;
    if ((*li) == NULL) return 1;
    Elem *no = (*li), *ult = (*li)->ant;
    do {
        if (no->prox->ant != no) return 0;
        no = no->prox;
    } while (no->prox != (*li));
    if (no != ult) return 0;
    if (ult->prox != (*li)) return 0;
    return 1;
}

int remove_lista_pos(Lista* li, int pos) {
    if (li == NULL || (*li) == NULL || pos <= 0) return 0;
    Elem *no = (*li);

    int i = 1;
    while (no->prox != (*li) && i < pos) {
        no = no->prox;
        i++;
    }

    if (i != pos) return 0;
    if (no->ant == no) {
        (*li) = NULL;
    } else {
        no->ant->prox = no->prox;
        if (no == (*li)) {
            (*li) = no->prox;
        }
        no->prox->ant = no->ant;
    }
    free(no);
    return 1;
}

int move_para_inicio(Lista* li, int mat) {
    if (li == NULL) return 0;
    if ((*li) == NULL) return 0;
    Elem *no = (*li);
    if (no->dados.matricula == mat) return 1;
    no = no->prox;
    while (no != (*li) && no->dados.matricula != mat) {
        no = no->prox;
    }
    if (no == (*li)) return 0;
    Elem *pen = (*li)->ant->ant;
    no->ant->prox = no->prox;
    no->prox->ant = no->ant;
    if (no->prox != (*li)) {
        no->ant = (*li)->ant;
    } else {
        no->ant = pen;
    }
    no->prox = (*li);
    (*li)->ant->prox = no;
    (*li)->ant = no;
    (*li) = no;
    return 1;
}

int remove_todos(Lista* li, int mat) {
    if (li == NULL) return 0;
    if ((*li) == NULL) return 0;
    Elem *no = (*li);
    int count = 0;
    do {
        if (no->dados.matricula == mat) {
            count++;
            if (no->ant == no) {
                free(no);
                no = NULL;
                (*li) = NULL;
                return count;
            } else if (no == (*li)) {
                no->prox->ant = (*li)->ant;
                (*li)->ant->prox = no->prox;
                (*li) = (*li)->prox;
                free(no);
                no = (*li);
            } else {
                Elem *aux = no->prox;
                no->ant->prox = no->prox;
                no->prox->ant = no->ant;
                free(no);
                no = aux;
            }
        } else {
            no = no->prox;
        }
    } while (no->prox != (*li));

    if (no->dados.matricula == mat) {
        count++;
        if (no->prox == no) {
            free(no);
            (*li) = NULL;
        } else {
            no->ant->prox = no->prox;
            (*li)->ant = no->ant;
            free(no);
            no = NULL;
        }
    }
    return count;
}

void inverte_lista(Lista* li) {
    if (li == NULL) {
        printf("Lista invalida\n");
        return;
    }
    if ((*li) == NULL) return;
    if ((*li)->prox == (*li)) return;

    Elem *no = (*li), *ante = (*li), *pri = (*li), *ult = (*li)->ant;
    no->ant = no->prox;
    no->prox = ult;
    no = no->ant;
    while (no->prox != pri) {
        ante = no;
        no = no->prox;
        ante->prox = ante->ant;
        ante->ant = no;
    }
    no->prox = ante;
    no->ant = pri;
    (*li) = no;
}

int eh_palindromo(Lista* li) {
    if (li == NULL) return 0;
    if ((*li) == NULL || (*li)->prox == (*li)) return 1;
    Elem *inicio = (*li), *final = (*li)->ant;

    int flag = 0;
    while (inicio != final && (final->prox != inicio || inicio == (*li))) {
        if (inicio->dados.matricula != final->dados.matricula) {
            flag = 1;
            break;
        }
        inicio = inicio->prox;
        final = final->ant;
    }

    if (flag != 0) {
        return 0;
    } else {
        return 1;
    }
}

// Funções desenvolvidas a parte:

void imprime_lista(Lista* li) {
    if (li == NULL || (*li) == NULL) {
        printf("Lista vazia\n");
        return;
    }
    Elem *no = (*li);

    do {
        printf("%d ", no->dados.matricula);
        no = no->prox;
    } while (no != (*li));
    printf("\n");
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