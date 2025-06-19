#ifndef GERAL_H  
#define GERAL_H
// Bibliotecas
#include <iostream>
using namespace std;
#include <string>
// Incluindo arquivos
#include "../ClassesHPP/alunos.hpp"
#include "../ClassesHPP//pessoas.hpp"
#include "../ClassesHPP/professores.hpp"
void instrcoes ();
void fechamento ();
int escolha();
void opcoes(int x, Pessoas *pessoa[], Alunos *aluno[], Professores *professor[]);
void registrandoPessoas(Pessoas *pessoa[], Alunos *aluno[], Professores *professor[]) ;
void liberarMemoria(Pessoas *pessoa[], Alunos *aluno[], Professores *professor[]);
#endif