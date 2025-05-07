#include "tarefas.h"
#include "cores.h"

int ultimo_id = 0;


// Implementação de cada função

void adicionarTarefa() {
    Tarefa novaTarefa;

    novaTarefa.id = ++ultimo_id;

    // Recebe os dados do usuário
    printf(CIANO "Digite a descricao da tarefa: " RESETAR);
    getchar();  // Limpa o buffer do teclado
    fgets(novaTarefa.descricao, sizeof(novaTarefa.descricao), stdin);
    novaTarefa.descricao[strcspn(novaTarefa.descricao, "\n")] = 0;  // Remove o '\n' do final

    printf(CIANO "Digite a data (dd/mm/yyyy): " RESETAR);
    scanf("%s", novaTarefa.data);

    printf(CIANO "Digite o horario (hh:mm): " RESETAR);
    scanf("%s", novaTarefa.horario);

    novaTarefa.concluida = 0;  // Por padrão, a tarefa é não concluída
    novaTarefa.ativo = 1;      // Por padrão, a tarefa é ativa

    // Abre o arquivo em modo de "append" binário
    FILE *arquivo = fopen("tarefas.dat", "ab");
    if (!arquivo) {
        perror(AMARELO "Erro ao abrir o arquivo" RESETAR);
        return;
    }

    // Escreve a nova tarefa no arquivo
    fwrite(&novaTarefa, sizeof(Tarefa), 1, arquivo);

    // Fecha o arquivo
    fclose(arquivo);

    printf(VERDE "\nTarefa adicionada com sucesso!\n" RESETAR);
}

void editarTarefa(int id) {
    FILE *arquivo = fopen("tarefas.dat", "rb+");
    if (!arquivo) {
        perror(AMARELO "Erro ao abrir o arquivo" RESETAR);
        return;
    }

    Tarefa tarefa;
    int encontrado = 0;

    // Procura a tarefa pelo ID
    while (fread(&tarefa, sizeof(Tarefa), 1, arquivo) == 1) {
        if (tarefa.id == id && tarefa.ativo) {  // Confirma se a tarefa está ativa
            encontrado = 1;

            printf(VERDE "Tarefa encontrada:\n" RESETAR);
            printf(CIANO "ID: " RESETAR "%d\n", tarefa.id);
            printf(CIANO "Descricao: " RESETAR "%s\n", tarefa.descricao);
            printf(CIANO "Data: " RESETAR "%s\n", tarefa.data);
            printf(CIANO "Horario: " RESETAR "%s\n", tarefa.horario);
            printf("%sConcluida:%s ", CIANO, RESETAR);
                if (tarefa.concluida)
                    printf(VERDE "[X]\n" RESETAR);
                else
                    printf(VERMELHO "[ ]\n" RESETAR);
                printf("----------------------\n");

            // Permite que o usuário insira novos dados
            printf(CIANO"Digite a nova descricao: " RESETAR);
            getchar();  // Limpa o buffer do newline anterior
            fgets(tarefa.descricao, sizeof(tarefa.descricao), stdin);
            tarefa.descricao[strcspn(tarefa.descricao, "\n")] = 0;  // Remove o newline

            printf(CIANO "Digite a nova data (DD/MM/AAAA): " RESETAR);
            getchar();
            fgets(tarefa.data, sizeof(tarefa.data), stdin);
            tarefa.data[strcspn(tarefa.data, "\n")] = 0;

            printf(CIANO "Digite o novo horario (HH:MM): " RESETAR);
            fgets(tarefa.horario, sizeof(tarefa.horario), stdin);
            tarefa.horario[strcspn(tarefa.horario, "\n")] = 0;


            // Move o ponteiro de volta para reescrever a tarefa atual
            fseek(arquivo, -sizeof(Tarefa), SEEK_CUR);
            fwrite(&tarefa, sizeof(Tarefa), 1, arquivo);

            printf(VERDE "\nTarefa atualizada com sucesso!\n" RESETAR);
            break;
        }
    }

    if (!encontrado) {
        printf(AMARELO "Tarefa com ID %d nao encontrada ou inativa.\n" RESETAR, id);
    }

    fclose(arquivo);
}

