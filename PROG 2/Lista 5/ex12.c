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
#define TAM_GABARITO 13
#define TAM_RESPOSTAS 13
#define APOSTADORES 10


/* Função principal */
int main() {
    /* Declaração de variáveis */
    int g[TAM_GABARITO], r[TAM_RESPOSTAS];
    int j, i, acertos;

    //Entrada -
    printf("Digite os valores do gabarito: \n");
    for (i = 0; i < TAM_GABARITO; i++){
        printf("Valor[%d]:", i+1);
        scanf("%d", &g[i]);
    }


    //Processamento -
    for (i = 0; i < APOSTADORES; i++){
        acertos = 0;
        printf("Digite as respostas do apostador [%d]:\n", i+1);
        for (j = 0; j< TAM_RESPOSTAS; j++) {
            printf("Resposta[%d]:", j+1);
            scanf("%d", &r[j]);
            if (r[j] == g[i]){
                acertos++;
            }
        }
        printf("Acertos do apostador %d : %d\n", i+1, acertos);
    }


    //Saída -


    //Encerramento
    getchar();
    return 0;
}
