// Versão 1: Responsavel: João Paulo
// Versão 2: Kaio Ribeiro Martis Barbosa
// Versão 3: João Lucas
// Versão 4: Paulinelle Junior
// Versão 5.1: Felicio Almeida (loop 25 alunos)

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
    float nota_f, media, media_final;
    int aluno;
    
    for (aluno = 1; aluno <= 25; aluno++) {

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

        if (media > 7) {
            printf("\nAprovado!");
        }
        else {
            printf("\nDigite a nota da prova final: ");
            scanf("%f", &nota_f);
            media_final = (media + nota_f)/2;
            // imprime se o aluno foi aprovado
            if(media_final >= 5) {
                printf("Aprovado AF.");
            }
            else { // caso nao aprovado
                printf("Reprovado.\n\n");
            } 
        }
    }

    getchar();
    return 0;
}