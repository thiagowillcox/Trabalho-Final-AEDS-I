#ifndef DATA_H
#define DATA_H
// Bibliotecas
#include <iostream>
using namespace std;
#include <string>

// Class data
class Data{
private:
    int dia;
    int mes;
    int ano;
public:
    Data()
    {
        setDia(0);
        setMes(0);
        setAno(0);
    }
    Data(int ano)
    {
        setDia(0);
        setMes(0); 
        setAno(ano);
    }
    Data(int dia, int mes, int ano)
    {
        setDia(dia);
        setMes(mes);
        setAno(ano);
    }
    void setDia(int dia);
    int getDia();
    void setMes(int mes);
    int getMes();
    void setAno(int ano);
    int getAno();
};
#endif