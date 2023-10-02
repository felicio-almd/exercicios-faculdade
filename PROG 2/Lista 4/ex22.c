/***************************************************************************
   CABEÇALHO
   Enunciado: A prefeitura de uma cidade fez uma pesquisa entre seus habitantes, 
   coletando dados sobre o salário e número de filhos. A prefeitura deseja saber:
a. Média do salário da população.
b. Média do número de filhos.
c. Maior salário.
d. Percentual de pessoas com salário até R$100,00.
O final da leitura de dados se dará com a entrada de um salário negativo.

   Autor: Felicio Almeida

   Histórico de Versão
   1.0 Versão Original. Responsável: Felicio Almeida
********************************************************************/

/* Importação de Bibliotecas */
#include <stdio.h>

/* Função principal */
int main() {
    /* Declaração de variáveis */
   float salario, maiorSalario = 0, salarioTodosHabitantes = 0;
   int numeroFilhos, totalFilhos = 0;
   int habitantes = 0, salarioAte100 = 0;
   float mediaSalario, mediaFilhos, percentualAte100; 

    //Entrada - A substituir com comentário adequado
      printf("Digite o salario do habitante (valor negativo encerra) : ");
      scanf("%f", &salario);

    //Processamento - A substituir com comentário adequado
   while (salario >= 0)
   {
      printf("Qual numero de filhos do habitante? ");
      scanf("%d", &numeroFilhos);
      
      habitantes++;
      salarioTodosHabitantes += salario;
      totalFilhos += numeroFilhos;
      
      if (salario > maiorSalario){
         maiorSalario = salario;
      }
      if (salario <= 100){
         salarioAte100++;
      }

      printf("Digite o salario do habitante (valor negativo encerra) : ");
      scanf("%f", &salario);
   } ;

   
   if (habitantes > 0) {
      mediaSalario = salarioTodosHabitantes / habitantes;
      mediaFilhos = totalFilhos / habitantes;
      percentualAte100 = salarioAte100 / habitantes*100; 
      
      printf("Media do salario da populacao: %.2f\n", mediaSalario);
      printf("Media do numero de filhos: %.2f\n", mediaFilhos);
      printf("Maior salario: %.2f\n", maiorSalario);
      printf("Percentual pessoas com ate 100 de salario: %.2f%%\n", percentualAte100);

   } else {
        printf("Nenhum dado foi inserido.\n");
    }
   

    //Saída - A substituir com comentário adequado

    //Encerramento
    getchar();
    return 0;
}
