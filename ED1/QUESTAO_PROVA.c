#include <stdio.h>
#include <stdlib.h>

typedef struct no
{
    int chave;
    struct no *prox;
    struct no *ant;
} No;

No *criaNo(int valor)
{
    No *novo;
    novo = (No *)calloc(1, sizeof(No));
    if (novo == NULL)
    {
        printf("Erro de alocação\n\n");
        exit(1);
    }
    novo->chave = valor;
    novo->prox = novo;
    novo->ant = novo;
    return novo;
}

No *maior(No *L, int k)
{
    int count = 1; // O(1) Inicializando count com 1, pois vamos começar do primeiro elemento
    No *aux = L;   // O(1)

    if (aux == NULL) // O(1)
    {
        return NULL; // Lista vazia - O(1)
    }
    // Percorrer a lista para encontrar o k-ésimo maior elemento
    do
    {
        if (count == k) // O(n-1)
        {
            return aux; // O(n-1)
        }
        aux = aux->ant; // O(n-1)
        count++;        // O(n-1)
    } while (aux != L->ant); // O(n) - Percorre a lista até voltar ao nó inicial

    if (count < k) // O(1) - significa que a lista nao tem k elementos
    {
        return NULL; // O(1)
    }
} // Complexidade total = O(n)
