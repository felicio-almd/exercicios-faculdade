#include <stdio.h>
#include <stdlib.h>
// PROGRAMA DA LISTA COM NO CABEÇA SEM ORDENAÇÃO

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

Cabeca *criaLista()
{ // Essa função só vai ser usada uma vez, quando for inicialiar o lista na função main
    Cabeca *novo;
    novo = (Cabeca *)calloc(1, sizeof(Cabeca));
    if (novo == NULL)
    {
        printf("ERRO: problemas com a alocacao de memoria . \n");
        exit(1);
    }
    return novo;
}

No *criaNo(int valor)
{
    No *novo;
    novo = (No *)calloc(1, sizeof(No));
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
    if (L->quantidade == 0)
        L->ultimo = 0;
    L->quantidade++;
}

void insereFinal(Cabeca *L, int valor)
{
    No *novo = criaNo(valor);
    No *aux = L->prox;

    if (L->quantidade != 0)
    {
        while (aux->prox != NULL)
        {
            aux = aux->prox;
        }
        aux->prox = novo;
    }
    else
    {
        L->prox = novo;
    }
    L->quantidade++;
}

void excluiInicio(Cabeca *L)
{
    No *aux = L->prox;
    if (L->quantidade != 0)
    {
        L->prox = aux->prox;
        free(aux);
        L->quantidade--;
        if (L->quantidade == 0)
            L->ultimo = NULL;
    }
}

void excluiFinal(Cabeca *L)
{
    No *aux = L->prox;
    No *pred = NULL;
    if (L->quantidade != 0)
    {
        while (aux->prox != NULL)
        {
            pred = aux;
            aux = aux->prox;
        }
        if (pred == NULL)
            L->prox = NULL;
        else
            pred->prox = NULL;
        free(aux);
        L->ultimo = pred;
        L->quantidade--;
    }
}

void excluiChave(Cabeca *L, int valor)
{
    No *aux = L->prox;
    No *pred = NULL; // Ponteiro para o nó anterior
    if (L == NULL || L->prox == NULL)
    {
        return;
    }
    while (aux != NULL && aux->chave != valor)
    {
        pred = aux;
        aux = aux->prox;
    }
    if (aux != NULL && aux->chave == valor)
    {
        if (pred == NULL)
        {
            L->prox = aux->prox; // Caso o nó a ser removido seja o primeiro da lista
        }
        else
        {
            pred->prox = aux->prox; // Caso o nó a ser removido não seja o primeiro da lista
        }
        if (aux == L->ultimo) // Atualiza o ponteiro para o último nó, se necessário
        {
            L->ultimo = pred;
        }
        free(aux);
        L->quantidade--;
    }
}

No *buscaChave(Cabeca *L, int valor)
{
    No *aux = L->prox;
    if (L->quantidade != 0)
    {
        while (aux != NULL && aux->chave != valor)
        {
            aux = aux->prox;
        }
        if (aux != NULL)
        {
            return (aux);
        }
    }
}

int verificaContido (Cabeca *L1, Cabeca *L2) {
    No *aux1 = L1->prox;
    No *aux2 = L2->prox;
    int cont;

    if(L1->quantidade < L2->quantidade){
        return 0;
    }
    while (aux2->prox != NULL) {
        cont = 0;
        while (aux1->prox != NULL){
            if (aux2->chave != aux1->chave){
                aux1 = aux1->prox;
            } else {
                cont = 1;
                break;
            }
        }
        if (cont == 1){
            aux2 = aux2->prox;
        }
        else {
            break;
        }
    }
    if (cont == 1 ){
        return 1;
    } else {
        return 0;
    }
}

void imprimeLista(Cabeca *L)
{
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
    No *chave;

    do
    {
        printf("\n\t0 - Sair\n\t1 - Imprimir Lista\n\t2 - Inserir no inicio\n\t3 - Inserir no Final\n\t4 - Remover no inicio\n\t5 - Remover do final\n\t6 - Remover chave\n\t7 - Buscar chave\n\n");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            imprimeLista(L);
            break;
        case 2:
            printf("Digite um valor: ");
            scanf("%d", &valor);
            insereInicio(L, valor);
            break;
        case 3:
            printf("Digite um valor: ");
            scanf("%d", &valor);
            insereFinal(L, valor);
            break;
        case 4:
            excluiInicio(L);
            break;
        case 5:
            excluiFinal(L);
            break;
        case 6:
            printf("Digite um valor: ");
            scanf("%d", &valor);
            excluiChave(L, valor);
            break;
        case 7:
            printf("Digite um valor: ");
            scanf("%d", &valor);
            chave = buscaChave(L, valor);
            if (chave != NULL)
            {
                printf("\nChave encontrada: %d\n", chave->chave);
            }
            else
            {
                printf("\nChave nao encontrada\n\n");
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
