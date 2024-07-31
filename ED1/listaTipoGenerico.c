#include <stdio.h>
#include <stdlib.h>

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
void imprimeElemento(void *info)
{
    printf("%d -> ", *(int *)info);
}

// Função main para testar as funções acima
int main()
{
    ListaGen *L = NULL; // Inicializa a lista vazia

    int val1 = 10;
    int val2 = 20;
    int val3 = 30;

    // Insere elementos na lista
    L = insereListagen(L, &val1);
    L = insereListagen(L, &val2);
    L = insereListagen(L, &val3);

    // Percorre e imprime a lista
    percorreListagen(L, imprimeElemento);
    printf("NULL\n");

    // Libera a memória alocada
    while (L != NULL)
    {
        ListaGen *temp = L;
        L = L->prox;
        free(temp);
    }

    return 0;
}
