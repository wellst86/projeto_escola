#ifndef ALUNO_H
#define ALUNO_H

#include <stdio.h>
#include "data.h"

#define TAM_ALUNOS 3
#define QTD_LETRAS 3

typedef struct{
    int matricula;
    char nome[50];
    char sexo;
    char cpf[20];
    Data data_nascimento;
} Aluno;

// Protótipos das funções
void adicionarAluno(Aluno alunos[], int *qtdAlunos, int *id_aluno);
void listarAlunos(Aluno alunos[], int qtdAlunos);
void atualizarAluno(Aluno alunos[], int qtdAlunos, int matricula);
void listarAlunosPorSexo (Aluno alunos[], int qtdAlunos, char sexo);
void listarAlunosPorAlfabeto (Aluno alunos[], int qtdAlunos);
void listarAlunosPorDataNascimento (Aluno alunos[], int qtdAlunos);
void excluirAluno(Aluno alunos[], int *qtdAlunos, int matricula);
int buscarAlunoPorMatricula(Aluno alunos[], int qtdAlunos, int matricula);
#endif