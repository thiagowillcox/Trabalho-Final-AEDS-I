// Bibliotecas
#include <iostream>
using namespace std;
// Incluindo arquivos
#include "../ClassesHPP/professores.hpp"
int Professores::TAMPROFESSOR=0;
// Set titulação do professor
void Professores::setTitulacao(string titulacao)
{
    this->titulacao=titulacao;
}
// Get titulação do professor
string Professores::getTitulacao()
{
    return titulacao;
}
