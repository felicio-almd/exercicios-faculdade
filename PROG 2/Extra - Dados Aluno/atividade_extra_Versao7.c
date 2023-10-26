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
ou acima da m�dia da turma.

Vers�o 7.0. Respons�vel: Felicio Almeida
Modifica��o: Gerar uma matriz de m�dias de um grupo de alunos em um conjunto de disciplinas
*/

/*IMPORTA��O DE BIBLIOTECAS*/
#include <stdio.h>
#include <string.h>


typedef struct aluno{
    char nome[60], curso[20], matricula[10], disciplina[20], resposta;
    int dd_nasc, mm_nasc, a_nasc, periodo, i, cont = 0, ab_media = 0, ac_media = 0, ig_media = 0;
} tAluno;


/*CORPO PRINCIPAL*/
int main(){
    /*DECLARA��O DE VARI�VEIS*/
    char nome[60], curso[20], matricula[10], disciplina[20], resposta;
    int dd_nasc, mm_nasc, a_nasc, periodo, i, cont = 0, ab_media = 0, ac_media = 0, ig_media = 0;
    float nota_1, nota_2, md_parcial, notaProvaFinal, mdFinal, mdf_alunos[25], md_turma = 0;


    do {
        /*SOLICITA��O DE ENTRADAS:
         -1: Solicitar informa��es do aluno */
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
         -1. C�lculo da m�dia parcial*/
            md_parcial=(nota_1+nota_2)/2;
         /*
         -2. Se m�dia parcial do aluno <7 solicitar nota da prova final*/
         if(md_parcial<7){
            printf("\nInforme nota da avaliacao final: ");
            scanf("%f",&notaProvaFinal);
            setbuf(stdin,NULL);//Limpeza de buffer;

            /*2.1. C�lculo m�dia  final do aluno*/
                mdFinal=(md_parcial+notaProvaFinal)/2;
         }

         /*Preenchimento do vetor mdf_alunos com as notas finais dos alunos*/
         if (md_parcial < 7){
            mdf_alunos[cont] = mdFinal;
         }
         else{
            mdf_alunos[cont] = md_parcial;
         }

         /*SA�DA DE DADOS:
         1. EXIBIR INFORMA��ES ALUNO*/
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

        /*Caso aluno esteja reprovado, exibir mensagem de reprova��o, caso contr�rio exibir aprova��o;*/
        if(md_parcial<7){
        /*2. Exibir m�dia final do aluno*/
            printf("\nMedia Final: %.2f",mdFinal);
            setbuf(stdin,NULL);//Limpeza de buffer;

        /*3. Se aluno com m�dia final < 5 exibir mensagem de reprova��o,
             caso contr�rio exibir aprova��o*/
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

    /*Calculo da m�dia da turma*/
    for (i = 0; i < cont; i++){
        md_turma += mdf_alunos[i];
    }
    md_turma = md_turma / cont;

    /*Loop para verificar a quantidade de alunos acima, abaixo e na m�dia da turma*/
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
    /*SA�DA DE DADOS
    4. Resultados em rela��o a turma*/
    printf("\n---RESULTADOS EM RELCAO A TURMA---");
    printf("\nQuantidade de alunos acima da media: %d\n", ac_media);
    printf("Quantidade de alunos abaixo da media: %d\n", ab_media);
    printf("Quantidade de alunos na media: %d\n", ig_media);

     /*FINALIZA��O*/

     getchar();
     return 0;
}
