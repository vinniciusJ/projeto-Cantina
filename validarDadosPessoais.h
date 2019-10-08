#ifndef VALIDARDADOSPESSOAIS_H_INCLUDED
#define VALIDARDADOSPESSOAIS_H_INCLUDED

#include <vector>
#include <iostream>
#include <vector>

using namespace std;

bool validarCPF(std::vector<int> cpf);
vector<int> calcularCPF(string CPF);
string validarEmail(string usuario);
inline bool validarTerminacaoEmail( const string& dominio);
string validarTelefone(string telefone);
inline bool validarDDD (int DDD, const vector <int>& listaDDD);
inline bool validarDigitos (const string& numeroTelefonico);


#endif // VALIDARDADOSPESSOAIS_H_INCLUDED
