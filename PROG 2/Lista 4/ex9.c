/***************************************************************************
   CABEÇALHO
   Enunciado:
   Autor: Felicio Almeida

    DUVIDA, SE DIGITAR O MESMO NUMERO EM DUAS POSIÇÕES DIFERENTES, 
    COMO RESOLVER ISSO?

   Histórico de Versão
   1.0 Versão Original. Responsável: Felicio Almeida
********************************************************************/

/* Importação de Bibliotecas */
#include <stdio.h>

/* Função principal */
int main() {
    /* Declaração de variáveis */
    int x, n, i;
    int numero;
    int posicao = 0;

    //Entrada - 
    printf("Digite o valor x: ");
    scanf("%d", &x);
    printf("digite a quantidade n de valores a serem lidos: ");
    scanf("%d", &n);

    //Processamento - A substituir com comentário adequado
    if ( n <= 0 ) {
        printf("quantidade invalida.\n");
        return 1;
    }

    for (i = 1; i <= n; i++){
        printf("Digite o numero %d: ", i);
        scanf(" %d", &numero);

        if (numero == x){
            posicao = i;
        }
    }
    
    if (posicao != 0)
    {
        printf("O valor %d aparece na posicao %d \n", x, posicao);
    } else {
        printf ("O valor %d nao foi encontrado.\n", x);
    }

    //Encerramento
    getchar();
    return 0;
}
