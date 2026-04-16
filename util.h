#ifndef UTIL_H
#define UTIL_H

#include "alunos.h"
#include "professor.h"


void remover_linha(char *str);
void limparBuffer(void);
void listarPessoasPorLetras(Aluno alunos[], int qtdAlunos, Professor professores[], int qtdProf, char letras[]);
void listarAniversariantesDoMes(Aluno alunos[], int qtdAlunos, Professor professores[], int qtdProf);
int validarCPF(const char *cpf);




#endif