void verificarTarefas() {

    FILE *arquivo = fopen("tarefas.dat", "rb");
    if (!arquivo) {
        perror(AMARELO "Erro ao abrir o arquivo" RESETAR);
        return;
    }

    // Verifica se o arquivo está vazio
    fseek(arquivo, 0, SEEK_END);
    long tamanhoArquivo = ftell(arquivo);
    if (tamanhoArquivo == 0) {
        printf(AMARELO "Nenhuma tarefa registrada.\n" RESETAR);
        fclose(arquivo);
        return;
    }
    rewind(arquivo); 

    Tarefa tarefas[TAMANHO_BLOCO];
    size_t lidos;

    while ((lidos = fread(tarefas, sizeof(Tarefa), TAMANHO_BLOCO, arquivo)) > 0) {
        for (size_t i = 0; i < lidos; i++) {
            if (tarefas[i].ativo) {  // Exibe apenas tarefas ativas
                printf("----------------------\n");
                printf("%sID:%s %d\n", CIANO, RESETAR, tarefas[i].id);
                printf("%sDescricao:%s %s\n", CIANO, RESETAR, tarefas[i].descricao);
                printf("%sData:%s %s\n", CIANO, RESETAR, tarefas[i].data);
                printf("%sHorario:%s %s\n", CIANO, RESETAR, tarefas[i].horario);
                printf("%sConcluida:%s ", CIANO, RESETAR);
                if (tarefas[i].concluida)
                    printf(VERDE "[X]\n" RESETAR);
                else
                    printf(VERMELHO "[ ]\n" RESETAR);
                printf("----------------------\n");
            }
        }
    }
    fclose(arquivo);
}

void marcarTarefaComoConcluida() {
    int id;
    verificarTarefas();
    printf(CIANO"Digite o ID da tarefa que deseja marcar como concluida/nao concluida: " RESETAR);
    scanf("%d", &id);

    FILE *arquivo = fopen("tarefas.dat", "r+b"); // Abre o arquivo para leitura e escrita em modo binário
    if (arquivo == NULL) {
        perror(AMARELO "Erro ao abrir o arquivo" RESETAR);
        return;
    }

    Tarefa tarefa;
    // Lê as tarefas até encontrar a correspondente ao ID
    while (fread(&tarefa, sizeof(Tarefa), 1, arquivo) == 1) {
        if (tarefa.id == id) {
            tarefa.concluida = !tarefa.concluida; // Alterna o concluida
            fseek(arquivo, -sizeof(Tarefa), SEEK_CUR); // Move o ponteiro de volta
            fwrite(&tarefa, sizeof(Tarefa), 1, arquivo); // Atualiza o arquivo
            printf(VERDE"Tarefa '%s' marcada como %s.\n" RESETAR, tarefa.descricao, tarefa.concluida ? "Concluida" : "Nao concluida");
            fclose(arquivo);
            return;
        }
    }

    printf(AMARELO "Tarefa nao encontrada.\n" RESETAR);
    fclose(arquivo);
}

void excluirTarefa() {
    FILE *arquivo;
    Tarefa tarefa;
    int idExcluir;
    int encontrou = 0;

    verificarTarefas();
    printf("Qual o ID da tarefa que sera excluida? ");
    scanf("%d", &idExcluir);

    // Abre o arquivo binário para leitura e atualização ("rb+").
    arquivo = fopen("tarefas.dat", "rb+");
    if (!arquivo) {
        printf(AMARELO "Erro ao abrir o arquivo!\n" RESETAR);
        return;
    }

    // Procura pela tarefa com o ID especificado.
    while (fread(&tarefa, sizeof(Tarefa), 1, arquivo) == 1) {
        if (tarefa.id == idExcluir) {
            tarefa.ativo = 0;  // Marca a tarefa como inativa.
            encontrou = 1;

            // Volta o cursor e atualiza o registro no arquivo.
            fseek(arquivo, -sizeof(Tarefa), SEEK_CUR);
            fwrite(&tarefa, sizeof(Tarefa), 1, arquivo);
            printf(VERDE "Tarefa com ID %d excluida (marcada como inativa) com sucesso!\n" RESETAR, idExcluir);
            break;
        }
    }

    if (!encontrou) {
        printf(AMARELO "Tarefa com ID %d nao encontrada!\n" RESETAR, idExcluir);
    }

    fclose(arquivo);
}

// Função para salvar o último ID em um arquivo
void salvar_ultimo_id() {
    FILE *arquivo = fopen("ultimo_id.dat", "wb");
    if (arquivo) {
        fwrite(&ultimo_id, sizeof(int), 1, arquivo);
        fclose(arquivo);
    }
}

// Função para carregar o último ID de um arquivo
void carregar_ultimo_id() {
    FILE *arquivo = fopen("ultimo_id.dat", "rb");
    if (arquivo) {
        fread(&ultimo_id, sizeof(int), 1, arquivo);
        fclose(arquivo);
    }
}