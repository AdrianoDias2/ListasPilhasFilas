#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct no
{

    int valor;
    struct no *prox;
} No;

typedef struct pilha
{

    struct pilha *topo;
} Pilha;

void cria_pilha(Pilha *p)
{
    p->topo = NULL;
}

void push(Pilha *p, int val)
{
    No *novoNo = (No *)malloc(sizeof(No));
    if (novoNo == NULL)
    {
        printf("Erro de alocacao de memoria");
        return;
    }
    novoNo->valor = val;
    novoNo->prox = p->topo;
    p->topo = novoNo;
}

int pop(Pilha *p)
{

    if (p->topo == NULL)
    {
        printf("Pilha vazia");

        return -1;
    }

    No *noRemovido = p->topo;
    int val = noRemovido->valor;
    p->topo = noRemovido->prox;
    free(noRemovido);

    return val;
}

bool pilha_vazia(Pilha *p)
{
    return p->topo == NULL;
}

void imprimir_pilha(Pilha *p)
{
    No *aux = p->topo;

    while (aux != NULL)
    {
        printf("%d \n", aux->valor);
        aux = aux->prox;
    }
}



int main()
{

    Pilha *p;

    cria_pilha(p);

    push(p, 10);
    push(p, 20);
    push(p, 30);
    push(p, 40);

    imprimir_pilha(p);

    printf("Depois do pop\n");

    pop(p);
    printf("primeiro pop\n");
    imprimir_pilha(p);
    pop(p);
    printf("segundo pop\n");
    imprimir_pilha(p);
    pop(p);
    printf("terceiro pop\n");
    imprimir_pilha(p);
    pop(p);
    printf("quarto pop\n");
    imprimir_pilha(p);
    pop(p);

    return 0;
}
