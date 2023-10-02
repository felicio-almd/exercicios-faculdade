/***************************************************************************
   CABEÇALHO
   Enunciado:
   Autor: Felicio Almeida

   Histórico de Versão
   1.0 Versão Original. Responsável: Felicio Almeida
********************************************************************/

/* Importação de Bibliotecas */
#include <stdio.h>

/* Função principal */
int main() {
    /* Declaração de variáveis */
    int a, b;

    //Entrada - A substituir com comentário adequado
    printf("Digite o numero A: ");
    scanf("%d", &a);
    printf("Digite o numero B: ");
    scanf("%d", &b);

    //Processamento - A substituir com comentário adequado
    if (a > b) {
        printf("Erro: a deve ser menor ou igual a b.\n");
        return 1; 
    }

    printf("a. Todos os números em [%d, %d]:\n", a, b);
    for (int i = a; i <= b; i++) {
        printf("%d ", i);
    }
    printf("\n");

    printf("b. Todos os números ímpares em [%d, %d]:\n", a, b);
    for (int i = a; i <= b; i++) {
        if (i % 2 != 0) {
            printf("%d ", i);
        }
    }
    printf("\n");

    printf("c. Todos os números ímpares em [%d, %d] múltiplos de 3:\n", a, b);
    for (int i = a; i <= b; i++) {
        if (i % 2 != 0 && i % 3 == 0) {
            printf("%d ", i);
        }
    }
    printf("\n");
    
    //Encerramento
    getchar();
    return 0;
}
