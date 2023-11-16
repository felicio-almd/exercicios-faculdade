/***************************************************************************
   CABEÇALHO
   Enunciado:
   Autor: Felicio Almeida

   Histórico de Versão
   1.0 Versão Original. Responsável: Felicio Almeida
********************************************************************/

/* Importação de Bibliotecas */
#include <stdio.h>

#define TAM_VETOR 2

void metade (float numero[]) {
    numero[0] = numero[0]/2;
    printf("A metade do numero eh: %f", numero[0]);
}

/* Função principal */
int main() {
    /* Declaração de variáveis */
    float a[TAM_VETOR];
    int i;

    for (i = 0; i < TAM_VETOR; i++) {
        printf("Digite os valores de A: ");
        scanf("%f", &a[i]);
    }

    for (i = 0; i < TAM_VETOR; i++) {
        metade(&a[i]);
    }
    //Encerramento
    getchar();
    return 0;
}
