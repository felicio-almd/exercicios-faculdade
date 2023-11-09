/*CABE�ALHO
Arquivo: exercicio5.c
Objetivo: controle de veiculos
*/

/*IMPORTA��O DE BIBLIOTECAS*/
#include <stdio.h>
#include <string.h>


/*Declara��o de constantes*/
#define NUM_VEICULOS 2

/*Declara��o de estrutura de veiculos*/
typedef struct Veiculo {
    char proprietario[50], chassi[18], modelo[25], marca[25], cor[17], combustivel[25], placa[10];
    int ano;
} tVeiculo;

/*CORPO PRINCIPAL*/
int main(){
    /*DECLARA��O DE VARI�VEIS*/

    struct Veiculo veiculo1;
    tVeiculo veiculos[NUM_VEICULOS];
    int i;

    /*SOLICITA��O DE ENTRADAS:*/
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

    /*SA�DA DE DADOS*/


     /*FINALIZA��O*/

     getchar();
     return 0;
}
