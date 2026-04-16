#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "professor.h"
#include "util.h"

void adicionarProfessor(Professor professores[], int *qtdProf, int *id_professor) {
    if (*qtdProf >= TAM_PROFESSOR) {
        printf("Limite de professores atingido!\n");
        return;
    }

    Professor *p = &professores[*qtdProf];

    printf("\nDigite o nome do professor:\n");
    fgets(p->nome, sizeof(p->nome), stdin);
    remover_linha(p->nome);

    printf("Data de nascimento:\n");
    printf("Dia: ");
    scanf("%d", &p->data_nascimento.dia);
    printf("Mes: ");
    scanf("%d", &p->data_nascimento.mes);
    printf("Ano: ");
    scanf("%d", &p->data_nascimento.ano);
    limparBuffer();

    printf("Sexo (M/F): ");
    scanf(" %c", &p->sexo);
    p->sexo = toupper(p->sexo);
    limparBuffer();

    do {
        printf("CPF (000.000.000-00 ou apenas numeros): ");
        fgets(p->cpf, sizeof(p->cpf), stdin);
        remover_linha(p->cpf);

        if (!validarCPF(p->cpf)) {
            printf("CPF invalido! Tente novamente.\n");
        }
    } while (!validarCPF(p->cpf));

    p->id = ++(*id_professor);
    (*qtdProf)++;

    printf("Professor cadastrado com sucesso! ID: %d\n", p->id);
}

void atualizarProfessor(Professor professores[], int qtdProf, int id) {
    int pos = buscarProfessorPorId(professores, qtdProf, id);
    if (pos == -1) {
        printf("Professor nao encontrado.\n");
        return;
    }

    Professor *p = &professores[pos];

    printf("\nDigite o novo nome do professor:\n");
    fgets(p->nome, sizeof(p->nome), stdin);
    remover_linha(p->nome);

    printf("Data de nascimento:\n");
    printf("Dia: ");
    scanf("%d", &p->data_nascimento.dia);
    printf("Mes: ");
    scanf("%d", &p->data_nascimento.mes);
    printf("Ano: ");
    scanf("%d", &p->data_nascimento.ano);
    limparBuffer();

    printf("Sexo (M/F): ");
    scanf(" %c", &p->sexo);
    p->sexo = toupper(p->sexo);
    limparBuffer();

    do {
        printf("CPF (000.000.000-00 ou apenas numeros): ");
        fgets(p->cpf, sizeof(p->cpf), stdin);
        remover_linha(p->cpf);

        if (!validarCPF(p->cpf)) {
            printf("CPF invalido! Tente novamente.\n");
        }
    } while (!validarCPF(p->cpf));

    printf("Professor atualizado com sucesso!\n");
}

void listarProfessores(Professor professores[], int qtdProf) {
    if (qtdProf == 0) {
        printf("Nenhum professor cadastrado.\n");
        return;
    }

    printf("\n#### Lista de Professores ####\n");
    for (int i = 0; i < qtdProf; i++) {
        printf("ID: %d\n", professores[i].id);
        printf("Nome: %s\n", professores[i].nome);
        printf("Sexo: %c\n", professores[i].sexo);
        printf("CPF: %s\n", professores[i].cpf);
        printf("Data de Nascimento: %02d/%02d/%04d\n",
               professores[i].data_nascimento.dia,
               professores[i].data_nascimento.mes,
               professores[i].data_nascimento.ano);
        printf("-----------------------------\n");
    }
}

void listarProfessoresPorSexo(Professor professores[], int qtdProf, char sexo) {
    printf("\n#### Professores do sexo %c ####\n", sexo);
    for (int i = 0; i < qtdProf; i++) {
        if (professores[i].sexo == sexo) {
            printf("ID: %d\n", professores[i].id);
            printf("Nome: %s\n", professores[i].nome);
            printf("CPF: %s\n", professores[i].cpf);
            printf("Data de Nascimento: %02d/%02d/%04d\n",
                   professores[i].data_nascimento.dia,
                   professores[i].data_nascimento.mes,
                   professores[i].data_nascimento.ano);
            printf("-----------------------------\n");
        }
    }
}

void listarProfessoresPorAlfabeto(Professor professores[], int qtdProf) {
    
    Professor *pprof[TAM_PROFESSOR];
    for (int i = 0; i < qtdProf; i++) {
        pprof[i] = &professores[i];
    }

    for (int i = 0; i < qtdProf - 1; i++) {
        for (int j = 0; j < qtdProf - i - 1; j++) {
            if (strcmp(pprof[j]->nome, pprof[j + 1]->nome) > 0) {
                Professor *temp = pprof[j];
                pprof[j] = pprof[j + 1];
                pprof[j + 1] = temp;
            }
        }
    }

    printf("\n#### Professores em Ordem Alfabetica ####\n");
    for (int i = 0; i < qtdProf; i++) {
        printf("ID: %d\n", pprof[i]->id);
        printf("Nome: %s\n", pprof[i]->nome);
        printf("Sexo: %c\n", pprof[i]->sexo);
        printf("CPF: %s\n", pprof[i]->cpf);
        printf("Data de Nascimento: %02d/%02d/%04d\n",
               pprof[i]->data_nascimento.dia,
               pprof[i]->data_nascimento.mes,
               pprof[i]->data_nascimento.ano);
        printf("-----------------------------\n");
    }
}

void listarProfessoresPorDataNascimento(Professor professores[], int qtdProf) {
    
    Professor *pprof[TAM_PROFESSOR];
    for (int i = 0; i < qtdProf; i++) {
        pprof[i] = &professores[i];
    }

    for (int i = 0; i < qtdProf - 1; i++) {
        for (int j = 0; j < qtdProf - i - 1; j++) {
            Data d1 = pprof[j]->data_nascimento;
            Data d2 = pprof[j + 1]->data_nascimento;

            if (d1.ano > d2.ano || 
                (d1.ano == d2.ano && d1.mes > d2.mes) || 
                (d1.ano == d2.ano && d1.mes == d2.mes && d1.dia > d2.dia)) {
                Professor *temp = pprof[j];
                pprof[j] = pprof[j + 1];
                pprof[j + 1] = temp;
            }
        }
    }

    printf("\n#### Professores por Data de Nascimento ####\n");
    for (int i = 0; i < qtdProf; i++) {
        printf("ID: %d\n", pprof[i]->id);
        printf("Nome: %s\n", pprof[i]->nome);
        printf("Sexo: %c\n", pprof[i]->sexo);
        printf("CPF: %s\n", pprof[i]->cpf);
        printf("Data de Nascimento: %02d/%02d/%04d\n",
               pprof[i]->data_nascimento.dia,
               pprof[i]->data_nascimento.mes,
               pprof[i]->data_nascimento.ano);
        printf("-----------------------------\n");
    }
}

void excluirProfessor(Professor professores[], int *qtdProf, int id) {
    int pos = buscarProfessorPorId(professores, *qtdProf, id);
    if (pos == -1) {
        printf("Professor nao encontrado.\n");
        return;
    }

    for (int i = pos; i < (*qtdProf) - 1; i++) {
        professores[i] = professores[i + 1];
    }
    (*qtdProf)--;
    printf("Professor excluido com sucesso!\n");
}

int buscarProfessorPorId(Professor professores[], int qtdProf, int id) {
    for (int i = 0; i < qtdProf; i++) {
        if (professores[i].id == id) {
            return i; // retorna a posição do professor
        }
    }
    return -1; // não encontrado
}