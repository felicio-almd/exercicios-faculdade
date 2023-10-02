/***************************************************************************
   CABEÇALHO
   Enunciado: Versão 3 do exercicio de sala - Entrar com dados do aluno e calcular a media das suas notas na disciplina e imprimir todos os dados e notas,
   tambem imprimir a media final, se a media for abaixo de 7 pedir a nota final e calcular a media
   Autor: Felicio Almeida

   Histórico de Versão
   1.0 Versão Original. Responsável: Felicio Almeida (Dados do aluno)
   2.0 Versão. Responsável: Felicio Almeida (calculando media do aluno)
   3.0 Versão. Responsável: Felicio Almeida (conferindo se a media está acima ou abaixo de 7, se for abaixo de 7 pedir a nota final e calcular a media)
********************************************************************/

/* Importação de Bibliotecas */
#include <stdio.h>
#include <stdlib.h>

/* Função principal */
int main() {
    /* Declaração de variáveis */
    char nome[50], curso[30], disciplina[30], nascimento[11];
    int matricula, periodo; 
    float nota1, nota2, media = 0, notaFinal, mediaFinal;

    //Entrada - Entrada dos dados do aluno
    printf("Digite seu nome: ");
    scanf("%s", nome);
    printf("Digite sua data de nascimento(DD/MM/AAAA): ");
    scanf("%s", nascimento);
    printf("Digite sua matricula: ");
    scanf("%d", &matricula);
    printf("Digite seu curso: ");
    scanf("%s", curso);
    printf("Digite seu periodo: ");
    scanf("%d", &periodo);
    printf("Digite a disciplina desejada: ");
    scanf("%s", disciplina);
    printf("Digite a primeira nota nessa disciplina: ");
    scanf("%f", &nota1);
    printf("Digite a segunda nota nessa disciplina: ");
    scanf("%f", &nota2);

    //Processamento - Calculo da media da nota na disciplina desejada
    media = (nota1 + nota2)/2;
    if (media < 7) {
        printf("Digite a nota da Prova Final: ");
        scanf("%f", &notaFinal);
        mediaFinal = (media + notaFinal)/2;
        media = mediaFinal;
    }
    
    if (media >= 7){
        mediaFinal = media;
    }
   

    //Saída - Mostrando os dados do usuario e media das notas dele na materia
    printf("\nNome: %s\n Data de Nascimento: %s\n Matricula: %d\n Curso: %s\n Periodo: %d\n Disciplina: %s\n Primeira Nota: %.2f\n Segunda Nota: %.2f\n Media: %.2f\n Nota Final: %.2f\n Media Final: %.2f.\n\n",
    nome, nascimento, matricula, curso, periodo, disciplina, nota1, nota2, media, notaFinal, mediaFinal);


    //Encerramento
    getchar();
    return 0;
}
