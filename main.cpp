#include <iostream>
#include <string>
#include "validarDadosPessoais.h"
#include "cadastrarDadosPessoais.h"

using namespace std;

int main(){

    string CPF;
    CPF = cadastrarCPF();
    cout << "O CPF Cadastrado é: " << CPF << endl;


    return 0;
}
