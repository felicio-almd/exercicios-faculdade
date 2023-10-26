/*CABE�ALHO
Arquivo: infoaluno.c
Objetivo:Coletar informa��es aluno.
Vers�o 1.0. Respons�vel: Matheus Paris.

Vers�o 2.0. Respons�vel: Lucas S. T. M.
Modifica��o: Solicita��o de nota de p1 e p2 e c�lculo de m�dia parcial.

Vers�o 3.0. Respons�vel: Jos� Parente.
Modifica��o: C�lculo de m�dia final.

Vers�o 4.0. Respons�vel: Camila Camata.
Modifica��o: Exibir se aluno est� ou n�o aprovado.

Vers�o 5.1. Respons�vel: Antonella Mota
Modifica��o: Loop com 25 alunos.

Vers�o 6.0. Respons�vel: Jo�o Lucas
Modifica��o: Contagem dos alunos que ficaram abaixo
ou acima da m�dia da turma.*/

/* Vers�o 7.0. Respons�vel: Felicio Almeida
Modifica��o: a partir da 5.2 gerar uma matriz de médias de um grupo de alunos 
em um conjunto de disciplinas.*/


/*IMPORTA��O DE BIBLIOTECAS*/
#include <stdio.h>
#include <string.h>

#define TOTAL_ALUNOS 25
#define TOTAL_DISCIPLINAS 5

/*CORPO PRINCIPAL*/
int main(){
    /*DECLARA��O DE VARI�VEIS*/
    char nome[TOTAL_ALUNOS][60], curso[TOTAL_ALUNOS][20], matricula[TOTAL_ALUNOS][10], disciplina[TOTAL_DISCIPLINAS][20];
    int dd_nasc[TOTAL_ALUNOS], mm_nasc[TOTAL_ALUNOS], a_nasc[TOTAL_ALUNOS], periodo[TOTAL_ALUNOS], i, j, num_alunos, num_disciplinas;
    float notas[TOTAL_ALUNOS][TOTAL_DISCIPLINAS][2], md_parcial[TOTAL_ALUNOS][TOTAL_DISCIPLINAS], notaProvaFinal[TOTAL_ALUNOS][TOTAL_DISCIPLINAS], mdFinal[TOTAL_ALUNOS][TOTAL_DISCIPLINAS];
    float media_disciplina[TOTAL_DISCIPLINAS] = {0.0};
    float media_aluno[TOTAL_ALUNOS] = {0.0};

    /* Solicitar número de alunos e número de disciplinas */
    printf("Informe o numero de alunos (ate 25): ");
    scanf("%d", &num_alunos);
    setbuf(stdin, NULL); // Limpeza de buffer;
    printf("Informe o numero de disciplinas (ate 5): ");
    scanf("%d", &num_disciplinas);
    setbuf(stdin, NULL); // Limpeza de buffer;

    /* LOOP PARA CADA ALUNO */
    for (i = 0; i < num_alunos; i++) {
        /* Solicitação de entradas para cada aluno e disciplina */
        for (j = 0; j < num_disciplinas; j++) {
         /*Solicitar informa��es do aluno */
         printf("\n----- SOLICITACAO DE DADOS PARA ALUNO %d, DISCIPLINA %d -----\n", i + 1, j + 1);
            printf("\nDigite seu nome: ");
            gets(nome[i]);
            setbuf(stdin, NULL); // Limpeza de buffer;
            printf("\nInforme sua data de nascimento. Formato -> dd mm aaaa: ");
            scanf("%d %d %d", &dd_nasc[i], &mm_nasc[i], &a_nasc[i]);
            printf("\nInforme sua matricula: ");
            gets(matricula[i]);
            setbuf(stdin, NULL); // Limpeza de buffer;
            printf("\nInforme seu curso: ");
            gets(curso[i]);
            setbuf(stdin, NULL); // Limpeza de buffer;
            printf("\nInforme periodo: ");
            scanf("%d", &periodo[i]);
            printf("\nInforme nome da disciplina: ");
            gets(disciplina[j]);
            setbuf(stdin, NULL); // Limpeza de buffer;
            printf("\nDigite nota da primeira avaliacao: ");
            scanf("%f", &notas[i][j][0]);
            printf("\nDigite nota da segunda avaliacao: ");
            scanf("%f", &notas[i][j][1]);
            setbuf(stdin, NULL); // Limpeza de buffer;

            /* Cálculo da média parcial para a disciplina */
            md_parcial[i][j] = (notas[i][j][0] + notas[i][j][1]) / 2;

            /* Se média parcial do aluno na disciplina < 7, solicitar nota da prova final */
            if (md_parcial[i][j] < 7) {
                printf("\nInforme nota da avaliacao final: ");
                scanf("%f", &notaProvaFinal[i][j]);
                setbuf(stdin, NULL); // Limpeza de buffer;

                /* Cálculo média final do aluno na disciplina */
                mdFinal[i][j] = (md_parcial[i][j] + notaProvaFinal[i][j]) / 2;
            }
        }
    }
    
    /*PROCESSAMENTO:*/

    /* Cálculo das médias da turma em cada disciplina */
    for (j = 0; j < num_disciplinas; j++) {
        for (i = 0; i < num_alunos; i++) {
            media_disciplina[j] += md_parcial[i][j];
            media_aluno[i] += md_parcial[i][j];
        }
        media_disciplina[j] /= num_alunos;
    }

    /* Cálculo dos coeficientes de cada aluno no curso */
    for (i = 0; i < num_alunos; i++) {
        media_aluno[i] /= num_disciplinas;
    }

    
    /*SA�DA DE DADOS
    4. Resultados em rela��o a turma*/
    /* SAÍDA DE DADOS */
    for (i = 0; i < num_alunos; i++) {
        printf("\n------ INFORMACOES DO ALUNO %d ------\n", i + 1);
        printf("\nNome: %s.", nome[i]);
        printf("\nData de Nascimento: %d/ %d/ %d.", dd_nasc[i], mm_nasc[i], a_nasc[i]);
        printf("\nCurso: %s.", curso[i]);
        printf("\nPeriodo: %d.", periodo[i]);
        printf("\n----- RESULTADO ------");
        for (j = 0; j < num_disciplinas; j++) {
            printf("\nDisciplina %s:", disciplina[j]);
            printf("\nNota da primeira avaliacao: %.2f", notas[i][j][0]);
            printf("\nNota da segunda avaliacao: %.2f", notas[i][j][1]);
            printf("\nMedia Parcial: %.2f", md_parcial[i][j]);

            if (md_parcial[i][j] < 7) {
                printf("\nMedia Final: %.2f", mdFinal[i][j]);

                if (mdFinal[i][j] < 5) {
                    printf("\nAluno reprovado por nota.\n");
                } else {
                    printf("\nAluno aprovado com AF.\n");
                }
            } else {
                printf("\nAluno aprovado.\n");
            }
        }
        printf("Coeficiente no curso: %.2f\n", media_aluno[i]);
    }

    /* Médias da turma em cada disciplina */
    for (j = 0; j < num_disciplinas; j++) {
        printf("\nMedia da turma na disciplina %s: %.2f", disciplina[j], media_disciplina[j]);
    }

    /*FINALIZA��O*/
     getchar();
     return 0;
}
