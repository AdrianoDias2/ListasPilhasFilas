#include <stdio.h>
#include <stdbool.h>

#define TAMANHO_MAXIMO 100

// Estrutura da pilha
typedef struct {
    int itens[TAMANHO_MAXIMO];
    int topo;
} Pilha;

// Inicializa a pilha
void inicializaPilha(Pilha *p) {
    p->topo = -1;
}

// Verifica se a pilha está vazia
bool estaVazia(Pilha *p) {
    return p->topo == -1;
}

// Verifica se a pilha está cheia
bool estaCheia(Pilha *p) {
    return p->topo == TAMANHO_MAXIMO - 1;
}

// Empilha um novo elemento
bool push(Pilha *p, int valor) {
    if (estaCheia(p)) {
        printf("Erro: Pilha cheia\n");
        return false;
    }
    p->itens[++(p->topo)] = valor;
    return true;
}

// Desempilha um elemento
int pop(Pilha *p) {
    if (estaVazia(p)) {
        printf("Erro: Pilha vazia\n");
        return -1; // Valor especial para indicar erro
    }
    return p->itens[(p->topo)--];
}

// Verifica o elemento no topo da pilha
int topo(Pilha *p) {
    if (estaVazia(p)) {
        printf("Erro: Pilha vazia\n");
        return -1; // Valor especial para indicar erro
    }
    return p->itens[p->topo];
}

// Mostra os elementos da pilha
void mostrarPilha(Pilha *p) {
    if (estaVazia(p)) {
        printf("Pilha vazia\n");
        return;
    }
    printf("Pilha: ");
    for (int i = 0; i <= p->topo; i++) {
        printf("%d ", p->itens[i]);
    }
    printf("\n");
}

int main() {
    Pilha p;
    inicializaPilha(&p);

    push(&p, 10);
    push(&p, 20);
    push(&p, 30);

    mostrarPilha(&p);

    printf("Desempilhando: %d\n", pop(&p));
    printf("Desempilhando: %d\n", pop(&p));

    mostrarPilha(&p);

    printf("Elemento no topo: %d\n", topo(&p));

    return 0;
}
