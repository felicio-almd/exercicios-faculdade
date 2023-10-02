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
    printf("Digite a quantidade de números a serem lidos: ");
    scanf("%d", &n);

    //Processamento - 
    if (n <= 0) {
        printf("Erro: Insira um valor positivo para n.\n");
        return 1; // Encerra o programa com código de erro
    }

    printf("Digite %d números:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &numero);
        printf("O triplo de %d é %d\n", numero, numero * 3);
    }
    
    //Encerramento
    getchar();
    return 0;
}
