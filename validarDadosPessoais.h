//
// Created by Vinicius on 08/10/2019.
//

#ifndef PORJETO_CANTINA_IFPR_CADASTRARDADOSPESSOAIS_H
#define PORJETO_CANTINA_IFPR_CADASTRARDADOSPESSOAIS_H

#include <iostream>
#include <vector>
#include "validarDadosPessoais.h"

using namespace std;

string cadastrarCPF();
string cadastrarNome();
string cadastrarEmail();
string cadastrarTelefone();
string cadastrarIdade();
string cadastrarMatricula();
void cadastrarDados(string &nome, string &idade, string &matricula ,string &CPF, string &email, string &telefone);

#endif //PORJETO_CANTINA_IFPR_CADASTRARDADOSPESSOAIS_H
