/***************************************************************************
   CABEÇALHO
   Enunciado: Faça um programa que dados três números os imprima em ordem crescente.
   Autor: Felicio Almeida

   Histórico de Versão
   1.0 Versão Original. Responsável: Felicio Almeida
********************************************************************/

/* Importação de Bibliotecas */
#include <stdio.h>

/* Função principal */
int main() {
    /* Declaração de variáveis */
    int num1, num2, num3, maior;

    //Entrada - 
    printf("Digite 3 numeros: ");
    scanf("%d", &num1);
    scanf("%d", &num2);
    scanf("%d", &num3);

    //Processamento - ordenando os 3 numeros
    if (num1 <= num2 && num1 <= num3) {
        printf("%d, ", num1);
        if (num2 <= num3) {
            printf("%d, %d\n", num2, num3);
        }   else {
            printf("%d, %d\n", num3, num2);
        } 
    } else if (num2 <= num1 && num2 <= num3) {
        printf("%d, ", num2);
        if (num1 <= num3) {
            printf("%d, %d\n", num1, num3);
        } else {
            printf("%d, %d\n", num3, num1);
        }
    } else {
        printf("%d, ", num3);
        if (num1 <= num2) {
            printf("%d, %d\n", num1, num2);
        } else {
            printf("%d, %d\n", num2, num1);
        }
    }

    //Encerramento
    getchar();
    return 0;
}
