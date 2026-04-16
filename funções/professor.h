#ifndef PROFESSOR_H
#define PROFESSOR_H

#include <stdio.h>
#include "data.h"

#define TAM_PROFESSOR 3

typedef struct{
    int id;
    char nome[50];
    char sexo;
    char cpf[20];
    Data data_nascimento;
} Professor;

void adicionarProfessor(Professor professores[], int *qtdProf, int *id_professor);
void listarProfessores(Professor professores[], int qtdProf);
void listarProfessoresPorSexo(Professor professores[], int qtdProf, char sexo);
void listarProfessoresPorDataNascimento(Professor professores[], int qtdProf);
void listarProfessoresPorAlfabeto(Professor professores[], int qtdProf);
void atualizarProfessor(Professor professores[], int qtdProf, int id);
void excluirProfessor(Professor professores[], int *qtdProf, int id); 
int buscarProfessorPorId(Professor professores[], int qtdProf, int id);

#endif