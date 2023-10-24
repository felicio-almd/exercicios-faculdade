      /***************************************************************************
         CABEÇALHO
         Enunciado: 
         
         Faça um algoritmo que leia um vetor V[10] e um vetor X[10]. A seguir, crie um vetor Y[20] que conterá
         os valores dos vetores V e X em ordem crescente.

         Autor: Felicio Almeida

         Histórico de Versão
         1.0 Versão Original. Responsável: Felicio Almeida
      ********************************************************************/

      /* Importação de Bibliotecas */
      #include <stdio.h>

      /* Declaração de constantes */
      #define TAM_V 10      
      #define TAM_X 10 
      #define TAM_Y 10 

      /* Função principal */
      int main() {
         /* Declaração de variáveis */
         int v[TAM_V], x[TAM_X], y[TAM_Y];
         int i, aux;

         //Entrada - 
         for ( i = 0; i < TAM_V; i++) {
            printf("Digite o valor [%d][%d] do vetor V: ");
            scanf("%d", &v[i]);
         }

         for ( i = 0; i < TAM_X; i++) {
            printf("Digite o valor [%d][%d] do vetor X: ");
            scanf("%d", &x[i]);
         }

         //Processamento - 

         for ( i = 0; i < TAM_Y; i++) {
            
         }

         //Saída - 

         //Encerramento
         getchar();
         return 0;
      }
