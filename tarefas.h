// O #ifndef verifica se "TAREFAS_H" já foi definido.
#ifndef TAREFAS_H
#define TAREFAS_H

#define limite_tarefas 100

// Definição da Struct
typedef struct {
    char descricao[100];
    int concluida; 
} Tarefa;

// Agora o array e a quantidade são ponteiros para não depender de variáveis globais.
void adicionarTarefa(Tarefa *tarefas, int *qtd);
void listarTarefas(Tarefa *tarefas, int qtd);
void marcarConcluida(Tarefa *tarefas, int qtd);
void excluirTarefa(Tarefa *tarefas, int *qtd);

#endif