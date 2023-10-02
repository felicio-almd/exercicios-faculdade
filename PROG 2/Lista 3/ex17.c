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
   float salario, novoSalario;
   int cargo;
    //Entrada - A substituir com comentário adequado
   printf("digite o salario do funcionario: ");
   scanf("%f", &salario);
   printf("Digite o codigo de cargo do funcionario (101, 102, 103, 104): ");
   scanf("%d", &cargo);

    //Processamento - A substituir com comentário adequado
   if ( cargo == 101 ) {
      printf("O funcionario eh gerente.\n");
      novoSalario = salario;
   } else if ( cargo == 102 ) {
      printf("O funcionario eh Analista.\n");
      novoSalario = salario + (salario * 0.005);
   } else if ( cargo == 103 ) {
      printf("O funcionario eh Programador.\n");
      novoSalario = salario + (salario * 0.0125);
   } else if ( cargo == 104 ) {
      printf("O funcionario eh Designer.\n");
      novoSalario = salario + (salario * 0.03);
   } else {
      printf("Cargo invalido");
   }

    //Saída - A substituir com comentário adequado
   printf("Seu novo salario eh: %.2f ", novoSalario);
    //Encerramento
    getchar();
    return 0;
}
