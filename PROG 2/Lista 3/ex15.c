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
    int mes;

    //Entrada - leitura do digito do mes
    printf("Digite o mes ( 1 p/ Janeiro ... 12 p/ Dezembro ): ");
    scanf("%d", &mes);

    //Processamento - verificação do mes indicado
    switch (mes) {
      case 1:
      printf("Janeiro\n");
      break;
      case 2:
      printf("Fevereiro\n");
      break;
      case 3:
      printf("Marco\n");
      break;
      case 4:
      printf("Abril\n");
      break;
      case 5:
      printf("Maio\n");
      break;
      case 6:
      printf("Junho\n");
      break;
      case 7:
      printf("Julho\n");
      break;
      case 8:
      printf("Agosto\n");
      break;
      case 9:
      printf("Setembro\n");
      break;
      case 10:
      printf("Outubro\n");
      break;
      case 11:
      printf("Novembro\n");
      break;
      case 12:
      printf("Dezembro\n");
      break;
    
    default:
      printf("Mes invalido.\n");
      break;
    }

    //Encerramento
    getchar();
    return 0;
}
