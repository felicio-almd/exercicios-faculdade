#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int valor;
    struc no *proximo;
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

int main () {

    return 0;
}
