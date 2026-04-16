#include <stdio.h>
#include <string.h>
#include "disciplina.h"
#include "util.h"

void adicionarDisciplina(Disciplina disciplinas[], int *qtdDisc, int *id_disciplina,
                         Professor professores[], int qtdProf) {
    if (*qtdDisc >= TAM_MATERIA) {
        printf("Limite de disciplinas atingido!\n");
        return;
    }

    Disciplina *d = &disciplinas[*qtdDisc];

    printf("\nDigite o nome da disciplina:\n");
    fgets(d->nome, sizeof(d->nome), stdin);
    remover_linha(d->nome);

    printf("Digite o semestre: ");
    scanf("%d", &d->semestre);
    limparBuffer();

    printf("Digite o ID do professor: ");
    scanf("%d", &d->professor_id);
    limparBuffer();

    if (buscarProfessorPorId(professores, qtdProf, d->professor_id) == -1) {
        printf("Professor nao encontrado! Disciplina nao cadastrada.\n");
        return;
    }

    d->cod_materia = ++(*id_disciplina);
    d->qtdAlunos = 0;
    (*qtdDisc)++;

    printf("Disciplina cadastrada com sucesso! Codigo: %d\n", d->cod_materia);
}

void atualizarDisciplina(Disciplina disciplinas[], int qtdDisc, int codigo) {
    int pos = buscarDisciplinaPorCodigo(disciplinas, qtdDisc, codigo);
    if (pos == -1) {
        printf("Disciplina nao encontrada.\n");
        return;
    }

    Disciplina *d = &disciplinas[pos];

    printf("\nDigite o novo nome da disciplina:\n");
    fgets(d->nome, sizeof(d->nome), stdin);
    remover_linha(d->nome);

    printf("Digite o novo semestre: ");
    scanf("%d", &d->semestre);
    limparBuffer();

    printf("Digite o novo ID do professor: ");
    scanf("%d", &d->professor_id);
    limparBuffer();

    printf("Disciplina atualizada com sucesso!\n");
}
void listarDisciplinas(Disciplina disciplinas[], int qtdDisc, Professor professores[], int qtdProf) {
    if (qtdDisc == 0) {
        printf("Nenhuma disciplina cadastrada.\n");
        return;
    }

    printf("\n#### Lista de Disciplinas ####\n");
    for (int i = 0; i < qtdDisc; i++) {
        int posProf = buscarProfessorPorId(professores, qtdProf, disciplinas[i].professor_id);

        printf("Codigo: %d\n", disciplinas[i].cod_materia);
        printf("Nome: %s\n", disciplinas[i].nome);
        printf("Semestre: %d\n", disciplinas[i].semestre);

        if (posProf != -1)
            printf("Professor: %s\n", professores[posProf].nome);
        else
            printf("Professor: Nao encontrado\n");

        printf("Quantidade de alunos: %d\n", disciplinas[i].qtdAlunos);
        printf("-----------------------------\n");
    }
}

int buscarDisciplinaPorCodigo(Disciplina disciplinas[], int qtdDisc, int codigo) {
    for (int i = 0; i < qtdDisc; i++) {
        if (disciplinas[i].cod_materia == codigo) {
            return i;
        }
    }
    return -1;
}

void atribuirAlunoDisciplina(Disciplina disciplinas[], int qtdDisc, Aluno alunos[], int qtdAlunos) {
    int codigo, matricula;

    printf("Digite o codigo da disciplina: ");
    scanf("%d", &codigo);
    limparBuffer();

    int posDisc = buscarDisciplinaPorCodigo(disciplinas, qtdDisc, codigo);
    if (posDisc == -1) {
        printf("Disciplina nao encontrada.\n");
        return;
    }

    printf("Digite a matricula do aluno: ");
    scanf("%d", &matricula);
    limparBuffer();

    int posAluno = buscarAlunoPorMatricula(alunos, qtdAlunos, matricula);
    if (posAluno == -1) {
        printf("Aluno nao encontrado.\n");
        return;
    }

    Disciplina *d = &disciplinas[posDisc];

    if (d->qtdAlunos >= MAX_ALUNOS_DISC) {
        printf("Limite de alunos na disciplina atingido.\n");
        return;
    }

    d->alunos[d->qtdAlunos++] = matricula;
    printf("Aluno adicionado à disciplina com sucesso!\n");
}

void listarUmaDisciplinaEspecifica(Disciplina disciplinas[], int qtdDisc, Professor professores[], int qtdProf,Aluno alunos[], int qtdAlunos, int codigo) {
    int encontrada = 0;

    for (int i = 0; i < qtdDisc; i++) {
        if (codigo == disciplinas[i].cod_materia) {
            encontrada = 1;

            printf("\n===== Disciplina =====\n");
            printf("Codigo: %d\n", disciplinas[i].cod_materia);
            printf("Nome: %s\n", disciplinas[i].nome);
            printf("Semestre: %d\n", disciplinas[i].semestre);

            int posProf = buscarProfessorPorId(professores, qtdProf, disciplinas[i].professor_id);

            if (posProf != -1)
                printf("Professor: %s", professores[posProf].nome);
            else
                printf("Professor: Nao encontrado\n");

            printf("\nAlunos:\n");
            for (int j = 0; j < disciplinas[i].qtdAlunos; j++) {
                int posAluno = buscarAlunoPorMatricula(alunos, qtdAlunos, disciplinas[i].alunos[j]);

                if (posAluno != -1)
                    printf("- %s", alunos[posAluno].nome);
                else
                    printf("- Aluno com matricula %d nao encontrado\n", disciplinas[i].alunos[j]);
            }
            break;
        }
    }

    if (!encontrada) {
        printf("Disciplina com codigo %d nao encontrada.\n", codigo);
    }
}


void excluirDisciplina(Disciplina disciplinas[], int *qtdDisc, int codigo) {
    int pos = buscarDisciplinaPorCodigo(disciplinas, *qtdDisc, codigo);
    if (pos == -1) {
        printf("Disciplina nao encontrada.\n");
        return;
    }

    for (int i = pos; i < (*qtdDisc) - 1; i++) {
        disciplinas[i] = disciplinas[i + 1];
    }
    (*qtdDisc)--;
    printf("Disciplina excluida com sucesso!\n");
}
void listarDisciplinascom40Alunos(Disciplina disciplinas[], int qtdDisc, Professor professores[], int qtdProf, Aluno alunos[], int qtdAlunos) {
    printf("\n#### Disciplinas com 40 Alunos ####\n");
    for (int i = 0; i < qtdDisc; i++) {
        if (disciplinas[i].qtdAlunos == MAX_ALUNOS_DISC) {
            printf("Codigo: %d\n", disciplinas[i].cod_materia);
            printf("Nome: %s\n", disciplinas[i].nome);
            printf("Semestre: %d\n", disciplinas[i].semestre);
            printf("-----------------------------\n");
        }
    }
}
