// Bibliotecas
#include <iostream>
using namespace std;
#include <limits>
// Bibliotecas gerais
#include "../OpcoesHPP/opcao7.hpp"
#include "../ClassesHPP/alunos.hpp"
#include "../ClassesHPP/pessoas.hpp"
#include "../ClassesHPP/professores.hpp"

void aniversariantesMes(int *mes, Professores *professor[], int *aniversariantes)
{
    if (Professores::TAMPROFESSOR == 0)
    {
        cout << "\nNão existe nenhum professor cadastrado.";
        return;
    }
    cout << "\n--- PROFESSORES ANIVERSARIANTES DO MÊS " << *mes << " ---";
    for (int i = 0; i < Professores::TAMPROFESSOR; i++)
    {
        if (professor[i] != nullptr && professor[i]->getMes() == *mes)
        {
            (*aniversariantes)++;
            cout << "\nNome: " << professor[i]->getNome()
                 << " - Data de nascimento: " << professor[i]->getDia()
                 << "/" << professor[i]->getMes()
                 << "/" << professor[i]->getAno()
                 << " - CPF: " << professor[i]->getCpf();
        }
    }
    cout << "\n-------------------------------------------------------\n";
}

void aniversariantesMes(int *mes, Alunos *aluno[], int *aniversariantes)
{
    if (Alunos::TAMALUNO == 0)
    {
        cout << "\nNão existe nenhum aluno cadastrado.";
        return;
    }
    cout << "\n--- ALUNOS ANIVERSARIANTES DO MÊS " << *mes << " ---";
    for (int i = 0; i < Alunos::TAMALUNO; i++)
    {
        if (aluno[i] != nullptr && aluno[i]->getMes() == *mes)
        {
            (*aniversariantes)++;
            cout << "\nNome: " << aluno[i]->getNome()
                 << " - Data de nascimento: " << aluno[i]->getDia()
                 << "/" << aluno[i]->getMes()
                 << "/" << aluno[i]->getAno()
                 << " - CPF: " << aluno[i]->getCpf();
        }
    }
    cout << "\n-------------------------------------------------------\n";
}

void separacao(int *mes, Alunos *aluno[], Professores *professor[])
{
    int aniversariantes = 0;
    aniversariantesMes(mes, aluno, &aniversariantes);
    aniversariantesMes(mes, professor, &aniversariantes);
    if (aniversariantes == 0)
        cout << "\nNão tem nenhum aniversariante nesse mês";
    else
        cout << "\nExistem " << aniversariantes << " nesse mês";
}

void opcao7escolha(int *mes, Alunos *aluno[], Professores *professor[])
{
    cout << "\n\n7.0 – Voltar ao menu anterior[0]";
    cout << "\n7.1 - Informar o mês a ser pesquisado[1]";
    cout << "\n7.2 - Listar aniversáriantes do mês[2]";
    int x = escolhaOpcao7();
    opcoesOpcao7(x, mes, aluno, professor);
}

void pegandoMesAniversariante(int *mes, Alunos *aluno[], Professores *professor[])
{
    bool teste = true;
    while (teste)
    {
        cout << "\nDigite o mês que deseja: ";
        cin >> *mes;
        if (cin.fail())
        {
            cout << "\nEntrada inválida. Por favor, digite um número.\a";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        else if (*mes >= 1 && *mes <= 12)
            teste = false;
        else
            cout << "\nMês inválido[1 a 12]\a";
    }
    opcao7escolha(mes, aluno, professor);
}

void opcoesOpcao7(int x, int *mes, Alunos *aluno[], Professores *professor[])
{
    switch (x)
    {
    case 0:
        break;
    case 1:
        pegandoMesAniversariante(mes, aluno, professor);
        break;
    case 2:
        separacao(mes, aluno, professor);
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
    int mes_local = 0;
    opcao7escolha(&mes_local, aluno, professor);
}