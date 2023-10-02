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
    float consumo, consumoAnterior, consumoAtual;
    float tarifa;
    float valorConta;

    //Entrada - Solicita a leitura do consumo em KwH do mês anterior
    printf("Informe o consumo em KwH do mês anterior: ");
    scanf("%f", &consumoAnterior);
    printf("Informe o consumo em KwH do mês atual: ");
    scanf("%f", &consumoAtual);

    //Processamento - A substituir com comentário adequado
    consumo = consumoAtual - consumoAnterior;
    if (consumo <= 70) {
        tarifa = 0.09;
    } else if (consumo <= 150) {
        tarifa = 0.20;
    } else if (consumo <= 200) {
        tarifa = 0.23;
    } else {
        tarifa = 0.26;
    }

    valorConta = consumo * tarifa;

    //Saída - Imprime o valor da conta de luz
    printf("Valor da conta de luz: R$ %.2f\n", valorConta);
    //Encerramento
    getchar();
    return 0;
}
