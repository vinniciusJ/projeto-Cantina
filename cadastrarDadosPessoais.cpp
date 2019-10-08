//
// Created by Vinicius on 08/10/2019.
//
#include <iostream>
#include <vector>
#include "validarDadosPessoais.h"

using namespace std;

// Declaração das funções

string cadastrarCPF();

string cadastrarCPF(){

    string CPF;
    cout << "CPF (Cadastro de Pessoa Física): ";
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
