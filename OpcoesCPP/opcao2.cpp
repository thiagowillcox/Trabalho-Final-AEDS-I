// Bibliotecas
#include <iostream>
using namespace std;
// Bibliotecas gerais
#include <fstream>
// Incluindo arquivos
#include "../OpcoesHPP/opcao2.hpp"
#include "../ClassesHPP/alunos.hpp"
#include "../ClassesHPP/pessoas.hpp"
#include "../ClassesHPP/professores.hpp"


// Escolha opção 2
int escolhaOpcao2()
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
// Listar professores
void listarProfessores()
{
    ifstream arquivo("professores.txt");
    if (!arquivo.is_open())
    {
        cout << "Arquivo de professores não encontrado. Nenhum dado carregado.\n";
        return;
    }
    string linha;
    if (Professores::TAMPROFESSOR!=0)
    {
        cout << "\n\nLista de professores cadastrados: ";
        while (getline(arquivo,linha))
        {
            cout << endl << linha;
        }
            cout << "\nTotal de professores: " << Professores::TAMPROFESSOR;
    }
    else cout << "\nNão há nenhum professor cadastrado";  
}
// Listar alunos
void listarAluno()
{    
    ifstream arquivo("alunos.txt");
    if (!arquivo.is_open())
    {
        cout << "Arquivo de alunos não encontrado. Nenhum dado carregado.\n";
        return;
    }
    string linha;
    if (Alunos::TAMALUNO!=0)
    {
        cout << "\n\nLista de alunos cadastrados: ";
        while (getline(arquivo,linha))
        {
            cout << endl << linha;
        }
            cout << "\nTotal de alunos: " << Alunos::TAMALUNO;
    }
    else cout << "\nNão há nenhum anluno cadastrado";  
}
// Opções opção 2
void opcoesOpcao2(int x)
{
    switch (x)
    {
    case 0:
        break;
    case 1:
        listarProfessores();
        break;
    case 2:
        listarAluno();
        break;
    default:
        break;
    }
}
// Opção 2
void opcao2()
{
    cout << "\n\n2.0 – Voltar ao menu anterior[0]";
    cout << "\n2.1 - Listar Professores[1]";
    cout << "\n2.2 - Listar Alunos[2]";
    int x= escolhaOpcao2();
    opcoesOpcao2(x);
}



