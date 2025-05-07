#include "tarefas.h"
#include "cores.h"

int main(){
    
    carregar_ultimo_id();

    int opcaoDeTarefa = 0;
    
    do {
        printf(CIANO "\n*******************************************\n" RESETAR);
        printf(CIANO "SISTEMA DE GERENCIAMENTO DE TAREFAS         \n" RESETAR);
        printf(CIANO "*******************************************\n" RESETAR);


        printf("%s1.%s Adicionar uma nova tarefa\n", VERDE, RESETAR);
        printf("%s2.%s Editar uma tarefa\n", VERDE,  RESETAR); //realiza alguma alteração necessária na tarefa desejada
        printf("%s3.%s Verificar tarefas\n", VERDE, RESETAR); //mostra a lista das tarefas adicionadas e seu status
        printf("%s4.%s Marcar tarefa como concluida\n", VERDE, RESETAR);
        printf("%s5.%s Excluir uma tarefa\n", VERDE, RESETAR);        
        printf("%s0.%s Sair\n", VERMELHO, RESETAR);
        printf(CIANO "*******************************************\n" RESETAR);
    
        printf("Escolha uma opcao: ");
        scanf("%d", &opcaoDeTarefa);
        printf("\n");
        
        switch (opcaoDeTarefa) {
            case 1:
                adicionarTarefa();//função adicionar tarefa 
            break;
    
            case 2: 
            {
                int id;
                verificarTarefas();
                printf("Digite o ID da tarefa desejada:");
                scanf("%d", &id);
                editarTarefa(id);//função editar uma tarefa 
                break;
            }

            case 3:
                verificarTarefas();//função verificar tarefas 
            break;
            
            case 4:
                marcarTarefaComoConcluida();//função marcar tarefa como concluida 
            break;
            
            case 5:
                excluirTarefa();//função excluir uma tarefa 
            break;
            
            case 0:
                printf(VERMELHO "Finalizando...\n" RESETAR);
            break;
            
            default:
                printf(AMARELO "Opcao Invalida! Tente Novamente:\n" RESETAR);
            break;
        }

    } while (opcaoDeTarefa != 0);

    salvar_ultimo_id();
    return 0;
}