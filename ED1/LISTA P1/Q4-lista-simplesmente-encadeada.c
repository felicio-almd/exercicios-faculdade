#include <stdio.h>
#include <stdlib.h>
// QUESTAO 4 LISTA P1

typedef struct no
{
    int chave;
    struct no *prox;
} No;

// Criar um novo nó, dado uma chave;
No *criaNo(int valor)
{
    No *novo = (No *)calloc(1, sizeof(No));

    if (novo == NULL)
    {
        printf('\nvalor null\n');
        exit(1);
    }
    novo->chave = valor;
    novo->prox = NULL;
    return novo;
}

// Imprimir os números contidos numa lista;
void imprimeLista(No *L)
{
    No *aux = L;

    while (aux != NULL)
    {
        printf("%d -> ", aux->chave);
        aux = aux->prox;
    }
    printf("\n");
}

// Inserir um nó criado no início de uma lista;
No *insereInicio(No *L, int valor)
{
    No *novo = criaNo(valor);
    novo->prox = L;
    return novo;
}

// Inserir um nó criado no final de uma lista;
No *insereFinal(No *L, int valor)
{
    No *novo = criaNo(valor);
    No *aux = L;

    if (L == NULL)
    {
        return novo;
    }

    while (aux->prox != NULL)
    {
        aux = aux->prox;
    }

    aux->prox = novo;
    return L;
}

// Remover todos os nós da lista que possuem informações duplicadas
// (deixe apenas uma ocorrência de cada número e dar free nos nós com valores repetidos);
No *removeNoIgual(No *L)
{
    No *aux = L;
    No *proximo = NULL;
    No *pred = NULL;
    if (L == NULL || L->prox == NULL)
    {
        return L;
    }
    while (aux->prox != NULL && aux != NULL)
    {
        pred = aux;
        proximo = aux->prox;
        while (proximo != NULL)
        {
            if (aux->chave == proximo->chave)
            {
                pred->prox = proximo->prox;
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
    return L;
}

// Imprime o total de ocorrências de um número em uma lista;
void imprimeOcorrencias(No *L, int valor)
{
    int cont = 0;
    No *aux = L;
    if (L == NULL)
    {
        printf("nao ha ocorrencias");
        return;
    }
    else
    {
        while (aux != NULL)
        {
            if (aux->chave == valor)
            {
                cont++;
            }
            aux = aux->prox;
        }
        printf("total de ocorrencias: %d", cont);
    }
}

// Multiplica todos os números da lista por 10;
No *multiplicaChave(No *L)
{
    No *aux = L;

    while (aux != NULL)
    {
        aux->chave = (aux->chave * 10);
        aux = aux->prox;
    }
    return L;
}

// Imprime na tela se uma dada lista está ordenada ou não.
void verificaOrdenada(No *L)
{
    No *aux = L;
    if (L == NULL)
    {
        printf("Lista vazia");
        return;
    }
    else
    {
        while (aux->prox != NULL)
        {
            if (aux->chave > aux->prox->chave)
            {
                printf("\nlista nao ordenada\n");
                break;
            }
            aux = aux->prox;
        }
        printf("\nlista ordenada\n");
    }
}

// Intercale duas listas encadeadas ordenadas. A lista resultante tem que estar ordenada. Sua função deve ter complexidade linear.
No *intercalaOrdenadas(No *L1, No *L2)
{
    // Caso base: se uma lista é vazia, retorna a outra
    if (L1 == NULL) // O(1)
        return L2;
    if (L2 == NULL) // O(1)
        return L1;

    No *L3 = NULL;  // Ponteiro para a nova lista
    No *aux = NULL; // Ponteiro para o nó atual

    // Escolhe o primeiro nó da lista resultado
    if (L1->chave <= L2->chave) // O(1)
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

    // Intercala os elementos restantes
    while (L1 != NULL && L2 != NULL) // O(n)
    {
        if (L1->chave <= L2->chave) // O(1)
        {
            aux->prox = L1;
            L1 = L1->prox;
        }
        else // O(1)
        {
            aux->prox = L2;
            L2 = L2->prox;
        }
        aux = aux->prox;
    }

    // Adiciona os elementos restantes, se houver
    if (L1 != NULL) // O(1)
        aux->prox = L1;
    if (L2 != NULL) // O(1)
        aux->prox = L2;

    return L3;
}

// Calcule a complexidade da função do item anterior.
// =>   O(1) + O(n) = O(n)

int main()
{
    // Criação de uma lista de exemplo: 1 -> 2 -> 3 -> 2 -> 4 -> 3 -> NULL
    No *L1 = criaNo(1);
    L1 = insereFinal(L1, 3);
    L1 = insereFinal(L1, 5);
    L1 = insereFinal(L1, 7);
    No *L2 = criaNo(2);
    L2 = insereFinal(L2, 4);
    L2 = insereFinal(L2, 6);

    No *L3 = NULL;

    printf("Lista original:\n");
    imprimeLista(L1);
    imprimeLista(L2);
    L3 = intercalaOrdenadas(L1, L2);
    imprimeLista(L3);

    return 0;
}