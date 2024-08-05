#include <stdio.h>
#include <stdlib.h>
// Lista duplamente encadeada circular
typedef struct no
{
    int chave;
    struct no *prox, *ant;
} No;

No *criaNo(int valor)
{
    No *novo = (No *)calloc(1, sizeof(No));
    if (novo == NULL)
    {
        printf("Erro de alocacao\n\n");
        exit(1);
    }
    novo->chave = valor;
    novo->prox = NULL;
    novo->ant = NULL;
    return novo;
}

// a) Inserção no início da lista.
No *insereInicio(No *L, int valor)
{
    No *novo = criaNo(valor);
    No *ultimo = NULL;
    if (L == NULL)
    {
        novo->prox = novo;
        novo->ant = novo;
        return novo;
    }
    else
    {
        ultimo = L->ant;
        novo->prox = L;
        novo->ant = ultimo;

        L->ant = novo;
        ultimo->prox = novo;
        return novo;
    }
}

// b) Remoção (free) do primeiro elemento da lista.
No *removePrimeiro(No *L)
{
    No *aux = L;
    No *ultimo = L->ant;
    if (L == NULL)
    {
        printf("\nLista vazia\n");
        return NULL;
    }
    if (L->prox == L)
    {
        free(L);
        return NULL;
    }
    else
    {
        ultimo->prox = aux->prox;
        L->prox->ant = ultimo;
        L = L->prox;

        free(aux);
        return L;
    }
}

// c) Inserção na última posição da lista.
No *insereFinal(No *L, int valor)
{
    No *ultimo = L->ant;
    No *novo = criaNo(valor);

    if (L == NULL)
    {
        novo->prox = novo;
        novo->ant = novo;
        return novo;
    }
    else
    {
        novo->prox = L;
        novo->ant = ultimo;
        ultimo->prox = novo;
        L->ant = novo;
        return L;
    }
}

// d) Remoção (free) do último elemento da lista.
No *removeUltimo(No *L)
{
    No *aux = NULL;
    No *ultimo = L->ant;
    if (L == NULL)
    {
        printf("Lista vazia\n");
        return NULL;
    }
    if (L->ant == L)
    {
        free(L);
        return NULL;
    }
    else
    {
        aux = ultimo->ant;
        aux->prox = ultimo->prox;
        L->ant = aux;
        free(ultimo);
        return L;
    }
}

// e) Remoção (free) de uma chave informada.
No *buscaChave(No *L, int chave)
{
    No *aux = L;
    if (L == NULL)
    {
        printf("Lista vazia, chave nao encontrada");
        return NULL;
    }
    while (aux->prox != L)
    {
        aux = aux->prox;
        if (aux->chave == chave)
        {
            printf("chave encontrada");
            return aux;
        }
    }
    printf("chave nao encontrada");
    return NULL;
}

No *removeChave(No *L, int chave)
{
    No *ch = buscaChave(L, chave);
    No *ultimo = L->ant;
    if (ch == NULL)
    {
        printf("nao ha chave");
        return NULL;
    }
    if (ch->prox == ch)
    {
        free(ch);
        return NULL;
    }
    if (ch == L) // Se a chave está na cabeça da lista
    {
        L = ch->prox;
    }
    else
    {
        ch->ant->prox = ch->prox;
        ch->prox->ant = ch->ant;
        free(ch);
    }
    return L;
}

// f) Impressão da lista.
void imprimeLista(No *L)
{
    if (L == NULL)
    {
        printf("\nLista Vazia\n");
        return;
    }

    No *aux = L;
    do
    {
        printf(" <- %d -> ", aux->chave);
        aux = aux->prox;
    } while (aux != L);
    printf(" (primeiro da lista)\n");
}

int main()
{
    No *lista = NULL;

    // Inserir alguns elementos na lista
    lista = insereInicio(lista, 1);
    lista = insereInicio(lista, 2);
    lista = insereInicio(lista, 3);

    // Imprimir a lista
    imprimeLista(lista);

    lista = removePrimeiro(lista);
    imprimeLista(lista);

    return 0;
}