#include <stdio.h>
#include <stdlib.h>
// Questão 6: Considere as estruturas seguintes:
typedef struct no
{
    int ch;
    struct no *prox, *ant;
} No;

typedef struct lista
{
    No *inicio, *fim;
} Lista;

// a) Cria uma lista vazia.
Lista *criaLista() // funcao para criar a lista vazia na main
{
    Lista *novo = (Lista *)calloc(1, sizeof(Lista));
    if (novo == NULL)
    {
        printf("erro ao alocar memoria");
        exit(1);
    }
    return novo;
}

No *criaNo(int valor)
{
    No *novo = (No *)calloc(1, sizeof(No));
    if (novo == NULL)
    {
        printf("Erro ao alocar memoria\n");
        exit(1);
    }
    novo->ch = valor;
    novo->prox = NULL;
    novo->ant = NULL;
    return novo;
}

// b) Insere no início da lista.
void insereInicio(Lista *L, int valor)
{
    No *novo = criaNo(valor);
    if (L->inicio == NULL)
    {
        L->inicio = novo;
        L->fim = novo;
    }
    else
    {
        novo->prox = L->inicio;
        L->inicio->ant = novo;
        L->inicio = novo;
    }
}

// c) Insere no final da lista.
void insereFinal(Lista *L, int valor)
{
    No *novo = criaNo(valor);
    if (L->fim == NULL) // Lista vazia
    {
        L->inicio = novo;
        L->fim = novo;
    }
    else
    {
        novo->ant = L->fim;
        L->fim->prox = novo;
        L->fim = novo;
    }
}

// d) Remove uma dada chave da lista.
void removeChave(Lista *L, int valor)
{
    No *aux = L->inicio;
    if (aux == NULL)
    {
        return;
    }
    while (aux != NULL)
    {
        if (aux->ch == valor)
        {
            if (aux->ant != NULL) // Não é o primeiro nó
            {
                aux->ant->prox = aux->prox;
            }
            else // É o primeiro nó
            {
                L->inicio = aux->prox;
            }

            if (aux->prox != NULL) // Não é o último nó
            {
                aux->prox->ant = aux->ant;
            }
            else // É o último nó
            {
                L->fim = aux->ant;
            }

            No *temp = aux->prox; // Salva o próximo nó
            free(aux);            // Libera o nó atual
            aux = temp;           // Move para o próximo nó
        }
        else
        {
            aux = aux->prox; // Move para o próximo nó
        }
    }
}

// e) Recebe duas listas, L1 e L2, e duas chaves, c1 e c2. Busca c1 na lista L1, busca c2 em
// L2. Caso as duas chaves existam nas respectivas listas, realiza a troca das chaves entre
// as listas. Ou seja, retira os nós que contém c1 e c2 de L1 e L2, respectivamente. Insere
// c1 em L2 na posição onde estava c2. Insere c2 em L1 na posição onde estava c1. Sua
// função deve ter complexidade linear.
No *buscaNo(Lista *L, int valor)
{
    No *aux = L->inicio;
    if (L == NULL) // O(1)
    {
        return NULL;
    }
    while (aux != NULL) // O(n)
    {
        if (aux->ch == valor)
        {
            return aux;
        }
        aux = aux->prox;
    }
    printf("No nao encontrado"); // O(1)
    return NULL;
}

void trocaNo(Lista *L1, Lista *L2, int c1, int c2)
{
    No *aux1 = NULL;
    No *aux2 = NULL;
    No *tempAnt = NULL;
    No *tempProx = NULL;
    if (L1 == NULL || L2 == NULL) // O(1)
    {
        printf("Uma das listas é vazia");
        return;
    }
    aux1 = buscaNo(L1, c1);           // O(n)
    aux2 = buscaNo(L2, c2);           // O(n)
    if (aux1 == NULL || aux2 == NULL) // O(1)
    {
        printf("Uma das lista nao tem a chave desejado");
        return;
    }

    if (aux1->ant != NULL) // O(1)
        aux1->ant->prox = aux2;
    else // O(1)
        L1->inicio = aux2;
    if (aux1->prox != NULL) // O(1)
        aux1->prox->ant = aux2;
    else // O(1)
        L1->fim = aux2;

    if (aux2->ant != NULL) // O(1)
        aux2->ant->prox = aux1;
    else // O(1)
        L2->inicio = aux1;
    if (aux2->prox != NULL) // O(1)
        aux2->prox->ant = aux1;
    else // O(1)
        L2->fim = aux1;

    tempAnt = aux1->ant;
    tempProx = aux1->prox;
    aux1->ant = aux2->ant;
    aux1->prox = aux2->prox;
    aux2->ant = tempAnt;
    aux2->prox = tempProx;
}

// Resultado: 0(1) + O(n) = O(n), a função tem complexidade O(n) linear, onde n é o numero de nós das listas combinadas.

// f) Calcule a função de complexidade de tempo da função do item anterior. Conclua com
// a notação assintótica da complexidade calculada.

void imprimeLista(Lista *L)
{
    No *aux = L->inicio;
    while (aux != NULL)
    {
        printf("%d -> ", aux->ch);
        aux = aux->prox;
    }
    printf("\n");
}

int main()
{
    Lista *L1;
    L1 = criaLista();
    insereInicio(L1, 1);
    insereFinal(L1, 2);
    insereFinal(L1, 3);
    imprimeLista(L1);
    removeChave(L1, 2);
    imprimeLista(L1);
    return 0;
}