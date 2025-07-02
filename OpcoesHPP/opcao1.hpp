#ifndef OPCAO1_H 
#define OPCAO1_H
// Bibliotecas
#include <iostream>
#include <string> 
using namespace std;
// Incluindo arquivos
#include "../ClassesHPP/alunos.hpp"
#include "../ClassesHPP/pessoas.hpp"
#include "../ClassesHPP/professores.hpp"

void opcao1(Pessoas *pessoa[], Alunos *aluno[], Professores *professor[]);

void opcoesOpcao1(int x, Pessoas *pessoa[], Alunos *aluno[], Professores *professor[]);

void cadastrarAluno(Pessoas *pessoa[], Alunos *aluno[]);

string registrandoMatricula(Alunos *aluno[]);

bool conferinfoMatricula(string matricula, Alunos *aluno[]);

void cadastrarProfessor(Pessoas *pessoa[],Professores *professor[]);

string registrandoTitulo();

int escolhaOpcao1();

string registrandoCpf(Pessoas *pessoa[]);

void escrevendoProfessorArquivo(Professores *professor);

void escrevendoAlunoArquivo(Alunos *aluno);

bool validandoData(int dia, int mes, int ano);

bool ehbissexto (int ano);

#endif