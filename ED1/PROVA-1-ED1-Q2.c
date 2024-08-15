// sobre lista duplamente encadeada sem no cabeca resolva:
#include <stdio.h>
#include <stdlib.h>

// a) declare uma struct para implementar a lista
typedef struct no
{
    int chave;
    struct no *prox, *ant;
} No;

No *removeChave(No *L, int x)
{
    No *aux = L;
    if (L == NULL)
    {
        printf("Lista vazia\n");
    }
    while (aux != NULL && aux->chave != x)
    {
        aux = aux->prox;
    }
    if (aux == NULL)
    {
        printf("nao achou a chave");
        return NULL;
    }
    if (aux->ant == NULL)
    {
        L = L->prox;
    }
    aux->ant->prox = aux->prox;
    aux->prox->ant = aux->ant;
    free(aux);
}

No *intercalaOrdenada(No *L1, No *L2)
{
    No *aux1 = NULL;
    No *aux2 = NULL;
    if (L1 == NULL)
        return L2;
    if (L2 == NULL)
        return L1;
    if (L1->chave < L2->chave)
    {
        aux1 = L1;
        aux2 = L2;
    }
    else
    {
        aux1 = L2;
        aux2 = L1;
    }

    aux1 = aux1->prox;
    while (aux1 != NULL)
    {
        if (aux1->chave < aux2->chave)
        {
            aux1 = aux1->prox;
        }
        aux1->ant->prox = aux2;
        aux2->ant = aux1->ant;
        aux1->ant = aux2;
        aux2 = aux2->prox;
    }
    aux2->prox = aux1;
    L1->prox = aux2;
    aux2->ant = L1;
    return L1;
}

int main()
{
    return 0;
}