#include <stdio.h>
#include <ctype.h>

#include "alunos.h"
#include "professor.h"
#include "disciplina.h"
#include "util.h"

//menus

int menuPrincipal() {
    int opcao;
    printf("\n====== ESCOLA SUPERIOR ======\n");
    printf("1 - Adicionar\n");
    printf("2 - Atualizar\n");
    printf("3 - Excluir\n");
    printf("4 - Listar (Relatorios)\n");
    printf("5 - Atribuir aluno na disciplina\n");
    printf("0 - Sair\n");
    printf("Escolha uma opcao: ");
    scanf("%d", &opcao);
    limparBuffer();
    return opcao;
}

int menuAdicionar() {
    int opcao;
    printf("\n###### ADICIONAR ######\n");
    printf("1 - Aluno\n");
    printf("2 - Professor\n");
    printf("3 - Disciplina\n");
    printf("0 - Voltar\n");
    printf("Opcao: ");
    scanf("%d", &opcao);
    limparBuffer();
    return opcao;
}

int menuAtualizar() {
    int opcao;
    printf("\n###### ATUALIZAR ######\n");
    printf("1 - Aluno\n");
    printf("2 - Professor\n");
    printf("3 - Disciplina\n");
    printf("0 - Voltar\n");
    printf("Opcao: ");
    scanf("%d", &opcao);
    limparBuffer();
    return opcao;
}

int menuExcluir() {
    int opcao;
    printf("\n###### EXCLUIR ######\n");
    printf("1 - Aluno\n");
    printf("2 - Professor\n");
    printf("3 - Disciplina\n");
    printf("0 - Voltar\n");
    printf("Opcao: ");
    scanf("%d", &opcao);
    limparBuffer();
    return opcao;
}

int menuListar() {
    int opcao;
    printf("\n###### RELATORIOS ######\n");
    printf("1 - Listar todos os Alunos\n");
    printf("2 - Listar todos os Professores\n");
    printf("3 - Listar todas as Disciplinas\n");
    printf("4 - Listar Alunos por Sexo\n");
    printf("5 - Listar Professores por Sexo\n");
    printf("6 - Listar Alunos por ordem alfabetica\n");
    printf("7 - Listar Professores por ordem alfabetica\n");
    printf("8 - Listar Alunos por data de nascimento\n");
    printf("9 - Listar Professores por data de nascimento\n");
    printf("10 - Listar Aniversariantes do Mes\n");
    printf("11 - Listar Disciplina Especifica\n");
    printf("12 - Listar Pessoas por Letras\n");
    printf("13 - Listar Disciplinas com 40 vagas\n");
    printf("0 - Voltar\n");
    printf("Opcao: ");
    scanf("%d", &opcao);
    limparBuffer();
    return opcao;
}

//main

