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
    int num1, num2, quad1, quad2;

    //Entrada - A substituir com comentário adequado
    printf("Digite 2 numeros inteiros: ");
    scanf("%d", &num1);
    scanf("%d", &num2);

    //Processamento - 
    quad1 = pow(num1, 2);
    quad2 = pow(num2, 2);

    if (quad1 < quad2) {
        printf("%d elevado ao quadrado e o menor valor.\n", num1);
    } else if (quad2 < quad1) {
        printf("%d elevado ao quadrado e o menor valor.\n", num2);
    } else {
        printf("Os dois números resultam no mesmo valor ao serem elevados ao quadrado.\n");
    }

    //Encerramento
    getchar();
    return 0;
}
