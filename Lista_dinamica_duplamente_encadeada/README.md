# Implementação de Lista Dinâmica Duplamente Encadeada em C

Repositório criado para a atividade prática da disciplina de Estrutura de Dados da UFPB, focada na implementação, manipulação e otimização de uma Lista Dinâmica Duplamente Encadeada e sua variação circular em linguagem C.

---

## Sobre a Atividade

O objetivo desta atividade é aplicar os conceitos avançados de alocação dinâmica, manipulação bidirecional de ponteiros com os campos `ant` e `prox`, e verificação de consistência estrutural. O projeto inclui a implementação das funções exigidas pelo professor, tais como percurso inverso, verificação de consistência, remoção por posição e valor, movimentação para o início, inversão da lista no lugar e verificação de palíndromos.

Além disso, foi implementado um desafio opcional completo explorando a variação de **Lista Duplamente Encadeada Circular**, onde **todas** as funções da biblioteca foram adaptadas para essa estrutura, juntamente com a resolução documentada das perguntas teóricas.

---

## Estrutura do Projeto e Organização dos Diretórios

O projeto está organizado nos seguintes diretórios e arquivos:

- **include/**: Contém os arquivos de cabeçalho.
  - `ListaDinEncadDupla.h`: Protótipos das funções da lista para a abordagem padrão duplamente encadeada linear.
  - `ListaDinEncadDuplaOtm.h`: Protótipos das funções da lista para a abordagem otimizada e circular duplamente encadeada do desafio opcional.
  - `menu.h`: Protótipos do sistema de menus interativo padrão.
  - `menuOtm.h`: Protótipos do sistema de menus adaptado para a versão circular otimizada.

- **src/**: Contém os arquivos-fonte.
  - `ListaDinEncadDupla.c`: Implementação das operações da lista duplamente encadeada padrão e funções da atividade (percurso inverso, consistência, remoção por posição e valor, inversão e palíndromos).
  - `ListaDinEncadDuplaOtm.c`: Implementação completa da versão circular duplamente encadeada do desafio opcional, adaptando **todas** as funções da biblioteca para essa representação.
  - `menu.c` e `menuOtm.c`: Implementações das interfaces de menus interativos para cada abordagem.
  - `main.c`: Ponto de entrada do programa e testes automatizados e manuais da versão padrão.
  - `mainOtm.c`: Ponto de entrada dedicado aos testes e validações da versão circular otimizada.

- **Outros arquivos e documentações**:
  - `Respostas.md`: Contém as resoluções detalhadas, explicações teóricas e análises de complexidade exigidas nas questões da atividade do professor.
  - `Documentacao_atividade.pdf`: Documento oficial com os requisitos e instruções detalhadas da prática.
  - `Makefile`: Automação para compilação rápida de ambas as versões do projeto.
  - `README.md`: Documentação principal do repositório.

---

## Diferença entre as Abordagens (Linear vs. Circular Dupla)

O repositório contempla duas formas de estruturar a lista dinâmica duplamente encadeada:

1. **Abordagem Padrão (ListaDinEncadDupla)**: 
   - Lista dinâmica duplamente encadeada linear tradicional, onde o primeiro elemento possui `ant` igual a `NULL` e o último possui `prox` igual a `NULL`.
   - Ideal para percursos bidirecionais seguros e validação de consistência entre os encadeamentos.

2. **Abordagem Otimizada e Desafio Opcional (ListaDinEncadDuplaOtm)**: 
   - Lista circular duplamente encadeada, onde o campo `prox` do último aponta para o primeiro e o campo `ant` do primeiro aponta para o último.
   - **Vantagem de Desempenho**: Garante complexidade $O(1)$ em inserções e remoções em ambas as extremidades (`*li` aponta para o início e `(*li)->ant` fornece acesso imediato ao final). Todo o conjunto de funções do programa foi implementado e adaptado para essa lógica circular.

---

## Como Compilar e Executar

O projeto possui um Makefile robusto configurado para compilar tanto a versão padrão quanto a versão otimizada de forma independente.

1. Certifique-se de estar na pasta raiz do projeto.
2. Para compilar ambas as versões de programa e programa otimizado, execute:
   ```bash
   make all

    ```

*(Ou utilize `make programa` para compilar apenas a versão padrão e `make programa_otm` para a versão otimizada).*

3. Após a compilação, execute o binário desejado para interagir com o sistema de menus:
* Versão Padrão:
    ```bash
    ./build/programa

    ```


* Versão Otimizada / Circular do Desafio:
    ```bash
    ./build/programa_otm

    ```


---

## Observações e Ferramentas de Qualidade

* **Respostas Teóricas**: Consulte o arquivo de respostas do repositório para conferir a explicação detalhada sobre percurso reverso, consistência de ponteiros, análise de erros, custos de operações e palíndromos.


* **Valgrind**: Recomenda-se a verificação de vazamentos de memória em todas as operações de alocação e liberação utilizando a ferramenta de diagnóstico:
```bash
valgrind --leak-check=full ./build/programa

```


* O código foi inteiramente desenvolvido seguindo rigorosamente o padrão de compilador C11 com avisos ativados (`-Wall -Wextra`).
