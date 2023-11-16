/*  CABEçALHO
    Arquivo: loop25Alunos.c
    Objetivo: Exibir o registro de matr�cula do estudante
    Versão 1.0: Fel�cio Rodney Almeida Rocha
    Versão 2.0: Paulo Augusto
    Versão 3.0: Paulo Augusto
    Versão 4.0: Antonella Mota
    Versão 5.2: Camila Camata
    Versão 6.0: José Parente | Modificação = Contar quantidade de alunos acima, abaixo ou na m�dia.
    Versão 7.0: João Lucas
    Versão 8.0: Felicio Almeida
*/

/* Importação das bibliotecas */
#include <stdio.h>
#include <string.h>

/* Declaração de constantes */
#define TAM_ALUNOS 25
#define TAM_DISCIPLINAS 5

typedef struct {
    char* nome;
    int dia_nascimento, mes_nascimento, ano_nascimento;
    char* curso;
    char* matricula;
    int periodo;
    float** notas;  // notas[disciplina][0] -> nota1, notas[disciplina][1] -> nota2
    float* media_final;
    char** situacao; // Situação por disciplina
} Aluno;

typedef struct {
    char nome[30];
    float media_turma;
} Disciplina;

void liberarMemoriaAluno(Aluno* aluno) {
    free(aluno->nome);
    free(aluno->curso);
    free(aluno->matricula);
    
    for (int i = 0; i < TAM_DISCIPLINAS; i++) {
        free(aluno->notas[i]);
        free(aluno->situacao[i]);
    }

    free(aluno->notas);
    free(aluno->media_final);
    free(aluno->situacao);
}

// Função para inicializar um aluno
void inicializarAluno(Aluno* aluno) {
    aluno->nome = (char*)malloc(70 * sizeof(char));
    aluno->curso = (char*)malloc(30 * sizeof(char));
    aluno->matricula = (char*)malloc(20 * sizeof(char));

    aluno->notas = (float**)malloc(TAM_DISCIPLINAS * sizeof(float*));
    aluno->situacao = (char**)malloc(TAM_DISCIPLINAS * sizeof(char*));

    for (int i = 0; i < TAM_DISCIPLINAS; i++) {
        aluno->notas[i] = (float*)malloc(2 * sizeof(float));
        aluno->situacao[i] = (char*)malloc(20 * sizeof(char));
    }

    aluno->media_final = (float*)malloc(TAM_DISCIPLINAS * sizeof(float));
}

void calcularMediaTurma(Aluno alunos[], Disciplina disciplinas[]) {
    /*Seção de variaveis*/
    int i, j;
    float media_disciplina = 0;
    
    // Loop para cada disciplina
    for (j = 0; j < TAM_DISCIPLINAS; j++) {
        
        // Calcular a média da turma na disciplina
        for (i = 0; i < TAM_ALUNOS; i++) {
            media_disciplina += alunos[i].media_final[j];
        }

        disciplinas[j].media_turma = media_disciplina / TAM_ALUNOS;

        // Identificar a situação de cada aluno em relação à média da turma
        for (i = 0; i < TAM_ALUNOS; i++) {
            if (alunos[i].media_final[j] >= disciplinas[j].media_turma) {
                strcpy(alunos[i].situacao[j], "Acima da média");
            } else {
                strcpy(alunos[i].situacao[j], "Abaixo da média");
            }
        }
    }
}

/* Função para exibir o registro de um aluno específico */
void exibirRegistroAluno(Aluno aluno, Disciplina disciplinas[]) {
    printf("\n------------ REGISTRO DO ALUNO ------------\n");
    printf("Nome: %s", aluno.nome);
    printf("Data de Nascimento: %d/%d/%d\n", aluno.dia_nascimento, aluno.mes_nascimento, aluno.ano_nascimento);
    printf("Curso: %s", aluno.curso);
    printf("Matrícula: %s", aluno.matricula);
    printf("Período: %d\n", aluno.periodo);

    printf("\n------------- NOTAS E SITUAÇÃO -------------\n");
    for (int j = 0; j < TAM_DISCIPLINAS; j++) {
        printf("Disciplina %d - %s\n", j + 1, disciplinas[j].nome);
        printf("Nota 1: %.2f\n", aluno.notas[j][0]);
        printf("Nota 2: %.2f\n", aluno.notas[j][1]);
        printf("Média Final: %.2f\n", aluno.media_final[j]);
        printf("Situação: %s\n", aluno.situacao[j]);
        printf("--------------------------------------------\n");
    }
}

