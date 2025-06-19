#ifndef OPCAO5_H  
#define OPCAO5_H
// Bibliotecas
#include <iostream>
using namespace std;
// Incluindo arquivos
#include "../ClassesHPP/alunos.hpp"
#include "../ClassesHPP/pessoas.hpp"
#include "../ClassesHPP/professores.hpp"

void opcao5(Alunos *aluno[], Professores *professor[]);
int escolhaOpcao5();
void opcoesOpcao5(int x, Alunos *aluno[], Professores *professor[]);
void excluirAluno(Alunos *aluno[]);
void reescrevendoArquivoAluno(Alunos *aluno[]);
void apagandoAlunosArquivo();
void excluindoAluno(Alunos *aluno[], int x);
int posicaoAluno(string cpf, Alunos *aluno[]);
bool pessquisaCpfAluno(string cpf, Alunos *aluno[]);
void excluirProfessor(Professores *professor[]);
void reescrevendoArquivoProfessor(Professores *professor[]);
void apagandoProfessoresArquivo();
void excluindoProfessor(Professores *professor[], int x);
int posicaoProfessor(string cpf, Professores *professor[]);
bool pessquisaCpfProfessor(string cpf, Professores *professor[]);
#endif