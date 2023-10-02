/***************************************************************************
   CABEÇALHO
   Enunciado: Versão 3 do exercicio de sala - Entrar com dados do aluno e calcular a media das 
   suas notas na disciplina e imprimir todos os dados e notas,
   tambem imprimir a media final, se a media for abaixo de 7 pedir a nota final e calcular a media
   Autor: Felicio Almeida

   Histórico de Versão
    1.0 Versão Original. Responsável: Paulo Augusto Campana (Dados do aluno)
    2.0 Versão. Responsável: Felicio Almeida (calculando media do aluno) (Gabriel Campana)
    3.0 Versão. Responsável: Felicio Almeida (conferindo se a media está acima ou abaixo de 7, 
        se for abaixo de 7 pedir a nota final e calcular a media)
    4.0 Versão. Responsável: Felicio Almeida (identificar a situação de um aluno em uma disciplina)
********************************************************************/

/* Importação de Bibliotecas */
#include <stdio.h>
#include <stdlib.h>

/* Função principal */
int main() {
    /* Seção de variáveis */
    char nome[50], curso[30], disciplina[30], nascimento[11];
    int matricula, periodo; 
    float nota1, nota2, media = 0, notaFinal, mediaFinal;

    //Solicitação dos dados do aluno
    scanf("%s", nome);   
    scanf("%s", nascimento);   
    scanf("%d", &matricula); 
    scanf("%s", curso);    
    scanf("%d", &periodo);   
    scanf("%s", disciplina);
    scanf("%f", &nota1);
    scanf("%f", &nota2);

    //Processamento - Calculo da media da nota na disciplina desejada
    media = (nota1 + nota2)/2;
    
    //Saída - Mostrando os dados do usuario e media das notas dele na materia
    printf("\nNome: %s\n Data de Nascimento: %s\n Matricula: %d\n Curso: %s\n Periodo: %d\n Disciplina: %s\n Primeira Nota: %.2f\n Segunda Nota: %.2f\n Media na disciplina: %.2f\n\n",
    nome, nascimento, matricula, curso, periodo, disciplina, nota1, nota2, media);
    
    if (media < 7) {
        printf("Aluno de Prova de Final!\n");
        printf("\nDigite a nota da Prova Final: ");
        scanf("%f", &notaFinal);
        mediaFinal = (media + notaFinal)/2;
        printf ("Media Final: %.2f", mediaFinal);
        if (mediaFinal < 5) {
            printf("\nAluno Reprovado por nota!\n\n");
        }
        if (mediaFinal >= 5) {
            printf("\nAluno Aprovado com AF!\n\n");
        }
    }

    if (media >= 7){
        printf("Aluno Aprovado!!\n\n");
        mediaFinal = media;
    }

    //Encerramento
    getchar();
    return 0;
}
