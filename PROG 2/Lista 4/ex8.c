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
    int i, n, numero, min = 0, max = 0;
    float media, soma = 0;

    //Entrada - A substituir com comentário adequado
    printf("Digite a quantidade de numeros (n): ");
    scanf("%d", &n);

    if (n < 3) {
        printf("Erro: n deve ser maior ou igual a 3.\n");
        return 1; // Encerra o programa com código de erro
    }

    //Processamento - A substituir com comentário adequado
    for (i = 0; i < n; i++) {
        printf("Digite o numero %d: ", i + 1);
        scanf("%d", &numero);

        if (i == 0) {
            min = max = numero;
        } else {
            if (numero < min) {
                min = numero;
            }
            if (numero > max) {
                max = numero;
            }
        }

        soma += numero;
    }

    // Calcula a média excluindo o menor e o maior
    media = (soma - min - max) / (n - 2);

   //Saída - A substituir com comentário adequado
    printf("Media dos numeros excluindo o menor e o maior: %.2f\n", media);

    //Encerramento
    getchar();
    return 0;
}
