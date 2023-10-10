

/* Importação de Bibliotecas */
#include <stdio.h>

/* Declaração de constantes */


/* Função principal */
int main() {
    /* Declaração de variáveis */
    char m[10][2];
    char g[2];
    int i, j;

    //Entrada -
    printf("Digite o gabarito:\n ");
    for ( i = 0; i < 2; i++){
        printf("questao[%d]: ", i+1);
        scanf(" %c", &g[i]);
    }

    printf("Digite as respostas: \n");
    for (i = 0; i < 10; i++){
        for (j = 0; j < 2; j++) {
            printf("Digite a resposta %d do aluno %d : ", j+1, i+1);
            scanf(" %c", &m[i][j]);
        }
        if (m[j] == g[i]){
            resultado++;
        }
    }
    
    printf("Resultados")




    //Processamento -


    //Saída -


    //Encerramento
    getchar();
    return 0;
}
