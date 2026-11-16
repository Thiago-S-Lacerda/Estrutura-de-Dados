# Respostas às Questões Teóricas e Discursivas

Este documento apresenta as respostas e justificativas para as perguntas teóricas propostas na lista de exercícios da disciplina de **Estrutura de Dados (UFPB)** sobre listas dinâmicas duplamente encadeadas.

---

## Questão 01 — Rastreamento de operações

* **Pergunta 1: Para cada chamada, registre o valor devolvido e, após a chamada, os campos inicio, final e qtd e o conteúdo das quatro posições do vetor, indicando quais posições pertencem à fila.**

  * Chamada: Fila *fi = cria_Fila(4); Valor devolvido da função: *fi; Campos: inicio = 0, final = 0 e qtd = 0; Conteúdo das posições: 0: Lixo, 1: Lixo, 2: Lixo, 3: Lixo; 
  * Chamada: insere_Fila(fi, a5); Valor devolvido da função: 1; Campos: inicio = 0, final = 1 e qtd = 1; Conteúdo das posições: 0: (5), 1: Lixo, 2: Lixo, 3: Lixo; 
  * Chamada: insere_Fila(fi, a8); Valor devolvido da função: 1; Campos: inicio = 0, final = 2 e qtd = 2; Conteúdo das posições: 0: (5), 1: (8), 2: Lixo, 3: Lixo; 
  * Chamada: insere_Fila(fi, a3); Valor devolvido da função: 1; Campos: inicio = 0, final = 3 e qtd = 3; Conteúdo das posições: 0: (5), 1: (8), 2: (3), 3: Lixo; 
  * Chamada: remove_Fila(fi); Valor devolvido da função: 1; Campos: inicio = 1, final = 3 e qtd = 2; Conteúdo das posições: 0: Lixo, 1: (8), 2: (3), 3: Lixo; 
  * Chamada: insere_Fila(fi, a9); Valor devolvido da função: 1; Campos: inicio = 1, final = 0 e qtd = 3; Conteúdo das posições: 0: Lixo, 1: (8), 2: (3), 3: (9); 
  * Chamada: insere_Fila(fi, a7); Valor devolvido da função: 1; Campos: inicio = 1, final = 1 e qtd = 4; Conteúdo das posições: 0: (7), 1: (8), 2: (3), 3: (9); 
  * Chamada: insere_Fila(fi, a1); Valor devolvido da função: 0; Campos: inicio = 1, final = 1 e qtd = 4; Conteúdo das posições: 0: (7), 1: (8), 2: (3), 3: (9); 
  * Chamada: remove_Fila(fi); Valor devolvido da função: 1; Campos: inicio = 2, final = 1 e qtd = 3; Conteúdo das posições: 0: (7), 1: Lixo, 2: (3), 3: (9); 
  * Chamada: insere_Fila(fi, a6); Valor devolvido da função: 1; Campos: inicio = 2, final = 2 e qtd = 4; Conteúdo das posições: 0: (7), 1: (6), 2: (3), 3: (9); 
  * Chamada: consulta_Fila(fi, &al); Valor devolvido da função: 1; Campos: inicio = 2, final = 2 e qtd = 4; Conteúdo das posições: 0: (7), 1: (6), 2: (3), 3: (9); al = 3;

* **Pergunta 2: Escreva a ordem dos elementos da fila ao final, do início para o final, e o aluno copiado para al pela consulta.**

  * 7 6 3 9 (Na ordem do vetor original); O aluno copiado para al foi o 3;

* **Pergunta 3: Indique quais posições do vetor foram gravadas mais de uma vez e explique por que essas sobrescritas não fazem a fila perder nenhum elemento.**

  * A posição 0 e 1 foram gravadas mais de uma vez. Essas sobrescritas não faz a fila perder nenhum elemento, por causa da manipulação dos ponteiros inicio e fim da lista, através disso, conseguimos aproveitar 100% do espaço alocado para a fila.

---

## Questão 02 — Atendimento prioritário

* **Pergunta 1: Escreva a função e teste-a com a fila vazia, com a fila em que inicio vale 0 e com a fila cheia.**

  * Função implementada em FilaEstatica.c;
    * Teste com inicio = 0 e capacidade = 4; O vetor de dados está: 0: (1), 1:(2), 2: (3), 3: Lixo; Na função: inicio = (0 + 4 -1) % 4 => 3 % 4 => 3; inicio = 3; Agora adicionamos o al (para fins de visibilidade, al vale 0) no inicio; O vetor fica: 0: (1), 1:(2), 2: (3), 3: 0;
    * Teste com filha cheia: A função já retorna 0 ao verificar que a lista está cheia através da função já criada.

* **Pergunta 2: Uma colega propôs atualizar o início com fi->inicio = (fi->inicio - 1) % fi->capacidade;. Mostre o que acontece quando inicio vale 0 e explique a consequência para a memória.**

  * Quando inicio vale 0, a expressão ficaria -1 % capacidade; Isso daria um número negativo e quando fosse acessar esse valor no vetor dados, iria causar um erro, pois a posição dados[-1] não existe.

* **Pergunta 3: Com essa operação, a estrutura continua sendo uma fila no sentido estrito? Justifique.**

  * Não continua no sentido estrito, pois não segue mais a política do FIFO (First In, First Out). Como um aluno pode entrar na frente de outro, agora o primeiro a sair não é necessariamente o primeiro que entrou.