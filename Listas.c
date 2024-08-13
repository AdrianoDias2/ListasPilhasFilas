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

void remove_lista(Lista *l, int val){
    if(l->cabeca == NULL){
        printf("Lista vazia");
        return;
    }
    No *temp = l->cabeca;
    No *anterior = NULL;

    while (temp != NULL && temp->valor != val)
    {
        anterior=temp;
        temp= temp->prox;
    }
    if(temp == NULL){
        printf("Valor nao encontrado");
        return;
    }
    if(anterior == NULL){
        l->cabeca= temp->prox;

    }
    else{
    anterior->prox=temp->prox;
    }
    free(temp);
}

No* busca(Lista *l, int val){

    No *temp = l->cabeca;

    while (temp != NULL)
    {
        if(temp->valor == val){
            return temp;
        }
        temp=temp->prox;
    }
    return NULL;
}

void imprime_lista(Lista *l){

    No *temp = l->cabeca;

    printf("\n-----Comeco da lista-----\n");

    while (temp != NULL)
    {
        printf("%d - ",temp->valor);
        temp=temp->prox;
    }

    printf("\n-----Fim da lista------\n");
    
}

int main(){

    Lista *l;

    cria_lista(l);
    insere_inicio(l,10);
    insere_inicio(l,110);
    imprime_lista(l);
    insere_inicio(l,102);
    insere_inicio(l,100);
    imprime_lista(l);
    insere_fim(l, 9);
    imprime_lista(l);
    insere_fim(l, 7);
    imprime_lista(l);
    remove_lista(l,100);
    remove_lista(l,100);
    imprime_lista(l);



    return 0;
}