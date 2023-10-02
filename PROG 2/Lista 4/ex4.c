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
    int n, i, negativo = 0;
    int valores;

    //Entrada - A substituir com comentário adequado
    printf("Digite quantos valores: ");
    scanf("%d", &valores);

    //Processamento - A substituir com comentário adequado
    printf("Digite os valores:\n");

    for (i = 0; i < valores; i++) {
        printf("Digite o valor %d: ", i + 1);
        scanf("%d", &n);

        if (n < 0) {
            negativo++;
        }
    }

    //Saída - A substituir com comentário adequado
    printf("Quantidade de valores negativos: %d\n", negativo);

    //Encerramento
    getchar();
    return 0;
}
