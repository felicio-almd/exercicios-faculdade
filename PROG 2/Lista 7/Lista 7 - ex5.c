/*CABEÇALHO
Arquivo: exercicio5.c
Objetivo: controle de veiculos
*/

/*IMPORTAÇÃO DE BIBLIOTECAS*/
#include <stdio.h>
#include <string.h>


/*Declaração de constantes*/
#define NUM_VEICULOS 2

/*Declaração de estrutura de veiculos*/
typedef struct Veiculo {
    char proprietario[50], chassi[18], modelo[25], marca[25], cor[17], combustivel[25], placa[10];
    int ano;
} tVeiculo;

/*CORPO PRINCIPAL*/
int main(){
    /*DECLARAÇÃO DE VARIÁVEIS*/

    struct Veiculo veiculo1;
    tVeiculo veiculos[NUM_VEICULOS];
    int i;

    /*SOLICITAÇÃO DE ENTRADAS:*/
    printf("Dados dos veiculos\n");
    for (i = 0; i < NUM_VEICULOS; i++) {
        printf("\nVeiculo: [%d]\n", i+1);
        printf("Informe o nome do proprietario: ");
        gets(veiculo1.proprietario);
        printf("Informe o chassi do veiculo: ");
        gets(veiculo1.chassi);
        printf("Informe o modelo do veiculo: ");
        gets(veiculo1.chassi);
        printf("Informe a marca do veiculo: ");
        gets(veiculo1.chassi);
        printf("Informe a cor do veiculo: ");
        gets(veiculo1.chassi);
        printf("Informe o combustivel usado pelo veiculo: ");
        gets(veiculo1.chassi);
        printf("Informe o ano de fabricacao do veiculo: ");
        scanf("%d", &veiculo1.ano);
        printf("Informe a placa do veiculo: ");
        gets(veiculo1.placa);
    }

    /*PROCESSAMENTO:*/

    /*SAÍDA DE DADOS*/


     /*FINALIZAÇÃO*/

     getchar();
     return 0;
}
