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
    float a, b, c;

    //Entrada - Solicita os comprimentos dos lados ao usuário
    printf("Informe o comprimento do lado a: ");
    scanf("%f", &a);

    printf("Informe o comprimento do lado b: ");
    scanf("%f", &b);

    printf("Informe o comprimento do lado c: ");
    scanf("%f", &c);

    //Processamento - Verifica se os lados formam um triângulo
    if (a + b > c && a + c > b && b + c > a) {
        // Verifica o tipo de triângulo
        if (a == b && b == c) {
            printf("Triangulo equilatero\n");
        } else if (a == b || a == c || b == c) {
            printf("Triangulo isosceles\n");
        } else {
            printf("Triangulo escaleno\n");
        }
    } else {
        printf("Nao formam triangulo\n");
    }

    //Encerramento
    getchar();
    return 0;
}
