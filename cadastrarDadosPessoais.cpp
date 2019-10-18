//
// Created by Vinicius on 08/10/2019.
//
#include <iostream>
#include <vector>
#include "validarDadosPessoais.h"

using namespace std;

// Declaração das funções

string cadastrarCPF();
string cadastrarNome();
string cadastrarEmail();
string cadastrarTelefone();
string cadastrarIdade();
string cadastrarMatricula();
void cadastrarDados(string &nome, string &idade, string &matricula,string &CPF, string &email, string &telefone);

string cadastrarNome(){

    string nome;
    cout << "NOME: ";
    getline(cin, nome);

    while(!validarNome(nome)){
        cout << "Nome invalido, por favor insira novamente: ";
        getline(cin, nome);
    }

    return nome;
}

string cadastrarMatricula(){

    string matricula;
    cout << "MATRICULA: ";
    cin >> matricula;

    while (!validarMatricula(matricula)){
        cout << "Matricula invalida, por favor informe novamente: ";
        cin >> matricula;
    }
    return matricula;
}

string cadastrarCPF(){

    string CPF;
    cout << "CPF (Cadastro de Pessoa Fisica): ";
    cin >> CPF;

    vector <int> CPFNumeros;
    CPFNumeros.clear();
    CPFNumeros = calcularCPF(CPF);

    while(!validarCPF(CPFNumeros)){
        cout << "CPF invalido, por favor insira novamente: ";
        cin >> CPF;
        CPFNumeros = calcularCPF(CPF);
    }
    return CPF;
}
string cadastrarEmail(){

    string email;
    cout << "E-mail: ";
    cin >> email;

    email = validarEmail(email);

    if(email.empty()){
        cout << "Email invalido, por favor insira novamente: ";
        cin >> email;
        email = validarEmail(email);
    }

    return email;
}
string cadastrarTelefone(){

    string telefone;
    cout << "TELEFONE: ";
    cin >> telefone;

    telefone = validarTelefone(telefone);
    while(telefone.empty()){
        cout << "Telefone invalido, digite novamente: ";
        cin >> telefone;
        telefone = validarTelefone(telefone);
    }
    return telefone;
}
string cadastrarIdade(){

    string idade;
    cout << "IDADE: ";
    cin >> idade;

    while(!validarIdade(idade)){
        cout << "Idade invalida, por favor insira novamente: ";
        cin >> idade;
    }

    return idade;
}
void cadastrarDados(string &nome, string &idade, string &matricula, string &CPF, string &email, string &telefone){

    nome = cadastrarNome();
    idade = cadastrarIdade();
    matricula = cadastrarMatricula();
    CPF = cadastrarCPF();
    email = cadastrarEmail();
    telefone = cadastrarTelefone();
}
