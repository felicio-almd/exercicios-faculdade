#ifndef __ARVORE_AVL_H__
#define __ARVORE_AVL_H__
#define max(a, b) ((a) > (b) ? (a) : (b))

#include <stdlib.h>
#include <stdio.h>

typedef struct NoAvl
{
    int chave;
    struct NoAvl *esq;
    struct NoAvl *dir;
    int altura; // Altura do nó
} NoAvl;

/*
    Nome da função: criaNo
    Parametro: valor:(chave a ser inserida do tipo inteiro)
    Retorno: ponteiro para um novo no da arvore alocado e inicializado com o valor de valor
    Objetivo: alocar e inicializar um novo nó da arvore binaria de busca
*/
NoAvl *criaNo(int valor);

/*
    Nome da função: busca
    Parametro: ch:(chave a ser buscada do tipo inteiro)
    Retorno: ponteiro para o no que contem a chave, caso ela exista em T, ou NULL caso contrario
    Objetivo: buscar uma chave na arvore T
*/
NoAvl *busca(NoAvl *T, int ch, NoAvl **pred);

/*
    Nome: insercao
    Objetivo: inserir uma nova chave ch na arvore T (ch sera inserida somente se ela nao existir na arvore)
    Parametros:
        T: ponteiro para o nó raiz da arvore
        ch: chave a ser inserida
    Retorno: ponteiro para a raiz da arvore resultante
*/
NoAvl *insercao(NoAvl *T, int ch);

/*
    Nome: imprime
    Objetivo: imprimir arvore completa
    Parametros:
        T: ponteiro para o nó raiz da arvore
    Retorno: void
*/
void imprime(NoAvl *T, int a);

/*
    Nome: remove
    Objetivo: excluir fisicamente o no de T que contem a ch caso ela exista
    Parametros:
        T: ponteiro para o nó raiz da arvore
        ch: chave a ser a ser removida
    Retorno: ponteiro para a raiz da arvore resultante
*/
NoAvl *remover(NoAvl *T, int ch);

/*
    Nome: sucessor
    Objetivo: encontrar o no sucessor de um no x da arvore e seu respectivo
    Parametros:
        T: ponteiro para um nó da arvore
        paisuc: referencia para o ponteiro que guarda o nó pai do sucessor
    Retorno: ponteiro para a raiz da arvore resultante
*/
NoAvl *sucessor(NoAvl *ch, NoAvl **paisuc);

// Funções adicionais para balanceamento e manipulação de altura
/*
    Nome da função: altura
    Parametro: n:(ponteiro para um nó da árvore)
    Retorno: altura do nó n
    Objetivo: obter a altura do nó
*/
int altura(NoAvl *n);

/*
    Nome da função: fatorBalanceamento
    Parametro: n:(ponteiro para um nó da árvore)
    Retorno: fator de balanceamento do nó n
    Objetivo: calcular o fator de balanceamento do nó
*/
int fatorBalanceamento(NoAvl *n);

/*
    Nome da função: atualizarAltura
    Parametro: n:(ponteiro para um nó da árvore)
    Retorno: void
    Objetivo: atualizar a altura do nó n
*/
void atualizarAltura(NoAvl *n);

/*
    Nome da função: rotacionarDireita
    Parametro: y:(ponteiro para um nó da árvore)
    Retorno: ponteiro para o nó raiz após a rotação à direita
    Objetivo: realizar rotação à direita
*/
NoAvl *rotacionarDireita(NoAvl *y);

/*
    Nome da função: rotacionarEsquerda
    Parametro: x:(ponteiro para um nó da árvore)
    Retorno: ponteiro para o nó raiz após a rotação à esquerda
    Objetivo: realizar rotação à esquerda
*/
NoAvl *rotacionarEsquerda(NoAvl *x);

/*
    Nome da função: rotacionarEsquerdaDireita
    Parametro: z:(ponteiro para um nó da árvore)
    Retorno: ponteiro para o nó raiz após a rotação à esquerda-direita
    Objetivo: realizar rotação à esquerda-direita
*/
NoAvl *rotacionarEsquerdaDireita(NoAvl *z);

/*
    Nome da função: rotacionarDireitaEsquerda
    Parametro: z:(ponteiro para um nó da árvore)
    Retorno: ponteiro para o nó raiz após a rotação à direita-esquerda
    Objetivo: realizar rotação à direita-esquerda
*/
NoAvl *rotacionarDireitaEsquerda(NoAvl *z);

#endif // __ARVORE_AVL_H__