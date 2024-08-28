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
    novo->esq = NULL;
    novo->dir = NULL;
    return novo;
}

No *busca(No *T, int ch, No **pred)
{
    No *aux = T;

    while (aux != NULL)
    {
        if (ch == aux->chave)
        {
            return aux;
        }

        *pred = aux;

        if (ch < aux->chave)
        {
            *pred = aux;
            aux = aux->esq;
        }
        if (ch > aux->chave)
        {
            *pred = aux;
            aux = aux->dir;
        }
    }
    return NULL;
}

// funcao de insercao na arvore com recursividade
No *insercao(No *T, int ch)
{
    if (T == NULL)
    {
        // Create and return a new node if the tree is empty
        return criaNo(ch);
    }

    if (ch < T->chave)
    {
        // Insert into the left subtree
        T->esq = insercao(T->esq, ch);
    }
    else if (ch > T->chave)
    {
        // Insert into the right subtree
        T->dir = insercao(T->dir, ch);
    }

    // After insertion, you might want to balance the tree (not implemented here)

    return T;
}

No *sucessor(No *ch, No **paisuc)
{
    No *sucessor = ch->dir;
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
        No *suc = sucessor(T, &paiSuc);

        T->chave = suc->chave;

        if (paiSuc->esq == suc)
        {
            paiSuc->esq = suc->dir;
        }
        else
        {
            paiSuc->dir = suc->dir;
        }

        free(suc);
    }

    return T;
}

// Impressao em ordem
void imprime(No *T, int nivel)
{
    int i;
    if (T)
    {
        imprime(T->dir, nivel + 1);
        for (i = 0; i < nivel; i++)
            printf("\t");
        printf("%d\n", T->chave);
        imprime(T->esq, nivel + 1);
    }
}

/*

void imprimePosOrdem(No *T)
{
    if (T == NULL)
    {
        printf("\nARVORE VAZIA\n");
        return;
    }

    // Primeiro visita o filho esquerdo
    imprimePosOrdem(T->esq);

    // Depois visita o filho direito
    imprimePosOrdem(T->dir);

    // Por último, visita o nó raiz
    printf("%d ", T->chave);
}

void imprimePreOrdem(No *T)
{
    if (T == NULL)
    {
        printf("\nARVORE VAZIA\n");
        return;
    }

    printf("%d ", T->chave);

    // Primeiro visita o filho esquerdo
    imprimePreOrdem(T->esq);
    // Depois visita o filho direito
    imprimePreOrdem(T->dir);
} */