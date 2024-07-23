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
} Conjunto;

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
    }
    else
    {
        printf("Erro de alocação de memoria\n");
    }
}

void removeConjunto(Conjunto *conj, int valor)
{
    Elemento *aux = conj->lista;
    Elemento *anterior = NULL;
    int encontrado = 0;

    if (aux == NULL)
        printf("Chave nao existe");
    while (aux != NULL)
    {
        if (aux->chave == valor)
        {
            if (anterior == NULL)
            {
                conj->lista = aux->prox;
            }
            else
            {
                anterior->prox = aux->prox;
            }

            free(aux);
            encontrado = 1;
            break;
        }
        anterior = aux;
        aux = aux->prox;
    }
    if (!encontrado)
    {
        printf("Valor não encontrado na lista\n");
    }
}

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

void esvaziarConjunto(Conjunto *conj)
{
    Elemento *aux = conj->lista;
    while (aux)
    {
        conj->lista = conj->lista->prox;
        free(aux);
        aux = conj->lista;
    }
}

int verificaVazio(Conjunto *conj)
{
    if (conj->lista == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void buscaElemento(Conjunto *conj, int valor)
{
    Elemento *aux = conj->lista;
    if (aux == NULL)
    {
        printf("\nlista vazia\n\n");
        return;
    }
    while (aux != NULL && aux->chave != valor)
    {
        aux = aux->prox;
    }
    if (aux != NULL && aux->chave == valor)
    {
        printf("\nValor encontrado: %d\n", aux->chave);
    }
    else
    {
        printf("\nvalor nao encontrado.\n");
    }
}

int main()
{
    int valor, opcao, verificacaoVazio;
    Conjunto *conjunto = (Conjunto *)malloc(sizeof(Conjunto));
    conjunto->lista = NULL;

    do
    {
        printf("\n\t0 - Sair\n\t1 - Imprimir lista\n\t2 - Inserir Conjunto\n\t3 - Remover uma chave do conjunto\n\t4 - Esvaziar conjunto\n\t5 - Verifica se eh vazio\n\t6 - Verifica se tem no conjunto\n\n");
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
            removeConjunto(conjunto, valor);
            break;
        case 4:
            esvaziarConjunto(conjunto);
            break;
        case 5:
            verificacaoVazio = verificaVazio(conjunto);
            if (verificacaoVazio == 1)
            {
                printf("\nConjunto eh vazio\n\n");
            }
            else
            {
                printf("\nConjunto nao eh vazio\n");
            }
            break;
        case 6:
            printf("Digite um valor: ");
            scanf("%d", &valor);
            buscaElemento(conjunto, valor);
            break;
        default:
            if (opcao != 0)
            {
                printf("Opcao invalida\n");
            }
            break;
        }
    } while (opcao != 0);

    Elemento *atual = conjunto->lista;
    while (atual != NULL)
    {
        Elemento *temp = atual;
        atual = atual->prox;
        free(temp);
    }

    free(conjunto);
    return 0;
}
