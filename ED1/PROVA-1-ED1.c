// sobre lista simplesmente encadeada sem no cabeca resolva:
#include <stdio.h>
#include <stdlib.h>

// a) declare uma struct para implementar a lista
typedef struct no
{
    int chave;
    struct no *prox;
} No;

// b) Implemente uma função que receba como parâmetro uma lista simples-
// mente encadeada e um valor inteiro n e divida a lista em duas, de tal forma que a
// segunda lista comece no primeiro nó logo após a primeira ocorrência de n na lista
// original. A figura a seguir ilustra essa separação:
// [A figura mostra duas listas encadeadas, representando a separação da lista original em duas]
// Lista original:
// l -> 3 -> 17 -> 5 -> 12 -> 1
// Após a separação (separa(L,5)):
// l -> 3 -> 17 -> 5
// nova lista -> 12 -> 1
// A função deve retornar um ponteiro para a segunda subdivisão da lista original,
// enquanto l deve continuar apontando para o primeiro elemento da primeira subdivisão
// da lista. Trate todos os casos que podem ocorrer neste problema.
No *separa(No *L, int chave)
{
    No *aux = L;
    No *L2 = NULL;
    if (L == NULL)
    {
        printf("Lista vazia\n");
        return NULL;
    }
    while (aux->chave != chave && aux != NULL)
    {
        aux = aux->prox;
    }
    if (aux == NULL)
    {
        printf("chave para separar nao encontrada\n");
        return NULL;
    }
    L2 = aux->prox;
    aux->prox = NULL;
    return L2;
}

// c)  Implemente uma função que recebe duas listas simplemente encadeadas
// e retorna 1 se a segunda lista estiver contida na primeira e 0, caso contrário.
int estaContida(No *L1, No *L2)
{
    No *aux2 = L2;
    No *aux1 = L1;

    if (L1 == NULL)
    {
        printf("L1 vazia\n");
        return 0;
    }
    if (L2 == NULL)
    {
        printf("L2 vazia então está contida em L1\n");
        return 1;
    }

    while (L1 != NULL)
    {
        aux1 = L1;
        // Comparar as listas
        while (aux2 != NULL && aux1->chave == aux2->chave)
        {
            aux1 = aux1->prox;
            aux2 = aux2->prox;
        }

        // Se `aux2` é NULL, significa que L2 foi completamente comparada
        if (aux2 == NULL)
        {
            return 1;
        }

        L1 = L1->prox;
    }

    return 0;
}

// Função para criar um novo nó
No *criarNo(int chave)
{
    No *novo = (No *)malloc(sizeof(No));
    novo->chave = chave;
    novo->prox = NULL;
    return novo;
}

// Função para adicionar um nó no final da lista
void adicionarNo(No **lista, int chave)
{
    No *novo = criarNo(chave);
    if (*lista == NULL)
    {
        *lista = novo;
    }
    else
    {
        No *temp = *lista;
        while (temp->prox != NULL)
        {
            temp = temp->prox;
        }
        temp->prox = novo;
    }
}
// Função para imprimir uma lista (opcional, para facilitar a visualização)
void imprimirLista(No *lista)
{
    while (lista != NULL)
    {
        printf("%d -> ", lista->chave);
        lista = lista->prox;
    }
    printf("NULL\n");
}

int main()
{
    No *L1 = NULL;
    No *L2 = NULL;

    // Criação da lista L1
    adicionarNo(&L1, 3);
    adicionarNo(&L1, 4);
    adicionarNo(&L1, 5);

    // Criação da lista L2
    adicionarNo(&L2, 1);
    adicionarNo(&L2, 2);

    // Imprimir listas para visualização
    printf("Lista L1: ");
    imprimirLista(L1);
    printf("Lista L2: ");
    imprimirLista(L2);

    // Verificar se L2 está contida em L1
    if (estaContida(L1, L2))
    {
        printf("L2 esta contida em L1\n");
    }
    else
    {
        printf("L2 nao esta contida em L1\n");
    }

    // Liberar memória (omissão para simplificação)
    // Implementar liberação de memória se necessário

    return 0;
}