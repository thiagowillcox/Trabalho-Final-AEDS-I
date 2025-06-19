#include <iostream>
using namespace std;
// Incluindo arquivos
#include "../ClassesHPP/pessoas.hpp"
#include "../ClassesHPP/data.hpp"
// Set dia 
void Data::setDia(int dia)
{
    this->dia= dia;
}
// Get dia
int Data::getDia()
{
    return this->dia;
}
void Data::setMes(int mes)
{
    this->mes= mes;
}
// Get mês
int Data::getMes()
{
     return this->mes;
}
void Data::setAno(int ano)
{
    this->ano= ano;
}
// Get ano
int Data::getAno()
{
     return this->ano;
}
