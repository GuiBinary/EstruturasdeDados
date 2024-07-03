#include <stdio.h>
#include <stdlib.h>
#include <limits.h>  // Para INT_MIN

// Estrutura para representar uma pilha
typedef struct Pilha {
    int topo;
    int capacidade;
    int* array;
} Pilha;

// Função para criar uma pilha de uma capacidade dada
Pilha* criarPilha(int capacidade) {
    Pilha* pilha = (Pilha*) malloc(sizeof(Pilha));
    pilha->capacidade = capacidade;
    pilha->topo = -1;
    pilha->array = (int*) malloc(pilha->capacidade * sizeof(int));
    return pilha;
}

// Função para verificar se a pilha está cheia
int estaCheia(Pilha* pilha) {
    return pilha->topo == pilha->capacidade - 1;
}

// Função para verificar se a pilha está vazia
int estaVazia(Pilha* pilha) {
    return pilha->topo == -1;
}

// Função para adicionar um item à pilha
void push(Pilha* pilha, int item) {
    if (estaCheia(pilha)) {
        printf("Pilha cheia. Não é possível empilhar o item.\n");
        return;
    }
    pilha->array[++pilha->topo] = item;
    printf("%d empilhado na pilha\n", item);
}

// Função para remover um item da pilha
int pop(Pilha* pilha) {
    if (estaVazia(pilha)) {
        printf("Pilha vazia. Não é possível desempilhar o item.\n");
        return INT_MIN;
    }
    return pilha->array[pilha->topo--];
}

// Função para pegar o item no topo da pilha sem removê-lo
int peek(Pilha* pilha) {
    if (estaVazia(pilha)) {
        printf("Pilha vazia. Não é possível ver o topo.\n");
        return INT_MIN;
    }
    return pilha->array[pilha->topo];
}

// Função principal para testar a implementação da pilha
int main() {
    Pilha* pilha = criarPilha(10);

    push(pilha, 10);
    push(pilha, 20);
    push(pilha, 30);

    printf("%d desempilhado da pilha\n", pop(pilha));
    printf("Topo da pilha é %d\n", peek(pilha));

    return 0;
}
