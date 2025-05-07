# 📋 Gerenciador de Tarefas (Terminal)

Este é um gerenciador de tarefas simples desenvolvido em **C**, com estrutura modular dividida em múltiplos arquivos, e interface no terminal com **destaques coloridos**. O programa permite adicionar, editar, excluir e listar tarefas, além de marcá-las como concluídas.

## 🧱 Estrutura do Projeto

O projeto está dividido nos seguintes arquivos:

- `main.c` — Arquivo principal que inicia o programa e apresenta o menu de interação com o usuário.
- `tarefas.h` — Arquivo de cabeçalho com a definição da estrutura `Tarefa` e das funções.
- `tarefas.c` — Implementação de todas as funcionalidades relacionadas à manipulação de tarefas.
- `cores.h` — Define macros de cores ANSI para estilização da saída no terminal.
- `tarefas.dat` — Arquivo binário onde as tarefas são armazenadas.
- `ultimo_id.dat` — Arquivo auxiliar para persistência do último ID de tarefa criada.

## ⚙️ Funcionalidades

- ✅ Adicionar uma nova tarefa com data e horário.
- ✏️ Editar tarefas existentes.
- 📋 Listar todas as tarefas ativas.
- ☑️ Marcar/desmarcar tarefas como concluídas.
- 🗑️ Excluir tarefas (inativação lógica).
- 💾 Armazenamento persistente em arquivos binários.

## 📁 Exemplo de estrutura da tarefa

```c
// Estrutura para armazenar uma tarefa
typedef struct Tarefa {
    int id;
    char descricao[100];
    char data[20];
    char horario[20];
    int concluida;
    int ativo;  // 1 para ativo, 0 para inativo
} Tarefa;
```

## 🖥️ Ambiente de Desenvolvimento

Este projeto foi desenvolvido e testado em **Linux**, utilizando:

- GCC (GNU Compiler Collection)
- Terminal com suporte a **ANSI escape codes** (para cores)

## 🧪 Compilação e Execução

### Compilação

```bash
gcc main.c tarefas.c -o gerenciador
```

### Execução

```bash
./gerenciador
```

> Nota: Certifique-se de que os arquivos tarefas.dat e ultimo_id.dat estão no mesmo diretório do executável. Eles são criados automaticamente na primeira execução, se não existirem.
> 

## 🎨 Cores no Terminal

A estilização com cores é definida no arquivo `cores.h`, com macros como:

```c
#ifndef CORES_H
#define CORES_H

#define RESETAR "\033[0m"
#define VERDE "\033[32m"
#define AMARELO "\033[33m"
#define VERMELHO "\033[31m"
#define CIANO "\033[36m"

#endif 
```

## 🔒 Licença

Este projeto é de uso acadêmico e pessoal. Sinta-se à vontade para estudar e adaptar.

---