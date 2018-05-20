#include <iostream>
#include <fstream>
#include <sstream>
#include "UFFLP/UFFLP.h"

using namespace std;
#define LIMITE_CREDITOS 32

struct Data{
    /*
     *  Disciplinas referentes aos identificadores
     */
    int *identificador;
    float *creditos;
    int *preRequisito;
    int *situacao;
    int disciplinasFaltantes = 8;
    int numPeriodosFaltantes = 5;
    int numDisciplinasOp = 0;
};

int solveCoin(Data *data){
    // Cria problema
    UFFProblem* prob = UFFLP_CreateProblem();
    
    // Cria variaveis X
	string varName, consName;
  	stringstream s;

    for (int i = 0; i < data->disciplinasFaltantes; i++) {
		for (int j = 0; j < data->numPeriodosFaltantes; j++) {
				s.clear();
				s << "X(" << i << "," << j << ")";
				s >> varName;
		      UFFLP_AddVariable(prob, (char*)varName.c_str(), 0.0, 1.0, j, UFFLP_Binary);
		}
	}

    //PRIMEIRA RESTRIÇÃO DO MODELO - LIMITE DE CRÉDITOS POR PERÍODO
    for (int j = 0; j < data->numPeriodosFaltantes; j++){
        s.clear();
        s << "LimCreditos_" << j;
        s >> consName;

        for (int i = 0; i < data->numPeriodosFaltantes; i++){
            s.clear();
            s << "X(" << i << "," << j << ")";
   	        s >> varName;
   	        UFFLP_SetCoefficient( prob, (char*)consName.c_str(),(char*)varName.c_str(), data->creditos[i]);
        }

        UFFLP_AddConstraint( prob, (char*)consName.c_str(), LIMITE_CREDITOS, UFFLP_Less);
    }

    //SEGUNDA RESTRIÇÃO
    for (int i = 0; i <= data->disciplinasFaltantes; i++){ // Usando número de disciplinas faltantes pois é a mesma quantidade de disciplinas obrigatórias
    s.clear();
    s << "Obrigatorias_" << i;
    s >> consName;
        for(int j = 0; j < data->numPeriodosFaltantes; j++){
            s.clear();
            s << "X(" << i << "," << j << ")";
   	        s >> varName;
   	        UFFLP_SetCoefficient( prob, (char*)consName.c_str(),(char*)varName.c_str(), 1);
        }
    UFFLP_AddConstraint( prob, (char*)consName.c_str(), LIMITE_CREDITOS, UFFLP_Equal);
    }

    //TERCEIRA RESTRIÇÃO DO MODELO - obriga mínimo de créditos de optativas
    s.clear();
    s << "MinOptativas_";
    s >> consName;
    for (int i = 0; i < data->numDisciplinasOp; i++){

        for (int j = 0; j < data->numPeriodosFaltantes; j++){
            s.clear();
            s << "X(" << i << "," << j << ")";
   	        s >> varName;
   	        UFFLP_SetCoefficient( prob, (char*)consName.c_str(),(char*)varName.c_str(), data->creditos[i]);
        }
    }
    UFFLP_AddConstraint( prob, (char*)consName.c_str(), data->numDisciplinasOp, UFFLP_Greater);

    //QUARTA RESTRIÇÃO- PAGA OP APENAS UMA VEZ POR PERÍODO
    for (int i = 0; i <= data->numDisciplinasOp; i++){ // Usando número de disciplinas faltantes pois é a mesma quantidade de disciplinas obrigatórias
    s.clear();
    s << "OpUmaVez_" << i;
    s >> consName;
        for(int j = 0; j < data->numPeriodosFaltantes; j++){
            s.clear();
            s << "X(" << i << "," << j << ")";
   	        s >> varName;
   	        UFFLP_SetCoefficient( prob, (char*)consName.c_str(),(char*)varName.c_str(), 1);
        }
    UFFLP_AddConstraint( prob, (char*)consName.c_str(), 1, UFFLP_Less);
    }

    // Escreve modelo no arquivo .lp
    UFFLP_WriteLP( prob, "PAAA.lp" );
    // Destroy the problem instance
    UFFLP_DestroyProblem( prob );

	return 0;
}



int main(){
    
    /*
     *  Disciplinas referentes aos identificadores
     */
    Data* data = new Data();
    
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
        arquivo >> preRequisito[i];
    }

    //Armazenando se disciplina foi paga ou não
    for (int i = 0; i < 12; i++){
        arquivo >> situacao[i];
    }

    data->identificador = identificador;
    data->creditos = creditos;
    data->preRequisito = preRequisito;
    data->situacao = situacao;
    cout << "UAYSGDUYASDYUAS" << endl;

    solveCoin(data);
}