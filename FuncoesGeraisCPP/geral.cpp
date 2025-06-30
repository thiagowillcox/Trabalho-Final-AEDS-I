// Bibliotecas
#include <iostream>
using namespace std;
// Bibliotecas gerais
#include <fstream>
#include <string>
#include <limits>
// Bibliotecas gerais
#include <fstream>
// Incluindo arquivos
#include "../FuncoesGeraisHPP/geral.hpp"
// Incluindo arquivos
#include "../ClassesHPP/alunos.hpp"
#include "../ClassesHPP/pessoas.hpp"
#include "../ClassesHPP/professores.hpp"
#include "../OpcoesHPP/opcao1.hpp"
#include "../OpcoesHPP/opcao2.hpp"
#include "../OpcoesHPP/opcao3.hpp"
#include "../OpcoesHPP/opcao4.hpp"
#include "../OpcoesHPP/opcao5.hpp"
#include "../OpcoesHPP/opcao6.hpp"
#include "../OpcoesHPP/opcao7.hpp"
// Escrita das opções
void instrcoes ()
{
    cout << "\n\n--- MENU PRINCIPAL ---";
    cout << "\n\n0 - Sair do programa";
    cout << "\n1 - Cadastrar uma pessoa";
    cout << "\n2 - Listar todas as pessoas cadastradas";
    cout << "\n3 - Pesquisar por nome";
    cout << "\n4 - Pesquisar por CPF";
    cout << "\n5 - Excluir pessoa";
    cout << "\n6 - Apagar todas as pessoas cadastradas";
    cout << "\n7 - Aniversariantes do mês";
    cout << "\n----------------------";
} 
// Mensagem de fechamento
void fechamento ()
{
    cout << "\n\nObrigado por usar o programa, volte quando precisar!";
}
// Escolha da opção
int escolha()
{
    int x;
    bool erro = true;
    while (erro)
    {
        cout << "\n\nDigite o que deseja: ";
        cin >> x;
        if (x >= 0 && x <= 7) erro = false;
        else cout << "\nSomente números de 0 a 7.\n\a";
    }//Fim do while
    
    return x;
}
// Opções
void opcoes(int x, Pessoas *pessoa[], Alunos *aluno[], Professores *professor[])
{
    switch (x)
    {
    case 1:
        opcao1(pessoa, aluno, professor);
        break;
    case 2:
        opcao2(aluno, professor);
        break;
    case 3:
        opcao3(aluno, professor);
        break;
    case 4:
        opcao4(aluno, professor);
        break;
    case 5:
        opcao5(aluno, professor);
        break;
    case 6:
        opcao6(aluno, professor);
        break;
    case 7:
        opcao7(aluno, professor);
        break;
    default:
        break;
    }
}
// Ler arquivo de alunos
void lerArquivoAlunos(Alunos *aluno[], Pessoas *pessoa[])
{
    ifstream arqAluno("alunos.txt");
    if (arqAluno.is_open())
    {
        string linha;
        int dia, mes, ano;
        string nome, cpf, matricula;
        int i=0;
        while (getline(arqAluno, linha)) 
        {
            // Nome
            nome= linha;
            // Data 
            getline(arqAluno, linha);
            dia = std::stoi(linha);
            getline(arqAluno, linha);
            mes = std::stoi(linha);
            getline(arqAluno, linha);
            ano = std ::stoi(linha);
            // CPF
            getline(arqAluno, linha);
            cpf= linha;
            // Matrícula
            getline(arqAluno, linha);
            matricula= linha;
            // Separador
            getline(arqAluno, linha);
            // Criando aluno
            aluno[i]= new Alunos(nome, dia, mes, ano, cpf, matricula);
            i++;
        }
        arqAluno.close();
    }
}
// Ler arquivo de professores
void lerArquivoProfessores(Professores *professor[], Pessoas *pessoa[])
{
    ifstream arqProf("professores.txt");
    if (arqProf.is_open())
    {
        string linha;
        int dia, mes, ano;
        string nome, cpf, titulacao;
        int i=0;
        while (getline(arqProf, linha)) 
        {
            // Nome
            nome= linha;
            // Data
            getline(arqProf, linha);
            dia = std::stoi(linha);
            getline(arqProf, linha);
            mes = std::stoi(linha);
            getline(arqProf, linha);
            ano = std ::stoi(linha);
            // CPF
            getline(arqProf, linha);
            cpf= linha;
            // Matrícula
            getline(arqProf, linha);
            titulacao= linha;
            // Separador
            getline(arqProf, linha);
            // Criando aluno
            professor[i]= new Professores(nome, dia, mes, ano, cpf, titulacao);
            i++;
        }
        arqProf.close();
    }
}
// Lendo pessoas do arquivo
void registrandoPessoas(Pessoas *pessoa[], Alunos *aluno[], Professores *professor[]) 
{
    lerArquivoAlunos(aluno, pessoa);
    lerArquivoProfessores(professor, pessoa);
}
// Liberar memória
void liberarMemoria(Pessoas *pessoa[], Alunos *aluno[], Professores *professor[]) 
{
    for (int i = 0; i < Alunos::TAMALUNO; i++) {
        if (aluno[i] != nullptr) 
        {
            delete aluno[i];
            aluno[i] = nullptr;
        }
    }
    for (int i = 0; i < Professores::TAMPROFESSOR; i++) {
        if (professor[i] != nullptr) 
        {
            delete professor[i];
            professor[i] = nullptr;
        }
    }
    Professores::TAMPROFESSOR = 0;
    Pessoas::TAMPES = 0;
}
