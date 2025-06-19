// Bibliotecas
#include <iostream>
using namespace std;
// Bibliotecas gerais
#include <fstream>
// Incluindo arquivos
#include "../OpcoesHPP/opcao5.hpp"
#include "../ClassesHPP/alunos.hpp"
#include "../ClassesHPP/pessoas.hpp"
#include "../ClassesHPP/professores.hpp"



// Pesquisa CPF do professor
bool pessquisaCpfProfessor(string cpf, Professores *professor[])
{
    for(int i=0; i<Professores::TAMPROFESSOR; i++)
    {
        if (professor[i]->getCpf() ==cpf) return true;
    }
    return false;
}
// Encontrando a posição do professor 
int posicaoProfessor(string cpf, Professores *professor[])
{
    for(int i=0; i<Professores::TAMPROFESSOR; i++)
    {
        if (professor[i]->getCpf() ==cpf) return i;
    }
    return -1;
}
// Excluindo o professor
void excluindoProfessor(Professores *professor[], int x)
{
    for (int i=x; i<Professores::TAMPROFESSOR; i++)
    {
        professor[i]->setNome(professor[i+1]->getNome());
        professor[i]->setDia(professor[i+1]->getDia());
        professor[i]->setMes(professor[i+1]->getMes());
        professor[i]->setAno(professor[i+1]->getAno());
        professor[i]->setCpf(professor[i+1]->getCpf());
    }
    delete(professor[Professores::TAMPROFESSOR-1]);
}
// Apagando professor do arquivo
void apagandoProfessoresArquivo()
{
    ofstream arquivo;
    arquivo.open("professores.txt");
    arquivo.close();
}
// Reescrevendo no arquivo de professores
void reescrevendoArquivoProfessor(Professores *professor[])
{
    ofstream arquivo;
    arquivo.open("professores.txt", ios::app);
    for (int i=0; i<Professores::TAMPROFESSOR; i++)
    {
        arquivo << "Nome: " << professor[i]->getNome() << " - Data de nascimento: " << professor[i]->getDia() <<
        "/" << professor[i]->getMes() << "/" << professor[i]->getAno() << " - CPF: " << professor[i]->getCpf() 
        << " - Título: " << professor[i]->getTitulacao() << endl;
    }
    arquivo.close();
}
// Excluir professor
void excluirProfessor(Professores *professor[])
{
    cout << "\n\nExcluir um aluno";
    string cpf;
    cout << "\nDigite o CPF do aluno que deseja excluir[0 para sair]: ";
    cin >> cpf;
    if(cpf=="0") return; 
    if(pessquisaCpfProfessor(cpf, professor))
    {
        string teste;
        cout << "Tem certeza que deseja excluir " << cpf << " ?[S/N]";
        cin >> teste;
        if(teste=="S" || teste=="s")
        {
            int x= posicaoProfessor(cpf, professor);
            excluindoProfessor(professor, x);
            apagandoProfessoresArquivo();
            reescrevendoArquivoProfessor(professor);
        }

     }
    else cout << "Não existe ninguém com esse CPF, confira se digitou certo";
}
// Pesquisa CPF do aluno
bool pessquisaCpfAluno(string cpf, Alunos *aluno[])
{
    for(int i=0; i<Alunos::TAMALUNO; i++)
    {
        if (aluno[i]->getCpf() ==cpf) return true;
    }
    return false;
}
// Encontrando a posição do aluno 
int posicaoAluno(string cpf, Alunos *aluno[])
{
    for(int i=0; i<Alunos::TAMALUNO; i++)
    {
        if (aluno[i]->getCpf() ==cpf) return i;
    }
    return -1;
}
// Excluindo o aluno
void excluindoAluno(Alunos *aluno[], int x)
{
    for (int i=x; i<Alunos::TAMALUNO; i++)
    {
        aluno[i]->setNome(aluno[i+1]->getNome());
        aluno[i]->setDia(aluno[i+1]->getDia());
        aluno[i]->setMes(aluno[i+1]->getMes());
        aluno[i]->setAno(aluno[i+1]->getAno());
        aluno[i]->setCpf(aluno[i+1]->getCpf());
    }
    delete(aluno[Alunos::TAMALUNO-1]);
}
// Apagando aluno do arquivo
void apagandoAlunosArquivo()
{
    ofstream arquivo;
    arquivo.open("alunos.txt");
    arquivo.close();
}
// Reescrevendo no arquivo de alunos
void reescrevendoArquivoAluno(Alunos *aluno[])
{
    ofstream arquivo;
    arquivo.open("alunos.txt", ios::app);
    for (int i=0; i<Alunos::TAMALUNO; i++)
    {
        arquivo << "Nome: " << aluno[i]->getNome() << " - Data de nascimento: " << aluno[i]->getDia() <<
        "/" << aluno[i]->getMes() << "/" << aluno[i]->getAno() << " - CPF: " << aluno[i]->getCpf() 
        << " - Matrícula: " << aluno[i]->getNumeroMatricula() << endl;
    }
    arquivo.close();
}
// Excluir aluno
void excluirAluno(Alunos *aluno[])
{
    cout << "\n\nExcluir um aluno";
    string cpf;
    cout << "\nDigite o CPF do aluno que deseja excluir[0 para sair]: ";
    cin >> cpf;
    if(cpf=="0") return; 
    if(pessquisaCpfAluno(cpf, aluno))
    {
        string teste;
        cout << "Tem certeza que deseja excluir " << cpf << " ?[S/N]";
        cin >> teste;
        if(teste=="S" || teste=="s")
        {
            int x= posicaoAluno(cpf, aluno);
            excluindoAluno(aluno, x);
            apagandoAlunosArquivo();
            reescrevendoArquivoAluno(aluno);
        }

     }
    else cout << "Não existe ninguém com esse CPF, confira se digitou certo";
}
// Opções opção 5
void opcoesOpcao5(int x, Alunos *aluno[], Professores *professor[])
{
    switch (x)
    {
    case 0:
        break;
    case 1:
        excluirProfessor(professor);
        break;
    case 2:
        excluirAluno(aluno);
        break;
    default:
        break;
    }
}
// Escolha opção 5
int escolhaOpcao5()
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
// Opção 5
void opcao5(Alunos *aluno[], Professores *professor[])
{
    cout << "\n\n5.0 – Voltar ao menu anterior[0]";
    cout << "\n5.1 - Excluir professor pelo CPF[1]";
    cout << "\n5.2 - Excluir aluno pelo CPF[2]";
    int x= escolhaOpcao5();
    opcoesOpcao5(x, aluno, professor);
}

