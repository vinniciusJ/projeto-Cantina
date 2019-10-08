#include <iostream>
#include <vector>

using namespace std;

bool validarCPF(std::vector <int> cpf);
vector<int> calcularCPF(string CPF);
string validarEmail(string usuario);
inline bool validarTerminacaoEmail( const string& dominio);
string validarTelefone(string telefone);
inline bool validarDDD (int DDD, const vector <int>& listaDDD);
inline bool validarDigitos (const string& numeroTelefonico);

bool validarCPF(vector<int> cpf) {

    for (int i = 0; i < 11; ++i) {

        if(cpf[i] < 0 || cpf[i] > 9){ //Validando a entrada de dados
            return  false;
        }
    }

    int digito1, digito2, temp = 0;

    for(char i = 0; i < 9; i++)
        temp += (cpf[i] * (10 - i));

    temp %= 11;

    if(temp < 2)
        digito1 = 0;
    else
        digito1 = 11 - temp;

    temp = 0;
    for(char i = 0; i < 10; i++)
        temp += (cpf[i] * (11 - i));

    temp %= 11;

    if(temp < 2)
        digito2 = 0;
    else
        digito2 = 11 - temp;

    if (digito1 == cpf[9]) {
        return cpf[10] == digito2;
    } else {
        return false;
    }

}

vector<int> calcularCPF(string CPF) {

    vector <int> CPF_convertido;
    CPF_convertido.clear();

    for(char i = 0; i < 11; i++)
    {
        CPF_convertido.push_back(static_cast<int>(CPF[i] - 48)); //Convertendo char para valor absoluto segundo tabela ASCII e passando para array de inteiros//

    }
    return CPF_convertido;
}
string validarEmail(string usuario) {

    int posicaoArroba = 0;
    string terminacao;
    terminacao.clear();

    for(int i=0; i<(int)usuario.size(); i++ ){
        if(usuario[i] == '@') {
            posicaoArroba = i;
            for(int j = posicaoArroba+1, k = 0; (int)usuario.size() > j; j++, k++){
                terminacao.push_back(usuario[j]);
            }
        }
    }
    if(validarTerminacaoEmail(terminacao)){
        return usuario;
    }else {
        usuario.clear();
        cout << "E-mail inválido, por favor informe novamente: ";
        usuario = "**********************";
        return usuario;
    }

}
bool validarTerminacaoEmail( const string& dominio) {
    vector <string> types = {"gmail.com", "yahoo.com", "outlook.com", "hotmail.com", "live.com" };

    for(const auto & type : types){
        if(dominio == type){
            return true;
        }
    }
    return false;
}
string validarTelefone(string telefone){

    vector <int> listaDDD ={11,12,13,14,15,16,17,18,19,21,22,24,27,28,31,32,33,34,35,37,38,41,42,43,44,45,46,47,48,49,51,
                            53,54,55,61,62,63,64,65,66,67,68,69,71,73,74,75,77,79,81,83,82,84,85,86,87,88,89,91,92,93,
                            95,94,96,97,98,99};
    int DDD = {(static_cast<int>(telefone[0] - 48)*10) + static_cast<int>(telefone[1] - 48)};
    if(validarDDD(DDD, listaDDD) && validarDigitos(telefone)){
        cout << "Telefone Válido" << endl;
        return telefone;
    }
    else {
        cout << "Telefone inválido" << endl;
        telefone.clear();
        return telefone;
    }
}
inline bool validarDDD (int DDD, const vector <int>& listaDDD){
    for(int digito : listaDDD){
        if(DDD == digito){
            return true;
        }
    }
    return false;
}
inline bool validarDigitos (const string& numeroTelefonico){
    return (numeroTelefonico.size() - 2) == 9;
}




