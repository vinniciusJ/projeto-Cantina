#include <vector>
#include <string>
#include <cctype>

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

bool validarIdade (const string& idade){

    if(idade.size() == 2) {

        if (isalpha(idade[0]) && isalpha(idade[1])) {
            return false;
        } else {
            int idadeINT = {(static_cast<int>(idade[0] - 48) * 10) + static_cast<int>(idade[1] - 48)};

            if (idadeINT == 0 || idadeINT < 0 || idadeINT > 99) {
                return false;
            }
        }
    }
    else {
        return false;
    }
    return true;
}
bool validarNome(const string& nome){

    int verificar = 0;

    for (int i = 0; i < (int)nome.size(); ++i) {
      if(isalpha(nome[i])){
          if(i == 0){
              if(isupper(nome[i])){
                  verificar++;
              }
              else {
                  return false;
              }
          }
          else if(isspace(nome[i-1])){
              if(isupper(nome[i])){
                  verificar++;
              }
              else if(nome[i] == 'd'){
                  verificar++;
              }
              else {
                  return false;
              }
          }
          else {
              if(isupper(nome[i])){
                  return false;
              }
              else {
                  verificar++;
              }
          }
      }
      else if(isspace(nome[i])){
          verificar++;
      }
      else {
          return false;
      }
    }
    return verificar == nome.size();
}

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
    bool teste = true;
    terminacao.clear();

    for(int i=0; i<(int)usuario.size(); i++ ){
        if(usuario[i] == '@') {
            if(i != 0) {
                posicaoArroba = i;
                for (int j = posicaoArroba + 1, k = 0; (int) usuario.size() > j; j++, k++) {
                    terminacao.push_back(usuario[j]);
                }
            }
            else {
                teste = false;
            }
        }
    }
    if(validarTerminacaoEmail(terminacao) && teste){
        return usuario;
    }else {
        usuario.clear();
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
        return telefone;
    }
    else {
        telefone.clear();
        return telefone;
    }
}
bool validarDDD (int DDD, const vector <int>& listaDDD){
    for(int digito : listaDDD){
        if(DDD == digito){
            return true;
        }
    }
    return false;
}
bool validarDigitos (const string& numeroTelefonico){
    return (numeroTelefonico.size() - 2) == 9;
}
bool validarMatricula (const string& matricula){

    int anoMatricula = 0, cont = 0;
    vector <int> anosMatricula = {2009, 2010, 2011, 2012, 2013, 2014, 2015, 2016, 2017, 2018, 2019};

    for (int i = 1000; i >= 1;  i = i/ 10) {
        anoMatricula+= (static_cast<int>(matricula[cont] - 48)*i);
        cont++;
    }
    if(matricula.size() == 11){
        int verificar = 0;

        for (int i : anosMatricula) {
            if(anoMatricula == i){
                verificar++;
            }
        }
        return verificar == 1;
    }
    else {
        return false;
    }
}