int main() {
    Aluno alunos[TAM_ALUNOS];
    Professor professores[TAM_PROFESSOR];
    Disciplina disciplinas[TAM_MATERIA];

    int qtdAlunos = 0, qtdProf = 0, qtdDisc = 0;
    int id_aluno = 2026000;
    int id_professor = 100000;
    int id_disciplina = 1;
    char sexo; 

    int opcaoPrincipal, opcaoSub, codigo;

    do {
        opcaoPrincipal = menuPrincipal();

        switch (opcaoPrincipal) {

            //adicionar
            case 1:
                opcaoSub = menuAdicionar();
                switch (opcaoSub) {
                    case 1:
                        adicionarAluno(alunos, &qtdAlunos, &id_aluno);
                        break;
                    case 2:
                        adicionarProfessor(professores, &qtdProf, &id_professor);
                        break;
                    case 3:
                        adicionarDisciplina(disciplinas, &qtdDisc, &id_disciplina, professores, qtdProf);
                        break;
                    case 0:
                        break;
                    default:
                        printf("Opcao invalida!\n");
                }
                break;

            //atualizar
            case 2:
                opcaoSub = menuAtualizar();
                switch (opcaoSub) {
                    case 1:
                        printf("Digite a matricula do aluno: ");
                        scanf("%d", &codigo);
                        limparBuffer();
                        atualizarAluno(alunos, qtdAlunos, codigo);
                        break;
                    case 2:
                        printf("Digite o codigo do professor: ");
                        scanf("%d", &codigo);
                        limparBuffer();
                        atualizarProfessor(professores, qtdProf, codigo);
                        break;
                    case 3:
                        printf("Digite o codigo da disciplina: ");
                        scanf("%d", &codigo);
                        limparBuffer();
                        atualizarDisciplina(disciplinas, qtdDisc, codigo);
                        break;
                    case 0:
                        break;
                    default:
                        printf("Opcao invalida!\n");
                }
                break;

            //excluir
            case 3:
                opcaoSub = menuExcluir();
                switch (opcaoSub) {
                    case 1:
                        printf("Digite a matricula do aluno: ");
                        scanf("%d", &codigo);
                        limparBuffer();
                        excluirAluno(alunos, &qtdAlunos, codigo);
                        break;
                    case 2:
                        printf("Digite o codigo do professor: ");
                        scanf("%d", &codigo);
                        limparBuffer();
                        excluirProfessor(professores, &qtdProf, codigo);
                        break;
                    case 3:
                        printf("Digite o codigo da disciplina: ");
                        scanf("%d", &codigo);
                        limparBuffer();
                        excluirDisciplina(disciplinas, &qtdDisc, codigo);
                        break;
                    case 0:
                        break;
                    default:
                        printf("Opcao invalida!\n");
                }
                break;

            //listar
            case 4:
                opcaoSub = menuListar();
                switch (opcaoSub) {
                    case 1:
                        listarAlunos(alunos, qtdAlunos);
                        break;
                    case 2:
                        listarProfessores(professores, qtdProf);
                        break;
                    case 3:
                        listarDisciplinas(disciplinas, qtdDisc, professores, qtdProf);
                        break;
                    case 4:
                        
                        printf("Digite o sexo (M/F): ");
                        scanf(" %c", &sexo);
                        sexo = toupper(sexo);
                        limparBuffer();
                        listarAlunosPorSexo(alunos, qtdAlunos, sexo);
                        break;
                    case 5:
                                               
                        printf("Digite o sexo (M/F): ");
                        scanf(" %c", &sexo);
                        sexo = toupper(sexo);
                        limparBuffer();
                        listarProfessoresPorSexo(professores, qtdProf, sexo);
                        break;
                    case 6:
                        listarAlunosPorAlfabeto(alunos, qtdAlunos);
                        break;
                    case 7:
                        listarProfessoresPorAlfabeto(professores, qtdProf);
                        break;
                    case 8:
                        listarAlunosPorDataNascimento(alunos, qtdAlunos);
                        break;
                    case 9:
                        listarProfessoresPorDataNascimento(professores, qtdProf);
                        break;
                    case 10:
                        listarAniversariantesDoMes(alunos, qtdAlunos, professores, qtdProf);
                        break;
                    case 11:
                        printf("Digite o codigo da disciplina:");
                        scanf("%d", &codigo);
                        limparBuffer();
                        listarUmaDisciplinaEspecifica(disciplinas, qtdDisc, professores, qtdProf, alunos, qtdAlunos, codigo);
                        break;
                    case 12: {
                    char letras[QTD_LETRAS];
                    for (int i = 0; i < QTD_LETRAS; i++) {
                    printf("Digite a %da letra: ", i + 1);
                    scanf(" %c", &letras[i]);  }
                    limparBuffer();
                    listarPessoasPorLetras(alunos, qtdAlunos, professores, qtdProf, letras);
                    break;
                    }
                        break;
                    case 13: 
                        listarDisciplinascom40Alunos(disciplinas, qtdDisc, professores, qtdProf, alunos, qtdAlunos);
                        break;
                    case 0:
                        break;
                    default:
                        printf("Opcao invalida!\n");
                }
                break;

            //atribuir aluno na disciplina
            case 5:
                atribuirAlunoDisciplina(disciplinas, qtdDisc, alunos, qtdAlunos);
                break;

            //sair
            case 0:
                printf("Encerrando o sistema...\n");
                break;

            default:
                printf("Opcao invalida!\n");
        }

    } while (opcaoPrincipal != 0);

    return 0;
}