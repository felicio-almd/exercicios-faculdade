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

    
    float salarioBruto, valorPrestacao;
    float limitePrestacao;

    // Entrada - A substituir com comentário adequado
    // Solicita ao usuário que insira o salário bruto
    printf("Insira o salario bruto do funcionario: ");
    scanf("%f", &salarioBruto);

    // Solicita ao usuário que insira o valor da prestação desejada
    printf("Insira o valor da prestacao desejada: ");
    scanf("%f", &valorPrestacao);

    //Processamento - Calcula o limite de prestação (30% do salário bruto)
    limitePrestacao = 0.30 * salarioBruto;

    // Verifica se o valor da prestação não ultrapassa o limite
    if (valorPrestacao <= limitePrestacao) {
        printf("O emprestimo pode ser concedido.\n");
    } else {
        printf("O emprestimo nao pode ser concedido, pois a prestacao ultrapassa o limite.\n");
    }

    //Encerramento
    getchar();
    return 0;
}
