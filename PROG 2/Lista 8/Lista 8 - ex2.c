/***************************************************************************
   CABEÇALHO
   Enunciado:
   Autor: Felicio Almeida

   Histórico de Versão
   1.0 Versão Original. Responsável: Felicio Almeida
********************************************************************/

/* Importação de Bibliotecas */
#include <stdio.h>


void troca (int x, int y) {
    int aux, novoX, novoY;
    aux = x;
    novoX = y;
    novoY = aux;
    //Saída
    printf("Os novos valores de x e y são:\nx: %d \ny: %d", novoX, novoY);
}

/* Função principal */
int main() {
    /* Declaração de variáveis */
    int x, y;

    //Entrada -
    printf("Digite os valores de x e y para serem trocados:\n");
    printf("x: ");
    scanf("%d", &x);
    printf("y: ");
    scanf("%d", &y);

    //Processamento e saida -
    troca(x, y);

    //Encerramento
    getchar();
    return 0;
}
