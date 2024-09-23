#include "arb.h"

NoRB *criaNo(int valor)
{
    NoRB *novo = (NoRB *)calloc(1, sizeof(NoRB));
    if (novo == NULL)
    {
        printf("erro");
        exit(1);
    }
    novo->chave = valor;
    novo->esq = NULL;
    novo->dir = NULL;
    novo->cor = 1;
}

NoRB *busca(NoRB *raiz, int ch)
{
    if (raiz == NULL || raiz->chave == ch)
    {
        return raiz;
    }

    if (ch < raiz->esq->chave)
        return busca(raiz->esq, ch);
    else
        return busca(raiz->dir, ch);
}

NoRB *sucessor(NoRB *ch, NoRB **paisuc)
{
    NoRB *sucessor = ch->dir;
    *paisuc = ch;

    while (sucessor != NULL && sucessor->esq != NULL)
    {
        *paisuc = sucessor;
        sucessor = sucessor->esq;
    }
    return sucessor;
}

int cor(NoRB *n)
{
    if (n == NULL)
        return 0; // Considera nó nulo como preto
    return n->cor;
}

void trocaCor(NoRB *n)
{
    n->cor = !n->cor; // Troca a cor do nó
    if (n->esq != NULL)
        n->esq->cor = !n->esq->cor; // Troca a cor do filho esquerdo
    if (n->dir != NULL)
        n->dir->cor = !n->dir->cor; // Troca a cor do filho direito
}

NoRB *rotacionarEsquerda(NoRB *y)
{
    NoRB *x = y->dir;
    y->dir = x->esq;
    x->esq = y;
    x->cor = y->cor;
    y->cor = 1; // Vermelho
    return x;
}

NoRB *rotacionarDireita(NoRB *y)
{
    NoRB *x = y->esq;
    y->esq = x->dir;
    x->dir = y;
    x->cor = y->cor;
    y->cor = 1; // Vermelho
    return x;
}

NoRB *insercao(NoRB *T, int ch)
{
    if (T == NULL)
        return criaNo(ch); // Insere novo nó

    if (ch < T->chave)
    {
        T->esq = insercao(T->esq, ch);
    }
    else if (ch > T->chave)
    {
        T->dir = insercao(T->dir, ch);
    }

    // Reequilíbrio da árvore após inserção
    if (cor(T->dir) == 1 && cor(T->esq) == 0) // Caso 1: rotação esquerda
        T = rotacionarEsquerda(T);

    if (cor(T->esq) == 1 && cor(T->esq->esq) == 1) // Caso 2: rotação direita
        T = rotacionarDireita(T);

    if (cor(T->esq) == 1 && cor(T->dir) == 1) // Caso 3: troca de cor
        trocaCor(T);

    return T;
}

NoRB *remover(NoRB *T, int ch)
{
    if (T == NULL)
        return NULL; // Caso a árvore esteja vazia

    // Passo 1: Descida na árvore como na árvore binária de busca
    if (ch < T->chave)
    {
        if (cor(T->esq) == 0 && cor(T->esq->esq) == 0)
        {
            // Corrige caso o filho esquerdo e seu filho esquerdo sejam pretos
            T = rotacionarDireita(T);
            if (T->esq != NULL)
                T->esq->cor = 1; // Coloca o filho como vermelho
        }
        T->esq = remover(T->esq, ch);
    }
    else
    {
        if (cor(T->esq) == 1)
        {
            // Se o filho esquerdo é vermelho, rotação à direita para ajustar
            T = rotacionarDireita(T);
        }

        if (ch == T->chave && T->dir == NULL)
        {
            // Caso o nó a ser removido seja encontrado e não tenha subárvore direita
            free(T);
            return NULL;
        }

        if (cor(T->dir) == 0 && cor(T->dir->esq) == 0)
        {
            // Corrige caso o filho direito e seu filho esquerdo sejam pretos
            T = rotacionarEsquerda(T);
            if (T->dir != NULL)
                T->dir->cor = 1; // Coloca o filho como vermelho
        }

        if (ch == T->chave)
        {
            // Se encontrarmos o nó a ser removido e ele tiver dois filhos
            NoRB *sucessorPai;
            NoRB *sucessorNode = sucessor(T, &sucessorPai); // Encontra o sucessor
            T->chave = sucessorNode->chave;
            T->dir = remover(T->dir, sucessorNode->chave); // Remove o sucessor
        }
        else
        {
            T->dir = remover(T->dir, ch); // Continua descendo na árvore
        }
    }

    // Passo 2: Rebalanceia a árvore após a remoção
    if (cor(T->dir) == 1)
    {
        // Se o filho direito é vermelho, faz uma rotação à esquerda
        T = rotacionarEsquerda(T);
    }
    if (cor(T->esq) == 1 && cor(T->esq->esq) == 1)
    {
        // Se o filho esquerdo e o filho do filho esquerdo são vermelhos
        T = rotacionarDireita(T);
    }
    if (cor(T->esq) == 1 && cor(T->dir) == 1)
    {
        // Caso os dois filhos sejam vermelhos, troca as cores
        trocaCor(T);
    }

    return T;
}

void imprime(NoRB *T, int nivel)
{
    int i;
    if (T != NULL)
    {
        imprime(T->dir, nivel + 1);
        for (i = 0; i < nivel; i++)
            printf("\t");
        printf("%d\n", T->chave);
        imprime(T->esq, nivel + 1);
    }
}