// Bibliotecas
#include <iostream>
using namespace std;
// Bibliotecas gerais
#include "../OpcoesHPP/opcao7.hpp"
#include "../ClassesHPP/alunos.hpp"
#include "../ClassesHPP/pessoas.hpp"
#include "../ClassesHPP/professores.hpp"

// Pegando o mês do aniversariante
void pegandoMesAniversariante(int *mes)
{
    bool erro=true;
    while (erro)
    {
        cout << "\nDigite o mês que deseja: ";
        cin >> *mes;
        if(*mes>=1 && *mes<=12) erro= false;
        else cout << "\nMês inválido[1 a 12]\a";
    }

}
// Listando professores aniversariantes do mês
void professoresAniversariantesMes(Professores *professor[], int *mes)
{
    int aniversariantes=0;
    if(Professores::TAMPROFESSOR!=0)
    {
        for(int i=0; i<Professores::TAMPROFESSOR; i++)
        {
            if(professor[i]->getMes()==*mes)
            {
                aniversariantes++;
                cout << "\nPROFESSOR-> Nome: " << professor[i]->getNome() << " - Data de nascimento: " << professor[i]->getDia() <<
                "/" << professor[i]->getMes() << "/" << professor[i]->getAno() << " - CPF: " << professor[i]->getCpf()
                << " - Título: " << professor[i]->getTitulacao();
            }
        }
    }
    else cout << "\nNão existe nenhum professor cadastrado";
    if(aniversariantes==0) cout << "\nNão existe nenhum professor aniversariante nesse mês";
    else cout << "\nTotal de professores aniversariantes do mês: " << aniversariantes;
}
// Listando alunos aniversariantes do mês
void alunossAniversariantesMes(Alunos *aluno[], int *mes)
{
    int aniversariantes=0;
    if(Alunos::TAMALUNO!=0)
    {
        for(int i=0; i<Alunos::TAMALUNO; i++)
        {
            if(aluno[i]->getMes()==*mes)
            {
                aniversariantes++;
                cout << "\naluno-> Nome: " << aluno[i]->getNome() << " - Data de nascimento: " << aluno[i]->getDia() <<
                "/" << aluno[i]->getMes() << "/" << aluno[i]->getAno() << " - CPF: " << aluno[i]->getCpf()
                << " - Matrícula: " << aluno[i]->getNumeroMatricula();
            }
        }
    }
    else cout << "\nNão existe nenhum aluno cadastrado";
    if(aniversariantes==0) cout << "\nNão existe nenhum aluno aniversariante nesse mês";
    else cout << "\nTotal de alunos aniversariantes do mês: " << aniversariantes;
}
// Opções opção 7
void opcoesOpcao7(int x, Alunos *aluno[], Professores *professor[])
{
    int mes;
    switch (x)
    {
    case 0:
        break;
    case 1:
        pegandoMesAniversariante(&mes);
        break;
    case 2:
        professoresAniversariantesMes(professor, &mes);
        break;
    case 3:
        alunossAniversariantesMes(aluno, &mes);
        break;
    default:
        break;
    }
}
// Escolha opção 7
int escolhaOpcao7()
{
    int x;
    bool erro=true;
    while(erro)
    {
        cout << "\n\nDigite o que deseja: ";
        cin >> x;
        if(x>=0 && x<=3) erro= false;
        else cout << "Somente números de 0 a 3\a";
    }
    return x;
}
//Opção 7
void opcao7(Alunos *aluno[], Professores *professor[])
{
    cout << "\n\n7.0 – Voltar ao menu anterior[0]";
    cout << "\n7.1 - Informar o mês a ser pesquisado[1]";
    cout << "\n7.2 - Listar os Professores aniversariantes do mês[2]";
    cout << "\n7.3 - Listar os Alunos aniversariantes do mês[3]";
    int x= escolhaOpcao7();
    opcoesOpcao7(x, aluno, professor);
}
