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
    int valor, maior, menor, i;

    //Entrada - A substituir com comentário adequado
    printf("Digite o valor 1: ");
    scanf("%d", &valor);

    maior = menor = valor;

    //Processamento - A substituir com comentário adequado
    for (int i = 2; i <= 50; i++) {
        printf("Digite o valor %d: ", i);
        scanf("%d", &valor);

        // Atualiza 'maior' e 'menor' conforme necessário
        if (valor > maior) {
            maior = valor;
        }
        if (valor < menor) {
            menor = valor;
        }
    }

   //Saída - A substituir com comentário adequado
    printf("Maior valor: %d\n", maior);
    printf("Menor valor: %d\n", menor);

    getchar();
    return 0;
}