/* Função para mostrar a situação do aluno em cada disciplina */
void mostrarSituacaoAluno(Aluno alunos[], int indiceAluno, Disciplina disciplinas[]) {
    printf("\n-------- SITUAÇÃO DO ALUNO --------\n");
    printf("Nome do Aluno: %s", alunos[indiceAluno].nome);
    
    for (int j = 0; j < TAM_DISCIPLINAS; j++) {
        printf("Disciplina %d - %s: %s\n", j + 1, disciplinas[j].nome, alunos[indiceAluno].situacao[j]);
    }

    printf("-----------------------------------\n");
}

/* Função principal */
int main(){

    /* Declaração de vari�veis */
    Aluno alunos[TAM_ALUNOS];
    Disciplina disciplinas[TAM_DISCIPLINAS];
    int i, j;

    // Inicializar disciplinas
    strcpy(disciplinas[0].nome, "Disciplina1");
    strcpy(disciplinas[1].nome, "Disciplina2");
    strcpy(disciplinas[2].nome, "Disciplina3");
    strcpy(disciplinas[3].nome, "Disciplina4");
    strcpy(disciplinas[4].nome, "Disciplina5");

    
    // Loop para cada aluno
    for (i = 0; i < TAM_ALUNOS; i++) {
        
        // Inicializar aluno
        inicializarAluno(&alunos[i]);

        // Solicitar entradas para cada aluno       
        printf("\nDigite o nome do aluno: ");
        setbuf(stdin, 0);
        fgets(alunos[i].nome, 70, stdin);

        printf("\nDigite a data de nascimento. Formato: dd mm aaaa: ");
        scanf("%d %d %d", &alunos[i].dia_nascimento, &alunos[i].mes_nascimento, &alunos[i].ano_nascimento);

        printf("\nDigite o curso do aluno: ");
        setbuf(stdin, 0);
        fgets(alunos[i].curso, 30, stdin);

        printf("\nDigite a matricula: ");
        setbuf(stdin, 0);
        fgets(alunos[i].matricula, 20, stdin);

        printf("\nDigite o periodo em que se encontra: ");
        scanf("%d", &alunos[i].periodo);

        // Loop para cada disciplina
        for (int j = 0; j < TAM_DISCIPLINAS; j++) {
            printf("\nDigite nota 1 para %s: ", disciplinas[j].nome);
            scanf("%f", &alunos[i].notas[j][0]);

            printf("\nDigite nota 2 para %s: ", disciplinas[j].nome);
            scanf("%f", &alunos[i].notas[j][1]);

            // Processamento - Cálculo da média das notas
            alunos[i].media_final[j] = (alunos[i].notas[j][0] + alunos[i].notas[j][1]) / 2;

            // Situação do aluno em cada disciplina
            if (alunos[i].media_final[j] >= 7) {
                strcpy(alunos[i].situacao[j], "Aprovado");
            } else {
                printf("\nDigite a nota final para %s: ", disciplinas[j].nome);
                scanf("%f", &alunos[i].media_final[j]);

                if (alunos[i].media_final[j] >= 5) {
                    strcpy(alunos[i].situacao[j], "Aprovado com AF");
                } else {
                    strcpy(alunos[i].situacao[j], "Reprovado");
                }
            }
        }
    }

    // Calcular a média da turma em cada disciplina e identificar a situação de cada aluno em relação à média da turma
    calcularMediaTurma(alunos, disciplinas);

    // Imprimir resultados
    printf("\n-------------COEFICIENTES--------------\n");
    for (i = 0; i < TAM_ALUNOS; i++) {
        float coeficiente = 0;
        for (j = 0; j < TAM_DISCIPLINAS; j++) {
            coeficiente += alunos[i].media_final[j] * 0.1; // Peso de cada disciplina
        }
        printf("Coeficiente do aluno %d: %.2f\n", i + 1, coeficiente);
    }

    printf("\n------------MEDIAS DA TURMA------------\n");
    for (j = 0; j < TAM_DISCIPLINAS; j++) {
        printf("Media da turma na disciplina %s: %.2f\n", disciplinas[j].nome, disciplinas[j].media_turma);
    }

    // Exemplo de uso das novas funções
    int indiceAlunoExibir = 0; // Índice do aluno a ser exibido
    exibirRegistroAluno(alunos[indiceAlunoExibir], disciplinas);

    int indiceAlunoMostrarSituacao = 1; // Índice do aluno para mostrar situação
    mostrarSituacaoAluno(alunos, indiceAlunoMostrarSituacao, disciplinas);

    // Liberação de memória alocada para cada aluno
    for (i = 0; i < TAM_ALUNOS; i++) {
        liberarMemoriaAluno(&alunos[i]);
    }

    /* Fim do programa */
    getchar();
    return 0;

}
