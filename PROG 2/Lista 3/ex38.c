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
    float area;
    char figura;

    //Entrada - A substituir com comentário adequado
    printf("Digite a figura escolhida: (q - quadrado. r - retângulo. t - triângulo. p - trapézio.)");
    scanf(" %c", &figura);
    

    //Processamento - A substituir com comentário adequado

    switch (figura) {
        case 'q':
        case 'Q':
            {
                float lado;
                printf("Digite o lado do quadrado (cm): ");
                scanf("%f", &lado);
                area = lado * lado;
                printf("Área do quadrado: %.2f cm²\n", area);
                break;
            }
        case 'r':
        case 'R':
            {
                float comprimento, largura;
                printf("Digite o comprimento do retângulo (cm): ");
                scanf("%f", &comprimento);
                printf("Digite a largura do retângulo (cm): ");
                scanf("%f", &largura);
                area = comprimento * largura;
                printf("Área do retângulo: %.2f cm²\n", area);
                break;
            }
        case 't':
        case 'T':
            {
                float base, altura;
                printf("Digite a base do triângulo (cm): ");
                scanf("%f", &base);
                printf("Digite a altura do triângulo (cm): ");
                scanf("%f", &altura);
                area = 0.5 * base * altura;
                printf("Área do triângulo: %.2f cm²\n", area);
                break;
            }
        case 'p':
        case 'P':
            {
                float base_maior, base_menor, altura;
                printf("Digite a base maior do trapézio (cm): ");
                scanf("%f", &base_maior);
                printf("Digite a base menor do trapézio (cm): ");
                scanf("%f", &base_menor);
                printf("Digite a altura do trapézio (cm): ");
                scanf("%f", &altura);
                area = 0.5 * (base_maior + base_menor) * altura;
                printf("Área do trapézio: %.2f cm²\n", area);
                break;
            }
        default:
            printf("Opção inválida.\n");
    }
    //Saída - A substituir com comentário adequado

    //Encerramento
    getchar();
    return 0;
}
