/*CABEÇALHO
Arquivo: infoaluno.c
Objetivo:Coletar informações aluno.
Versão 1.0. Responsável: Matheus Paris.

Versão 2.0. Responsável: Lucas S. T. M.
Modificação: Solicitação de nota de p1 e p2 e cálculo de média parcial.

Versão 3.0. Responsável: José Parente.
Modificação: Cálculo de média final.

Versão 4.0. Responsável: Camila Camata.
Modificação: Exibir se aluno está ou não aprovado.

Versão 5.1. Responsável: Antonella Mota
Modificação: Loop com 25 alunos.

Versão 6.0. Responsável: João Lucas
Modificação: Contagem dos alunos que ficaram abaixo
ou acima da média da turma.

Versão 7.0. Responsável: Felicio Almeida
Modificação: Gerar uma matriz de médias de um grupo de alunos em um conjunto de disciplinas
*/

/*IMPORTAÇÃO DE BIBLIOTECAS*/
#include <stdio.h>
#include <string.h>


typedef struct aluno{
    char nome[60], curso[20], matricula[10], disciplina[20], resposta;
    int dd_nasc, mm_nasc, a_nasc, periodo, i, cont = 0, ab_media = 0, ac_media = 0, ig_media = 0;
} tAluno;


/*CORPO PRINCIPAL*/
int main(){
    /*DECLARAÇÃO DE VARIÁVEIS*/
    char nome[60], curso[20], matricula[10], disciplina[20], resposta;
    int dd_nasc, mm_nasc, a_nasc, periodo, i, cont = 0, ab_media = 0, ac_media = 0, ig_media = 0;
    float nota_1, nota_2, md_parcial, notaProvaFinal, mdFinal, mdf_alunos[25], md_turma = 0;


    do {
        /*SOLICITAÇÃO DE ENTRADAS:
         -1: Solicitar informações do aluno */
         printf("\n-----SOLICITACAO DE DADOS------\n");
         printf("\nDigite seu nome: ");
         gets(nome);
         setbuf(stdin,NULL); //Limpeza de buffer;

         printf("\nInforme sua data de nascimento. Formato -> dd mm aaaa: ");
         scanf("%d %d %d",&dd_nasc,&mm_nasc,&a_nasc);
         setbuf(stdin,NULL); //Limpeza de buffer;

         printf("\nInforme sua matricula: ");
         gets(matricula);

         printf("\nInforme seu curso: ");
         gets(curso);
         setbuf(stdin,NULL); //Limpeza de buffer;

         printf("\nInforme periodo: ");
         scanf("%d",&periodo);
         setbuf(stdin,NULL);//Limpeza de buffer;

         printf("\nDeseja verificar qual disciplina: ");
         gets(disciplina);
         setbuf(stdin,NULL);//Limpeza de buffer;

         printf("\nDigite nota da primeira avaliacao: ");
         scanf("%f",&nota_1);

         printf("\nDigite nota da segunda avaliacao: ");
         scanf("%f",&nota_2);
         setbuf(stdin,NULL);//Limpeza de buffer;

         /*PROCESSAMENTO:
         -1. Cálculo da média parcial*/
            md_parcial=(nota_1+nota_2)/2;
         /*
         -2. Se média parcial do aluno <7 solicitar nota da prova final*/
         if(md_parcial<7){
            printf("\nInforme nota da avaliacao final: ");
            scanf("%f",&notaProvaFinal);
            setbuf(stdin,NULL);//Limpeza de buffer;

            /*2.1. Cálculo média  final do aluno*/
                mdFinal=(md_parcial+notaProvaFinal)/2;
         }

         /*Preenchimento do vetor mdf_alunos com as notas finais dos alunos*/
         if (md_parcial < 7){
            mdf_alunos[cont] = mdFinal;
         }
         else{
            mdf_alunos[cont] = md_parcial;
         }

         /*SAÍDA DE DADOS:
         1. EXIBIR INFORMAÇÕES ALUNO*/
         printf("\n------INFORMACOES DO ALUNO------\n   ");
         printf("\nNome: %s.", nome);
         printf("\nData de Nascimento: %d/ %d/ %d.", dd_nasc, mm_nasc, a_nasc);
         printf("\nCurso: %s.",curso);
         printf("\nPeriodo: %d.",periodo);
         printf("\nDisciplina: %s.",disciplina);
         printf("\nNota da primeira avaliacao: %.2f",nota_1);
         printf("\nNota da segunda avaliacao: %.2f",nota_2);
         printf("\n----- RESULTADO ------");
         printf("\nMedia Parcial: %.2f",md_parcial);

        /*Caso aluno esteja reprovado, exibir mensagem de reprovação, caso contrário exibir aprovação;*/
        if(md_parcial<7){
        /*2. Exibir média final do aluno*/
            printf("\nMedia Final: %.2f",mdFinal);
            setbuf(stdin,NULL);//Limpeza de buffer;

        /*3. Se aluno com média final < 5 exibir mensagem de reprovação,
             caso contrário exibir aprovação*/
            if(mdFinal<5){
                printf("\nAluno reprovado por nota.\n");
            }
            else{
                printf("\nAluno aprovado com AF.\n");
            }
         }
         else{
            printf("\nAluno aprovado.\n");
         }

        printf("Voce deseja cadastrar mais um aluno? ");
        scanf("%c", &resposta);
        cont++;
    } while (resposta == 'S');

    /*Calculo da média da turma*/
    for (i = 0; i < cont; i++){
        md_turma += mdf_alunos[i];
    }
    md_turma = md_turma / cont;

    /*Loop para verificar a quantidade de alunos acima, abaixo e na média da turma*/
    /*for (i = 0; i < cont; i++){
        if(mdf_alunos[i] > md_turma){
            ac_media++;
        }
        else if(mdf_alunos[i] < md_turma){
            ab_media++;
        }
        else{
            ig_media++;
        }
    }*/
    /*SAÍDA DE DADOS
    4. Resultados em relação a turma*/
    printf("\n---RESULTADOS EM RELCAO A TURMA---");
    printf("\nQuantidade de alunos acima da media: %d\n", ac_media);
    printf("Quantidade de alunos abaixo da media: %d\n", ab_media);
    printf("Quantidade de alunos na media: %d\n", ig_media);

     /*FINALIZAÇÃO*/

     getchar();
     return 0;
}
