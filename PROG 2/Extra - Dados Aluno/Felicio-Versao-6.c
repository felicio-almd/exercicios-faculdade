/* Nome: Lucas Stm.
    Versão: 1.1 */

/* Nome: Matheus Pariz
    Versão: 1.2 */

/* Nome: Paulinelle Junior
    Versão: 1.3 */

/* Nome: João Lucas Justino
    Versão: 1.4 */

/* Nome: Kaio Ribeiro Martins Barbosa
    Versão: 1.5 - 1.5.2 */

/* Nome: Felicio Rodney Almeida Rocha
    Versão: 1.6 */


//Importação de bibliotecas

#include <stdio.h>
#include <string.h>

/* Declara��o de constante*/
#define NOTAS 25

//Função principal

int main() {
    //Inicialização de valores na declaração
    int periodo, matricula, dia_nas, mes_nas, ano_nas;
    float nota1, nota2, notaf, mediaf;
    char curso[21], disciplina[21], nome[50];
    int continua; // Variável para controlar se o usuário deseja continuar
    
    int j = 0;
    int i = 0;
    float soma_notas = 0.0; // Soma das notas de todos os alunos
    float lista_notas[NOTAS]; //array das notas
    int total_alunos = 0;   // Total de alunos
    float media_geral = 0.0; // Média geral da turma
    int acima_media = 0;    // Contador para alunos com média acima da média geral da turma
    int igual_media = 0;    // Contador para alunos com média igual à média geral da turma
    int abaixo_media = 0;   // Contador para alunos com média abaixo da média geral da turma
    

    // printf("Nome: %s\n", nome);
    // printf("Data de nascimento: %d/%d/%d\n", dia_nas, mes_nas, ano_nas);
    // printf("Curso: %s\n", curso);
    // printf("Matricula: %d\n", matricula);
    // printf("Disciplina: %s\n", disciplina);
    // printf("Periodo: %d\n", periodo);
    // printf("1 - nota: %.2f\n", nota1);
    // printf("2 - nota: %.2f\n", nota2);
    
    // // (5.1)
    // for (i = 0; i < 25; i++) {

    // printf("2 - nota: %.2f\n", nota2);
    // }

    // if (mediaf < 7) {
    //     printf("Digite a nota final: \n");
    //     scanf("%f", notaf);

    //     mediaf = (mediaf + notaf) / 2;
    //     printf("Media final: %.2f", mediaf);

    //     if (mediaf > 5) {
    //         printf("Aprovado por prova final\n");
    //     }

    //     else {
    //         printf("Aluno reprovado\n");
    //     }
    // } 
    
    
    // Versão 6

    do {

        if (total_alunos > 25){
            printf("Quantidade maxima de alunos alcancada! ");
            break;
        }

        printf("Digite seu nome: ");
        setbuf(stdin, 0);
        gets(nome);
        printf("Digite seu curso: ");
        setbuf(stdin, 0);
        gets(curso);
        printf("Digite sua disciplina: ");
        setbuf(stdin, 0);
        gets(disciplina);
        printf("Digite sua matricula: ");
        scanf("%d", &matricula);
        printf("Digite seu periodo: ");
        scanf("%d", &periodo);
        printf("Digite seu dia de nascimento: ");
        scanf("%d", &dia_nas);
        printf("Digite seu mes de nascimento: ");
        scanf("%d", &mes_nas);
        printf("Digite seu ano de nascimento: ");
        scanf("%d", &ano_nas);
        printf("Digite a primeira nota: ");
        scanf("%f", &nota1);
        printf("Digite a segunda nota: ");
        scanf("%f", &nota2);
        printf("\nCadastro concluido\n\n");

        //Printando informações do usuário

        printf("Nome: %s\n", nome);
        printf("Data de nascimento: %d/%d/%d\n", dia_nas, mes_nas, ano_nas);
        printf("Curso: %s\n", curso);
        printf("Matricula: %d\n", matricula);
        printf("Disciplina: %s\n", disciplina);
        printf("Periodo: %d\n", periodo);
        printf("1 - nota: %.2f\n", nota1);
        printf("2 - nota: %.2f\n", nota2);

        if (mediaf < 7) {
            printf("Digite a nota final: \n");
            scanf("%f", notaf);

            mediaf = (mediaf + notaf) / 2;
            printf("Media final: %.2f", mediaf);

            if (mediaf > 5) {
                printf("Aprovado por prova final\n");
            }

            else {
                printf("Aluno reprovado\n");
            }
        }

        total_alunos++;
    
        printf("\nDeseja registrar mais um aluno? (1 para Sim / 0 para Nao): ");
        scanf("%d", &continua);
    } while (continua);


    for (i = 0; i < total_alunos; i++){ //somar cada elemento do array
        soma_notas = soma_notas + lista_notas[i];
    }

    media_geral = soma_notas/total_alunos;

    for(j = 0;j < total_alunos; j++) {//Verificar quem esta abaixo, igual ou acima da media da turma

        printf("Lista: %f \n", lista_notas[j]);
        if  (lista_notas[j] < media_geral){
            abaixo_media ++;
        }
        if  (lista_notas[j] == media_geral){
            igual_media ++;
        }
        if  (lista_notas[j] > media_geral){
            acima_media ++;
        }
    }


    printf("\n\nMedia da Turma: %f;\nQuantidade de alunos abaixo da media da turma: %d;\nQuantidade de alunos acima da media da turma: %d;\nQuantidade de alunos com a nota igual a media da turma: %d;\n", media_geral, abaixo_media, acima_media, igual_media);


    getchar();
    return 0;
}
