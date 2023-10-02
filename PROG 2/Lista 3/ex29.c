/***************************************************************************
   CABEÇALHO
   Enunciado:
   Autor: Felicio Almeida

   Histórico de Versão
   1.0 Versão Original. Responsável: Felicio Almeida
********************************************************************/

/* Importação de Bibliotecas */
#include <stdio.h>
#include <stdlib.h>

/* Função principal */
int main() {
    /* Declaração de variáveis */
    char nome[100];
    int numProvas;
    float nota, somaNotas = 0.0;
    float media;

    //Entrada - Solicita o nome do aluno
    printf("Informe o nome do aluno: ");
    gets(nome);
    printf("Informe a quantidade de provas realizadas: ");
    scanf("%d", &numProvas);

    //Processamento - A substituir com comentário adequado
    printf("Informe as notas das %d provas:\n", numProvas);
    for (int i = 1; i <= numProvas; i++) {
        printf("Nota da prova %d: ", i);
        scanf("%f", &nota);
        somaNotas += nota;
    }
    // Calcula a média aritmética
    media = somaNotas / numProvas;

    //Saída - Exibe o nome do aluno e a média das notas
    printf("\nNome do aluno: %s\n", nome);
    printf("Media das notas: %.2f\n", media);

    //Encerramento
    getchar();
    return 0;
}
