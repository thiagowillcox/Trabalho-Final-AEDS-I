#ifndef OPCAO7_H  
#define OPCAO7_H
// Bibliotecas
#include <iostream>
using namespace std;
// Incluindo arquivos
#include "../ClassesHPP/alunos.hpp"
#include "../ClassesHPP/pessoas.hpp"
#include "../ClassesHPP/professores.hpp"

void opcao7(Alunos *aluno[], Professores *professor[]);
int escolhaOpcao7();
void opcoesOpcao7(int x, Alunos *aluno[], Professores *professor[]);
void alunossAniversariantesMes(Alunos *aluno[], int *mes);
void professoresAniversariantesMes(Professores *professor[], int *mes);
void pegandoMesAniversariante(int *mes);
#endif