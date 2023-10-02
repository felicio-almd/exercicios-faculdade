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
    char cpf[12];
    int numDependentes;
    float rendaMensal;
    float descontoDependentes;
    float imposto;

    //Entrada - A substituir com comentário adequado
     printf("Digite o CPF do contribuinte (apenas números): ");
    scanf("%s", cpf);
    printf("Digite o número de dependentes: ");
    scanf("%d", &numDependentes);
    printf("Digite a renda mensal (em reais): ");
    scanf("%f", &rendaMensal);

    //Processamento - A substituir com comentário adequado
    descontoDependentes = numDependentes * 0.05 * rendaMensal;
    if (rendaMensal <= 2.0) {
        imposto = 0.0; // Isento
    } else if (rendaMensal <= 3.0) {
        imposto = (rendaMensal - descontoDependentes) * 0.05;
    } else if (rendaMensal <= 5.0) {
        imposto = (rendaMensal - descontoDependentes) * 0.10;
    } else if (rendaMensal <= 7.0) {
        imposto = (rendaMensal - descontoDependentes) * 0.15;
    } else {
        imposto = (rendaMensal - descontoDependentes) * 0.20;
    }

    //Saída - A substituir com comentário adequado
    printf("\nCPF do contribuinte: %s\n", cpf);
    printf("Número de dependentes: %d\n", numDependentes);
    printf("Renda mensal (em reais): %.2f\n", rendaMensal);
    printf("Desconto dos dependentes: %.2f\n", descontoDependentes);
    printf("Imposto de renda a pagar: %.2f\n", imposto);

    //Encerramento
    getchar();
    return 0;
}
