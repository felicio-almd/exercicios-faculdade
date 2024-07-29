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

int verificaContido(Conjunto *L1, Conjunto *L2)
{
    Elemento *aux1 = L1->lista;
    Elemento *aux2 = L2->lista;

    if (L1->lista == NULL || L2->lista == NULL)
    {
        return 0; // Um dos conjuntos está vazio
    }

    while (aux2 != NULL)
    {
        int encontrado = 0;
        aux1 = L1->lista; // Reinicia aux1 para percorrer L1

        while (aux1 != NULL)
        {
            if (aux2->chave == aux1->chave)
            {
                encontrado = 1;
                break;
            }
            aux1 = aux1->prox;
        }

        if (!encontrado)
        {
            return 0; // Se um elemento de L2 não for encontrado em L1, retorna 0
        }

        aux2 = aux2->prox; // Passa para o próximo elemento de L2
    }

    return 1; // Todos os elementos de L2 foram encontrados em L1
}

int main()
{
    int valor, opcao, verificacaoVazio;
    Conjunto *conjunto1 = (Conjunto *)malloc(sizeof(Conjunto));
    conjunto1->lista = NULL;

    Conjunto *conjunto2 = (Conjunto *)malloc(sizeof(Conjunto));
    conjunto2->lista = NULL;

    do
    {
        printf("\n\t0 - Sair\n\t1 - Imprimir lista 1\n\t2 - Inserir valor na lista 1\n\t3 - Remover uma chave da lista 1\n\t4 - Esvaziar lista 1\n\t5 - Verifica se lista 1 eh vazia\n\t6 - Verifica se tem no conjunto 1\n\t7 - Verifica se lista 2 esta contida na lista 1\n\n");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            imprimeConjunto(conjunto1->lista);
            break;
        case 2:
            printf("Digite um valor: ");
            scanf("%d", &valor);
            insereConjunto(conjunto1, valor);
            break;
        case 3:
            printf("Digite o valor a ser removido do conjunto: ");
            scanf("%d", &valor);
            removeConjunto(conjunto1, valor);
            break;
        case 4:
            esvaziarConjunto(conjunto1);
            break;
        case 5:
            verificacaoVazio = verificaVazio(conjunto1);
            if (verificacaoVazio == 1)
            {
                printf("\nConjunto 1 eh vazio\n\n");
            }
            else
            {
                printf("\nConjunto 1 nao eh vazio\n");
            }
            break;
        case 6:
            printf("Digite um valor: ");
            scanf("%d", &valor);
            buscaElemento(conjunto1, valor);
            break;
        case 7:
            // Preencher o conjunto 2 para teste
            printf("Preencha o Conjunto 2:\n");
            while (1)
            {
                printf("Digite um valor para o conjunto 2 (ou -1 para terminar): ");
                scanf("%d", &valor);
                if (valor == -1)
                    break; // -1 para terminar a inserção
                insereConjunto(conjunto2, valor);
            }
            // Verifica se conjunto 2 está contido em conjunto 1
            if (verificaContido(conjunto1, conjunto2))
            {
                printf("O conjunto 2 esta contido no conjunto 1.\n");
            }
            else
            {
                printf("O conjunto 2 nao esta contido no conjunto 1.\n");
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

    esvaziarConjunto(conjunto1);
    esvaziarConjunto(conjunto2);
    free(conjunto1);
    free(conjunto2);
    return 0;
}