/***************************************************************************
   CABEÇALHO
   Enunciado:
   Autor: Felicio Almeida

   Histórico de Versão
   1.0 Versão Original. Responsável: Felicio Almeida
********************************************************************/

/* Importação de Bibliotecas */
#include <stdio.h>
#include <math.h>

/* Declaração de constantes */
#define PI 3.1415926535

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
    double r, area;
    char continuar;

    //Entrada - A substituir com comentário adequado

    //Processamento - A substituir com comentário adequado
    do
    {
      printf("Digite o valor do raio do circulo: ");
      scanf(" %lf", &r);

      area = PI * pow(r, 2);

      while (getchar() != '\n');
      
      printf("A area do circulo eh: %.10lf\n", area);

      printf("Deseja calcular mais areas? (S para Sim / N para Nao): \n");
      continuar = getchar();  

    } while (continuar == 'S' || continuar == 's');
    

    //Saída - A substituir com comentário adequado

    //Encerramento
    getchar();
    return 0;
}
