#include <stdio.h>
#include <stdlib.h>
// Considere a lista duplamente encadeada
// Declare uma estrutura de uma lista simplesmente encadeada de números inteiros e implemente as seguintes funções:
typedef struct no
{
    int chave;
    struct no *prox;
    struct no *ant;
} No;

// a) Criar um novo nó, dado uma chave.
No *criaNo(int valor)
{
    No *novo = (No *)calloc(1, sizeof(No));

    if (novo == NULL)
    {
        printf("\nErro ao alocar memoria\n");
        exit(1);
    }

    novo->chave = valor;
    novo->prox = NULL;
    novo->ant = NULL;
    return novo;
}

// b) Imprimir os números contidos numa lista.
void imprimeLista(No *L)
{
    No *aux = L;
    while (aux != NULL)
    {
        printf("| %d |->", aux->chave);
        aux = aux->prox;
    }
    printf("\n\n");
}

// c) Inserir um nó criado numa lista ordenada. O resultado deve ser uma lista ordenada.
No *insereOrdenado(No *L, int valor)
{
    No *aux = L;
    No *novo = criaNo(valor);

    if (L == NULL)
    {
        return novo;
    }

    if (valor <= L->chave) // caso o novo for o primeiro da lista
    {
        novo->prox = aux;
        aux->ant = novo;
        return novo;
    }

    while (aux->prox != NULL && valor > aux->prox->chave)
    {
        aux = aux->prox;
    }
    novo->prox = aux->prox;
    if (aux->prox != NULL)
    {
        aux->prox->ant = novo;
    }
    aux->prox = novo;
    novo->ant = aux;
    return L;
}

// d) Remover todos os nós da lista que possuem informações duplicadas (deixe apenas uma
// ocorrência de cada número e dar free nos nós com valores repetidos).
void removeDuplicado(No *L)
{
    No *aux = L;
    No *pred = NULL;
    No *proximo = NULL;

    if (L == NULL || L->prox == NULL)
    {
        return;
    }

    while (aux != NULL && aux->prox != NULL)
    {
        pred = aux;
        proximo = aux->prox;
        while (proximo != NULL)
        {
            if (aux->chave == proximo->chave)
            {
                pred->prox = proximo->prox;
                if (pred->prox != NULL)
                {
                    proximo->prox->ant = pred;
                }
                free(proximo);
                proximo = pred->prox;
            }
            else
            {
                pred = proximo;
                proximo = proximo->prox;
            }
        }
        aux = aux->prox;
    }
}

// e) Intercale duas listas encadeadas ordenadas. A lista resultante tem que estar ordenada.
// Sua função deve ter complexidade linear.
No *concatenaOrdenada(No *L1, No *L2)
{
    No *L3 = NULL;
    No *aux = NULL;

    if (L1 == NULL) // O(1)
        return L2;
    if (L2 == NULL) // O(1)
        return L1;

    if (L1->chave <= L2->chave) // O(1) ver qual a primeira chave
    {
        L3 = L1;
        L1 = L1->prox;
    }
    else // O(1)
    {
        L3 = L2;
        L2 = L2->prox;
    }
    aux = L3;

    while (L1 != NULL && L2 != NULL) // O(n)
    {
        if (L1->chave <= L2->chave) // O(1)
        {
            aux->prox = L1;
            L1->ant = aux; // avança com o ant e liga ele na aux
            L1 = L1->prox; // avança o L1
        }
        else // O(1)
        {
            aux->prox = L2;
            L2->ant = aux;
            L2 = L2->prox;
        }
        aux = aux->prox;
    }

    if (L1 != NULL) // O(1)  quando uma das listas for vazia aux recebe o resto da
    {
        aux->prox = L1;
        L1->ant = aux;
    }
    else // O(1)
    {
        aux->prox = L2;
        L2->ant = aux;
    }

    return L3; // O(1)
}

// f) Calcule a função de complexidade de tempo da função do item anterior.
// Conclua com a notação assintótica da complexidade calculada.

// Resultado: O(n)
// Notação Assintótica: A complexidade de tempo da função intercalaOrdenadas é O(n),
// onde n é o número total de nós nas duas listas combinadas.

int main()
{
    No *L1 = NULL;
    No *L2 = NULL;
    L1 = insereOrdenado(L1, 1);
    L1 = insereOrdenado(L1, 3);
    L1 = insereOrdenado(L1, 9);
    L1 = insereOrdenado(L1, 7);
    L1 = insereOrdenado(L1, 5);
    L1 = insereOrdenado(L1, 3);
    L2 = insereOrdenado(L2, 2);
    L2 = insereOrdenado(L2, 4);
    L2 = insereOrdenado(L2, 6);
    L2 = insereOrdenado(L2, 4);
    imprimeLista(L1);
    imprimeLista(L2);
    printf("\n");
    removeDuplicado(L1);
    imprimeLista(L1);
    return 0;
}