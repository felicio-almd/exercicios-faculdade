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
    float valor, valorReal;
    int prazo;

    //Entrada - A substituir com comentário adequado
    printf("insira o valor a ser pago: ");
    scanf("%f", &valor);
    printf("digite o prazo de pagamento: ");
    scanf("%d", &prazo);

    //Processamento - A substituir com comentário adequado
    if ( prazo >= 1 && prazo <= 3 ) {
        valorReal = valor;
    } else if ( prazo >= 4 && prazo <= 7 ) {
        valorReal = valor + (valor * 0.005);
    } else if ( prazo >= 8 && prazo <= 12 ) {
        valorReal = valor + (valor * 0.015);
    } else if ( prazo >= 12 && prazo <= 20 ) {
        valorReal = valor + (valor * 0.03);
    } else {
        printf("Prazo invalido.\n");
    }

    //Saída - saida
    printf("Valor total a ser pago pelo cliente: %.2f", valorReal);

    //Encerramento
    getchar();
    return 0;
}
