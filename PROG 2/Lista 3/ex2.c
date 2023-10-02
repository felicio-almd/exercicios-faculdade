/***************************************************************************
   CABEÇALHO
   Enunciado: Faça um programa para ler dois valores reais e verificar se são iguais, 
   imprimindo como resposta uma mensagem de confirmação.
   Autor: Felicio Almeida

   Histórico de Versão
   1.0 Versão Original. Responsável: Felicio Almeida
********************************************************************/

/* Importação de Bibliotecas */
#include <stdio.h>

/* Função principal */
int main() {
    /* Declaração de variáveis */
    float num1, num2;

    //Entrada - A substituir com comentário adequado
   printf("Digite um numero real: ");
   scanf("%f", &num1);
    printf("Digite outro numero real: ");
   scanf("%f", &num2);

    //Processamento - A substituir com comentário adequado
    if ( num1 == num2 ) {
      printf("Numeros iguais!!\n\n");
    }
    else {
      printf("Numeros diferentes!!\n\n");
    }

    //Saída - A substituir com comentário adequado

    //Encerramento
    getchar();
    return 0;
}
