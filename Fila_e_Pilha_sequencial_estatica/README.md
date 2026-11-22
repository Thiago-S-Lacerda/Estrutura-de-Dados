# Implementação de Filas e Pilhas Sequenciais Estáticas em C

Repositório criado para a atividade prática da disciplina de **Estrutura de Dados da UFPB**, focada na implementação, manipulação e análise de Filas e Pilhas Sequenciais Estáticas com capacidade definida na criação.

---

## Sobre a Atividade

O objetivo desta atividade é aplicar os conceitos de estruturas de dados estáticas baseadas em vetores circulares e lineares, gerenciando ponteiros de controle (`inicio`, `final`, `qtd`) e políticas de acesso como FIFO (First In, First Out) e LIFO (Last In, Last Out). O projeto inclui o rastreamento de operações em filas, a simulação do Problema de Josefo, validação de sequências de pilha, verificação de delimitadores aninhados (`PilhaChar`) e o compartilhamento otimizado de memória com duas pilhas em um único vetor (`PilhaDupla`).

Também foi incluída a resolução documentada das perguntas teóricas e discursivas propostas na lista de exercícios.

---

## Estrutura do Projeto e Organização dos Diretórios

O projeto está organizado nos seguintes diretórios e arquivos:

* **include/**: Contém os arquivos de cabeçalho.
* `FilaEstatica.h`: Protótipos e estruturas da fila sequencial estática.
* `PilhaSequencial.h`: Protótipos e estruturas da pilha sequencial estática padrão.
* `PilhaDupla.h`: Protótipos e estruturas do desafio de duas pilhas em um único vetor.


* `PilhaChar.h`: Variação da pilha armazenando caracteres para verificação de delimitadores.


* `menuFila.h`, `menuPilha.h`, `menuPilhaDupla.h`: Protótipos dos sistemas de menus interativos para cada módulo.


* **src/**: Contém os arquivos-fonte.
* `FilaEstatica.c`: Implementação das operações da fila estática (incluindo tratamento de vetor circular).


* `PilhaSequencial.c`: Implementação das operações da pilha sequencial.
* `PilhaDupla.c`: Implementação da estrutura que gerencia duas pilhas compartilhando o mesmo vetor.


* `PilhaChar.c`: Implementação da pilha de caracteres para a verificação de delimitadores.


* `menuFila.c`, `menuPilha.c`, `menuPilhaDupla.c`: Implementações das interfaces de menus interativos.
* `mainFila.c`, `mainPilha.c`, `mainPilhaDupla.c`: Pontos de entrada dos programas e execução dos testes manuais e automatizados.


* **Outros arquivos e documentações**:
* `Respostas.md`: Contém as resoluções detalhadas, explicações teóricas, rastreamentos e análises de complexidade exigidas nas questões.
* `Documentacao_atividade_2.pdf`: Documento oficial com os requisitos e instruções detalhadas da prática.


* `Makefile`: Automação para compilação rápida de todos os módulos do projeto.
* `README.md`: Documentação principal do repositório.



---

## Módulos do Projeto

O repositório está dividido em três grandes frentes estruturais:

1. **Fila Sequencial Estática (`fila`)**:
* Gerenciamento circular de posições (`inicio`, `final`, `qtd`).


* Resolução de rastreamentos de operações e simulação do **Problema de Josefo**.




2. **Pilha Sequencial Estática (`pilha`)**:
* Operações padrão LIFO e análise de sequências de inserção/remoção.


* Módulo especializado `PilhaChar` para validação de expressões e aninhamento correto de delimitadores.




3. **Pilha Dupla em Vetor Único (`pilha_dupla`)**:
* Compartilhamento eficiente de um único vetor de dados onde a Pilha 1 cresce da esquerda para a direita e a Pilha 2 cresce da direita para a esquerda, otimizando o uso de memória em sistemas restritos.





---

## Como Compilar e Executar

O projeto possui um `Makefile` robusto configurado para compilar os módulos de forma independente ou conjunta.

1. Certifique-se de estar na pasta `Fila_e_Pilha_sequencial_estatica`.
2. Para compilar **todos os programas** de uma vez, execute:
```bash
make all

```


*(Ou utilize comandos específicos como `make fila`, `make pilha` ou `make pilha_dupla`).*
3. Após a compilação, execute o binário desejado no diretório `build/`:
* Módulo de Fila:
```bash
./build/fila

```


* Módulo de Pilha:
```bash
./build/pilha

```


* Módulo de Pilha Dupla:
```bash
./build/pilha_dupla

```





---

## Observações e Ferramentas de Qualidade

* **Respostas Teóricas**: Consulte o arquivo `Respostas.md` do repositório para conferir o rastreamento detalhado de filas, justificativas de complexidade e análises estruturais.


* **Valgrind**: Recomenda-se a verificação de alocações e gerenciamento de memória utilizando a ferramenta de diagnóstico:
```bash
valgrind --leak-check=full ./build/fila

```


* O código foi inteiramente desenvolvido seguindo rigorosamente o padrão de compilador `C11` com avisos ativados (`-Wall -Wextra`).