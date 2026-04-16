#include "util.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "alunos.h"
#include "professor.h"

void remover_linha(char *str) {
    str[strcspn(str, "\n")] = '\0';
}

void limparBuffer(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int validarCPF(const char *cpf) {
    int contador = 0;

    for (int i = 0; cpf[i] != '\0'; i++) {
        if (isdigit((unsigned char)cpf[i])) {
            contador++;  
        } 
        else if (cpf[i] != '.' && cpf[i] != '-') {
            return 0;    
        }
    }

    
    return (contador == 11);
}

    void listarPessoasPorLetras(Aluno alunos[], int qtdAlunos, Professor professores[], int qtdProf, char letras[]) {

    printf("\n#### Pessoas com as letras ");
    for (int i = 0; i < QTD_LETRAS; i++) { printf("%c ", letras[i]); }
    printf("no nome ####\n");

    for (int i = 0; i < qtdAlunos; i++) {
    int achou = 0;

    for (int k = 0; alunos[i].nome[k] != '\0' && !achou; k++) {
        for (int j = 0; j < QTD_LETRAS; j++) {
            if (toupper(alunos[i].nome[k]) == toupper(letras[j])) {

                printf("Aluno: %s\n", alunos[i].nome);
                printf("Matricula: %d\n", alunos[i].matricula);
                printf("Sexo: %c\n", alunos[i].sexo);
                printf("Data de Nascimento: %02d/%02d/%04d\n",
                       alunos[i].data_nascimento.dia,
                       alunos[i].data_nascimento.mes,
                       alunos[i].data_nascimento.ano);
                printf("CPF: %s\n", alunos[i].cpf);
                printf("-----------------------------\n");

                achou = 1;
                break;
            }
        }
    }
}
    for (int i = 0; i < qtdProf; i++) {
    int achou = 0;

    for (int k = 0; professores[i].nome[k] != '\0' && !achou; k++) {
        for (int j = 0; j < QTD_LETRAS; j++) {
            if (toupper(professores[i].nome[k]) == toupper(letras[j])) {

                printf("Professor: %s\n", professores[i].nome);
                printf("ID: %d\n", professores[i].id);
                printf("Sexo: %c\n", professores[i].sexo);
                printf("Data de Nascimento: %02d/%02d/%04d\n",
                       professores[i].data_nascimento.dia,
                       professores[i].data_nascimento.mes,
                       professores[i].data_nascimento.ano);
                printf("CPF: %s\n", professores[i].cpf);
                printf("-----------------------------\n");

                achou = 1;
                break;
            }
            }
        }
    }
}



    void listarAniversariantesDoMes(Aluno alunos[], int qtdAlunos, Professor professores[], int qtdProf) {
    int mes;
    printf("\nDigite o mes (1-12) para listar aniversariantes: ");
    scanf("%d", &mes);
    limparBuffer(); 
    if (mes < 1 || mes > 12) {
        printf("Mes invalido! Digite um valor entre 1 e 12.\n");
        return;
    }
    printf("\n#### Aniversariantes do mes %d ####\n", mes);
    for (int i = 0; i < qtdAlunos; i++) {
        if (alunos[i].data_nascimento.mes == mes) {
            printf("Aluno: %s - Aniversario: %02d/%02d/%04d\n", alunos[i].nome, alunos[i].data_nascimento.dia, alunos[i].data_nascimento.mes, alunos[i].data_nascimento.ano);
        }
    }
    for (int i = 0; i < qtdProf; i++) {
        if (professores[i].data_nascimento.mes == mes) {        
            printf("Professor: %s - Aniversario: %02d/%02d/%04d\n", professores[i].nome, professores[i].data_nascimento.dia, professores[i].data_nascimento.mes, professores[i].data_nascimento.ano);
        }
    }
}