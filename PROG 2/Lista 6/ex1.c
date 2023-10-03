       /***************************************************************************
      CABEÇALHO
      Enunciado:
      Autor: Felicio Almeida

      Histórico de Versão
      1.0 Versão Original. Responsável: Felicio Almeida
   ********************************************************************/

   /* Importação de Bibliotecas */
   #include <stdio.h>

   /* Declaração de constantes */
   #define LINHAS 6
   #define COLUNAS 6
   #define TAM_VETOR 36

   /* Declaração de estruturas
      Nome:
      Objetivo: */

   /* Declaração de funções
      Nome:
      Entrada:
      Saída:
      Objetivo: */

   /* Função principal */
   int main() {
      /* Declaração de variáveis */
      int S[LINHAS][COLUNAS];
      int A, i, j, k;
      int v[TAM_VETOR];

      //Entrada - 
      printf("Digite um numero para multiplicar a matriz: ");
      scanf("%d", &A);
      printf("Digite a matriz S[6][6]: \n");
      for (i = 0; i < LINHAS; i++) {
        for (j = 0; j < COLUNAS; j++) {
            printf("Elemento[%d][%d]: ", i+1, j+1);
            scanf("%d", &S[i][j]);
        }
      }

      //Processamento - Feita a multiplicação dos numeros da matriz e armazenando em um vetor
      k = 0; // inicializando o indice do vetor v

      for (i = 0; i < LINHAS; i++) {
        for (j = 0; j < COLUNAS; j++){
            v[k] = S[i][j] * A;
            k++;
        }
      }

      //Saída - Loop imprimindo o vetor

      printf("Vetor resultante V[36]: \n");
      for ( i = 0; i < TAM_VETOR; i++) {
        printf("%d ", v[i]);
      }

      printf("\n");

      //Encerramento
      getchar();
      return 0;
   }
