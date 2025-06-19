// Bibliotecas
#include <iostream>
using namespace std;
// Bibliotecas gerais
#include <fstream>
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
    cout << "\n\n0 - Sair do programa";
    cout << "\n1 - Cadastrar uma pessoa";
    cout << "\n2 - Listar todas as pessoas cadastradas";
    cout << "\n3 - Pesquisar por nome";
    cout << "\n4 - Pesquisar por CPF";
    cout << "\n5 - Excluir pessoa";
    cout << "\n6 - Apagar todas as pessoas cadastradas";
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
        opcao2();
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
    if (arqAluno.is_open()) {
        string linha;
        while (getline(arqAluno, linha)) {
            if (linha.find("ALUNO->") != string::npos) {
                // Extrair dados do aluno
                size_t posNome = linha.find("Nome: ") + 6;
                size_t posData = linha.find(" - Data de nascimento: ");
                string nome = linha.substr(posNome, posData - posNome);
                
                size_t posDia = posData + 23;
                size_t posBarra1 = linha.find("/", posDia);
                int dia = stoi(linha.substr(posDia, posBarra1 - posDia));
                
                size_t posMes = posBarra1 + 1;
                size_t posBarra2 = linha.find("/", posMes);
                int mes = stoi(linha.substr(posMes, posBarra2 - posMes));
                
                size_t posAno = posBarra2 + 1;
                size_t posCpf = linha.find(" - CPF: ", posAno);
                int ano = stoi(linha.substr(posAno, posCpf - posAno));
                
                size_t posCpfVal = posCpf + 8;
                size_t posMatricula = linha.find(" - Matrícula: ", posCpfVal);
                string cpf = linha.substr(posCpfVal, posMatricula - posCpfVal);
                
                size_t posMatriculaVal = posMatricula + 14;
                string matricula = linha.substr(posMatriculaVal);
                
                // Criar novo aluno
                aluno[Alunos::TAMALUNO] = new Alunos(nome, dia, mes, ano, cpf, matricula);
                pessoa[Pessoas::TAMPES] = aluno[Alunos::TAMALUNO];
                Alunos::TAMALUNO++;
                Pessoas::TAMPES++;
            }
        }
        arqAluno.close();
    }
}
// Ler arquivo de professores
void lerArquivoProfessores(Professores *professor[], Pessoas *pessoa[])
{
    ifstream arqProf("professores.txt");
    if (arqProf.is_open()) {
        string linha;
        while (getline(arqProf, linha)) {
            if (linha.find("PROFESSOR->") != string::npos) {
                // Extrair dados do professor
                size_t posNome = linha.find("Nome: ") + 6;
                size_t posData = linha.find(" - Data de nascimento: ");
                string nome = linha.substr(posNome, posData - posNome);
                
                size_t posDia = posData + 23;
                size_t posBarra1 = linha.find("/", posDia);
                int dia = stoi(linha.substr(posDia, posBarra1 - posDia));
                
                size_t posMes = posBarra1 + 1;
                size_t posBarra2 = linha.find("/", posMes);
                int mes = stoi(linha.substr(posMes, posBarra2 - posMes));
                
                size_t posAno = posBarra2 + 1;
                size_t posCpf = linha.find(" - CPF: ", posAno);
                int ano = stoi(linha.substr(posAno, posCpf - posAno));
                
                size_t posCpfVal = posCpf + 8;
                size_t posTitulo = linha.find(" - Título: ", posCpfVal);
                string cpf = linha.substr(posCpfVal, posTitulo - posCpfVal);
                
                size_t posTituloVal = posTitulo + 11;
                string titulo = linha.substr(posTituloVal);
                
                // Criar novo professor
                professor[Professores::TAMPROFESSOR] = new Professores(nome, dia, mes, ano, cpf, titulo);
                pessoa[Pessoas::TAMPES] = professor[Professores::TAMPROFESSOR];
                Professores::TAMPROFESSOR++;
                Pessoas::TAMPES++;
            }
        }
        arqProf.close();
    }
}
// Lendo pessoas do arquivo
void registrandoPessoas(Pessoas *pessoa[], Alunos *aluno[], Professores *professor[]) 
{
    // Limpar contadores estáticos
    Pessoas::TAMPES = 0;
    Alunos::TAMALUNO = 0;
    Professores::TAMPROFESSOR = 0;
    lerArquivoAlunos(aluno, pessoa);
    lerArquivoProfessores(professor, pessoa);
}
// Liberar memória
void liberarMemoria(Pessoas *pessoa[], Alunos *aluno[], Professores *professor[]) {
    for (int i = 0; i < Pessoas::TAMPES; i++) {
        delete pessoa[i];
    }
    for (int i = 0; i < Alunos::TAMALUNO; i++) {
        delete aluno[i];
    }
    for (int i = 0; i < Professores::TAMPROFESSOR; i++) {
        delete professor[i];
    }
}
