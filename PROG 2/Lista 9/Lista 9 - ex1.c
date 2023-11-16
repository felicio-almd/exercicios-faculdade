/***************************************************************************
   CABEÇALHO
   Enunciado:
   Autor: Felicio Almeida

   Histórico de Versão
   1.0 Versão Original. Responsável: Felicio Almeida
********************************************************************/

/* Importação de Bibliotecas */
#include <stdio.h>


void cubo (float *numero) {
    *numero = (*numero)*(*numero)*(*numero);
}

/* Função principal */
int main() {
    /* Declaração de variáveis */
    float num;

    //Entrada -
    printf("Digite um valor para conferir seu cubo: ");
    scanf("%f", &num);

    //Processamento -
    cubo(&num);

    //Saída -
    printf("O cubo do numero: %f", num);

    //Encerramento
    getchar();
    return 0;
}
