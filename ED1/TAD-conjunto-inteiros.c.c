#include <stdio.h>
#include <stdlib.h>

typedef struct lista {
    int chave;
    struct lista *prox;
} Elemento;

typedef struct conjunto {
    Elemento *lista;
} Conjunto;


void insereConjunto(Conjunto *conj, int valor) {
    Elemento *aux = conj->lista;
    Elemento *novo = NULL;

    while (aux) {
        if (aux->chave == valor) {
            printf("Ja existe esse valor na lista\n");
            return;
        }
        aux = aux->prox;
    }

    novo = (Elemento *)calloc(1, sizeof(Elemento));
    if (novo) {
        novo->chave = valor;
        novo->prox = conj->lista;
        conj->lista = novo;
    } else {
        printf("Erro de alocação de memoria\n");
    }
}

void imprimeConjunto(Elemento *no) {
    printf("\n\tConjunto: ");
    while (no) {
        printf("%d ", no->chave);
        no = no->prox;
    }
    printf("\n\n");
}

int main() {
    int valor, opcao;
    Conjunto *conjunto = (Conjunto *)malloc(sizeof(Conjunto));
    conjunto->lista = NULL;

    do {
        printf("\n\t0 - Sair\n\t1 - Inserir Conjunto\n\t2 - Imprimir lista\n\n");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite um valor: ");
                scanf("%d", &valor);
                insereConjunto(conjunto, valor);
                break;
            case 2:
                imprimeConjunto(conjunto->lista);
                break;
            default:
                if (opcao != 0) {
                    printf("Opcao invalida\n");
                }
                break;
        }
    } while (opcao != 0);

    free(conjunto);
    return 0;
}
