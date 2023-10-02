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
    float saldo_medio, credito;
    //Entrada - A substituir com comentário adequado
    printf("Digite o saldo médio do cliente (em R$): ");
    scanf("%f", &saldo_medio);

    //Processamento - A substituir com comentário adequado
     if (saldo_medio >= 0 && saldo_medio <= 200) {
        credito = 0;
    } else if (saldo_medio > 200 && saldo_medio <= 400) {
        credito = saldo_medio * 0.20;
    } else if (saldo_medio > 400 && saldo_medio <= 600) {
        credito = saldo_medio * 0.30;
    } else if (saldo_medio > 600) {
        credito = saldo_medio * 0.40;
    } else {
        printf("Saldo médio inválido.\n");
        return 1; // Encerra o programa com código de erro
    }

    //Saída - A substituir com comentário adequado
    printf("Saldo médio: R$ %.2f\n", saldo_medio);
    printf("Valor do crédito: R$ %.2f\n", credito);
    //Encerramento
    getchar();
    return 0;
}
