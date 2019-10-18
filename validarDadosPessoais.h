#ifndef VALIDARDADOSPESSOAIS_H_INCLUDED
#define VALIDARDADOSPESSOAIS_H_INCLUDED

#include <vector>
#include <cctype>
#include <string>

using namespace std;

bool validarCPF(std::vector <int> cpf);
vector<int> calcularCPF(string CPF);
string validarEmail(string usuario);
bool validarTerminacaoEmail( const string& dominio);
string validarTelefone(string telefone);
bool validarDDD (int DDD, const vector <int>& listaDDD);
bool validarDigitos (const string& numeroTelefonico);
bool validarNome(const string& nome);
bool validarIdade (const string& idade);
bool validarMatricula (const string& matricula);


#endif // VALIDARDADOSPESSOAIS_H_INCLUDED
