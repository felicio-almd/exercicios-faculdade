#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int valor;
    struc no *prox;
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

int main () {

    return 0;
}
