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

---

## Questão 03 —  Problema de Josefo

* **Pergunta 1: Escreva a função e teste-a com (n, k) = (7, 3), (5, 2), (1, 4) e (6, 1).**
  * Teste (7, 3) -> Saída: 3 6 2 7 5 1; Sobrevivente: 4
  * Teste (5, 2) -> Saída: 2 4 1 5; Sobrevivente: 3
  * Teste (1, 4) -> Saída: ; Sobrevivente: 1
  * Teste (6, 1) -> Saída: 1 2 3 4 5; Sobrevivente: 6

* **Pergunta 2: Qual capacidade a fila precisa ter? Justifique por que ela nunca fica cheia durante a simulação.**
  * A fila precisa ter capacidade "n". Ela só fica cheia no início quando é povoada com os números de 1 a n, no restante, como os números são retirados, ela não ficará cheia.

* **Pergunta 3: Determine o custo da simulação em função de n e k. Em seguida, compare com o custo da mesma simulação feita sobre a lista sequencial estática, usando remove_lista_inicio e insere_lista_final, e justifique qual estrutura é a mais adequada.**
  * O custo da simulação é O(n.k), já que para cada elemento da fila é preciso retirar os k-1 números anteriores e depois colocá-los na fila novamente. Já o custo da simulação com a lista sequencial estática seria O(n².k), já que para cada elemento ao remover é necessário copiar todos os dados uma posição a esquerda. A estrutura mais adequada para esse caso seria de fato a fila, já que teria um custo menor, ou seja, mais rápido e eficiente.

---

## Questão 04 —  Sequências de inserção e remoção

* **Pergunta 1: Escreva a sequência de inserções (I) e remoções (R) que produz a saída 2, 4, 3, 1, mostrando o conteúdo da pilha após cada operação.**
  * I I R I I R R R

* **Pergunta 2: É possível obter a saída 3, 1, 4, 2? Justifique com base na política LIFO.**
  * Não é possível, pois na política LIFO diz que o "Last In, First Out", ou seja, o último a entrar é o primeiro a sair. Então, para sair o 3 primeiro seria necessário inserir 3 vezes e a pilha ficaria: 1 2 3; Depois remove da pilha, imprimindo o topo, a pilha ficaria: 1 2; Porém, agora chegamos em um ponto que é impossível imprimir o 1 antes do 2 na pilha, já que segue a política LIFO e o 2 que é o topo e não o 1.

* **Pergunta 3: Considere que uma sequência de I e R é válida quando tem o mesmo número de I e de R e nenhuma remoção ocorre com a pilha vazia. Implemente a função abaixo, que devolve 1 se a sequência for válida e 0 caso contrário; por exemplo, IRIIRR é válida e IRRI não é.**
  * Função escrita no menu.c

* **Pergunta 4: A sua função precisou de uma pilha? Explique o que a variável usada representa em relação à pilha.**
  * Não precisou de uma pilha. A variável representa a quantidade de termos dentro da pilha, pois somente isso é necessário para resolver o caso de saber se é válido ou não. Se tentar remover com a quantidade já em 0 vai dar erro. Então é só usar uma variável que conta quantos elementos têm e ir fazendo a comparação. Como o número de inserções tem que ser igual ao número de remoções, se a variável de controle não for 0 ao final da sequência, então é uma sequência inválida.

---

## Questão 05 —  Verificação de delimitadores

* **Pergunta 1: A biblioteca da pasta 07 armazena struct aluno. Crie PilhaChar.h e PilhaChar.c a partir dela, trocando o tipo do elemento por char, e indique cada linha que precisou mudar.**
  * Mudei o struct pilha colocando um vetor de caracteres, além disso alterei o malloc do "cria_Pilha" para usar o tamanho de chars. Por fim, os parâmetros que utilizavam o struct aluno, modifiquei para char.

