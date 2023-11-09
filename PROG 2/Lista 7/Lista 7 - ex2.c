/***************************************************************************
   CABEÇALHO
   Enunciado:
   Autor: Felicio Almeida

   Histórico de Versão
   1.0 Versão Original. Responsável: Felicio Almeida
********************************************************************/

/* Importação de Bibliotecas */
#include <stdio.h>

struct Imovel {
    char identificacao[30];
    float valorImposto;
    int mesesAtraso;
    float multa;
};

/* Função principal */
int main() {
    /* Declaração de variáveis */
    struct Imovel imovel;

    //Entrada - lendo a identificação
    printf("Digite a identificação do imovel: ");
    scanf("%s", imovel.identificacao);

    //Processamento - leitura dos dados
    while (strcmp(imovel.identificacao, "XXX") != 0) {
        printf("Digite o valor do imposto: ");
        scanf("%f", &imovel.valorImposto);

        printf("Digite o número de meses em atraso: ");
        scanf("%d", &imovel.mesesAtraso);

        // calculando o valor da multa
        imovel.multa = imovel.valorImposto * 0.01 * imovel.mesesAtraso;

        // saida, exibindo os resultados
        printf("\nIdentificação do imovel: %s\n", imovel.identificacao);
        printf("Imposto a ser pago: %f \n", imovel.valorImposto);
        printf("Meses em atraso: %d \n", imovel.mesesAtraso);
        printf("Multa: %f \n\n", imovel.multa);

        // lendo o proximo registro
        printf("Digite a identificação do próximo registro: ");
        scanf("%s", imovel.identificacao);
    }


    printf("\nPrograma Encerrado.");

    //Encerramento
    getchar();
    return 0;
}
