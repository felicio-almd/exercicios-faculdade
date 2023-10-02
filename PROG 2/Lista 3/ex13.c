/***************************************************************************
   CABEÇALHO
   Enunciado: Faça um programa que leia a data de nascimento (valores dd, mm e aaaa) de uma pessoa e o dia
atual. Calcule e mostre a idade da pessoa em dias, meses e anos. Verifique e mostre, também, se
ela já tem idade suficiente para tirar carteira de habilitação e votar.
Obs.: Ignore os anos bissextos, ou seja, 1 ano equivale a 12 meses que equivale a 365 dias.
   Autor: Felicio Almeida

   Histórico de Versão
   1.0 Versão Original. Responsável: Felicio Almeida
********************************************************************/

/* Importação de Bibliotecas */
#include <stdio.h>

/* Função principal */
int main() {
    /* Declaração de variáveis */
    int diaNascimento, mesNascimento, anoNascimento;
    int diaAtual, mesAtual, anoAtual;
    int idadeAnos, idadeMeses, idadeDias;

    //Entrada - A substituir com comentário adequado
    // Solicita a data de nascimento
    printf("Insira a data de nascimento (dd mm aaaa): ");
    scanf("%d %d %d", &diaNascimento, &mesNascimento, &anoNascimento);

    // Solicita o dia atual
    printf("Insira o dia atual: ");
    scanf("%d", &diaAtual);

    // Solicita o mês atual
    printf("Insira o mês atual: ");
    scanf("%d", &mesAtual);

    // Solicita o ano atual
    printf("Insira o ano atual: ");
    scanf("%d", &anoAtual);

    //Processamento -

    // Calcula a idade em anos, meses e dias
    idadeAnos = anoAtual - anoNascimento;
    idadeMeses = mesAtual - mesNascimento;
    idadeDias = diaAtual - diaNascimento;

    // Ajusta a idade se os meses ou dias forem negativos
    if (idadeDias < 0) {
        idadeMeses--;
        idadeDias += 30; // Considerando um mês com 30 dias para simplificar
    }
    if (idadeMeses < 0) {
        idadeAnos--;
        idadeMeses += 12;
    }

    // Verifica se a pessoa tem idade para tirar carteira de habilitação (18 anos)
    if (idadeAnos >= 18) {
        printf("A pessoa tem idade para tirar carteira de habilitacao.\n");
    } else {
        printf("A pessoa ainda nao tem idade para tirar carteira de habilitacao.\n");
    }

    // Verifica se a pessoa tem idade para votar (16 anos)
    if (idadeAnos >= 16) {
        printf("A pessoa tem idade para votar.\n");
    } else {
        printf("A pessoa ainda nao tem idade para votar.\n");
    }

    //Saída - Exibe a idade calculada
    printf("Idade: %d anos, %d meses, %d dias.\n", idadeAnos, idadeMeses, idadeDias);


    //Encerramento
    getchar();
    return 0;
}
