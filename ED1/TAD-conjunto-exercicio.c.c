#include <stdio.h>
#include <stdlib.h>
// PROGRAMA DA LISTA COM NO CABEÇA SEM ORDENAÇÃO
// Implementar funcao busca, funcao exclui especifico e terminar a main

typedef struct no
{
    int chave;
    struct no *prox;
} No;

typedef struct cabeca
{
    struct no *prox;
    struct no *ultimo;
    int quantidade;
} Cabeca;

Cabeca *criaLista(){   //Essa função só vai ser usada uma vez, quando for inicialiar o lista na função main
    Cabeca *novo;
    novo = (Cabeca*) calloc(1,sizeof(Cabeca));
    if (novo == NULL)
    {
        printf("ERRO: problemas com a alocacao de memoria . \n");
        exit(1);
    }
    return novo;
}

No *criaNo(int valor){
    No *novo;
    novo = (No*) calloc(1, sizeof(No));
    if (novo == NULL)
    {
        printf("ERRO: problemas com a alocacao de memoria . \n");
        exit(1);
    }
    novo->chave = valor;
    return novo;
}

void insereInicio(Cabeca *L, int valor)
{
    No *novo = criaNo(valor);
    novo->prox = L->prox;
    L->prox = novo;
    if (L->quantidade == 0) L->ultimo = 0;
    L->quantidade++;
}

void excluiInicio(Cabeca *L){
    No *aux = L->prox;
    if (L->quantidade != 0)
    {
        L->prox = aux->prox;
        free(aux);
        L->quantidade --;
        if (L->quantidade == 0) L->ultimo = NULL;
    }
}

void excluiFinal(Cabeca *L){
    No *aux = L->prox;
    No *pred = NULL;
    if (L->quantidade != 0)
    {
        while(aux->prox != NULL)
        {
            pred = aux;
            aux = aux->prox;
        }
        if (pred == NULL) L->prox = NULL;
        else pred->prox = NULL;
        free(aux);
        L->ultimo = pred;
        L->quantidade --;
    }
}

void imprimeLista(Cabeca *L){
    No *aux = L->prox;
    printf("Lista -> |%d|", L->quantidade);
    while (aux != NULL)
    {
        printf(" -> %d", aux->chave);
        aux = aux->prox;
    }
}

int main()
{
    int valor, opcao;
    Cabeca *L = criaLista();

    do
    {
        printf("\n\t0 - Sair\n\t1 - Imprimir Lista\n\t2 - Inserir no inicio\n\t3 - Inserir no final\n\t4 - Remover do inicio\n\n");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            imprimeConjunto(L);
            break;
        case 2:
            printf("Digite um valor: ");
            scanf("%d", &valor);
            insereConjunto(L, valor);
            break;
        case 3:
            printf("Digite o valor a ser removido da lista: ");
            scanf("%d", &valor);
            removido = removeConjunto(L, valor);
            if (removido)
            {
                printf("elemento removido: %d\n", removido->chave);
                free(removido);
            }
            else
            {
                printf("nao tem elemento");
            }
            break;
        default:
            if (opcao != 0)
            {
                printf("Opcao invalida\n");
            }
            break;
        }
    } while (opcao != 0);

    free(L);
    return 0;
}
