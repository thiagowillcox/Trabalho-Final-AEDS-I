#ifndef PROFESSORES_H  
#define PROFESSORES_H
// Bibliotecas
#include <iostream>
using namespace std;
#include <string>
// Incluindo arquivos
#include "pessoas.hpp"
// Class professor
class Professores:public Pessoas{
private:
    string titulacao;
public:
    static int TAMPROFESSOR;
    void setTitulacao(string titulacao);
    string getTitulacao();
    Professores():Pessoas()
    {
        setTitulacao("");
        TAMPROFESSOR++;
    }
    Professores(string nome, string cpf, string titulo):Pessoas(nome, cpf)
    {
        setTitulacao(titulo);
        TAMPROFESSOR++;
    }
    Professores(string nome, int dia, int mes, int ano, string cpf, string titulo):Pessoas(nome, dia, mes, ano, cpf)
    {
        setTitulacao(titulo);
        TAMPROFESSOR++;
    }
    ~Professores()
    {
        if (Professores::TAMPROFESSOR > 0) 
        { 
            Professores::TAMPROFESSOR--;
        }
    }
};

#endif