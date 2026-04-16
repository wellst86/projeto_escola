#include "alunos.h"
#include "util.h"
#include <string.h>
#include <ctype.h>



void adicionarAluno(Aluno alunos[], int *qtdAlunos, int *id_aluno) {
    if (*qtdAlunos >= TAM_ALUNOS) {
        printf("Limite de alunos atingido!\n");
        return;
    }

    Aluno *a = &alunos[*qtdAlunos];

    printf("\nDigite o nome do aluno:\n");
    fgets(a->nome, sizeof(a->nome), stdin);
    remover_linha(a->nome);

    printf("Data de nascimento:\n");
    printf("Dia: "); scanf("%d", &a->data_nascimento.dia);
    printf("Mes: "); scanf("%d", &a->data_nascimento.mes);
    printf("Ano: "); scanf("%d", &a->data_nascimento.ano);
    limparBuffer();

    printf("Sexo (M/F): ");
    scanf(" %c", &a->sexo);
    a->sexo = toupper(a->sexo);
    limparBuffer();

    do {
        printf("CPF (000.000.000-00 ou apenas numeros): ");
        fgets(a->cpf, sizeof(a->cpf), stdin);
        remover_linha(a->cpf);

        if (!validarCPF(a->cpf))
            printf("CPF invalido! Tente novamente.\n");
    } while (!validarCPF(a->cpf));

    a->matricula = ++(*id_aluno);
    (*qtdAlunos)++;

    printf("Aluno cadastrado com sucesso! Matricula: %d\n", a->matricula);
}

void atualizarAluno(Aluno alunos[], int qtdAlunos, int matricula) {
    int pos = buscarAlunoPorMatricula(alunos, qtdAlunos, matricula);
    if (pos == -1) {
        printf("Aluno nao encontrado.\n");
        return;
    }

    Aluno *a = &alunos[pos];

    printf("\nDigite o novo nome do aluno:\n");
    fgets(a->nome, sizeof(a->nome), stdin);
    remover_linha(a->nome);

    printf("Data de nascimento:\n");
    printf("Dia: "); scanf("%d", &a->data_nascimento.dia);
    printf("Mes: "); scanf("%d", &a->data_nascimento.mes);
    printf("Ano: "); scanf("%d", &a->data_nascimento.ano);
    limparBuffer();

    printf("Sexo (M/F): ");
    scanf(" %c", &a->sexo);
    a->sexo = toupper(a->sexo);
    limparBuffer();

    do {
        printf("CPF (000.000.000-00 ou apenas numeros): ");
        fgets(a->cpf, sizeof(a->cpf), stdin);
        remover_linha(a->cpf);

        if (!validarCPF(a->cpf))
            printf("CPF invalido! Tente novamente.\n");
    } while (!validarCPF(a->cpf));

    printf("Aluno atualizado com sucesso!\n");
}

void listarAlunos(Aluno alunos[], int qtdAlunos) {
    printf("\n#### Lista de Alunos ####\n");
    for (int i = 0; i < qtdAlunos; i++) {
        printf("Nome: %s\n", alunos[i].nome);
        printf("Matricula: %d\n", alunos[i].matricula);
        printf("Sexo: %c\n", alunos[i].sexo);
        printf("Data de Nascimento: %02d/%02d/%04d\n",
               alunos[i].data_nascimento.dia,
               alunos[i].data_nascimento.mes,
               alunos[i].data_nascimento.ano);
        printf("CPF: %s\n", alunos[i].cpf);
        printf("-------------------------\n");
    }
    
}

void listarAlunosPorSexo (Aluno alunos[], int qtdAlunos, char sexo) {
    printf("\n#### Alunos do sexo %c ####\n", sexo);
    for (int i = 0; i < qtdAlunos; i++) {
        if (alunos[i].sexo == sexo) {
            printf("Nome: %s\n", alunos[i].nome);
            printf("Matricula: %d\n", alunos[i].matricula);
            printf("Data de Nascimento: %02d/%02d/%04d\n",
               alunos[i].data_nascimento.dia,
               alunos[i].data_nascimento.mes,
               alunos[i].data_nascimento.ano);
            printf("CPF: %s\n", alunos[i].cpf);
            printf("-------------------------\n");
        }
    }
}

void listarAlunosPorAlfabeto (Aluno alunos[], int qtdAlunos) {
    printf("\n#### Alunos em ordem alfabetica ####\n");
    for (int i = 0; i < qtdAlunos - 1; i++) {
        for (int j = 0; j < qtdAlunos - i - 1; j++) {
            if (strcmp(alunos[j].nome, alunos[j + 1].nome) > 0) {
                Aluno temp = alunos[j];
                alunos[j] = alunos[j + 1];
                alunos[j + 1] = temp;
            }
        }
    }
    listarAlunos(alunos, qtdAlunos);
}

void listarAlunosPorDataNascimento(Aluno alunos[], int qtdAlunos) {
    
    Aluno *palunos[TAM_ALUNOS];
    for (int i = 0; i < qtdAlunos; i++) {
        palunos[i] = &alunos[i];
    }

    for (int i = 0; i < qtdAlunos - 1; i++) {
        for (int j = 0; j < qtdAlunos - i - 1; j++) {
            Data d1 = palunos[j]->data_nascimento;
            Data d2 = palunos[j + 1]->data_nascimento;

            if (d1.ano > d2.ano || 
                (d1.ano == d2.ano && d1.mes > d2.mes) || 
                (d1.ano == d2.ano && d1.mes == d2.mes && d1.dia > d2.dia)) {
                Aluno *temp = palunos[j];
                palunos[j] = palunos[j + 1];
                palunos[j + 1] = temp;
            }
        }
    }

    printf("\n#### Alunos por Data de Nascimento ####\n");
    for (int i = 0; i < qtdAlunos; i++) {
        printf("Matricula: %d\n", palunos[i]->matricula);
        printf("Nome: %s\n", palunos[i]->nome);
        printf("Sexo: %c\n", palunos[i]->sexo);
        printf("CPF: %s\n", palunos[i]->cpf);
        printf("Data de Nascimento: %02d/%02d/%04d\n",
               palunos[i]->data_nascimento.dia,
               palunos[i]->data_nascimento.mes,
               palunos[i]->data_nascimento.ano);
        printf("-----------------------------\n");
    }
}

void excluirAluno(Aluno alunos[], int *qtdAlunos, int matricula) {
    int pos = buscarAlunoPorMatricula(alunos, *qtdAlunos, matricula);
    if (pos == -1) {
        printf("Aluno nao encontrado.\n");
        return;
    }

    for (int i = pos; i < (*qtdAlunos) - 1; i++) {
        alunos[i] = alunos[i + 1];
    }
    (*qtdAlunos)--;
    printf("Aluno excluido com sucesso!\n");
}

int buscarAlunoPorMatricula(Aluno alunos[], int qtdAlunos, int matricula) {
    for (int i = 0; i < qtdAlunos; i++) {
        if (alunos[i].matricula == matricula) {
            return i;
        }
    }
    return -1; // Não encontrado 
}