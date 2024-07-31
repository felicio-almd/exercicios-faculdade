#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estrutura da lista genérica
typedef struct ListaGen
{
    void *info;
    struct ListaGen *prox;
} ListaGen;

// Função para criar uma nova célula na lista
ListaGen *criaListagen(void *v)
{
    ListaGen *novo = (ListaGen *)calloc(1, sizeof(ListaGen));
    if (novo == NULL)
    {
        printf("\n\nErro na alocação de memória\n\n");
        exit(1);
    }
    novo->info = v;
    return novo;
}

// Função para inserir uma nova célula na cabeça da lista
ListaGen *insereListagen(ListaGen *L, void *v)
{
    ListaGen *novo = criaListagen(v);
    novo->prox = L;
    return novo;
}

ListaGen *insereFinalListaGen(ListaGen *L, void *v)
{
    ListaGen *novo = criaListagen(v);
    if (L == NULL) // Caso a lista esteja vazia, inicializa a lista
    {
        return novo;
    }
    else
    {
        ListaGen *aux = L;
        while (aux->prox != NULL)
        {
            aux = aux->prox;
        }
        aux->prox = novo;
        return L;
    }
}

// Função para percorrer a lista e aplicar uma função callback a cada elemento
void percorreListagen(ListaGen *L, void (*cb)(void *))
{
    ListaGen *aux = L;
    while (aux != NULL)
    {
        cb(aux->info);
        aux = aux->prox;
    }
}

// Função callback para imprimir um elemento da lista
void imprimeInt(void *info)
{
    printf("%d -> ", *(int *)info);
}

void imprimeString(void *info)
{
    printf("%s -> ", (char *)info);
}

// Função main para testar as funções acima
int main()
{
    ListaGen *L = NULL;  // Inicializa a lista vazia
    ListaGen *L2 = NULL; // Inicializa a lista vazia

    char *nome1 = "Alice";
    char *nome2 = "Bob";
    char *nome3 = "Charlie";

    int val1 = 10;
    int val2 = 20;
    int val3 = 30;
    int val4 = 20;

    // Insere elementos na lista
    L = insereListagen(L, nome1);
    L = insereListagen(L, nome2);
    L = insereListagen(L, nome3);

    L2 = insereListagen(L2, &val1);
    L2 = insereListagen(L2, &val2);
    L2 = insereListagen(L2, &val3);
    L2 = insereFinalListaGen(L2, &val4);

    // Percorre e imprime a lista
    percorreListagen(L, imprimeString);
    printf("NULL\n");

    printf("\n\n");

    percorreListagen(L2, imprimeInt);
    printf("NULL\n");

    // Libera a memória alocada
    while (L != NULL)
    {
        ListaGen *temp = L;
        L = L->prox;
        free(temp);
    }

    while (L2 != NULL)
    {
        ListaGen *temp = L2;
        L2 = L2->prox;
        free(temp);
    }

    return 0;
}
