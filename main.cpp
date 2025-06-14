// Bibliotecas
#include <iostream>
#include <locale.h>
#include <fstream>
#include <cstdio>
#include <cstring>
// Definições
using namespace std;
#define _MAX 100
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
// Set dia 
void Data::setDia(int dia)
{
    this->dia= dia;
}
// Get dia
int Data::getDia()
{
    return this->dia;
}
void Data::setMes(int mes)
{
    this->mes= mes;
}
// Get mês
int Data::getMes()
{
     return this->mes;
}
void Data::setAno(int ano)
{
    this->ano= ano;
}
// Get ano
int Data::getAno()
{
     return this->ano;
}
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
int Pessoas::TAMPES=0;
// Set dia Pessoas
void Pessoas::setDia(int dia)
{
    this->dataNascimento.setDia(dia);
}
// Get dia Pessoas
int Pessoas::getDia()
{
    return this->dataNascimento.getDia();
}
// Set mês Pessoas
void Pessoas::setMes(int mes)
{
    this->dataNascimento.setMes(mes);
}
// Get mês Pessoas
int Pessoas::getMes()
{
    return this->dataNascimento.getMes();
}
// Set dia Pessoas
void Pessoas::setAno(int ano)
{
    this->dataNascimento.setAno(ano);
}
// Get ano Pessoas
int Pessoas::getAno()
{
    return this->dataNascimento.getAno();
}
// Set nome
void Pessoas::setNome(string nome)
{
    this->nome= nome;
}
// Get nome
string Pessoas::getNome()
{
    return this->nome;
}
// Set cpf
void Pessoas::setCpf(string cpf)
{
    this->cpf= cpf;
}
// Get cpf
string Pessoas::getCpf()
{
    return this->cpf;
}
// Class aluno
class Alunos:public Pessoas{
private:
    string numeroMatricula;
public:
    void setNumeroMatricula(string numeroMatricula);
    string getNumeroMatricula();
    static int TAMALUNO;
    Alunos():Pessoas()
    {
        setNumeroMatricula("");
        TAMALUNO++;
    }
    Alunos(string nome, string cpf, string numeroMatricula):Pessoas(nome, cpf)
    {
        setNumeroMatricula(numeroMatricula);
        TAMALUNO++;
    }
    Alunos(string nome, int dia, int mes, int ano, string cpf, string numeroMatricula):Pessoas(nome, dia, mes, ano, cpf)
    {
        setNumeroMatricula(numeroMatricula);
        TAMALUNO++;
    }
};
int Alunos::TAMALUNO=0;
// Set número de matrícula
void Alunos::setNumeroMatricula(string numeroMatricula)
{
    this->numeroMatricula= numeroMatricula;
}
// Get número de matrícula
string Alunos::getNumeroMatricula()
{
    return this->numeroMatricula;
}
// Class professor
class Professores:public Pessoas{
private:
    string titulacao;
public:
    static int TAMPROFESSOR;
    void setTitulacao(string titulacao);
    string getTitulacao();
    Professores():Pessoas()
    {
        setTitulacao("");
        TAMPROFESSOR++;
    }
    Professores(string nome, string cpf, string titulo):Pessoas(nome, cpf)
    {
        setTitulacao(titulo);
        TAMPROFESSOR++;
    }
    Professores(string nome, int dia, int mes, int ano, string cpf, string titulo):Pessoas(nome, dia, mes, ano, cpf)
    {
        setTitulacao(titulo);
        TAMPROFESSOR++;
    }
};
int Professores::TAMPROFESSOR=0;
// Set titulação do professor
void Professores::setTitulacao(string titulacao)
{
    this->titulacao=titulacao;
}
// Get titulação do professor
string Professores::getTitulacao()
{
    return titulacao;
}
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
        if (x >= 0 && x <= 6) erro = false;
        else cout << "\nSomente números de 0 a 6.\n\a";
    }//Fim do while
    return x;
}
// Verificando se ano é bissexto
bool ehbissexto (int ano)
{
    bool teste= false;
    if((ano%4==0 && ano%100!=0)||(ano%400==0)) teste= true;
    return teste;
}
// Validando data
bool validandoData(int dia, int mes, int ano)
{
    bool erro = false;
    bool bissexto = ehbissexto(ano);
    //Verificação do mes
    if (mes<1 || mes>12)
    {
        cout << "\nMês inválido\a";
        erro = true;
    }
    //Verificação do ano
    if (ano<=1900 || ano>2025)
    {
        cout << "\nAno inválido\a";
        erro = true;
    }
    //Verificação do dia
    if(!erro)
    {
        if ((mes==1 || mes==3 || mes==5 || mes==7 || mes==8 || mes==10 || mes==12) && (dia<1 || dia>31))
        {
            cout << "\nDia inválido\a";
            erro = true;
        }
        else if ((mes==4 || mes==6 || mes==9 || mes==11) && (dia<1 || dia>30))
        {
            cout << "\nDia inválido\a";
            erro = true;
        }
        else if (mes==2)
        {
            if ((bissexto && (dia<1 || dia>29)) || (!bissexto && (dia<1 || dia>28)))
            {
                cout << "\nDia inválido\a";
                erro = true;
            }
        }
    }
    return erro;
}
// Escrevendo aluno no arquivo
void escrevendoAlunoArquivo(Alunos *aluno)
{
    ofstream arquivo;
    if(Pessoas::TAMPES==0) arquivo.open("pessoas.txt");
    else arquivo.open("pessoas.txt", ios::app);
    arquivo << "ALUNO-> Nome: " << aluno->getNome() << " - Data de nascimento: " << aluno->getDia() <<
    "/" << aluno->getMes() << "/" << aluno->getAno() << " - CPF: " << aluno->getCpf() << " - Matrícula: " 
    << aluno->getNumeroMatricula() << endl;
    arquivo.close();  
}
// Escrevendo professor no arquivo
void escrevendoProfessorArquivo(Professores *professor)
{
    ofstream arquivo;
    if(Pessoas::TAMPES==0) arquivo.open("pessoas.txt");
    else arquivo.open("pessoas.txt", ios::app);
    arquivo << "PROFESSOR-> Nome: " << professor->getNome() << " - Data de nascimento: " << professor->getDia() <<
    "/" << professor->getMes() << "/" << professor->getAno() << " - CPF: " << professor->getCpf() << " - Matrícula: " 
    << " - Título: " << professor->getTitulacao() << endl;
    arquivo.close();  
}
// Conferindo se CPF existe
bool conferindoCpf(Pessoas *pessoa[], string cpf)
{
    for (int i=0; i<Pessoas::TAMPES; i++)
    {
        if(pessoa[i]->getCpf()==cpf) return false;
    }
    return true;
}
// Registrando CPF
string registrandoCpf(Pessoas *pessoa[])
{
    string cpf;
    bool erro=true;
    while (erro)
    {
        cout << "\nDigite seu cpf[xxx.xxx.xxx-xx]: ";
        cin.ignore();
        getline(cin, cpf);
        if(conferindoCpf(pessoa, cpf)) erro=false;
        else cout << "\nCPF já registrado\a";
    }
    return cpf;
}
// Escolha opção 1
int escolhaOpcao1()
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
// Registrando título
string registrandoTitulo()
{
    int x;
    bool erro=true;
    cout << "\nEscolhendo o título do professor:";
    while (erro)
    {
        cout << "\n1 para: Especialista";
        cout << "\n2 para: Mestre";
        cout << "\n3 para: Doutor";
        cout << "\nDigite: ";
        cin >> x;
        if(x>=1 && x<=3) erro= false;
        else cout << "\nSomente números de 1 a 3\a";
    }
    string titulo;
    switch (x)
    {
    case 1:
        titulo= "Especialista";
        break;
    case 2:
        titulo= "Mestre";
        break;
    case 3:
        titulo= "Doutor"; 
        break;
    default:
        break;
    }
    return titulo;
}
// Cadastrar professor
void cadastrarProfessor(Pessoas *pessoa[], Alunos *aluno[], Professores *professor[])
{
    string nome;
    // Nome
    cout << "\n\nDigite seu nome: ";
    cin.ignore();
    getline(cin, nome);
    // CPF
    string cpf= registrandoCpf(pessoa);
    // Data
    int dia, mes, ano;
    bool erro = true;
    while (erro)
    {
        cout << "\nDigite sua data de nascimento[xx/xx/xxxx]: ";
        scanf("%d/%d/%d", &dia, &mes, &ano);
        if (!validandoData(dia, mes, ano)) erro = false;
    }
    // Título
    string titulo= registrandoTitulo();
    // Adicionando
    int x = Professores::TAMPROFESSOR;
    professor[x] = new Professores(nome, dia, mes, ano, cpf, titulo);
    escrevendoProfessorArquivo(professor[x]);
    // Mensagens
    cout << "\nPessoa cadastrada com sucesso!";
    cout << endl << "Total de pessoas: " << Pessoas::TAMPES;
    cout << endl << "Total de professores: " << Professores::TAMPROFESSOR;
    cout << endl << "Total de alunos: " << Alunos::TAMALUNO;
}
// Conferindo matrícula
bool conferinfoMatricula(string matricula, Alunos *aluno[])
{
    for (int i=0; i<Alunos::TAMALUNO; i++)
    {
       if(aluno[i]->getNumeroMatricula()==matricula) return false; 
    }
    return true;
}
// Registrando matrícula
string registrandoMatricula(Alunos *aluno[])
{
    string matricula;
    bool erro= true;
    while(erro)
    {
        cout << "\nDigite seu número de matrícula: ";
        cin.ignore();
        getline(cin, matricula);
        if(conferinfoMatricula(matricula, aluno)) erro= false;
        else cout << "\nEsse número de matrícula já está cadastrado";
    }
    return matricula;
}
// Cadastrar alunos
void cadastrarAluno(Pessoas *pessoa[], Alunos *aluno[], Professores *professor[])
{
    string nome;
    // Nome
    cout << "\n\nDigite seu nome: ";
    cin.ignore();
    getline(cin, nome);
    // CPF
    string cpf= registrandoCpf(pessoa);
    // Data
    int dia, mes, ano;
    bool erro = true;
    while (erro)
    {
        cout << "\nDigite sua data de nascimento[xx/xx/xxxx]: ";
        scanf("%d/%d/%d", &dia, &mes, &ano);
        if (!validandoData(dia, mes, ano)) erro = false;
    }
    // Matrícula
    string matricula= registrandoMatricula(aluno);
    // Adicionando
    int x = Alunos::TAMALUNO;
    aluno[x] = new Alunos(nome, dia, mes, ano, cpf, matricula);
    escrevendoAlunoArquivo(aluno[x]);
    // Mensagens
    cout << "\nPessoa cadastrada com sucesso!";
    cout << endl << "Total de pessoas: " << Pessoas::TAMPES;
    cout << endl << "Total de professores: " << Professores::TAMPROFESSOR;
    cout << endl << "Total de alunos: " << Alunos::TAMALUNO;
}
// Opções opção 1
void opcoesOpcao1(int x, Pessoas *pessoa[], Alunos *aluno[], Professores *professor[])
{
    switch (x)
    {
    case 0:
        break;
    case 1:
        cadastrarProfessor(pessoa, aluno, professor);
        break;
    case 2:
        cadastrarAluno(pessoa, aluno, professor);
        break;
    default:
        break;
    }
}
// Opção 1
void opcao1(Pessoas *pessoa[], Alunos *aluno[], Professores *professor[])
{
    cout << "\n\n1.0 – Voltar ao menu anterior[0]";
    cout << "\n\n1.1 - Cadastrar rofessor[1]";
    cout << "\n\n1.2 - Cadastrar Aluno[2]";
    int x= escolhaOpcao1();
    opcoesOpcao1(x, pessoa, aluno, professor);
}
// Opção 2
void opcao2()
{
    cout << "\n\nLista das pessoas cadastradas: ";
    if(Pessoas::TAMPES>0)
    {
        ifstream arquivo;
        arquivo.open("pessoas.txt");
        string linha;
        while (getline(arquivo, linha))
        {
           cout << endl << linha;
        }
        cout << endl << "Total de pessoas: " << Pessoas::TAMPES;
    }
    else cout << "\nNão há nenhuma pessoa cadastrada";
}
// Opção 3
void opcao3(Pessoas *pessoa[])
{
    cout << "\n\nPesquisa por nome";
    string nome;
    cout << "\nDigite o nome que deseja procurar: ";
    cin.ignore();
    getline(cin, nome);
    bool achou= false;
    for (int i=0; i<Pessoas::TAMPES; i++)
    {
        if(nome==pessoa[i]->getNome()) 
        {
            cout << "Nome: " << pessoa[i]->getNome() << " - Data de nascimento: " << pessoa[i]->getDia() <<
            "/" << pessoa[i]->getMes() << "/" << pessoa[i]->getAno() << " - CPF: " << pessoa[i]->getCpf() << endl;
            achou=true;
        }
    }
    if(!achou) cout << "\nNão existe ninguém com esse nome";
}
// Opção 4
void opcao4(Pessoas *pessoa[])
{
    cout << "\n\nPesquisa por cpf";
    string cpf;
    cout << "\nDigite o CPF que deseja procurar: ";
    cin.ignore();
    getline(cin, cpf);
    bool achou= false;
    for (int i=0; i<Pessoas::TAMPES; i++)
    {
        if(cpf==pessoa[i]->getCpf()) 
        {
            cout << "Nome: " << pessoa[i]->getNome() << " - Data de nascimento: " << pessoa[i]->getDia() <<
            "/" << pessoa[i]->getMes() << "/" << pessoa[i]->getAno() << " - CPF: " << pessoa[i]->getCpf() << endl;
            achou=true;
        }
    }
    if(!achou) cout << "\nNão existe ninguém com esse CPF";
}
// Conferindo existência da pessoa
bool pessquisaCpf(string cpf, Pessoas *pessoa[])
{
    for(int i=0; i<Pessoas::TAMPES; i++)
    {
        if (pessoa[i]->getCpf() ==cpf) return true;
    }
    return false;
}
// Encontrando a posição da pessoa 
int posicao(string cpf, Pessoas *pessoa[])
{
    for(int i=0; i<Pessoas::TAMPES; i++)
    {
        if (pessoa[i]->getCpf() ==cpf) return i;
    }
}
// Excluindo uma pessoa
int excluindoPessoa(Pessoas *pessoa[], int x)
{
    for (int i=x; i<Pessoas::TAMPES; i++)
    {
        pessoa[i]->setNome(pessoa[i+1]->getNome());
        pessoa[i]->setDia(pessoa[i+1]->getDia());
        pessoa[i]->setMes(pessoa[i+1]->getMes());
        pessoa[i]->setAno(pessoa[i+1]->getAno());
        pessoa[i]->setCpf(pessoa[i+1]->getCpf());
    }
    delete(pessoa[Pessoas::TAMPES-1]);
}
// Apagando pessoas do arquivo
void apagandoPessoasArquivo()
{
    ofstream arquivo;
    arquivo.open("pessoas.txt");
    arquivo.close();
}
// Reescrevendo no arquivo
void reescrevendoArquivo(Pessoas *pessoa[])
{
    ofstream arquivo;
    arquivo.open("pessoas.txt", ios::app);
    for (int i=0; i<Pessoas::TAMPES; i++)
    {
        arquivo << "Nome: " << pessoa[i]->getNome() << " - Data de nascimento: " << pessoa[i]->getDia() <<
        "/" << pessoa[i]->getMes() << "/" << pessoa[i]->getAno() << " - CPF: " << pessoa[i]->getCpf() << endl;
    }
    arquivo.close();
}
// Opção 5
void opcao5(Pessoas *pessoa[])
{
    cout << "\n\nExcluir uma pessoa";
    string cpf;
    cout << "\nDigite o CPF da pessoa que deseja excluir[0 para sair]: ";
    cin >> cpf;
    if(cpf=="0") return; 
    if(pessquisaCpf(cpf, pessoa))
    {
        string teste;
        cout << "Tem certeza que deseja excluir " << cpf << " ?[S/N]";
        cin >> teste;
        if(teste=="S" || teste=="s")
        {
            int x= posicao(cpf, pessoa);
            excluindoPessoa(pessoa, x);
            apagandoPessoasArquivo();
            reescrevendoArquivo(pessoa);
        }

     }
    else cout << "Não existe ninguém com esse CPF, confira se digitou certo";
    
}
// Opção 6
void opcao6(Pessoas *pessoa[], Alunos *aluno[], Professores *professor[])
{
    ofstream arquivo;
    arquivo.open("pessoas.txt");
    arquivo.close();
    for(int i=0; i<Pessoas::TAMPES; i++)
    {
        delete(pessoa[i]);
    }
    for(int i=0; i<Alunos::TAMPES; i++)
    {
        delete(aluno[i]);
    }
    for(int i=0; i<Professores::TAMPES; i++)
    {
        delete(professor[i]);
    }
    cout << "\n\nPessoas apagadas com sucesso";
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
        opcao3(pessoa);
        break;
    case 4:
        opcao4(pessoa);
        break;
    case 5:
        opcao5(pessoa);
        break;
    case 6:
        opcao6(pessoa, aluno, professor);
        break;
    default:
        break;
    }
}// Lendo pessoas do arquivo
void registrandoPessoas(Pessoas *pessoa[])
{
    ifstream arquivo("pessoas.txt");
    if (!arquivo.is_open())
    {
        cout << "Arquivo de pessoas não encontrado. Nenhum dado carregado.\n";
        return;
    }
    string linha;
    char nomeTemp[100], cpfTemp[50];
    int dia, mes, ano;
    while (getline(arquivo, linha))
    {
        if (sscanf(linha.c_str(), 
            "Nome: %[^-] - Data de nascimento: %d/%d/%d - CPF: %[^\n]",
            nomeTemp, &dia, &mes, &ano, cpfTemp) == 5)
        {
            int len = strlen(nomeTemp);
            while (len > 0 && nomeTemp[len-1] == ' ') {
                nomeTemp[len-1] = '\0';
                len--;
            }
            pessoa[Pessoas::TAMPES] = new Pessoas(string(nomeTemp), dia, mes, ano, string(cpfTemp));
            if (Pessoas::TAMPES >= _MAX) break; // evitar overflow do array
        }
        else
        {
            cout << "Linha mal formatada ignorada: " << linha << endl;
        }
    }
    arquivo.close();
}
//Main
int main ()
{
    setlocale(LC_ALL, "Portuguese");
    system("chcp 65001 > nul");
    Pessoas *pessoa[_MAX];
    Alunos *aluno[_MAX];
    Professores *professor[_MAX];
    registrandoPessoas(pessoa);
    instrcoes();
    int x= escolha();
    cout << "\n\nBem-vindo, siga as instruções: ";
    while (x!=0)
    {
        opcoes(x, pessoa, aluno, professor);
        instrcoes();
        x= escolha();
    }
    fechamento ();
    return 0;
}