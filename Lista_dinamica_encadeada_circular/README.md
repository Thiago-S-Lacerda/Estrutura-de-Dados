# Implementação de Lista Dinâmica Encadeada Circular em C

Repositório criado para a atividade prática da disciplina de **Estrutura de Dados (UFPB)**, focada na implementação, manipulação e otimização de uma **Lista Dinâmica Encadeada Circular** em linguagem C.

---

## Sobre a Atividade

O objetivo desta atividade é aplicar os conceitos avançados de alocação dinâmica, manipulação segura de ponteiros e estruturas encadeadas circulares. Além das operações tradicionais de inserção e remoção, o projeto inclui a resolução de funções avançadas exigidas pelo professor (como busca cíclica, rotação de lista, concatenação e o clássico **Problema de Josephus**).

Também foi implementado um desafio opcional completo explorando uma variação de representação da lista circular, onde **todas** as funções da biblioteca foram adaptadas, além da resolução documentada das perguntas teóricas propostas na lista de exercícios.

---

## Estrutura do Projeto e Organização dos Diretórios

O projeto está organizado nos seguintes diretórios e arquivos:

- **`include/`**: Contém os arquivos de cabeçalho (`.h`).
  - `ListaDinEncadCirc.h`: Protótipos das funções da lista para a abordagem padrão (ponteiro apontando para o início).
  - `ListaDinEncadCircOtm.h`: Protótipos das funções da lista para a abordagem otimizada do desafio.
  - `menu.h`: Protótipos do sistema de menus interativo padrão.
  - `menuOtm.h`: Protótipos do sistema de menus adaptado para a versão otimizada.

- **`src/`**: Contém os arquivos-fonte (`.c`).
  - `ListaDinEncadCirc.c`: Implementação das operações da lista circular padrão e funções da atividade (impressão, maior matrícula, correção de defeitos, busca cíclica, remoção por posição, rotação, concatenação e Josephus).
  - `ListaDinEncadCircOtm.c`: Implementação completa da versão otimizada do desafio opcional, adaptando **todas** as funções da biblioteca para a representação em que o ponteiro da lista guarda o final da estrutura.
  - `menu.c` / `menuOtm.c`: Implementações das interfaces de menu interativas para cada abordagem.
  - `main.c`: Ponto de entrada do programa e testes automatizados/manuais da versão padrão.
  - `mainOtm.c`: Ponto de entrada dedicado aos testes e validações do desafio opcional.

- **Outros arquivos e documentações**:
  - `Respostas.md` (ou arquivo de respostas): Contém as resoluções detalhadas, explicações teóricas e análises de complexidade exigidas em questões específicas da atividade do professor (como análise de defeitos e justificativas de custo).
  - `Documentacao_atividade.pdf`: Documento oficial com os requisitos e instruções detalhadas da prática.
  - `Makefile`: Automação para compilação rápida de ambas as versões do projeto.
  - `README.md`: Documentação principal do repositório.

---

## Diferença entre as Abordagens (Padrão vs. Otimizada)

O repositório contempla duas formas de estruturar a lista dinâmica encadeada circular:

1. **Abordagem Padrão (`ListaDinEncadCirc`)**: 
   - O ponteiro principal (`*li`) armazena o endereço do **início** (primeiro elemento) da lista.
   - Ideal para operações focadas na cabeça da lista, mas exige travessia completa para encontrar o último nó em inserções no final.

2. **Abordagem Otimizada / Desafio Opcional (`ListaDinEncadCircOtm`)**: 
   - O ponteiro principal (`*lf`) armazena o endereço do **final** da lista (cujo campo `prox` aponta para o primeiro elemento).
   - **Vantagem de Desempenho**: Reduz para $O(1)$ o custo de inserção nas duas extremidades (início e fim) e a remoção do início, tornando o acesso às pontas extremamente eficiente. Todo o conjunto de funções do programa foi implementado adaptado para essa lógica.

---

## Como Compilar e Executar

O projeto possui um **Makefile** robusto configurado para compilar tanto a versão padrão quanto a versão otimizada de forma independente.

1. Certifique-se de estar na pasta raiz do projeto.
2. Para compilar **ambas as versões** (`programa` e `programa_otm`), execute:
   ```bash
   make all
   
    ```

*(Ou utilize `make programa` para compilar apenas a versão padrão e `make programa_otm` para a versão otimizada).*

3. Após a compilação, execute o binário desejado para interagir com o sistema de menus:
* Versão Padrão:
```bash
./build/programa

```


* Versão Otimizada (Desafio):
```bash
./build/programa_otm

```





---

## Observações e Ferramentas de Qualidade

* A função **concatena_listas** utiliza uma lista auxiliar interna (implementada diretamente no código) para fins de praticidade. O usuário interage via menu controlando apenas a lista principal.

* **Respostas Teóricas**: Consulte o arquivo de respostas do repositório para conferir a explicação detalhada de defeitos em códigos, custos de rotação/concatenação e a justificativa da remoção no final.


* **Valgrind**: Recomenda-se a verificação de vazamentos de memória em todas as operações de alocação/liberação (`free`) utilizando a ferramenta de diagnóstico:


```bash
valgrind --leak-check=full ./build/programa

```


* O código foi inteiramente desenvolvido seguindo rigorosamente o padrão de compilador `C11` com avisos ativados (`-Wall -Wextra`).