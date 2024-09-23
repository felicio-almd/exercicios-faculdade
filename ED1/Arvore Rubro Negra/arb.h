#ifndef __ARVORE_RB_H__
#define __ARVORE_RB_H__

#include <stdlib.h>
#include <stdio.h>

#define RED 1
#define BLACK 0

typedef struct NoRB
{
    int chave;
    struct NoRB *esq;
    struct NoRB *dir;
    int cor; // cor do nó
} NoRB;

NoRB *criaNo(int valor);
NoRB *busca(NoRB *T, int ch);
NoRB *insercao(NoRB *T, int ch);
void imprime(NoRB *raiz, int nivel);
NoRB *remover(NoRB *T, int ch);
NoRB *sucessor(NoRB *ch, NoRB **paisuc);
int cor(NoRB *n);
void trocaCor(NoRB *n);
NoRB *rotacionarDireita(NoRB *y);
NoRB *rotacionarEsquerda(NoRB *y);

#endif // __ARVORE_RB_H__