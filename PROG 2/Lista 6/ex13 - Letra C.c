      /***************************************************************************
         CABEÇALHO
         Enunciado: Letra C
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
         int i, j, soma;

         //Entrada - A substituir com comentário adequado
         printf("Digite os elementos matriz M[7][7]: \n");
         for (i = 0; i < LINHAS; i++){
            for (j = 0; j < COLUNAS; j++){
               printf("Elemento [%d][%d]: ", i+1, j+1);
               scanf("%d", &m[i][j]);
            }
         }

         //Processamento - QUANDO OS NUMEROS DE I FOREM MENORES QUE OS DE J É EFETUADO A SOMA DO ELEMENTO
         soma = 0;

         for (i = 0; i < LINHAS; i++){
            for (j = 1; j < COLUNAS; j++){
               if ( i < j ){
                    soma += m[i][j];
                }
            }
         }

         //Saída - A substituir com comentário

         printf("A soma dos elementos da Matriz eh: %d . \n", soma);

         //Encerramento
         getchar();
         return 0;
      }
