#ifndef DISCIPLINA_H
#define DISCIPLINA_H

#include "professor.h"
#include "alunos.h"

#define TAM_MATERIA 3
#define MAX_ALUNOS_DISC 40

typedef struct {
    int cod_materia;
    char nome[50];
    int semestre;
    int professor_id;
    int alunos[MAX_ALUNOS_DISC];
    int qtdAlunos;
} Disciplina;

void adicionarDisciplina(Disciplina disciplinas[], int *qtdDisc, int *id_disciplina, Professor professores[], int qtdProf);
void atualizarDisciplina(Disciplina disciplinas[], int qtdDisc, int codigo);
void listarDisciplinas(Disciplina disciplinas[], int qtdDisc,  Professor professores[], int qtdProf);

int buscarDisciplinaPorCodigo(Disciplina disciplinas[], int qtdDisc, int codigo);

void atribuirAlunoDisciplina(Disciplina disciplinas[], int qtdDisc,  Aluno alunos[], int qtdAlunos);
void excluirDisciplina(Disciplina disciplinas[], int *qtdDisc, int codigo);
void listarUmaDisciplinaEspecifica(Disciplina disciplinas[], int qtdDisc, Professor professores[], int qtdProf,Aluno alunos[], int qtdAlunos, int codigo);
void listarDisciplinascom40Alunos(Disciplina disciplinas[], int qtdDisc, Professor professores[], int qtdProf, Aluno alunos[], int qtdAlunos);
#endif