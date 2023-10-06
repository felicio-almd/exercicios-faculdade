      /***************************************************************************
         CABEÇALHO
         Enunciado: Letra D
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

         //Processamento - somar os numeros em que a soma de i e j for menor ou igual i + j
         soma = 0;

         for (i = 0; i < LINHAS; i++){
            for (j = 0; j < COLUNAS; j++){
               if (i + j < LINHAS - 1) {
                soma += M[i][j];
            }
         }

         //Saída - Imprime a soma dos elementos selecionados
         
         printf("A soma dos elementos da Matriz eh: %d . \n", soma);

         //Encerramento
         getchar();
         return 0;
      }