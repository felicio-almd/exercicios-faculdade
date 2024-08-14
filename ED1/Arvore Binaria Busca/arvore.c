#include "arvore.h"

No *criaNo(int ch)
{
    No *novo = (No *)calloc(1, sizeof(No));
    if (!novo)
    {
        printf("Erro de alocacao");
        exit(1);
    }
    novo->chave = ch;
}

No *busca(No *T, int ch)
{
    No *aux = T;
    while (aux != NULL)
    {
        if (aux->chave == ch)
        {
            return aux;
        }

        if (ch < aux->chave)
        {
            aux = aux->esq;
        }
        else
        {
            aux = aux->dir;
        }
    }
    return aux;
}

// funcao de insercao na arvore com recursividade
No *insercao(No *T, int ch)
{
    No *novo = criaNo(ch);
    No *aux = T;
    if (T == NULL)
    {
        T->chave = novo;
        T->dir = NULL;
        T->esq = NULL;
    }
    else if (ch < T->chave)
    {
        T->esq = insercao(T->esq, ch);
    }
    else
    {
        T->dir = insercao(T->dir, ch);
    }
}

No *sucessor(No *ch, No **paisuc)
{
    No *sucessor = NULL;
    sucessor = ch->dir;
    *paisuc = ch;

    while (sucessor != NULL && sucessor->esq != NULL)
    {
        *paisuc = sucessor;
        sucessor = sucessor->esq;
    }
    return sucessor;
}

No *remover(No *T, int ch)
{
    if (T == NULL)
    {
        return T;
    }

    if (ch < T->chave)
    {
        T->esq = remover(T->esq, ch);
    }
    else if (ch > T->chave)
    {
        T->dir = remover(T->dir, ch);
    }
    else
    {
        if (T->esq == NULL)
        {
            No *temp = T->dir;
            free(T);
            return temp;
        }
        else if (T->dir == NULL)
        {
            No *temp = T->esq;
            free(T);
            return temp;
        }

        No *paiSuc = NULL;
        No *sucessor = sucessor(T->dir, &paiSuc);

        T->chave = sucessor->chave;

        T->dir = remover(T->dir, sucessor->chave);
    }

    return T;
}

// falta fazer o nivel da arvore
void imprime(No *T)
{
    if (T == NULL)
    {
        printf("\nARVORE VAZIA\n");
        return;
    }

    // Imprime em ordem (esquerda, raiz, direita)
    if (T->esq != NULL)
    {
        imprime(T->esq);
    }

    printf("%d ", T->chave);

    if (T->dir != NULL)
    {
        imprime(T->dir);
    }
}