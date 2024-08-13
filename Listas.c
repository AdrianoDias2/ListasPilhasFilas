#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct no
{

    int valor;
    struct no *prox;
} No;

typedef struct lista
{

    struct lista *cabeca;
} Lista;

void cria_lista(Lista *l)
{
    l->cabeca = NULL;
}

void insere_inicio(Lista *l, int val)
{
    No *novoNo = (No *)malloc(sizeof(No));
    if (novoNo == NULL)
    {
        printf("Erro de alocacao de memoria");
        return;
    }

    novoNo->valor = val;
    novoNo->prox = l->cabeca;
    l->cabeca = novoNo;
}

void insere_fim(Lista *l, int val){
    No *novoNo = (No*)malloc(sizeof(No));
    if(novoNo == NULL){
        printf("Erro de alocacao de memoria");
        return;
    }

    novoNo->valor=val;
    novoNo->prox=NULL;
    
    if(l->cabeca == NULL){
        l->cabeca = novoNo;
    }
    else{
        No *temp = l->cabeca;

        while (temp->prox !=NULL)
        {
            temp=temp->prox;
        }
        
        temp->prox= novoNo;
    }
}

