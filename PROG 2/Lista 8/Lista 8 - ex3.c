/***************************************************************************
   CABEÇALHO
   Enunciado:
   Autor: Felicio Almeida

   Histórico de Versão
   1.0 Versão Original. Responsável: Felicio Almeida
********************************************************************/

/* Importação de Bibliotecas */
#include <stdio.h>


void sinal (int n) {
    if (n > 0) {
        printf("Numero positivo.\n");
    }
    else if (n<0){
        printf("Numero negativo.\n");
    }
    else {
        printf("Numero igual a zero.\n");
    }
}

/* Função principal */
int main() {
    /* Declaração de variáveis */
    int num;

    //Entrada -
    printf("Digite um valor de N: ");
    scanf("%d", &num);

    //Processamento e saida -
    sinal(num);

    //Encerramento
    getchar();
    return 0;
}
