// Bibliotecas
#include <iostream>
using namespace std;
#include <limits>
// Bibliotecas gerais
#include "../OpcoesHPP/opcao7.hpp"
#include "../ClassesHPP/alunos.hpp"
#include "../ClassesHPP/pessoas.hpp"
#include "../ClassesHPP/professores.hpp"

    /*PROFESSORES*/

void professoresAniversariantesMes(Professores *professor[])
{
    int mes = pegandoMesAniversariante();
    int aniversariantes = 0;
    if (Professores::TAMPROFESSOR == 0)
    {
        cout << "\nNão existe nenhum professor cadastrado.";
        return;
    }
    cout << "\n--- PROFESSORES ANIVERSARIANTES DO MÊS " << mes << " ---";
    for (int i = 0; i < Professores::TAMPROFESSOR; i++)
    {
        if (professor[i] != nullptr && professor[i]->getMes() == mes)
        {
            aniversariantes++;
            cout << "\nPROFESSOR-> Nome: " << professor[i]->getNome()
                 << " - Data de nascimento: " << professor[i]->getDia()
                 << "/" << professor[i]->getMes()
                 << "/" << professor[i]->getAno()
                 << " - CPF: " << professor[i]->getCpf()
                 << " - Título: " << professor[i]->getTitulacao();
        }
    }
    cout << "\n-------------------------------------------------------\n";
    if (aniversariantes == 0)
        cout << "\nNão existe nenhum professor aniversariante nesse mês";
    else
        cout << "\nTotal de professores aniversariantes do mês: " << aniversariantes;
}

/*ALUNOS*/

void alunosAniversariantesMes(Alunos *aluno[])
{
    int mes = pegandoMesAniversariante();
    int aniversariantes = 0;
    if (Alunos::TAMALUNO == 0)
    {
        cout << "\nNão existe nenhum aluno cadastrado.";
        return;
    }
    cout << "\n--- ALUNOS ANIVERSARIANTES DO MÊS " << mes << " ---";
    for (int i = 0; i < Alunos::TAMALUNO; i++)
    {
        if (aluno[i] != nullptr && aluno[i]->getMes() == mes)
        {
            aniversariantes++;
            cout << "\nALUNO-> Nome: " << aluno[i]->getNome()
                 << " - Data de nascimento: " << aluno[i]->getDia()
                 << "/" << aluno[i]->getMes()
                 << "/" << aluno[i]->getAno()
                 << " - CPF: " << aluno[i]->getCpf()
                 << " - Matrícula: " << aluno[i]->getNumeroMatricula();
        }
    }
    cout << "\n-----------------------------------------------------\n";
    if (aniversariantes == 0)
        cout << "\nNão existe nenhum aluno aniversariante nesse mês";
    else
        cout << "\nTotal de alunos aniversariantes do mês: " << aniversariantes;
}

/*GERAL*/

int pegandoMesAniversariante()
{
    int mes;
    while (true)
    {
        cout << "\nDigite o mês que deseja: ";
        cin >> mes;
        if (cin.fail())
        {
            cout << "\nEntrada inválida. Por favor, digite um número.\a";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        else if (mes >= 1 && mes <= 12)
        {
            return mes;
        }
        else
        {
            cout << "\nMês inválido[1 a 12]\a";
        }
    }
}

void opcoesOpcao7(int x, Alunos *aluno[], Professores *professor[])
{
    switch (x)
    {
    case 0:
        break;
    case 1:
        professoresAniversariantesMes(professor);
        break;
    case 2:
        alunosAniversariantesMes(aluno);
        break;
    default:
        break;
    }
}

int escolhaOpcao7()
{
    int x;
    bool erro = true;
    while (erro)
    {
        cout << "\n\nDigite o que deseja: ";
        cin >> x;
        if (x >= 0 && x <= 2)
            erro = false;
        else
            cout << "Somente números de 0 a 2\a";
    }
    return x;
}

void opcao7(Alunos *aluno[], Professores *professor[])
{
    cout << "\n\n7.0 – Voltar ao menu anterior[0]";
    cout << "\n7.1 - Listar os Professores aniversariantes do mês[1]";
    cout << "\n7.2 - Listar os Alunos aniversariantes do mês[2]";
    int x = escolhaOpcao7();
    opcoesOpcao7(x, aluno, professor);
}