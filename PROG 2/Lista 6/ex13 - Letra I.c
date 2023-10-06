      /***************************************************************************
         CABEÇALHO
         Enunciado: Letra I
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
         int m[LINHAS][COLUNAS];
         int i, j, soma, contagemLinhas;

         //Entrada - leitura dos elementos da matriz
         printf("Digite os elementos matriz m[7][7]: \n");
         for (i = 0; i < LINHAS; i++){
            for (j = 0; j < COLUNAS; j++){
               printf("elemento [%d][%d]: ", i+1, j+1);
               scanf("%d", &m[i][j]);
            }
         }

         //Processamento - CONSERTAR A SOMA
         soma = 0;
         contagemLinhas = 1;

         for (j = 0; j < COLUNAS; j++){
            for (i = contagemLinhas; i < LINHAS - contagemLinhas; i++){
               
               soma += m[i][j];
            
            }
            contagemLinhas++; 
         }

         //Saída -         
         printf("A soma de todos os elementos da Matriz eh: %d . \n", soma);

         //Encerramento
         getchar();
         return 0;
      }