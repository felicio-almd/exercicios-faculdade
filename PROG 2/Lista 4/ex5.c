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
    int valor;
    int contador = 0;
    float media, soma = 0;

    //Entrada - A substituir com comentário adequado
    printf("Digite valores para calcular a media(Numero negativo encerra)\n");
   
    //Processamento - A substituir com comentário adequado
    while (1)
    {
      printf("Digite um valor: ");
      scanf("%d", &valor);

      if (valor < 0){
         break;
      }

      soma += valor;
      contador++;
    }
    
    //Saída - 

    if (contador == 0) {
        printf("Nenhum valor positivo foi inserido.\n");
    } else {
        media = soma / contador;
        printf("Media dos valores positivos: %.2f\n", media);
    }

    //Encerramento
    getchar();
    return 0;
}
