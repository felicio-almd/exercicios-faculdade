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

/* Função principal */
int main() {
    /* Declaração de variáveis */
    float a, b, c;
    float delta, raiz1, raiz2;

    //Entrada -
    printf("Informe o coeficiente a: ");
    scanf("%f", &a);
    printf("Informe o coeficiente b: ");
    scanf("%f", &b);
    printf("Informe o coeficiente c: ");
    scanf("%f", &c);

    //Processamento -
    delta = (b * b) - (4 * a * c);
    if (delta > 0) {
        // Duas raízes reais distintas
        raiz1 = (-b + sqrt(delta)) / (2 * a);
        raiz2 = (-b - sqrt(delta)) / (2 * a);
        printf("As raizes sao reais e distintas:\n");
        printf("Raiz 1 = %.2f\n", raiz1);
        printf("Raiz 2 = %.2f\n", raiz2);
    } else if (delta == 0) {
        // Uma raiz real (raiz dupla)
        raiz1 = -b / (2 * a);
        printf("A raiz e real e dupla:\n");
        printf("Raiz = %.2f\n", raiz1);
    } else {
        // Não há raízes reais
        printf("Não há raízes reais.\n");
    }

    //Encerramento
    getchar();
    return 0;
}
