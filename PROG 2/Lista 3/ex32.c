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
    int consumoAnterior, consumoAtual, diferencaConsumo;
    float tarifaAgua, tarifaEsgoto, tarifaHidrometro, valorContaAgua;

    //Entrada -
    printf("Digite o consumo de agua do mes anterior (m3): ");
    scanf("%d", &consumoAnterior);
    printf("Digite o consumo de agua do mes atual (m3): ");
    scanf("%d", &consumoAtual);

    //Processamento - 
    diferencaConsumo = consumoAtual - consumoAnterior;
    if (diferencaConsumo >= 0 && diferencaConsumo <= 10) {
        tarifaAgua = 0.69;
    } else if (diferencaConsumo >= 11 && diferencaConsumo <= 15) {
        tarifaAgua = 1.17;
    } else if (diferencaConsumo >= 16 && diferencaConsumo <= 25) {
        tarifaAgua = 1.48;
    } else {
        tarifaAgua = 1.60;
    }
    
    tarifaEsgoto = 0.025 * tarifaAgua;
    tarifaHidrometro = 5.00;
    valorContaAgua = (tarifaAgua + tarifaEsgoto + tarifaHidrometro) * diferencaConsumo;

    //Saída -
    printf("Valor da conta de agua: R$ %.2f\n", valorContaAgua);

    //Encerramento
    getchar();
    return 0;
}
