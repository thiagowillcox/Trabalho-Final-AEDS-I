#ifndef OPCAO6_H  
#define OPCAO6_H
// Bibliotecas
#include <iostream>
// Incluindo arquivos
#include "../ClassesHPP/alunos.hpp"
#include "../ClassesHPP/pessoas.hpp"
#include "../ClassesHPP/professores.hpp"

void opcao6 (Alunos *aluno[], Professores *professor[]);
int escolhaOpcao6();
void opcoesOpcao6(int x, Alunos *aluno[], Professores *professor[]);
void deletarTodosAlunos(Alunos *aluno[]);
void deletarTodosProfessores(Professores *professor[]);
#endif