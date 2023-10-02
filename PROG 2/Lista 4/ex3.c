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
    int n, numero;

    //Entrada - 
    printf("Digite a quantidade de valores a serem lidos: ");
    scanf("%d", &n);

    //Processamento - 
    if (n <= 0) {
        printf("Erro: Insira um valor positivo para n.\n");
        return 1; 
    }
    
    printf("Digite %d números:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &numero);
        
        // Verifica se o número é positivo ou negativo e exibe a classificação
        if (numero > 0) {
            printf("%d é positivo.\n", numero);
        } else if (numero < 0) {
            printf("%d é negativo.\n", numero);
        } else {
            printf("%d é zero.\n", numero);
        }
    }

    //Saída - A substituir com comentário adequado

    //Encerramento
    getchar();
    return 0;
}
