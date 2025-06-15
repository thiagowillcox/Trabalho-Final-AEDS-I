// Bibliotecas
#include <iostream>
#include <locale.h>
#include <fstream>
#include <cstdio>
#include <cstring>
#include <ctime>
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
    Data(){
        setDia(0);
        setMes(0);
        setAno(0);
    }
    Data(int ano){
        setDia(0);
        setMes(0); 
        setAno(ano);
    }
    Data(int dia,int mes,int ano){
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
void Data::setDia(int dia){
    this->dia=dia;
}
// Get dia
int Data::getDia(){
    return this->dia;
}
void Data::setMes(int mes){
    this->mes=mes;
}
// Get mês
int Data::getMes(){
     return this->mes;
}
void Data::setAno(int ano){
    this->ano=ano;
}
// Get ano
int Data::getAno(){
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
    Pessoas(){
        setNome("");
        this->dataNascimento=Data();
        setCpf("");
        TAMPES++;
    }
    Pessoas(string nome,string cpf){
        setNome(nome);
        this->dataNascimento=Data();
        setCpf(cpf);
        TAMPES++;
    }
    Pessoas(string nome,int dia,int mes,int ano,string cpf){
        setNome(nome);
        this->dataNascimento=Data(dia,mes,ano);
        setCpf(cpf);
        TAMPES++;
    }
    ~Pessoas(){
        if(Pessoas::TAMPES>0)Pessoas::TAMPES--;
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
void Pessoas::setDia(int dia){
    this->dataNascimento.setDia(dia);
}
// Get dia Pessoas
int Pessoas::getDia(){
    return this->dataNascimento.getDia();
}
// Set mês Pessoas
void Pessoas::setMes(int mes){
    this->dataNascimento.setMes(mes);
}
// Get mês Pessoas
int Pessoas::getMes(){
    return this->dataNascimento.getMes();
}
// Set dia Pessoas
void Pessoas::setAno(int ano){
    this->dataNascimento.setAno(ano);
}
// Get ano Pessoas
int Pessoas::getAno(){
    return this->dataNascimento.getAno();
}
// Set nome
void Pessoas::setNome(string nome){
    this->nome=nome;
}
// Get nome
string Pessoas::getNome(){
    return this->nome;
}
// Set cpf
void Pessoas::setCpf(string cpf){
    this->cpf=cpf;
}
// Get cpf
string Pessoas::getCpf(){
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
    Alunos():Pessoas(){
        setNumeroMatricula("");
        TAMALUNO++;
    }
    Alunos(string nome,string cpf,string numeroMatricula):Pessoas(nome,cpf){
        setNumeroMatricula(numeroMatricula);
        TAMALUNO++;
    }
    Alunos(string nome,int dia,int mes,int ano,string cpf,string numeroMatricula):Pessoas(nome,dia,mes,ano,cpf){
        setNumeroMatricula(numeroMatricula);
        TAMALUNO++;
    }
    ~Alunos(){
        if(Alunos::TAMALUNO>0)Alunos::TAMALUNO--;
    }
};
int Alunos::TAMALUNO=0;
// Set número de matrícula
void Alunos::setNumeroMatricula(string numeroMatricula){
    this->numeroMatricula=numeroMatricula;
}
// Get número de matrícula
string Alunos::getNumeroMatricula(){
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
    Professores():Pessoas(){
        setTitulacao("");
        TAMPROFESSOR++;
    }
    Professores(string nome,string cpf,string titulo):Pessoas(nome,cpf){
        setTitulacao(titulo);
        TAMPROFESSOR++;
    }
    Professores(string nome,int dia,int mes,int ano,string cpf,string titulo):Pessoas(nome,dia,mes,ano,cpf){
        setTitulacao(titulo);
        TAMPROFESSOR++;
    }
    ~Professores(){
        if(Professores::TAMPROFESSOR>0)Professores::TAMPROFESSOR--;
    }
};
int Professores::TAMPROFESSOR=0;
// Set titulação do professor
void Professores::setTitulacao(string titulacao){
    this->titulacao=titulacao;
}
// Get titulação do professor
string Professores::getTitulacao(){
    return titulacao;
}

// Escrita das opções
void instrcoes(){
    cout<<"\n\n0 - Sair do programa";
    cout<<"\n1 - Cadastrar uma pessoa";
    cout<<"\n2 - Listar todas as pessoas cadastradas";
    cout<<"\n3 - Pesquisar por nome";
    cout<<"\n4 - Pesquisar por CPF";
    cout<<"\n5 - Excluir pessoa";
    cout<<"\n6 - Apagar todas as pessoas cadastradas";
}
// Mensagem de fechamento
void fechamento(){
    cout<<"\n\nObrigado por usar o programa, volte quando precisar!";
}
// Escolha da opção
int escolha(){
    int x;
    bool erro=true;
    while(erro){
        cout<<"\n\nDigite o que deseja: ";
        cin>>x;
        if(x>=0&&x<=7)erro=false;
        else cout<<"\nSomente números de 0 a 7.\n\a";
    }
    return x;
}

// Verificando se ano é bissexto
bool ehbissexto(int ano){
    bool teste=false;
    if((ano%4==0&&ano%100!=0)||(ano%400==0))teste=true;
    return teste;
}
// Validando data
bool validandoData(int dia,int mes,int ano){
    bool erro=false;
    bool bissexto=ehbissexto(ano);
    //Verificação do mes
    if(mes<1||mes>12){
        cout<<"\nMês inválido\a";
        erro=true;
    }
    //Verificação do ano
    time_t t=time(NULL);
    tm*timePtr=localtime(&t);
    int anoAtual=timePtr->tm_year+1900;
    if(ano<=1900||ano>anoAtual){
        cout<<"\nAno inválido\a";
        erro=true;
    }
    //Verificação do dia
    if(!erro){
        if((mes==1||mes==3||mes==5||mes==7||mes==8||mes==10||mes==12)&&(dia<1||dia>31)){
            cout<<"\nDia inválido\a";
            erro=true;
        }
        else if((mes==4||mes==6||mes==9||mes==11)&&(dia<1||dia>30)){
            cout<<"\nDia inválido\a";
            erro=true;
        }
        else if(mes==2){
            if((bissexto&&(dia<1||dia>29))||(!bissexto&&(dia<1||dia>28))){
                cout<<"\nDia inválido\a";
                erro=true;
            }
        }
    }
    return erro;
}
// Escrevendo aluno no arquivo
void escrevendoAlunoArquivo(Alunos*aluno){
    ofstream arquivo;
    arquivo.open("alunos.txt",ios::app);
    if(arquivo.is_open()){
        arquivo<<"ALUNO-> Nome: "<<aluno->getNome()<<" - Data de nascimento: "<<aluno->getDia()<<
        "/"<<aluno->getMes()<<"/"<<aluno->getAno()<<" - CPF: "<<aluno->getCpf()<<" - Matrícula: " 
        <<aluno->getNumeroMatricula()<<endl;
        arquivo.close();
    }
}
// Escrevendo professor no arquivo
void escrevendoProfessorArquivo(Professores*professor){
    ofstream arquivo;
    arquivo.open("professores.txt",ios::app);
    if(arquivo.is_open()){
        arquivo<<"PROFESSOR-> Nome: "<<professor->getNome()<<" - Data de nascimento: "<<professor->getDia()<<
        "/"<<professor->getMes()<<"/"<<professor->getAno()<<" - CPF: "<<professor->getCpf()
        <<" - Título: "<<professor->getTitulacao()<<endl;
        arquivo.close();
    }
}
// Conferindo se CPF existe
bool conferindoCpf(Pessoas*pessoa[],string cpf){
    for(int i=0;i<Pessoas::TAMPES;i++){
        if(pessoa[i]->getCpf()==cpf)return false;
    }
    return true;
}
// Validando formato do CPF
bool validarFormatoCPF(string cpf){
    if(cpf.length()!=14)return false;
    if(cpf[3]!='.'||cpf[7]!='.'||cpf[11]!='-')return false;
    return true;
}
// Registrando CPF
string registrandoCpf(Pessoas*pessoa[]){
    string cpf;
    bool erro=true;
    while(erro){
        cout<<"\nDigite seu cpf[xxx.xxx.xxx-xx]: ";
        cin.ignore();
        getline(cin,cpf);
        if(!validarFormatoCPF(cpf)){
            cout<<"\nFormato de CPF inválido\a";
            continue;
        }
        if(conferindoCpf(pessoa,cpf))erro=false;
        else cout<<"\nCPF já registrado\a";
    }
    return cpf;
}
// Escolha opção 1
int escolhaOpcao1(){
    int x;
    bool erro=true;
    while(erro){
        cout<<"\n\nDigite o que deseja: ";
        cin>>x;
        if(x>=0&&x<=2)erro=false;
        else cout<<"Somente números de 0 a 2\a";
    }
    return x;
}
// Registrando título
string registrandoTitulo(){
    int x;
    bool erro=true;
    cout<<"\nEscolhendo o título do professor:";
    while(erro){
        cout<<"\n1 para: Especialista";
        cout<<"\n2 para: Mestre";
        cout<<"\n3 para: Doutor";
        cout<<"\nDigite: ";
        cin>>x;
        if(x>=1&&x<=3)erro=false;
        else cout<<"\nSomente números de 1 a 3\a";
    }
    string titulo;
    switch(x){
    case 1:
        titulo="Especialista";
        break;
    case 2:
        titulo="Mestre";
        break;
    case 3:
        titulo="Doutor"; 
        break;
    default:
        break;
    }
    return titulo;
}
// Cadastrar professor
void cadastrarProfessor(Pessoas*pessoa[],Alunos*aluno[],Professores*professor[]){
    string nome;
    // Nome
    cout<<"\n\nDigite seu nome: ";
    cin.ignore();
    getline(cin,nome);
    // CPF
    string cpf=registrandoCpf(pessoa);
    // Data
    int dia,mes,ano;
    bool erro=true;
    while(erro){
        cout<<"\nDigite sua data de nascimento[xx/xx/xxxx]: ";
        scanf("%d/%d/%d",&dia,&mes,&ano);
        if(!validandoData(dia,mes,ano))erro=false;
    }
    // Título
    string titulo=registrandoTitulo();
    // Adicionando
    int x=Professores::TAMPROFESSOR;
    professor[x]=new Professores(nome,dia,mes,ano,cpf,titulo);
    pessoa[Pessoas::TAMPES]=professor[x];
    escrevendoProfessorArquivo(professor[x]);
    // Mensagens
    cout<<"\nPessoa cadastrada com sucesso!";
    cout<<endl<<"Total de pessoas: "<<Pessoas::TAMPES;
    cout<<endl<<"Total de professores: "<<Professores::TAMPROFESSOR;
    cout<<endl<<"Total de alunos: "<<Alunos::TAMALUNO;
}
// Conferindo matrícula
bool conferinfoMatricula(string matricula,Alunos*aluno[]){
    for(int i=0;i<Alunos::TAMALUNO;i++){
       if(aluno[i]->getNumeroMatricula()==matricula)return false; 
    }
    return true;
}
// Registrando matrícula
string registrandoMatricula(Alunos*aluno[]){
    string matricula;
    bool erro=true;
    while(erro){
        cout<<"\nDigite seu número de matrícula: ";
        cin.ignore();
        getline(cin,matricula);
        if(conferinfoMatricula(matricula,aluno))erro=false;
        else cout<<"\nEsse número de matrícula já está cadastrado";
    }
    return matricula;
}
// Cadastrar alunos
void cadastrarAluno(Pessoas*pessoa[],Alunos*aluno[],Professores*professor[]){
    string nome;
    // Nome
    cout<<"\n\nDigite seu nome: ";
    cin.ignore();
    getline(cin,nome);
    // CPF
    string cpf=registrandoCpf(pessoa);
    // Data
    int dia,mes,ano;
    bool erro=true;
    while(erro){
        cout<<"\nDigite sua data de nascimento[xx/xx/xxxx]: ";
        scanf("%d/%d/%d",&dia,&mes,&ano);
        if(!validandoData(dia,mes,ano))erro=false;
    }
    // Matrícula
    string matricula=registrandoMatricula(aluno);
    // Adicionando
    int x=Alunos::TAMALUNO;
    aluno[x]=new Alunos(nome,dia,mes,ano,cpf,matricula);
    pessoa[Pessoas::TAMPES]=aluno[x];
    escrevendoAlunoArquivo(aluno[x]);
    // Mensagens
    cout<<"\nPessoa cadastrada com sucesso!";
    cout<<endl<<"Total de pessoas: "<<Pessoas::TAMPES;
    cout<<endl<<"Total de professores: "<<Professores::TAMPROFESSOR;
    cout<<endl<<"Total de alunos: "<<Alunos::TAMALUNO;
}
// Opções opção 1
void opcoesOpcao1(int x,Pessoas*pessoa[],Alunos*aluno[],Professores*professor[]){
    switch(x){
    case 0:
        break;
    case 1:
        cadastrarProfessor(pessoa,aluno,professor);
        break;
    case 2:
        cadastrarAluno(pessoa,aluno,professor);
        break;
    default:
        break;
    }
}
// Opção 1
void opcao1(Pessoas*pessoa[],Alunos*aluno[],Professores*professor[]){
    cout<<"\n\n1.0 – Voltar ao menu anterior[0]";
    cout<<"\n1.1 - Cadastrar Professor[1]";
    cout<<"\n1.2 - Cadastrar Aluno[2]";
    int x=escolhaOpcao1();
    opcoesOpcao1(x,pessoa,aluno,professor);
}

// Escolha opção 2
int escolhaOpcao2(){
    int x;
    bool erro=true;
    while(erro){
        cout<<"\n\nDigite o que deseja: ";
        cin>>x;
        if(x>=0&&x<=2)erro=false;
        else cout<<"Somente números de 0 a 2\a";
    }
    return x;
}
// Listar professores
void listarProfessores(Professores*professor[]){
    ifstream arquivo("professores.txt");
    if(!arquivo.is_open()){
        cout<<"Arquivo de professores não encontrado. Nenhum dado carregado.\n";
        return;
    }
    string linha;
    if(Professores::TAMPROFESSOR!=0){
        cout<<"\n\nLista de professores cadastrados: ";
        while(getline(arquivo,linha)){
            cout<<endl<<linha;
        }
            cout<<"\nTotal de professores: "<<Professores::TAMPROFESSOR;
    }
    else cout<<"\nNão há nenhum professor cadastrado";  
    arquivo.close();
}
// Listar alunos
void listarAluno(Alunos*aluno[]){    
    ifstream arquivo("alunos.txt");
    if(!arquivo.is_open()){
        cout<<"Arquivo de alunos não encontrado. Nenhum dado carregado.\n";
        return;
    }
    string linha;
    if(Alunos::TAMALUNO!=0){
        cout<<"\n\nLista de alunos cadastrados: ";
        while(getline(arquivo,linha)){
            cout<<endl<<linha;
        }
            cout<<"\nTotal de alunos: "<<Alunos::TAMALUNO;
    }
    else cout<<"\nNão há nenhum anluno cadastrado";  
    arquivo.close();
}
// Opções opção 2
void opcoesOpcao2(int x,Alunos*aluno[],Professores*professor[]){
    switch(x){
    case 0:
        break;
    case 1:
        listarProfessores(professor);
        break;
    case 2:
        listarAluno(aluno);
        break;
    default:
        break;
    }
}
// Opção 2
void opcao2(Alunos*aluno[],Professores*professor[]){
    cout<<"\n\n2.0 – Voltar ao menu anterior[0]";
    cout<<"\n2.1 - Listar Professores[1]";
    cout<<"\n2.2 - Listar Alunos[2]";
    int x=escolhaOpcao2();
    opcoesOpcao2(x,aluno,professor);
}

// Pesquisar Professor por nome
void pesquisarProfessorNome(Professores*professor[]){
    cout<<"\n\nPesquisar professor por nome";
    string nome;
    cout<<"\nDigite o nome do professor que deseja procurar: ";
    cin.ignore();
    getline(cin,nome);
    bool achou=false;
    for(int i=0;i<Professores::TAMPROFESSOR;i++){
        if(nome==professor[i]->getNome()){
            cout<<"Nome: "<<professor[i]->getNome()<<" - Data de nascimento: "<<professor[i]->getDia()<<
            "/"<<professor[i]->getMes()<<"/"<<professor[i]->getAno()<<" - CPF: "<<professor[i]->getCpf()  
            <<" - Título: "<<professor[i]->getTitulacao()<<endl;
            achou=true;
        }
    }
    if(!achou)cout<<"\nNão existe ninguém com esse nome";
}
// Pesquisar Aluno por nome
void pesquisarAlunoNome(Alunos*aluno[]){
    cout<<"\n\nPesquisar aluno por nome";
    string nome;
    cout<<"\nDigite o nome do aluno que deseja procurar: ";
    cin.ignore();
    getline(cin,nome);
    bool achou=false;
    for(int i=0;i<Alunos::TAMALUNO;i++){
        if(nome==aluno[i]->getNome()){
            cout<<"Nome: "<<aluno[i]->getNome()<<" - Data de nascimento: "<<aluno[i]->getDia()<<
            "/"<<aluno[i]->getMes()<<"/"<<aluno[i]->getAno()<<" - CPF: "<<aluno[i]->getCpf()<<" - Matrícula: " 
            <<aluno[i]->getNumeroMatricula()<<endl;
            achou=true;
        }
    }
    if(!achou)cout<<"\nNão existe ninguém com esse nome";
}
// Opções opção 3
void opcoesOpcao3(int x,Alunos*aluno[],Professores*professor[]){
    switch(x){
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
int escolhaOpcao3(){
    int x;
    bool erro=true;
    while(erro){
        cout<<"\n\nDigite o que deseja: ";
        cin>>x;
        if(x>=0&&x<=2)erro=false;
        else cout<<"Somente números de 0 a 2\a";
    }
    return x;
}
// Opção 3
void opcao3(Alunos*aluno[],Professores*professor[]){
    cout<<"\n\n3.0 – Voltar ao menu anterior[0]";
    cout<<"\n3.1 - Pesquisar Professores por nome[1]";
    cout<<"\n3.2 - Pesquisar Alunos por nome[2]";
    int x=escolhaOpcao3();
    opcoesOpcao3(x,aluno,professor);
}

// Pesquisar Professor por CPF
void pesquisarProfessorCPF(Professores*professor[]){
    cout<<"\n\nPesquisar professor por CPF";
    string cpf;
    cout<<"\nDigite o CPF que deseja procurar: ";
    cin.ignore();
    getline(cin,cpf);
    bool achou=false;
    for(int i=0;i<Professores::TAMPROFESSOR;i++){
        if(cpf==professor[i]->getCpf()){
            cout<<"Nome: "<<professor[i]->getNome()<<" - Data de nascimento: "<<professor[i]->getDia()<<
            "/"<<professor[i]->getMes()<<"/"<<professor[i]->getAno()<<" - CPF: "<<professor[i]->getCpf()  
            <<" - Título: "<<professor[i]->getTitulacao()<<endl;
            achou=true;
            return;
        }
    }
    if(!achou)cout<<"\nNão existe ninguém com esse CPF, verifique se digitou corretamente";
}
// Pesquisar Aluno por CPF
void pesquisarAlunoCPF(Alunos*aluno[]){
    cout<<"\n\nPesquisar aluno por CPF";
    string cpf;
    cout<<"\nDigite o CPF que deseja procurar: ";
    cin.ignore();
    getline(cin,cpf);
    bool achou=false;
    for(int i=0;i<Alunos::TAMALUNO;i++){
        if(cpf==aluno[i]->getCpf()){
            cout<<"Nome: "<<aluno[i]->getNome()<<" - Data de nascimento: "<<aluno[i]->getDia()<<
            "/"<<aluno[i]->getMes()<<"/"<<aluno[i]->getAno()<<" - CPF: "<<aluno[i]->getCpf()<<" - Matrícula: " 
            <<aluno[i]->getNumeroMatricula()<<endl;
            achou=true;
            return;
        }
    }
    if(!achou)cout<<"\nNão existe ninguém com esse CPF, verifique se digitou corretamente";
}
// Opções opção 4
void opcoesOpcao4(int x,Alunos*aluno[],Professores*professor[]){
    switch(x){
    case 0:
        break;
    case 1:
        pesquisarProfessorCPF(professor);
        break;
    case 2:
        pesquisarAlunoCPF(aluno);
        break;
    default:
        break;
    }
}
// Escolha opção 4
int escolhaOpcao4(){
    int x;
    bool erro=true;
    while(erro){
        cout<<"\n\nDigite o que deseja: ";
        cin>>x;
        if(x>=0&&x<=2)erro=false;
        else cout<<"Somente números de 0 a 2\a";
    }
    return x;
}
// Opção 4
void opcao4(Alunos*aluno[],Professores*professor[]){
    cout<<"\n\n4.0 – Voltar ao menu anterior[0]";
    cout<<"\n4.1 - Pesquisar Professores por CPF[1]";
    cout<<"\n4.2 - Pesquisar Alunos por CPF[2]";
    int x=escolhaOpcao4();
    opcoesOpcao4(x,aluno,professor);
}

// Pesquisa CPF do professor
bool pessquisaCpfProfessor(string cpf,Professores*professor[]){
    for(int i=0;i<Professores::TAMPROFESSOR;i++){
        if(professor[i]->getCpf()==cpf)return true;
    }
    return false;
}
// Encontrando a posição do professor 
int posicaoProfessor(string cpf,Professores*professor[]){
    for(int i=0;i<Professores::TAMPROFESSOR;i++){
        if(professor[i]->getCpf()==cpf)return i;
    }
    return -1;
}
// Excluindo o professor
void excluindoProfessor(Professores*professor[],int x){
    for(int i=x;i<Professores::TAMPROFESSOR-1;i++){
        professor[i]=professor[i+1];
    }
    delete professor[Professores::TAMPROFESSOR-1];
    Professores::TAMPROFESSOR--;
}
// Apagando professor do arquivo
void apagandoProfessoresArquivo(){
    ofstream arquivo;
    arquivo.open("professores.txt",ios::trunc);
    arquivo.close();
}
// Reescrevendo no arquivo de professores
void reescrevendoArquivoProfessor(Professores*professor[]){
    ofstream arquivo;
    arquivo.open("professores.txt",ios::app);
    for(int i=0;i<Professores::TAMPROFESSOR;i++){
        arquivo<<"PROFESSOR-> Nome: "<<professor[i]->getNome()<<" - Data de nascimento: "<<professor[i]->getDia()<<
        "/"<<professor[i]->getMes()<<"/"<<professor[i]->getAno()<<" - CPF: "<<professor[i]->getCpf()
        <<" - Título: "<<professor[i]->getTitulacao()<<endl;
    }
    arquivo.close();
}
// Excluir professor
void excluirProfessor(Professores*professor[]){
    cout<<"\n\nExcluir um professor";
    string cpf;
    cout<<"\nDigite o CPF do professor que deseja excluir[0 para sair]: ";
    cin>>cpf;
    if(cpf=="0")return; 
    if(pessquisaCpfProfessor(cpf,professor)){
        string teste;
        cout<<"Tem certeza que deseja excluir "<<cpf<<" ?[S/N]";
        cin>>teste;
        if(teste=="S"||teste=="s"){
            int x=posicaoProfessor(cpf,professor);
            if(x!=-1){
                excluindoProfessor(professor,x);
                apagandoProfessoresArquivo();
                reescrevendoArquivoProfessor(professor);
                cout<<"\nProfessor excluído com sucesso!";
            }
        }
     }
    else cout<<"Não existe ninguém com esse CPF, confira se digitou certo";
}
// Pesquisa CPF do aluno
bool pessquisaCpfAluno(string cpf,Alunos*aluno[]){
    for(int i=0;i<Alunos::TAMALUNO;i++){
        if(aluno[i]->getCpf()==cpf)return true;
    }
    return false;
}
// Encontrando a posição do aluno 
int posicaoAluno(string cpf,Alunos*aluno[]){
    for(int i=0;i<Alunos::TAMALUNO;i++){
        if(aluno[i]->getCpf()==cpf)return i;
    }
    return -1;
}
// Excluindo o aluno
void excluindoAluno(Alunos*aluno[],int x){
    for(int i=x;i<Alunos::TAMALUNO-1;i++){
        aluno[i]=aluno[i+1];
    }
    delete aluno[Alunos::TAMALUNO-1];
    Alunos::TAMALUNO--;
}
// Apagando aluno do arquivo
void apagandoAlunosArquivo(){
    ofstream arquivo;
    arquivo.open("alunos.txt",ios::trunc);
    arquivo.close();
}
// Reescrevendo no arquivo de alunos
void reescrevendoArquivoAluno(Alunos*aluno[]){
    ofstream arquivo;
    arquivo.open("alunos.txt",ios::app);
    for(int i=0;i<Alunos::TAMALUNO;i++){
        arquivo<<"ALUNO-> Nome: "<<aluno[i]->getNome()<<" - Data de nascimento: "<<aluno[i]->getDia()<<
        "/"<<aluno[i]->getMes()<<"/"<<aluno[i]->getAno()<<" - CPF: "<<aluno[i]->getCpf()
        <<" - Matrícula: "<<aluno[i]->getNumeroMatricula()<<endl;
    }
    arquivo.close();
}
// Excluir aluno
void excluirAluno(Alunos*aluno[]){
    cout<<"\n\nExcluir um aluno";
    string cpf;
    cout<<"\nDigite o CPF do aluno que deseja excluir[0 para sair]: ";
    cin>>cpf;
    if(cpf=="0")return; 
    if(pessquisaCpfAluno(cpf,aluno)){
        string teste;
        cout<<"Tem certeza que deseja excluir "<<cpf<<" ?[S/N]";
        cin>>teste;
        if(teste=="S"||teste=="s"){
            int x=posicaoAluno(cpf,aluno);
            if(x!=-1){
                excluindoAluno(aluno,x);
                apagandoAlunosArquivo();
                reescrevendoArquivoAluno(aluno);
                cout<<"\nAluno excluído com sucesso!";
            }
        }
     }
    else cout<<"Não existe ninguém com esse CPF, confira se digitou certo";
}
// Opções opção 5
void opcoesOpcao5(int x,Alunos*aluno[],Professores*professor[]){
    switch(x){
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
int escolhaOpcao5(){
    int x;
    bool erro=true;
    while(erro){
        cout<<"\n\nDigite o que deseja: ";
        cin>>x;
        if(x>=0&&x<=2)erro=false;
        else cout<<"Somente números de 0 a 2\a";
    }
    return x;
}
// Opção 5
void opcao5(Alunos*aluno[],Professores*professor[]){
    cout<<"\n\n5.0 – Voltar ao menu anterior[0]";
    cout<<"\n5.1 - Excluir professor pelo CPF[1]";
    cout<<"\n5.2 - Excluir aluno pelo CPF[2]";
    int x=escolhaOpcao5();
    opcoesOpcao5(x,aluno,professor);
}

// Deletar todos os professores
void deletarTodosProfessores(Professores*professor[]){
    ofstream arquivo;
    arquivo.open("professores.txt",ios::trunc);
    arquivo.close();
    for(int i=0;i<Professores::TAMPROFESSOR;i++){
        delete professor[i];
    }
    Professores::TAMPROFESSOR=0;
    cout<<"\n\nTodos os professores foram apagados com sucesso";
}
// Deletar todos os alunos
void deletarTodosAlunos(Alunos*aluno[]){
    ofstream arquivo;
    arquivo.open("alunos.txt",ios::trunc);
    arquivo.close();
    for(int i=0;i<Alunos::TAMALUNO;i++){
        delete aluno[i];
    }
    Alunos::TAMALUNO=0;
    cout<<"\n\nTodos os alunos foram apagados com sucesso";
}
// Opções opção 6
void opcoesOpcao6(int x,Alunos*aluno[],Professores*professor[]){
    switch(x){
    case 0:
        break;
    case 1:
        deletarTodosProfessores(professor);
        break;
    case 2:
        deletarTodosAlunos(aluno);
        break;
    default:
        break;
    }
}
// Escolha opção 6
int escolhaOpcao6(){
    int x;
    bool erro=true;
    while(erro){
        cout<<"\n\nDigite o que deseja: ";
        cin>>x;
        if(x>=0&&x<=2)erro=false;
        else cout<<"Somente números de 0 a 2\a";
    }
    return x;
}
// Opção 6
void opcao6(Pessoas*pessoa[],Alunos*aluno[],Professores*professor[]){
    cout<<"\n\n6.0 – Voltar ao menu anterior[0]";
    cout<<"\n6.1 - Excluir todos os professores[1]";
    cout<<"\n6.2 - Excluir todos os alunos[2]";
    int x=escolhaOpcao6();
    opcoesOpcao6(x,aluno,professor);
}

// Pegando o mês do aniversariante
void pegandoMesAniversariante(int*mes){
    bool erro=true;
    while(erro){
        cout<<"\nDigite o mês que deseja: ";
        cin>>*mes;
        if(*mes>=1&&*mes<=12)erro=false;
        else cout<<"\nMês inválido[1 a 12]\a";
    }
}
// Listando professores aniversariantes do mês
void professoresAniversariantesMes(Professores*professor[],int*mes){
    int aniversariantes=0;
    if(Professores::TAMPROFESSOR!=0){
        for(int i=0;i<Professores::TAMPROFESSOR;i++){
            if(professor[i]->getMes()==*mes){
                aniversariantes++;
                cout<<"\nPROFESSOR-> Nome: "<<professor[i]->getNome()<<" - Data de nascimento: "<<professor[i]->getDia()<<
                "/"<<professor[i]->getMes()<<"/"<<professor[i]->getAno()<<" - CPF: "<<professor[i]->getCpf()
                <<" - Título: "<<professor[i]->getTitulacao();
            }
        }
    }
    else cout<<"\nNão existe nenhum professor cadastrado";
    if(aniversariantes==0)cout<<"\nNão existe nenhum professor aniversariante nesse mês";
    else cout<<"\nTotal de professores aniversariantes do mês: "<<aniversariantes;
}
// Listando alunos aniversariantes do mês
void alunossAniversariantesMes(Alunos*aluno[],int*mes){
    int aniversariantes=0;
    if(Alunos::TAMALUNO!=0){
        for(int i=0;i<Alunos::TAMALUNO;i++){
            if(aluno[i]->getMes()==*mes){
                aniversariantes++;
                cout<<"\naluno-> Nome: "<<aluno[i]->getNome()<<" - Data de nascimento: "<<aluno[i]->getDia()<<
                "/"<<aluno[i]->getMes()<<"/"<<aluno[i]->getAno()<<" - CPF: "<<aluno[i]->getCpf()
                <<" - Matrícula: "<<aluno[i]->getNumeroMatricula();
            }
        }
    }
    else cout<<"\nNão existe nenhum aluno cadastrado";
    if(aniversariantes==0)cout<<"\nNão existe nenhum aluno aniversariante nesse mês";
    else cout<<"\nTotal de alunos aniversariantes do mês: "<<aniversariantes;
}
// Opções opção 7
void opcoesOpcao7(int x,Alunos*aluno[],Professores*professor[]){
    int mes;
    switch(x){
    case 0:
        break;
    case 1:
        pegandoMesAniversariante(&mes);
        break;
    case 2:
        professoresAniversariantesMes(professor,&mes);
        break;
    case 3:
        alunossAniversariantesMes(aluno,&mes);
        break;
    default:
        break;
    }
}
// Escolha opção 7
int escolhaOpcao7(){
    int x;
    bool erro=true;
    while(erro){
        cout<<"\n\nDigite o que deseja: ";
        cin>>x;
        if(x>=0&&x<=3)erro=false;
        else cout<<"Somente números de 0 a 3\a";
    }
    return x;
}
//Opção 7
void opcao7(Alunos*aluno[],Professores*professor[]){
    cout<<"\n\n7.0 – Voltar ao menu anterior[0]";
    cout<<"\n7.1 - Informar o mês a ser pesquisado[1]";
    cout<<"\n7.2 - Listar os Professores aniversariantes do mês[2]";
    cout<<"\n7.3 - Listar os Alunos aniversariantes do mês[3]";
    int x=escolhaOpcao7();
    opcoesOpcao7(x,aluno,professor);
}

// Opções
void opcoes(int x,Pessoas*pessoa[],Alunos*aluno[],Professores*professor[]){
    switch(x){
    case 1:
        opcao1(pessoa,aluno,professor);
        break;
    case 2:
        opcao2(aluno,professor);
        break;
    case 3:
        opcao3(aluno,professor);
        break;
    case 4:
        opcao4(aluno,professor);
        break;
    case 5:
        opcao5(aluno,professor);
        break;
    case 6:
        opcao6(pessoa,aluno,professor);
        break;
    case 7:
        opcao7(aluno,professor);
        break;
    default:
        break;
    }
}
// Ler arquivo de alunos
void lerArquivoAlunos(Alunos*aluno[],Pessoas*pessoa[]){
    ifstream arqAluno("alunos.txt");
    if(arqAluno.is_open()){
        string linha;
        while(getline(arqAluno,linha)){
            if(linha.find("ALUNO->")!=string::npos){
                // Extrair dados do aluno
                size_t posNome=linha.find("Nome: ")+6;
                size_t posData=linha.find(" - Data de nascimento: ");
                string nome=linha.substr(posNome,posData-posNome);
                
                size_t posDia=posData+23;
                size_t posBarra1=linha.find("/",posDia);
                int dia=stoi(linha.substr(posDia,posBarra1-posDia));
                
                size_t posMes=posBarra1+1;
                size_t posBarra2=linha.find("/",posMes);
                int mes=stoi(linha.substr(posMes,posBarra2-posMes));
                
                size_t posAno=posBarra2+1;
                size_t posCpf=linha.find(" - CPF: ",posAno);
                int ano=stoi(linha.substr(posAno,posCpf-posAno));
                
                size_t posCpfVal=posCpf+8;
                size_t posMatricula=linha.find(" - Matrícula: ",posCpfVal);
                string cpf=linha.substr(posCpfVal,posMatricula-posCpfVal);
                
                size_t posMatriculaVal=posMatricula+14;
                string matricula=linha.substr(posMatriculaVal);
                
                // Criar novo aluno
                aluno[Alunos::TAMALUNO]=new Alunos(nome,dia,mes,ano,cpf,matricula);
                pessoa[Pessoas::TAMPES]=aluno[Alunos::TAMALUNO];
                Alunos::TAMALUNO++;
                Pessoas::TAMPES++;
            }
        }
        arqAluno.close();
    }
}
// Ler arquivo de professores
void lerArquivoProfessores(Professores*professor[],Pessoas*pessoa[]){
    ifstream arqProf("professores.txt");
    if(arqProf.is_open()){
        string linha;
        while(getline(arqProf,linha)){
            if(linha.find("PROFESSOR->")!=string::npos){
                // Extrair dados do professor
                size_t posNome=linha.find("Nome: ")+6;
                size_t posData=linha.find(" - Data de nascimento: ");
                string nome=linha.substr(posNome,posData-posNome);
                
                size_t posDia=posData+23;
                size_t posBarra1=linha.find("/",posDia);
                int dia=stoi(linha.substr(posDia,posBarra1-posDia));
                
                size_t posMes=posBarra1+1;
                size_t posBarra2=linha.find("/",posMes);
                int mes=stoi(linha.substr(posMes,posBarra2-posMes));
                
                size_t posAno=posBarra2+1;
                size_t posCpf=linha.find(" - CPF: ",posAno);
                int ano=stoi(linha.substr(posAno,posCpf-posAno));
                
                size_t posCpfVal=posCpf+8;
                size_t posTitulo=linha.find(" - Título: ",posCpfVal);
                string cpf=linha.substr(posCpfVal,posTitulo-posCpfVal);
                
                size_t posTituloVal=posTitulo+11;
                string titulo=linha.substr(posTituloVal);
                
                // Criar novo professor
                professor[Professores::TAMPROFESSOR]=new Professores(nome,dia,mes,ano,cpf,titulo);
                pessoa[Pessoas::TAMPES]=professor[Professores::TAMPROFESSOR];
                Professores::TAMPROFESSOR++;
                Pessoas::TAMPES++;
            }
        }
        arqProf.close();
    }
}
// Lendo pessoas do arquivo
void registrandoPessoas(Pessoas*pessoa[],Alunos*aluno[],Professores*professor[]){
    // Limpar contadores estáticos
    Pessoas::TAMPES=0;
    Alunos::TAMALUNO=0;
    Professores::TAMPROFESSOR=0;
    
    // Limpar arrays
    for(int i=0;i<_MAX;i++){
        pessoa[i]=nullptr;
        aluno[i]=nullptr;
        professor[i]=nullptr;
    }
    
    lerArquivoAlunos(aluno,pessoa);
    lerArquivoProfessores(professor,pessoa);
}
// Liberar memória
void liberarMemoria(Pessoas*pessoa[],Alunos*aluno[],Professores*professor[]){
    // Liberar apenas uma vez cada objeto
    for(int i=0;i<Pessoas::TAMPES;i++){
        if(pessoa[i]!=nullptr){
            delete pessoa[i];
            pessoa[i]=nullptr;
        }
    }
    // Resetar contadores
    Pessoas::TAMPES=0;
    Alunos::TAMALUNO=0;
    Professores::TAMPROFESSOR=0;
}
//Main
int main(){
    setlocale(LC_ALL,"Portuguese");
    system("chcp 65001 > nul");
    Pessoas*pessoa[_MAX];
    Alunos*aluno[_MAX];
    Professores*professor[_MAX];
    registrandoPessoas(pessoa,aluno,professor);
    instrcoes();
    int x=escolha();
    cout<<"\n\nBem-vindo, siga as instruções: ";
    while(x!=0){
        opcoes(x,pessoa,aluno,professor);
        instrcoes();
        x=escolha();
    }
    fechamento();
    liberarMemoria(pessoa,aluno,professor);
    return 0;
}