// Bibliotecas
#include <iostream>
using namespace std;
// Bibliotecas gerais
#include "../OpcoesHPP/opcao3.hpp"
#include "../ClassesHPP/alunos.hpp"
#include "../ClassesHPP/pessoas.hpp"
#include "../ClassesHPP/professores.hpp"

// Pesquisar Professor por nome
void pesquisarProfessorNome (Professores *professor[])
{
    cout << "\n\nPesquisar professor por nome";
    string nome;
    cout << "\nDigite o nome do professor que deseja procurar: ";
    cin.ignore();
    getline(cin, nome);
    bool achou= false;
    for (int i=0; i<Professores::TAMPROFESSOR; i++)
    {
        if(nome==professor[i]->getNome()) 
        {
            cout << "Nome: " << professor[i]->getNome() << " - Data de nascimento: " << professor[i]->getDia() <<
            "/" << professor[i]->getMes() << "/" << professor[i]->getAno() << " - CPF: " << professor[i]->getCpf()  
            << " - Título: " << professor[i]->getTitulacao() << endl;
            achou=true;
        }
    }
    if(!achou) cout << "\nNão existe ninguém com esse nome";
}
// Pesquisar Aluno por nome
void pesquisarAlunoNome(Alunos *aluno[])
{
    cout << "\n\nPesquisar aluno por nome";
    string nome;
    cout << "\nDigite o nome do aluno que deseja procurar: ";
    cin.ignore();
    getline(cin, nome);
    bool achou= false;
    for (int i=0; i<Alunos::TAMALUNO; i++)
    {
        if(nome==aluno[i]->getNome()) 
        {
            cout << "Nome: " << aluno[i]->getNome() << " - Data de nascimento: " << aluno[i]->getDia() <<
            "/" << aluno[i]->getMes() << "/" << aluno[i]->getAno() << " - CPF: " << aluno[i]->getCpf() << " - Matrícula: " 
            << aluno[i]->getNumeroMatricula() << endl;
            achou=true;
        }
    }
    if(!achou) cout << "\nNão existe ninguém com esse nome";
}
// Opções opção 3
void opcoesOpcao3(int x, Alunos *aluno[], Professores *professor[])
{
    switch (x)
    {
    case 0:
        break;
    case 1:
        pesquisarProfessorNome(professor);
        break;
    case 2:
        pesquisarAlunoNome(aluno);
        break;
    default:
        break;
    }
}
// Escolha opção 3
int escolhaOpcao3()
{
    int x;
    bool erro=true;
    while(erro)
    {
        cout << "\n\nDigite o que deseja: ";
        cin >> x;
        if(x>=0 && x<=2) erro= false;
        else cout << "Somente números de 0 a 2\a";
    }
    return x;
}
// Opção 3
void opcao3(Alunos *aluno[], Professores *professor[])
{
    cout << "\n\n3.0 – Voltar ao menu anterior[0]";
    cout << "\n3.1 - Pesquisar Professores por nome[1]";
    cout << "\n3.2 - Pesquisar Alunos por nome[2]";
    int x= escolhaOpcao3();
    opcoesOpcao3(x, aluno, professor);
}



