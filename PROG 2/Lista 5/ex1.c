      /***************************************************************************
         CABEÇALHO
         Enunciado:
         Autor: Felicio Almeida

         Histórico de Versão
         1.0 Versão Original. Responsável: Felicio Almeida
      ********************************************************************/

      /* Importação de Bibliotecas */
      #include <stdio.h>

      int main() {
      int V[6];
      int contador_negativos = 0;

      // Leitura dos valores no vetor
      for (int i = 0; i < 6; i++) {
         printf("Digite o valor para V[%d]: ", i);
         scanf("%d", &V[i]);

         // Verifica se o valor é negativo e incrementa o contador, se for o caso
         if (V[i] < 0) {
               contador_negativos++;
         }
      }

      // Exibição do resultado
      printf("Quantidade de valores negativos no vetor: %d\n", contador_negativos);

      return 0;
      }
