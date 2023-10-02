// Versão 1: Responsavel: João Paulo
// Versão 2: Kaio Ribeiro Martis Barbosa
// Versão 3: João Lucas
// Versão 4: Paulinelle Junior
// Versão 5.1: Felicio Almeida (loop 25 alunos)
// Versão 5.2: Felicio Almeida (loop indeterminado de alunos)
// Versão 6: Felicio Almeida 

/* Importação de Bibliotecas */
#include <stdio.h>

/* Função Principal */
int main() {
    /* Declaração de Variaveis */
    char curso[50];
    int periodo;
    char disci[50];
    int matricula;
    char nome[256];
    int dd_nasc, mes_nasc, ano_nasc;
    float nota1, nota2;
    float nota_f, media;
    int continua; // Variável para controlar se o usuário deseja continuar
    
    float soma_notas = 0.0; // Soma das notas de todos os alunos
    int total_alunos = 0;   // Total de alunos
    float media_geral = 0.0; // Média geral da turma
    int acima_media = 0;    // Contador para alunos com média acima da média geral da turma
    int igual_media = 0;    // Contador para alunos com média igual à média geral da turma
    int abaixo_media = 0;   // Contador para alunos com média abaixo da média geral da turma


    do {
        /* Solicitação de dados */
        printf("Insira seu curso: ");
        scanf("%s", curso);
        printf("Insira seu periodo: ");
        scanf("%d", &periodo);
        printf("Insira sua disciplina: ");
        scanf("%s", disci);
        printf("Insira a matricula: ");
        scanf("%d", &matricula);
        printf("Insira seu nome: ");
        scanf("%s", nome);
        printf("Insira o dia do seu nascimento: ");
        scanf("%d", &dd_nasc);
        printf("Insira o mes do seu nascimento: ");
        scanf("%d", &mes_nasc);
        printf("Insira o ano do seu nascimento: ");
        scanf("%d", &ano_nasc);
        printf("Nota 1: ");
        scanf("%f", &nota1);
        printf("Nota 2: ");
        scanf("%f", &nota2);

        /* Saida de Dados */
        printf("\nNome: %s \nMatricula: %d \nCurso: %s \nDisciplina: %s \nPeriodo: %d \nData de nascimento: %d %d %d \nNota 1: %f \nNota 2: %f \n", nome, matricula, curso, disci, periodo, dd_nasc, mes_nasc, ano_nasc, nota1, nota2);

        // Media das notas //
        media = (nota1 + nota2) / 2;
        printf("\nMedia das notas: ");
        printf("%f", media);

        soma_notas += media;

        if (media > 7) {
            printf("\nAprovado!");
            acima_media++;
        }
        else {
            printf("\nDigite a nota da prova final: ");
            scanf("%f", &nota_f);
            media = ((media + nota_f)/2);
            // imprime se o aluno foi aprovado
            if(media > 5) {
                printf("Aprovado AF.");
                acima_media++;
            }
            else if (media == 5) {
                printf("Aprovado na media.");
                igual_media++;
            }
            else { // caso nao aprovado
                printf("Reprovado.\n\n");
                abaixo_media++;
            } 
        }

        total_alunos++;
    
    /* Pergunta ao usuário se deseja continuar */
        printf("\nDeseja registrar mais um aluno? (1 para Sim / 0 para Nao): ");
        scanf("%d", &continua);
    } while (continua);

    /* Cálculo da média geral da turma */
    media_geral = soma_notas / total_alunos;

    /* Saída das estatísticas da turma */
    printf("\nEstatisticas da Turma:\n");
    printf("Media geral da turma: %.2f\n", media_geral);
    printf("Alunos acima da media geral da turma: %d\n", acima_media);
    printf("Alunos com media igual a media geral da turma: %d\n", igual_media);
    printf("Alunos abaixo da media geral da turma: %d\n", abaixo_media);

    getchar();
    return 0;
}

// duvida em precisar de trabalhar com array, se sim como?