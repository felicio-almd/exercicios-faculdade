      /***************************************************************************
         CABEÇALHO
         Enunciado:
         Autor: Felicio Almeida

         Histórico de Versão
         1.0 Versão Original. Responsável: Felicio Almeida
      ********************************************************************/

     /* Importação de Bibliotecas */
#include <stdio.h>

/* Declaração de constantes */
#define LINHAS 4
#define COLUNAS 4

/* Função principal */
int main() {
    /* Declaração de variáveis */
    int a[LINHAS][COLUNAS];
    int i, j, zeros, linhasNulas, colunasNulas;

    //Entrada -
    printf("Digite os elementos da matriz:\n");
    for (i = 0; i < LINHAS; i++){
        for (j = 0; j < COLUNAS; j++){
            printf("Elemento[%d][%d]:", i+1, j+1);
            scanf("%d", &a[i][j]);
        }
    }

    printf("Matriz Gerada:\n");
    for (i = 0; i < LINHAS; i++){
        for (j = 0; j < COLUNAS; j++){
            printf("%3d", a[i][j]);
        }
        printf("\n");
    }


    //Processamento -
    linhasNulas = 0;
    colunasNulas = 0;

    for (i = 0; i < LINHAS; i++){
        zeros = 0;
        for (j = 0; j < COLUNAS; j++){
            if ( a[i][j] == 0 ){
                zeros++;
            }
        }
        if (zeros == LINHAS) {
            linhasNulas++;
        }
    }

    for (j = 0; j < COLUNAS; j++){
        zeros = 0;
        for (i = 0; i < LINHAS; i++){
            if ( a[i][j] == 0 ){
                zeros++;
            }
        }
        if (zeros == COLUNAS) {
            colunasNulas++;
        }
    }


    //Saída -
    printf("A matriz tem %d linhas nulas e %d colunas nulas.\n", linhasNulas, colunasNulas);



    //Encerramento
    getchar();
    return 0;
}
