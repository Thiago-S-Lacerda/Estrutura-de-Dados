# Implementação de Lista Sequencial Estática em C

Repositório criado para a atividade prática da disciplina de **Estrutura de Dados**, focada na implementação e manipulação de uma **Lista Sequencial Estática** em linguagem C.

---

## Sobre a Atividade

O objetivo principal desta atividade é colocar em prática os conceitos de alocação estática e manipulação de listas, implementando novas operações solicitadas pelo professor e integrando-as a um sistema de testes funcional.

### Estrutura do Projeto

O projeto está organizado nos seguintes diretórios e arquivos:

* **`include/`**: Contém os arquivos de cabeçalho (`.h`).
* `lista.h`: Protótipos das funções da lista (incluindo as novas funcionalidades).
* `menu.h`: Protótipos do sistema de menus.


* **`src/`**: Contém os arquivos-fonte (`.c`).
* `lista.c`: Implementação das operações da lista.
* `menu.c`: Implementação da interface de menu interativa.
* `main.c`: Ponto de entrada do programa e testes automatizados/manuais.


* **`Makefile`**: Automação para compilação do projeto.
* **`README.md`**: Explicação detalhada da proposta da atividade.
* **`Documentacao_atividade`**: Documento oficial com os requisitos pedidos pelo professor.

---

## 🛠️️ Como Compilar e Executar

O projeto possui um **Makefile** para facilitar o processo de compilação no terminal.

1. Certifique-se de estar na pasta raiz do projeto.
2. Execute o seguinte comando para compilar:

```bash
make programa

```

3. Após a compilação bem-sucedida, execute o binário gerado para interagir com o mini sistema de testes e verificar o funcionamento de todas as funções implementadas.

---

## Observações

* Por se tratar de uma estrutura **estática**, a capacidade máxima da lista é limitada pelo tamanho definido previamente em código.
* O programa de testes (`main.c`) foi estruturado para demonstrar de forma simples e direta o comportamento de cada função desenvolvida.
* **Função de Mesclagem (`mescla_listas`)**: Junta duas listas em uma nova estrutura (atualmente testada com uma lista padrão gerada diretamente no código).

---
