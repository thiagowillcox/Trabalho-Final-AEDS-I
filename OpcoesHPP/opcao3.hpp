#ifndef OPCAO3_H  
#define OPCAO3_H
// Bibliotecas
#include <iostream>
using namespace std;
// Incluindo arquivos
#include "../ClassesHPP/alunos.hpp"
#include "../ClassesHPP/pessoas.hpp"
#include "../ClassesHPP/professores.hpp"

void opcao3(Alunos *aluno[], Professores *professor[]);
int escolhaOpcao3();
void opcoesOpcao3(int x, Alunos *aluno[], Professores *professor[]);
void pesquisarAlunoNome(Alunos *aluno[]);
void pesquisarProfessorNome (Professores *professor[]);
#endif