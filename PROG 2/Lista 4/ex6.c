/***************************************************************************
   CABEÇALHO
   Enunciado:
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
    int contador = 0; 
    float media, soma = 0;

    //Entrada - A substituir com comentário adequado
    printf("Digite valores para calcular a media(Numero 0 encerra)\n");

    //Processamento - A substituir com comentário adequado
      while (1)
      {
         printf("digite um numero:");
         scanf("%d", &num);
         
         if (num == 0){
         break;
         }
      if (num % 2 == 0) {
            soma += num;
            contador++;
        }

      }

   //Saída
      if (contador == 0) {
        printf("Nenhum numero par foi inserido.\n");
      } else {
        media = soma / contador;
        printf("Media dos numeros pares: %.2f\n", media);
      }
      
    //Encerramento
    getchar();
    return 0;
}
