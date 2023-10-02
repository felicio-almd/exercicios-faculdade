/***************************************************************************
   CABEÇALHO
   Enunciado: Dados 5 num inteiros, ordena los por condicional simples
   Autor: Felicio Almeida

   Histórico de Versão
   1.0 Versão Original. Responsável: Maria Teixeira
********************************************************************/

/* Importação de Bibliotecas */
#include <stdio.h>


/* Função principal */
int main() {
    /* Declaração de variáveis */
    int num1, num2, num3, num4, num5, temp;

    //Entrada - Obtendo os 5 numeros inteiros
    printf("Entre com 5 numeros inteiros: ");
    scanf("%d", &num1);
    scanf("%d", &num2);
    scanf("%d", &num3);
    scanf("%d", &num4);
    scanf("%d", &num5);

    //Processamento - Verificar quais são os numeros maiores, usar apenas if para cada um, 
    // com um numero temporario que recebe o valor menor da comparaçao
    if (num1 > num2) {
        temp = num1;
        num1 = num2;
        num2 = temp;
    }
    if (num2 > num3) {
        temp = num2;
        num2 = num3;
        num3 = temp;
    }
    if (num3 > num4) {
        temp = num3;
        num3 = num4;
        num4 = temp;
    }
    if (num4 > num5) {
        temp = num4;
        num4 = num5;
        num5 = temp;
    }
    if (num1 > num2) {
        temp = num1;
        num1 = num2;
        num2 = temp;
    }
    if (num2 > num3) {
        temp = num2;
        num2 = num3;
        num3 = temp;
    }
    if (num3 > num4) {
        temp = num3;
        num3 = num4;
        num4 = temp;
    }
    if (num1 > num2) {
        temp = num1;
        num1 = num2;
        num2 = temp;
    }
    if (num2 > num3) {
        temp = num2;
        num2 = num3;
        num3 = temp;
    }
    if (num1 > num2) {
        temp = num1;
        num1 = num2;
        num2 = temp;
    }

    // Saída - Imprimir os números ordenados
    printf("\nNúmeros ordenados em ordem crescente: ");
    printf("%d %d %d %d %d\n", num1, num2, num3, num4, num5);

    //Encerramento
    getchar();
    return 0;
}
