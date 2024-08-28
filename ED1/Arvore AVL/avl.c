#include "avl.h"

NoAvl *criaNo(int ch)
{
    NoAvl *novo = (NoAvl *)calloc(1, sizeof(NoAvl));
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

int altura(NoAvl *n)
{
    if (n == NULL)
        return 0;
    return n->altura;
}

int fatorBalanceamento(NoAvl *n)
{
    if (n == NULL)
        return 0;
    return altura(n->esq) - altura(n->dir);
}

void atualizarAltura(NoAvl *n)
{
    if (n != NULL)
    {
        n->altura = 1 + max(altura(n->esq), altura(n->dir));
    }
}

// rotações da arvore AVL
NoAvl *rotacionarDireita(NoAvl *y)
{
    NoAvl *x = y->esq;
    NoAvl *T2 = x->dir;

    x->dir = y;
    y->esq = T2;

    atualizarAltura(y);
    atualizarAltura(x);

    return x;
}

NoAvl *rotacionarEsquerda(NoAvl *x)
{
    NoAvl *y = x->dir;
    NoAvl *T2 = y->esq;

    y->esq = x;
    x->dir = T2;

    atualizarAltura(x);
    atualizarAltura(y);

    return y;
}

NoAvl *rotacionarEsquerdaDireita(NoAvl *z)
{
    z->esq = rotacionarEsquerda(z->esq);
    return rotacionarDireita(z);
}

NoAvl *rotacionarDireitaEsquerda(NoAvl *z)
{
    z->dir = rotacionarDireita(z->dir);
    return rotacionarEsquerda(z);
}

NoAvl *busca(NoAvl *T, int ch, NoAvl **pred)
{
    NoAvl *aux = T;

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
NoAvl *insercao(NoAvl *T, int ch)
{
    if (T == NULL)
    {
        return criaNo(ch);
    }

    if (ch < T->chave)
    {
        T->esq = insercao(T->esq, ch);
    }
    else if (ch > T->chave)
    {
        T->dir = insercao(T->dir, ch);
    }
    else
    {
        return T; // No duplicado não é permitido
    }

    atualizarAltura(T);

    int balanceamento = fatorBalanceamento(T);

    // Rotação à esquerda
    if (balanceamento > 1 && ch < T->esq->chave)
    {
        return rotacionarDireita(T);
    }

    // Rotação à direita
    if (balanceamento < -1 && ch > T->dir->chave)
    {
        return rotacionarEsquerda(T);
    }

    // Rotação à esquerda-direita
    if (balanceamento > 1 && ch > T->esq->chave)
    {
        return rotacionarEsquerdaDireita(T);
    }

    // Rotação à direita-esquerda
    if (balanceamento < -1 && ch < T->dir->chave)
    {
        return rotacionarDireitaEsquerda(T);
    }

    return T;
}

NoAvl *sucessor(NoAvl *ch, NoAvl **paisuc)
{
    NoAvl *sucessor = ch->dir;
    *paisuc = ch;

    while (sucessor != NULL && sucessor->esq != NULL)
    {
        *paisuc = sucessor;
        sucessor = sucessor->esq;
    }
    return sucessor;
}

NoAvl *remover(NoAvl *T, int ch)
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
            NoAvl *temp = T->dir;
            free(T);
            return temp;
        }
        else if (T->dir == NULL)
        {
            NoAvl *temp = T->esq;
            free(T);
            return temp;
        }

        NoAvl *paiSuc = NULL;
        NoAvl *suc = sucessor(T, &paiSuc);

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

    if (T == NULL)
    {
        return T;
    }

    atualizarAltura(T);

    int balanceamento = fatorBalanceamento(T);

    // Rotação à esquerda
    if (balanceamento > 1 && fatorBalanceamento(T->esq) >= 0)
    {
        return rotacionarDireita(T);
    }

    // Rotação à direita
    if (balanceamento < -1 && fatorBalanceamento(T->dir) <= 0)
    {
        return rotacionarEsquerda(T);
    }

    // Rotação à esquerda-direita
    if (balanceamento > 1 && fatorBalanceamento(T->esq) < 0)
    {
        return rotacionarEsquerdaDireita(T);
    }

    // Rotação à direita-esquerda
    if (balanceamento < -1 && fatorBalanceamento(T->dir) > 0)
    {
        return rotacionarDireitaEsquerda(T);
    }

    return T;
}

// Impressao em ordem
void imprime(NoAvl *T, int nivel)
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