#include <iostream>
#include <fstream>

using namespace std;
#define LIMITE_CREDITOS 3


int main(){
    /*
     *  Disciplinas referentes aos identificadores
     */
    int identificador[12] = {0};
    float creditos[12] = {0};
    int preRequisito[12] = {0};
    int situacao[12] = {0};

    string line;
    ifstream arquivo("instancia.txt", ios::in);
 
    //Armazenando identificador da disciplina
    for (int i = 0; i < 12; i++){
        arquivo >> identificador[i];
    }

    //Armazenando crédito da disciplina
    for (int i = 0; i < 12; i++){
        arquivo >> creditos[i];
    }

    //Armazenando Pré-requisito da disciplina
    for (int i = 0; i < 12; i++){
        arquivo >> creditos[i];
    }

    //Armazenando se disciplina foi paga ou não
    for (int i = 0; i < 12; i++){
        arquivo >> creditos[i];
    }

}