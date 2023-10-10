

/* Importação de Bibliotecas */
#include <stdio.h>

/* Declaração de constantes */


/* Função principal */
int main() {
    /* Declaração de variáveis */
    char m[10][2];
    char g[2];
    int acertos[10]
    int erros[10];
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
    }

    printf("Resultados: \n");
    for ( i = 0 ; i < 10 ; i++) {
        int acerto = 0;
        int erro = 0;

        for ( j = 0 ; j < 2; j++){
            if(vetorA[j] == matriz[i][j]){
                acerto++;
            } else {
                erro++;
            }
        }
        acertos[i] = acerto;
        erros[i] = erro;
    }

    printf("\n ==== Resultados  ==== \n\n");

    for ( i = 0; i <5 ; i ++){
        printf("Aluno %d",i+1);
        printf("\n");
        printf("  Acertos : %d",acertos[i]);
        printf("\n");
        printf("  Erros : %d",erros[i]);
        printf("\n");
        printf("\n");
    }
 }




    //Processamento -


    //Saída -


    //Encerramento
    getchar();
    return 0;
}
