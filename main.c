#include <stdio.h>
#include "tarefas.h" // Inclui o cabeçalho

int main() {
    // Variáveis locais do main
    Tarefa lista_tarefas[limite_tarefas];
    int total_tarefas = 0;
    int opcao;

    while (1) {
        printf("\n--- Gerenciador de Tarefas ---\n");
        printf("1. Adicionar Tarefa\n");
        printf("2. Listar Tarefas\n");
        printf("3. Marcar Tarefa como Concluida\n");
        printf("4. Excluir Tarefa\n");
        printf("5. Sair\n");
        printf("Digite sua opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                // Passamos o endereço (&) de total_tarefas para poder alterá-lo
                adicionarTarefa(lista_tarefas, &total_tarefas);
                break;
            case 2:
                // Aqui só passamos o valor, pois listar não altera a quantidade
                listarTarefas(lista_tarefas, total_tarefas);
                break;
            case 3:
                marcarConcluida(lista_tarefas, total_tarefas);
                break;
            case 4:
                excluirTarefa(lista_tarefas, &total_tarefas);
                break;
            case 5:
                printf("Encerrando programa...\n");
                return 0;
            default:
                printf("Opcao invalida. Tente novamente.\n");
        }
    }
    return 0;
}