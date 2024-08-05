#include <stdio.h>
#include <stdlib.h>
// lista simplesmente encadeada circular
typedef struct no
{
    int chave;
    struct no *prox;
} No;

No *criaNo(int chave)
{
    No *novo = (No *)calloc(1, sizeof(No));
    if (novo == NULL)
    {
        printf("Erro ao alocar memória!\n");
        exit(1);
    }
    novo->chave = chave;
    novo->prox = NULL;
    return novo;
}

// a)Inserção no início da lista.
No *insereInicio(No *L, int valor)
{
    No *novo = criaNo(valor);
    No *aux = L;
    if (L == NULL)
    {
        novo->prox = novo;
        return novo;
    }
    while (aux->prox != L)
    {
        aux = aux->prox;
    }
    novo->prox = L;
    aux->prox = novo;
    return novo;
}

// b) Remoção (free) do primeiro elemento da lista.
No *removeInicio(No *L)
{
    No *aux = L;
    if (L == NULL)
    {
        printf("Lista vazia\n");
        return NULL;
    }
    while (aux->prox != L)
    {
        aux = aux->prox;
    }
    No *temp = aux->prox;
    aux->prox = L->prox;
    L = L->prox;
    free(temp);
    return L;
}

// c) Inserção na última posição da lista. // é igual insere inicio mas retorna L ao inves de novo
No *insereFim(No *L, int valor)
{
    No *aux = L;
    No *novo = criaNo(valor);
    if (L == NULL)
    {
        novo->prox = novo;
        return novo;
    }
    while (aux->prox != L)
    {
        aux = aux->prox;
    }
    novo->prox = L;
    aux->prox = novo;
    return L;
}

// d) Remoção (free) do último elemento da lista.
No *removeFinal(No *L)
{
    No *aux = L;
    No *pred = L;
    if (L == NULL)
    {
        printf("\nlista vazia\n");
        return NULL;
    }
    while (aux->prox != L)
    {
        pred = aux;
        aux = aux->prox;
    }
    pred->prox = aux->prox;
    free(aux);
    return L;
}

// e) Remoção (free) de uma chave informada.
No *removeChave(No *L, int valor)
{
    No *aux = L;
    No *pred = NULL;
    No *inicio = L;
    No *ultimo = NULL;
    if (L == NULL)
    {
        printf("\nlista vazia\n");
        return NULL;
    }
    do
    {
        if (aux->chave == valor)
        {
            if (aux->prox == aux) // Se o nó a ser removido for o único nó na lista
            {
                free(aux);
                return NULL;
            }
            ultimo = aux;
            while (ultimo->prox = L)
            {
                ultimo = ultimo->prox;
            }
            if (pred == NULL)
            {
                L = aux->prox;
            }
            else
            {
                pred->prox = aux->prox;
            }
            // Atualizar o último nó para apontar para o novo início
            ultimo->prox = L;
            free(aux);
            return L;
        }
        pred = aux;
        aux = aux->prox;
    } while (aux != inicio);

    printf("\nchave nao encontrada\n");
    return L;
}

// f) Impressão da lista.
void imprimeLista(No *L)
{
    No *aux = L;
    if (L == NULL)
    {
        printf("A lista está vazia.\n");
        return;
    }

    do
    {
        printf("%d -> ", aux->chave);
        aux = aux->prox;
    } while (aux != L);
    printf("(primeiro da lista)\n");
}

int main()
{
    No *L1 = NULL;
    L1 = insereInicio(L1, 2);
    L1 = insereInicio(L1, 1);
    imprimeLista(L1);
    L1 = removeInicio(L1);
    imprimeLista(L1);
    L1 = insereFim(L1, 3);
    L1 = insereFim(L1, 4);
    L1 = insereFim(L1, 5);
    imprimeLista(L1);
    L1 = removeFinal(L1);
    imprimeLista(L1);
    return 0;
}
