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
    int idade;

    //Entrada - A substituir com comentário adequado
    printf("Digite a idade da pessoa: ");
    scanf("%d", &idade);

    //Processamento - A substituir com comentário adequado
    if (idade < 18) {
      printf("Menor de idade\n");
    } else if( idade > 18 && idade < 65) {
      printf("Maior de idade.\n");
    } else {
      printf("Idosa.\n");
    }

    //Encerramento
    getchar();
    return 0;
}
