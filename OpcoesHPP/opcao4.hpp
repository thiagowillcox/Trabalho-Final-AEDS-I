#ifndef OPCAO4_H  
#define OPCAO4_H
// Bibliotecas
#include <iostream>
// Incluindo arquivos
#include "../ClassesHPP/alunos.hpp"
#include "../ClassesHPP/pessoas.hpp"
#include "../ClassesHPP/professores.hpp"

void opcao4(Alunos *aluno[], Professores *professor[]);

int escolhaOpcao4();

void opcoesOpcao4(int x, Alunos *aluno[], Professores *professor[]);

void pesquisarAlunoCPF(Alunos *aluno[]);

void pesquisarProfessorCPF(Professores *professor[]);

#endif