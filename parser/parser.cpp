#include "parser.h"
#include "nlohmann/json.hpp" //Include único p/ biblioteca do JSON
#include <iostream> 
#include <vector>
#include <fstream>
#include <string>
#include <sstream>

using json = nlohmann::json; //Para utiliar as funções da biblioteca do JSON
#define MAX_DISCIPLINAS 92
#define LIMITE_CREDITOS 32


void atualizaDados(Data* data){
    ifstream arquivoAluno("instancia.json", ios::in); // Abre instância com dados do aluno
    ifstream arquivoHorario("horario.txt", ios::in); // Abre instância com horários das disciplinas
    string horario1;
    
    json j;
    arquivoAluno >> j; // Transfere informações da instância para objeto do json
    
    int discUteis = -1;
    while (horario1 != "end"){ //Loop que identifica quantidade de disciplinas úteis
        arquivoHorario >> horario1; //Transfere informações dos horários para objeto do json
        if (horario1 == "0"){
            continue;
        }    
        ++discUteis;
    }
    arquivoHorario.close();

    //Fazendo segunda parte
    string horario[discUteis]; //Variável que armazena todos os horários
    ifstream arquivoHorario2("horario.txt", ios::in); // Abre instância com horários das disciplinas
    string horario2;
    int *identificador = new int[discUteis];
    int k = 0, temp = 0;
    while (horario2 != "end"){ //Loop que identifica quantidade de disciplinas úteis
        arquivoHorario2 >> horario2;
        
        if (horario2 != "0" && horario2 != "end"){
            identificador[k] = temp;
            horario[k] = horario2; //Armazena horarios p/ criação da matriz choque de horario
            k++;
        }
        temp++;
    }

    cout << "Qnt. de cadeiras com horario: " << discUteis << endl;

    //Iterando json e armazenando Qnt. de créditos de cada cadeira
    int *credito = new int[discUteis];
    for (json::iterator it = j["cargaHoraria"].begin(); it != j["cargaHoraria"].end(); ++it) {
        int i = atoi(it.key().data());
        
        //Organiza dados de acordo com os que tem horário
        int retorno = 0, iTemp = 0;
        while (iTemp < 68){
            if (identificador[iTemp] == i){
                retorno = 1;
                break;
            }
            iTemp++;
        }
        if (retorno == 1){
            credito[iTemp] = it.value();
            credito[iTemp] /= 15;
        }
    }

    //Iterando json e armazenando situacao (concluido = 1 ou pendente = 0)
    int *situacao = new int[discUteis];
    for (json::iterator it = j["situacao"].begin(); it != j["situacao"].end(); ++it) {
        int i = atoi(it.key().data());
        
        //Organiza dados de acordo com os que tem horário
        int retorno = 0, iTemp = 0;
        while (iTemp < 68){
            if (identificador[iTemp] == i){
                retorno = 1;
                break;
            }
            iTemp++;
        }

        if ((retorno == 1) && (it.value() != "CONCLUIDO")){
            situacao[iTemp] = 0;
        }else{
            situacao[iTemp] = 1;
        }
    }

    //CRIA E PREENCHE MATRIZ DE CHOQUE DE HORÁRIOS
    bool choqueHorario[discUteis][discUteis]; //Armazena se tem choque de horario ou não
    for (int i = 0; i < discUteis; i++){
        for (int j = 0; j < discUteis; j++){
            if (horario[i] == horario[j])
                choqueHorario[i][j] = true;
            else
                choqueHorario[i][j] = false;
        }
    }

    //CRIA E PREENCHE MATRIZ DE PRE REQUISITOS
    int preReqI[discUteis][discUteis];
    for (json::iterator it = j["expressaoPreRequisito"].begin(); it != j["expressaoPreRequisito"].end(); ++it){
        int i = atoi(it.key().data());
        
        //Organiza dados de acordo com os que tem horário
        int retorno = 0, iTemp = 0;
        while (iTemp < 68){
            if (identificador[iTemp] == i){
                retorno = 1;
                break;
            }
            iTemp++;
        }
        if (retorno == 1){
            credito[iTemp] = it.value();
            credito[iTemp] /= 15;
        }
    }

    //Atribuição dos dados que serão utilizados no modelo p/ a struct
    data->creditos = credito;
    data->identificador = identificador;
    data->situacao = situacao;
    data->disciplinas = discUteis;
    data->numPeriodos = 10;
    data->numDisciplinasOp = 0;

    //Preenche matriz de choque de horário direto em i
    data->choqueHorarioI = new bool*[data->disciplinas];
    for (int i = 0; i < data->disciplinas; i++){
        data->choqueHorarioI[i] = new bool[data->disciplinas];
        for (int j = 0; j < data->disciplinas; j++){
            data->choqueHorarioI[i][j] = choqueHorario[i][j];
        }
    }

    //Print genérico para visualizar se o parser exibe valores certos
    for (int i = 0; i < discUteis; i++){
        cout << identificador[i] << " : " << horario[i] << endl;
    }
    //---------------------------------------------------------------
    
    //Printa matriz choque de horário
    /*for (int i = 0; i < discUteis; i++){
        for (int j = 0; j < discUteis; j++){
            cout << data->choqueHorarioI[i][j] << " ";
        }
        cout << endl;
    }*/

    //Fecha arquivos
    arquivoAluno.close();
    arquivoHorario.close();
    arquivoHorario2.close();
}

void solveCoin(Data* data){

}