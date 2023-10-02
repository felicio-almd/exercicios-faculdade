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
   
    float nota;
    

    //Entrada - A substituir com comentário adequado
    printf("Digite a nota do aluno na disciplina: ");
    scanf("%f", &nota);

    //Processamento - 
    /*if ( nota >= 0 && nota < 5 ) {
        conceito = 1;
    }*/

    switch (nota) {
        case 0.0 ... 4.9:
            printf("Conceito = D");
            break;
        case 5.0 ... 6.9:
            printf("Conceito = C");
            break;
        case 7.0 ... 8.9:
            printf("Conceito = B");
            break;
        case 9.0 ... 10.0:
            printf("Conceito = A");
            break;
        default:
            printf("Conceito inexistente"); // N para Nota inválida
            break;
    }


    //Saída - A substituir com comentário adequado

    //Encerramento
    getchar();
    return 0;
}
