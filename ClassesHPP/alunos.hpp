#ifndef ALUNOS_H  
#define ALUNOS_H
// Bibliotecas
#include <iostream>
using namespace std;
#include <string>
// Incluindo arquivos
#include "pessoas.hpp"

// Class aluno
class Alunos:public Pessoas{
private:
    string numeroMatricula;
public:
    void setNumeroMatricula(string numeroMatricula);
    string getNumeroMatricula();
    static int TAMALUNO;
    Alunos():Pessoas()
    {
        setNumeroMatricula("");
        TAMALUNO++;
    }
    Alunos(string nome, string cpf, string numeroMatricula):Pessoas(nome, cpf)
    {
        setNumeroMatricula(numeroMatricula);
        TAMALUNO++;
    }
    Alunos(string nome, int dia, int mes, int ano, string cpf, string numeroMatricula):Pessoas(nome, dia, mes, ano, cpf)
    {
        setNumeroMatricula(numeroMatricula);
        TAMALUNO++;
    }
    ~Alunos()
    {
        if (Alunos::TAMALUNO > 0)
        {
            Alunos::TAMALUNO--;
        }
    }
};

#endif