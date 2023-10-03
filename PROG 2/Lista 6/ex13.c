      /***************************************************************************
         CABEÇALHO
         Enunciado: Letra E
         Autor: Felicio Almeida

         Histórico de Versão
         1.0 Versão Original. Responsável: Felicio Almeida
      ********************************************************************/

      /* Importação de Bibliotecas */
      #include <stdio.h>

      /* Declaração de constantes */

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
         int M[7][7];
         int i, j, soma = 0;

         //Entrada - A substituir com comentário adequado
         printf("Digite os elementos matriz M[7][7]: \n");
         for (i = 0; i < 7; i++){
            for (j = 0; j < 7; j++){
               printf("elemento [%d][%d]: ", i+1, j+1);
               scanf("%d", &M[i][j]);
            }
         }

         //Processamento - A substituir com comentário adequado

         for (i = 0; i < 7; i++){
            for (j = 0; j < 7; j++){
               soma += M[i][j];
            }
         }

         //Saída - A substituir com comentário 
         
         printf("A soma de todos os elementos da Matriz eh: %d . \n", soma);

         //Encerramento
         getchar();
         return 0;
      }