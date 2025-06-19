#include "../ClassesHPP/pessoas.hpp"
#include <iostream>
using namespace std;
// Variável global
int Pessoas::TAMPES=0;
// Set dia Pessoas
void Pessoas::setDia(int dia)
{
    this->dataNascimento.setDia(dia);
}
// Get dia Pessoas
int Pessoas::getDia()
{
    return this->dataNascimento.getDia();
}
// Set mês Pessoas
void Pessoas::setMes(int mes)
{
    this->dataNascimento.setMes(mes);
}
// Get mês Pessoas
int Pessoas::getMes()
{
    return this->dataNascimento.getMes();
}
// Set dia Pessoas
void Pessoas::setAno(int ano)
{
    this->dataNascimento.setAno(ano);
}
// Get ano Pessoas
int Pessoas::getAno()
{
    return this->dataNascimento.getAno();
}
// Set nome
void Pessoas::setNome(string nome)
{
    this->nome= nome;
}
// Get nome
string Pessoas::getNome()
{
    return this->nome;
}
// Set cpf
void Pessoas::setCpf(string cpf)
{
    this->cpf= cpf;
}
// Get cpf
string Pessoas::getCpf()
{
    return this->cpf;
}

