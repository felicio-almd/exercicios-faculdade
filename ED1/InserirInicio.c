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

void imprimeLista (No *no) {
    printf("\n\tLista: ");
    while (no) {
        printf("%d ", no->valor);
        no = no->prox;
    }

    printf("\n\n");
}

int main () {
    int num, opcao;
    No *lista = NULL;

    do {
        printf("\n1. Inserir valor\n2. Imprimir lista\n0. Sair\nEscolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite um valor: ");
                scanf("%d", &num);
                inserirNoInicio(&lista, num);
                break;
            case 2:
                imprimeLista(lista);
                break;
            default:
                if (opcao != 0) {
                    printf("opcao invalida");
                }
         }
    }while(opcao != 0);

    return 0;
}
