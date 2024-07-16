#include <stdio.h>
#include <stdlib.h>

typedef struct lista {
    int chave;
    struct lista *prox;
} Elemento;

typedef struct conjunto{
    Elemento *lista;
} Conjunto;


void insereConjunto(Conjunto *conj, int valor){
    Elemento *aux = conj->lista;
    Elemento *novo = NULL;

    while(aux) {
        if(aux->chave == valor){
            printf("Ja existe esse valor na lista\n");
            return;
        }
        aux = aux->prox;
    }
    novo = (Elemento *)calloc(1,sizeof(Elemento));
    if(novo){
        novo->chave = valor;
        novo->prox = conj->lista;
        conj->lista = novo;
    }
    else{
        printf("Erro de alocação de memoria");
    }

}

void imprimeLista (Elemento *no) {
    printf("\n\tLista: ");
    while (no) {
        printf("%d ", no->chave);
        no = no->prox;
    }

    printf("\n\n");
}


int main () {
    int valor, opcao;
    Conjunto *conjunto = NULL;

    do {
        printf("\n\ 0 - Sair\n\t 1 - Inserir Conjunto 2 - Imprimir lista\n\n");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite um valor");
                scanf("%d", &valor);
                insereConjunto(conjunto, valor);
                break;
            case 2:
                imprimeLista(conjunto);
                break;
            default:
                if (opcao != 0) {
                    printf("opcao invalida");
                }
        }
    } while (opcao != 0);
    return 0;
}
