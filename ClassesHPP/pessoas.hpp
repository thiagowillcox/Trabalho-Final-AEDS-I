#ifndef PESSOAS_H  
#define PESSOAS_H
// Bibliotecas
#include <iostream>
using namespace std;
#include <string>
// Incluindo arquivos
#include "data.hpp"
// Class pessoas
class Pessoas{
private:
    string nome;
    Data dataNascimento;
    string cpf;
public:
    static int TAMPES;
    Pessoas()
    {
        setNome("");
        this->dataNascimento= Data();
        setCpf("");
        TAMPES++;
    }
    Pessoas(string nome, string cpf)
    {
        setNome(nome);
        this->dataNascimento= Data();
        setCpf(cpf);
        TAMPES++;
    }
    Pessoas(string nome, int dia, int mes, int ano, string cpf)
    {
        setNome(nome);
        this->dataNascimento= Data(dia, mes, ano);
        setCpf(cpf);
        TAMPES++;
    }
    ~Pessoas()
    {
        if (Pessoas::TAMPES > 0) Pessoas::TAMPES--;
    }
    void setNome(string nome);
    string getNome();

    void setDia(int dia);
    int getDia();

    void setMes(int mes);
    int getMes();

    void setAno(int ano);
    int getAno();
    
    void setCpf(string cpf);
    string getCpf();
};
#endif
