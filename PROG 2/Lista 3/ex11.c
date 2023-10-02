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
    int num1, num2, num3, num4, num5, negativo = 0;

    //Entrada - A substituir com comentário adequado
    printf("Digite um numero: ");
    scanf("%d", &num1);
    printf("Digite um numero: ");
    scanf("%d", &num2);
    printf("Digite um numero: ");
    scanf("%d", &num3);
    printf("Digite um numero: ");
    scanf("%d", &num4);
    printf("Digite um numero: ");
    scanf("%d", &num5);

    //Processamento - A substituir com comentário adequado
    if (num1 < 0) {
        negativo++;
    }
    if (num2 < 0) {
        negativo++;
    }
     if (num3 < 0) {
        negativo++;
    }
     if (num4 < 0) {
        negativo++;
    }
     if (num5 < 0) {
        negativo++;
    }

    //Saída - A substituir com comentário adequado
    printf("O total de negativos: %d \n", negativo);
    
    //Encerramento
    getchar();
    return 0;
}
