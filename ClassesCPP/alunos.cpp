// Bibliotecas
#include <iostream>
using namespace std;
// Incluindo arquivos
#include "../ClassesHPP/alunos.hpp"
// Variável global
int Alunos::TAMALUNO=0;
// Set número de matrícula
void Alunos::setNumeroMatricula(string numeroMatricula)
{
    this->numeroMatricula= numeroMatricula;
}
// Get número de matrícula
string Alunos::getNumeroMatricula()
{
    return this->numeroMatricula;
}
