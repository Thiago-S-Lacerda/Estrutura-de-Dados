# Implementação de Lista Dinâmica Encadeada em C

Repositório criado para a atividade prática da disciplina de **Estrutura de Dados**, focada na implementação e manipulação de uma **Lista Dinâmica Encadeada** em linguagem C.

---

## Sobre a Atividade

O objetivo desta atividade é aplicar os conceitos aprendidos em sala de aula sobre alocação dinâmica e estruturas encadeadas, manipulando ponteiros com segurança e implementando **novas funcionalidades** requisitadas pelo professor.

---

## Estrutura do Projeto

O projeto está organizado nos seguintes diretórios e arquivos:

* **`include/`**: Contém os arquivos de cabeçalho (`.h`).
  * `ListaDinEncad.h`: Protótipos das funções da lista (separando as funções tradicionais das novas funcionalidades exigidas).
  * `menu.h`: Protótipos do sistema de menus.

* **`src/`**: Contém os arquivos-fonte (`.c`).
  * `ListaDinEncad.c`: Implementação das operações e das novas funções da lista.
  * `menu.c`: Implementação da interface de menu interativa.
  * `main.c`: Ponto de entrada do programa e testes automatizados/manuais.

* **`Makefile`**: Automação para compilação rápida e eficiente do projeto.
* **`README.md`**: Documentação detalhada da proposta e execução da atividade.
* **`Documentacao_atividade.pdf`**: Documento oficial com os requisitos e instruções do professor.

---

## Como Compilar e Executar

O projeto possui um **Makefile** configurado para facilitar a compilação via terminal.

1. Certifique-se de estar na pasta raiz do projeto.
2. Execute o seguinte comando para compilar:
   ```bash
   make programa
    ```

3. Após a compilação bem-sucedida, execute o binário gerado para interagir com o sistema de menus e testar as operações implementadas:

```bash
./programa

```

---

## Observações

* O programa de testes (`main.c`) foi estruturado para demonstrar o comportamento de cada função desenvolvida de forma limpa.
* **Função de Mesclagem (`mescla_listas`)**: Responsável por juntar duas listas em uma nova estrutura (atualmente testada com uma lista padrão gerada diretamente no código).

---