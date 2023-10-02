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

/* Função principal */
int main() {
    /* Declaração de variáveis */
    float numeradorA = 1, denominadorA = 1;
    double somaA  = 0.0;
    float numeradorB = 2, denominadorB = 50;
    double somaB = 0.0;
    int n;

    //Processamento -

    while (numeradorA <= 99 && denominadorA <= 50) {
        somaA += numeradorA / denominadorA;
        numeradorA += 2;
        denominadorA += 1;
    }
   
    for (n = 1; numeradorB <= 50 && denominadorB >= 1; n++) {
        somaB += numeradorB / denominadorB;
        numeradorB = pow(2, n); // Calcula 2 elevado a n
        denominadorB --; // Diminui o denominador
    }

    //Saída -
    printf("Primeiro Somatorio: %.2f \n", somaA);
    printf("Segundo somatorio: %.2f \n ", somaB);

    //Encerramento
    getchar();
    return 0;
}
