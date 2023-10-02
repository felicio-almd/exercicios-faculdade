/***************************************************************************
   CABEÇALHO
   Enunciado: Faça um programa que leia um número inteiro maior que zero e
    informe se tal número é par ou ímpar.
   Autor: Felicio Almeida

   Histórico de Versão
   1.0 Versão Original. Responsável: Felicio Almeida
********************************************************************/

/* Importação de Bibliotecas */
#include <stdio.h>

/* Função principal */
int main() {
    /* Declaração de variáveis */
   int num;

    //Entrada - leitura do numero digitado
   printf("Digite um numero inteiro maior que zero: ");
   scanf("%d", &num);

    //Processamento e saida - verificação se o numero é inteiro //
   if (num > 0){
      if ( num % 2 == 0 ) {
         printf("\nNumero par\n\n");
      }  
      else {
         printf("\nNumero impar\n\n");
      }
   }
   else {
      printf("\nNumero digitado nao e maior que zero\n\n");
   }

    //Encerramento
    getchar();
    return 0;
}
