#include "arb.h"

int main()
{
    int opcao = 0, chave = 0;
    NoRB *T = NULL;
    NoRB *pred = NULL;
    printf("Digite a opcao desejada: \n1-Inserir\n2-Buscar\n3-Remover\n4-Imprimir\n5-Sair\n");

    while (scanf("%d", &opcao) == 1 && opcao != 5)
    {
        switch (opcao)
        {
        case 1:
            printf("Digite a chave a ser inserida: ");
            if (scanf("%d", &chave) == 1)
            {
                T = insercao(T, chave);
                printf("Chave %d inserida.\n", chave);
            }
            else
            {
                printf("Entrada inválida. Por favor, insira um número inteiro.\n");
                // Limpa o buffer de entrada
                while (getchar() != '\n')
                    ;
            }
            break;

        case 2:
            printf("Digite a chave a ser buscada: ");
            if (scanf("%d", &chave) == 1)
            {
                NoRB *resultado = busca(T, chave);
                if (resultado)
                    printf("Chave %d encontrada.\n", chave);
                else
                    printf("Chave %d não encontrada.\n", chave);
            }
            else
            {
                printf("Entrada inválida. Por favor, insira um número inteiro.\n");
                // Limpa o buffer de entrada
                while (getchar() != '\n')
                    ;
            }
            break;

        case 3:
            printf("Digite a chave a ser removida: ");
            if (scanf("%d", &chave) == 1)
            {
                T = remover(T, chave);
                printf("Chave %d removida (se existia).\n", chave);
            }
            else
            {
                printf("Entrada inválida. Por favor, insira um número inteiro.\n");
                // Limpa o buffer de entrada
                while (getchar() != '\n')
                    ;
            }
            break;

        case 4:
            printf("Imprimindo árvore:\n");
            imprime(T, 0);
            break;

        default:
            printf("Opção inválida. Por favor, escolha uma opção entre 1 e 5.\n");
            break;
        }
        printf("Digite a opcao desejada: \n1-Inserir\n2-Buscar\n3-Remover\n4-Imprimir\n5-Sair\n");
    }

    printf("Saindo...\n");
    return 0;
}
