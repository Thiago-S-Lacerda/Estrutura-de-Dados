# Estruturas de Dados - UFTB

Repositório centralizado dedicado ao armazenamento e à documentação das atividades práticas desenvolvidas para a disciplina de **Estrutura de Dados** da **UFPB** (*Universidade Federal da Paraíba*). 

O objetivo deste repositório é aplicar os conceitos teóricos estudados em sala de aula através da implementação prática e da manipulação eficiente de estruturas de dados utilizando a linguagem **C**.

---

## Sobre a Disciplina e a Dinâmica das Atividades

Ao longo da disciplina, exploramos diferentes formas de organizar, armazenar e manipular dados na memória. A cada módulo ou lista de exercícios proposta pelo professor, construímos estruturas do zero, manipulando ponteiros com segurança, gerenciando alocação dinâmica (`malloc`/`free`) e implementando funções avançadas para resolver problemas específicos.

Enquanto avançamos na matéria (passando por listas, pilhas, filas e outras estruturas futuras), cada projeto é isolado em sua própria pasta com sua respectiva documentação e sistema de testes.

---

## Organização do Repositório

O repositório está estruturado em pastas separadas por listas de exercícios ou projetos práticos:

| Pasta / Lista | Descrição Resumida | Tecnologias / Conceitos |
| :--- | :--- | :--- |
| **`Lista_04/`** | Implementação e manipulação de listas sequenciais e estáticas (adicionar, remover, novas funções). | Linguagem C, Ponteiros, Alocação Estática, Makefiles. |
| **`Lista_05/`** | Expansão de funcionalidades para listas dinâmicas encadeadas com critérios de prioridade e organização. | Linguagem C, Alocação Dinâmica, Manipulação Avançada de Nós. |
| *Próximas Listas* | *Em breve: Pilhas, Filas, Árvores, etc.* | *Estruturas de Dados Lineares e Não-Lineares* |

> **Nota:** Cada pasta de lista possui o seu próprio `README.md` detalhado, explicando o escopo da atividade específica, os requisitos exigidos pelo professor e instruções de como compilar e executar o código daquela lista em particular.

---

## Como Compilar e Testar os Projetos

Cada lista possui o seu próprio arquivo de automação (`Makefile`). Para compilar e rodar qualquer uma das listas, siga o padrão abaixo:

1. Acesse a pasta da lista desejada via terminal:
   ```bash
   cd Lista_0X

```

2. Compile o projeto utilizando o Makefile:
```bash
make programa

```


3. Execute o binário gerado:
```bash
./build/programa

```



---

## Tecnologias Utilizadas

* **Linguagem C**: Linguagem base para o desenvolvimento de todos os algoritmos e estruturas.
* **Makefiles**: Automação do processo de compilação.
* **Valgrind**: Ferramenta utilizada para auditoria de memória, rastreamento de vazamentos (*memory leaks*) e garantia de estabilidade.
* **Git & GitHub**: Controle de versão e portfólio acadêmico.

---

*Desenvolvido com dedicação por **Thiago Lacerda** como parte da jornada de aprendizado em Ciência de Dados e Inteligência Artifical.*