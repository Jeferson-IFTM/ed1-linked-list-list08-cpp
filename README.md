# ed1-linked-list-list08-cpp

**Estrutura de Dados I** — IFTM Campus Patrocínio — TADS, 3º período (noturno)
**Lista 08:** Técnicas Avançadas em Listas Encadeadas (C++)
**Professor:** Júnio Moreira

> Aluno: _preencher nome_ — Matrícula: _preencher_

## Estrutura

```
ed1-linked-list-list08-cpp/
├── CMakeLists.txt
├── README.md
├── .gitignore
├── include/
│   ├── List.h
│   └── LinkedList.h
└── src/
    ├── Exer01_MiddleNode.cpp
    ├── Exer02_PalindromeList.cpp
    ├── Exer03_RemoveDuplicates.cpp
    ├── Exer04_OddEvenList.cpp
    └── Exer05_AddTwoNumbers.cpp
```

Cada questão é um executável independente, com `main` próprio, que lê da entrada padrão (stdin) e escreve na saída padrão.

## Requisitos

- Compilador C++17 (g++ ≥ 8, clang ≥ 7 ou MSVC 2019+)
- CMake ≥ 3.14 (opcional)

## Compilação

### Com CMake

```bash
git clone <URL-DO-REPOSITORIO>
cd ed1-linked-list-list08-cpp

cmake -S . -B build
cmake --build build
```

Os executáveis ficam em `build/` (ou `build/Debug/` no Visual Studio).

### Com g++ (sem CMake)

```bash
mkdir -p build
for e in Exer01_MiddleNode Exer02_PalindromeList Exer03_RemoveDuplicates Exer04_OddEvenList Exer05_AddTwoNumbers; do
  g++ -std=c++17 -Wall -Wextra -Iinclude src/$e.cpp -o build/$e
done
```

### CLion

Abra a pasta, escolha o alvo (`Exer01_MiddleNode`, ...) e clique em **Run**. Para fornecer a entrada, use *Edit Configurations > Redirect input from*.

## Execução

Digite a entrada e pressione Enter, ou use `printf`/`echo`:

```bash
echo "1 2 3 4 5 6"        | ./build/Exer01_MiddleNode       # 4 5 6
echo "1 2 2 1"            | ./build/Exer02_PalindromeList   # true
echo "1 1 2 3 3"          | ./build/Exer03_RemoveDuplicates # 1 2 3
echo "2 1 3 5 6 4 7"      | ./build/Exer04_OddEvenList      # 2 3 6 7 1 5 4
printf "2 4 3\n5 6 4\n"   | ./build/Exer05_AddTwoNumbers     # 7 0 8
```

No PowerShell: `"1 2 3 4 5" | .\build\Exer01_MiddleNode.exe`. A Questão 5 recebe duas linhas: `"2 4 3", "5 6 4" | .\build\Exer05_AddTwoNumbers.exe`.

### Verificação de memória (opcional)

```bash
cmake -S . -B build-asan -DENABLE_SANITIZERS=ON
cmake --build build-asan
echo "1 1 2 3 3" | ./build-asan/Exer03_RemoveDuplicates
```

## Resumo das soluções

| # | Arquivo | Técnica | Tempo | Espaço |
|---|---------|---------|-------|--------|
| 1 | `Exer01_MiddleNode.cpp` | `slow` anda 1 nó e `fast` anda 2; retorna o 2º central se N for par | O(N) | O(1) |
| 2 | `Exer02_PalindromeList.cpp` | Acha a metade, inverte a 2ª metade, compara e restaura a lista | O(N) | O(1) |
| 3 | `Exer03_RemoveDuplicates.cpp` | Compara `current` com `next`; religa o `next` e depois dá `delete` no duplicado | O(N) | O(1) |
| 4 | `Exer04_OddEvenList.cpp` | Dois ponteiros (ímpares e pares) reencadeados in-place; une as duas partes | O(N) | O(1) |
| 5 | `Exer05_AddTwoNumbers.cpp` | Soma dígito a dígito com `carry` e nó sentinela; cria nó extra se sobrar transporte | O(max(N, M)) | O(1) auxiliar* |

\* A lista resultante é nova (O(max(N, M)) de saída), mas não há estruturas auxiliares além dela.

## Entrega

1. Criar o repositório `ed1-linked-list-list08-cpp` no GitHub.
2. Enviar o código:

   ```bash
   git init
   git add .
   git commit -m "Lista 08: tecnicas avancadas em listas encadeadas"
   git branch -M main
   git remote add origin https://github.com/<usuario>/ed1-linked-list-list08-cpp.git
   git push -u origin main
   ```

3. Anexar o link do repositório no Moodle.
4. Segunda etapa: enviar o vídeo demonstrativo, conforme orientação no Moodle.
