#ifndef __ARVORE_H__
#define __ARVORE_H__

#include <stdlib.h>
#include <stdio.h>

typedef struct no
{
    int chave;
    struct no *esq, *dir;
} No;

/*
    Nome da função: criaNo
    Parametro: valor:(chave a ser inserida do tipo inteiro)
    Retorno: ponteiro para um novo no da arvore alocado e inicializado com o valor de valor
    Objetivo: alocar e inicializar um novo nó da arvore binaria de busca
*/
No *criaNo(int valor);

/*
    Nome da função: busca
    Parametro: ch:(chave a ser buscada do tipo inteiro)
    Retorno: ponteiro para o no que contem a chave, caso ela exista em T, ou NULL caso contrario
    Objetivo: buscar uma chave na arvore T
*/
No *busca(No *T, int ch);

/*
    Nome: insercao
    Objetivo: inserir uma nova chave ch na arvore T (ch sera inserida somente se ela nao existir na arvore)
    Parametros:
        T: ponteiro para o nó raiz da arvore
        ch: chave a ser inserida
    Retorno: ponteiro para a raiz da arvore resultante
*/
No *insercao(No *T, int ch);

/*
    Nome: imprime
    Objetivo: imprimir arvore completa
    Parametros:
        T: ponteiro para o nó raiz da arvore
    Retorno: void
*/
void imprime(No *T);

/*
    Nome: remove
    Objetivo: excluir fisicamente o no de T que contem a ch caso ela exista
    Parametros:
        T: ponteiro para o nó raiz da arvore
        ch: chave a ser a ser removida
    Retorno: ponteiro para a raiz da arvore resultante
*/
No *remover(No *T, int ch);

/*
    Nome: sucessor
    Objetivo: encontrar o no sucessor de um no x da arvore e seu respectivo
    Parametros:
        T: ponteiro para um nó da arvore
        paisuc: referencia para o ponteiro que guarda o nó pai do sucessor
    Retorno: ponteiro para a raiz da arvore resultante
*/
No *sucessor(No *ch, No **paisuc);

#endif