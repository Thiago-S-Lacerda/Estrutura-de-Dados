# Respostas às Questões Teóricas e Discursivas

Este documento apresenta as respostas e justificativas para as perguntas teóricas propostas na lista de exercícios da disciplina de **Estrutura de Dados (UFPB)** sobre listas dinâmicas encadeadas circulares.

---

## Questão 06 — Rotação da lista

- **Pergunta 1: Qual é o custo da função, e por que ela não precisa ser $O(N)$ para $k$ pequeno?**
  - A função no pior caso é $O(N)$, pois dependendo do valor de $k$, ela precisa dar várias voltas na lista. No caso de $k$ ser pequeno (menor que o tamanho da lista), o algoritmo não vai depender do tamanho de elementos da lista para o funcionamento da função.

- **Pergunta 2: O que seria necessário para obter o mesmo efeito em uma lista dinâmica encadeada não circular, e qual seria o custo?**
  - Seria necessário reiniciar a busca na lista explicitamente quando chegasse no final dela, no caso de $k$ ser um número maior do que o número de elementos atuais da lista. O custo também seria $O(N)$ no pior caso.

---

## Questão 7 — Concatenação de duas listas

- **Pergunta: Qual seria o custo desta mesma operação na representação que guarda o final da lista em `(*li)`, apresentada no fim da aula?**
  - Seria $O(1)$, pois não seria mais necessário percorrer as duas listas procurando o último elemento para mexer nos ponteiros.

---

## Desafio Opcional — A representação que guarda o final

- **Pergunta: Justifique, em até cinco linhas, por que a remoção do final permanece $O(N)$ mesmo nessa representação.**
  - Porque é necessário ter acesso ao penúltimo elemento para mexer no ponteiro, então de todo jeito é preciso percorrer a lista até o final, sendo assim $O(N)$. Todavia, se a representação guardasse o penúltimo elemento, todas as outras funções de inserção e remoção que transformaram-se em $O(1)$ continuariam $O(1)$, e a remoção do final ficaria $O(1)$ também.