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
    float nota1, nota2, nota3;
    char opcao;
    float media;

    //Entrada - Solicita as notas ao usuário
    printf("Informe a primeira nota: ");
    scanf("%f", &nota1);
    printf("Informe a segunda nota: ");
    scanf("%f", &nota2);
    printf("Informe a terceira nota: ");
    scanf("%f", &nota3);
    printf("Escolha o tipo de media (a para Aritmetica, p para Ponderada): ");
    scanf(" %c", &opcao);

    //Processamento - Calcula a média com base7 na opção escolhida
    switch (opcao) {
        case 'a':
        case 'A':
            // Média aritmética
            media = (nota1 + nota2 + nota3) / 3;
            break;
        case 'p':
        case 'P':
            // Média ponderada
            media = (nota1 * 3 + nota2 * 3 + nota3 * 4) / 10;
            break;
        default:
            printf("Opcao invalida.\n");
            return 1; // Encerra o programa com código de erro
    }

    //Saída - Exibe o resultado
    printf("A media e: %.2f\n", media);

    //Encerramento
    getchar();
    return 0;
}
