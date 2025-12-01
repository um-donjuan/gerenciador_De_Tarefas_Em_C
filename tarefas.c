#include <stdio.h>
#include <string.h>
#include "tarefas.h" // Inclui o cabeçalho

// Função para adicionar
// Recebe o ponteiro para o array e o ponteiro para a quantidade (*qtd)
void adicionarTarefa(Tarefa *tarefas, int *qtd) {
    if (*qtd >= limite_tarefas) {
        printf("Limite maximo de tarefas atingido!\n");
        return;
    }

    printf("Digite a descricao da nova tarefa: ");
    getchar(); 
    // Acessamos o índice usando (*qtd)
    fgets(tarefas[*qtd].descricao, 100, stdin); 

    tarefas[*qtd].descricao[strcspn(tarefas[*qtd].descricao, "\n")] = 0; 
    tarefas[*qtd].concluida = 0;

    (*qtd)++; // Incrementa o valor 
    printf("Tarefa adicionada com sucesso!\n");
}

// Função para listar
// neste caso, qtd é apenas um int, pois a quantidade não será alterada
void listarTarefas(Tarefa *tarefas, int qtd) {
    if (qtd == 0) {
        printf("Nenhuma tarefa cadastrada.\n");
        return;
    }

    //condição ? verdadeira ou falsa
    // Se concluida for 1, imprime 'X', senão ' '
    printf("\n--- Lista de Tarefas ---\n");
    for (int i = 0; i < qtd; i++) {
        printf("%d - [%c] %s\n", 
            i + 1, 
            tarefas[i].concluida ? 'X' : ' ', 
            tarefas[i].descricao
        );
    }
}

// Função para marcar a tarefa concluída
void marcarConcluida(Tarefa *tarefas, int qtd) {
    int id;
    listarTarefas(tarefas, qtd);

    printf("\nDigite o numero da tarefa para marcar como concluida: ");
    scanf("%d", &id);

    if (id < 1 || id > qtd) {
        printf("Tarefa invalida.\n");
        return;
    }

    tarefas[id - 1].concluida = 1;
    printf("Tarefa marcada como concluida!\n");
}

// Função para excluir a tarefa
// Recebe ponteiro *qtd pois vamos diminuir o número total de tarefas
void excluirTarefa(Tarefa *tarefas, int *qtd) {
    int id;
    listarTarefas(tarefas, *qtd); // Passamos o valor apontado por qtd

    printf("\nDigite o numero da tarefa para excluir: ");
    scanf("%d", &id);

    if (id < 1 || id > *qtd) {
        printf("Tarefa invalida.\n");
        return;
    }

    for (int i = id - 1; i < *qtd - 1; i++) {
        tarefas[i] = tarefas[i + 1];
    }

    (*qtd)--; // Decrementa o contador original
    printf("Tarefa excluida com sucesso!\n");
}