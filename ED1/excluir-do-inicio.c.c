#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int valor;
    struct no *prox;
} No;

// recebe um ponteiro para ponteiro, porque teremos um ponteiro pra lista no metodo, entao recebe o endereço
void inserirNoInicio (No **lista, int num) {
    No *novo = malloc(sizeof(No));

    if(novo) {
        novo->valor = num;
        novo->prox = *lista;
        *lista = novo;
    }
    else {
        printf("Erro ao alocar memoria");
    }
}

// procedimento para inserir no fim
void insereNoFim (No **lista, int num) {
    No *novo = malloc(sizeof(No));
    No *aux = malloc(sizeof(No));

    if (novo) {
        novo->valor = num;
        novo->prox = NULL;
        // eh o primeiro?
        if ( *lista == NULL ){
            *lista = novo;
        } else {
            aux = *lista;
            while (aux->prox != NULL) {
                aux = aux->prox;
            }
            aux->prox = novo;
        }
    }
    else {
        printf("Erro ao alocar");
    }
}

void insereNoMeio (No **lista, int num, int ant) {
    No *novo = malloc(sizeof(No));
    No *aux = malloc(sizeof(No));

    if (novo) {
        novo->valor = num;
        // eh o primeiro?
        if (*lista == NULL) {
            novo->prox = NULL;
            *lista = novo;
        }
        // nao esta vazia
        else {
            aux = *lista;
            while (aux->prox != ant && aux->prox != NULL){
                aux = aux->prox;
            }
            novo->prox = aux->prox;
            aux->prox = novo;
        }

    } else {
        printf("Erro ao alocar");
    }
}

No *excluirDoInicio (No *lista) {
    No *aux = malloc(sizeof(No));
    aux = lista;
    if (lista == NULL) return NULL;
    else{
        lista = lista->prox;
        free(aux);
        return lista;
    }
}

void imprimeLista (No *lista) {
    No *aux = lista;
    printf("\n\tLista: ");
    while (aux != NULL) {
        printf("%d ", aux->valor);
        aux = aux->prox;
    }

    printf("\n\n");
}


int main () {
    int valor, ant, opcao;
    No *lista = NULL;

    do {
        printf("\n\ 0 - Sair\n\t 1 - Inserir no inicio \n\t 2 - Inserir no Fim \n\t 3 - Inserir no meio \n\t 4 - Excluir do inicio \n\t 5 - Imprimir lista\n\n");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite um valor");
                scanf("%d", &valor);
                inserirNoInicio(&lista, valor);
                break;
            case 2:
                printf("Digite um valor");
                scanf("%d", &valor);
                insereNoFim(&lista, valor);
                break;
            case 3:
                printf("Digite um valor");
                scanf("%d", &valor);
                printf("digite o valor de referencia");
                scanf("%d", &ant);
                insereNoMeio(&lista, valor, ant);
                break;
            case 4:
                excluirDoInicio(lista);
                break;
            case 5:
                imprimeLista(lista);
                break;
            default:
                if (opcao != 0) {
                    printf("opcao invalida");
                }
        }


    } while (opcao != 0);

    No *prox;
    while (lista != NULL) {
        prox = lista->prox;
        free(lista);
        lista = prox;
    }
    return 0;
}
