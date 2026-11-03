# Respostas às Questões Teóricas e Discursivas

Este documento apresenta as respostas e justificativas para as perguntas teóricas propostas na lista de exercícios da disciplina de **Estrutura de Dados (UFPB)** sobre listas dinâmicas duplamente encadeadas.

---

## Questão 03 — Identificação e correção de erros

* **Pergunta 1: Descreva o que ocorre na chamada `remove_lista(li, 33)` sobre a lista `33 ⇄ 23 ⇄ 16`.**
* O algoritmo tenta acessar `no->ant->prox`, mas `no->ant` é `NULL` nesse caso, pois o 33 é o primeiro da lista. Além disso, mesmo se isso funcionasse, não há uma mudança no ponteiro `(*li)`, nesse caso o `(*li)` apontaria para uma região de memória liberada.


* **Pergunta 2: Partindo novamente de `33 ⇄ 23 ⇄ 16`, desenhe a lista após `remove_lista(li, 23)`, indicando os campos `ant` e `prox` de cada nó restante. Explique por que `tamanho_lista` devolve o valor esperado e por que `lista_consistente` (questão 2) devolve 0.**
* `NULL <- 33 -> 16 -> NULL`. Contudo, o `ant` do 16 não foi configurado, ele continua apontando para a região do 23, mesmo que tenha sido liberado.
* O `tamanho_lista` devolve 2, pois ela consegue usar o `prox` de todos os nós até o final para contar, porém na função `lista_consistente`, quando ela compara o `ant` do 16 com o nó anterior de fato, dá errado pois seu ponteiro não foi configurado.


* **Pergunta 3: Reescreva a função corrigida.**
```c
int remove_lista_question3(Lista* li, int mat) {
    if(li == NULL) return 0;
    if((*li) == NULL) return 0;
    Elem* no = *li;
    while(no != NULL && no->dados.matricula != mat)
        no = no->prox;
    if(no == NULL) return 0;
    if (no == (*li)) {
        (*li) = no->prox;
        if (no->prox != NULL) {
            no->prox->ant = NULL;
        }
        free(no);
        return 1;
    } else {
        no->ant->prox = no->prox;
        if (no->prox != NULL) {
            no->prox->ant = no->ant;
        }
        free(no);
        return 1;
    }
}

```



---

## Questão 5 — Mover um elemento para o início

* **Pergunta: Quantos campos de ponteiro são escritos quando o elemento está no meio da lista? E quando é o último? Justifique pelo seu código.**
* Quando o elemento está no meio, 5 ponteiros são escritos, enquanto que quando está no final, apenas 4 são escritos. Isso acontece, pois o `prox` do último elemento é `NULL`, então ele não tem ponteiro `ant` para apontar para `no->ant`.



---

## Questão 7 — Inversão da lista no lugar

* **Pergunta: Justifique por que, em uma lista duplamente encadeada, trocar os campos `ant` e `prox` de cada nó e atualizar o início é suficiente. Indique o custo da função.**
* É suficiente, pois os ponteiros `prox` e `ant` são os que ditam a ordem, então quando invertemos todos e colocamos `(*li)` no antigo final, a lista fica invertida.



---

## Questão 8 — Sequência palíndroma

* **Pergunta: Indique o custo da função e explique por que a mesma estratégia não se aplica diretamente à lista encadeada simples.**
* O custo da função é $O(N)$, porém não é necessário andar pela lista toda, apenas pela metade. Essa estratégia não se aplica à lista encadeada simples, pois lá não existe o ponteiro `ant`, então não seria possível usar dois ponteiros (um no início e outro no final).



---

## Desafio Opcional — Lista Duplamente Encadeada Circular

* **Pergunta: Implemente `insere_lista_inicio`, `insere_lista_final`, `remove_lista_inicio` e `remove_lista_final` para essa representação, todas em $O(1)$, e compare com os custos das mesmas operações na lista circular simples que guarda o início.**
* Inserir no final e remover no final tornam-se $O(1)$, pois não é mais necessário percorrer a lista para encontrar o último elemento. O último elemento passa a ser: `(*li)->ant`.