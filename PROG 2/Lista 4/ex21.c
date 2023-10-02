/***************************************************************************
   CABEÇALHO
   Enunciado: Faça um algoritmo que imprima uma tabela com os valores 
   de (x, y) e f(x,y), para
   x = 1, 4, 9, 16, ..., 100 e y = 1,2,3,4,5;
   Autor: Felicio Almeida

   Histórico de Versão
   1.0 Versão Original. Responsável: Felicio Almeida
********************************************************************/

/* Importação de Bibliotecas */
#include <stdio.h>

/* Função principal */
int main() {
    /* Declaração de variáveis */
    int x, y;
    float resultado;

    //Entrada - 
    printf("x   y   f(x, y)\n");

    //Processamento -
   
   for (x = 1; x <= 100; x++) {
      if (x == 1 || x == 4 || x == 9 || x == 16 || x == 25 || x == 36 || x == 49 || x == 64 || x == 81 || x == 100){
         for (y = 1; y <= 5; y++) {
         resultado = ((x*x) + (3*x) + (y*y)) / (x*y + 5*y - 3*x + 15);
         printf("\nResultado com %d e %d = %.2f", x, y, resultado); 
         }
      }
   } 

   // for (x = 1; x <= 100; x++) { // x: 1, 2, 3, ..., 100
   //      // Verifica se x é um quadrado perfeito
   //      int quadrado_perfeito = 0;
   //      for (int i = 1; i * i <= x; i++) {
   //          if (i * i == x) {
   //              quadrado_perfeito = 1;
   //              break;
   //          }
   //      }

   //      if (quadrado_perfeito) {
   //          for (y = 1; y <= 5; y++) { // y: 1, 2, 3, 4, 5
   //              resultado = ((x * x) + (3 * x) + (y * y)) / (x * y + 5 * y - 3 * x + 15);
   //              printf("%d   %d   %.2lf\n", x, y, resultado);
   //          }
   //      }
   //  }

    //Encerramento
    getchar();
    return 0;
}
