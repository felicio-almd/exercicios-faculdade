/***************************************************************************
   CABEÇALHO
   Enunciado:
   Autor: Felicio Almeida

   Histórico de Versão
   1.0 Versão Original. Responsável: Felicio Almeida
********************************************************************/

/* Importação de Bibliotecas */
#include <stdio.h>
#include <string.h>

/* Função principal */
int main() {
    /* Declaração de variáveis */
    char nome[50];
    int numProvas;
    float somaNotas = 0;
    float media;

    //Entrada - A substituir com comentário adequado
    printf("Digite o nome do aluno: ");
    gets(nome);

   if (numProvas <= 0) {
        printf("Quantidade de provas inválida.\n");
        return 1; // Encerra o programa com código de erro
    }

    //Processamento - A substituir com comentário adequado
    for (int i = 1; i <= numProvas; i++) {
        float nota;
        printf("Digite a nota da prova %d: ", i);
        scanf("%f", &nota);
        somaNotas += nota;
    }

    media = somaNotas / numProvas;

    //Saída - Imprime o nome do aluno e a média das notas
    printf("Aluno: %s\n", nome);
    printf("Média das notas: %.2f\n", media);
    
    //Encerramento
    getchar();
    return 0;
}
