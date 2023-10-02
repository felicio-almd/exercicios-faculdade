/***************************************************************************
   CABEÇALHO
   Enunciado: Escreva um programa que leia três valores a, b e c, e posteriormente calcula e escreve a média
ponderada com peso 5,0 para o maior dos três valores e peso 2,5 para os outros dois.
   Autor: Felicio Almeida

   Histórico de Versão
   1.0 Versão Original. Responsável: Felicio Almeida
********************************************************************/

/* Importação de Bibliotecas */
#include <stdio.h>

/* Função principal */
int main() {
    /* Declaração de variáveis */
   float a, b, c, maior, menor1, menor2, media;

    //Entrada - A substituir com comentário adequado
    printf("Digite o valor a: ");
    scanf("%f", &a);
    printf("Digite o valor b: ");
    scanf("%f", &b);
    printf("Digite o valor c: ");
    scanf("%f", &c);

    //Processamento - A substituir com comentário adequado
    if ( a >= b && a >= c) {
      maior = a;
      menor1 = b;
      menor2 = c;
    }
    if ( b >= a && b >= c) {
      maior = b;
      menor1 = a;
      menor2 = c;
    }
    else {
      maior = c;
      menor1 = a;
      menor2 = b;
    }

    // Calcula a média ponderada
    media = ((maior * 5.0) + (menor1 * 2.5) + (menor2 * 2.5) )/ 10.0;

    //Saída - mostrando a media
    printf("A media ponderada eh: %.2f \n", media);

    //Encerramento
    getchar();
    return 0;
}
