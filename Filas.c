#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct no
{

    int valor;
    struct no *prox;
} No;

typedef struct fila
{

    No *inicio;
    No *fim;
    int size;

} Fila;

void cria_fila(Fila *f)
{

    f->inicio == NULL;
    f->fim == NULL;
    f->size = 0;
}

bool fila_vazia(Fila *f)
{

    return f->inicio == NULL;
}

void insere_fila(Fila *f, int val)
{
    No *novoNo = (No *)malloc(sizeof(No));

    if (novoNo == NULL)
    {
        printf("Erro de alocacao de memoria");
        return;
    }

    novoNo->valor = val;
    novoNo->prox = NULL;
    f->size ++;

    if (fila_vazia(f))
    {

        f->inicio = novoNo;
        f->fim = novoNo;
    }
    else
    {

        f->fim->prox = novoNo;
        f->fim = novoNo;
    }
}

int remove_fila(Fila *f)
{

    if (fila_vazia(f))
    {
        printf("Erro:Fila vazia");
        return -1;
    }

    No *Noremovido = f->inicio;
    int val = Noremovido->valor;
    f->inicio = Noremovido->prox;
    f->size --;

    if (f->inicio == NULL)
    {
        f->fim == NULL;
    }

    free(Noremovido);

    return val;
}

void imprime_fila(Fila *f)
{
    if (fila_vazia(f))
    {
        printf("FILA VAZIA");
    }

    No *aux = f->inicio;

    while (aux != NULL)
    {
        printf("%d , ", aux->valor);
        aux = aux->prox;
    }
}

int main()
{

    Fila *f;

    cria_fila(f);
    insere_fila(f, 1);
    insere_fila(f, 2);
    insere_fila(f, 1);
    insere_fila(f, 3);
    printf("Fila apos insercoes\n\n");
    imprime_fila(f);
    remove_fila(f);
    printf("\n\nfila apos remocao\n");
    imprime_fila(f);
    remove_fila(f);
    printf("fila apos remocao\n");
    imprime_fila(f);
    remove_fila(f);
    printf("fila apos remocao\n");
    imprime_fila(f);
    remove_fila(f);
    printf("fila apos remocao\n");
    imprime_fila(f);

    return 0;
}