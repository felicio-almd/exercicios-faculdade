/***************************************************************************
   CABEÇALHO
   Enunciado: Escrever um programa que leia três valores correspondentes às medidas dos lados (a, b e c) de
uma figura geométrica, e verifica se eles formam ou não um triângulo. Caso os valores formem um
triângulo, calcular e escrever a área deste. Caso contrário, escrever os valores lidos com a
mensagem: “Não formam triângulo”.
Obs. 1: Supor que os valores lidos são inteiros e positivos.
Obs. 2: Em todo triângulo, qualquer lado tem medida menor que a soma das medidas dos outros
dois. 
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
    int ladoA, ladoB, ladoC;
    float area, semiperimetro;

    //Entrada - lados da figura geometrica
    printf("digite o lado a: ");
    scanf("%d", &ladoA);
    printf("digite o lado b: ");
    scanf("%d", &ladoB);
    printf("digite o lado c: ");
    scanf("%d", &ladoC);

    //Processamento - Verificar se formam um triangulo
   if (ladoA < ladoB + ladoC && ladoB < ladoA + ladoC && ladoC < ladoA + ladoB) {
        // Calcula o semiperímetro
        semiperimetro = (ladoA + ladoB + ladoC) / 2.0;

        // Calcula a área usando a fórmula de Heron
        area = sqrt(semiperimetro * (semiperimetro - ladoA) * (semiperimetro - ladoB) * (semiperimetro - ladoC));

   // Saida - 
        printf("Os valores formam um triangulo.\n");
        printf("A area do triangulo e: %.2lf\n", area);
    } else {
        printf("Os valores nao formam um triangulo.\n");
    }

   getchar();
   return 0;
}
