#ifndef TAREFAS_H
#define TAREFAS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estrutura para armazenar uma tarefa
typedef struct Tarefa {
    int id;
    char descricao[100];
    char data[20];
    char horario[20];
    int concluida;
    int ativo;  // 1 para ativo, 0 para inativo
} Tarefa;

#define TAMANHO_BLOCO (sizeof(Tarefa) * 10)

// Declaração das funções
void adicionarTarefa();
void editarTarefa(int id);
void verificarTarefas();
void marcarTarefaComoConcluida();
void excluirTarefa();
void carregar_ultimo_id();
void salvar_ultimo_id();

#endif // TAREFAS_H
