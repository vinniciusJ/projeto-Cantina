#include <iostream>
#include <string>
#include<fstream>

using namespace std;

    class teste{

        public:
        int x;

            bool verificar(int numero){
                if(numero == 1){
                    return true;
                }
                else{
                    return false;
                }
            }

            int numero(int numero){

                if(verificar(numero) == true){
                    return 1;
                }
                else {
                    return 0;
                }

            }
    };

int main(){

    int testeV = 0;
    teste testando;

    testeV = testando.numero(testeV);

    cout << testeV;

    return 0;
}