* **Pergunta 2: Usando apenas a interface de PilhaChar.h, implemente a função abaixo, que devolve 1 se a expressão estiver corretamente aninhada e 0 caso contrário. Caracteres que não são delimitadores devem ser ignorados.**
  * Função implementada em menu.c

* **Pergunta 3: Que capacidade a pilha precisa ter para que nenhuma inserção falhe? Justifique.**
  * A pilha precisa ter o tamanho da expressão passada como capacidade para não haver nenhum erro de inserção. Utizamos strlen() da biblioteca <string.h> para pegar o tamanho da expressão.

* **Pergunta 4: A técnica da questão 4c resolveria este problema? Use a expressão ([)] na justificativa.**
  * Nesse caso não daria certo, pois precisamos obrigatoriamente saber o topo da pilha para fazer o match com o fechamento do delimitador. No exemplo: "([)]", não daria para saber se o ")" iria casar com o topo da pilha, pois só teríamos a quantidade de elementos na pilha.

--- 

## Questão 06 —  Duas pilhas em um único vetor

* **Pergunta 1: Defina struct pilha_dupla em PilhaDupla.c e implemente as funções. Indique em que posição do vetor fica o topo de cada pilha e qual é a condição de pilha cheia.**
  * O topo da pilha 1 é o "qtd1 - 1" (é utilizado quando qtd1 > 0); O topo da pilha 2 é "capacidade - qtd2" (é utilizado quando qtd2 > 0); A condição de pilha cheia agora é: qtd1 + qtd2 == capacidade;

* **Pergunta 2: Com capacidade 5, execute: insere 10 na pilha 1, 90 na pilha 2, 20 na pilha 1, 80 na pilha 2, 30 na pilha 1, 70 na pilha 2; remove da pilha 2; insere 40 na pilha 1. Desenhe o vetor e os campos de controle ao final e indique o valor devolvido por cada chamada.**
  * | Operação | qtd1 | qtd2 | dados[0, 1, ..., 4] | Retorno |
    | insere(10, 1) | 1 | 0 | 10;-;-;-;- | 1 |
    | insere(90, 2) | 1 | 1 | 10;-;-;-;90 | 1 |
    | insere(20, 1) | 2 | 1 | 10;20;-;-;90 | 1 |
    | insere(80, 2) | 2 | 2 | 10;20;-;80;90 | 1 |
    | insere(30, 1) | 3 | 2 | 10;20;30;80;90 | 1 |
    | insere(70, 2) | 3 | 2 | 10;20;30;80;90 | 0 |
    | remove(2) | 3 | 1 | 10;20;30;-;90 | 1 |
    | insere(40, 1) | 4 | 1 | 10;20;30;40;90 | 1 |

* **Pergunta 3: Compare a PilhaDupla de capacidade 8 com duas pilhas da pasta 07 de capacidade 4 cada. Mostre uma sequência de operações em que a PilhaDupla aceita uma inserção que as pilhas separadas recusam. Existe a situação inversa? Justifique.**
  * Comparando as duas, é visto que a pilha dupla acaba usando um pouco menos de memória a mais por conta de que a variável "capacidade" é declarada apenas uma vez. Além disso, pode-se manejar o vetor de uma forma que as listas separadas com capacidade 4 não poderiam fazer sozinhas. Uma sequência de operações é: insere(10, 1), insere(20, 1), insere(80, 2), insere(70, 2), insere(30, 1), insere(40, 1), insere(50, 1), insere(60, 1); Nessa sequência temos que a pilha 1 possui 6 elementos e a pilha 2 possui 2 elementos. Isso não seria possível com duas pilhas de capacidade 4.

* **Pergunta 4: Qual é o custo de cada operação? Em que tipo de aplicação essa organização é vantajosa?**
  * Todas as operações são O(1). Essa organização é vantajosa em aplicações de sistemas embarcados em que a memória é um recurso muito restrito, então utilizar dessa forma é um jeito de poupar memória.