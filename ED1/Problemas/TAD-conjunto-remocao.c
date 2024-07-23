#include <stdio.h>
#include <stdlib.h>

typedef struct lista
{
    int chave;
    struct lista *prox;
} Elemento;

typedef struct conjunto
{
    Elemento *lista;
    Elemento *fim;
    int quantidade;
} Conjunto;

void criaConj(Conjunto *conj)
{
    conj->lista = NULL;
    conj->quantidade = 0;
}
void insereConjunto(Conjunto *conj, int valor)
{
    Elemento *aux = conj->lista;
    Elemento *novo = NULL;

    while (aux)
    {
        if (aux->chave == valor)
        {
            printf("Ja existe esse valor na lista\n");
            return;
        }
        aux = aux->prox;
    }

    novo = (Elemento *)calloc(1, sizeof(Elemento));
    if (novo)
    {
        novo->chave = valor;
        novo->prox = conj->lista;
        conj->lista = novo;
        conj->quantidade++;
    }
    else
    {
        printf("Erro de alocação de memoria\n");
    }
}

// no = elemento  e   lista=conjunto
Elemento *removeConjunto(Conjunto *conj, int valor)
{
    Elemento *remover = NULL;
    Elemento *aux = conj->lista;

    if (aux == NULL)
        printf("Chave nao existe");
    while (aux != NULL)
    {
        if (aux->chave == valor)
        {
            remover = aux;
            conj->lista = remover->prox;
            conj->quantidade--;
        }
        else
        {
            while (aux->prox && aux->prox->chave != valor)
                aux = aux->prox;
            if (aux->prox)
            {
                remover = aux->prox;
                aux->prox = remover->prox;
                conj->quantidade--;
            }
        }
    }
    return remover;
} // o que ta errado nessa funcao, desenhar no papel

void imprimeConjunto(Elemento *no)
{
    printf("\n\tConjunto: ");
    while (no)
    {
        printf("%d ", no->chave);
        no = no->prox;
    }
    printf("\n\n");
}

int main()
{
    int valor, opcao;
    Conjunto *conjunto = (Conjunto *)malloc(sizeof(Conjunto));
    conjunto->lista = NULL;
    Elemento *removido;

    do
    {
        printf("\n\t0 - Sair\n\t1 - Imprimir Conjunto\n\t2 - Inserir Conjunto\n\t3 - Remover uma chave do conjunto\n\n");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            imprimeConjunto(conjunto->lista);
            break;
        case 2:
            printf("Digite um valor: ");
            scanf("%d", &valor);
            insereConjunto(conjunto, valor);
            break;
        case 3:
            printf("Digite o valor a ser removido do conjunto: ");
            scanf("%d", &valor);
            removido = removeConjunto(conjunto, valor);
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

    free(conjunto);
    return 0;
}
