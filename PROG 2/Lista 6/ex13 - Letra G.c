      /***************************************************************************
         CABEÇALHO
         Enunciado: Letra G
         Autor: Felicio Almeida

         Histórico de Versão
         1.0 Versão Original. Responsável: Felicio Almeida
      ********************************************************************/

      /* Importação de Bibliotecas */
      #include <stdio.h>

      /* Declaração de constantes */
      #define LINHAS 7  
      #define COLUNAS 7   

      /* Função principal */
      int main() {
         /* Declaração de variáveis */
         int M[LINHAS][COLUNAS];
         int i, j, soma;

         //Entrada - A substituir com comentário adequado
         printf("Digite os elementos matriz M[7][7]: \n");
         for (i = 0; i < LINHAS; i++){
            for (j = 0; j < COLUNAS; j++){
               printf("elemento [%d][%d]: ", i+1, j+1);
               scanf("%d", &M[i][j]);
            }
         }

         //Processamento - A substituir com comentário adequado
         soma = 0;

         for (i = 0; i < LINHAS; i++){
            for (j = 0; j < COLUNAS; j++){
               if (i + j >= LINHAS) {
                  soma += M[i][j];
               }
            }
         }

         //Saída - A substituir com comentário 
         printf("A soma de todos os elementos da Matriz eh: %d . \n", soma);

         //Encerramento
         getchar();
         return 0;
      }